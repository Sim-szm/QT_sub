#-------------------------------------------------
#
# Project created by QtCreator 2014-05-25T19:01:01
#
#-------------------------------------------------

QT       += core gui
QT       +=sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mainform
TEMPLATE = app


SOURCES += main.cpp\
        mainform.cpp \
    database.cpp \
    myitem.cpp \
    input.cpp \
    topscore.cpp \
    gamearea.cpp

HEADERS  += mainform.h \
    database.h \
    myitem.h \
    input.h \
    topscore.h \
    gamearea.h

FORMS    += mainform.ui \
    input.ui \
    topscore.ui
