#include <iostream>
#include <fstream>
#include <string>
#include <vector>   //for std::vector
#include <sstream>  //for std::istringstream
#include <iterator> //for std::istream_iterator
#include "Cell.h"
#include "Vector.h"
#include "Material.h"

using namespace std;

class Model
{
private:
	vector<Vector> Vertices;
	vector<Material> Materials;
	vector<cell> VectorCell;

public:
	Model(string FileName);
	~Model();
	int SaveModel(void);
	void LoadModel(string FileName);
	void SetCell(string data);
	void SetVertices(string data);
	void SetMaterial(string data);
	string GetCell(int ID, string Type);
	void GetVertices(int ID);
	void GetMaterial(int ID);
	void FindCentre(void);
	int NumberVertices(void);


};

