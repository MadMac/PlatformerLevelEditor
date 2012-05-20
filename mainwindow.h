
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolBar>
#include <QPushButton>
#include <QFrame>
#include <QScrollArea>
#include <iostream>
#include <fstream>

#include "newmap.h"
#include "newlayer.h"
#include "deletelayer.h"
#include "layer.h"
#include <QTimer>
#include "glwidget.h"
#include "tileselection.h"
#include "addattribute.h"


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
    void selectLayer();
    void addAttributeWindow();

    void changeTab();

    void changeToolAddObject();
    void changeToolPen();
    void changeToolMoveObject();

protected:
    void closeEvent(QCloseEvent *evt);
    void keyPressEvent(QKeyEvent *e);

private:
    Ui::MainWindow *ui;
    QToolBar* ui_toolbar;

    QScrollArea* ui_Editor;

    GLWidget* editorOpenGL;

    tileSelection* tileGL;
    tileSelection* objectGL;

    std::vector<int> currentTile;

    newMap* newMapWindow;
    newLayer* newLayerWindow;
    deletelayer* newDeleteLayerWindow;
    addAttribute* newAttributeWindow;

    QDir currentFilePath;

    std::vector<layer> allLayers;

    int layerSelected;

    int mapWidth, mapHeight;

    std::ofstream file;

    int currentTool;
    std::vector<int> layerCount;
};

#endif // MAINWINDOW_H
