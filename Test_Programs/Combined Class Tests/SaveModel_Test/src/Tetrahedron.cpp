#include "Tetrahedron.h"

double Tetrahedron :: getvolume() {
	std::vector<Vector> v = getV();
	double volume = 0;
	Vector A = v[0] - v[1];
	Vector B = v[0] - v[2];
	Vector C = v[0] - v[3];
	volume = std::abs((A.vectorproduct(B)).scalarproduct(C)) * (1.0 / 6.0);
	return volume;
}

Vector Tetrahedron::getCentre() {
	std::vector<Vector> v = getV();
	Vector centre;
	Vector total = v[0] + v[1] + v[2] + v[3];
	centre = total.divide(4);
	return centre;
}