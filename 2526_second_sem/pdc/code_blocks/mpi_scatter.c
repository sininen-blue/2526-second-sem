#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

#define TOTAL_PIXELS 16
#define CHUNK_SIZE 4

int main() {
	MPI_Init(null, null);

	int rank, size;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	if (size != 4) {
		if (rank == 0) printf("Please run with exactly 4 processes.\n");
		MPI_Finalize();
		return 1;
	}

	int original_image[TOTAL_PIXELS] = {
		10, 200, 50, 250,
		100, 90, 220, 10,
		0, 30, 240, 150,
		80, 180, 210, 5
	};

	int final_image[TOTAL_PIXELS]; // Only Process 0 will print this at the end
	int local_pixels[CHUNK_SIZE];  // Every process gets a chunk

	// Scatter


	// Apply Brightness


	// Gather


	// Print
	if (rank == 0) {
		printf("Brightened Image:\n");
		for (int i = 0; i < TOTAL_PIXELS; i++) {
			printf("%d ", final_image[i]);
			if ((i + 1) % 4 == 0) printf("\n");
		}
	}

	MPI_Finalize();
	return 0;
}
