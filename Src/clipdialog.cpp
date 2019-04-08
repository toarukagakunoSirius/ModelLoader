#include "clipdialog.h"

<<<<<<< HEAD:Src/clipdialog.cpp

=======
>>>>>>> 877e1ae4343f3b2d29d55c3e1c9c650a58c133e7:Src/clipdialog.cpp

ClipDialog::ClipDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClipDialog)
{
    ui->setupUi(this);
}

ClipDialog::~ClipDialog()
{
    delete ui;
}

void ClipDialog::on_CilpSpinBox_valueChanged(double arg1)
{
    this ->Clipfactor = arg1;
}

void ClipDialog::on_ClipcomboBox_activated(const QString &arg1)
{
    if (arg1 == "X-Axis"){
        Clipcheck = 1;
    }
    else if (arg1 == "Y-Axis"){
        Clipcheck = 2;
    }
    else if (arg1 == "Z-Axis"){
        Clipcheck = 3;
    }
}

int ClipDialog::getClipcheck(){
    return this->Clipcheck;
}
double ClipDialog::getClipfactor(){
    return this->Clipfactor;
}
