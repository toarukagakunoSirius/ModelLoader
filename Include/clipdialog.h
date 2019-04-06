#ifndef CLIPDIALOG_H
#define CLIPDIALOG_H

#include <QDialog>

namespace Ui {
class ClipDialog;
}

class ClipDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ClipDialog(QWidget *parent = nullptr);
    ~ClipDialog();
    double getClipfactor();
    int getClipcheck();


private slots:
    void on_CilpSpinBox_valueChanged(double arg1);

    void on_ClipcomboBox_activated(const QString &arg1);

private:
    Ui::ClipDialog *ui;
    double Clipfactor;
    int Clipcheck;
};

#endif // CLIPDIALOG_H
