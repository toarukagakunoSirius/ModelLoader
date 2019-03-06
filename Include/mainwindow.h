#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>

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
#include <vtkHexahedron.h>
#include <vtkSmartPointer.h>
#include <vtkActor.h>

#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkPlane.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkPoints.h>
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
#include <vtkSphereSource.h>

//Feature
#include <vtkShrinkFilter.h>
#include <vtkClipDataSet.h>

#include "Model.h"

#include <array>
#include <vector>
#include <vtkPolyDataMapper.h>
#include <vtkGlyph3DMapper.h>
#include <vtkPropAssembly.h>
#include <vtkAssembly.h>

#include <QColorDialog>
#include <QColor>


#include "ui_mainwindow.h"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    vector<int> NumCells;
    vtkSmartPointer<vtkRenderer> renderer;
    vector<vtkSmartPointer<vtkActor>> actors;
    vtkSmartPointer<vtkDataSetMapper> mapper;
    vtkSmartPointer<vtkShrinkFilter> shrinkFilter;
    //P: Shrink Filter

    //Hana: clip filter
    vtkSmartPointer<vtkCubeSource> cubeSource;
    //Hana: axis filter
    /*vtkSmartPointer<vtkSphereSource> sphereSource;
    vtkSmartPointer<vtkAxisActor> axis;
    vtkSmartPointer<vtkNamedColors> colors;
    vtkSmartPointer<vtkActor> actor; //Hana: note for the future - try to change this to actors and have one variable only (Ed's variable)
    vtkSmartPointer<vtkRenderWindowInteractor> interactor;*/


private slots:
    void on_actionModel_triggered();
    void on_loadmodelButton_pressed();
    void on_ShrinkFilter_sliderMoved();
    void on_ClipFilterButton_clicked(); //clip filter
    //void on_AxisButton_clicked();

private:
    Ui::MainWindow *ui;
    vector<float> CellVertex;
    vector<int> CellVertices;
    vector<float> MatColour;
    vector<array<double, 3>> pointCoordinates;

};

#endif // MAINWINDOW_H
