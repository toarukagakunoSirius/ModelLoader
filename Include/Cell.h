#include <stdio.h>
using namespace std;

/*----------------------------------------------------------------------------*/

class cell {
protected:
      int CellID, material;
      string type;
      int* p;
public:
      setCell(int ID, int m, string type);
      //virtual double getvolume();
      //double getweight(double volume);
      //virtual double getcentre();
}

/*----------------------------------------------------------------------------*/

class tetrahedron : public cell {
public:
      setTetrahedron(int p[4]);
      //double getvolume();
      //double getcentre();
}

/*----------------------------------------------------------------------------*/

class pyramid : public cell {
public:
      setyPyramid(int p[5]);
      //double getvolume();
      //double getcentre();
}

/*----------------------------------------------------------------------------*/

class hexahedron : public cell {
public:
      setHexahedron(int p[8]);
      //double getvolume();
      //double getcentre();
}
