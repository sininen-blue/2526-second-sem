---
title: 04 Parts of a Programming Language
exportFilename: exports/dipl/04_scanner
lineNumbers: true
---

# Components and Implementation of a Scanner

---

## A tree walk interpreter

We'll be writing around 2000 lines of java code to implement a tree-walk interpreter for Lox.

Everyone will end up with the same end result with the same code, and so the majority of your grade will come from your ability to explain and demonstrate your code.

---

## Framework

```
lox/Lox.java
create a new file
```
```java
package com.craftinginterpreters.lox;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.charset.Charset;
import java.io.file.Files;
import java.nio.file.Paths;
import java.util.List;

public class Lox {
    public static void main(String[] args) throws IOException {
        if (args.length > 1) {
            System.out.println("Usage: jlox [script]");
            System.exit(64);
        } else if (args.length == 1) {
            runFile(args[0]);
        } else {
            runPrompt();
        }
    }
}

```

---

## Framework

```
lox/Lox.java
add after main()
```
```java
private static void runFile(String path) throws IOException {
    byte[] bytes = Files.readAllBytes(Paths.get(path));
    run(new String(bytes, Charset.defaultCharset()));
}
```

---

## Framework

```
lox/Lox.java
add after runFile()
```
```java
private static void runPrompt() throws IOException {
    InputStreamReader input = new InputStreamReader(System.in);
    BufferedReader reader = new BufferedReader(input);

    for (;;) {
        System.out.print("> ");
        String line = reader.readLine();
        if (line == null) break;
        run(line);
    }
}
```

---

## Framework

```
lox/Lox.java
add after runPrompt()
```
```java
private static void run(String source) {
    Scanner scanner = new Scanner(source);
    List<Token> tokens = scanner.scanTokens();

    for (Token token : tokens) {
        System.out.println(token);
    }
}
```

---

## Error handling

```
lox/Lox.java
add after run()
```
```java
static void error(int line, String message) {
    report(line, "", message);
}

private static void report(int line, String where, String message) {
    System.err.println("[line " + line + "] Error" + where + ": " + message);
    hadError = true;
}
```

---

## Error handling

```
lox/Lox.java
in class Lox
```
```java
public class Lox {
    static boolean hadError = false;
```

---

## Error handling

```
lox/Lox.java
in runFile()
```
```java
    // run(new String(bytes, Charset.defaultCharset()));

    if (hadError) System.exit(65);
}
```
```
lox/Lox.java
in runPrompt()
```
```java
    // run(line);
    hadError = false;
}
```

---
layout: center
---

# Checkpoint
We can't run the program yet

---

## Lexemes and Tokens

---

## Regular Languages and Expressions

---

## The Scanner Class

---

## Recognizing Lexemes

---

## Lexical Errors

---

## Operators

---

## Longer Lexemes

---

## Identifiers and Keywords
