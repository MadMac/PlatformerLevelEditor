
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolBar>
#include <QPushButton>
#include <QFrame>
#include <QScrollArea>
#include "mapeditor.h"
#include "tileselection.h"
#include "newmap.h"
#include "newlayer.h"
#include "deletelayer.h"
#include "layer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void openNewMap();

    void saveLevel();
    void loadLevel();

    void makeNewLayer();
    void deleteLayer();
    void showLayer();

private:
    Ui::MainWindow *ui;
    QToolBar* ui_toolbar;

    QScrollArea* ui_Editor;

    mapEditor* editorSFML;

    tileSelection* tileSFML;

    newMap* newMapWindow;
    newLayer* newLayerWindow;
    deletelayer* newDeleteLayerWindow;

    QDir currentFilePath;

    std::vector<layer> allLayers;

    int mapWidth, mapHeight;
};

#endif // MAINWINDOW_H
