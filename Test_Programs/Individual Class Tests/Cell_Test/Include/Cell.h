#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*Class cell*/
class cell {
protected:
      int CellID, material;
      string type;
      vector<int> p;                            //vector storing verticesID
public:
      void setCell(int ID, int m, string type); //store cellID, matID and cell type
      void setVertices(int v);                          //store verticesID
	  string getType();                       //return cell type, cellID, materialID and verticesID
	  int getCellID();
	  int getMaterialID();
	  int getVerticesID(int n);
};