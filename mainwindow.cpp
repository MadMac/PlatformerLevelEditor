
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    editorSFML = new mapEditor(ui->tileScrollArea, QPoint(0, 0), QSize(32*30, 32*15));
    editorSFML->setMinimumSize(32*30, 32*15);
    editorSFML->setMaximumSize(32*30, 32*15);
    ui->mapEditor->setWidget(editorSFML);



    tileSFML = new tileSelection(this, QPoint(0,0), QSize(800,550));
    tileSFML->setMinimumSize(1024,768);
    ui->tileScrollArea->setWidget(tileSFML);

    ui->tilesetTab->setTabText(0, "Tiles");
    ui->tilesetTab->setTabText(1, "Objects");

    connect(ui->actionNew, SIGNAL(triggered()), this, SLOT(openNewMap()));
    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(saveLevel()));
    connect(ui->actionLoad, SIGNAL(triggered()), this, SLOT(loadLevel()));


    //Layers
    connect(ui->addLayerButton, SIGNAL(clicked()), this, SLOT(makeNewLayer()));
    connect(ui->deleteLayerButton, SIGNAL(clicked()), this, SLOT(deleteLayer()));
    connect(ui->layers, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(showLayer()));

}
MainWindow::~MainWindow()
{
    delete editorSFML;
    delete tileSFML;
    delete ui;
    delete newMapWindow;
    delete newLayerWindow;
    delete newDeleteLayerWindow;
}

void MainWindow::openNewMap()
{
    newMapWindow = new newMap();
    newMapWindow->show();
}


void MainWindow::saveLevel()
{
    QString nSaveFilePath = QFileDialog::getSaveFileName (this, tr("Save level"), currentFilePath.path());
    if ( nSaveFilePath.isNull() == false )
    {
        currentFilePath.setPath(nSaveFilePath);
    }

    qDebug() << currentFilePath;
}

void MainWindow::loadLevel()
{
    QString nLoadFilePath = QFileDialog::getOpenFileName (this, tr("Save level"), currentFilePath.path());
    if ( nLoadFilePath.isNull() == false )
    {
        currentFilePath.setPath(nLoadFilePath);
    }

    qDebug() << currentFilePath;
}

void MainWindow::makeNewLayer()
{
    newLayerWindow = new newLayer(this);
    newLayerWindow->show();
}

void MainWindow::deleteLayer()
{
    newDeleteLayerWindow = new deletelayer(this);
    newDeleteLayerWindow->show();

}

void MainWindow::showLayer()
{


}
