#include "mainwindow.h"

//Hana: window not opening (trying to get axis filter to work)

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    // standard call to setup Qt UI (same as previously)
    ui->setupUi( this );

    //Indicator Value at the beginning
    Shrink_Indicator = 0;

    //Create the render window
    vtkNew<vtkGenericOpenGLRenderWindow> renderWindow; //New render window

    ui->qtvtkWidget->SetRenderWindow( renderWindow );	 //Assign window to Qtwidget in mainwindow.ui

    renderer = vtkSmartPointer<vtkRenderer>::New(); //Create a smartpointer pointing to the window renderer
    ui->qtvtkWidget->GetRenderWindow()->AddRenderer( renderer );

    renderer->SetBackground(2.55,2.55,2.55);

    //Set Ui Connection
    connect(ui->sliderR,SIGNAL(sliderPressed()),this,SLOT(on_sliderR_sliderMoved()));
    connect(ui->sliderG,SIGNAL(sliderPressed()),this,SLOT(on_sliderG_sliderMoved()));
    connect(ui->sliderB,SIGNAL(sliderPressed()),this,SLOT(on_sliderB_sliderMoved()));
    connect(ui->ShrinkFilter,SIGNAL(sliderPressed()),this,SLOT(on_ShrinkFilter_sliderMoved())); //Connect Slider to ShrinkFilter
    connect( ui->ListView, &QComboBox::currentTextChanged, this, &MainWindow::on_ListView_activated);// Connect Combo box to all camera position
    //connect( ui->ShrinkButton, &QPushButton::released, this, &MainWindow::on_ShrinkButton_clicked );

    ui->qtvtkWidget->SetRenderWindow( renderWindow );	 //Assign window to Qtwidget in mainwindow.ui	
    renderer = vtkSmartPointer<vtkRenderer>::New(); //Create a smartpointer pointing to the window renderer
    ui->qtvtkWidget->GetRenderWindow()->AddRenderer( renderer );
    renderer->SetBackground(2.55,2.55,2.55);

    //Hana: LINE BELOW NEEDS CHECKING (SLIDER B DOESNT EXIST ANYMORE)
    //connect(ui->sliderB,SIGNAL(sliderPressed()),this,SLOT(on_ShrinkFilter_sliderMoved()));


    // Create Shrink Filter variable
   // shrinkFilter = vtkSmartPointer<vtkShrinkFilter>::New();

    //**Hana: defining cube source for clip filter
    cubeSource = vtkSmartPointer<vtkCubeSource>::New();

    shrinkFilter = vtkSmartPointer<vtkShrinkFilter>::New();
    shrinkFilter->SetShrinkFactor(1);
    shrinkFilter->SetInputConnection(0, cubeSource->GetOutputPort());
    // Create a mapper that will hold the cube's geometry in a format suitable for rendering

    mapper = vtkSmartPointer<vtkDataSetMapper>::New(); //mapper is defined in the header file in private member variables
    mapper->SetInputConnection( 0, shrinkFilter->GetOutputPort() );

    // Create an actor that is used to set the cube's properties for rendering and place it in the window
    vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);
    actor->GetProperty()->EdgeVisibilityOn();

    // Add the actor to the scene
    renderer->AddActor(actor);
    //renderer->SetBackground( colors->GetColor3d("Silver").GetData() );
    renderer->ResetCamera(); //Set the camera back to origin

    //ModelLoader();

}

MainWindow::~MainWindow()
{
    delete ui;
}

//Clip Filter
void MainWindow::on_ClipFilterButton_clicked(){

    vtkSmartPointer<vtkPlane> planeLeft = vtkSmartPointer<vtkPlane>::New();
    planeLeft->SetOrigin(0.0, 0.0, 0.0);
    planeLeft->SetNormal(-1.0, 0.0, 0.0);
    vtkSmartPointer<vtkClipDataSet> clipFilter = vtkSmartPointer<vtkClipDataSet>::New();
    clipFilter->SetInputConnection(cubeSource->GetOutputPort() ) ; //trying clip for different shapes
    clipFilter->SetClipFunction( planeLeft.Get() );
    mapper->SetInputConnection( 0, clipFilter->GetOutputPort() );
    mapper->Update();
    ui->qtvtkWidget->GetRenderWindow()->Render();
}

/*void MainWindow:: on_AxisButton_clicked(){

}*/

void MainWindow::on_ShrinkFilter_sliderMoved()
{
    //ModelLoader Condition
    if (Shrink_Indicator == 1) {
      for(int x = 0;x < Shrinks.size();x++){
            Shrinks[x]->SetShrinkFactor( (float) (100 - ui->ShrinkFilter->value())/ 100);
            Shrinks[x]->Update();
          }
    }
    else if (Shrink_Indicator == 0){
      shrinkFilter->SetShrinkFactor( (float) (100 - ui -> ShrinkFilter -> value())/ 100);
      shrinkFilter->Update();
      }
    ui->qtvtkWidget->GetRenderWindow()->Render();
}


void MainWindow::on_sliderB_sliderMoved()
{
    double R = (ui->sliderR->value())/100.00;
    double G = (ui->sliderG->value())/100.00;
    double B = (ui->sliderB->value())/100.00;

    for (int x=0; x < actors.size(); x++){
        actors[x]->GetProperty()->SetColor(R,G,B);
    }

    ui->qtvtkWidget->GetRenderWindow()->Render();
    ui->lineEditB->setText(QString::number(B*100));
}

void MainWindow::on_sliderG_sliderMoved()
{
    double R = (ui->sliderR->value())/100.00;
    double G = (ui->sliderG->value())/100.00;
    double B = (ui->sliderB->value())/100.00;

    for (int x=0; x < actors.size(); x++){
        actors[x]->GetProperty()->SetColor(R,G,B);
    }

    ui->qtvtkWidget->GetRenderWindow()->Render();
     ui->lineEditG->setText(QString::number(G*100));
}

void MainWindow::on_sliderR_sliderMoved()
{
    double R = (ui->sliderR->value())/100.00;
    double G = (ui->sliderG->value())/100.00;
    double B = (ui->sliderB->value())/100.00;

    for (int x=0; x < actors.size(); x++){
        actors[x]->GetProperty()->SetColor(R,G,B);
    }

    ui->qtvtkWidget->GetRenderWindow()->Render();
    ui->lineEditR->setText(QString::number(R*100));
}

//Model color change with color dialog

void MainWindow::on_actionModel_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white,this,"Choose Color");
    if ( color.isValid() )
    {
        for (int x=0; x < actors.size(); x++){
            actors[x]->GetProperty()->SetColor(color.redF(), color.greenF(), color.blueF());
        }
        ui->qtvtkWidget->GetRenderWindow()->Render();
    }
}

//Background color change with color dialog
void MainWindow::on_actionBackground_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white,this,"Choose Color");
    if ( color.isValid() )
    {
        renderer->SetBackground(color.redF(), color.greenF(), color.blueF());

    }
}

void MainWindow::on_loadmodelButton_pressed(){
    actors.clear();
    renderer->RemoveAllViewProps();

    //Indicator for ModelLoader scenario
    Shrink_Indicator = 1;

    //Load the model
    QString File = QFileDialog::getOpenFileName(this, tr("Open MOD File"), "./", tr("MOD Files(*.mod)"));

    std::string FileName = File.toUtf8().constData();

    if (FileName != ""){

        Model M(FileName);

        //Retrieves the number of cells for each shape
        NumCells = M.NumberCells();

        //Loops through each Cell
        for (int H = 0; H < NumCells[2]; H++ ){

            //Gets the vertices and material colour for each cell
            CellVertices = M.GetCellVertices(H,"h");
            MatColour = M.GetMaterialColour(M.GetCellMaterial(H, "h"));

            //Push the Vector data for each cell. (Loops through each vector for that cell)
            for (int V = 0; V < 8; V++){
                CellVertex = M.GetVertices(CellVertices[V]);
                pointCoordinates.push_back({{CellVertex[0], CellVertex[1], CellVertex[2]}});
            }

            // Create a hexahedron from the points.
            vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();
            vtkSmartPointer<vtkHexahedron> hex = vtkSmartPointer<vtkHexahedron>::New();

            //Inserts the points into the smartpointers
            for (auto i = 0; i < pointCoordinates.size(); ++i){
                points->InsertNextPoint(pointCoordinates[i].data());
                hex->GetPointIds()->SetId(i, i);
            }

            // Add the points and hexahedron to an unstructured grid.
            vtkSmartPointer<vtkUnstructuredGrid> uGrid = vtkSmartPointer<vtkUnstructuredGrid>::New();
            uGrid->SetPoints(points);
            uGrid->InsertNextCell(hex->GetCellType(), hex->GetPointIds());

            // Visualize.
            vtkSmartPointer<vtkDataSetMapper> mapper = vtkSmartPointer<vtkDataSetMapper>::New();
            mapper->SetInputData(uGrid);

            shrinkFilter = vtkSmartPointer<vtkShrinkFilter>::New();
            shrinkFilter->SetShrinkFactor(1);
            shrinkFilter->AddInputDataObject(0,uGrid);
            Shrinks.push_back(shrinkFilter);
            mapper->SetInputConnection( shrinkFilter->GetOutputPort() );

            //Add as an actor
            vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();

            actor->GetProperty()->SetColor(MatColour[0]/100,MatColour[1]/100,MatColour[2]/100 );
            actor->SetMapper(mapper);
            //actor->GetProperty()->EdgeVisibilityOn();
            renderer->AddActor(actor);
            //assembly->AddPart(actor);

            actors.push_back(actor);

            //Clear unused data storage
            CellVertices.clear();
            MatColour.clear();
            CellVertex.clear();
            pointCoordinates.clear();

        }

        for (int T = 0; T < NumCells[1]; T++ ){
            CellVertices = M.GetCellVertices(T,"t");
            MatColour = M.GetMaterialColour(M.GetCellMaterial(T, "t"));

            vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();

            for (int V = 0; V < 4; V++){
                CellVertex = M.GetVertices(CellVertices[V]);
                points->InsertNextPoint(CellVertex[0], CellVertex[1], CellVertex[2]);
            }

            vtkSmartPointer<vtkUnstructuredGrid> unstructuredGrid = vtkSmartPointer<vtkUnstructuredGrid>::New();
            unstructuredGrid->SetPoints(points);

            vtkIdType ptIds[] = {0, 1, 2, 3};
            unstructuredGrid->InsertNextCell( VTK_TETRA, 4, ptIds );

            vtkSmartPointer<vtkDataSetMapper> mapper = vtkSmartPointer<vtkDataSetMapper>::New();
            mapper->SetInputData(unstructuredGrid);

            vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();

            actor->GetProperty()->SetColor(MatColour[0]/100,MatColour[1]/100,MatColour[2]/100 );
            actor->SetMapper(mapper);
            //actor->GetProperty()->EdgeVisibilityOn();
            renderer->AddActor(actor);
            //assembly->AddPart(actor);

            actors.push_back(actor);

            //Clear unused data storage
            CellVertices.clear();
            MatColour.clear();
            CellVertex.clear();
            pointCoordinates.clear();

        }

        for (int P = 0; P < NumCells[0]; P++ ){
            CellVertices = M.GetCellVertices(P,"p");
            MatColour = M.GetMaterialColour(M.GetCellMaterial(P, "p"));

            vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();
            for (int V = 0; V < 5; V++){
                CellVertex = M.GetVertices(CellVertices[V]);
                points->InsertNextPoint(CellVertex[0], CellVertex[1], CellVertex[2]);
            }
            vtkSmartPointer<vtkPyramid> pyramid = vtkSmartPointer<vtkPyramid>::New();
              pyramid->GetPointIds()->SetId(0,0);
              pyramid->GetPointIds()->SetId(1,1);
              pyramid->GetPointIds()->SetId(2,2);
              pyramid->GetPointIds()->SetId(3,3);
              pyramid->GetPointIds()->SetId(4,4);

            vtkSmartPointer<vtkCellArray> cells = vtkSmartPointer<vtkCellArray>::New();
            cells->InsertNextCell (pyramid);

            vtkSmartPointer<vtkUnstructuredGrid> ug = vtkSmartPointer<vtkUnstructuredGrid>::New();
            ug->SetPoints(points);
            ug->InsertNextCell(pyramid->GetCellType(),pyramid->GetPointIds());

            vtkSmartPointer<vtkDataSetMapper> mapper = vtkSmartPointer<vtkDataSetMapper>::New();
            mapper->SetInputData(ug);

            vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();

            actor->GetProperty()->SetColor(MatColour[0]/100,MatColour[1]/100,MatColour[2]/100 );
            actor->SetMapper(mapper);
            //actor->GetProperty()->EdgeVisibilityOn();
            renderer->AddActor(actor);
            //assembly->AddPart(actor);

            actors.push_back(actor);

            //Clear unused data storage
            CellVertices.clear();
            MatColour.clear();
            CellVertex.clear();
            pointCoordinates.clear();
        }

        renderer->ResetCamera(); //Set the camera back to origin
        renderer->GetActiveCamera()->Azimuth(30);
        renderer->GetActiveCamera()->Elevation(30);
        ui->qtvtkWidget->GetRenderWindow()->Render();
    }
}
void MainWindow::on_ListView_activated(const QString &View)
{
    if (View == "X-Axis"){
      renderer->GetActiveCamera ()->SetPosition(1.0,0.0,0.0);
    }
    else if (View == "Y-Axis") {
      renderer->GetActiveCamera ()->SetPosition(0.0,1.0,0.0);
    }
    else if (View == "Z-Axis") {
      renderer->GetActiveCamera ()->SetPosition(0.0,0.0,1.0);
    }
    else if (View == "90º Azimuth") {
      renderer->GetActiveCamera ()->Azimuth(90);
    }
    else if (View == "90º Elevation") {
      renderer->GetActiveCamera ()->Elevation(90);
    }
    renderer->ResetCamera();
    ui->qtvtkWidget->GetRenderWindow()->Render();
}

void MainWindow::on_ShrinkButton_clicked()
{
    /*shrinkButton = new ShrinkDialog(this);
    shrinkButton->show();

    //ModelLoader Condition
    if (Shrink_Indicator == 1) {
      for(int x = 0;x < Shrinks.size();x++){
            Shrinks[x]->SetShrinkFactor( shrinkButton->getShrinkValue());
            Shrinks[x]->Update();
          }
    }
    //Stl Condition
    else if (Shrink_Indicator == 0){
      shrinkFilter->SetShrinkFactor( shrinkButton->getShrinkValue());
      shrinkFilter->Update();
      }
    ui->qtvtkWidget->GetRenderWindow()->Render();*/
}
