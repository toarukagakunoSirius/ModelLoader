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

	Vertices = new Vector[CapV];
	Materials = new Material[CapM];
	Cells = new Cell[CapC];

	CapV = 0, CapM = 0, CapC = 0;
	file.open(FileName);
	while (getline(file, data)) {
		line = data[0];
		if (line == "v") {
			SetVertices(data, CapV);
			CapV++;
		}
		else if (line == "m") {
			SetMaterial(data, CapM);
			CapM++;
		}
		else if (line == "c") {
			SetCell(data, CapC);
			CapC++;
		}
	}
	file.close();
}
string Model::SetCell(string data, int CapV) {
	istringstream iss(data);
	vector<std::string> results((std::istream_iterator<std::string>(iss)),
		istream_iterator<std::string>());

	Cells[CapV].ID = stoi(results[1]);

}
string Model::SetVertices(string data, int CapV) {
	istringstream iss(data);
	vector<std::string> results((std::istream_iterator<std::string>(iss)),
		istream_iterator<std::string>());

	Vertices[CapV].ID = stoi(results[1]);
	Vertices[CapV].X = stof(results[2]);
	Vertices[CapV].Y = stof(results[3]);
	Vertices[CapV].Z = stof(results[4]);
}
string Model::SetMaterial(string data, int CapM) {

	istringstream iss(data);
	vector<string> results((istream_iterator<string>(iss)),
		istream_iterator<string>());
	int ID = stoi(results[1]);
	int Density = stoi(results[2]);
	string Name = results[4];
	string Colour = results[3];

	Materials[CapM].setMaterial(ID, Density, Colour, Name);

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