#ifndef QCOLORHIST_PIXRATIO_FEATURE_H
#define QCOLORHIST_PIXRATIO_FEATURE_H
#include"qmajiangrecbase.h"
#include<QMessageBox>
#include<opencv2/ml/ml.hpp>
typedef struct
{
    float feature[793];
    int label;
}FEATURE;

class QColorHist_PixRatio_Feature : public QMaJiangRecBase
{
    Q_OBJECT
public:
    QColorHist_PixRatio_Feature();
    void doFeatureDetect();
    void trainSVM();
    float getFeature(Mat inSrc);
    bool getFeature(Mat srcIn,int label,FEATURE &feature);
    vector<FEATURE> imageFeature;


    Ptr<cv::ml::SVM> model;
    void loadModel(QString str);

    QString  getPai(int label);
    QString getPredictResult(Mat inSrc);
    bool getPredictResult(std::vector<Mat> &imgs,std::vector<QString> &labels);


    //knnTrain
    bool useKNN;
    Ptr<cv::ml::KNearest> knnModel;
    void trainKNN();
};

#endif // QCOLORHIST_PIXRATIO_FEATURE_H
