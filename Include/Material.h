#include <string>

using namespace std;

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
