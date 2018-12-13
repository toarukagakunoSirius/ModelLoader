
#this is the cmakelists file for vector class
cmake_minimum_required( VERSION 2.8 )





project( Model )
#project( Material )



# Create library 

# 2 requirements

# output library name and File input for library

add_library( vector STATIC Vector.cpp)
add_library( material STATIC Material.cpp )
add_library( cell STATIC Cell.cpp )
add_library( model STATIC Model.cpp )



# Create executable

# 2 requirements

# output exe name and Test file

#add_executable( Test vectortest.cpp )
add_executable( Model_Test Main.cpp )



# For link output and library

target_link_libraries( Model_Test model 
								vector
								material
								cell)
#target_link_libraries( Test material )





