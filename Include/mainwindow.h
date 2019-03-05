#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>

#include <vtkActor.h>
#include <vtkCamera.h>
#include <vtkCellArray.h>
#include <vtkCellType.h>
#include <vtkDataSetMapper.h>
#include <vtkGenericOpenGLRenderWindow.h>

#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkPlane.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkPoints.h>
#include <vtkProperty.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkSmartPointer.h>
#include <vtkSTLReader.h>
#include <vtkUnstructuredGrid.h>

//Type of the object
#include <vtkTetra.h>
#include <vtkPyramid.h>
#include <vtkCubeSource.h>

//Feature
#include <vtkShrinkFilter.h>
#include <vtkClipDataSet.h>

#include "Model.h"
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
     vtkSmartPointer<vtkRenderer> renderer;
     //P: Shrink Filter
     vtkSmartPointer<vtkShrinkFilter> shrinkFilter;
     //Hana: clip filter
     vtkSmartPointer<vtkDataSetMapper> mapper;
     vtkSmartPointer<vtkCubeSource> cubeSource;


    void ModelLoader();

private slots:

     void on_ShrinkFilter_sliderMoved(int position);

     void on_ClipFilterButton_clicked(); //clip filter

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
