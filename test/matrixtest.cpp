//test file for matrix
/* Driver program to test rotation function */
#include "Matrix.h"
#include <iostream>
#include <stdlib.h>
#define N 3
using namespace std;


void rotateMatrix(int mat[N][N]);
void displayMatrix(int mat[N][N]);
void det(float m);

int main()
{

	Matrix test1, test2, test3, test4;
	// Test Case 1 
	int mat[N][N] =
	{
		{1, 2, 3},
		{5, 6, 7},
		{9, 10, 11},
	};

	test1.rotateMatrix(mat);

	// Print rotated matrix 
	cout << "Output matrix rotated 90 degrees anticlockwise:" << endl;
	test2.displayMatrix(mat);

	//return 0;

	//test case 2, calculating determinant
	static float m; //should get -20 with this
	static float m11 = 6;
	static float m12 = 2;
	static float m13 = 3;
	static float m21 = 5;
	static float m22 = 6;
	static float m23 = 7;
	static float m31 = 9;
	static float m32 = 10;
	static float m33 = 11;

	//Matrix::det(m);
	static float detanswer = test3.det(m);
	//test3.print();
	cout << "the determinant is:\n" << detanswer << endl;
}