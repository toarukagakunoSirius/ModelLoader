#include <vtkCubeSource.h>
#include <vtkSmartPointer.h>
#include <vtkActor.h>
#include <vtkNamedColors.h>
#include <vtkProperty.h>
#include <vtkCamera.h>
#include <vtkPolyData.h>
#include <vtkDataSetMapper.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkUnstructuredGrid.h>
#include <vtkRenderer.h>
#include <vtkNew.h>
#include <vtkTetra.h>
#include <vtkPoints.h>
#include <vtkCellArray.h>
#include <vtkCellType.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    // standard call to setup Qt UI (same as previously)
    ui->setupUi( this );

    //Create the render window
    vtkNew<vtkGenericOpenGLRenderWindow> renderWindow;
    ui->qtvtkWidget->SetRenderWindow( renderWindow );		
    renderer = vtkSmartPointer<vtkRenderer>::New();
    ui->qtvtkWidget->GetRenderWindow()->AddRenderer( renderer );						
    renderer->ResetCamera();
}

MainWindow::~MainWindow()
{
    delete ui;
}

