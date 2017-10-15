#include "qsurf_feature.h"

QSurf_Feature::QSurf_Feature()
{
    surf = SURF::create(800);
}



void QSurf_Feature::doFeatureDetect()
{
    QString imageName;
    int count=0;
    int  label;
    printf("procesing doFeatureDetect!!!\n");
    fflush(stdout);

    for(int i=0;i<imagePath.size();i++)
    {
        imageName=imagePath[i];
        label = iamgeLabel[i];
        Mat src = imread(imageName.toStdString());
        if(src.empty())
        {
            continue;
        }
        vector<KeyPoint>key1;
        Mat c;
        Rect rect(4,10,src.cols-5,src.rows-11);
        src = src(rect).clone();
        cutMat(src,src);
        cv::resize(src,src,Size(25,35));
//        QString fileName;
//        fileName.sprintf("./samples/%d_%s.png",count++,getPai(label).toLatin1().data());
//        imwrite(fileName.toStdString(),src);
//        imshow("src2",src);
//        waitKey(1);
        surf->detectAndCompute(src, Mat(), key1, c);//输入图像，输入掩码，输入特征点，输出Mat，存放所有特征点的描述向量
        printf("%d,%d ",c.cols,c.rows);
        fflush(NULL);
//        imageFeature.push_back(feature);
    }
}

void QSurf_Feature::trainSVM()
{
    //1
    getImagesAndLabels();
    //2
    doFeatureDetect();
    //3

//    Mat imgFeature = Mat(imageFeature.size(),793,CV_32FC1);
////    Mat imgFeature = Mat(imageFeature2.size(),2625,CV_32FC1);
//    Mat imgLabel = Mat(imageFeature.size(),1,CV_32SC1);

//    for(int i=0;i<imageFeature.size();i++)
//    {
//        imgLabel.at<int>(i,0) = imageFeature[i].label;
//        for(int j=0;j<793;j++)
//        {
//            imgFeature.at<float>(i,j) = imageFeature[i].feature[j];
//        }
//    }

//    //4
//    Ptr<cv::ml::SVM> model = cv::ml::SVM::create();
//    model->setType(cv::ml::SVM::C_SVC);
//    model->setKernel(cv::ml::SVM::LINEAR);  //核函数
//   // model->setC(3);
//   // model->setGamma(2);


//    model->setTermCriteria(cvTermCriteria(CV_TERMCRIT_ITER, 400000, 0.00001));

//    //设置训练数据
//    Ptr<cv::ml::TrainData> tData =cv::ml::TrainData::create(imgFeature, cv::ml::ROW_SAMPLE, imgLabel);
//    // 训练分类器
//    model->train(tData);
//    model->save("svm_model.xml");
//    QMessageBox::information(NULL,"title","model finish");

}
