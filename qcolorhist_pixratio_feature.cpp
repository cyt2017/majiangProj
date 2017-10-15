
#include "qcolorhist_pixratio_feature.h"


void QColorHist_PixRatio_Feature::loadModel(QString str)
{
    if(str.length()<=0)
    {
        QMessageBox::information(NULL,"title","model path is null");
    }
   // QString str= "/home/cty/workspace/majiang/majiang_case/build/svm_model.xml";
    if(str.contains("svm"))
    {
        printf("load SVM\n");
        fflush(NULL);
        model =cv::ml::SVM::load(str.toStdString());
    }
    //    knnModel = cv::ml::KNearest::load(str.toStdString());
    if(str.contains("knn"))
    {
        printf("load KNN\n");
        fflush(NULL);
        knnModel = Algorithm::load<cv::ml::KNearest>(str.toStdString());
    }
}

QString QColorHist_PixRatio_Feature::getPai(int label)
{
    if(label<10)
    {
        return QString::asprintf("%d",label)+QString::fromLocal8Bit("饼");
    }
    else if(label<19)
    {
        return QString::asprintf("%d",label-9)+QString::fromLocal8Bit("条");
    }
    else if(label<28)
    {
        return QString::asprintf("%d",label-18)+QString::fromLocal8Bit("万");
    }
    else if(label==28)
    {
        return QString::fromLocal8Bit("东")/*QString::asprintf("Dong")*/;
    }
    else if(label==29)
    {
        return QString::fromLocal8Bit("南")/*QString::asprintf("Nan")*/;
    }
    else if(label==30)
    {
        return QString::fromLocal8Bit("西")/*QString::asprintf("Xi")*/;
    }
    else if(label==31)
    {
        return QString::fromLocal8Bit("北")/*QString::asprintf("Bei")*/;
    }
    else if(label==32)
    {
        return QString::fromLocal8Bit("中")/*QString::asprintf("Zhong")*/;
    }
    else if(label==33)
    {
        return QString::fromLocal8Bit("白")/*QString::asprintf("Baiban")*/;
    }
    else if(label==34)
    {
        return QString::fromLocal8Bit("发")/*QString::asprintf("Fa")*/;
    }
    else if(label==35)
    {
        return QString::fromLocal8Bit("梅")/*QString::asprintf("Fa")*/;
    }
    else if(label==36)
    {
        return QString::fromLocal8Bit("兰")/*QString::asprintf("Fa")*/;
    }
    else if(label==37)
    {
        return QString::fromLocal8Bit("竹")/*QString::asprintf("Fa")*/;
    }
    else if(label==38)
    {
        return QString::fromLocal8Bit("菊")/*QString::asprintf("Fa")*/;
    }
    else if(label==39)
    {
        return QString::fromLocal8Bit("春")/*QString::asprintf("Fa")*/;
    }
    else if(label==40)
    {
        return QString::fromLocal8Bit("夏")/*QString::asprintf("Fa")*/;
    }
    else if(label==41)
    {
        return QString::fromLocal8Bit("秋")/*QString::asprintf("Fa")*/;
    }
    else if(label==42)
    {
        return QString::fromLocal8Bit("冬")/*QString::asprintf("Fa")*/;
    }
    else if(label==43)
    {
        return QString::fromLocal8Bit("老鼠")/*QString::asprintf("Fa")*/;
    }
    else if(label==44)
    {
        return QString::fromLocal8Bit("财神")/*QString::asprintf("Fa")*/;
    }
    else if(label==45)
    {
        return QString::fromLocal8Bit("猫")/*QString::asprintf("Fa")*/;
    }
    else if(label==46)
    {
        return QString::fromLocal8Bit("聚宝盆")/*QString::asprintf("Fa")*/;
    }
    else if(label==47)
    {
        return QString::fromLocal8Bit("百搭")/*QString::asprintf("Fa")*/;
    }
    else if(label==48)
    {
        return QString::fromLocal8Bit("空")/*QString::asprintf("Fa")*/;
    }
    else
    {
        return "error";
    }
}

bool QColorHist_PixRatio_Feature::getPredictResult(std::vector<Mat> &imgs,std::vector<QString> &labels)
{
    if(labels.size()>0)
    {
        labels.clear();
    }
    for(int i = 0;i<imgs.size();i++)
    {
        QString l = getPredictResult(imgs[i].clone());
        labels.push_back(l);
//        imshow("imgs",imgs[i]);
//        waitKey(-1);
    }
    return true;
}

void QColorHist_PixRatio_Feature::trainKNN()
{
    printf("use KNN \n");
    fflush(NULL);
    //1
    getImagesAndLabels();
    //2
    doFeatureDetect();
    //3

    Mat imgFeature = Mat(imageFeature.size(),793,CV_32FC1);
//    Mat imgFeature = Mat(imageFeature2.size(),2625,CV_32FC1);
    Mat imgLabel = Mat(imageFeature.size(),1,CV_32SC1);

    for(int i=0;i<imageFeature.size();i++)
    {
        imgLabel.at<int>(i,0) = imageFeature[i].label;
        for(int j=0;j<793;j++)
        {
            imgFeature.at<float>(i,j) = imageFeature[i].feature[j];
        }
    }

    //4
    Ptr<cv::ml::KNearest> model = cv::ml::KNearest::create();
    model->setDefaultK(5);
    model->setIsClassifier(true);

    //设置训练数据
    Ptr<cv::ml::TrainData> tData =cv::ml::TrainData::create(imgFeature, cv::ml::ROW_SAMPLE, imgLabel);
    // 训练分类器
    model->train(tData);
    model->save("knn_model.xml");
    QMessageBox::information(NULL,"title","model finish");
}


QString QColorHist_PixRatio_Feature::getPredictResult(Mat inSrc)
{
//    Mat mat = imread("/home/cyt/workspace/majiang/majiang_case/build/zi/xi/17.jpg");
    static int count=0;
    Mat mat = inSrc.clone();
    Rect rect(4,10,mat.cols-5,mat.rows-11);
    mat = mat(rect).clone();
    cutMat(mat,mat);
    cv::resize(mat,mat,Size(25,35));
//     QString fileName;
//     fileName.sprintf("./samples/%d.png",count++);
//     imwrite(fileName.toStdString(),mat);
//     imshow("src2",mat);
//     waitKey(1);



    Mat imgData = Mat(1,793,CV_32FC1);
    FEATURE feature;
    getFeature(mat,0,feature);

    for(int j=0;j<793;j++)
    {
        imgData.at<float>(0,j) = feature.feature[j];
    }

    float label = -1.0;
    if(!useKNN)
    {
        label = model->predict(imgData);
    }
    else
    {
        label = knnModel->predict(imgData);
    }
    return /*(int)label*/getPai((int)label);
}
void QColorHist_PixRatio_Feature::doFeatureDetect()
{
    QString imageName;
    int count=0;
    int  label;
    imageFeature.clear();
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
        FEATURE feature;
        Rect rect(4,10,src.cols-5,src.rows-11);
        src = src(rect).clone();
        cutMat(src,src);
        cv::resize(src,src,Size(25,35));
        QString fileName;
        fileName.sprintf("./samples/%d_%s.png",count++,getPai(label).toLatin1().data());
        imwrite(fileName.toStdString(),src);
        imshow("src2",src);
        waitKey(1);
        getFeature(src,label,feature);

        imageFeature.push_back(feature);
    }

}
void QColorHist_PixRatio_Feature::trainSVM()
{
    printf("use SVM \n");
    fflush(NULL);
    //1
    getImagesAndLabels();
    //2
    doFeatureDetect();
    //3

    Mat imgFeature = Mat(imageFeature.size(),793,CV_32FC1);
//    Mat imgFeature = Mat(imageFeature2.size(),2625,CV_32FC1);
    Mat imgLabel = Mat(imageFeature.size(),1,CV_32SC1);

    for(int i=0;i<imageFeature.size();i++)
    {
        imgLabel.at<int>(i,0) = imageFeature[i].label;
        for(int j=0;j<793;j++)
        {
            imgFeature.at<float>(i,j) = imageFeature[i].feature[j];
        }
    }

    //4
    Ptr<cv::ml::SVM> model = cv::ml::SVM::create();
    model->setType(cv::ml::SVM::C_SVC);
    model->setKernel(cv::ml::SVM::LINEAR);  //核函数
   // model->setC(3);
   // model->setGamma(2);


    model->setTermCriteria(cvTermCriteria(CV_TERMCRIT_ITER, 400000, 0.00001));

    //设置训练数据
    Ptr<cv::ml::TrainData> tData =cv::ml::TrainData::create(imgFeature, cv::ml::ROW_SAMPLE, imgLabel);
    // 训练分类器
    model->train(tData);
    model->save("svm_model.xml");
    QMessageBox::information(NULL,"title","model finish");
}

QColorHist_PixRatio_Feature::QColorHist_PixRatio_Feature()
{
    useKNN = false;
}
float QColorHist_PixRatio_Feature::getFeature(Mat inSrc)
{
    int num=0;
    int w = inSrc.cols;
    int h = inSrc.rows;
    for(int i=0;i<w;i++)
    {
        for(int j=0;j<h;j++)
        {
            if(inSrc.at<uchar>(j,i)==0)
            {
                num++;
            }
        }
    }
    float portion = (float)num/(float)(w*h);
    return portion;
}

bool QColorHist_PixRatio_Feature::getFeature(Mat srcIn,int label,FEATURE &feature)
{
    Mat gray,binary;
    Mat src = srcIn.clone();

    if(src.rows!=35 || src.cols!=25)
        return false;

    vector<Mat> rgb_planes;
    split( src, rgb_planes );

    int histR[256]={0};
    int histG[256]={0};
    int histB[256]={0};
    memset(histR,0,256*sizeof(int));
    memset(histG,0,256*4);
    memset(histB,0,256*4);

    for(int row=0;row<src.rows;row++)
    {
        for(int col=0;col<src.cols;col++)
        {
            int r=rgb_planes[0].at<uchar>(row,col);
            int g=rgb_planes[1].at<uchar>(row,col);
            int b=rgb_planes[2].at<uchar>(row,col);
            histR[r]++;
            histG[g]++;
            histB[b]++;
        }
    }

    memset(&feature,0,sizeof(feature));
    feature.label = label;
    int size=0;
    for(int row=0;row<256;row++)
    {
        feature.feature[size]= (float)histR[row];
        size++;
        feature.feature[size]= (float)histG[row];
        size++;
        feature.feature[size]= (float)histB[row];
        size++;
    }

//    imshow("src",src);



    //提取25维特征像素值
    cvtColor(src,gray,CV_BGR2GRAY);
//    imshow("gray",gray);
//    cv::medianBlur(gray,gray,3);
//    imshow("gray medianBlur",gray);

//    Mat m1=gray(Rect(0,0,gray.cols,13)).clone();
//    threshold(m1,binary,0,255,THRESH_BINARY+THRESH_OTSU);
//    imshow("m1",binary);

    threshold(gray,binary,0,255,THRESH_BINARY+THRESH_OTSU);
//    imshow("binary",binary);
//    waitKey(-1);

    int w = binary.cols/5;
    int h = binary.rows/5;

    for(int row=0;row<binary.rows;row+=h)
    {
        for(int col=0;col<binary.cols;col+=w)
        {
            feature.feature[size]=getFeature(binary(Rect(col,row,w,h)).clone());
            size++;
        }
    }

    return true;
}
