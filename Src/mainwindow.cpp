#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    // standard call to setup Qt UI (same as previously)
    ui->setupUi( this );

    //Create the render window
    vtkNew<vtkGenericOpenGLRenderWindow> renderWindow; //New render window
    ui->qtvtkWidget->SetRenderWindow( renderWindow );	 //Assign window to Qtwidget in mainwindow.ui	
    renderer = vtkSmartPointer<vtkRenderer>::New(); //Create a smartpointer pointing to the window renderer
    ui->qtvtkWidget->GetRenderWindow()->AddRenderer( renderer );						
    renderer->ResetCamera(); //Set the camera back to origin


    // Create Shrink Filter variable
    shrinkFilter = vtkSmartPointer<vtkShrinkFilter>::New();

    // P: Waiting to be edited
    //shrinkFilter->SetInputDataObject(0,Grid);
    //mapper = vtkSmartPointer<vtkDataSetMapper>::New();
    //mapper->SetInputConnection( shrinkFilter->GetOutputPort() );

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ShrinkFilter_sliderMoved(int position)
{
    shrinkFilter->SetShrinkFactor( (float) (100 - ui -> ShrinkFilter -> value())/ 100);
    shrinkFilter->Update();
    // P: Waiting to be edited
    //ui->qvtkWidget->GetRenderWindow()->Render();
}

