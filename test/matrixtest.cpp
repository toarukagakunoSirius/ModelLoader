//test file for matrix
/* Driver program to test rotation function */
#include "Matrix.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	// Test Case 1 
	int mat[N][N] =
	{
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16}
	};

	rotateMatrix(mat);

	// Print rotated matrix 
	displayMatrix(mat);

	return 0;
}