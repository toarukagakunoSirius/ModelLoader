#include <string>

using namespace std;

#ifndef MATERIAL_H
#define MATERIAL_H

class Material
{
private:
	int MatID;
	int Density;
	string MatName;
	string Colour;

public:
	Material();
	~Material();
	void setMaterial(int RCMat, int RCDen, string RCCol,string RCNam);
	int getMatID() const;
	int getDensity() const;
	string getName() const;
	string getColour() const;
};

#endif
