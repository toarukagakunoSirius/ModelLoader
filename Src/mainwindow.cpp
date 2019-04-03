#include "mainwindow.h"

//Hana: window not opening (trying to get axis filter to work)

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    // standard call to setup Qt UI (same as previously)
    ui->setupUi( this );

    //Indicator Value at the beginning
    Indicator = 0;

    //Create the render window
    vtkNew<vtkGenericOpenGLRenderWindow> renderWindow; //New render window

   // ui->qtvtkWidget->SetRenderWindow( renderWindow );	 //Assign window to Qtwidget in mainwindow.ui

   // renderer = vtkSmartPointer<vtkRenderer>::New(); //Create a smartpointer pointing to the window renderer
   // ui->qtvtkWidget->GetRenderWindow()->AddRenderer( renderer );

   // renderer->SetBackground(2.55,2.55,2.55);

    //Set Ui Connection
    connect(ui->sliderR,SIGNAL(sliderPressed()),this,SLOT(on_sliderR_sliderMoved()));
    connect(ui->sliderG,SIGNAL(sliderPressed()),this,SLOT(on_sliderG_sliderMoved()));
    connect(ui->sliderB,SIGNAL(sliderPressed()),this,SLOT(on_sliderB_sliderMoved()));
    connect(ui->ShrinkFilter,SIGNAL(sliderPressed()),this,SLOT(on_ShrinkFilter_sliderMoved())); //Connect Slider to ShrinkFilter

    connect(ui->ClipFilterSlider,SIGNAL(sliderPressed()),this,SLOT(on_ClipFilterSlider_sliderMoved())); //Connect Slider to ShrinkFilter

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



    planeLeft = vtkSmartPointer<vtkPlane>::New();
    planeLeft->SetOrigin(1000, 0.0, 0.0);
    planeLeft->SetNormal(-1, 0, 0);

    clipFilter = vtkSmartPointer<vtkClipDataSet>::New();
    clipFilter->SetInputConnection( cubeSource->GetOutputPort() ) ;
    clipFilter->SetClipFunction( planeLeft.Get() );

    shrinkFilter = vtkSmartPointer<vtkShrinkFilter>::New();
    shrinkFilter->SetShrinkFactor(1);
    shrinkFilter->SetInputConnection(0, clipFilter->GetOutputPort());



    // Create a mapper that will hold the cube's geometry in a format suitable for rendering

    vtkSmartPointer<vtkDataSetMapper> mapper = vtkSmartPointer<vtkDataSetMapper>::New(); //mapper is defined in the header file in private member variables
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
void MainWindow::on_ClipFilterSlider_sliderMoved(){

   //ModelLoader Condition
   if (Indicator == 1) {
        for(int x = 0;x < ClipFilters.size();x++){
            planeLeft->SetOrigin((float) ui->ClipFilterSlider->value()/100, 0.0, 0.0);
           // planeLeft->SetNormal((float) ui->ClipFilterSlider->value() / 100 , 0.0, 0.0);
            ClipFilters[x]->SetClipFunction( planeLeft.Get() );
            ClipFilters[x]->Update();
        }
    }
    else if (Indicator == 0){
        planeLeft->SetOrigin((float) ui->ClipFilterSlider->value() /100, 0.0, 0.0);
        //planeLeft->SetNormal((float) ui->ClipFilterSlider->value() / 100 , 0.0, 0.0);
        clipFilter->SetClipFunction( planeLeft.Get() );
        clipFilter->Update();
    }
    ui->qtvtkWidget->GetRenderWindow()->Render();

}

void MainWindow::on_ShrinkFilter_sliderMoved()
{
    //ModelLoader Condition
    if (Indicator == 1) {
      for(int x = 0;x < Shrinks.size();x++){
            Shrinks[x]->SetShrinkFactor( (float) (100 - ui->ShrinkFilter->value())/ 100);
            Shrinks[x]->Update();
          }
    }
    else if (Indicator == 0){
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


//Loading Models below

void MainWindow::on_loadmodelButton_pressed(){
    planeLeft->SetOrigin(1000, 0.0, 0.0);
    //Load the model
    QString File = QFileDialog::getOpenFileName(this, tr("Open MOD File"), "./", tr("MODEL Files(*.mod *.stl)"));
    std::string FileName = File.toUtf8().constData();
    if (FileName != ""){
        QStringList partsList = File.split('.');
        QString suffix = partsList.at(1);
        std::string s = suffix.toUtf8().constData();

        actors.clear();
        renderer->RemoveAllViewProps();
        if (s == "mod")
            Load_Mod_File(FileName); //Load the .mod file
        else
            Load_STL_File(File); //Load the .stl file
    }
}

void MainWindow::Load_STL_File(QString File){

    vtkSmartPointer<vtkSTLReader> reader = vtkSmartPointer<vtkSTLReader>::New();
    reader->SetFileName(File.toLatin1().data());
    reader->Update();

    // Visualize
    vtkSmartPointer<vtkDataSetMapper> mapper = vtkSmartPointer<vtkDataSetMapper>::New();
    mapper->SetInputConnection(reader->GetOutputPort());

    //Link the shrink filter into the grid
    shrinkFilter = vtkSmartPointer<vtkShrinkFilter>::New();
    shrinkFilter->SetShrinkFactor(1);
    shrinkFilter->SetInputConnection(0, reader->GetOutputPort(0));
    Shrinks.push_back(shrinkFilter);

    clipFilter = vtkSmartPointer<vtkClipDataSet>::New();
    clipFilter->SetInputConnection( shrinkFilter->GetOutputPort() ) ;
    clipFilter->SetClipFunction( planeLeft.Get() );
    ClipFilters.push_back(clipFilter);


    mapper->SetInputConnection( clipFilter->GetOutputPort() );

    vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);

    vtkSmartPointer<vtkNamedColors> colors = vtkSmartPointer<vtkNamedColors>::New();
    actor->GetProperty()->SetColor( 1.30,0.97,1.64 );
    renderer->AddActor(actor);
    renderer->ResetCamera(); //Set the camera back to origin
    renderer->GetActiveCamera()->Azimuth(30);
    renderer->GetActiveCamera()->Elevation(30);
    ui->qtvtkWidget->GetRenderWindow()->Render();
}

void MainWindow::Load_Mod_File(std::string FileName){

    //INITIALISATIONS
    CellColours.clear();
    Indicator = 1; //Indicator for ModelLoader scenario
    renderer->RemoveAllViewProps();
    Cell_Iterations = 0;
    Model M(FileName);
    NumCells = M.NumberCells(); //Retrieves the number of cells for each shape




    //-------------LOAD HEXAHEDRONS--------------
    vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();
    vtkSmartPointer<vtkUnstructuredGrid> uGrid = vtkSmartPointer<vtkUnstructuredGrid>::New();
    for (int H = 0; H < NumCells[2]; H++ ){ //Loops through each Cell
        CellVertices = M.GetCellVertices(H,"h"); //Gets the vertices and material colour for each cell
        MatColour = M.GetMaterialColour(M.GetCellMaterial(H, "h")); //Retrieve the colour data for the cell

        //Creates a new actor for each colour by checking if the colour for the cells has changed since the previous cell.
        if ((Last_Colour[0] != MatColour[0] || Last_Colour[1] != MatColour[1] || Last_Colour[2] != MatColour[2]) && H != 0){
            Cell_Iterations = H; //If a new colour has started the SetID for the hexagon must be offset back to zero so a reference point is used
            CellColours.push_back({Last_Colour[0],Last_Colour[1],Last_Colour[2]}); //Store the colours for each actor for later use
            uGrid->SetPoints(points); //Sets the points for the grouop of cells into an unstructured grid
            uGrids.push_back(uGrid); //Adds the unstructuredgrid to vector of grids for later rendering
            points = vtkSmartPointer<vtkPoints>::New(); //Creates a new smart pointer of points for storing the new cells
            uGrid = vtkSmartPointer<vtkUnstructuredGrid>::New(); //Creates a new unstructured grid for the next actor
        }

        for (int V = 0; V < 8; V++){ //Push the Vector data for each cell. (Loops through each vector for that cell)
            CellVertex = M.GetVertices(CellVertices[V]); //Retrieve the cells vector
            points->InsertNextPoint(CellVertex[0], CellVertex[1], CellVertex[2]); //Store the vector as a point
        }

        vtkSmartPointer<vtkHexahedron> hex = vtkSmartPointer<vtkHexahedron>::New();
        for (auto i = 0; i < 8; ++i) //Inserts the points into the smartpointers
            hex->GetPointIds()->SetId(i, ((8*(H-Cell_Iterations))+i));        // Create a hexahedron from the points.

        uGrid->InsertNextCell(hex->GetCellType(), hex->GetPointIds()); //Insert the created cell into the grid
        Last_Colour = MatColour; //Set the last_colour reference to the current colour so it can be checked on the next loop
    }
    //Send the final group of cells into an unstructured grid
    CellColours.push_back({Last_Colour[0],Last_Colour[1],Last_Colour[2]}); //Send the colour of the actor to a vector for later use
    uGrid->SetPoints(points); //Sets the points for the grouop of cells into an unstructured grid
    uGrids.push_back(uGrid); //Adds the unstructuredgrid to vector of grids for later rendering
    Cell_Iterations = 0;
    //-------------------------------------------


    //-------------LOAD PYRAMIDS-----------------
    points = vtkSmartPointer<vtkPoints>::New();
    uGrid = vtkSmartPointer<vtkUnstructuredGrid>::New();
    for (int P = 0; P < NumCells[0]; P++ ){ //Loops through each Cell
        CellVertices = M.GetCellVertices(P,"p");
        MatColour = M.GetMaterialColour(M.GetCellMaterial(P, "p"));

        //Creates a new actor for each colour by checking if the colour for the cells has changed since the previous cell.
        if ((Last_Colour[0] != MatColour[0] || Last_Colour[1] != MatColour[1] || Last_Colour[2] != MatColour[2]) && P != 0){
            Cell_Iterations = P; //If a new colour has started the SetID for the hexagon must be offset back to zero so a reference point is used
            CellColours.push_back({Last_Colour[0],Last_Colour[1],Last_Colour[2]}); //Store the colours for each actor for later use
            uGrid->SetPoints(points); //Sets the points for the grouop of cells into an unstructured grid
            uGrids.push_back(uGrid); //Adds the unstructuredgrid to vector of grids for later rendering
            points = vtkSmartPointer<vtkPoints>::New(); //Creates a new smart pointer of points for storing the new cells
            uGrid = vtkSmartPointer<vtkUnstructuredGrid>::New(); //Creates a new unstructured grid for the next actor
        }

        for (int V = 0; V < 5; V++){ //Push the Vector data for each cell. (Loops through each vector for that cell)
            CellVertex = M.GetVertices(CellVertices[V]); //Retrieve the cells vector
            points->InsertNextPoint(CellVertex[0], CellVertex[1], CellVertex[2]); //Store the vector as a point
        }

        vtkSmartPointer<vtkPyramid> pyramid = vtkSmartPointer<vtkPyramid>::New();
        for (auto i = 0; i < 5; ++i) //Inserts the points into the smartpointers
            pyramid->GetPointIds()->SetId(i, ((5*(P-Cell_Iterations))+i));        // Create a hexahedron from the points.

        vtkSmartPointer<vtkCellArray> cells = vtkSmartPointer<vtkCellArray>::New();
        cells->InsertNextCell (pyramid);

        uGrid->InsertNextCell(pyramid->GetCellType(),pyramid->GetPointIds()); //Insert the created cell into the grid
        Last_Colour = MatColour; //Set the last_colour reference to the current colour so it can be checked on the next loop
    }
    //Send the final group of cells into an unstructured grid
    CellColours.push_back({Last_Colour[0],Last_Colour[1],Last_Colour[2]}); //Send the colour of the actor to a vector for later use
    uGrid->SetPoints(points); //Sets the points for the grouop of cells into an unstructured grid
    uGrids.push_back(uGrid); //Adds the unstructuredgrid to vector of grids for later rendering
    Cell_Iterations = 0;
    //-------------------------------------------


    //-------------LOAD TETRAHEDRONS-----------------
    points = vtkSmartPointer<vtkPoints>::New();
    uGrid = vtkSmartPointer<vtkUnstructuredGrid>::New();
    for (int T = 0; T < NumCells[1]; T++ ){
        CellVertices = M.GetCellVertices(T,"t");
        MatColour = M.GetMaterialColour(M.GetCellMaterial(T, "t"));

        //Creates a new actor for each colour by checking if the colour for the cells has changed since the previous cell.
        if ((Last_Colour[0] != MatColour[0] || Last_Colour[1] != MatColour[1] || Last_Colour[2] != MatColour[2]) && T != 0){
            Cell_Iterations = T; //If a new colour has started the SetID for the hexagon must be offset back to zero so a reference point is used
            CellColours.push_back({Last_Colour[0],Last_Colour[1],Last_Colour[2]}); //Store the colours for each actor for later use
            uGrid->SetPoints(points); //Sets the points for the grouop of cells into an unstructured grid
            uGrids.push_back(uGrid); //Adds the unstructuredgrid to vector of grids for later rendering
            points = vtkSmartPointer<vtkPoints>::New(); //Creates a new smart pointer of points for storing the new cells
            uGrid = vtkSmartPointer<vtkUnstructuredGrid>::New(); //Creates a new unstructured grid for the next actor
        }

        for (int V = 0; V < 4; V++){ //Push the Vector data for each cell. (Loops through each vector for that cell)
            CellVertex = M.GetVertices(CellVertices[V]); //Retrieve the cells vector
            points->InsertNextPoint(CellVertex[0], CellVertex[1], CellVertex[2]); //Store the vector as a point
        }

        vtkSmartPointer<vtkTetra> tetra = vtkSmartPointer<vtkTetra>::New();
        for (auto i = 0; i < 4; ++i) //Inserts the points into the smartpointers
            tetra->GetPointIds()->SetId(i, ((4*(T-Cell_Iterations))+i));        // Create a hexahedron from the points.

        vtkSmartPointer<vtkCellArray> cells = vtkSmartPointer<vtkCellArray>::New();
        cells->InsertNextCell (tetra);

        uGrid->InsertNextCell(tetra->GetCellType(),tetra->GetPointIds()); //Insert the created cell into the grid
        Last_Colour = MatColour; //Set the last_colour reference to the current colour so it can be checked on the next loop
    }
    //Send the final group of cells into an unstructured grid
    CellColours.push_back({Last_Colour[0],Last_Colour[1],Last_Colour[2]}); //Send the colour of the actor to a vector for later use
    uGrid->SetPoints(points); //Sets the points for the grouop of cells into an unstructured grid
    uGrids.push_back(uGrid); //Adds the unstructuredgrid to vector of grids for later rendering
    Cell_Iterations = 0;
    //-------------------------------------------


    //-------------MAPPER -> FILTERS -> RENDER-----------------
    //Loop through the vector of unstructured grids to render them and link a mapper plus add filters
    for (int G=0;G<uGrids.size();G++){
        vtkSmartPointer<vtkDataSetMapper> mapper = vtkSmartPointer<vtkDataSetMapper>::New();
        mapper->SetInputData(uGrids[G]); //Create a mapper and send the grid as the inputted data

        //Link the shrink filter into the grid
        shrinkFilter = vtkSmartPointer<vtkShrinkFilter>::New();
        shrinkFilter->SetShrinkFactor(1);
        shrinkFilter->AddInputDataObject(0,uGrids[G]);
        Shrinks.push_back(shrinkFilter);

        clipFilter = vtkSmartPointer<vtkClipDataSet>::New();
        clipFilter->SetInputConnection( shrinkFilter->GetOutputPort() ) ;
        clipFilter->SetClipFunction( planeLeft.Get() );
        ClipFilters.push_back(clipFilter);

        mapper->SetInputConnection( clipFilter->GetOutputPort() );

        //Add as an actor
        vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
        actor->GetProperty()->SetColor( CellColours[G][0]/100,CellColours[G][1]/100,CellColours[G][2]/100 ); //Set the colour of the actor
        actor->SetMapper(mapper); //Link the actor to a mapper
        renderer->AddActor(actor); //Add the actor to the render window
        actors.push_back(actor); //Put the actors into a vector of actors so they can be accessed later
    }

    //Reset the render window
    renderer->ResetCamera(); //Set the camera back to origin
    renderer->GetActiveCamera()->Azimuth(30);
    renderer->GetActiveCamera()->Elevation(30);
    ui->qtvtkWidget->GetRenderWindow()->Render();
    CellVertex.clear();

    CellVertices.clear();
    MatColour.clear();
    pointCoordinates.clear();
    uGrids.clear();
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
