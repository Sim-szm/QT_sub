#-------------------------------------------------
#
# Project created by QtCreator 2014-05-25T19:01:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mainform
TEMPLATE = app


SOURCES += main.cpp\
        mainform.cpp \
    database.cpp \
    gamearea.cpp \
    input.cpp \
    myitem.cpp \
    topscore.cpp \
    dialog.cpp

HEADERS  += mainform.h \
    database.h \
    gamearea.h \
    input.h \
    myitem.h \
    topscore.h \
    dialog.h

FORMS    += mainform.ui \
    topscore.ui \
    input.ui
