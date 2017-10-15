#ifndef DIALOGMAJIANG_H
#define DIALOGMAJIANG_H

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
class DialogMaJiang;
}

class DialogMaJiang : public QDialog
{
    Q_OBJECT

public:
    explicit DialogMaJiang(QWidget *parent = 0);
    ~DialogMaJiang();

    vector<Mat> imgE,imgN,imgW,imgS;
    vector<QString> labelE,labelN,labelW,labelS;

    void showImageMj();

    void mouseMoveEvent(QMouseEvent *e);

    QImageLabel *imageLabel[136];

private slots:
    void on_pushButton_clicked();

    void recvImage(Mat mat);

    void on_saveAllToSampleBtn_clicked();

private:
    Ui::DialogMaJiang *ui;
    Mat currentImage;
};

#endif // DIALOGMAJIANG_H
