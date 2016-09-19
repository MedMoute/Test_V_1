#-------------------------------------------------
#
# Project created by QtCreator 2016-09-17T12:05:28
#
#-------------------------------------------------

QT       += core gui

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Test_V_1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qdesktopicon.cpp \
    dosprompt.cpp \
    qrightclickbutton.cpp \
    qcudesktopwidget.cpp \
    explorer.cpp \
    qdraggablewindow.cpp \
    loginform.cpp

HEADERS  += mainwindow.h \
    dosprompt.h \
    qrightclickbutton.h \
    qdesktopicon.h \
    qcudesktopwidget.h \
    explorer.h \
    qdraggablewindow.h \
    loginform.h

FORMS    += mainwindow.ui \
    dosprompt.ui \
    explorer.ui \
    loginform.ui
