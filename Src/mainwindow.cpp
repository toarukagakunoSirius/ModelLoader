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

    //ModelLoader();



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


void MainWindow::ModelLoader(){
    //Load the model
    string FileName = "ExampleModel2.mod";
    Model M(FileName);
    vector<int> NumCells = M.NumberCells();
    cout << NumCells[2] << endl;




    for (int H = 0; H < NumCells[2]; H++ ){
        vector<int> CellVertices = M.GetCellVertices(H,"h");
        for (int V = 0; V < 8; V++){
            cout << CellVertices[V] << endl;
        }
    }


    for (int T = 0; T < NumCells[1]; T++ ){
        vector<int> CellVertices = M.GetCellVertices(T,"t");
        for (int T = 0; T < 4; T++){
            cout << CellVertices[T] << endl;
        }
    }

    for (int P = 0; P < NumCells[0]; P++ ){
        vector<int> CellVertices = M.GetCellVertices(P,"p");
        for (int P = 0; P < 5; P++){
            cout << CellVertices[P] << endl;
        }
    }


    //M.NumberVertices();				Return vertices
    //M.SaveModel(); 					Save model
    //NumCells = M.NumberCells(); 	No. Cells
    //M.FindCentre();					Return Centre of model


}

