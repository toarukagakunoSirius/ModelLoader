#include <iostream>
#include <string>
#include "Material.h"
#include "Cell.h"
#include "Model.h"
#include "Vector.h"

using namespace std;


/*Class cell functions*/

//store cellID, matID and cell type
void cell :: setCell(int ID, int m, string type){
      this->CellID = ID;
      this->material = m;
      this->type = type;
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


/*Member class tetrahedron functions*/
//store tetrahedron veteces
void tetrahedron :: setTetrahedron(int p[4]) {
      this->p = new int [4];
      for (i = 0, i < 4, i++){
            this->p[i] = p[i];
      }
}

/*double tetrahedron :: getvolume(int id, ) {

}

double tetrahedron :: getcentre() {

}*/


/*Member class pyramid functions*/
//store pyramid veteces
void pyramid :: setPyramid(int p[5]) {
      this->p = new int [5];
      for (i = 0, i < 5, i++){
            this->p[i] = p[i];
      }
}
}

/*double pyramid :: getvolume() {

}

double pyramid :: getcentre() {

}*/


/*Member class hexahedron functions*/
//store hexaahedron veteces
void hexahedron :: setHexahedron(int p[8]) {
      this->p = new int [8];
      for (i = 0, i < 8, i++){
            this->p[i] = p[i];
      }
}

/*double hexahedron :: getvolume() {

}

double hexahedron :: getcentre() {

}*/
