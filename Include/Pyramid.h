#pragma once

#include "Cell.h"

class Pyramid : public cell {
public:
	double getvolume();
	double getWeight();
	Vector getCentre();
};