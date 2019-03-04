//Matrix test file by Hana Makhlouf as part of H62PEP
//The matrix class is a work in progress. It can currently calculate the determinant
//of a 3x3 matrix as well as rotate it 90 degrees anti clockwise

//The code to find the inverse is not working right now. The class is not linked to the rest of the classes yet

#include "Matrix.h"
#include <iostream>
#include <stdlib.h>
#define N 3
using namespace std;

//functions being used in this test file
void rotateMatrix(int mat[N][N]);
void displayMatrix(int mat[N][N]);
void det(float m);
void inverse(int mat[N][N]);

int main()
{
	Matrix test1, test2, test3;
	
	// Test Case 1, rotating matrix by 90 degrees using random set of data
	int mat[N][N] =
	{
		{6, 2, 3},
		{5, 6, 7},
		{9, 10, 11},
	};

	test1.rotateMatrix(mat); //result confirmed correct using online matrix calculator [3 7 11, 2 6 10, 6 5 9]

	// Print rotated matrix 
	cout << "Output matrix rotated 90 degrees anticlockwise:" << endl;
	test2.displayMatrix(mat);

	//test case 2, calculating determinant
	static float m;
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

	//print determinant value. It is -20 for the above set of data, confirmed using online matrix calculator
	static float detanswer = test3.det(m);
	cout << "the determinant is:\n" << detanswer << endl;

	//test 3, calculating inverse matrix - Not working right now-outputting in correct values
	/*
	cout << "the inverse is:\n" << endl;
	test3.inverse(mat);
	test3.displayMatrix(mat);
	*/

}