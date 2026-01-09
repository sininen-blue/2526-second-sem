---
title: 03 Running java programs
exportFilename: exports/dipl/03_java
lineNumbers: true
---

# Running Java

---

## Install Java Development Kit (JDK)

[oracle.com/asean/java/technologies/downloads/#java25](https://www.oracle.com/asean/java/technologies/downloads/#java25).

In lab, this *should* already be installed.

check by opening a terminal and running:

```
java --version
```

---

## Make a Java file

Inside a folder anywhere, create a file named `HelloWorld.java` with the following content:

```java
class HelloWorld {
    public static void main(String[] args) {
        System.out.println("Hello, World!");
    }
}
```

---

## In the terminal

Navigate to the folder where you created `HelloWorld.java`.

```
javac HelloWorld.java
```

This **c**ompiles the java file into java bytecode, and you should have a file named `HelloWorld.class` now.

then to run

```
java HelloWorld
```

---

## Java syntax overview

[learnxinyminutes.com/java/](https://learnxinyminutes.com/java/)


---

## A note on IDEs

You can use any text editor or IDE to write Java code.

I will be using notepad and the terminal for demonstration purposes.
