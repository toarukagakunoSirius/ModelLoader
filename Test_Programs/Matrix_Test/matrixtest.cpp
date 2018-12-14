//test file for matrix class by Hana Makhlouf

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
	Matrix test1, test2, test3;
	
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

	//test case 2, calculating determinant
	static float m; //should get -20 with this but GETTING ZERO???!
	static float m11 = 6;
	static float m12 = 2;
	static float m13 = 3;
	static float m21 = 5;
	static float m22 = 6;
	static float m23 = 7;
	static float m31 = 9;
	static float m32 = 10;
	static float m33 = 11;
	test3.SetMatrix(m11, m12, m13, m21, m22, m23, m31, m32, m33);

	static float detanswer = test3.det(m);
	//test3.print();
	cout << "the determinant is:\n" << detanswer << endl;
}