#include "Main.h"

int main(void)
{
	cout << "Model Name: ";
	cin >> FileName; //Prompt user to input filename
	//string FileName = "ExampleModel2.mod";
	Model M(FileName);

	M.SaveModel(); //Save model
	

	return 0;
}
