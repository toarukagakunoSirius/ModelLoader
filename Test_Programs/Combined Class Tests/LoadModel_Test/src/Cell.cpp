
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








