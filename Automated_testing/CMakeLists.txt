cmake_minimum_required(VERSION 3.3 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 17)


project( Model )
include(CTest)



include_directories(../include )

# 2 requirements

# output library name and File input for library


set( CMAKE_INCLUDE_CURRENT_DIR ON )

add_library( Model
  ../include/cell.h
  ../include/model.h
  ../include/material.h
 ../include/vector.h
  ../include/hexahedron.h
  ../include/tetrahedron.h
  ../include/pyramid.h
  ../src/model.cpp
  ../src/vector.cpp
  ../src/material.cpp
  ../src/cell.cpp
  ../src/hexahedron.cpp
  ../src/tetrahedron.cpp
  ../src/pyramid.cpp


)

add_executable(Model_Test test.cpp model_test.cpp)



target_link_libraries( Model_Test Model )

add_test(Model_Test Model_Test)
