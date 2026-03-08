---
title: 09 Evaluating Expressions
exportFilename: exports/dipl/09_expressions
lineNumbers: true
---

# Evaluating Expressions

---

## Executing code

The simplest, *shortest* path to executing code is through the syntax tree itself

Since our parser only supports expresisons

all our interpreter will do is go through those expressions, and **generate a value**

This raises two questions

1. what kind of value
2. how do we organize the code

---

## Representing Values

In lox, a *value* is created by **literals**, which are computed by *expressions*, and then stored in *variables*

Ang given that lox is a *dynamically typed language* and java is **not**, we need to bridge that gap somehow

```java
java.lang.Object
```

In places where the interpreter needs to store a value, we use the `Object` type

Which we then convert during runtime to `number` or `string` or `bool`

---

## Evaluating Expressions

For every type of expression we can parse, we need some code to define how it's actually evaluated

We'll do this by implementing another *Visitor* pattern

```
lox/Interpreter.java
create new file
```
```java
package com.craftinginterpreters.lox;

class Interpreter implements Expr.Visitor<Object> {
}
```

So we declare a visitor, which returns an object, and all we need to do is define the the *visit* methods for each class

---

## Literals

The *Leaves* of our abstract syntax tree, the smallest bits of code in Lox, are **literals**

Literals are **almost** values, but not quite.

They **evaluate** to values, but they aren't values themselves.

```
lox/Interpreter.java
in class Interpreter
```
```java
@Override
public Object visitLiteralExpr(Expr.Literal expr) {
    return expr.value;
}
```

---

## Parenthesis

```
lox/Interpreter.java
in class Interpreter
```
```java
@Override
public Object visitGroupingExpr(Expr.Grouping expr) {
    return evaluate(expr.expression);
}

private Object evaluate(Expr expr) {
    return expr.accept(this);
}
```

---

## Unary


```
lox/Interpreter.java
after visitLiteralExpr()
```
```java
@Override
public Object visitUnaryExpr(Expr.Unary expr) {
    Object right = evaluate(expr.right);

    switch (expr.operator.type) {
        case MINUS:
            return -(double)right;
        case BANG:
            return !isTruthy(right);
    }
    // Unreachable.

    return null;
}
```
Our evaluation recursively traverses the tree. We can’t evaluate the unary operator itself until **after** we evaluate its operand

That means our interpreter is doing a **post-order** traversal

Each node evaluates its children before doing its own work

---

## Truthiness

---

## Binary

---

## Runtime Errors

---

## Detecting Runtime Errors

---

## Hooking it up

---

## Reporting runtime errors

---

## Running the interpreter
