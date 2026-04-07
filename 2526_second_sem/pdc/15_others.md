---
title: 15 Other functions
exportFilename: exports/pdc/14_other_functions
lineNumbers: true
---

# Other Essential Functions

---

## Other Essential Functions

There are a lot more functions in defined in the `MPICH` implementation of `MPI`, most of which are *not* essential for most applications

We'll be going over some of the more *commonly used* ones, but for a more comprehensive list of functions

A good place to look at is:

[rookiehpc.org/mpi/docs/index.html](https://rookiehpc.org/mpi/docs/index.html)

---

## Barrier

```c
int MPI_Barrier(MPI_Comm comm)
```

Creates a *synchronization point*. No process can pass this line of code until *all* processes in the communicator have reached it.

It's primarily used for *debugging*, *benchmarking*, and *input/output* processes

Note that `MPI_Barrier` kills parallel performance, so it should be used *sparingly* in production code.

---

## Barrier Example

```c

```

---

## Barrier Exercise

1. have `rank 0` print "Initializing"
2. make each processes "work" by making it sleep for a duration equal to its rank (e.g. `rank 0` sleeps for 0 seconds, `rank 1` sleeps for 1 second, etc.)
3. use `MPI_Barrier` to wait for all processes to finish their work
4. *Immediately* after the barrier, have `rank 0` print "All processes finished work"
5. Run the program without the barrier, and with the barrier, and *compare the outputs*

---
layout: two-cols-header
---

## Isend and Irecv

Non blocking send and receive functions. They do the transfer and return **immediately**

This allows the program to do *other work* while the transfer is happening in the *background*. 

::left::
```c
int MPI_Isend(
    const void *buf, 
    int count, 
    MPI_Datatype datatype, 
    int dest,
    int tag, 
    MPI_Comm comm, 
    MPI_Request *request
)
```

::right::
```c
int MPI_Irecv(
    void *buf, 
    int count, 
    MPI_Datatype datatype, 
    int source, 
    int tag,
    MPI_Comm comm, 
    MPI_Request *request
)
```

---

## Request

`MPI_Request` is a "*reciept*" for a background task, since `Isend` and `Irecv` return immediately, they can't return a status of the transfer. 

So instead they return a request object that can be used to check on the status of the transfer later on.

```c
MPI_Request request;
MPI_Isend(..., &request);
```

Request simply contains metadata about the transfer

It's almost always *passed* into an `MPI_Wait` or `MPI_Waitall` function to check on the status of the transfer

---
layout: two-cols-header
---

## Wait and waitall

Since you *can't* safely read from or write to a buffer involved in a *non-blocking* transfer until the transfer is *complete*

Wait is simply a *synchronization point* for a *specific transfer*, it blocks until the transfer associated with the request is complete

::left::
```c
int MPI_Wait(MPI_Request *request, MPI_Status *status)
```

Used for one request

::right::
```c
int MPI_Waitall(
    int count, 
    MPI_Request array_of_requests[], 
    MPI_Status array_of_statuses[],
)
```

Used for an array of requests, it blocks until *all* transfers associated with the requests are complete

---

## Isend and Irecv Exercise

Non blocking ring (Rank 0 -> 1 -> 2 -> 0)

1. Every process must send its rank number to its right neighbor ($i$ + 1)
2. every process must receive the rank number from its left neightbor ($i$ - 1)
3. Use *MPI_Isend* and *MPI_Irecv* to do the transfers, store the requests in an array of size 2
4. add a `printf("I am doing something else")` to simulate overlapping computation
5. use `MPI_Waitall` to wait for both transfers to finish
6. print the received value to confirm it is correct

---

## Status

`MPI_Status` represents the status of a *receive* operation

Returned by receive operations (`MPI_Recv`), or non-blocking operation wait (`MPI_Wait`, `MPI_Waitall`). 

In C the `MPI_Status` is a *structure* that contains **at least 3 attributes**: 
- `MPI_SOURCE`, 
- `MPI_TAG` and 
- `MPI_ERROR`. 

When the user has no use of the MPI_Status, they can pass the constant `MPI_STATUS_IGNORE` (or `MPI_STATUSES_IGNORE` for array of statuses).

---

## Status Exercise

---

## Sendrecv

`MPI_Sendrecv` is a combination of an `MPI_Send` and an `MPI_Recv`. 

Which prevents *deadlock* in situations where two processes need to exchange data with each other.

```c
int MPI_Sendrecv(
    const void *sendbuf, 
    int sendcount, MPI_Datatype sendtype, int dest, int sendtag,
    void *recvbuf, 
    int recvcount, MPI_Datatype recvtype, int source, int recvtag, 
    MPI_Comm comm, 
    MPI_Status * status
)
```

---

## Sendrecv Exercise

---
layout: two-cols-header
---

## Scatterv and gatherv


::left::
```c
int MPI_Scatterv(
    const void *sendbuf, 
    const int *sendcounts, 
    const int *displs,
    MPI_Datatype sendtype, 
    void *recvbuf, 
    int recvcount,
    MPI_Datatype recvtype,
    int root, 
    MPI_Comm comm
)
```

A version of `MPI_Scatter` where the data dispatched from the root process can *vary* in the number of elements

::right::
```c
int MPI_Gatherv(
    const void *sendbuf, 
    int sendcount, 
    MPI_Datatype sendtype,
    void *recvbuf, 
    const int recvcounts[], 
    const int displs[],
    MPI_Datatype recvtype,
    int root,
    MPI_Comm comm
)
```

A variant of `MPI_Gather` which allows the messages received to have **different lengths** and **be stored at arbitrary locations** in the root process buffer 

---

## Sendcounts and displacement

`sendcounts`, `recvcounts`, and `displacement` are arrays of size `world_size` that specify the number of elements sent to or received from each process

- `sendcounts[i]` specifies the number of elements sent to process `i` in `MPI_Scatterv`
- `recvcounts[i]` specifies the number of elements received from process `i` in `MPI_Gatherv`
- `displs[i]` specifies the displacement (offset) in the send buffer for process `i` in `MPI_Scatterv`, and in the receive buffer for process `i` in `MPI_Gatherv`

```c
int sendcounts[world_size] = {2, 3, 1}; // example for 3 processes
int displs[world_size] = {0, 2, 5}; // example for 3 processes
MPI_Scatterv(..., sendcounts, displs, ...);
```

---

## scatterv and gatherv Exercise

---
