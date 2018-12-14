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