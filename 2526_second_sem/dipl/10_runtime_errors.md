---
title: 10 Runtime errors
exportFilename: exports/dipl/10_runtime_errors
lineNumbers: true
---

# Runtime errors

---

## Runtime errors

Runtime errors are errors that happen on *runtime*

Of our many type casts, *almost all* of them will **break** during runtime. 

A `MINUS` unary cannot convert the right expression to a double if the right expression evaluates to a *bool*

```java
case MINUS:
    return -(double)right;
```

---

## Runtime errors

```java
2 * (3 / -"muffin")
```

In `Java` when an error occurs, it cascades

- we can't negate a `string`
- which means we *can't* divide that by `3`
- which means we *can't* evaluate that grouping
- which means we *can't* multiply it by `2`

So whenever a runtime error occurs, we need to escape all the way out

And in our case, we stop a running program, but we *ignore* it when we hit the interpreter

---

## Detecting run time errors

Since our interpreter evaluates nested expressions using recursive method calls

We need to *unwind* out of those method calls

first, we'll check the operands type

```
lox/Interpreter.java
in visitUnaryExpr()
```
```java
case MINUS:
    checkNumberOperand(expr.operator, right);
    return -(double)right;
```

---

## Detecting run time errors

```
lox/Interpreter.java
add after visitUnaryExpr()
```
```java
private void checkNumberOperand(Token operator, Object operand) {
    if (operand instanceof Double) return;
    throw new RuntimeError(operator, "Operand must be a number");
}
```

---

## Custom runtime error

```
lox/RuntimeError.java
create new file
```
```java
package com.craftinginterpreters.lox;

class RuntimeError extends RuntimeException {
    final Token token;

    RuntimeError(Token token, String message) {
        super(message);
        this.token = token;
    }
}
```

We make our own custom runtime error which extends off of the default java runtimeException 


---

## Add it everywhere

In `7.3.1` of the book, it shows you where to place this number check

[book link](https://craftinginterpreters.com/evaluating-expressions.html#hooking-up-the-interpreter)

along with an extra

```java
private void checkNumberOperands(Token operator, Object left, Object right)
```

To check for multiple operands

---

## Hooking everything up

```
lox/Interpreter.java
in class Interpreter
```
```java
void interpret(Expr expression) {
    try {
        Object value = evaluate(expression);
        System.out.println(stringify(value));
    } catch (RuntimeError error) {
        Lox.runtimeError(error);
    }
}
```

---

## Stringify

```
lox/Interpreter.java
add after isEqual()
```
```java
private String stringify(Object object) {
    if (object == null) return "nil";

    if (object instanceof Double) {
        String text = object.toString();
        if (text.endsWith(".0")) {
            text = text.substring(0, text.length() - 2);
        }
        return text;
    }
    return object.toString();
}
```

---

## Reporting runtime errors

```
lox/Lox.java
add after error()
```
```java
static void runtimeError(RuntimeError error) {
    System.err.println(error.getMessage() + "\n[line" + error.token.line + "]")
    hadRuntimeError = true;
}
```

---

## Reporting runtime errors

```
lox/Lox.java
in class Lox
```
```java
static boolean hadError = false;
static boolean hadRuntimeError = false
```

---

## Reporting runtime errors

```
lox/Lox.java
in runFile()
```
```java
    if (hadError) System.exit(65);
    if (hadRuntimeError) System.exit(70);
```

---

## Running the interpreter

```
lox/Lox.java
in class Lox
```
```java
public class Lox {
    private static final Interpreter interpreter = new Interpreter();
    static boolean hadError = false;
```

---

## Running the interpreter


```
lox/Lox.java
in run()
```
```java
    interpreter.interpret(expression)
}
```

---

## Activity

Take a screenshot of your lox implementation running the following expressions

```
5 + 2
true == false
(5 * 10) == 2 * (-18 / 22)
```

Note that the code provided in my git ends at chapter 6.4
