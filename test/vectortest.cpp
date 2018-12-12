//Test file for vector class
//Test programme by Hana Makhlouf

#include <iostream>
#include <stdlib.h>
#include "Vector.h"
#include "Vector.cpp"
using namespace std;

int main(int argc, char **argv) {
	int x = 1;
	int y = 2;
	int z = 3;

	int v.x = 4;
	int v.x = 5;
	int v.x = 6;

	Vector v = Vector(x, y, z);
	int add(Vector v);

	cout << v << endl;
	//cout << y2 << endl;
	//cout << z2 << endl;
}


/*float Vector::getx() { return x; }
float Vector::gety() { return y; }
float Vector::getz() { return z; }*/

//void Vector::subtract(Vector v);

//float Vector::scalarproduct(Vector v);

//Vector  Vector::vectorproduct(Vector v);