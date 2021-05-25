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
        config.cpp \
        mainwindow.cpp \
        xml.cpp

HEADERS  += mainwindow.h \
    config.h \
    log.h \
    xml.h

FORMS    += mainwindow.ui

RESOURCES += \
    myimages.qrc

DEFINES  += QT_MESSAGELOGCONTEXT
