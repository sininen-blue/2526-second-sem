#include <stdio.h>
#include <mpi.h>
#include <string.h>


typedef struct {
	int comm_rank;
	union {
		float f;
		int i;
	} number;
} CommRankNumber;


int compare_float_comm_rank_number(const void *a, const void *b) {
  CommRankNumber *comm_rank_number_a = (CommRankNumber *)a;
  CommRankNumber *comm_rank_number_b = (CommRankNumber *)b;
  if (comm_rank_number_a->number.f < comm_rank_number_b->number.f) {
    return -1;
  } else if (comm_rank_number_a->number.f > comm_rank_number_b->number.f) {
    return 1;
  } else {
    return 0;
  }
}

int compare_int_comm_rank_number(const void *a, const void *b) {
  CommRankNumber *comm_rank_number_a = (CommRankNumber *)a;
  CommRankNumber *comm_rank_number_b = (CommRankNumber *)b;
  if (comm_rank_number_a->number.i < comm_rank_number_b->number.i) {
    return -1;
  } else if (comm_rank_number_a->number.i > comm_rank_number_b->number.i) {
    return 1;
  } else {
    return 0;
  }
}


void *gather_numbers_to_root(void *number, MPI_Datatype datatype, MPI_Comm comm) {
	int comm_rank, comm_size;
	MPI_Comm_rank(comm, &comm_rank);
	MPI_Comm_size(comm, &comm_size);

	int datatype_size;
	MPI_Type_size(datatype, &datatype_size);

	void *gathered_numbers;
	if (comm_rank == 0) {
		gathered_numbers = malloc(datatype_size * comm_size);
	}

	MPI_Gather(number, 1, datatype, gathered_numbers, 1, datatype, 0, comm);

	return gathered_numbers;
}


int *get_ranks(void *gathered_numbers, int gathered_number_count, MPI_Datatype datatype) {
	int data_type_size;
	MPI_Type_size(datatype, &data_type_size);

	CommRankNumber *comm_rank_numbers = malloc(gathered_number_count * sizeof(CommRankNumber));

	int i;
	for (i = 0; i < gathered_number_count; i++) {
		comm_rank_numbers[i].comm_rank = i;
		memcpy(&(comm_rank_numbers[i].number), gathered_numbers + (i * data_type_size), data_type_size);
	}

	if (datatype == MPI_FLOAT) {
		qsort(comm_rank_numbers, gathered_number_count, sizeof(CommRankNumber), &compare_float_comm_rank_number);;
	} else {
		qsort(comm_rank_numbers, gathered_number_count, sizeof(CommRankNumber), &compare_int_comm_rank_number);;
	}

	int *ranks = (int *)malloc(sizeof(int) * gathered_number_count);
	for (i = 0; i < gathered_number_count; i++) {
		ranks[comm_rank_numbers[i].comm_rank] = i;
	}

	free(comm_rank_numbers);
	return ranks;
}
