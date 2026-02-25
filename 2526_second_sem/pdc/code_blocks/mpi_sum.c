#include <stdio.h>
#include <mpi.h>

// You should be able to run this with
// mpicc -Wall -o filename filename.c
// mpirun -n 4 ./filename

int main() {
	int comm_sz;
	int my_rank;

	// TODO: 1. Initialize the MPI environment

	// TODO: 2. Get the number of processes and your rank

	if (my_rank == 0) {
		int total_sum = 0;

		printf("Main process %d starting with %d processes\n", my_rank, comm_sz);

		for (int q = 1; q < comm_sz; q++) {
			int number_to_send = q * 10; 
			// TODO: Use MPI_Send to send 'number_to_send' to process 'q'
			// Use tag 0 and MPI_INT
		}

		for (int q = 1; q < comm_sz; q++) {
			int received_result;
			// TODO: Use MPI_Recv to receive the 'received_result' from process 'q'
			// Use MPI_STATUS_IGNORE

			total_sum += received_result;
			printf("Master received %d from process %d\n", received_result, q);
		}

		printf("Final Total Sum: %d\n", total_sum);

	} else {
		int incoming_value;

		// TODO: Use MPI_Recv to receive 'incoming_val' from process 0

		// defualt calculation, you can change this if you want
		int result = incoming_val * my_rank;

		// TODO: Use MPI_Send to send 'result' back to process 0
	}

	MPI_Finalize(); 
	return 0;
}
