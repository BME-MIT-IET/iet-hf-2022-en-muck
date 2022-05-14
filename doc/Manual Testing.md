# Manual testing

in this part i tested diffrent structs and some of the important functions using assertion function .
all individual test files are available in test_suite folder and all of the tests will be called one by one using test_all file in a unit test fashion . the result of the test will be available in test.log built inside of the main directory , we can access that log file using   " cat ./test.log " .


# test_all

this files having the main method calls each test in the test suit folder one by one and in case of successfull results it will print the compilation time . in case of successfull execution with no error we would see a similar output in test.log built inside of the main directory :

``` 
Test red black tree ... 
Test red black tree [OK] 
==========Test sparse matrix ... 
test_inputs : 
[0][1] : 10.00 
[1][0] : 3.00 
[2][3] : 16.00 
[3][0] : 4.00 
[4][1] : 4.00 
[5][2] : 2.00 
[6][0] : 4.00 
[7][3] : 8.00 
[8][2] : 23.00 
[9][2] : 11.00 
[10][3] : 7.00 
[11][1] : 22.00 
test_coefficient_matrix initialized successfully
sorting ... 
sorted inputs : 
3 10 23 16 
4 4 11 7 
0 0 0 8 
4 22 2 0 
values of spars matrix :
[0][0] : 3.00 
[0][1] : 4.00 
[0][3] : 4.00 
[1][0] : 10.00 
[1][1] : 4.00 
[1][3] : 22.00 
[2][0] : 23.00 
[2][1] : 11.00 
[2][3] : 2.00 
[3][0] : 16.00 
[3][1] : 7.00 
[3][2] : 8.00 
sparse_matrix initialized successfully
Sparse matrix and Coefficient matrix released properly 
======Test sparse matrix [OK] 
==========Test training set ... 
training set allocated successfully 
training set test inputs: 
2 4 4 4 
4 2 4 9 
5 9 6 7 
4 3 9 1 
training set successfully compiled and inserted into sparse matrix . 
training set memory released successfully . 
======Test training set [OK] 
Test binary heap ... 
Test binary heap [OK] 
Time : 0.079721 s 
``` 



# test_training_set
this is one of the main test and it checks the correctness of training set struct.
first we set input parameter to be a test 4x4 matrix (num of users x num of items ) and we check if memory allocation was successful then we try to initialize the training set with some random ratings from 0-10 then we print the results as bellow in case of success :

``` 

training set test inputs: 
2 4 4 4 
4 2 4 9 
5 9 6 7 
4 3 9 1 
```

after compiling the training set we compare the input values and the values inside of training test set ratings entries and if both values are equal we successfully initialized the training set struct and we would have a sparse matrix of ratings inside of it , then we release its memory and we check again to see if we dont have memory leakage .


# test_sparse_matrix

this struct handles converting a coefficient matric into a sparse matrix 
first we declare size of test input matrix then we declare a coo_matrix_t type pointer with the chosen size 
and we initialize it with zeros, then we choose a random value between 0-30 and we enter this value into the matrix in random rows and columns positions (if random position is already filled we try anpther time until we find a free spot ) and we print these values to the console as you can see bellow :

``` 

test_inputs : 
[0][1] : 10.00 
[1][0] : 3.00 
[2][3] : 16.00 
[3][0] : 4.00 
[4][1] : 4.00 
[5][2] : 2.00 
[6][0] : 4.00 
[7][3] : 8.00 
[8][2] : 23.00 
[9][2] : 11.00 
[10][3] : 7.00 
[11][1] : 22.00 

```

 if initialization was success we go to next part which would be testing sort_coo_matrix function , after calling this function we print the results to the console as bellow :
 
```
sorted inputs : 
3 10 23 16 
4 4 11 7 
0 0 0 8 
4 22 2 0 

```
 
 this function supoosed to sort the coefficient matrix therefore we check if descending order is correct.

in the next part we construct our test sparse matrix using init_sparse_matrix function which will recieves our test coefficient matrix and input size of rows and columns then we check the constructed sparse matrix's values with coefficient matrix's values one by one and if they are both equal then we successfully generated a sparse matrix from initial matrix and we print the result : 

```
values of spars matrix :
[0][0] : 3.00 
[0][1] : 4.00 
[0][3] : 4.00 
[1][0] : 10.00 
[1][1] : 4.00 
[1][3] : 22.00 
[2][0] : 23.00 
[2][1] : 11.00 
[2][3] : 2.00 
[3][0] : 16.00 
[3][1] : 7.00 
[3][2] : 8.00 
```

 finally we free the matrices using free_coo_matrix and free_sparse_matrix function and check if memory deallocation was successful .



# important remark 

as you can see output matrix for the sorted matrix is not correct and sort_coo_matrix function is not behaving correctly therefor in order to execute the tests fully i had to comment out the test for sorting part otherwise the rest of test would not run as we have a faulty application .

