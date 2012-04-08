#-------------------------------------------------
#
# Project created by QtCreator 2012-04-08T17:45:41
#
#-------------------------------------------------

QT       += core gui

TARGET = PlatformerLevelEditor
TEMPLATE = app

INCLUDEPATH += E:/QtSDK/Desktop/Qt/4.7.3/mingw/include
LIBS += E:/QtSDK/Desktop/Qt/4.7.3/mingw/lib/libsfml-graphics.a \
        E:/QtSDK/Desktop/Qt/4.7.3/mingw/lib/libsfml-window.a \
        E:/QtSDK/Desktop/Qt/4.7.3/mingw/lib/libsfml-system.a

SOURCES += main.cpp\
        mainwindow.cpp \
    mapeditor.cpp \
    QSFMLCanvas.cpp \
    tileselection.cpp \
    newmap.cpp

HEADERS  += mainwindow.h \
    mapeditor.h \
    QSFMLCanvas.h \
    tileselection.h \
    newmap.h

FORMS    += mainwindow.ui \
    newmap.ui
