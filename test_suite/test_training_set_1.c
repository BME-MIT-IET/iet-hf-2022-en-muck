#include "../src/recommender.h"
#include "../src/training_set.h"
#include "../src/model_parameters.h"

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#include <time.h>
#include <stddef.h>

#include "test_training_set_1.h"
#include "../src/nearest_neighbors.h"
#define USER_NUMBER_TEST_SIZE		4

#define ITEM_NUMBER_TEST_SIZE		4

#define TRAINING_SET_TEST_SIZE		(4 * 4)

int test_training_set_1(void)
{
	training_set_t* tset;
	size_t u,  i, k;
	double * a;

	model_parameters_t params = { 0 };

	printf("==========Test training set ... \n");

	params.items_number = ITEM_NUMBER_TEST_SIZE;
	params.users_number = USER_NUMBER_TEST_SIZE;
	params.training_set_size = TRAINING_SET_TEST_SIZE;

	/* Initialize a training set */
	tset = init_training_set(&params);
	assert(tset->training_set_size == TRAINING_SET_TEST_SIZE);
	printf("training set allocated successfully \n");

	srand ( 23 );

	printf("training set test inputs: \n");
	for (u = 0; u < tset->users_number; u++)
	{
		for (i = 0; i < tset->items_number; i++)
		{
			int x=(rand() % 10);
			set_known_rating(u, i, (float) x, tset);
			printf("%d ",x);
		}
		printf("\n");
	}
	

	compile_training_set(tset);


	for (i = 0; i < TRAINING_SET_TEST_SIZE; i++)
	{
		float val;

		u = tset->ratings->entries[i].row_i;
		k = tset->ratings->entries[i].column_j;

		assert(element_exists(u, k, tset->ratings_matrix));

		val = get_element(u, k, tset->ratings_matrix);

		assert(val == tset->ratings->entries[i].value);
	}
	printf("training set successfully compiled and inserted into sparse matrix . \n");

	free_training_set(tset);

	printf("training set memory released successfully . \n");
	
	printf("======Test training set [OK] \n");

	return 0;
}