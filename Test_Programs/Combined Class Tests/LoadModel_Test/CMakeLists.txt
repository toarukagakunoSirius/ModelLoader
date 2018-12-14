
#this is the cmakelists file for vector class
cmake_minimum_required( VERSION 2.8 )





project( Model )
#project( Material )



# Create library 

# 2 requirements

# output library name and File input for library

add_library( vector STATIC src/Vector.cpp)
add_library( material STATIC src/Material.cpp )
add_library( cell STATIC src/Cell.cpp )
add_library( model STATIC src/Model.cpp )

include_directories(include)

add_executable(Model_Test
  src/Main.cpp
  include/Main.h
  include/Cell.h
  include/Model.h
  include/Material.h
  include/Vector.h
)

# Create executable

# 2 requirements

# output exe name and Test file

#add_executable( Test vectortest.cpp )
#add_executable( Model_Test Main.cpp )



# For link output and library

target_link_libraries( Model_Test model 
								vector
								material
								cell)
#target_link_libraries( Test material )







