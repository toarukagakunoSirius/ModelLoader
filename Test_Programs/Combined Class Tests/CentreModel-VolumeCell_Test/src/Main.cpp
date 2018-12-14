#include "Main.h"

int main(void)
{
	cout << "Model Name: ";
	cin >> FileName; //Prompt user to input filename
	//string FileName = "ExampleModel2.mod";
	Model M(FileName);

	//Number of vertices
	cout << "The number of vertices = " << M.NumberVertices() << endl;

	//Number of each type of shape
	NumCells = M.NumberCells();
	cout << "There are " << NumCells[0] << " Pyramid Cells" << endl;
	cout << "There are " << NumCells[1] << " Tetrahedron Cells" << endl;
	cout << "There are " << NumCells[2] << " Hexahedron Cells" << endl;

	//Find Centre
	centre = M.FindCentre();
	cout << "\n Centre of model \n" << "X: " << centre[0] << " Y: " << centre[1] << " Z: " << centre[2] << endl; // Print out the centre of the model

	//Find Volume 
	Volume = M.GetCellVolume(0); //Input cell ID here
	cout << "\nVolume of cell 0 =" <<Volume<<endl;
	

	return 0;
}
