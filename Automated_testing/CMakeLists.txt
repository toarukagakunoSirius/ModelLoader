cmake_minimum_required(VERSION 3.3 FATAL_ERROR)



project( Model )
include(CTest)

set( CMAKE_INCLUDE_CURRENT_DIR ON )

include_directories(../include )









# 2 requirements

# output library name and File input for library
add_library( vector STATIC ../src/Vector.cpp)
add_library( material STATIC ../src/Material.cpp )
add_library( cell STATIC ../src/Cell.cpp )
add_library( model STATIC ../src/Model.cpp )
add_library( hexahedron STATIC ../src/Hexahedron.cpp )
add_library( tetrahedron STATIC ../src/Tetrahedron.cpp )
add_library( pyramid STATIC ../src/Pyramid.cpp )

add_executable(Model_Test MACOSX_BUNDLE
  ../include/Cell.h
  ../include/Model.h
  ../include/Material.h
 ../include/Vector.h
  ../include/Hexahedron.h
  ../include/Tetrahedron.h
  ../include/pyramid.h
  catch.hpp
  Model_Test.cpp
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
