#include "dialogmj152.h"
#include "ui_dialogmj152.h"

DialogMJ152::DialogMJ152(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogMJ152)
{
    ui->setupUi(this);

//east
    imageLabelEast[0] = ui->label;
    imageLabelEast[1] = ui->label_2;
    imageLabelEast[2] = ui->label_3;
    imageLabelEast[3] = ui->label_4;
    imageLabelEast[4] = ui->label_5;
    imageLabelEast[5] = ui->label_6;
    imageLabelEast[6] = ui->label_7;
    imageLabelEast[7] = ui->label_8;
    imageLabelEast[8] = ui->label_9;
    imageLabelEast[9] = ui->label_10;
    imageLabelEast[10] = ui->label_11;
    imageLabelEast[11] = ui->label_12;
    imageLabelEast[12] = ui->label_13;
    imageLabelEast[13] = ui->label_14;
    imageLabelEast[14] = ui->label_15;
    imageLabelEast[15] = ui->label_16;
    imageLabelEast[16] = ui->label_17;
    imageLabelEast[17] = ui->label_18;
    imageLabelEast[18] = ui->label_19;

    imageLabelEast[19] = ui->label_20;
    imageLabelEast[20] = ui->label_21;
    imageLabelEast[21] = ui->label_22;
    imageLabelEast[22] = ui->label_23;
    imageLabelEast[23] = ui->label_24;
    imageLabelEast[24] = ui->label_25;
    imageLabelEast[25] = ui->label_26;
    imageLabelEast[26] = ui->label_27;
    imageLabelEast[27] = ui->label_28;
    imageLabelEast[28] = ui->label_29;
    imageLabelEast[29] = ui->label_30;
    imageLabelEast[30] = ui->label_31;
    imageLabelEast[31] = ui->label_32;
    imageLabelEast[32] = ui->label_33;
    imageLabelEast[33] = ui->label_34;
    imageLabelEast[34] = ui->label_35;
    imageLabelEast[35] = ui->label_36;
    imageLabelEast[36] = ui->label_37;
    imageLabelEast[37] = ui->label_38;

    int i=0;
    txtLabelEast[i++] = ui->label_39;
    txtLabelEast[i++] = ui->label_40;
    txtLabelEast[i++] = ui->label_41;
    txtLabelEast[i++] = ui->label_42;
    txtLabelEast[i++] = ui->label_43;
    txtLabelEast[i++] = ui->label_44;
    txtLabelEast[i++] = ui->label_45;
    txtLabelEast[i++] = ui->label_46;
    txtLabelEast[i++] = ui->label_47;
    txtLabelEast[i++] = ui->label_48;
    txtLabelEast[i++] = ui->label_49;
    txtLabelEast[i++] = ui->label_50;
    txtLabelEast[i++] = ui->label_51;
    txtLabelEast[i++] = ui->label_52;
    txtLabelEast[i++] = ui->label_53;
    txtLabelEast[i++] = ui->label_54;
    txtLabelEast[i++] = ui->label_55;
    txtLabelEast[i++] = ui->label_56;
    txtLabelEast[i++] = ui->label_57;
    txtLabelEast[i++] = ui->label_58;
    txtLabelEast[i++] = ui->label_59;
    txtLabelEast[i++] = ui->label_60;
    txtLabelEast[i++] = ui->label_61;
    txtLabelEast[i++] = ui->label_62;
    txtLabelEast[i++] = ui->label_63;
    txtLabelEast[i++] = ui->label_64;
    txtLabelEast[i++] = ui->label_65;
    txtLabelEast[i++] = ui->label_66;
    txtLabelEast[i++] = ui->label_67;
    txtLabelEast[i++] = ui->label_68;
    txtLabelEast[i++] = ui->label_69;
    txtLabelEast[i++] = ui->label_70;
    txtLabelEast[i++] = ui->label_71;
    txtLabelEast[i++] = ui->label_72;
    txtLabelEast[i++] = ui->label_73;
    txtLabelEast[i++] = ui->label_74;
    txtLabelEast[i++] = ui->label_75;
    txtLabelEast[i++] = ui->label_76;
    //west
    imageLabelWest[0] = ui->label_77;
    imageLabelWest[1] = ui->label_78;
    imageLabelWest[2] = ui->label_79;
    imageLabelWest[3] = ui->label_80;
    imageLabelWest[4] = ui->label_81;
    imageLabelWest[5] = ui->label_82;
    imageLabelWest[6] = ui->label_83;
    imageLabelWest[7] = ui->label_84;
    imageLabelWest[8] = ui->label_85;
    imageLabelWest[9] = ui->label_86;
    imageLabelWest[10] = ui->label_87;
    imageLabelWest[11] = ui->label_88;
    imageLabelWest[12] = ui->label_89;
    imageLabelWest[13] = ui->label_90;
    imageLabelWest[14] = ui->label_91;
    imageLabelWest[15] = ui->label_92;
    imageLabelWest[16] = ui->label_93;
    imageLabelWest[17] = ui->label_94;
    imageLabelWest[18] = ui->label_95;

    imageLabelWest[19] = ui->label_96;
    imageLabelWest[20] = ui->label_97;
    imageLabelWest[21] = ui->label_98;
    imageLabelWest[22] = ui->label_99;
    imageLabelWest[23] = ui->label_100;
    imageLabelWest[24] = ui->label_101;
    imageLabelWest[25] = ui->label_102;
    imageLabelWest[26] = ui->label_103;
    imageLabelWest[27] = ui->label_104;
    imageLabelWest[28] = ui->label_105;
    imageLabelWest[29] = ui->label_106;
    imageLabelWest[30] = ui->label_107;
    imageLabelWest[31] = ui->label_108;
    imageLabelWest[32] = ui->label_109;
    imageLabelWest[33] = ui->label_110;
    imageLabelWest[34] = ui->label_111;
    imageLabelWest[35] = ui->label_112;
    imageLabelWest[36] = ui->label_113;
    imageLabelWest[37] = ui->label_114;

    i=0;
    txtLabelWest[i++] = ui->label_115;
    txtLabelWest[i++] = ui->label_116;
    txtLabelWest[i++] = ui->label_117;
    txtLabelWest[i++] = ui->label_118;
    txtLabelWest[i++] = ui->label_119;
    txtLabelWest[i++] = ui->label_120;
    txtLabelWest[i++] = ui->label_121;
    txtLabelWest[i++] = ui->label_122;
    txtLabelWest[i++] = ui->label_123;
    txtLabelWest[i++] = ui->label_124;
    txtLabelWest[i++] = ui->label_125;
    txtLabelWest[i++] = ui->label_126;
    txtLabelWest[i++] = ui->label_127;
    txtLabelWest[i++] = ui->label_128;
    txtLabelWest[i++] = ui->label_129;
    txtLabelWest[i++] = ui->label_130;
    txtLabelWest[i++] = ui->label_131;
    txtLabelWest[i++] = ui->label_132;
    txtLabelWest[i++] = ui->label_133;
    txtLabelWest[i++] = ui->label_134;
    txtLabelWest[i++] = ui->label_135;
    txtLabelWest[i++] = ui->label_136;
    txtLabelWest[i++] = ui->label_137;
    txtLabelWest[i++] = ui->label_138;
    txtLabelWest[i++] = ui->label_139;
    txtLabelWest[i++] = ui->label_140;
    txtLabelWest[i++] = ui->label_141;
    txtLabelWest[i++] = ui->label_142;
    txtLabelWest[i++] = ui->label_143;
    txtLabelWest[i++] = ui->label_144;
    txtLabelWest[i++] = ui->label_145;
    txtLabelWest[i++] = ui->label_146;
    txtLabelWest[i++] = ui->label_147;
    txtLabelWest[i++] = ui->label_148;
    txtLabelWest[i++] = ui->label_149;
    txtLabelWest[i++] = ui->label_150;
    txtLabelWest[i++] = ui->label_151;
    txtLabelWest[i++] = ui->label_152;

    //north
    imageLabelNorth[0] = ui->label_153;
    imageLabelNorth[1] = ui->label_154;
    imageLabelNorth[2] = ui->label_155;
    imageLabelNorth[3] = ui->label_156;
    imageLabelNorth[4] = ui->label_157;
    imageLabelNorth[5] = ui->label_158;
    imageLabelNorth[6] = ui->label_159;
    imageLabelNorth[7] = ui->label_160;
    imageLabelNorth[8] = ui->label_161;
    imageLabelNorth[9] = ui->label_162;
    imageLabelNorth[10] = ui->label_163;
    imageLabelNorth[11] = ui->label_164;
    imageLabelNorth[12] = ui->label_165;
    imageLabelNorth[13] = ui->label_166;
    imageLabelNorth[14] = ui->label_167;
    imageLabelNorth[15] = ui->label_168;
    imageLabelNorth[16] = ui->label_169;
    imageLabelNorth[17] = ui->label_170;
    imageLabelNorth[18] = ui->label_171;

    imageLabelNorth[19] = ui->label_172;
    imageLabelNorth[20] = ui->label_173;
    imageLabelNorth[21] = ui->label_174;
    imageLabelNorth[22] = ui->label_175;
    imageLabelNorth[23] = ui->label_176;
    imageLabelNorth[24] = ui->label_177;
    imageLabelNorth[25] = ui->label_178;
    imageLabelNorth[26] = ui->label_179;
    imageLabelNorth[27] = ui->label_180;
    imageLabelNorth[28] = ui->label_181;
    imageLabelNorth[29] = ui->label_182;
    imageLabelNorth[30] = ui->label_183;
    imageLabelNorth[31] = ui->label_184;
    imageLabelNorth[32] = ui->label_185;
    imageLabelNorth[33] = ui->label_186;
    imageLabelNorth[34] = ui->label_187;
    imageLabelNorth[35] = ui->label_188;
    imageLabelNorth[36] = ui->label_189;
    imageLabelNorth[37] = ui->label_190;

    i=0;
    txtLabelNorth[i++] = ui->label_191;
    txtLabelNorth[i++] = ui->label_192;
    txtLabelNorth[i++] = ui->label_193;
    txtLabelNorth[i++] = ui->label_194;
    txtLabelNorth[i++] = ui->label_195;
    txtLabelNorth[i++] = ui->label_196;
    txtLabelNorth[i++] = ui->label_197;
    txtLabelNorth[i++] = ui->label_198;
    txtLabelNorth[i++] = ui->label_199;
    txtLabelNorth[i++] = ui->label_200;
    txtLabelNorth[i++] = ui->label_201;
    txtLabelNorth[i++] = ui->label_202;
    txtLabelNorth[i++] = ui->label_203;
    txtLabelNorth[i++] = ui->label_204;
    txtLabelNorth[i++] = ui->label_205;
    txtLabelNorth[i++] = ui->label_206;
    txtLabelNorth[i++] = ui->label_207;
    txtLabelNorth[i++] = ui->label_208;
    txtLabelNorth[i++] = ui->label_209;
    txtLabelNorth[i++] = ui->label_210;
    txtLabelNorth[i++] = ui->label_211;
    txtLabelNorth[i++] = ui->label_212;
    txtLabelNorth[i++] = ui->label_213;
    txtLabelNorth[i++] = ui->label_214;
    txtLabelNorth[i++] = ui->label_215;
    txtLabelNorth[i++] = ui->label_216;
    txtLabelNorth[i++] = ui->label_217;
    txtLabelNorth[i++] = ui->label_218;
    txtLabelNorth[i++] = ui->label_219;
    txtLabelNorth[i++] = ui->label_220;
    txtLabelNorth[i++] = ui->label_221;
    txtLabelNorth[i++] = ui->label_222;
    txtLabelNorth[i++] = ui->label_223;
    txtLabelNorth[i++] = ui->label_224;
    txtLabelNorth[i++] = ui->label_225;
    txtLabelNorth[i++] = ui->label_226;
    txtLabelNorth[i++] = ui->label_227;
    txtLabelNorth[i++] = ui->label_228;
    //South
    imageLabelSouth[0] = ui->label_229;
    imageLabelSouth[1] = ui->label_230;
    imageLabelSouth[2] = ui->label_231;
    imageLabelSouth[3] = ui->label_232;
    imageLabelSouth[4] = ui->label_233;
    imageLabelSouth[5] = ui->label_234;
    imageLabelSouth[6] = ui->label_235;
    imageLabelSouth[7] = ui->label_236;
    imageLabelSouth[8] = ui->label_237;
    imageLabelSouth[9] = ui->label_238;
    imageLabelSouth[10] = ui->label_239;
    imageLabelSouth[11] = ui->label_240;
    imageLabelSouth[12] = ui->label_241;
    imageLabelSouth[13] = ui->label_242;
    imageLabelSouth[14] = ui->label_243;
    imageLabelSouth[15] = ui->label_244;
    imageLabelSouth[16] = ui->label_245;
    imageLabelSouth[17] = ui->label_246;
    imageLabelSouth[18] = ui->label_247;

    imageLabelSouth[19] = ui->label_248;
    imageLabelSouth[20] = ui->label_249;
    imageLabelSouth[21] = ui->label_250;
    imageLabelSouth[22] = ui->label_251;
    imageLabelSouth[23] = ui->label_252;
    imageLabelSouth[24] = ui->label_253;
    imageLabelSouth[25] = ui->label_254;
    imageLabelSouth[26] = ui->label_255;
    imageLabelSouth[27] = ui->label_256;
    imageLabelSouth[28] = ui->label_257;
    imageLabelSouth[29] = ui->label_258;
    imageLabelSouth[30] = ui->label_259;
    imageLabelSouth[31] = ui->label_260;
    imageLabelSouth[32] = ui->label_261;
    imageLabelSouth[33] = ui->label_262;
    imageLabelSouth[34] = ui->label_263;
    imageLabelSouth[35] = ui->label_264;
    imageLabelSouth[36] = ui->label_265;
    imageLabelSouth[37] = ui->label_266;

    i=0;
    txtLabelSouth[i++] = ui->label_267;
    txtLabelSouth[i++] = ui->label_268;
    txtLabelSouth[i++] = ui->label_269;
    txtLabelSouth[i++] = ui->label_270;
    txtLabelSouth[i++] = ui->label_271;
    txtLabelSouth[i++] = ui->label_272;
    txtLabelSouth[i++] = ui->label_273;
    txtLabelSouth[i++] = ui->label_274;
    txtLabelSouth[i++] = ui->label_275;
    txtLabelSouth[i++] = ui->label_276;
    txtLabelSouth[i++] = ui->label_277;
    txtLabelSouth[i++] = ui->label_278;
    txtLabelSouth[i++] = ui->label_279;
    txtLabelSouth[i++] = ui->label_280;
    txtLabelSouth[i++] = ui->label_281;
    txtLabelSouth[i++] = ui->label_282;
    txtLabelSouth[i++] = ui->label_283;
    txtLabelSouth[i++] = ui->label_284;
    txtLabelSouth[i++] = ui->label_285;
    txtLabelSouth[i++] = ui->label_286;
    txtLabelSouth[i++] = ui->label_287;
    txtLabelSouth[i++] = ui->label_288;
    txtLabelSouth[i++] = ui->label_289;
    txtLabelSouth[i++] = ui->label_290;
    txtLabelSouth[i++] = ui->label_291;
    txtLabelSouth[i++] = ui->label_292;
    txtLabelSouth[i++] = ui->label_293;
    txtLabelSouth[i++] = ui->label_294;
    txtLabelSouth[i++] = ui->label_295;
    txtLabelSouth[i++] = ui->label_296;
    txtLabelSouth[i++] = ui->label_297;
    txtLabelSouth[i++] = ui->label_298;
    txtLabelSouth[i++] = ui->label_299;
    txtLabelSouth[i++] = ui->label_300;
    txtLabelSouth[i++] = ui->label_301;
    txtLabelSouth[i++] = ui->label_302;
    txtLabelSouth[i++] = ui->label_303;
    txtLabelSouth[i++] = ui->label_304;
    for(int i=0;i<38;i++)
    {
        connect(imageLabelEast[i],SIGNAL(sendImage(Mat)),this,SLOT(recvImage152(Mat)));
        connect(imageLabelWest[i],SIGNAL(sendImage(Mat)),this,SLOT(recvImage152(Mat)));
        connect(imageLabelNorth[i],SIGNAL(sendImage(Mat)),this,SLOT(recvImage152(Mat)));
        connect(imageLabelSouth[i],SIGNAL(sendImage(Mat)),this,SLOT(recvImage152(Mat)));
    }
}

DialogMJ152::~DialogMJ152()
{
    delete ui;
}

void DialogMJ152::showImageMj()
{
    printf("imgE size:%d\n",(int)imgE.size());
    printf("imgW size:%d\n",(int)imgW.size());
    printf("imgN size:%d\n",(int)imgN.size());
    printf("imgS size:%d\n",(int)imgS.size());
    fflush(NULL);
    //East West North South
    QImage img;
    int count = 0;
    for(int i=0;i<(int)imgE.size();i++)
    {
        Mat src = imgE[i].clone();
        cvtColor(src,src,CV_BGR2RGB);
        img = QImage(src.data,src.cols,src.rows,src.cols*3,QImage::Format_RGB888);
        if(i%2==0)
        {
            imageLabelEast[count]->setPixmap(QPixmap::fromImage(img));
            txtLabelEast[count]->setText(labelE[i]);
            imageLabelEast[count]->image = imgE[i].clone();
            count++;
        }
        else
        {
            imageLabelEast[count+18]->setPixmap(QPixmap::fromImage(img));
            txtLabelEast[count+18]->setText(labelE[i]);
            imageLabelEast[count+18]->image = imgE[i].clone();
        }
    }
    count = 0;
    for(int i=0;i<(int)imgW.size();i++)
    {
        Mat src = imgW[i].clone();
        cvtColor(src,src,CV_BGR2RGB);
        img = QImage(src.data,src.cols,src.rows,src.cols*3,QImage::Format_RGB888);
        if(i%2==0)
        {
            imageLabelWest[count]->setPixmap(QPixmap::fromImage(img));
            txtLabelWest[count]->setText(labelW[i]);
            imageLabelWest[count]->image = imgW[i].clone();
            count++;
        }
        else
        {
            imageLabelWest[count+18]->setPixmap(QPixmap::fromImage(img));
            txtLabelWest[count+18]->setText(labelW[i]);
            imageLabelWest[count+18]->image = imgW[i].clone();
        }
    }
    count = 0;
    for(int i=0;i<(int)imgN.size();i++)
    {
        Mat src = imgN[i].clone();
        cvtColor(src,src,CV_BGR2RGB);
        img = QImage(src.data,src.cols,src.rows,src.cols*3,QImage::Format_RGB888);
        if(i%2==0)
        {
            imageLabelNorth[count]->setPixmap(QPixmap::fromImage(img));
            txtLabelNorth[count]->setText(labelN[i]);
            imageLabelNorth[count]->image = imgN[i].clone();
            count++;
        }
        else
        {
            imageLabelNorth[count+18]->setPixmap(QPixmap::fromImage(img));
            txtLabelNorth[count+18]->setText(labelN[i]);
            imageLabelNorth[count+18]->image = imgN[i].clone();
        }
    }
    count = 0;
    for(int i=0;i<(int)imgS.size();i++)
    {
        Mat src = imgS[i].clone();
        cvtColor(src,src,CV_BGR2RGB);
        img = QImage(src.data,src.cols,src.rows,src.cols*3,QImage::Format_RGB888);
        if(i%2==0)
        {
            imageLabelSouth[count]->setPixmap(QPixmap::fromImage(img));
            txtLabelSouth[count]->setText(labelS[i]);
            imageLabelSouth[count]->image = imgS[i].clone();
            count++;
        }
        else
        {
            imageLabelSouth[count+18]->setPixmap(QPixmap::fromImage(img));
            txtLabelSouth[count+18]->setText(labelS[i]);
            imageLabelSouth[count+18]->image = imgS[i].clone();
        }
    }
}

void DialogMJ152::mouseMoveEvent(QMouseEvent *e)
{
    ui->label_Mouse->setText(QString::asprintf("[%d,%d]",e->x(),e->y()));
}

void DialogMJ152::recvImage152(Mat mat)
{
    Mat src = mat.clone();
    currentImage=mat.clone();
    cvtColor(src,src,CV_BGR2RGB);
    cv::resize(src,src,cv::Size(40,60));
    QImage img = QImage(src.data,src.cols,src.rows,src.cols*3,QImage::Format_RGB888);
    ui->label_error->setPixmap(QPixmap::fromImage(img));
    ui->pushButton->setEnabled(true);
}

void DialogMJ152::on_pushButton_clicked()
{
    int index = ui->comboBox_Num->currentIndex();
    QString name = ui->comboBox_Zi->currentText();
    QString imgName="";
    QFile file;
    if(name == "wan" || name == "bing" || name == "tiao")
    {
        imgName = name+"/"+QString::asprintf("%d/",index);
        for(int i=0;i<999;i++)
        {
            QString str;
            str.sprintf("%d.png",i);
            str = imgName+str;
            file.setFileName(str);
            if(!file.exists())
            {
                imwrite(str.toLatin1().data(),currentImage);
                break;
            }
        }
    }
    else if(name=="dong"||name == "nan" || name == "xi" || name == "bei"||name == "zhong" || name == "fa" || name == "baiban")
    {
        imgName = "zi/"+name;
        for(int i=0;i<999;i++)
        {
            QString str;
            str.sprintf("/%d.png",i);
            str = imgName+str;
            file.setFileName(str);
            if(!file.exists())
            {
                imwrite(str.toLatin1().data(),currentImage);
                break;
            }
        }
    }
    else if(name=="Mei"||name == "Lan" || name == "Zhu" || name == "Ju"||name == "Spring" || name == "Summer" || name == "Autumn" || name == "Winter" || name == "Mouse" || name == "CaiShen" || name == "Cat" || name == "JuBaoPen" || name == "BaiDa" || name == "Kong")
    {
        imgName = "hua/"+name;
        for(int i=0;i<999;i++)
        {
            QString str;
            str.sprintf("/%d.png",i);
            str = imgName+str;
            file.setFileName(str);
            if(!file.exists())
            {
                imwrite(str.toLatin1().data(),currentImage);
                break;
            }
        }
    }
    else
    {
        QMessageBox::about(NULL,"err","select err");
    }
    ui->pushButton->setEnabled(false);
}
