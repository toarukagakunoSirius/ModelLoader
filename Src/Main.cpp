// main.cpp-------------------------------------------------------------------
#include <QApplication>
#include <QSurfaceFormat>
#include <QVTKOpenGLWidget.h>
#include "mainwindow.h"
#include "Main.h"

int main( int argc, char** argv )
{
  string FileName = "ExampleModel2.mod";
  Model M(FileName);

  cout << "The number of vertices = " << M.NumberVertices() << endl;
  M.NumberCells();
	
  // needed to ensure appropriate OpenGL context is created for VTK rendering.
  QSurfaceFormat::setDefaultFormat( QVTKOpenGLWidget::defaultFormat() );

  QApplication a( argc, argv );

  MainWindow window;
  window.show();

  return a.exec();
}
// /main.cpp------------------------------------------------------------------