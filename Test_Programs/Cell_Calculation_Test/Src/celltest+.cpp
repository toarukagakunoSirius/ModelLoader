#include "Tetrahedron.h"
#include "Pyramid.h"
#include "Hexahedron.h"
#include <string>
#include <iostream>

int main(void) {
	/*Tetrahedron t1;
	t1.setCell(0, 0, "t");
	for (int i = 0; i < 4; i++) {
		t1.setVertices(i);
	}
	t1.setV(0, 0, 4, 3);
	t1.setV(1, 9, 2, 4);
	t1.setV(2, 6, 1, 7);
	t1.setV(3, 0, 1, 5);
	cout << t1.getvolume() << endl;*/

	Pyramid p1;
	p1.setCell(0, 0, "p");
	for (int i = 0; i < 5; i++) {
		p1.setVertices(i);
	}
	p1.setV(0, 1.95, 1.15, 1.5);
	p1.setV(1, 2.95, 1.15, 1.5);
	p1.setV(2, 2.95, 2.15, 1.5);
	p1.setV(3, 1.95, 2.15, 1.5);
	p1.setV(4, 1.95, 1.15, -1.21429);
	cout << "volume: " << p1.getvolume() << endl;
	cout << "centre: " << p1.getCentre().getx() << ", " << p1.getCentre().gety() << ", " << p1.getCentre().getz() << endl;

	/*Hexahedron h1;
	h1.setCell(0, 0, "h");
	for (int i = 0; i < 8; i++) {
		h1.setVertices(i);
	}
	h1.setV(0, 1.95, 1.15, 1.5);
	h1.setV(1, 2.95, 1.15, 1.5);
	h1.setV(2, 2.95, 2.15, 1.5);
	h1.setV(3, 1.95, 2.15, 1.5);
	h1.setV(4, 1.95, 1.15, -1.21429);
	h1.setV(5, 2.95, 1.15, -1.21429);
	h1.setV(6, 2.95, 1.15, -1.21429);
	h1.setV(7, 1.95, 2.15, -1.21429);
	cout << h1.getvolume() << endl;*/

	return 0;
}