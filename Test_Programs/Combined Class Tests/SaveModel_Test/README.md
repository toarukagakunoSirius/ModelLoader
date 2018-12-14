**BUILD INSTRUCTIONS**

This test shows that the model can be loaded, stored in classes then saved into a new model file

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
*Output File = Model.mod*

EXPECTED OUTPUT
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Model Name: ExampleModel2.mod
Saving...
Finished Saving to Model.mod
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
