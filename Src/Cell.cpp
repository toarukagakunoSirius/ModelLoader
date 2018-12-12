#include <iostream>
#include <string>
#include "Material.h"
#include "Cell.h"
#include "Model.h"
#include "Vector.h"

using namespace std;

/*----------------------------------------------------------------------------*/

void cell::setCell(int ID, int m, string type){
      this->CellID = ID;
      this->material = m;
      this->type = type;
	  cout << "test";
}

/*double cell :: getvoulume() {
      return 0;
}

double cell :: getweight( Model *m ) {

      Material mat = m->getMaterial( this->material )；
      //Materials[ID].getDensity

      return volume * mat->Density;
}

double cell :: getcentre() {
      return 0;
}*/

/*----------------------------------------------------------------------------*/

void tetrahedron::setTetrahedron(int p[4]) {
      p = new int [4];
	  for (int i = 0; i < 4; i++) {
            p[i] = p[i];
      }
}

/*double tetrahedron :: getvolume(int id, ) {

}

double tetrahedron :: getcentre() {

}*/

/*----------------------------------------------------------------------------*/

void pyramid::setPyramid(int p[5]) {
      p = new int [5];
	  for (int i = 0; i < 5; i++) {
            p[i] = p[i];
      }
}


/*double pyramid :: getvolume() {

}

double pyramid :: getcentre() {

}*/

/*----------------------------------------------------------------------------*/

void hexahedron::setHexahedron(int p[8]) {
      this->p = new int [8];
	  for (int i = 0; i < 8; i++) {
            this->p[i] = p[i];
      }
}

/*double hexahedron :: getvolume() {

}

double hexahedron :: getcentre() {

}*/
