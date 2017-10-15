#ifndef QSURF_FEATURE_H
#define QSURF_FEATURE_H
#include"qmajiangrecbase.h"
#include "opencv2/features2d.hpp"
#include"opencv2/xfeatures2d.hpp"
#include"opencv2/ml.hpp"

using namespace cv::xfeatures2d;

class QSurf_Feature : public QMaJiangRecBase
{
public:
    QSurf_Feature();

    Ptr<SURF> surf;
    void doFeatureDetect();
    void trainSVM();
};

#endif // QSURF_FEATURE_H
