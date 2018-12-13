//test file for matrix
/* Driver program to test rotation function */
#include "Matrix.h"
#include <iostream>
#include <stdlib.h>
#define N 3
using namespace std;


void rotateMatrix(Matrix mat);
void displayMatrix(Matrix mat);

int main()
{
	// Test Case 1 
	int mat[N][N] =
	{
		{1, 2, 3},
		{5, 6, 7},
		{9, 10, 11},
	};

	rotateMatrix(mat);

	// Print rotated matrix 
	displayMatrix(mat);

	return 0;
}