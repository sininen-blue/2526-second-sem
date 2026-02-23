---
title: 06 Printer
exportFilename: exports/dipl/06_printer
lineNumbers: true
---

# A printer

---

## Goals

We now have a scanner and the bones of a parser that makes a syntax tree

To make it easier to debug, let's convert that syntax tree into lines that you can print

```
(* (- 123) (group 45.67))
```

---

## The printer

```
lox/AstPrinter.java
create new file
```
```java
package com.craftinginterpreters.lox;

class AstPrinter implements Expr.Visitor<String> {
    String print(Extr expr) {
        return expr.accept(this);
    }
}
```

Simply using the visitor pattern to walk the tree and return a string


---

## The printer

```
lox/AstPrinter.java
add after print()
```
```java
@Override
public String visitBinaryExpr(Expr.Binary expr) {
    return parenthesize(expr.operator.lexeme, expr.left, expr.right);
}
@Override
public String visitGroupingExpr(Expr.Grouping expr) {
    return parenthesize("group", expr.expression);
}
@Override
public String visitLiteralExpr(Expr.Literal expr) {
    if (expr.value == null) return "nil";
    return expr.value.toString();
}
@Override
public String visitUnaryExpr(Expr.Unary expr) {
    return parenthesize(expr.operator.lexeme, expr.right);
}
```

---

## The printer

```
lox/AstPrinter.java
add after visitUnaryExpr()
```
```java
private String parenthesize(String name, Expr... exprs) {
    StringBuilder builder = new StringBuilder();

    builder.append("(").append(name);
    for (Expr expr : exprs) {
        builder.append(" ");
        builder.append(expr.accept(this));
    }
    builder.append(")");

    return builder.toString();
}
```

---

## The printer

Some Test data since we don't have a parser yet

```
lox/AstPrinter.java
add after parenthesize()
```
```java
public static void main(String[] args) {
    Expr expression = new Expr.Binary(
        new Expr.Unary(
            new Token(TokenType.MINUS, "-", null, 1),
            new Expr.Literal(123)),
        new Token(TokenType.STAR, "*", null, 1),
        new Expr.Grouping(
            new Expr.Literal(45.67)));

    System.out.println(new AstPrinter().print(expression));
}
```

---

## The printer

```
(* (- 123) (group 45.67))
```
