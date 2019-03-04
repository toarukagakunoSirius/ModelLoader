#pragma once

#include "Cell.h"

class Hexahedron : public cell {
public:
	double getvolume();
	Vector getCentre();
};