cmake_minimum_required(VERSION 3.3 FATAL_ERROR)

foreach(p
    CMP0071 # 3.10: Let AUTOMOC and AUTOUIC process GENERATED files
    )
  if(POLICY ${p})
    cmake_policy(SET ${p} NEW)
  endif()
endforeach()

project( Model )
include(CTest)

set( CMAKE_INCLUDE_CURRENT_DIR ON )

include_directories( ../../include )


set( CMAKE_AUTOMOC ON )
set( CMAKE_AUTOUIC ON )






# 2 requirements

# output library name and File input for library
add_library( vector STATIC ../../src/Vector.cpp)
add_library( material STATIC ../../src/Material.cpp )
add_library( cell STATIC ../../src/Cell.cpp )
add_library( model STATIC ../../src/Model.cpp )
add_library( hexahedron STATIC ../../src/Hexahedron.cpp )

add_executable(Model_Test MACOSX_BUNDLE
  ../../include/Cell.h
  ../../include/Model.h
  ../../include/Material.h
  ../../include/Vector.h
  ../../include/Hexahedron.h

  catch.hpp
  Model_Test.cpp
  test.cpp

)

# Create executable

# 2 requirements

# output exe name and Test file



# For link output and library


# Tell CMake that the executable depends on the VTK libraries

target_link_libraries( Model_Test
								model
								vector
								material
								cell
								hexahedron
								)
# Tell CMake that the executable depends on the Qt::Widget libraries.

add_test(Model_Test Model_Test)
