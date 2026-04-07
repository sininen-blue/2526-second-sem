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

A good place to look is:

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
#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main() {
    MPI_Init(NULL, NULL);
 
    int my_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
 
    printf("[MPI process %d] I start waiting on the barrier.\n", my_rank);
    MPI_Barrier(MPI_COMM_WORLD);
    printf("[MPI process %d] I know all MPI processes have waited on the barrier.\n", my_rank);
 
    MPI_Finalize();
    return 0;
}
```

---
layout: two-cols-header
---

## Isend and Irecv

**Non** blocking send and receive functions. They do the transfer and return **i**mmediately

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

## Isend example

```c
int main() {
    enum role_ranks { SENDER, RECEIVER };
    switch(my_rank) {
        case SENDER:
        {
            int buffer_sent = 12345;
            MPI_Request request;
            MPI_Isend(&buffer_sent, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, &request);
            MPI_Wait(&request, MPI_STATUS_IGNORE);
            break;
        }
        case RECEIVER:
        {
            int received;
            MPI_Recv(&received, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE); 
            break;
        }
    }
    MPI_Finalize();
    return 0;
}
```

---

## Request

`MPI_Request` is a "*receipt*" for a background task, since `Isend` and `Irecv` return immediately, they don't return a status of the transfer. 

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

You *can't* safely read from or write to a buffer involved in a *non-blocking* transfer until the transfer is *complete*

`Wait` is simply a *synchronization point* for a *specific transfer*, it blocks until the transfer associated with the request is complete

Note that you can use `MPI_STATUS_IGNORE` if you don't care about the status of the transfer

::left::
```c
int MPI_Wait(
    MPI_Request *request, 
    MPI_Status *status
)
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

## Status

`MPI_Status` represents the status of a *receive* operation

Returned by receive operations (`MPI_Recv`), or non-blocking operation wait (`MPI_Wait`, `MPI_Waitall`). 

In C the `MPI_Status` is a *structure* that contains **at least 3 attributes**: 
- `MPI_SOURCE`, 
- `MPI_TAG` and 
- `MPI_ERROR`. 

When the user has no use of the MPI_Status, they can pass the constant `MPI_STATUS_IGNORE` (or `MPI_STATUSES_IGNORE` for array of statuses).

---

## Status Example

```c
int main() {
    MPI_Init(NULL, NULL);
    if(my_rank == 0) {
        int buffer_sent = 12345;
        int tag = 123;
        MPI_Ssend(&buffer_sent, 1, MPI_INT, 1, tag, MPI_COMM_WORLD);
    } else {
        int buffer_received;
        MPI_Status status;
        MPI_Recv(&buffer_received, 1, MPI_INT, 
                 MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, 
                 &status);
        printf("%d, %d from rank %d, with tag %d and error code %d.\n", 
               my_rank,
               buffer_received,
               status.MPI_SOURCE,
               status.MPI_TAG,
               status.MPI_ERROR);
    }
    MPI_Finalize();
}
```

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

## Sendrecv Example

```c
int main() {
    MPI_Init(NULL, NULL);

    int my_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    int buffer_send = (my_rank == 0) ? 12345 : 67890;
    int buffer_recv;
    int tag_send = 0;
    int tag_recv = tag_send;
    int peer = (my_rank == 0) ? 1 : 0;

    // Issue the send + receive at the same time
    printf("MPI process %d sends value %d to MPI process %d.\n", 
           my_rank, buffer_send, peer);
    MPI_Sendrecv(&buffer_send, 1, MPI_INT, peer, tag_send,
                 &buffer_recv, 1, MPI_INT, peer, tag_recv, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    printf("MPI process %d received value %d from MPI process %d.\n", 
           my_rank, buffer_recv, peer);
    MPI_Finalize();
}
```

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

## scatterv example

```c
int main() {
    MPI_Init(NULL, NULL);
    int root_rank = 0;
    int my_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    switch(my_rank) {
        case 0:
        {
            int my_value;
            int buffer[7] = {100, 0, 101, 102, 0, 0, 103};
            int displacements[3] = {0, 2, 6};
            int counts[3] = {1, 2, 1};

            MPI_Scatterv(buffer, counts, displacements, 
                         MPI_INT, &my_value, 
                         1, MPI_INT, 
                         root_rank, MPI_COMM_WORLD);
            printf("Process %d received value %d.\n", my_rank, my_value);
            break;
        }
```

---

## scatterv example (cont)

```c
    case 1:
    {
        int my_values[2];
        MPI_Scatterv(NULL, NULL, NULL, 
                     MPI_INT, my_values, 
                     2, MPI_INT, 
                     root_rank, MPI_COMM_WORLD);
        printf("Process %d received values %d and %d.\n", my_rank, my_values[0], my_values[1]);
        break;
    }
    case 2:
    {
        int my_value;
        MPI_Scatterv(NULL, NULL, NULL, 
                     MPI_INT, &my_value, 
                     1, MPI_INT, 
                     root_rank, MPI_COMM_WORLD);
        printf("Process %d received value %d.\n", my_rank, my_value);
        break;
    }
```

---

## Gatherv example

```c
    int root_rank = 0;

    switch(my_rank) {
        case 0:
        {
            int my_value = 100;
            int counts[3] = {1, 1, 2};
            int displacements[3] = {0, 3, 5};

            int* buffer = (int*)calloc(7, sizeof(int));
            MPI_Gatherv(&my_value, 1, MPI_INT, 
                        buffer, counts, 
                        displacements, MPI_INT, 
                        root_rank, MPI_COMM_WORLD);
            free(buffer);
            break;
        }

```

---

## Gatherv example

``` c
    case 1:
    {
        int my_value = 101;

        MPI_Gatherv(&my_value, 1, MPI_INT, 
                    NULL, NULL, NULL, 
                    MPI_INT, root_rank, MPI_COMM_WORLD);
        break;
    }
    case 2:
    {
        int my_values[2] = {102, 103};

        MPI_Gatherv(my_values, 2, MPI_INT, 
                    NULL, NULL, NULL, 
                    MPI_INT, root_rank, MPI_COMM_WORLD);
        break;
    }
```
