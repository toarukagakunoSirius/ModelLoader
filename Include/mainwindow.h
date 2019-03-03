#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vtkSmartPointer.h>
#include <vtkActor.h>
#include <vtkNamedColors.h>

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

private slots:

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
