#include <string>//For string type
#include <iostream>//For cout and cin

using namespace std;//For std::

#include "Material.h"

/*Test File
Typing your Material information
This will keep getting information and display that infomation on CMD*/
int main() {
  //Test Variable
  string NAME;
	Material Mat1;
	string Col;
	int id;
	int den;

  //Infinity loop
  while(1){

  //Getting Information
	cout << "What is your Material ID(Integer Number)" << endl;
	cin >> id;
	cout << "What is your Density(Integer Number)" << endl;
	cin >> den;
	cout << "What is your Colour" << endl;
	cin >> Col;
	cout << "What is your Material Name" << endl;
	cin >> NAME;

  //Create Material
	Mat1.setMaterial(id, den, Col, NAME);

  //Display on CMD
	cout << "Your Material:" << endl << "	ID: " << Mat1.getMatID() << endl
		<< "	Density: " << Mat1.getDensity() << endl
		<< "	Colour: " << Mat1.getColour() << endl
		<< "	Name: " << Mat1.getName() << endl;
  }
}
