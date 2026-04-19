---
title: 17 Logical Operators
exportFilename: exports/dipl/17_logical_operators
lineNumbers: true
---

# Logical Operators

---

## Short-Circuiting

Logical operators `and` and `or` aren't like other binary operators

Because they **short-circuit**

If the left operand determines the *truth value* of the entire expression, 

we **don't** evaluate the right operand

For example, in `false and doSomething()`, the function `doSomething()` should never execute

---

## A New AST Node

Because of short-circuiting, we can't reuse our existing `Binary` expression class

Our `Binary` expression evaluates both of its operands *before* evaluating the operator itself

So, we need to introduce a new `Logical` *expression* node to handle this special behavior

```
tool/GenerateAst.java
in main()
```
```java
    "Grouping : Expr expression",
    "Literal  : Object value",
    "Logical  : Expr left, Token operator, Expr right",
    "Unary    : Token operator, Expr right"
```

---

## Updating the Grammar

We need to add logical operators to our grammar. They sit right above `equality` in precedence

And `or` has lower precedence than `and` (following `c`)

```
expression -> assignment ;
assignment -> IDENTIFIER "=" assignment | logic_or ;
logic_or   -> logic_and ( "or" logic_and )* ;
logic_and  -> equality ( "and" equality )* ;
```

Because of this, we need to update our `assignment` rule to call `or` instead of `equality`

```
lox/Parser.java
in assignment()
```
```java
private Expr assignment() {
    Expr expr = or();
    // ...
```

---

## Parsing OR

Let's implement the parsing logic for `or`

It looks very similar to our other binary operator parsing methods

```
lox/Parser.java
after assignment()
```
```java
private Expr or() {
    Expr expr = and();

    while (match(OR)) {
        Token operator = previous();
        Expr right = and();
        expr = new Expr.Logical(expr, operator, right);
    }

    return expr;
}
```

---

## Parsing AND

Next, we implement the parsing logic for `and`

It relies on `equality()`, which is the next highest level of precedence

```
lox/Parser.java
after or()
```
```java
private Expr and() {
    Expr expr = equality();

    while (match(AND)) {
        Token operator = previous();
        Expr right = equality();
        expr = new Expr.Logical(expr, operator, right);
    }

    return expr;
}
```

---

## Interpreting Logical Expressions

Now for the interpreter. We evaluate the left operand first

Then we look at its truthiness to see if we can short-circuit and skip the right side entirely

```
lox/Interpreter.java
in class Interpreter
```
```java
@Override
public Object visitLogicalExpr(Expr.Logical expr) {
    Object left = evaluate(expr.left);

    if (expr.operator.type == TokenType.OR) {
        if (isTruthy(left)) return left;
    } else {
        if (!isTruthy(left)) return left;
    }

    return evaluate(expr.right);
}
```

---

## Returning Values

Notice that we return the **value** of the operand itself with `return left;`

We don't return a strict `true` or `false` boolean literal unless the expression evaluated to one

This is a common, powerful feature in dynamically typed languages like Ruby, JavaScript, and Python

```javascript
print "hi" or 2; // "hi"
print nil or "yes"; // "yes"
```

