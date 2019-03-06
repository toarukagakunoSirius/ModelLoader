#include "mainwindow.h"

//Hana: window not opening (trying to get axis filter to work)

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    // standard call to setup Qt UI (same as previously)
    ui->setupUi( this );

    //Create the render window
    vtkNew<vtkGenericOpenGLRenderWindow> renderWindow; //New render window
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

    // Create a mapper that will hold the cube's geometry in a format suitable for rendering

    mapper = vtkSmartPointer<vtkDataSetMapper>::New(); //mapper is defined in the header file in private member variables
    mapper->SetInputConnection( cubeSource->GetOutputPort() );

    // Create an actor that is used to set the cube's properties for rendering and place it in the window
    vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);
    actor->GetProperty()->EdgeVisibilityOn();

    // Add the actor to the scene
    renderer->AddActor(actor);
    //renderer->SetBackground( colors->GetColor3d("Silver").GetData() );
    renderer->ResetCamera(); //Set the camera back to origin

    // P: Create Shrink Filter variable
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

//Clip Filter
void MainWindow::on_ClipFilterButton_clicked(){

    vtkSmartPointer<vtkPlane> planeLeft = vtkSmartPointer<vtkPlane>::New();
    planeLeft->SetOrigin(0.0, 0.0, 0.0);
    planeLeft->SetNormal(-1.0, 0.0, 0.0);
    vtkSmartPointer<vtkClipDataSet> clipFilter = vtkSmartPointer<vtkClipDataSet>::New();
    clipFilter->SetInputConnection(cubeSource->GetOutputPort() ) ; //trying clip for different shapes
    clipFilter->SetClipFunction( planeLeft.Get() );
    mapper->SetInputConnection( clipFilter->GetOutputPort() );
}

/*void MainWindow:: on_AxisButton_clicked(){

}*/

void MainWindow::on_ShrinkFilter_sliderMoved()
{
    shrinkFilter = vtkSmartPointer<vtkShrinkFilter>::New();
    shrinkFilter->SetShrinkFactor( (float) (100 - ui->ShrinkFilter->value())/ 100);
    shrinkFilter->Update();

    // P: Waiting to be edited
    ui->qtvtkWidget->GetRenderWindow()->Render();
}

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

void MainWindow::on_loadmodelButton_pressed(){
    actors.clear();
    renderer->RemoveAllViewProps();
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
            //mapper->SetInputData(uGrid);

            shrinkFilter = vtkSmartPointer<vtkShrinkFilter>::New();
            shrinkFilter->SetInputDataObject(0,uGrid);
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

