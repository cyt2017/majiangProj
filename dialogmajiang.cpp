#include "dialogmajiang.h"
#include "ui_dialogmajiang.h"

DialogMaJiang::DialogMaJiang(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogMaJiang)
{
    ui->setupUi(this);
    setMouseTracking(true);
    ui->pushButton->setEnabled(false);
    setWindowTitle(QString::fromLocal8Bit("识别结果"));
//east
    imageLabel[0] = ui->label_east_1;
    imageLabel[1] = ui->label_east_2;
    imageLabel[2] = ui->label_east_3;
    imageLabel[3] = ui->label_east_4;
    imageLabel[4] = ui->label_east_5;
    imageLabel[5] = ui->label_east_6;
    imageLabel[6] = ui->label_east_7;
    imageLabel[7] = ui->label_east_8;
    imageLabel[8] = ui->label_east_9;
    imageLabel[9] = ui->label_east_10;
    imageLabel[10] = ui->label_east_11;
    imageLabel[11] = ui->label_east_12;
    imageLabel[12] = ui->label_east_13;
    imageLabel[13] = ui->label_east_14;
    imageLabel[14] = ui->label_east_15;
    imageLabel[15] = ui->label_east_16;
    imageLabel[16] = ui->label_east_17;

    imageLabel[17] = ui->label_east_35;
    imageLabel[18] = ui->label_east_36;
    imageLabel[19] = ui->label_east_37;
    imageLabel[20] = ui->label_east_38;
    imageLabel[21] = ui->label_east_39;
    imageLabel[22] = ui->label_east_40;
    imageLabel[23] = ui->label_east_41;
    imageLabel[24] = ui->label_east_42;
    imageLabel[25] = ui->label_east_43;
    imageLabel[26] = ui->label_east_44;
    imageLabel[27] = ui->label_east_45;
    imageLabel[28] = ui->label_east_46;
    imageLabel[29] = ui->label_east_47;
    imageLabel[30] = ui->label_east_48;
    imageLabel[31] = ui->label_east_49;
    imageLabel[32] = ui->label_east_50;
    imageLabel[33] = ui->label_east_51;

    //west
    imageLabel[34] = ui->label_east_69;
    imageLabel[35] = ui->label_east_70;
    imageLabel[36] = ui->label_east_71;
    imageLabel[37] = ui->label_east_72;
    imageLabel[38] = ui->label_east_73;
    imageLabel[39] = ui->label_east_74;
    imageLabel[40] = ui->label_east_75;
    imageLabel[41] = ui->label_east_76;
    imageLabel[42] = ui->label_east_77;
    imageLabel[43] = ui->label_east_78;
    imageLabel[44] = ui->label_east_79;
    imageLabel[45] = ui->label_east_80;
    imageLabel[46] = ui->label_east_81;
    imageLabel[47] = ui->label_east_82;
    imageLabel[48] = ui->label_east_83;
    imageLabel[49] = ui->label_east_84;
    imageLabel[50] = ui->label_east_85;

    imageLabel[51] = ui->label_east_103;
    imageLabel[52] = ui->label_east_104;
    imageLabel[53] = ui->label_east_105;
    imageLabel[54] = ui->label_east_106;
    imageLabel[55] = ui->label_east_107;
    imageLabel[56] = ui->label_east_108;
    imageLabel[57] = ui->label_east_109;
    imageLabel[58] = ui->label_east_110;
    imageLabel[59] = ui->label_east_111;
    imageLabel[60] = ui->label_east_112;
    imageLabel[61] = ui->label_east_113;
    imageLabel[62] = ui->label_east_114;
    imageLabel[63] = ui->label_east_115;
    imageLabel[64] = ui->label_east_116;
    imageLabel[65] = ui->label_east_117;
    imageLabel[66] = ui->label_east_118;
    imageLabel[67] = ui->label_east_119;

    //north
    imageLabel[68] = ui->label_east_137;
    imageLabel[69] = ui->label_east_138;
    imageLabel[70] = ui->label_east_139;
    imageLabel[71] = ui->label_east_140;
    imageLabel[72] = ui->label_east_141;
    imageLabel[73] = ui->label_east_142;
    imageLabel[74] = ui->label_east_143;
    imageLabel[75] = ui->label_east_144;
    imageLabel[76] = ui->label_east_145;
    imageLabel[77] = ui->label_east_146;
    imageLabel[78] = ui->label_east_147;
    imageLabel[79] = ui->label_east_148;
    imageLabel[80] = ui->label_east_149;
    imageLabel[81] = ui->label_east_150;
    imageLabel[82] = ui->label_east_151;
    imageLabel[83] = ui->label_east_152;
    imageLabel[84] = ui->label_east_153;

    imageLabel[85] = ui->label_east_171;
    imageLabel[86] = ui->label_east_172;
    imageLabel[87] = ui->label_east_173;
    imageLabel[88] = ui->label_east_174;
    imageLabel[89] = ui->label_east_175;
    imageLabel[90] = ui->label_east_176;
    imageLabel[91] = ui->label_east_177;
    imageLabel[92] = ui->label_east_178;
    imageLabel[93] = ui->label_east_179;
    imageLabel[94] = ui->label_east_180;
    imageLabel[95] = ui->label_east_181;
    imageLabel[96] = ui->label_east_182;
    imageLabel[97] = ui->label_east_183;
    imageLabel[98] = ui->label_east_184;
    imageLabel[99] = ui->label_east_185;
    imageLabel[100] = ui->label_east_186;
    imageLabel[101] = ui->label_east_187;

    //South
    imageLabel[102] = ui->label_east_205;
    imageLabel[103] = ui->label_east_206;
    imageLabel[104] = ui->label_east_207;
    imageLabel[105] = ui->label_east_208;
    imageLabel[106] = ui->label_east_209;
    imageLabel[107] = ui->label_east_210;
    imageLabel[108] = ui->label_east_211;
    imageLabel[109] = ui->label_east_212;
    imageLabel[110] = ui->label_east_213;
    imageLabel[111] = ui->label_east_214;
    imageLabel[112] = ui->label_east_215;
    imageLabel[113] = ui->label_east_216;
    imageLabel[114] = ui->label_east_217;
    imageLabel[115] = ui->label_east_218;
    imageLabel[116] = ui->label_east_219;
    imageLabel[117] = ui->label_east_220;
    imageLabel[118] = ui->label_east_221;

    imageLabel[119] = ui->label_east_239;
    imageLabel[120] = ui->label_east_240;
    imageLabel[121] = ui->label_east_241;
    imageLabel[122] = ui->label_east_242;
    imageLabel[123] = ui->label_east_243;
    imageLabel[124] = ui->label_east_244;
    imageLabel[125] = ui->label_east_245;
    imageLabel[126] = ui->label_east_246;
    imageLabel[127] = ui->label_east_247;
    imageLabel[128] = ui->label_east_248;
    imageLabel[129] = ui->label_east_249;
    imageLabel[130] = ui->label_east_250;
    imageLabel[131] = ui->label_east_251;
    imageLabel[132] = ui->label_east_252;
    imageLabel[133] = ui->label_east_253;
    imageLabel[134] = ui->label_east_254;
    imageLabel[135] = ui->label_east_255;

    for(int i=0;i<135;i++)
    {
        connect(imageLabel[i],SIGNAL(sendImage(Mat)),this,SLOT(recvImage(Mat)));
    }

}

DialogMaJiang::~DialogMaJiang()
{
    delete ui;
}



#define label(i) ui->label_east_##i
void DialogMaJiang::showImageMj()
{
    printf("imgE size:%d\n",(int)imgE.size());
    printf("imgW size:%d\n",(int)imgW.size());
    printf("imgN size:%d\n",(int)imgN.size());
    printf("imgS size:%d\n",(int)imgS.size());
    fflush(NULL);
    //East West North South
    QImage img;
    for(int i=0;i<(int)imgE.size();i++)
    {
        Mat src = imgE[i].clone();
        cvtColor(src,src,CV_BGR2RGB);
        img = QImage(src.data,src.cols,src.rows,src.cols*3,QImage::Format_RGB888);
//        label(这里我再查一下，不记得怎么写了)->setPixmap(QPixmap::fromImage(img));
        if(i==0){
            ui->label_east_1->setPixmap(QPixmap::fromImage(img));
            ui->label_east_1->image = imgE[i].clone();
            ui->label_east_18->setText(labelE[i]);
        }
        else if(i==2){
            ui->label_east_2->setPixmap(QPixmap::fromImage(img));
            ui->label_east_2->image = imgE[i].clone();
            ui->label_east_19->setText(labelE[i]);
        }
        else if(i==4){
            ui->label_east_3->setPixmap(QPixmap::fromImage(img));
            ui->label_east_3->image = imgE[i].clone();
            ui->label_east_20->setText(labelE[i]);
        }
        else if(i==6){
            ui->label_east_4->setPixmap(QPixmap::fromImage(img));
            ui->label_east_4->image = imgE[i].clone();
            ui->label_east_21->setText(labelE[i]);
        }
        else if(i==8){
            ui->label_east_5->setPixmap(QPixmap::fromImage(img));
            ui->label_east_5->image = imgE[i].clone();
            ui->label_east_22->setText(labelE[i]);
        }
        else if(i==10){
            ui->label_east_6->setPixmap(QPixmap::fromImage(img));
            ui->label_east_6->image = imgE[i].clone();
            ui->label_east_23->setText(labelE[i]);
        }
        else if(i==12){
            ui->label_east_7->setPixmap(QPixmap::fromImage(img));
            ui->label_east_7->image = imgE[i].clone();
            ui->label_east_24->setText(labelE[i]);
        }
        else if(i==14){
            ui->label_east_8->setPixmap(QPixmap::fromImage(img));
            ui->label_east_8->image = imgE[i].clone();
            ui->label_east_25->setText(labelE[i]);
        }
        else if(i==16){
            ui->label_east_9->setPixmap(QPixmap::fromImage(img));
            ui->label_east_9->image = imgE[i].clone();
            ui->label_east_26->setText(labelE[i]);
        }
        else if(i==18){
            ui->label_east_10->setPixmap(QPixmap::fromImage(img));
            ui->label_east_10->image = imgE[i].clone();
            ui->label_east_27->setText(labelE[i]);
        }
        else if(i==20){
            ui->label_east_11->setPixmap(QPixmap::fromImage(img));
            ui->label_east_11->image = imgE[i].clone();
            ui->label_east_28->setText(labelE[i]);
        }
        else if(i==22){
            ui->label_east_12->setPixmap(QPixmap::fromImage(img));
            ui->label_east_12->image = imgE[i].clone();
            ui->label_east_29->setText(labelE[i]);
        }
        else if(i==24){
            ui->label_east_13->setPixmap(QPixmap::fromImage(img));
            ui->label_east_13->image = imgE[i].clone();
            ui->label_east_30->setText(labelE[i]);
        }
        else if(i==26){
            ui->label_east_14->setPixmap(QPixmap::fromImage(img));
            ui->label_east_14->image = imgE[i].clone();
            ui->label_east_31->setText(labelE[i]);
        }
        else if(i==28){
            ui->label_east_15->setPixmap(QPixmap::fromImage(img));
            ui->label_east_15->image = imgE[i].clone();
            ui->label_east_32->setText(labelE[i]);
        }
        else if(i==30){
            ui->label_east_16->setPixmap(QPixmap::fromImage(img));
            ui->label_east_16->image = imgE[i].clone();
            ui->label_east_33->setText(labelE[i]);
        }
        else if(i==32){
            ui->label_east_17->setPixmap(QPixmap::fromImage(img));
            ui->label_east_17->image = imgE[i].clone();
            ui->label_east_34->setText(labelE[i]);
        }
        else if(i==1){
            ui->label_east_35->setPixmap(QPixmap::fromImage(img));
            ui->label_east_35->image = imgE[i].clone();
            ui->label_east_52->setText(labelE[i]);
        }
        else if(i==3){
            ui->label_east_36->setPixmap(QPixmap::fromImage(img));
            ui->label_east_36->image = imgE[i].clone();
            ui->label_east_53->setText(labelE[i]);
        }
        else if(i==5){
            ui->label_east_37->setPixmap(QPixmap::fromImage(img));
            ui->label_east_37->image = imgE[i].clone();
            ui->label_east_54->setText(labelE[i]);
        }
        else if(i==7){
            ui->label_east_38->setPixmap(QPixmap::fromImage(img));
            ui->label_east_38->image = imgE[i].clone();
            ui->label_east_55->setText(labelE[i]);
        }
        else if(i==9){
            ui->label_east_39->setPixmap(QPixmap::fromImage(img));
            ui->label_east_39->image = imgE[i].clone();
            ui->label_east_56->setText(labelE[i]);
        }
        else if(i==11){
            ui->label_east_40->setPixmap(QPixmap::fromImage(img));
            ui->label_east_40->image = imgE[i].clone();
            ui->label_east_57->setText(labelE[i]);
        }
        else if(i==13){
            ui->label_east_41->setPixmap(QPixmap::fromImage(img));
            ui->label_east_41->image = imgE[i].clone();
            ui->label_east_58->setText(labelE[i]);
        }
        else if(i==15){
            ui->label_east_42->setPixmap(QPixmap::fromImage(img));
            ui->label_east_42->image = imgE[i].clone();
            ui->label_east_59->setText(labelE[i]);
        }
        else if(i==17){
            ui->label_east_43->setPixmap(QPixmap::fromImage(img));
            ui->label_east_43->image = imgE[i].clone();
            ui->label_east_60->setText(labelE[i]);
        }
        else if(i==19){
            ui->label_east_44->setPixmap(QPixmap::fromImage(img));
            ui->label_east_44->image = imgE[i].clone();
            ui->label_east_61->setText(labelE[i]);
        }
        else if(i==21){
            ui->label_east_45->setPixmap(QPixmap::fromImage(img));
            ui->label_east_45->image = imgE[i].clone();
            ui->label_east_62->setText(labelE[i]);
        }
        else if(i==23){
            ui->label_east_46->setPixmap(QPixmap::fromImage(img));
            ui->label_east_46->image = imgE[i].clone();
            ui->label_east_63->setText(labelE[i]);
        }
        else if(i==25){
            ui->label_east_47->setPixmap(QPixmap::fromImage(img));
            ui->label_east_47->image = imgE[i].clone();
            ui->label_east_64->setText(labelE[i]);
        }
        else if(i==27){
            ui->label_east_48->setPixmap(QPixmap::fromImage(img));
            ui->label_east_48->image = imgE[i].clone();
            ui->label_east_65->setText(labelE[i]);
        }
        else if(i==29){
            ui->label_east_49->setPixmap(QPixmap::fromImage(img));
            ui->label_east_49->image = imgE[i].clone();
            ui->label_east_66->setText(labelE[i]);
        }
        else if(i==31){
            ui->label_east_50->setPixmap(QPixmap::fromImage(img));
            ui->label_east_50->image = imgE[i].clone();
            ui->label_east_67->setText(labelE[i]);
        }
        else if(i==33){
            ui->label_east_51->setPixmap(QPixmap::fromImage(img));
            ui->label_east_51->image = imgE[i].clone();
            ui->label_east_68->setText(labelE[i]);
        }
    }
    for(int i=0;i<(int)imgW.size();i++)
    {
        Mat src = imgW[i].clone();
        cvtColor(src,src,CV_BGR2RGB);
        img = QImage(src.data,src.cols,src.rows,src.cols*3,QImage::Format_RGB888);
//        label(这里我再查一下，不记得怎么写了)->setPixmap(QPixmap::fromImage(img));
        if(i==0){
            ui->label_east_69->setPixmap(QPixmap::fromImage(img));
            ui->label_east_69->image=imgW[i].clone();
            ui->label_east_86->setText(labelW[i]);
        }
        else if(i==2){
            ui->label_east_70->setPixmap(QPixmap::fromImage(img));
            ui->label_east_70->image=imgW[i].clone();
            ui->label_east_87->setText(labelW[i]);
        }
        else if(i==4){
            ui->label_east_71->setPixmap(QPixmap::fromImage(img));
            ui->label_east_71->image=imgW[i].clone();
            ui->label_east_88->setText(labelW[i]);
        }
        else if(i==6){
            ui->label_east_72->setPixmap(QPixmap::fromImage(img));
            ui->label_east_72->image=imgW[i].clone();
            ui->label_east_89->setText(labelW[i]);
        }
        else if(i==8){
            ui->label_east_73->setPixmap(QPixmap::fromImage(img));
            ui->label_east_73->image=imgW[i].clone();
            ui->label_east_90->setText(labelW[i]);
        }
        else if(i==10){
            ui->label_east_74->setPixmap(QPixmap::fromImage(img));
            ui->label_east_74->image=imgW[i].clone();
            ui->label_east_91->setText(labelW[i]);
        }
        else if(i==12){
            ui->label_east_75->setPixmap(QPixmap::fromImage(img));
            ui->label_east_75->image=imgW[i].clone();
            ui->label_east_92->setText(labelW[i]);
        }
        else if(i==14){
            ui->label_east_76->setPixmap(QPixmap::fromImage(img));
            ui->label_east_76->image=imgW[i].clone();
            ui->label_east_93->setText(labelW[i]);
        }
        else if(i==16){
            ui->label_east_77->setPixmap(QPixmap::fromImage(img));
            ui->label_east_77->image=imgW[i].clone();
            ui->label_east_94->setText(labelW[i]);
        }
        else if(i==18){
            ui->label_east_78->setPixmap(QPixmap::fromImage(img));
            ui->label_east_78->image=imgW[i].clone();
            ui->label_east_95->setText(labelW[i]);
        }
        else if(i==20){
            ui->label_east_79->setPixmap(QPixmap::fromImage(img));
            ui->label_east_79->image=imgW[i].clone();
            ui->label_east_96->setText(labelW[i]);
        }
        else if(i==22){
            ui->label_east_80->setPixmap(QPixmap::fromImage(img));
            ui->label_east_80->image=imgW[i].clone();
            ui->label_east_97->setText(labelW[i]);
        }
        else if(i==24){
            ui->label_east_81->setPixmap(QPixmap::fromImage(img));
            ui->label_east_81->image=imgW[i].clone();
            ui->label_east_98->setText(labelW[i]);
        }
        else if(i==26){
            ui->label_east_82->setPixmap(QPixmap::fromImage(img));
            ui->label_east_82->image=imgW[i].clone();
            ui->label_east_99->setText(labelW[i]);
        }
        else if(i==28){
            ui->label_east_83->setPixmap(QPixmap::fromImage(img));
            ui->label_east_83->image=imgW[i].clone();
            ui->label_east_100->setText(labelW[i]);
        }
        else if(i==30){
            ui->label_east_84->setPixmap(QPixmap::fromImage(img));
            ui->label_east_84->image=imgW[i].clone();
            ui->label_east_101->setText(labelW[i]);
        }
        else if(i==32){
            ui->label_east_85->setPixmap(QPixmap::fromImage(img));
            ui->label_east_85->image=imgW[i].clone();
            ui->label_east_102->setText(labelW[i]);
        }
        else if(i==1){
            ui->label_east_103->setPixmap(QPixmap::fromImage(img));
            ui->label_east_103->image=imgW[i].clone();
            ui->label_east_120->setText(labelW[i]);
        }
        else if(i==3){
            ui->label_east_104->setPixmap(QPixmap::fromImage(img));
            ui->label_east_104->image=imgW[i].clone();
            ui->label_east_121->setText(labelW[i]);
        }
        else if(i==5){
            ui->label_east_105->setPixmap(QPixmap::fromImage(img));
            ui->label_east_105->image=imgW[i].clone();
            ui->label_east_122->setText(labelW[i]);
        }
        else if(i==7){
            ui->label_east_106->setPixmap(QPixmap::fromImage(img));
            ui->label_east_106->image=imgW[i].clone();
            ui->label_east_123->setText(labelW[i]);
        }
        else if(i==9){
            ui->label_east_107->setPixmap(QPixmap::fromImage(img));
            ui->label_east_107->image=imgW[i].clone();
            ui->label_east_124->setText(labelW[i]);
        }
        else if(i==11){
            ui->label_east_108->setPixmap(QPixmap::fromImage(img));
            ui->label_east_108->image=imgW[i].clone();
            ui->label_east_125->setText(labelW[i]);
        }
        else if(i==13){
            ui->label_east_109->setPixmap(QPixmap::fromImage(img));
            ui->label_east_109->image=imgW[i].clone();
            ui->label_east_126->setText(labelW[i]);
        }
        else if(i==15){
            ui->label_east_110->setPixmap(QPixmap::fromImage(img));
            ui->label_east_110->image=imgW[i].clone();
            ui->label_east_127->setText(labelW[i]);
        }
        else if(i==17){
            ui->label_east_111->setPixmap(QPixmap::fromImage(img));
            ui->label_east_111->image=imgW[i].clone();
            ui->label_east_128->setText(labelW[i]);
        }
        else if(i==19){
            ui->label_east_112->setPixmap(QPixmap::fromImage(img));
            ui->label_east_112->image=imgW[i].clone();
            ui->label_east_129->setText(labelW[i]);
        }
        else if(i==21){
            ui->label_east_113->setPixmap(QPixmap::fromImage(img));
            ui->label_east_113->image=imgW[i].clone();
            ui->label_east_130->setText(labelW[i]);
        }
        else if(i==23){
            ui->label_east_114->setPixmap(QPixmap::fromImage(img));
            ui->label_east_114->image=imgW[i].clone();
            ui->label_east_131->setText(labelW[i]);
        }
        else if(i==25){
            ui->label_east_115->setPixmap(QPixmap::fromImage(img));
            ui->label_east_115->image=imgW[i].clone();
            ui->label_east_132->setText(labelW[i]);
        }
        else if(i==27){
            ui->label_east_116->setPixmap(QPixmap::fromImage(img));
            ui->label_east_116->image=imgW[i].clone();
            ui->label_east_133->setText(labelW[i]);
        }
        else if(i==29){
            ui->label_east_117->setPixmap(QPixmap::fromImage(img));
            ui->label_east_117->image=imgW[i].clone();
            ui->label_east_134->setText(labelW[i]);
        }
        else if(i==31){
            ui->label_east_118->setPixmap(QPixmap::fromImage(img));
            ui->label_east_118->image=imgW[i].clone();
            ui->label_east_135->setText(labelW[i]);
        }
        else if(i==33){
            ui->label_east_119->setPixmap(QPixmap::fromImage(img));
            ui->label_east_119->image=imgW[i].clone();
            ui->label_east_136->setText(labelW[i]);
        }
    }
    for(int i=0;i<(int)imgN.size();i++)
    {
        Mat src = imgN[i].clone();
        cvtColor(src,src,CV_BGR2RGB);
        img = QImage(src.data,src.cols,src.rows,src.cols*3,QImage::Format_RGB888);
//        label(这里我再查一下，不记得怎么写了)->setPixmap(QPixmap::fromImage(img));
        if(i==0){
            ui->label_east_137->setPixmap(QPixmap::fromImage(img));
            ui->label_east_137->image=imgN[i].clone();
            ui->label_east_154->setText(labelN[i]);
        }
        else if(i==2){
            ui->label_east_138->setPixmap(QPixmap::fromImage(img));
            ui->label_east_138->image=imgN[i].clone();
            ui->label_east_155->setText(labelN[i]);
        }
        else if(i==4){
            ui->label_east_139->setPixmap(QPixmap::fromImage(img));
            ui->label_east_139->image=imgN[i].clone();
            ui->label_east_156->setText(labelN[i]);
        }
        else if(i==6){
            ui->label_east_140->setPixmap(QPixmap::fromImage(img));
            ui->label_east_140->image=imgN[i].clone();
            ui->label_east_157->setText(labelN[i]);
        }
        else if(i==8){
            ui->label_east_141->setPixmap(QPixmap::fromImage(img));
            ui->label_east_141->image=imgN[i].clone();
            ui->label_east_158->setText(labelN[i]);
        }
        else if(i==10){
            ui->label_east_142->setPixmap(QPixmap::fromImage(img));
            ui->label_east_142->image=imgN[i].clone();
            ui->label_east_159->setText(labelN[i]);
        }
        else if(i==12){
            ui->label_east_143->setPixmap(QPixmap::fromImage(img));
            ui->label_east_143->image=imgN[i].clone();
            ui->label_east_160->setText(labelN[i]);
        }
        else if(i==14){
            ui->label_east_144->setPixmap(QPixmap::fromImage(img));
            ui->label_east_144->image=imgN[i].clone();
            ui->label_east_161->setText(labelN[i]);
        }
        else if(i==16){
            ui->label_east_145->setPixmap(QPixmap::fromImage(img));
            ui->label_east_145->image=imgN[i].clone();
            ui->label_east_162->setText(labelN[i]);
        }
        else if(i==18){
            ui->label_east_146->setPixmap(QPixmap::fromImage(img));
            ui->label_east_146->image=imgN[i].clone();
            ui->label_east_163->setText(labelN[i]);
        }
        else if(i==20){
            ui->label_east_147->setPixmap(QPixmap::fromImage(img));
            ui->label_east_147->image=imgN[i].clone();
            ui->label_east_164->setText(labelN[i]);
        }
        else if(i==22){
            ui->label_east_148->setPixmap(QPixmap::fromImage(img));
            ui->label_east_148->image=imgN[i].clone();
            ui->label_east_165->setText(labelN[i]);
        }
        else if(i==24){
            ui->label_east_149->setPixmap(QPixmap::fromImage(img));
            ui->label_east_149->image=imgN[i].clone();
            ui->label_east_166->setText(labelN[i]);
        }
        else if(i==26){
            ui->label_east_150->setPixmap(QPixmap::fromImage(img));
            ui->label_east_150->image=imgN[i].clone();
            ui->label_east_167->setText(labelN[i]);
        }
        else if(i==28){
            ui->label_east_151->setPixmap(QPixmap::fromImage(img));
            ui->label_east_151->image=imgN[i].clone();
            ui->label_east_168->setText(labelN[i]);
        }
        else if(i==30){
            ui->label_east_152->setPixmap(QPixmap::fromImage(img));
            ui->label_east_152->image=imgN[i].clone();
            ui->label_east_169->setText(labelN[i]);
        }
        else if(i==32){
            ui->label_east_153->setPixmap(QPixmap::fromImage(img));
            ui->label_east_153->image=imgN[i].clone();
            ui->label_east_170->setText(labelN[i]);
        }
        else if(i==1){
            ui->label_east_171->setPixmap(QPixmap::fromImage(img));
            ui->label_east_171->image=imgN[i].clone();
            ui->label_east_188->setText(labelN[i]);
        }
        else if(i==3){
            ui->label_east_172->setPixmap(QPixmap::fromImage(img));
            ui->label_east_172->image=imgN[i].clone();
            ui->label_east_189->setText(labelN[i]);
        }
        else if(i==5){
            ui->label_east_173->setPixmap(QPixmap::fromImage(img));
            ui->label_east_173->image=imgN[i].clone();
            ui->label_east_190->setText(labelN[i]);
        }
        else if(i==7){
            ui->label_east_174->setPixmap(QPixmap::fromImage(img));
            ui->label_east_174->image=imgN[i].clone();
            ui->label_east_191->setText(labelN[i]);
        }
        else if(i==9){
            ui->label_east_175->setPixmap(QPixmap::fromImage(img));
            ui->label_east_175->image=imgN[i].clone();
            ui->label_east_192->setText(labelN[i]);
        }
        else if(i==11){
            ui->label_east_176->setPixmap(QPixmap::fromImage(img));
            ui->label_east_176->image=imgN[i].clone();
            ui->label_east_193->setText(labelN[i]);
        }
        else if(i==13){
            ui->label_east_177->setPixmap(QPixmap::fromImage(img));
            ui->label_east_177->image=imgN[i].clone();
            ui->label_east_194->setText(labelN[i]);
        }
        else if(i==15){
            ui->label_east_178->setPixmap(QPixmap::fromImage(img));
            ui->label_east_178->image=imgN[i].clone();
            ui->label_east_195->setText(labelN[i]);
        }
        else if(i==17){
            ui->label_east_179->setPixmap(QPixmap::fromImage(img));
            ui->label_east_179->image=imgN[i].clone();
            ui->label_east_196->setText(labelN[i]);
        }
        else if(i==19){
            ui->label_east_180->setPixmap(QPixmap::fromImage(img));
            ui->label_east_180->image=imgN[i].clone();
            ui->label_east_197->setText(labelN[i]);
        }
        else if(i==21){
            ui->label_east_181->setPixmap(QPixmap::fromImage(img));
            ui->label_east_181->image=imgN[i].clone();
            ui->label_east_198->setText(labelN[i]);
        }
        else if(i==23){
            ui->label_east_182->setPixmap(QPixmap::fromImage(img));
            ui->label_east_182->image=imgN[i].clone();
            ui->label_east_199->setText(labelN[i]);
        }
        else if(i==25){
            ui->label_east_183->setPixmap(QPixmap::fromImage(img));
            ui->label_east_183->image=imgN[i].clone();
            ui->label_east_200->setText(labelN[i]);
        }
        else if(i==27){
            ui->label_east_184->setPixmap(QPixmap::fromImage(img));
            ui->label_east_184->image=imgN[i].clone();
            ui->label_east_201->setText(labelN[i]);
        }
        else if(i==29){
            ui->label_east_185->setPixmap(QPixmap::fromImage(img));
            ui->label_east_185->image=imgN[i].clone();
            ui->label_east_202->setText(labelN[i]);
        }
        else if(i==31){
            ui->label_east_186->setPixmap(QPixmap::fromImage(img));
            ui->label_east_186->image=imgN[i].clone();
            ui->label_east_203->setText(labelN[i]);
        }
        else if(i==33){
            ui->label_east_187->setPixmap(QPixmap::fromImage(img));
            ui->label_east_187->image=imgN[i].clone();
            ui->label_east_204->setText(labelN[i]);
        }
    }
    for(int i=0;i<(int)imgS.size();i++)
    {
        Mat src = imgS[i].clone();
        cvtColor(src,src,CV_BGR2RGB);
        img = QImage(src.data,src.cols,src.rows,src.cols*3,QImage::Format_RGB888);
//        label(这里我再查一下，不记得怎么写了)->setPixmap(QPixmap::fromImage(img));
        if(i==0){
            ui->label_east_205->setPixmap(QPixmap::fromImage(img));
            ui->label_east_205->image=imgS[i].clone();
            ui->label_east_222->setText(labelS[i]);
        }
        else if(i==2){
            ui->label_east_206->setPixmap(QPixmap::fromImage(img));
            ui->label_east_206->image=imgS[i].clone();
            ui->label_east_223->setText(labelS[i]);
        }
        else if(i==4){
            ui->label_east_207->setPixmap(QPixmap::fromImage(img));
            ui->label_east_207->image=imgS[i].clone();
            ui->label_east_224->setText(labelS[i]);
        }
        else if(i==6){
            ui->label_east_208->setPixmap(QPixmap::fromImage(img));
            ui->label_east_208->image=imgS[i].clone();
            ui->label_east_225->setText(labelS[i]);
        }
        else if(i==8){
            ui->label_east_209->setPixmap(QPixmap::fromImage(img));
            ui->label_east_209->image=imgS[i].clone();
            ui->label_east_226->setText(labelS[i]);
        }
        else if(i==10){
            ui->label_east_210->setPixmap(QPixmap::fromImage(img));
            ui->label_east_210->image=imgS[i].clone();
            ui->label_east_227->setText(labelS[i]);
        }
        else if(i==12){
            ui->label_east_211->setPixmap(QPixmap::fromImage(img));
            ui->label_east_211->image=imgS[i].clone();
            ui->label_east_228->setText(labelS[i]);
        }
        else if(i==14){
            ui->label_east_212->setPixmap(QPixmap::fromImage(img));
            ui->label_east_212->image=imgS[i].clone();
            ui->label_east_229->setText(labelS[i]);
        }
        else if(i==16){
            ui->label_east_213->setPixmap(QPixmap::fromImage(img));
            ui->label_east_213->image=imgS[i].clone();
            ui->label_east_230->setText(labelS[i]);
        }
        else if(i==18){
            ui->label_east_214->setPixmap(QPixmap::fromImage(img));
            ui->label_east_214->image=imgS[i].clone();
            ui->label_east_231->setText(labelS[i]);
        }
        else if(i==20){
            ui->label_east_215->setPixmap(QPixmap::fromImage(img));
            ui->label_east_215->image=imgS[i].clone();
            ui->label_east_232->setText(labelS[i]);
        }
        else if(i==22){
            ui->label_east_216->setPixmap(QPixmap::fromImage(img));
            ui->label_east_216->image=imgS[i].clone();
            ui->label_east_233->setText(labelS[i]);
        }
        else if(i==24){
            ui->label_east_217->setPixmap(QPixmap::fromImage(img));
            ui->label_east_217->image=imgS[i].clone();
            ui->label_east_234->setText(labelS[i]);
        }
        else if(i==26){
            ui->label_east_218->setPixmap(QPixmap::fromImage(img));
            ui->label_east_218->image=imgS[i].clone();
            ui->label_east_235->setText(labelS[i]);
        }
        else if(i==28){
            ui->label_east_219->setPixmap(QPixmap::fromImage(img));
            ui->label_east_219->image=imgS[i].clone();
            ui->label_east_236->setText(labelS[i]);
        }
        else if(i==30){
            ui->label_east_220->setPixmap(QPixmap::fromImage(img));
            ui->label_east_220->image=imgS[i].clone();
            ui->label_east_237->setText(labelS[i]);
        }
        else if(i==32){
            ui->label_east_221->setPixmap(QPixmap::fromImage(img));
            ui->label_east_221->image=imgS[i].clone();
            ui->label_east_238->setText(labelS[i]);
        }
        else if(i==1){
            ui->label_east_239->setPixmap(QPixmap::fromImage(img));
            ui->label_east_239->image=imgS[i].clone();
            ui->label_east_256->setText(labelS[i]);
        }
        else if(i==3){
            ui->label_east_240->setPixmap(QPixmap::fromImage(img));
            ui->label_east_240->image=imgS[i].clone();
            ui->label_east_257->setText(labelS[i]);
        }
        else if(i==5){
            ui->label_east_241->setPixmap(QPixmap::fromImage(img));
            ui->label_east_241->image=imgS[i].clone();
            ui->label_east_258->setText(labelS[i]);
        }
        else if(i==7){
            ui->label_east_242->setPixmap(QPixmap::fromImage(img));
            ui->label_east_242->image=imgS[i].clone();
            ui->label_east_259->setText(labelS[i]);
        }
        else if(i==9){
            ui->label_east_243->setPixmap(QPixmap::fromImage(img));
            ui->label_east_243->image=imgS[i].clone();
            ui->label_east_260->setText(labelS[i]);
        }
        else if(i==11){
            ui->label_east_244->setPixmap(QPixmap::fromImage(img));
            ui->label_east_244->image=imgS[i].clone();
            ui->label_east_261->setText(labelS[i]);
        }
        else if(i==13){
            ui->label_east_245->setPixmap(QPixmap::fromImage(img));
            ui->label_east_245->image=imgS[i].clone();
            ui->label_east_262->setText(labelS[i]);
        }
        else if(i==15){
            ui->label_east_246->setPixmap(QPixmap::fromImage(img));
            ui->label_east_246->image=imgS[i].clone();
            ui->label_east_263->setText(labelS[i]);
        }
        else if(i==17){
            ui->label_east_247->setPixmap(QPixmap::fromImage(img));
            ui->label_east_247->image=imgS[i].clone();
            ui->label_east_264->setText(labelS[i]);
        }
        else if(i==19){
            ui->label_east_248->setPixmap(QPixmap::fromImage(img));
            ui->label_east_248->image=imgS[i].clone();
            ui->label_east_265->setText(labelS[i]);
        }
        else if(i==21){
            ui->label_east_249->setPixmap(QPixmap::fromImage(img));
            ui->label_east_249->image=imgS[i].clone();
            ui->label_east_266->setText(labelS[i]);
        }
        else if(i==23){
            ui->label_east_250->setPixmap(QPixmap::fromImage(img));
            ui->label_east_250->image=imgS[i].clone();
            ui->label_east_267->setText(labelS[i]);
        }
        else if(i==25){
            ui->label_east_251->setPixmap(QPixmap::fromImage(img));
            ui->label_east_251->image=imgS[i].clone();
            ui->label_east_268->setText(labelS[i]);
        }
        else if(i==27){
            ui->label_east_252->setPixmap(QPixmap::fromImage(img));
            ui->label_east_252->image=imgS[i].clone();
            ui->label_east_269->setText(labelS[i]);
        }
        else if(i==29){
            ui->label_east_253->setPixmap(QPixmap::fromImage(img));
            ui->label_east_253->image=imgS[i].clone();
            ui->label_east_270->setText(labelS[i]);
        }
        else if(i==31){
            ui->label_east_254->setPixmap(QPixmap::fromImage(img));
            ui->label_east_254->image=imgS[i].clone();
            ui->label_east_271->setText(labelS[i]);
        }
        else if(i==33){
            ui->label_east_255->setPixmap(QPixmap::fromImage(img));
            ui->label_east_255->image=imgS[i].clone();
            ui->label_east_272->setText(labelS[i]);
        }
    }
}

void DialogMaJiang::mouseMoveEvent(QMouseEvent *e)
{
    ui->label_mouse->setText(QString::asprintf("[%d,%d]",e->x(),e->y()));
}

void DialogMaJiang::on_pushButton_clicked()
{
    int index = ui->comboBox_NUM->currentIndex();
    QString name = ui->comboBox_ZI->currentText();
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
    else
    {
        QMessageBox::about(NULL,"err","select err");
    }
    ui->pushButton->setEnabled(false);
}

void DialogMaJiang::recvImage(Mat mat)
{
    Mat src = mat.clone();
    currentImage=mat.clone();
    cvtColor(src,src,CV_BGR2RGB);
    cv::resize(src,src,cv::Size(40,60));
    QImage img = QImage(src.data,src.cols,src.rows,src.cols*3,QImage::Format_RGB888);
    ui->label->setPixmap(QPixmap::fromImage(img));
    ui->pushButton->setEnabled(true);
}

void DialogMaJiang::on_saveAllToSampleBtn_clicked()
{

}
