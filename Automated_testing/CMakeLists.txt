cmake_minimum_required(VERSION 3.3 FATAL_ERROR)



project( Model )
include(CTest)

set( CMAKE_INCLUDE_CURRENT_DIR ON )

include_directories(../include )









# 2 requirements

# output library name and File input for library
add_library( vector STATIC ../Src/Vector.cpp)
add_library( material STATIC ../Src/Material.cpp )
add_library( cell STATIC ../Src/Cell.cpp )
add_library( model STATIC ../Src/Model.cpp )
add_library( hexahedron STATIC ../Src/Hexahedron.cpp )
add_library( tetrahedron STATIC ../Src/Tetrahedron.cpp )
add_library( pyramid STATIC ../Src/Pyramid.cpp )

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
