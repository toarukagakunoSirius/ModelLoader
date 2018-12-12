//Test file for vector class
//Test programme by Hana Makhlouf

#include <iostream>
#include <stdlib.h>
#include "Vector.h"
#include "Vector.cpp"
using namespace std;

int main(int argc, char **argv) {
	int x1 = 1;
	int y1= 2;
	int z1 = 3;

	int x2 = 4;
	int y2 = 5;
	int z2 = 6;

	Vector x, y, z;
	x = x1 + x2;
	y = y1 + y2;
	z = z1 + z2;

	Vector::print();
}


/*float Vector::getx() { return x; }
float Vector::gety() { return y; }
float Vector::getz() { return z; }*/

//void Vector::subtract(Vector v);

//float Vector::scalarproduct(Vector v);

//Vector  Vector::vectorproduct(Vector v);