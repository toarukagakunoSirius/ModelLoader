#pragma once

#include "Cell.h"

class Hexahedron : public cell {
public:
	double getvolume();
	double getWeight();
	Vector getCentre();
};