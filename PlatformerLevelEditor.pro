#-------------------------------------------------
#
# Project created by QtCreator 2012-04-08T17:45:41
#
#-------------------------------------------------

CONFIG += qt
QT       += core gui widgets

TARGET = PlatformerLevelEditor
TEMPLATE = app

INCLUDEPATH += D:\Qt3\5.0.2\mingw47_32\include


SOURCES += main.cpp\
        mainwindow.cpp \
    tileselection.cpp \
    newmap.cpp \
    newlayer.cpp \
    tile.cpp \
    deletelayer.cpp \
    layer.cpp \
    glwidget.cpp \
    attribute.cpp \
    addattribute.cpp

HEADERS  += mainwindow.h \
    tileselection.h \
    newmap.h \
    newlayer.h \
    tile.h \
    deletelayer.h \
    layer.h \
    glwidget.h \
    attribute.h \
    addattribute.h

QT += opengl

FORMS    += mainwindow.ui \
    newmap.ui \
    newlayer.ui \
    deletelayer.ui \
    addattribute.ui

OTHER_FILES += \
    TODO.txt
