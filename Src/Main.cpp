include "Main.h"

int main(void)
{
	string FileName = "ExampleModel2.mod";
	Model M(FileName);

	cout << "The number of vertices = " << M.NumberVertices() << endl;
	M.NumberCells();

	return 0;
}
