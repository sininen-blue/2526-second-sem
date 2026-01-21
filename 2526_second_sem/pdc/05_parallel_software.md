---
title: 05 Parallel Software
exportFilename: exports/pdc/05_software
lineNumbers: true
---

# Parallel software

---

most system software makes some use of parallelism

However, there are still many programs that can only make use of
a single core, and there are many programmers with no experience writing par-
allel programs. This is a problem, because we can no longer rely on hardware
and compilers to provide a steady increase in application performance

---

First, some terminology. Typically when we run our shared-memory programs,
we’ll start a single process and fork multiple threads. So when we discuss shared-
memory programs, we’ll talk about threads carrying out tasks. On the other hand,
when we run distributed-memory programs, we’ll start multiple processes, and we’ll
talk about processes carrying out tasks

---

## Caveats

Second, we’ll mainly focus on what’s often called single program, multiple
data, or SPMD, programs. Instead of running a different program on each core,
SPMD programs consist of a single executable that can behave as if it were multiple
different programs through the use of conditional branches. For example

---

## Coordination

In a very few cases, obtaining excellent parallel performance is trivial. For example,
suppose we have two arrays and we want to add them

Although we might wish for a term that’s a little easier to pronounce, recall that
the process of converting a serial program or algorithm into a parallel program is
often called parallelization. Programs that can be parallelized by simply dividing
the work among the processes/threads are sometimes said to be embarrassingly
parallel. This is a bit unfortunate, since it suggests that programmers should be
embarrassed to have written an embarrassingly parallel program, when, to the
contrary, successfully devising a parallel solution to any problem is a cause for
great rejoicing

---

# Shared memory

---

## Dynamic and static threads

In many environments, shared-memory programs use dynamic threads. In this
paradigm, there is often a master thread and at any given instant a (possibly empty)
collection of worker threads

The master thread typically waits for work requests—
for example, over a network—and when a new request arrives, it forks a worker
thread, the thread carries out the request, and when the thread completes the work,
it terminates and joins the master thread. This paradigm makes efficient use of sys-
tem resources, since the resources required by a thread are only being used while the
thread is actually running.

An alternative to the dynamic paradigm is the static thread paradigm. In this
paradigm, all of the threads are forked after any needed setup by the master thread
and the threads run until all the work is completed. After the threads join the master
thread, the master thread may do some cleanup (e.g., free memory), and then it also
terminates. In terms of resource usage, this may be less efficient: if a thread is idle,
its resources (e.g., stack, program counter, and so on) can’t be freed. However, fork-
ing and joining threads can be fairly time-consuming operations

---

## Non determinsim

In any MIMD system in which the processors execute asynchronously it is likely that
there will be nondeterminism. A computation is nondeterministic if a given input
can result in different outputs. If multiple threads are executing independently, the
relative rate at which they’ll complete statements varies from run to run, and hence
the results of the program may be different from run to run. As a very simple example,
suppose we have two threads, one with ID or rank 0 and the other with ID or rank 1.
Suppose also that each is storing a private variable my_x, thread 0’s value for my_x is 7,
and thread 1’s is 19. Further, suppose both threads execute the following code

dead guy example

---

When threads or processes attempt to simultaneously access a
shared resource, and the accesses can result in an error, we often say the program
has a race condition, because the threads or processes are in a “race” to carry out
an operation. That is, the outcome of the computation depends on which thread wins
the race. In our example, the threads are in a race to execute x += my_val. In this case,
unless one thread completes x += my_val before the other thread starts, the result will
be incorrect. So we need for each thread’s operation x += my_val to be atomic

---

A block of
code that can only be executed by one thread at a time is called a critical section,
and it’s usually our job as programmers to ensure mutually exclusive access to a
critical section. In other words, we need to ensure that if one thread is executing the
code in the critical section, then the other threads are excluded.

---

The most commonly used mechanism for ensuring mutual exclusion is a mutual
exclusion lock or mutex, or simply lock

---

Also note that the use of a mutex enforces serialization of the critical section.
Since only one thread at a time can execute the code in the critical section, this code
is effectively serial. Thus we want our code to have as few critical sections as possible,
and we want our critical sections to be as short as possible.
There are alternatives to mutexes. In busy-waiting, a thread enters a loop, whose
sole purpose is to test a condition. In our example, suppose there is a shared variable
ok_for_1 that has been initialized to false. Then something like the following code
can ensure that thread 1 won’t update x until after thread 0 has updated

---

**Semaphores** are similar to mutexes,
although the details of their behavior are slightly different, and there are some types of
thread synchronization that are easier to implement with semaphores than mutexes.
A monitor provides mutual exclusion at a somewhat higher level: it is an object
whose methods can only be executed by one thread at a time

---

## Thread safety

In many, if not most, cases, parallel programs can call functions developed for use in
serial programs, and there won’t be any problems. However, there are some notable
exceptions. The most important exception for C programmers occurs in functions that
make use of static local variables. Recall that ordinary C local variables—variables
declared inside a function—are allocated from the system stack. Since each thread
has its own stack, ordinary C local variables are private. However, recall that a static
variable that’s declared in a function persists from one call to the next


strtok

A function such as strtok is not thread safe. This means that if it is used in
a multithreaded program, there may be errors or unexpected results. When a block
of code isn’t thread safe, it’s usually because different threads are accessing shared
data. Thus, as we’ve seen, even though many serial functions can be used safely in
multithreaded programs—that is, they’re thread safe—programmers need to be wary
of functions that were written exclusively for use in serial programs.

---

# Distributed memory

---

message passing

---

 one sided communication

---

partiioned global address spaec language

---

gpu programming
