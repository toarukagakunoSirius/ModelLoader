BUILD INSTRUCTIONS

Test program for calculations of cell volume and centre
The input is specified with variables in the celltest+.cpp 

Run the following commands
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
1)	>mkdir build
2)	>cd build
3)	>cmake -G "MinGW Makefiles" ..
4)	>mingw32-make
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


EXPECTED OUTPUT
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
volume t1: 10
centre t1: 3.75, 2, 4.75
volume p1: 0.904763
centre p1: 2.35, 1.55, 0.957142
volume h1: 1.80953
centre h1: 2.45, 1.525, 0.142855

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
