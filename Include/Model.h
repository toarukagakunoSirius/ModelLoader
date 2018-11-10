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
	int VNum = 0, MNum = 0, CNum = 0;
	Vector *Vertices;
	Material *Materials;
	Cell *Cells;
	string FileName = "ExampleModel2.mod";
public:
	Model();
	~Model();
	int SaveModel(void);
	void LoadModel(void);
	string SetCell(string data, int VNum);
	string SetVertices(string data, int VNum);
	string SetMaterial(string data, int MNum);
	string GetCell(int c);
	string GetVertices(int v);
	string GetMaterial(int m);
	int Count();
	int FindCentre(void);


};

