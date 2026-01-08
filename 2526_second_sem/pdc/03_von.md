---
title: 03 Von Neumann Architecture
exportFilename: exports/pdc/01_von
lineNumbers: true
---

# Introduction

---

## The von Neumann Architecture

consisting of
1. main memory
2. cpu
3. interconnect

It's the basis of **all*** modern computers

---

## The von Neumann Architecture

image here

- control unit: what instruction to do
- data path: executing the instructions

<!--
cpu is empty
cpu wants to run progrma
control gets from memory, stores in registers
control sends to datapath
data path sends back to memory or stores in registers
-->

---

## The von Neumann Bottleneck

CPU's are incredibly fast, millions of instructions per second fast

Memory, and memory transfers, are slow, thousands of bits per second slow

And in a loop system, the slowest part determines the speed of the whole system

---

## factory and warehouse

---

## Software inside the von Neumann Architecture

The operating system is a piece of software

1. When a user runs a program, it creates a process

This includes things like
- machine language
- a block of memory (stack and heap)
- descriptors of resources (files, network connections, etc)
- etc

Most operating systems, and all modern ones, are **multitasking**

---

## Multitasking

The operating system provides the ability to run multiple programs and processes at the same time

> Even in single core von Neumann architecture systems

They operate on something called **time slices**

When processes need to wait for resources, a **block**, it gives the opportunity for other processes to run

Usually done with **threads**

image

---

## Modifications to the von Neumann model

The von neumman architecture **works**, but it's flaws have existed since the beginning

And so people have done modifications to it to make it faster

Mainly in three ways
1. to not pull in as much data
2. to pull more data at once
3. to run multiple instructions at once

---

## Caching

The most widely used modification

> Back to the example

There are two ways to make the von neumman faster

1. Widen the road
2. Move the factory

---

## Caching

In code

```c
float z[1000];

sum = 0.0;
for(i = 0; i < 1000; i++) {
    sum += z[i];
}
```

The operating system uses **locality** to also pull in nearby data when running this program

Arrays are blocks of contiguous memory, so it makes sense to pull in more than one value at a time

It pulls in a **cache block** or a **cache line**

---

## Cache hits and misses

When the CPU needs to access an instruction, it first checks the cache

If it's not in there, it's a **cache miss**

Then it has to go to main memory to get it, which is slow

If it is in there, it's a **cache hit**

Then it can get it quickly from the cache

---

## Fuller Example

---

## Virtual Memory

---

## Instruction level parallelism

--

## Hardware multi threading
