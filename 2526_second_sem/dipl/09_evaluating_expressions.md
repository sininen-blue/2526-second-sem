---
title: 09 Evaluating Expressions
exportFilename: exports/dipl/09_expressions
lineNumbers: true
---

# Evaluating Expressions

---

## Executing code

The simplest, *shortest* path to executing code is through the syntax tree itself

Since our parser currently only supports expressions. No statements, no variables, no functions, no control flow,

All our interpreter will do is go through those expressions, and **generate a value**

This raises two questions

1. what kind of value
2. how do we organize the code

---

## Representing Values

In lox, a *value* is created by **literals**, which are computed as *expressions*, and then stored in *variables*

And given that lox is a *dynamically typed language* and java is **not**, we need to bridge that gap somehow

```java
java.lang.Object // the root of the class hierarchy in Java
```

In places where the interpreter needs to store a value, we use the `Object` type

Which we then convert during runtime to `number` or `string` or `bool`

---

## Note

The code in the next slides expect a starting point of a working parser

You can clone the code available here

[github.com/sininen-blue/alaan_cs370](https://github.com/sininen-blue/alaan_cs370)

From the commit `8385e1e7b5bf` `6.4 wiring up the parser`

Which is the latest commit as of writing this `March 11 2026`

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

So we declare a *visitor*, which returns an object, and all we need to do is define the *visit* methods for each class

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

The next simplest node to evaluate is the **grouping** expression

Remember that we defined the grouping expression as a single sub-expression wrapped in parentheses

```java
Grouping(Expr expression) {
    this.expression = expression;
}
```

So all we have to do is evaluate the expression, and return it

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

Like grouping, we have a single sub-expression that needs to be evaluated


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

---

## Post Order Traversal

Our evaluation recursively traverses the tree. We can’t evaluate the unary operator itself until **after** we evaluate its operand

That means our interpreter is doing a **post-order** traversal

Each node evaluates its children before doing its own work

---

## Truthiness

What happens when something that **isn't** a boolean, is used in a logical operation

One way of solving this is to **error**, but most dynamically typed languages don't do this

```javascript
const x = 5;
if ( x ) console.log("x is true");
```

This is called *truthiness*, it's arbitrary, and every language has its own rules for it

Lox follows the same rules `Ruby` does, which is that `false` and `nil` are falsey, and everything else is truthy

```
lox/interpreter.java
in after visitUnaryExpr()
```
```java
private boolean isTruthy(Object object) {
    if (object == null) return false;
    if (object instanceof Boolean) return (boolean)object;
    return true;
}
```

---

## Binary

There's a few binary operations, but they all follow the same pattern

```
lox/interpreter.java
in class Interpreter
```
```java
@Override
public Object visitBinaryExpr(Expr.Binary expr) {
    Object left = evaluate(expr.left);
    Object right = evaluate(expr.right);

    switch (expr.operator.type) {
        case MINUS:
            return (double)left - (double)right;
        case SLASH:
            return (double)left / (double)right;
        case STAR:
            return (double)left * (double)right;
    }

    return null;
```

---

## Addition

The addition operator is special in lox, because it supports two different types, numbers and strings

```
lox/interpreter.java
in switch statement in visitBinaryExpr()
```
```java
    case PLUS:
        if (left instanceof Double && right instanceof Double) {
            return (double)left + (double)right;
        }

        if (left instanceof String && right instanceof String) {
            return (String)left + (String)right;
        }
        break;
```

---

## Comparison

The comparison operators are fairly straightforward, but they only work on numbers

```
lox/interpreter.java
in switch statement in visitBinaryExpr()
```
```java
    switch (expr.operator.type) {
        case GREATER:
            return (double)left > (double)right;
        case GREATER_EQUAL:
            return (double)left >= (double)right;
        case LESS:
            return (double)left < (double)right;
        case LESS_EQUAL:
            return (double)left <= (double)right;
    }
```

---

## Equality

The last pair are

```
lox/interpreter.java
in switch statement in visitBinaryExpr()
```
```java
    case BANG_EQUAL:
        return !isEqual(left, right);
    case EQUAL_EQUAL:
        return isEqual(left, right);
```


```
lox/interpreter.java
after isTruthy()
```
```java
private boolean isEqual(Object a, Object b) {
    if (a == null && b == null) return true;
    if (a == null) return false;

    return a.equals(b);
}
```

This is a weird corner case in java

In Lox, equality is *slightly* different compared to java, primarily, we need to handle `null` values separately since `Java` throws a `NullPointerException` if we try to call `equals` on a `null` value

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
