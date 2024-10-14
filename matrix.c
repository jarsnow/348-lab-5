/*
Name: John Rader
KUID: 3139234
Lab Session: Wednesday 1pm
Lab Assignment: 5
Description: Provides a sales report with a given input file
Collaborators: None
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

// writes m1 + m2 to array
void addMatrices(int **array, int m1[SIZE][SIZE], int m2[SIZE][SIZE]){
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            array[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

// writes m1 x m2 to array
void multiplyMatrices(int **array, int m1[SIZE][SIZE], int m2[SIZE][SIZE]){
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            // take the dot product of m1's row i and m2's col j
            int sum = 0;
            for (int k = 0; k < SIZE; k++){
                sum += m1[i][k] * m2[k][j];
            }
            array[i][j] = sum;
        }
    }
}

void transposeMatrix(int **array, int m1[SIZE][SIZE]){
    // only traverse half of the matrix, rounded down
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            //  write number to array of mirrored index
            array[i][j] = m1[j][i];
        }
    }
}

// prints given matrix
void printMatrix(int **array){
    printf("Output Matrix:\n");
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            printf("%d,",array[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int m1[SIZE][SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}};

    int m2[SIZE][SIZE] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}};

    // allocate memory for the entire array
    int **array;
    array = malloc(sizeof(int*)*SIZE);
    for (int i = 0; i < SIZE; i++){
        array[i] = malloc(sizeof(int)*SIZE);
    }

    // put function here
    transposeMatrix(array, m1);

    // print output for testing:
    printMatrix(array);

    free(array);
}