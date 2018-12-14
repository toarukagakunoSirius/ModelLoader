
#this is the cmakelists file for vector class
cmake_minimum_required( VERSION 2.8 )

project( Cell )
#project( Material )


# Create library 

# 2 requirements

# output library name and File input for library

add_library( cell STATIC Src/Cell.cpp)


include_directories(Include)

add_executable(Cell_Test
  src/celltest.cpp
  include/Cell.h
  
)

# Create executable

# 2 requirements

# output exe name and Test file

#add_executable( Test vectortest.cpp )
#add_executable( Model_Test Main.cpp )



# For link output and library

target_link_libraries( Cell_Test cell)
#target_link_libraries( Test material )







