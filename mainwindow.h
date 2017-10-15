#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"qcolorhist_pixratio_feature.h"
#include<QFileDialog>
#include<dialogmajiang.h>

#include "dialogmj152.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QColorHist_PixRatio_Feature colorHist;

    void showImage(Mat inSrc);

private slots:
    void on_trainBtn_clicked();

    void on_openBtn_clicked();

    void on_loadModelBtn_clicked();

    void on_predictBtn_clicked();

private:
    Ui::MainWindow *ui;
    DialogMaJiang mjDlg;
    DialogMJ152 mjDlg152;
};

#endif // MAINWINDOW_H
