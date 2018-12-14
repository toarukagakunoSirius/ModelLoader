#include "Main.h"

int main(void)
{
	string FileName = "ExampleModel2.mod";
	Model M(FileName);

	cout << "The number of vertices = " << M.NumberVertices() << endl;
	M.NumberCells();
	M.FindCentre();
	M.GetCellVolume(0);
	

	return 0;
}
