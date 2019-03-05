#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <vtkActor.h>
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
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkUnstructuredGrid.h>
#include <vtkRenderer.h>
#include <vtkNew.h>
#include <vtkTetra.h>
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
#include <vtkPolyData.h>
#include <vtkPoints.h>
#include <vtkProperty.h>
#include <vtkRenderer.h>
#include <vtkSmartPointer.h>
#include <vtkUnstructuredGrid.h>

//Type of the object
#include <vtkTetra.h>
#include <vtkPyramid.h>
#include <vtkCubeSource.h>

//Feature
#include <vtkShrinkFilter.h>

#include "Model.h"
#include <array>
#include <vector>
#include <vtkPolyDataMapper.h>
#include <vtkGlyph3DMapper.h>
#include <vtkPropAssembly.h>
#include <vtkAssembly.h>



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


private slots:
    void on_sliderB_sliderMoved();
    void on_sliderG_sliderMoved();
    void on_sliderR_sliderMoved();
    void on_loadmodelButton_pressed();

     void on_ShrinkFilter_sliderMoved(int position);

private:
    Ui::MainWindow *ui;
    vector<float> CellVertex;
    vector<int> CellVertices;
    vector<float> MatColour;
    vector<array<double, 3>> pointCoordinates;

};

#endif // MAINWINDOW_H
