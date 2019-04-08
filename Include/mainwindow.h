#ifndef MAINWINDOW_H
#define MAINWINDOW_H

	/** @file
	* This file is the mainwindoiw for Qt and contains most of the main functions   
	*/
	/** Brief description
	* Allows slots and other functions 
	*/

//Include Utility parameters
#include <array>
#include <vector>

//Include Qt Header files
#include <QMainWindow>
#include <QFileDialog>
#include <QColorDialog>
#include <QColor>
#include <QString>


//Include Vtk Header files
#include <vtkActor.h>

#include <vtkAxisActor.h>


#include <vtkAssembly.h>

#include <vtkSTLReader.h>


#include <vtkCamera.h>
#include <vtkPolyData.h>
#include <vtkDataSetMapper.h>
//#include <QFileInfo.h>
#include <vtkPoints.h>


#include <vtkCellArray.h>
#include <vtkCellType.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkGlyph3DMapper.h>
#include <vtkLight.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkPlane.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkGenericClip.h>
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
#include "clipdialog.h"

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
    vtkSmartPointer<vtkPlane> planeLeft;
    vtkSmartPointer<vtkClipDataSet> clipFilter;
    vector<vtkSmartPointer<vtkClipDataSet>> ClipFilters;

    vtkSmartPointer<vtkLight> light;
     //Hana: clip filter

     vtkSmartPointer<vtkCubeSource> cubeSource;
     vtkSmartPointer<vtkPlane> plane;




    //Create Indicator
    int Indicator;
    int Cell_Iterations = 0;
    vector<float> Last_Colour = {0,0,0};





private slots:

//  void on_sliderB_sliderMoved(); //Colour Blue Slider
//  void on_sliderG_sliderMoved(); //Colour Green Slider
//  void on_sliderR_sliderMoved(); //Colour Red Slider

    void on_actionModel_triggered(); //Colour model function
    void on_actionBackground_triggered(); //Colour of background function
    void on_ShrinkFilter_sliderMoved();//ShrinkFilter
    //void on_ClipFilterButton_clicked(); //clip filter
    void on_ListView_activated(const QString &View); //Camera combo box
    void Load_STL_File(QString File);
    void Load_Mod_File(std::string FileName);
    void on_Save_Button_clicked();

    void on_ClipFilterSlider_sliderMoved();

    void on_Light_sliderMoved(int position);

    void on_ClipButton_clicked();

    void ClipOperation();

    void on_LightradioButton_clicked(bool checked);

    void on_actionOpen_triggered();//Loading of model

private:
    Ui::MainWindow *ui;
    vector<float> CellVertex;
    vector<int> CellVertices;
    vector<float> MatColour;
    vector<array<double, 3>> pointCoordinates;
    vector<array<double, 3>> CellColours;
    ClipDialog *ClipWindow;
    Model M;

};

#endif // MAINWINDOW_H
