//Test file for vector class
//Test programme by Hana Makhlouf

//This programme contains a set of test data in order to calculate the sum, difference, scalar and vector product of 2 x,y,z vectors

#include <iostream>
#include <stdlib.h>
#include "Vector.h" //include the vector class header file 
using namespace std;

int main() {
	float scalarresult;
	//x,y,z for vector 1
	float x1 = 1;
	float y1 = 2;
	float z1 = 3;

	//x,y,z for vector 2
	float x2 = 4;
	float y2 = 5;
	float z2 = 6;
	
	//combines x,y,z coordinates in a vector using the vector class
	Vector Test1, Test2, Test3, Test4, Test5;
	Test1 = Vector(x1, y1, z1);
	Test2 = Vector(x2, y2, z2);
	Test3 = Vector(x1, y1, z1);
	Test4 = Vector(x1, y1, z1);

	//uses add function and print function to add 2 vectors
	Test1.add(Test2);
	cout << "the sum of vector 1 and vector 2 is:" << endl;
	Test1.print();

	//uses subtract function and print function to subtract 2 vectors
	Test3.subtract(Test2); 
	cout << "the difference of vector 1 and vector 2 is:" << endl;
	Test3.print();

	//uses scalar product function to find the dot product of 2 vectors
	//the function returns the result in the function itself so no print function needed
	scalarresult = Test4.scalarproduct(Test2);
	cout << "the scalar product of vector 1 and vector 2 is:\n"<< scalarresult << endl; 
	
	//function to find vector product and print it
	Test5 = Test1.vectorproduct(Test2);
	cout << "the vector product of vector 1 and vector 2 is:" << endl;
	Test5.print();
}