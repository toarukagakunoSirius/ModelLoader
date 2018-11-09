#include <iostream>
//#include "Material.h"
#include "Cell.h"
//#include "Model.h"

using namespace std;

/*----------------------------------------------------------------------------*/

cell :: cell(int ID, int m, int type){
      this->CellID = ID;
      this->material = m;
      this->type = type;
}

double cell :: getvoulume() {
      return 0;
}

cell.getWeight()


double cell :: getweight(double volume,int material) {

      return volume * Material.getDensity(material);
}

double cell :: getcentre() {
      return 0;
}

/*----------------------------------------------------------------------------*/

tetrahedron :: tetrahedron(int p[4]) {
      this->p = new int [4];
      for (i = 0, i < 4, i++){
            this->p[i] = p[i];
      }
}

double tetrahedron :: getvolume(int id, ) {

}

double tetrahedron :: getcentre() {

}

/*----------------------------------------------------------------------------*/

pyramid :: pyramid(int p[5]) {
      this->p = new int [5];
      for (i = 0, i < 5, i++){
            this->p[i] = p[i];
      }
}
}

double pyramid :: getvolume() {

}

double pyramid :: getcentre() {

}

/*----------------------------------------------------------------------------*/

hexahedron :: hexahedron(int p[8]) {
      this->p = new int [8];
      for (i = 0, i < 8, i++){
            this->p[i] = p[i];
      }
}

double hexahedron :: getvolume() {

}

double hexahedron :: getcentre() {

}
