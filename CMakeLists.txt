cmake_minimum_required(VERSION 3.3 FATAL_ERROR)

foreach(p
    CMP0071 # 3.10: Let AUTOMOC and AUTOUIC process GENERATED files
    )
  if(POLICY ${p})
    cmake_policy(SET ${p} NEW)
  endif()
endforeach()

project( Model )


set( CMAKE_INCLUDE_CURRENT_DIR ON )

include_directories( include )


set( CMAKE_AUTOMOC ON )
set( CMAKE_AUTOUIC ON )

find_package( Qt5Widgets )

set( UIS include/mainwindow.ui)
qt5_wrap_ui( UI_Srcs ${UIS} )

find_package( VTK REQUIRED )
include( ${VTK_USE_FILE} )
# Create library

# 2 requirements

# output library name and File input for library
add_library( vector STATIC src/Vector.cpp)
add_library( material STATIC src/Material.cpp )
add_library( cell STATIC src/Cell.cpp )
add_library( model STATIC src/Model.cpp )
add_library( hexahedron STATIC src/Hexahedron.cpp )

add_executable(Model_Test MACOSX_BUNDLE
  include/main.h
  include/Cell.h
  include/Model.h
  include/Material.h
  include/Vector.h
  include/Hexahedron.h
  include/mainwindow.h
  src/mainwindow.cpp
  src/Main.cpp
  ${UI_Srcs}
)

# Create executable

# 2 requirements

# output exe name and Test file

#add_executable( Test vectortest.cpp )
#add_executable( Model_Test Main.cpp )



# For link output and library
target_link_libraries( Model_Test  Qt5::Widgets )

# Tell CMake that the executable depends on the VTK libraries
target_link_libraries( Model_Test  ${VTK_LIBRARIES} )
target_link_libraries( Model_Test
								model
								vector
								material
								cell
								hexahedron
								)
# Tell CMake that the executable depends on the Qt::Widget libraries.

