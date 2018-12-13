cmake_minimum_required( VERSION 2.8 )

# Project name
project( Material )

# Create library 
# 2 requirements
# output library name and File input for library
add_library( material STATIC Src/Material.cpp )

include_directories(Inc)

# Create executable
# 2 requirements
# output exe name and Test file
add_executable( Creating_Material Material_Test.cpp
				    Inc/Material.h)

# For link output and library
target_link_libraries( Creating_Material material )
