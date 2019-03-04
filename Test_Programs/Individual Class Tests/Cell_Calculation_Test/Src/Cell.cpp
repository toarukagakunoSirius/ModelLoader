#include "Cell.h"

using namespace std;

//store cellID, matID and cell type
void cell :: setCell(int ID, int m, string type){
      this->CellID = ID;
      this->material = m;
      this->type = type;	   
}

//store verticesID
void cell :: setVertices(int v){
      this->p.push_back(v);
}

//return cell type, cellID, materialID and verticesID
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

//store vertices used in this cell
//getting values from pointers of Vector class
void cell :: setV(int id, double x, double y, double z) {
	Vector *V = new Vector;
	V->SetVector(id, x, y, z);
	v.push_back(*V);
}

//return vertices stored in this cell
std::vector<Vector> cell :: getV() {
	return v;
}