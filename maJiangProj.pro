#-------------------------------------------------
#
# Project created by QtCreator 2017-10-02T16:05:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = maJiangProj
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    dialogmajiang.cpp \
    qmajiangrecbase.cpp \
    qcolorhist_pixratio_feature.cpp \
    qimagelabel.cpp \
    dialogmj152.cpp

HEADERS  += mainwindow.h \
    dialogmajiang.h \
    qmajiangrecbase.h \
    qcolorhist_pixratio_feature.h \
    qimagelabel.h \
    dialogmj152.h

FORMS    += mainwindow.ui \
    dialogmajiang.ui \
    dialogmj152.ui


LIBS += /home/cyt/myLibs/lib/libopencv*.so
INCLUDEPATH +=/home/cyt/myLibs/include
