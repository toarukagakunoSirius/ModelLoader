cmake_minimum_required(VERSION 3.3 FATAL_ERROR)



project( Model )
include(CTest)

set( CMAKE_INCLUDE_CURRENT_DIR ON )

include_directories(../Include )









# 2 requirements

# output library name and File input for library
add_library( Vector STATIC ../Src/Vector.cpp)
add_library( Material STATIC ../Src/Material.cpp )
add_library( Cell STATIC ../Src/Cell.cpp )
add_library( Model STATIC ../Src/Model.cpp )
add_library( Hexahedron STATIC ../Src/Hexahedron.cpp )
add_library( Tetrahedron STATIC ../Src/Tetrahedron.cpp )
add_library( Pyramid STATIC ../Src/Pyramid.cpp )

add_executable(Model_Test MACOSX_BUNDLE
  ../Include/Cell.h
  ../Include/Model.h
  ../Include/Material.h
 ../Include/Vector.h
  ../Include/Hexahedron.h
  ../Include/Tetrahedron.h
  ../Include/pyramid.h
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
