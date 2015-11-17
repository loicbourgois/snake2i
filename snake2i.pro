#-------------------------------------------------
#
# Project created by QtCreator 2015-11-17T14:02:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = snake
TEMPLATE = app


SOURCES += main.cpp\
        main-window.cpp \
    options-window.cpp

HEADERS  += main-window.h \
    options-window.h

FORMS    += mainwindow.ui \
    options-window.ui
