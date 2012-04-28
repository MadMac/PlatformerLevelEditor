#-------------------------------------------------
#
# Project created by QtCreator 2012-04-08T17:45:41
#
#-------------------------------------------------

QT       += core gui

TARGET = PlatformerLevelEditor
TEMPLATE = app

INCLUDEPATH += E:/QtSDK/Desktop/Qt/4.7.3/mingw/include


SOURCES += main.cpp\
        mainwindow.cpp \
    tileselection.cpp \
    newmap.cpp \
    newlayer.cpp \
    tile.cpp \
    deletelayer.cpp \
    layer.cpp \
    glwidget.cpp

HEADERS  += mainwindow.h \
    tileselection.h \
    newmap.h \
    newlayer.h \
    tile.h \
    deletelayer.h \
    layer.h \
    glwidget.h

QT += opengl

FORMS    += mainwindow.ui \
    newmap.ui \
    newlayer.ui \
    deletelayer.ui
