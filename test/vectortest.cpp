//Test file for vector class
//Test programme by Hana Makhlouf

//This programme contains a set of test data in order to calculate the sum, difference, scalar and vector product of 2 x,y,z vectors

#include <iostream>
#include <stdlib.h>
#include "Vector.h" //include the vector class header file 
using namespace std;

int main() {
	float t;
	//x,y,z for vector 1
	float x1 = 1;
	float y1 = 2;
	float z1 = 3;
	Vector Test1, Test2, Test3, Test4, Test5;
	Test1 = Vector(x1, y1, z1);
	Test3 = Vector(x1, y1, z1);
	Test4 = Vector(x1, y1, z1);

	//x,y,z for vector 2
	float x2 = 4;
	float y2 = 5;
	float z2 = 6;
	
	Test2 = Vector(x2, y2, z2);
	
	Test1.add(Test2);
	cout << "the sum of vector 1 and vector 2 is:" << endl;
	Test1.print();

	Test3.subtract(Test2); 
	cout << "the difference of vector 1 and vector 2 is:" << endl;
	Test3.print();

	t = Test4.scalarproduct(Test2);
	cout << "the scalar product of vector 1 and vector 2 is:\n"<< t << endl;
	

	Test5 = Test1.vectorproduct(Test2);
	cout << "the vector product of vector 1 and vector 2 is:" << endl;
	Test5.print();
}