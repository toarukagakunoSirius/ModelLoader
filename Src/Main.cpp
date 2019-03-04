// main.cpp-------------------------------------------------------------------
#include <QApplication>
#include <QSurfaceFormat>
#include <QVTKOpenGLWidget.h>
#include "mainwindow.h"
#include "Main.h"

int main( int argc, char** argv )
{
	//Load the model
  string FileName = "ExampleModel2.mod";
  Model M(FileName);


  //M.NumberVertices();				Return vertices
  //M.SaveModel(); 					Save model
  //NumCells = M.NumberCells(); 	No. Cells
  //M.FindCentre();					Return Centre of model

  
  //Initiate QT stuff
	
  // needed to ensure appropriate OpenGL context is created for VTK rendering.
  QSurfaceFormat::setDefaultFormat( QVTKOpenGLWidget::defaultFormat() );
  QApplication a( argc, argv );
  MainWindow window;
  window.show();
  return a.exec();
}
// /main.cpp------------------------------------------------------------------