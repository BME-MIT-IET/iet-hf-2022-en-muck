#include "../src/recommender.h"

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#include <time.h>
#include <stddef.h>

#include "../src/matrix_factorization.h"
#include "../src/matrix_factorization_bias.h"
#include "../src/sparse_matrix.h"

#include "test_sparse_matrix_1.h"

#define ROW_MATRIX_TEST_SIZE 4

#define COLUMN_MATRIX_TEST_SIZE 4

#define COO_MATRIX_TEST_SIZE 12

int test_sparse_matrix_1(void)
{
	size_t i, j, k;
	unsigned char* used_;
	float* coo_in;

	coo_matrix_t* c_matrix = init_coo_matrix(COO_MATRIX_TEST_SIZE);
	sparse_matrix_t* s_matrix;

	printf("==========Test sparse matrix ... \n");

	used_ =(unsigned char*) malloc(ROW_MATRIX_TEST_SIZE * COLUMN_MATRIX_TEST_SIZE * sizeof(unsigned char));

	

	if (!used_)
		return 1;

	for (i = 0; i < ROW_MATRIX_TEST_SIZE * COLUMN_MATRIX_TEST_SIZE; i++)
		used_[i] = 0;

	assert(c_matrix);

	if (!c_matrix)
		return 1;
	
	srand ( 25 );


	printf("test_inputs : \n");
	for (i = 0; i < COO_MATRIX_TEST_SIZE; i++)
	{
		j = rand() % ROW_MATRIX_TEST_SIZE;
		k = rand() % COLUMN_MATRIX_TEST_SIZE;

		if (!used_[j * COLUMN_MATRIX_TEST_SIZE + k])
		{	
			used_[j * COLUMN_MATRIX_TEST_SIZE + k] = 1;
			float in = (float) (rand()% 30) ;
			insert_coo_matrix(in, j, k, c_matrix);
			printf ( "[%d][%d] : %.2f \n", i, j , in );
		} else i--;
	}

	assert(c_matrix->current_size == COO_MATRIX_TEST_SIZE);
	printf("test_coefficient_matrix initialized successfully\n");



	printf("sorting ... \n");
	sort_coo_matrix(c_matrix);



	printf("sorted inputs : \n");


	int index = 0;
	for (j = 0; j < COLUMN_MATRIX_TEST_SIZE; j++)
	{
		for (i = 0; i < ROW_MATRIX_TEST_SIZE; i++)
		{
			int index =-1 ;
			for ( k = 0; k < COO_MATRIX_TEST_SIZE; k++)
			{
				if (c_matrix->entries[k].row_i == i && c_matrix->entries[k].column_j == j ){
					index = k ; 
				}
			}
			if(index == -1 ) printf("0 ");
			else printf("%.0f ",  c_matrix->entries[index].value);
		}
				
		printf("\n");
	}


	// this part is not successfull (sorting )

	for ( k = 1; k < COO_MATRIX_TEST_SIZE; k++)
	{
				assert(c_matrix->entries[k].value < c_matrix->entries[k-1].column_j && " sorting failed" );
	}


	s_matrix = 
		init_sparse_matrix(c_matrix, 
							ROW_MATRIX_TEST_SIZE, 
								COLUMN_MATRIX_TEST_SIZE);


	add_row(s_matrix);
	add_column(s_matrix);


	insert_coo(s_matrix,c_matrix);

	printf("values of spars matrix :\n");
	for (i = 0; i < COO_MATRIX_TEST_SIZE; i++)
	{
		j = c_matrix->entries[i].row_i;
		k = c_matrix->entries[i].column_j;

		assert(element_exists(j, k, s_matrix));

		float val = get_element(j, k, s_matrix);
		assert(val == c_matrix->entries[i].value);
		printf("[%d][%d] : %.2f \n", j, k , val);
	}

	printf("sparse_matrix initialized successfully\n");




	free_coo_matrix(c_matrix);
	free_sparse_matrix(s_matrix);

	assert(s_matrix);
	assert(c_matrix);
	printf("Sparse matrix and Coefficient matrix released properly \n");


	printf("======Test sparse matrix [OK] \n");

	return 0;
}