#-------------------------------------------------
#
# Project created by QtCreator 2016-05-24T22:05:19
#
#-------------------------------------------------

QT       += core gui\
         xml\
         widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mymainwindow
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        xml.cpp

HEADERS  += mainwindow.h \
    xml.h

FORMS    += mainwindow.ui

RESOURCES += \
    myimages.qrc
