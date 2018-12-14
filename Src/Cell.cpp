#include "Cell.h"


using namespace std;



void cell :: setCell(int ID, int m, string type){
      this->CellID = ID;
      this->material = m;
      this->type = type;	   
}

void cell :: setVertices(int v){
	
      this->p.push_back(v); 
	  
}

string cell :: getType() {
	  return this->type;
}

int cell :: getCellID() {
	  return this->CellID;
}

int cell :: getMaterialID() {
	  return this->material;
}

int cell :: getVerticesID(int n) {
	return this->p[n];
}

//vector<Material>& CellMaterials
//CellMaterials[material].getDensity()

//vector<Vector>& CellVertices
//CellVertices[p[0]].getx()


void cell :: setV(vector<Vector>& CellVertices) {
	Vector *V = new Vector;
	for (int Vertex = 0; Vertex < p.size(); Vertex++) {
		*V = CellVertices[p[Vertex]];
		v.push_back(*V);
	}
}

std::vector<Vector> cell :: getV() {
	return v;

}



/*double cell :: getweight( Model *m ) {

      Material mat = m->getMaterial( this->material )；
      //Materials[ID].getDensity

      return volume * mat->Density;
}

double cell :: getcentre() {
      return 0;
}*/


/*Member class tetrahedron functions*/
//store tetrahedron veteces
/*void tetrahedron :: setTetrahedron(int p[4]) {
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
/*void pyramid :: setPyramid(int p[5]) {
      this->p = new int [5];
      for (i = 0, i < 5, i++){
            this->p[i] = p[i];
      }
}


/*double pyramid :: getvolume() {

}

double pyramid :: getcentre() {

}*/


/*Member class hexahedron functions*/
//store hexaahedron veteces
/*void hexahedron :: setHexahedron(int p[8]) {

      this->p = new int [8];
	  for (int i = 0; i < 8; i++) {
            this->p[i] = p[i];
      }
}

/*double hexahedron :: getvolume() {

}

double hexahedron :: getcentre() {

}*/
