#include <string>
#include <iostream>

using namespace std;

#include "Material.h"

int main() {
  string NAME;
	Material Mat1;
	string Col;
	int id;
	int den;
  while(1){
	cout << "What is your Material ID" << endl;
	cin >> id;
	cout << "What is your Density" << endl;
	cin >> den;
	cout << "What is your Colour" << endl;
	cin >> Col;
	cout << "What is your Material Name" << endl;
	cin >> NAME;

	Mat1.setMaterial(id, den, Col, NAME);
	cout << "Your Material:" << endl << "	ID: " << Mat1.getMatID() << endl
		<< "	Density: " << Mat1.getDensity() << endl
		<< "	Colour: " << Mat1.getColour() << endl
		<< "	Name: " << Mat1.getName() << endl;
}
}
