cmake_minimum_required(VERSION 2.8.0)



project( Model )
include(CTest)



include_directories(../include )

# 2 requirements

# output library name and File input for library
add_library( Vector STATIC ../src/vector.cpp)
add_library( Material STATIC ../src/material.cpp )
add_library( Cell STATIC ../src/cell.cpp )
add_library( Model STATIC ../src/model.cpp )
add_library( Hexahedron STATIC ../src/hexahedron.cpp )
add_library( Tetrahedron STATIC ../src/tetrahedron.cpp )
add_library( Pyramid STATIC ../src/pyramid.cpp )

set( CMAKE_INCLUDE_CURRENT_DIR ON )

add_executable(Model_Test 
  ../include/cell.h
  ../include/model.h
  ../include/material.h
 ../include/vector.h
  ../include/hexahedron.h
  ../include/tetrahedron.h
  ../include/pyramid.h
  
  catch.hpp
  model_Test.cpp
  test.cpp

)



target_link_libraries( Model_Test
								model
								vector
								material
								cell
								hexahedron
								pyramid
								tetrahedron
								)

add_test(Model_Test Model_Test)
