#include <iostream>
#include <fstream>
#include <string>
#include <vector>   //for std::vector
#include <sstream>  //for std::istringstream
#include <iterator> //for std::istream_iterator
#include "Cell.h"
#include "Vector.h"
#include "Material.h"
#include "Pyramid.h"
#include "Hexahedron.h"
#include "Tetrahedron.h"

using namespace std;

class Model
{
private:
	vector<Vector> Vertices;
	vector<Material> Materials;
	vector<cell> Cells;
	vector<Pyramid> Pyramids;
	vector<Hexahedron> Hexahedrons;
	vector<Tetrahedron> Tetrahedrons;
	float x, y, z;
public:
	Model(string FileName);
	~Model();
	void SaveModel(void);
	void LoadModel(string FileName);
	void SetCell(string data);
	void SetVertices(string data); 
	void SetMaterial(string data);
	int GetCell(int ID, string Type);
	void GetVertices(int ID);
	void GetMaterial(int ID);
	double GetCellVolume(int ID);
	vector<float> FindCentre(void);
	vector<int> NumberCells(void);
	int NumberVertices(void);
};

