
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

private:
    Ui::MainWindow *ui;
    QToolBar* ui_toolbar;

    QScrollArea* ui_Editor;

    mapEditor* editorSFML;

    tileSelection* tileSFML;

    newMap* newMapWindow;

    QDir currentFilePath;
};

#endif // MAINWINDOW_H
