#include <stdio.h>
using namespace std;

/*----------------------------------------------------------------------------*/

class cell {
protected:
      int CellID, material;
      char type;
      int* p;
public:
      cell(int ID, int m, char type);
      virtual double getvolume();
      double getweight(double volume);
      virtual double getcentre();
}

/*----------------------------------------------------------------------------*/

class tetrahedron : public cell {
public:
      tetrahedron(int p[4]);
      double getvolume();
      double getcentre();
}

/*----------------------------------------------------------------------------*/

class pyramid : public cell {
public:
      pyramid(int p[5]);
      double getvolume();
      double getcentre();
}

/*----------------------------------------------------------------------------*/

class hexahedron : public cell {
public:
      hexahedron(int p[8]);
      double getvolume();
      double getcentre();
}
