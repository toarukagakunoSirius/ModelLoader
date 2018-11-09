#include <iostream>
#include <fstream>
#include <string>
#include <vector>   //for std::vector
#include <sstream>  //for std::istringstream
#include <iterator> //for std::istream_iterator

using namespace std;

class Model
{
private:
	int CapV = 1, CapM = 1, CapC = 1;
	Vector *Vertices;
	Material *Materials;
	Cell *Cells;
	string FileName = "ExampleModel2.mod";
public:
	Model();
	~Model();
	int SaveModel(void);
	void LoadModel(void);
	string SetCell(string data, int CapV);
	string SetVertices(string data, int CapV);
	string SetMaterial(string data, int CapM);
	int Count();
	int FindCentre(void);


};

