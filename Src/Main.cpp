// main.cpp-------------------------------------------------------------------

#include "Main.h"

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
