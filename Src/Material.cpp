#include "Material.h"



Material::Material()
{
  int MatID = 0;
  int Density = 0;
}
Material::~Material()
{
}

void Material::setMaterial(int RCMat, int RCDen, string RCCol, string RCNam){
	this->MatID = RCMat;
	this->Density = RCDen;
	this->MatName = RCNam;
	this->Colour = RCCol;
}
int Material::getMatID() const{
	return MatID;
}
string Material::getColour() const{
	return Colour;
}
int Material::getDensity() const{
	return Density;
}
string Material::getName() const{
	return MatName;
}
