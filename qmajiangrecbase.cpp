#include "qmajiangrecbase.h"
void QMaJiangRecBase::GetGrayAvgStdDev(cv::Mat& src, double& avg, double &stddev)
{
    cv::Mat img;
    if (src.channels() == 3)
        cv::cvtColor(src, img, CV_BGR2GRAY);
    else
        img = src;
    cv::mean(src);
    cv::Mat mean;
    cv::Mat stdDev;
    cv::meanStdDev(img, mean, stdDev);

    avg = mean.ptr<double>(0)[0];
    stddev = stdDev.ptr<double>(0)[0];
}

bool QMaJiangRecBase::getDetails_152(Mat inSrc)
{
    //1 分解东南西北
    getMaJiangImage_152(inSrc);
    //2 提取每一张麻将
    segmentationImage_152();
}

bool QMaJiangRecBase::getMaJiangImage_152(Mat inSrc)
{
    Mat out;
    Mat src = inSrc.clone();
    Mat gray,binary,dst;
    Mat img[3];
    Rect imgRect[3];
    if(src.empty())
    {
        printf("src.empty() fail..\n");
        return false;
    }

    cvtColor(src,gray,CV_BGR2GRAY);
//    cv::medianBlur(gray,gray,3);
    blur(gray,gray,Size(7,7));

    Mat kernel = getStructuringElement(MORPH_RECT,Size(3,3));
    cv::erode(gray,gray,kernel);
    morphologyEx(gray,gray,MORPH_OPEN,kernel);

    threshold(gray,binary,0,255,THRESH_BINARY+THRESH_OTSU);

    vector<vector<Point>> contours;
    Rect rect;

    findContours(binary,contours,CV_RETR_EXTERNAL,CV_CHAIN_APPROX_SIMPLE);
    int j=0;
    for(int i=0;i<contours.size();i++)
    {
        if(contourArea(contours[i])<500)
        {
            continue;
        }
        cvtColor(binary,dst,CV_GRAY2BGR);
//        drawContours(dst,contours,-1,Scalar(0,0,255),2,8);
        rect = boundingRect(contours[i]);
        printf("rect:[%d,%d,%d,%d]\n",rect.x,rect.y,rect.width,rect.height);
        fflush(NULL);

        if(((double)rect.width/(double)rect.height>5.8 && (double)rect.width/(double)rect.height<6.4)\
                ||((double)rect.width/(double)rect.height>0.15 && (double)rect.width/(double)rect.height<0.2))
        {
             src(rect).copyTo(out);

             if(rect.width>rect.height)
             {
                 imgWest = out.clone();
                 continue;
             }
            img[j]=out.clone();
            imgRect[j] = rect;
            j++;
        }
        if(((double)rect.width/(double)rect.height>3.5) && ((double)rect.width/(double)rect.height<3.9 ))
        {
            rect.x = rect.x;
            rect.y = rect.y+rect.height/2.5;
            rect.width = rect.width;
            rect.height = rect.height-rect.height/2.5;
            src(rect).copyTo(out);
            imgEast = out.clone();
        }
    }

    if(imgRect[0].x <= imgRect[1].x)
    {
        imgNorth = img[0].clone();
        imgSouth = img[1].clone();
    }
    else
    {
        imgNorth = img[1].clone();
        imgSouth = img[0].clone();
    }
    imshow("East",imgEast);
    imshow("West",imgWest);
    imshow("North",imgNorth);
    imshow("South",imgSouth);
    waitKey(-1);
    return true;
}

void QMaJiangRecBase::segmentationImage_152()
{
    Rect rect;
    imgE.clear();imgN.clear();imgW.clear();imgS.clear();
    cv::resize(imgEast,imgEast,Size(imgEast.cols+19-imgEast.cols%19,imgEast.rows));
    int w  = imgEast.cols/19;
    int h = imgEast.rows/2;

    for(int x=0;x<19*w;x+=w)
    {
        for(int y=0;y<2*h;y+=h)
        {
            rect = Rect(x,y,w,h);
            imgE.push_back(imgEast(rect).clone());
//            imshow("imgEast",imgEast(rect).clone());
//            waitKey(-1);
        }
    }
    cv::resize(imgWest,imgWest,Size(imgWest.cols+19-imgWest.cols%19,imgWest.rows));
     w  = imgWest.cols/19;
     h = imgWest.rows/2;

    for(int x=0;x<19*w;x+=w)
    {
        for(int y=0;y<2*h;y+=h)
        {
            rect = Rect(x,y,w,h);
            imgW.push_back(imgWest(rect).clone());
//            imshow("imgWest",imgWest(rect).clone());
//            waitKey(-1);
        }
    }
    Mat src = faceRotate(imgNorth,90);
    cv::resize(src,src,Size(src.cols+19-src.cols%19,src.rows));
    w  = src.cols/19;
    h = src.rows/2;

    for(int x=0;x<19*w;x+=w)
    {
        for(int y=0;y<2*h;y+=h)
        {
            rect = Rect(x,y,w,h);
            imgN.push_back(src(rect).clone());
//            imshow("imgNorth",src(rect).clone());
//            waitKey(-1);
        }
    }
    src = faceRotate(imgSouth,270);
    cv::resize(src,src,Size(src.cols+19-src.cols%19,src.rows));
    w  = src.cols/19;
    h = src.rows/2;

    for(int x=0;x<19*w;x+=w)
    {
        for(int y=0;y<2*h;y+=h)
        {
            rect = Rect(x,y,w,h);
            imgS.push_back(src(rect).clone());
//            imshow("imgSouth",src(rect).clone());
//            waitKey(-1);
        }
    }
}

void QMaJiangRecBase::cutMat(Mat in,Mat &out)
{
    double  avg=0;
    double stddev=0;
    Mat src = in.clone();
    Mat out1,out2,out3,out4;

    int line=0;
    for(int row=0;row<src.rows;row++)
    {
        Mat tmp=src(Rect(0,row,src.cols,1)).clone();
        GetGrayAvgStdDev(tmp, avg,  stddev);
        if(stddev<15)
            line++;
        else
            break;
        if(line==src.rows)
        {
            line = 0;
        }
    }
    out1 = src(Rect(0,line,src.cols,src.rows-line)).clone();


//    printf("\n");
    line = 0;
    for(int row=out1.rows-1;row>=out1.rows-10;row--)
    {
        Mat tmp=out1(Rect(0,row,out1.cols,1)).clone();
        GetGrayAvgStdDev(tmp, avg,  stddev);
        if(stddev<15)
            line++;
        else
            break;
        if(line==9)
        {
            line = 0;
        }
//        printf("%lf ",stddev);
    }

    out2 = out1(Rect(0,0,out1.cols,out1.rows-line)).clone();

    line = 0;
    for(int col=0;col<out2.cols;col++)
    {
        Mat tmp=out2(Rect(col,0,1,out2.rows)).clone();
        GetGrayAvgStdDev(tmp, avg,  stddev);
        if(stddev<10)
            line++;
        else
            break;
        if(line==out2.cols)
        {
            line = 0;
        }
//        printf("%lf ",stddev);
    }

    out3 = out2(Rect(line,0,out2.cols-line,out2.rows)).clone();

    line = 0;
    for(int col=out3.cols-1;col>0;col--)
    {
        Mat tmp=out3(Rect(col,0,1,out3.rows)).clone();
        GetGrayAvgStdDev(tmp, avg,  stddev);
        if(stddev<10)
            line++;
        else
            break;
        if(line==out3.cols-1)
        {
            line = 0;
        }
//        printf("%lf ",stddev);
    }

    out4 = out3(Rect(0,0,out3.cols-line,out3.rows)).clone();

    out = out4.clone();
//    printf("\n");
}

QMaJiangRecBase::QMaJiangRecBase(QObject *parent) : QObject(parent)
{
    imgE.clear();
    imgN.clear();
    imgW.clear();
    imgS.clear();
    imagePath.clear();
    iamgeLabel.clear();
}
bool QMaJiangRecBase::getDetails(Mat inSrc)
{
    //1 分解东南西北
    getMaJiangImage(inSrc);
    //2 提取每一张麻将
    segmentationImage();
}

bool QMaJiangRecBase::getMaJiangImage(Mat inSrc)
{
    Mat out;
    Mat src = inSrc.clone();
    Mat gray,binary,dst;
    Mat img[3];
    Rect imgRect[3];
    if(src.empty())
    {
        printf("src.empty() fail..\n");
        return false;
    }

    cvtColor(src,gray,CV_BGR2GRAY);
//    cv::medianBlur(gray,gray,3);
    blur(gray,gray,Size(7,7));

    Mat kernel = getStructuringElement(MORPH_RECT,Size(3,3));
    cv::erode(gray,gray,kernel);
    morphologyEx(gray,gray,MORPH_OPEN,kernel);

    threshold(gray,binary,0,255,THRESH_BINARY+THRESH_OTSU);

    vector<vector<Point>> contours;
    Rect rect;

    findContours(binary,contours,CV_RETR_EXTERNAL,CV_CHAIN_APPROX_SIMPLE);
    int j=0;
    for(int i=0;i<contours.size();i++)
    {
        if(contourArea(contours[i])<500)
        {
            continue;
        }
        cvtColor(binary,dst,CV_GRAY2BGR);
//        drawContours(dst,contours,-1,Scalar(0,0,255),2,8);
        rect = boundingRect(contours[i]);
        printf("rect:[%d,%d,%d,%d]\n",rect.x,rect.y,rect.width,rect.height);
        fflush(NULL);

        if(((double)rect.width/(double)rect.height>5.3 && (double)rect.width/(double)rect.height<5.6)\
                ||((double)rect.width/(double)rect.height>0.15 && (double)rect.width/(double)rect.height<0.2))
        {
             src(rect).copyTo(out);

             if(rect.width>rect.height)
             {
                 imgWest = out.clone();
                 continue;
             }
            img[j]=out.clone();
            imgRect[j] = rect;
            j++;
        }
        if(((double)rect.width/(double)rect.height>3.2) && ((double)rect.width/(double)rect.height<3.354 ))
        {
            rect.x = rect.x;
            rect.y = rect.y+rect.height/2.5;
            rect.width = rect.width;
            rect.height = rect.height-rect.height/2.5;
            src(rect).copyTo(out);
            imgEast = out.clone();
        }
    }

    if(imgRect[0].x <= imgRect[1].x)
    {
        imgNorth = img[0].clone();
        imgSouth = img[1].clone();
    }
    else
    {
        imgNorth = img[1].clone();
        imgSouth = img[0].clone();
    }
    return true;
}
Mat QMaJiangRecBase::faceRotate(Mat inSrc, double angle)
{
    Mat src,dst;
    src = inSrc.clone();
    cv::Point2f center(src.cols / 2, src.rows / 2);
    cv::Mat rot = cv::getRotationMatrix2D(center, angle, 1);
    cv::Rect bbox = cv::RotatedRect(center, src.size(), angle).boundingRect();

    rot.at<double>(0, 2) += bbox.width / 2.0 - center.x;
    rot.at<double>(1, 2) += bbox.height / 2.0 - center.y;
    cv::warpAffine(src, dst, rot, bbox.size());
    return dst;
}
void QMaJiangRecBase::segmentationImage()
{
    Rect rect;
    imgE.clear();imgN.clear();imgW.clear();imgS.clear();
    cv::resize(imgEast,imgEast,Size(imgEast.cols+17-imgEast.cols%17,imgEast.rows));
    int w  = imgEast.cols/17;
    int h = imgEast.rows/2;

    for(int x=0;x<17*w;x+=w)
    {
        for(int y=0;y<2*h;y+=h)
        {
            rect = Rect(x,y,w,h);
            imgE.push_back(imgEast(rect).clone());
        }
    }
    cv::resize(imgWest,imgWest,Size(imgWest.cols+17-imgWest.cols%17,imgWest.rows));
     w  = imgWest.cols/17;
     h = imgWest.rows/2;

    for(int x=0;x<17*w;x+=w)
    {
        for(int y=0;y<2*h;y+=h)
        {
            rect = Rect(x,y,w,h);
            imgW.push_back(imgWest(rect).clone());
        }
    }
    Mat src = faceRotate(imgNorth,90);
    cv::resize(src,src,Size(src.cols+17-src.cols%17,src.rows));
    w  = src.cols/17;
    h = src.rows/2;

    for(int x=0;x<17*w;x+=w)
    {
        for(int y=0;y<2*h;y+=h)
        {
            rect = Rect(x,y,w,h);
            imgN.push_back(src(rect).clone());
        }
    }
    src = faceRotate(imgSouth,270);
    cv::resize(src,src,Size(src.cols+17-src.cols%17,src.rows));
    w  = src.cols/17;
    h = src.rows/2;

    for(int x=0;x<17*w;x+=w)
    {
        for(int y=0;y<2*h;y+=h)
        {
            rect = Rect(x,y,w,h);
            imgS.push_back(src(rect).clone());
        }
    }
}
void QMaJiangRecBase::getImagesAndLabels()
{
    QFile imageFile;

    imagePath.clear();
    iamgeLabel.clear();


    printf("procesing bing!!!\n");
    fflush(stdout);
    QString path = "/home/cyt/workspace/majiang/maJiangProj/build/bing/";
    int label = 0;
    for(int i=1;i<10;i++)
    {
        label++;
        QString sPath = path+QString::asprintf("%d/",i);
        for(int j=0;j<999;j++)
        {
            QString fileName = sPath+QString::asprintf("%d.png",j);
            imageFile.setFileName(fileName);
            if(imageFile.exists())
            {
                imagePath.push_back(fileName);
                iamgeLabel.push_back(label);
            }
        }

    }
    printf("procesing tiao!!!\n");
    fflush(stdout);
    path = "/home/cyt/workspace/majiang/maJiangProj/build/tiao/";
    for(int i=1;i<10;i++)
    {
        label++;
        QString sPath = path+QString::asprintf("%d/",i);
        for(int j=0;j<999;j++)
        {
            QString fileName = sPath+QString::asprintf("%d.png",j);
            imageFile.setFileName(fileName);
            if(imageFile.exists())
            {
                imagePath.push_back(fileName);
                iamgeLabel.push_back(label);
            }
        }
    }

    printf("procesing wan!!!\n");
    fflush(stdout);
    path = "/home/cyt/workspace/majiang/maJiangProj/build/wan/";
    for(int i=1;i<10;i++)
    {
        label++;
        QString sPath = path+QString::asprintf("%d/",i);
        for(int j=0;j<999;j++)
        {
            QString fileName = sPath+QString::asprintf("%d.png",j);
            imageFile.setFileName(fileName);
            if(imageFile.exists())
            {
                imagePath.push_back(fileName);
                iamgeLabel.push_back(label);
            }
        }
    }
    printf("procesing dong!!!\n");
    fflush(stdout);
    path = "/home/cyt/workspace/majiang/maJiangProj/build/zi/dong/";
    label++;
    for(int j=0;j<999;j++)
    {
        QString fileName = path+QString::asprintf("%d.png",j);
        imageFile.setFileName(fileName);
        if(imageFile.exists())
        {
            imagePath.push_back(fileName);
            iamgeLabel.push_back(label);
        }
    }
    printf("procesing nan!!!\n");
    fflush(stdout);
    path = "/home/cyt/workspace/majiang/maJiangProj/build/zi/nan/";
    label++;
    for(int j=0;j<999;j++)
    {
        QString fileName = path+QString::asprintf("%d.png",j);
        imageFile.setFileName(fileName);
        if(imageFile.exists())
        {
            imagePath.push_back(fileName);
            iamgeLabel.push_back(label);
        }
    }
    printf("procesing xi!!!\n");
    fflush(stdout);
    path = "/home/cyt/workspace/majiang/maJiangProj/build/zi/xi/";
    label++;
    for(int j=0;j<999;j++)
    {
        QString fileName = path+QString::asprintf("%d.png",j);
        imageFile.setFileName(fileName);
        if(imageFile.exists())
        {
            imagePath.push_back(fileName);
            iamgeLabel.push_back(label);
        }
    }
    printf("procesing bei!!!\n");
    fflush(stdout);
    path = "/home/cyt/workspace/majiang/maJiangProj/build/zi/bei/";
    label++;
    for(int j=0;j<999;j++)
    {
        QString fileName = path+QString::asprintf("%d.png",j);
        imageFile.setFileName(fileName);
        if(imageFile.exists())
        {
            imagePath.push_back(fileName);
            iamgeLabel.push_back(label);
        }
    }
    printf("procesing zhong!!!\n");
    fflush(stdout);
    path = "/home/cyt/workspace/majiang/maJiangProj/build/zi/zhong/";
    label++;
    for(int j=0;j<999;j++)
    {
        QString fileName = path+QString::asprintf("%d.png",j);
        imageFile.setFileName(fileName);
        if(imageFile.exists())
        {
            imagePath.push_back(fileName);
            iamgeLabel.push_back(label);
        }
    }
    printf("procesing baiban!!!\n");
    fflush(stdout);
    path = "/home/cyt/workspace/majiang/maJiangProj/build/zi/baiban/";
    label++;
    for(int j=0;j<999;j++)
    {
        QString fileName = path+QString::asprintf("%d.png",j);
        imageFile.setFileName(fileName);
        if(imageFile.exists())
        {
            imagePath.push_back(fileName);
            iamgeLabel.push_back(label);
        }
    }
    printf("procesing fa!!!\n");
    fflush(stdout);
    path = "/home/cyt/workspace/majiang/maJiangProj/build/zi/fa/";
    label++;
    for(int j=0;j<999;j++)
    {
        QString fileName = path+QString::asprintf("%d.png",j);
        imageFile.setFileName(fileName);
        if(imageFile.exists())
        {
            imagePath.push_back(fileName);
            iamgeLabel.push_back(label);
        }
    }
    printf("procesing Mei!!!\n");
    fflush(stdout);
    path = "/home/cyt/workspace/majiang/maJiangProj/build/hua/Mei/";
    label++;
    for(int j=0;j<999;j++)
    {
        QString fileName = path+QString::asprintf("%d.png",j);
        imageFile.setFileName(fileName);
        if(imageFile.exists())
        {
            imagePath.push_back(fileName);
            iamgeLabel.push_back(label);
        }
    }
    printf("procesing Lan!!!\n");
    fflush(stdout);
    path = "/home/cyt/workspace/majiang/maJiangProj/build/hua/Lan/";
    label++;
    for(int j=0;j<999;j++)
    {
        QString fileName = path+QString::asprintf("%d.png",j);
        imageFile.setFileName(fileName);
        if(imageFile.exists())
        {
            imagePath.push_back(fileName);
            iamgeLabel.push_back(label);
        }
    }
    printf("procesing Zhu!!!\n");
    fflush(stdout);
    path = "/home/cyt/workspace/majiang/maJiangProj/build/hua/Zhu/";
    label++;
    for(int j=0;j<999;j++)
    {
        QString fileName = path+QString::asprintf("%d.png",j);
        imageFile.setFileName(fileName);
        if(imageFile.exists())
        {
            imagePath.push_back(fileName);
            iamgeLabel.push_back(label);
        }
    }
    printf("procesing Ju!!!\n");
    fflush(stdout);
    path = "/home/cyt/workspace/majiang/maJiangProj/build/hua/Ju/";
    label++;
    for(int j=0;j<999;j++)
    {
        QString fileName = path+QString::asprintf("%d.png",j);
        imageFile.setFileName(fileName);
        if(imageFile.exists())
        {
            imagePath.push_back(fileName);
            iamgeLabel.push_back(label);
        }
    }
    printf("procesing Spring!!!\n");
    fflush(stdout);
    path = "/home/cyt/workspace/majiang/maJiangProj/build/hua/Spring/";
    label++;
    for(int j=0;j<999;j++)
    {
        QString fileName = path+QString::asprintf("%d.png",j);
        imageFile.setFileName(fileName);
        if(imageFile.exists())
        {
            imagePath.push_back(fileName);
            iamgeLabel.push_back(label);
        }
    }
    printf("procesing Summer!!!\n");
    fflush(stdout);
    path = "/home/cyt/workspace/majiang/maJiangProj/build/hua/Summer/";

    label++;
    for(int j=0;j<999;j++)
    {
        QString fileName = path+QString::asprintf("%d.png",j);
        imageFile.setFileName(fileName);
        if(imageFile.exists())
        {
            imagePath.push_back(fileName);
            iamgeLabel.push_back(label);
        }
    }
    printf("procesing Autumn!!!\n");
    fflush(stdout);
    path = "/home/cyt/workspace/majiang/maJiangProj/build/hua/Autumn/";
    label++;
    for(int j=0;j<999;j++)
    {
        QString fileName = path+QString::asprintf("%d.png",j);
        imageFile.setFileName(fileName);
        if(imageFile.exists())
        {
            imagePath.push_back(fileName);
            iamgeLabel.push_back(label);
        }
    }
    printf("procesing Winter!!!\n");
    fflush(stdout);
    path = "/home/cyt/workspace/majiang/maJiangProj/build/hua/Winter/";
    label++;
    for(int j=0;j<999;j++)
    {
        QString fileName = path+QString::asprintf("%d.png",j);
        imageFile.setFileName(fileName);
        if(imageFile.exists())
        {
            imagePath.push_back(fileName);
            iamgeLabel.push_back(label);
        }
    }
    printf("procesing Mouse!!!\n");
    fflush(stdout);
    path = "/home/cty/workspace/majiang/maJiangProj/build/hua/Mouse/";
    label++;
    for(int j=0;j<999;j++)
    {
        QString fileName = path+QString::asprintf("%d.png",j);
        imageFile.setFileName(fileName);
        if(imageFile.exists())
        {
            imagePath.push_back(fileName);
            iamgeLabel.push_back(label);
        }
    }
    printf("procesing CaiShen!!!\n");
    fflush(stdout);
    path = "/home/cty/workspace/majiang/maJiangProj/build/hua/CaiShen/";
    label++;
    for(int j=0;j<999;j++)
    {
        QString fileName = path+QString::asprintf("%d.png",j);
        imageFile.setFileName(fileName);
        if(imageFile.exists())
        {
            imagePath.push_back(fileName);
            iamgeLabel.push_back(label);
        }
    }
    printf("procesing Cat!!!\n");
    fflush(stdout);
    path = "/home/cty/workspace/majiang/maJiangProj/build/hua/Cat/";
    label++;
    for(int j=0;j<999;j++)
    {
        QString fileName = path+QString::asprintf("%d.png",j);
        imageFile.setFileName(fileName);
        if(imageFile.exists())
        {
            imagePath.push_back(fileName);
            iamgeLabel.push_back(label);
        }
    }
    printf("procesing JuBaoPen!!!\n");
    fflush(stdout);
    path = "/home/cty/workspace/majiang/maJiangProj/build/hua/JuBaoPen/";
    label++;
    for(int j=0;j<999;j++)
    {
        QString fileName = path+QString::asprintf("%d.png",j);
        imageFile.setFileName(fileName);
        if(imageFile.exists())
        {
            imagePath.push_back(fileName);
            iamgeLabel.push_back(label);
        }
    }
    printf("procesing BaiDa!!!\n");
    fflush(stdout);
    path = "/home/cyt/workspace/majiang/maJiangProj/build/hua/BaiDa/";
    label++;
    for(int j=0;j<999;j++)
    {
        QString fileName = path+QString::asprintf("%d.png",j);
        imageFile.setFileName(fileName);
        if(imageFile.exists())
        {
            imagePath.push_back(fileName);
            iamgeLabel.push_back(label);
        }
    }
    printf("procesing Kong!!!\n");
    fflush(stdout);
    path = "/home/cyt/workspace/majiang/maJiangProj/build/hua/Kong/";
    label++;
    for(int j=0;j<999;j++)
    {
        QString fileName = path+QString::asprintf("%d.png",j);
        imageFile.setFileName(fileName);
        if(imageFile.exists())
        {
            imagePath.push_back(fileName);
            iamgeLabel.push_back(label);
        }
    }
//    imshow("fa",imread(imagePath[imagePath.size()-1].toStdString()));
//    waitKey(-1);
//    printf("iamgeLabel[]:%d\n",iamgeLabel[iamgeLabel.size()-1]);
//    fflush(NULL);
}
