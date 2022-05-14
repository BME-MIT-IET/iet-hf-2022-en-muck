# Manual testing

in this part i tested diffrent structs and some of the important functions using assertion function .
all individual test files are available in test_suite folder and all of the tests will be called one by one using test_all file in a unit test fashion .

# test_training_set
this is one of the main test and it checks the correctness of training set struct.
first we set input parameter to be a test 4x4 matrix (num of users x num of items ) and we check if memory allocation was successful then we try to initialize the training set with some random ratings from 0-10 then we print the results as bellow in case of success :

'''
    training set test inputs: 
    2 4 4 4 
    4 2 4 9 
    5 9 6 7 
    4 3 9 1 

'''

after compiling the training set we compare the input values and the values inside of training test set ratings entries and if both values are equal we successfully initialized the training set struct and we would have a sparse matrix of ratings inside of it , then we release its memory and we check again to see if we dont have memory leakage .



