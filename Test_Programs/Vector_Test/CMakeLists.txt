cmake_minimum_required( VERSION 2.8 )

# Project name
project( Vector )

# Create library 
# 2 requirements
# output library name and File input for library
add_library( vector STATIC Src/Vector.cpp )

#Add include path
include_directories(Inc)

# Create executable
# 2 requirements
# output exe name and Test file
add_executable( Creating_Vertices vectortest.cpp
				    Inc/Vector.h)

# For link output and library
target_link_libraries( Creating_Vertices vector )
