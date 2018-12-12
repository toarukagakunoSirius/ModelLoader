#include "Model.h"
#include <vector>
Model::Model(string FileName) {
	LoadModel(FileName);
}
Model::~Model() {
	//delete[]Vertices;
	//delete[]Cells;
	//delete[]Materials;
}
int Model::SaveModel(void) {
	return 0;
}
void Model::LoadModel(string FileName) {
	string line, data;
	ifstream file;
	
	vector<Vector> Vertices;
	vector<Material> Materials;
	vector<cell> VectorCell;
	

	file.open(FileName);
	while (getline(file, data)) { //Read each line and send data to classes
		line = data[0];
		
		if (line == "v") {
			SetVertices(data); //
			
		
		}
		else if (line == "m") {
			SetMaterial(data);
			
		}
		else if (line == "c") {
			SetCell(data);
		}
	}
	file.close();
}
void Model::SetCell(string data) {
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
	C->setCell(ID, MaterialID, Type);
	VectorCell.push_back(*C);

	if (Type == "h") {
		cell *C = new cell;
		for (int i = 0; i < 8; i++) {
			C->setVertices(stoi(results[i + 4]));
		}
		
	
	} 
	else if (Type == "p") {
		cell *C = new cell;
		for (int i = 0; i < 5; i++) {
			
			C->setVertices(stoi(results[i + 4]));
		}
		
		
	}
	else if (Type == "t") {
		cell *C = new cell;

		for (int i = 0; i < 4; i++) {
			
			C->setVertices(stoi(results[i + 4]));
		}
		
		
	}

}
void Model::SetVertices(string data) {
	istringstream iss(data);
	vector<std::string> results((std::istream_iterator<std::string>(iss)),
		istream_iterator<std::string>());
	int ID = stoi(results[1]);
	float X = stof(results[2]);
	float Y = stof(results[3]);
	float Z = stof(results[4]);

	Vector *V = new Vector;
	V->SetVector(ID, X, Y, Z);
	Vertices.push_back(*V);
}
void Model::SetMaterial(string data) {

	istringstream iss(data);
	vector<string> results((istream_iterator<string>(iss)),
		istream_iterator<string>());
	int ID = stoi(results[1]);
	int Density = stoi(results[2]);
	string Name = results[4];
	string Colour = results[3];

	//Materials[NumN].setMaterial(ID, Density, Colour, Name);

	Material *M = new Material;
	M->setMaterial(ID, Density, Colour, Name);
	Materials.push_back(*M);
}
string Model::GetCell(int ID, string Type) {
	/*if (Type == "p") {
		if (ID <= pyramids.size())
			return pyramids[ID] <-ID;
	}
	else if (Type == "t") {

	}
	else if (Type == "h") {

	}
	else
		cout << "Type not Found" << endl;*/
	return "";
}
void Model::GetVertices(int ID) {
	float x = Vertices[ID].getx();
	float y = Vertices[ID].gety();
	float z = Vertices[ID].getz();
}
void Model::GetMaterial(int ID) {
	int ID2 = Materials[ID].getMatID();
	string Colour = Materials[ID].getColour();
	string Name = Materials[ID].getName();
	int Density = Materials[ID].getDensity();
}
void Model::FindCentre(void) {
}