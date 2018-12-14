#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*Class cell*/
class cell {
protected:
      int CellID, material;
      string type;
      vector<int> p;                                        //vector storing verticesID
public:
      void setCell(int ID, int m, string type); //store cellID, matID and cell type
      void setVertices(int v);                          //store verticesID
};


class Pyramid : public cell {
	
};

class Tetrahedron : public cell {

};

class Hexahedron : public cell {

};