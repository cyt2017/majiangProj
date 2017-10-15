#ifndef DIALOGMJ152_H
#define DIALOGMJ152_H

#include <QDialog>

#include <opencv2/opencv.hpp>
#include <QDir>
#include <QFile>
#include <QImage>
#include <QMessageBox>
#include<QMouseEvent>

#include"qimagelabel.h"

using namespace std;
using namespace cv;

namespace Ui {
class DialogMJ152;
}

class DialogMJ152 : public QDialog
{
    Q_OBJECT

public:
    explicit DialogMJ152(QWidget *parent = 0);
    ~DialogMJ152();

    vector<Mat> imgE,imgN,imgW,imgS;
    vector<QString> labelE,labelN,labelW,labelS;

    void showImageMj();

    void mouseMoveEvent(QMouseEvent *e);

    QImageLabel *imageLabelEast[38];
    QImageLabel *imageLabelWest[38];
    QImageLabel *imageLabelSouth[38];
    QImageLabel *imageLabelNorth[38];

    QLabel *txtLabelEast[38];
    QLabel *txtLabelWest[38];
    QLabel *txtLabelSouth[38];
    QLabel *txtLabelNorth[38];

private slots:
    void recvImage152(Mat mat);

    void on_pushButton_clicked();

private:
    Ui::DialogMJ152 *ui;
    Mat currentImage;
};

#endif // DIALOGMJ152_H
