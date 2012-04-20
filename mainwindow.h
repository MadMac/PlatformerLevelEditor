
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolBar>
#include <QPushButton>
#include <QFrame>
#include <QScrollArea>
#include "tileselection.h"
#include "newmap.h"
#include "newlayer.h"
#include "deletelayer.h"
#include "layer.h"
#include <QTimer>
#include "glwidget.h"


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
protected:
    void closeEvent(QCloseEvent *evt);

private:
    Ui::MainWindow *ui;
    QToolBar* ui_toolbar;

    QScrollArea* ui_Editor;

    GLWidget* editorOpenGL;

    tileSelection* tileSFML;

    newMap* newMapWindow;
    newLayer* newLayerWindow;
    deletelayer* newDeleteLayerWindow;

    QDir currentFilePath;

    std::vector<layer> allLayers;

    int mapWidth, mapHeight;
};

#endif // MAINWINDOW_H
