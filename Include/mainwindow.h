#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//Include Utility parameters
#include <array>
#include <vector>

//Include Qt Header files
#include <QMainWindow>
#include <QFileDialog>
#include <QColorDialog>
#include <QColor>

//Include Vtk Header files
#include <vtkActor.h>

#include <vtkAxisActor.h>
#include <vtkCellArray.h>
#include <vtkPyramid.h>
#include <vtkAssembly.h>
#include <vtkTetra.h>
#include <vtkNamedColors.h>
#include <vtkProperty.h>
#include <vtkCamera.h>
#include <QFileDialog>
#include <vtkPolyData.h>
#include <vtkDataSetMapper.h>
#include <vtkPoints.h>

#include <vtkCamera.h>
#include <vtkCellArray.h>
#include <vtkCellType.h>
#include <vtkDataSetMapper.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkGlyph3DMapper.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkPlane.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkPoints.h>
#include <vtkPropAssembly.h>
#include <vtkProperty.h>
#include <vtkTextProperty.h>
#include <vtkRenderer.h>

#include <vtkRenderWindow.h>

#include <vtkRenderWindowInteractor.h>

#include <vtkSmartPointer.h>
#include <vtkSTLReader.h>
#include <vtkStringArray.h>
#include <vtkUnstructuredGrid.h>

//Type of the object
#include <vtkTetra.h>
#include <vtkPyramid.h>
#include <vtkCubeSource.h>

#include <vtkHexahedron.h>

#include <vtkSphereSource.h>


//Feature
#include <vtkShrinkFilter.h>
#include <vtkClipDataSet.h>

//Other Header files
#include "Model.h"//ModelLoader
#include "ui_mainwindow.h"

//Second Window header files
//#include "shrinkdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


    //Create global variables

    vector<int> NumCells;

    vtkSmartPointer<vtkRenderer> renderer;
    vector<vtkSmartPointer<vtkActor>> actors;
    vector<vtkSmartPointer<vtkShrinkFilter>> Shrinks;
    vtkSmartPointer<vtkDataSetMapper> mapper;
    vtkSmartPointer<vtkHexahedron> hex ;
     vtkSmartPointer<vtkActor> actor;
     vtkSmartPointer<vtkShrinkFilter> shrinkFilter;
    vtkSmartPointer<vtkUnstructuredGrid> uGrid;


 vector<vtkSmartPointer<vtkUnstructuredGrid>> uGrids;


     //P: Shrink Filter

     //Hana: clip filter

     vtkSmartPointer<vtkCubeSource> cubeSource;




    //Create Indicator
    int Shrink_Indicator;
    int Cell_Iterations = 0;
    vector<float> Last_Colour = {0,0,0};

public slots:
    void on_ShrinkButton_clicked();

    //Hana: clip filter
   
   
    //Hana: axis filter
    /*vtkSmartPointer<vtkSphereSource> sphereSource;
    vtkSmartPointer<vtkAxisActor> axis;
    vtkSmartPointer<vtkNamedColors> colors;
    vtkSmartPointer<vtkActor> actor; //Hana: note for the future - try to change this to actors and have one variable only (Ed's variable)
    vtkSmartPointer<vtkRenderWindowInteractor> interactor;*/



private slots:

    void on_sliderB_sliderMoved(); //Colour Blue Slider
    void on_sliderG_sliderMoved(); //Colour Green Slider
    void on_sliderR_sliderMoved(); //Colour Red Slider

    void on_actionModel_triggered(); //Colour model function
    void on_actionBackground_triggered(); //Colour of background function
    void on_loadmodelButton_pressed(); //Loading of model
    void on_ShrinkFilter_sliderMoved();//ShrinkFilter
    void on_ClipFilterButton_clicked(); //clip filter
    void on_ListView_activated(const QString &View); //Camera combo box

private:
    Ui::MainWindow *ui;
    vector<float> CellVertex;
    vector<int> CellVertices;
    vector<float> MatColour;
    vector<array<double, 3>> pointCoordinates;
    vector<array<double, 3>> CellColours;
    //ShrinkDialog *shrinkButton;

};

#endif // MAINWINDOW_H
