cmake_minimum_required( VERSION 2.8 )

# Project name
project( Material )

# Create library 
# 2 requirements
# output library name and File input for library
add_library( material STATIC Material.cpp )

# Create executable
# 2 requirements
# output exe name and Test file
add_executable( Test Material_Test.cpp )

# For link output and library
target_link_libraries( Test material )
