# ﻿**H62PEP Computing Project - Group 2's group repository**

[![Build Status](https://travis-ci.com/edwardpercy/ModelLoader.svg?branch=master)](https://travis-ci.com/edwardpercy/ModelLoader)

## Documentation: [GitHub Pages](https://edwardpercy.github.io/ModelLoader/html/index.html)

## **MEMBERS**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Group 2 members: 
	> Hana 
	> Harry
	> Ed
	> P.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
For this project we will be designing and creating software to view 3D CAD models and simulate. It will be created using the QT and VTK libraries and written using C++. The program will be available for both Windows and Mac OS

## **ROLES**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
- Vector class: Hana
- Model class: Ed
- Cell class: Harry
- Material class: P
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

This repository will include 4 classes (.cpp and .h files) as well as a main.cpp file combining all classes and integrating them.
The repository will also include several test files for each class as well as one for the main.cpp file.
.a file will be included to compile as well as a cmake file
A .gitignore file is included

*How to Fetch/Push*
https://help.github.com/articles/syncing-a-fork/

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.
├── Include                 	# Contains header files (.h)
├── Resources               	# Contains and extra files needed 
├── Src                     	# Contains source files (.cpp)
├── Static_Library          	# Static library files build (.a)
├── Test_Programs           	# Cmake files for different test applications
│	│
│   	├── Individual Class Tests  
│	│   ├── Cell_Test           		# Tests basic functionality for the cell class
│	│   ├── Cell_Calculation_Test       # Tests cell volume calculations
│	│   ├── Material_Test       		# Basic functionality for the material class
│	│   ├── Vector_Test         		# Tests basic functionality for vectors 
│	│   └── Matrix_Test         		# Tests the matrix functionality
│	│
│   	└── Combined Class Tests    		 
│	    ├── LoadModel_Test      		 # Loads a file and outputs the number of cells/vertices
│	    └── CentreModel-CellVolume_Test  # Tests calculating model centre and cell volume
└── ...
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
