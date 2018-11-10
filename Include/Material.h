#include <string>

using namespace std;

#ifndef MATERIAL_H
#define MATERIAL_H

class Material
{
private:
	//Variables
	int MatID;//Material Unique ID
	int Density;
	string MatName;//Material Name
	string Colour;

public:
	//Default Constructor
	Material();

	/*Overload Constructor
	@param RCMat = Material Unique ID
				 RCDen = Density
				 RCCol = Colour
				 RCNam = Material Name*/
	Material(int RCMat, int RCDen, string RCCol,string RCNam);

	//Destructor
	~Material();

	/*Setup Function (Just in case)
	@param RCMat = Material Unique ID
				 RCDen = Density
				 RCCol = Colour
				 RCNam = Material Name*/
	void setMaterial(int RCMat, int RCDen, string RCCol,string RCNam);

	//Accessor Functions
	int getMatID();
				//return Material Unique ID

	int getDensity();
				//return Density

	string getName();
				//return Material Name

	string getColour();
				//return Colour in <string "HEX Color Code">
};

#endif
