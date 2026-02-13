Instructor’s Key: 1D Heat Diffusion Parallelization
Step 1: Partitioning

    The Finest-Grained Task: The calculation of a single segment's temperature for one time step (Tinew​).

    Data Ownership: Each task "owns" its current temperature (Tiold​) and produces its next temperature (Tinew​).

Step 2: Communication

    Dependencies: Task i requires data from Task i−1 (left neighbor) and Task i+1 (right neighbor).

    Sketch Logic: Arrows should point from i−1 and i+1 toward i. This represents a local, synchronous communication pattern.

Step 3: Agglomeration

    Grouping Choice: Students should choose Block Partitioning (contiguous chunks).

        Justification: Assigning blocks (e.g., segments 1–250 to Core 0) minimizes the number of "boundary" segments that need to talk to other cores. If we interleaved them (Core 0 gets 1, 5, 9...), every single calculation would require communication, which is incredibly slow.

    The "Ghost Cell" Problem: Core A needs the value of segment 251 from Core B.

        Note: In practice, we often create a "halo" or "ghost zone"—an extra memory slot on Core A that stores a copy of Core B's first element.

Step 4: Mapping

    MIMD (CPU) Strategy: We use a Barrier Synchronization.

        Why: We must ensure all cores have finished calculating new_temp before any core begins the next time step. If Core 0 finishes and starts the next second while Core 1 is still on the previous second, the "neighbor" data will be corrupted (the Race Condition).

    GPU Strategy: On a GPU, we typically do not agglomerate into large blocks per thread.

        Why: GPUs thrive on having thousands of tiny threads to hide memory latency. We map one thread to one segment. The "communication" happens via fast Shared Memory or L1 Cache rather than explicit message passing.

Critical Thinking: The Surface-to-Volume Ratio

Question: Why does increasing the "block size" make the program more efficient?

Answer: This is the core of parallel efficiency.

    Computation is proportional to the Volume (the number of segments in a block).

    Communication is proportional to the Surface Area (only the segments at the very edges of the block).

As the block size grows, the amount of work (Math) increases much faster than the amount of talking (Communication). This reduces the "Parallel Overhead" and leads to better speedup.
