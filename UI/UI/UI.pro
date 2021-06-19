#-------------------------------------------------
#
# Project created by QtCreator 2021-06-12T16:54:38
#
#-------------------------------------------------

QT       += core gui

CONFIG += c++11 console
CONFIG -= app_bundle
CONFIG += C++11   //添加对C++11的支持
DEFINES += QT_DEPRECATED_WARNINGS

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UI
TEMPLATE = app

INCLUDEPATH += /dji/local/include/opencv4
LIBS += -L/dji/local/lib -lopencv_core -lopencv_imgcodecs -lopencv_imgproc -lopencv_highgui -lopencv_calib3d
LIBS += /usr/local/lib/libopencv_shape.so \
        /usr/local/lib/libopencv_videoio.so \
        /usr/local/lib/libopencv_core.so.3.4.7
LIBS+=-lpthread


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../linuxSDK_V2.1.0.20/lib/arm64/release/ -lMVSDK
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../linuxSDK_V2.1.0.20/lib/arm64/debug/ -lMVSDK
else:unix: LIBS += -L$$PWD/../../../linuxSDK_V2.1.0.20/lib/arm64/ -lMVSDK

INCLUDEPATH += $$PWD/../../../linuxSDK_V2.1.0.20/lib/arm64
DEPENDPATH += $$PWD/../../../linuxSDK_V2.1.0.20/lib/arm64
