**BUILD INSTRUCTIONS**

This test shows the centre of model and volume of cell functionality 

Run the following commands
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
1)	>mkdir build
2)	>cd build
3)	>cmake -G "Visual Studio 15 2017 Win64" ..
4)	>"C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise\VC\Auxiliary\Build\vcvarsall.bat" amd64
5)	>msbuild Model.sln
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

*Place the Model file to load in the same directory as the executable*
*Test carried out using "ExampleModel2.mod" model file*

EXPECTED OUTPUT
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Model Name: ExampleModel2.mod
The number of vertices = 301
There are 0 Pyramid Cells
There are 0 Tetrahedron Cells
There are 129 Hexahedron Cells

 Centre of model
X: 0.00498937 Y: 0.00236761 Z: 0.00150169

Volume of cell 0 =2.71429e-09
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
