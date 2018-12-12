#include "Main.h"

int main(void)
{
	string FileName = "ExampleModel2.mod";
	Model M(FileName);
	M.GetMaterial(0);
	return 0;
}
