#ifndef QIMAGELABEL_H
#define QIMAGELABEL_H

#include <QObject>
#include<QLabel>

#include<opencv2/opencv.hpp>
using namespace cv;

class QImageLabel : public QLabel
{
    Q_OBJECT
public:
    explicit QImageLabel(QObject *parent = 0);

    Mat image;
protected:
    void mousePressEvent(QMouseEvent *ev);

signals:
    void sendImage(Mat img);

public slots:
};

#endif // QIMAGELABEL_H
