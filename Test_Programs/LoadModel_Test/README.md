BUILD INSTRUCTIONS

A test which shows simple functionality of all classes linked together and it reading the model file and returning the number of vertices and cells with their specific type

Run the following commands
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
1)	>mkdir build
2)	>cd build
3)	>cmake -G "Visual Studio 15 2017 Win64" ..
4)	>"C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise\VC\Auxiliary\Build\vcvarsall.bat" amd64
5)	>msbuild Model.sln
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

*Place the Model file to load in the same directory as the executable*

EXPECTED OUTPUT
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
>The number of vertices = 301
>There are 0 Pyramid Cells
>There are 0 Tetrahedron Cells
>There are 129 Hexahedron Cells
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
