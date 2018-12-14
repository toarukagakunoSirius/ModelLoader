#include "Cell.h"
#include <string>
#include <iostream>

int main(void) {
	cell c;
	c.setCell(1, 0, "h");
	for (int i = 0; i < 8; i++) {
		c.setVertices(i);
	}

	for (int i = 0; i < 8; i++) {
		cout << "vetices: " << c.getVerticesID(i) << endl;
	}
	cout << "cellID: " << c.getCellID() << endl;
	cout << "materialID: " << c.getMaterialID() << endl;
	cout << "type: " << c.getType() << endl;
	return 0;
}