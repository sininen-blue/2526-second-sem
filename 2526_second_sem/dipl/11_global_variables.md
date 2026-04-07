---
title: 11 Global Variables
exportFilename: exports/dipl/11_global_variables
lineNumbers: true
---

# Statements and State

---

## Summary of 8.1

- defined the difference between statements and expressions
- the two type of statements we have (expressions, print)
- rewired the current parser to work with statements

---
layout: center
---

# Global Variables

---

## Global variables

After defining a *state*, we can start workong on a bunch of other statements

The easiest one being **global variables**

This requires two thigns

1. A variable *declaration*, which brings a new variable into the world

```
var beverage = "espresso";
```

2. A variable *expression*, which *evaluates* to a value, accessing a *binding*
```
print beverage;
```

---

## Syntax

One thing to note about variable declarations is that they aren't interchangable

```
if (day == "monday") var beverage = "coffee";
``` 

While technically possible, meaning we *can* make it work. There's confusion here
- what would the value be if the day isn't monday?
- what happens after the if statement?
- does the variable exist outside of monday?

---

## Syntax

This is why variables are split into two levels of precedence

```
program → declaration* EOF ;

declaration → varDecl | statement ;
statement → exprStmt | printStmt ;
```

So anywhere a declaration exists, a non declaring statement can also exist

```
var x = 10;
21 / 31;
```

But there are places where a statement can exist but a declaration can't

```
if (var x = 10); # not allowed
if (x == 10)
```

---

## Syntax

A variable is declared like so

```
varDecl → "var" IDENTIFIER ( "=" expression )? ";" ;
```

With the "*var*" keyword, an *IDENTIFIER* leaf, and an optional `= expression`

```
var burger = "beef";
var burger;
```

Are both valid

Note that we also add `IDENTIFIER` into primary

```
primary →   "true" | "false" | "nil"
            | NUMBER | STRING
            | "(" expression ")"
            | IDENTIFIER ;
```

---

## Wiring

```
tool/GenerateAst.java
in main()
```
```java
    "Expression : Expr expression",
    "Print : Expr expression",
    "Var : Token name, Expr initializer"
    ));
```

We'll make a statement class called "*Var*", which has
- a `Token` for a name, and
- an `Expression` as an initializer

---

## Wiring

```
tool/GenerateAst.java
in main()
```
```java
    "Literal : Object value",
    "Unary : Token operator, Expr right",
    "Variable : Token name"
    ));
```

And we'll also make an expression class called "*Variable*", which is just the name of a token

> Run the GenreateAST file

---

## Parsing Variables

Before we do any parsing, we'll first need to do some cleanup

```
lox/Parser.java
in parse()
```
```java
    while (!isAtEnd()) {
        statements.add(declaration());
    }
```

---

## Parsing Variables

```
lox/Parser.java
add after expression()
```
```java
private Stmt declaration() {
    try {
        if (match(VAR)) return varDeclaration();

        return statement();
    } catch (ParseError error) {
        synchronize();
        return null;
    }
}
```

Where instead of running `Statements`, we'll be running `Declarations`

---

## A note on Error recovery

A declartion is essentially a full line, which is why it's a perfect place to do error recovery.

```java
synchronize()
```

just calls the function we made a while ago that says
- if there's a problem in the current line of code
- record it
- and jump out of that entire line
- then continue running the code as if that line didn't exist

Which lets us record *multiple* errors at a time while still *minimizing cascading errors*

---

## Wiring

```
lox/Parser.java
add after printStatement()
```
```java
private Stmt varDeclaration() {
    Token name = consume(IDENTIFIER, "Expect variable name.");
    Expr initializer = null;

    if (match(EQUAL)) {
        initializer = expression();
    }

    consume(SEMICOLON, "Expect ';' after variable declaration.");
    return new Stmt.Var(name, initializer);
}
```

We'll parse it like standard, consuming name, adding an init if it exists, then consuming a semicolon

---

## Wiring

```
lox/Parser.java
in primary()
```
```java
        return new Expr.Literal(previous().literal);
    }

    if (match(IDENTIFIER)) {
        return new Expr.Variable(previous());
    }

    if (match(LEFT_PAREN)) {
```

Then just add identifier to primary

This gives us a theoretically working frontend

---

## Environments

When we define a variable, we need to place that name and value somewhere

This is usually stored in a place called **environment**

It's essentially a *map* (dictionary) where the *keys* are the names, and the *values* are values

And while we could put that map into our interpreter, since it's a cleanly separated concept

We'll make a new class

```
lox/Environment.java
create new file
```

---

## Environments


```
lox/Environment.java
create new file
```
```java

package com.craftinginterpreters.lox;

import java.util.HashMap;
import java.util.Map;

class Environment {
	private final Map<String, Object> values = new HashMap<>();
}
```

---

## Environments

And then add a new function inside the class to *define*/*bind* a variable

```
lox/Environment.java
inside the class
```
```java
	void define(String name, Object value) {
		values.put(name, value);
	}
}
```

---

## A note on semantics

Because of the way we defined our variables

```
var a = "before";
print a;
var a = "after";
print a;
```

is *valid*, which isn't the case for many other languages, but we'll choose to keep it for here

---

## Environments

```
lox/Environment.java
inside the class
```
```java
	Object get(Token name) {
		if (values.containsKey(name.lexeme)) {
			return values.get(name.lexeme);
		}

		throw new RuntimeError(name, "Undefined variable '" + name.lexeme + "'.");
	}

	void define(String name, Object value) {
```

We'll also define a new function called get, which will error if we can't find the variable

Specifically, we'll be using a runtime error

---

## Why runtime error

The problem is that using a variable isn’t the same as referring to it

```
fun isOdd(n) {
    if (n == 0) return false;
    return isEven(n - 1);
}

fun isEven(n) {
    if (n == 0) return true;
    return isOdd(n - 1);
}
```

Static (compile time) errors are too difficult

---

## Global variables

```
lox/Interpreter.java
in the class
```
```java
class Interpreter implements Expr.Visitor<Object>, Stmt.Visitor<Void> {
	private Environment environment = new Environment();
```

In our interpreter, we simply add the environment

---

## Global variables

```
lox/Interpreter.java
in the class
```
```java
	@Override
	public Void visitVarStmt(Stmt.Var stmt) {
		Object value = null;

		if (stmt.initializer != null) {
			value = evaluate(stmt.initializer);
		}

		environment.define(stmt.name.lexeme, value);
		return null;
	}
```

Then we declare what happens when we hit a variable in our tree

---

## Global variables

```
lox/Interpreter.java
add after visitUnaryExpr
```
```java
    @Override
    public Object visitVariableExpr(Expr.Variable expr) {
        return environment.get(expr.name);
    }
```

And finally we declare what happens when we evaluate a variable

---


## Assignment

It’s possible to create a language that has variables but does not let you reassign (*mutate*)

Think *const* in js

since mutating is a *side-effect*, meaning that it has *any observable effect* other than its primary effect of *reading* the value of its arguments and *returning* a value to the invoker of the operation

---

## Assignment syntax

assignment is an expression, not a statement, so we place it somewhere on the hierarchy, in our case, the very bottom

```
expression → assignment ;
assignment → IDENTIFIER "=" assignment
            | equality ;
```

This says an assignment is either an *identifier* followed by an `=` and an *expression* for the value, or an *equality* (and thus any other) expression

---

## Assignment

```
in tool/GenerateAST.java
inside the expression definitions
```
```java
    defineAst(outputDir, "Expr", Arrays.asList(
        "Assign   : Token name, Expr value",
```

Which gives us an assign class

---

## Parsing assignment

```
lox/parser.java
replace the expression() function 
```
```java
private Expr expression() {
    return assignment();
}
```

An interesting thing about assignment is that it's different compared to every other expression since it has two distinct *sides*

consider

```
var a = "before";
a = "value";
```

---

## Parsing assignment

```
var a = "before";
a = "value";
```

on the second line, we don't *evaluate* a. We only want to store "*value*" into a

unlike in something like

```
a == "value";
```

Where we do

This is called the **l-value** and **r-value** constructs

---

## Parsing assignment


```
in lox/parser.java
add after expressionStatement()
```
```java
	private Expr assignment() {
		Expr expr = equality();
		if (match(EQUAL)) {
			Token equals = previous();
			Expr value = assignment();
			if (expr instanceof Expr.Variable) {
				Token name = ((Expr.Variable)expr).name;
				return new Expr.Assign(name, value);
			}
			error(equals, "Invalid assignment target.");
		}
		return expr;
	}
```

So we do a trick, where we simple evaluate the left side as normal, and convert it to an assign after

Since anywhere an assign is valid, a declaration is also valid

---

## Assignment semantics

```
in lox/interpreter.java
add after visitVarStmt()
```
```java
	@Override
	public Object visitAssignExpr(Expr.Assign expr) {
		Object value = evaluate(expr.value);
		environment.assign(expr.name, value);
		return value;
	}
```

---

## Assignment semantics

```
lox/environemnt.java
add after get
```
```java
	void assign(Token name, Object value) {
		if (values.containsKey(name.lexeme)) {
			values.put(name.lexeme, value);
			return;
		}
		throw new RuntimeError(name, "Undefined variable '" + name.lexeme + "'.");
	}
```

---


## Run through

```
var a = 1;
var b = 2;
print a + b;

```

