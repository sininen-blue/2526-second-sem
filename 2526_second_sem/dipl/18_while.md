---
title: 18 While Loops
exportFilename: exports/dipl/18_while_loops
lineNumbers: true
---

# While Loops

---

## Looping Control Flow

Looping control flow executes a chunk of code more than once. 

It jumps back so that you can do something again

Since you don't usually want infinite loops, it typically has some conditional logic to know when to stop looping

---

## A New AST Node

We need to introduce a new `While` statement node to handle this control flow

It stores the *condition* and the body of the loop. Separating expressions and statements makes it clear that the condition is an expression and the body is a statement

```
tool/GenerateAst.java
in main()
```
```java
    "Print      : Expr expression",
    "Var        : Token name, Expr initializer",
    "While      : Expr condition, Stmt body"
```

---

## Updating the Grammar

We need to add the `while` statement to our grammar

```
statement  -> exprStmt
            | ifStmt
            | printStmt
            | whileStmt
            | block ;

whileStmt  -> "while" "(" expression ")" statement ;
```

---

## Updating the Parser

Over in the parser, we follow the same process we used for `if` statements by updating our `statement()` rule to detect and match the leading keyword

```
lox/Parser.java
in statement()
```
```java
    if (match(IF)) return ifStatement();
    if (match(PRINT)) return printStatement();
    if (match(WHILE)) return whileStatement();
    if (match(LEFT_BRACE)) return new Stmt.Block(block());
```

---

## Parsing While Loops

The `whileStatement()` method delegates the real work of parsing the condition and the body

It hews closely to the grammar, consuming the mandatory parentheses around the condition expression

```
lox/Parser.java
after ifStatement()
```
```java
private Stmt whileStatement() {
    consume(LEFT_PAREN, "Expect '(' after 'while'.");
    Expr condition = expression();
    consume(RIGHT_PAREN, "Expect ')' after condition.");
    Stmt body = statement();

    return new Stmt.While(condition, body);
}
```

---

## Interpreting While Loops

Now for the interpreter. We evaluate the condition expression first

If it's truthy, we execute the body. We keep looping as long as the condition remains truthy!

```
lox/Interpreter.java
in class Interpreter
```
```java
@Override
public Void visitWhileStmt(Stmt.While stmt) {
    while (isTruthy(evaluate(stmt.condition))) {
        execute(stmt.body);
    }
    return null;
}
```

---

## Turing Completeness

Like `if` statements, the interpreter implementation is a thin wrapper around Java's own code

We use Java's `while` loop to execute the Lox `while` loop

It's simple, but it finally makes Lox **Turing-complete**, letting us write programs where the running time isn't strictly bound by the length of the source code
