#ifndef QMAJIANGRECBASE_H
#define QMAJIANGRECBASE_H

#include <QObject>
#include <opencv2/opencv.hpp>
#include <QDir>
#include <QFile>
#include <QImage>
#include <QMessageBox>


using namespace std;
using namespace cv;
class QMaJiangRecBase : public QObject
{
    Q_OBJECT
public:
    explicit QMaJiangRecBase(QObject *parent = 0);

signals:

public slots:


public:
    //一整张大图切割成小图
    Mat imgEast,imgSouth,imgNorth,imgWest;
    vector<Mat> imgE,imgN,imgW,imgS;

    bool getDetails(Mat inSrc);
    bool getMaJiangImage(Mat inSrc);
    void segmentationImage();
    Mat faceRotate(Mat inSrc, double angle);
    void cutMat(Mat in,Mat &out);
    void GetGrayAvgStdDev(cv::Mat& src, double& avg, double &stddev);

    //152张麻将
    bool getDetails_152(Mat inSrc);
    bool getMaJiangImage_152(Mat inSrc);
    void segmentationImage_152();

    //用于训练的样本
    vector<QString> imagePath;
    vector<int> iamgeLabel;

    void getImagesAndLabels();
};

#endif // QMAJIANGRECBASE_H
