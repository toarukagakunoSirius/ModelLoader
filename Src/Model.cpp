#include "Model.h"

Model::Model() {
	LoadModel();
}
Model::~Model() {
	delete[]Vertices;
	delete[]Cells;
	delete[]Materials;
}
int Model::SaveModel(void) {
}
void Model::LoadModel(void) {
	string line, data;
	ifstream file;
	Count(); //Counts the number of materials,cells and vertices

	Vertices = new Vector[CapV]; //Create multiple objects of class type Vector
	Materials = new Material[CapM];
	Cells = new Cell[CapC];

	
	file.open(FileName);
	while (getline(file, data)) { //Read each line and send data to classes
		line = data[0];
		if (line == "v") {
			SetVertices(data, VNum); //
			CapV++;
		}
		else if (line == "m") {
			SetMaterial(data, MNum);
			CapM++;
		}
		else if (line == "c") {
			SetCell(data, CNum);
			CapC++;
		}
	}
	file.close();
}
string Model::SetCell(string data, int NumC) {
	istringstream iss(data);
	vector<std::string> results((std::istream_iterator<std::string>(iss)),
		istream_iterator<std::string>());

	int Vertices_List[sizeof(results)];
	for (int i = 0; i < sizeof(results); i++) {
		Vertices_List[i] = stoi(results[i + 3]);
	}
	
	int ID = stoi(results[1]);
	string Type = results[2];
	int MaterialID = stoi(results[3]);
	Cells[NumC].setCells(ID, MaterialID, Type);

	if (Type == "h") {
		int Vertices_List[8];
		for (int i = 0; i < 8; i++) {
			Vertices_List[i] = stoi(results[i + 4]);
		}
		Cells[NumC].setHexahedron(Vertices_List);
	}
	else if (Type == "p") {
		int Vertices_List[5];
		for (int i = 0; i < 5; i++) {
			Vertices_List[i] = stoi(results[i + 4]);
		}
		Cells[NumC].setPyramid(Vertices_List);
	}
	else if (Type == "t") {
		int Vertices_List[4];
		for (int i = 0; i < 4; i++) {
			Vertices_List[i] = stoi(results[i + 4]);
		}
		Cells[NumC].setTetrahedron(Vertices_List);
	}

}
string Model::SetVertices(string data, int NumV) {
	istringstream iss(data);
	vector<std::string> results((std::istream_iterator<std::string>(iss)),
		istream_iterator<std::string>());
	int ID = stoi(results[1]);
	int X = stof(results[2]);
	int Y = stof(results[3]);
	int Z = stof(results[4]);

	Vertices[NumV].setVertices(ID, X, Y, Z);
}
string Model::SetMaterial(string data, int NumM) {

	istringstream iss(data);
	vector<string> results((istream_iterator<string>(iss)),
		istream_iterator<string>());
	int ID = stoi(results[1]);
	int Density = stoi(results[2]);
	string Name = results[4];
	string Colour = results[3];

	Materials[NumN].setMaterial(ID, Density, Colour, Name);

}
string Model::GetCell(int c) {
}
string Model::GetVertices(int v) {
}
string Model::GetMaterial(int m) {
}
int Model::Count() {
	string line, data;
	ifstream file;
	file.open(FileName);
	if (!file) {
		cerr << "Unable to open file datafile.txt";
		exit(1);   // call system to stop
	}
	while (getline(file, data)) {
		line = data[0];
		if (line == "v")
			++CapV;
		else if (line == "m")
			++CapM;
		else if (line == "c")
			++CapC;
	}
	file.close();
}
int Model::FindCentre(void) {
}