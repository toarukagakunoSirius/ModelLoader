#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "Vector.h"

using namespace std;

/*Class cell*/
class cell {
protected:
      int CellID, material;
      string type;
      vector<int> p;                         //vector storing verticesID
	  vector<Vector> v;      //vector storing vertices used in this cell
public:
      void setCell(int ID, int m, string type); //store cellID, matID and cell type
      void setVertices(int v);                           //store verticesID
	  string getType();                       //return cell type, cellID, materialID and verticesID
	  int getCellID();
	  int getMaterialID();
	  int getVerticesID(int n);
	  void setV(int id, double x, double y, double z);     //store vertices used in this cell
	  std::vector<Vector> getV();                                     //return vertices stored in this cell
};