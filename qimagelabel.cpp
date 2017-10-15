#include "qimagelabel.h"

QImageLabel::QImageLabel(QObject *parent) : QLabel((QWidget*)parent)
{

}

void QImageLabel::mousePressEvent(QMouseEvent *ev)
{
    emit sendImage(image);
}
