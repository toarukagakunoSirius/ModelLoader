
#this is the cmakelists file for vector class
cmake_minimum_required( VERSION 2.8 )

project( Cell_Calculation )
#project( Material )


# Create library 

# 2 requirements

# output library name and File input for library

add_library( cell STATIC Src/Cell.cpp)
add_library( vector STATIC Src/Vector.cpp)
add_library( tetrahedron STATIC Src/Tetrahedron.cpp)
add_library( pyramid STATIC Src/Pyramid.cpp)
add_library( hexahedron STATIC Src/Hexahedron.cpp)

include_directories(Include)

add_executable(Cell_Calculation
  Src/celltest+.cpp
  include/Cell.h
  include/Vector.h
  include/Tetrahedron.h
  include/Pyramid.h
  include/Hexahedron.h
)

# Create executable

# 2 requirements

# output exe name and Test file

#add_executable( Test vectortest.cpp )
#add_executable( Model_Test Main.cpp )



# For link output and library

target_link_libraries( Cell_Calculation cell vector tetrahedron pyramid hexahedron)
#target_link_libraries( Test material )







