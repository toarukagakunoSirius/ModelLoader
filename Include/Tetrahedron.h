#pragma once

#include "Cell.h"

class Tetrahedron : public cell {
public:
	double getvolume();
	double getWeight();
	Vector getCentre();
};