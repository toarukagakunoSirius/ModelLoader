// main.cpp-------------------------------------------------------------------

#include "Main.h"
/** @file
	* This file contains the declarations of all exported functions.
	*/
	/** Brief description
	* This description will hopefully be picked up on by doxygen
	*/
int main( int argc, char** argv )
{
		
	

    //Initiate QT stuff

    // needed to ensure appropriate OpenGL context is created for VTK rendering.
    QSurfaceFormat::setDefaultFormat( QVTKOpenGLWidget::defaultFormat() );
    QApplication a( argc, argv );
    MainWindow window;
    window.show();
    return a.exec();
}
// /main.cpp------------------------------------------------------------------
