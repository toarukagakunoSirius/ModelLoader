#pragma once

#include "Cell.h"

class Tetrahedron : public cell {
public:
	double getvolume();
	Vector getCentre();
};