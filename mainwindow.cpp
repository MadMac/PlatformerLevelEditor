
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Temp sizes
    mapWidth = 32*80;
    mapHeight = 32*25;

//    editorSFML = new mapEditor(ui->tileScrollArea, QPoint(0, 0), QSize(mapWidth, mapHeight));
//    editorSFML->init(&allLayers);
//    editorSFML->setMinimumSize(mapWidth, mapHeight);
//    editorSFML->setMaximumSize(mapWidth, mapHeight);
//    ui->mapEditor->setWidget(editorSFML);

    editorOpenGL = new GLWidget();

    editorOpenGL->setMinimumSize(mapWidth, mapHeight);
    editorOpenGL->setMaximumSize(mapWidth, mapHeight);
    ui->mapEditor->setWidget(editorOpenGL);
    editorOpenGL->init(&allLayers, mapWidth/32, mapHeight/32);
    editorOpenGL->show();
//    tileSFML = new tileSelection(this, QPoint(0,0), QSize(800,550));
//    tileSFML->setMinimumSize(1024,768);
//    ui->tileScrollArea->setWidget(tileSFML);

    ui->tilesetTab->setTabText(0, "Tiles");
    ui->tilesetTab->setTabText(1, "Objects");

    connect(ui->actionNew, SIGNAL(triggered()), this, SLOT(openNewMap()));
    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(saveLevel()));
    connect(ui->actionLoad, SIGNAL(triggered()), this, SLOT(loadLevel()));


    //Layers
    connect(ui->addLayerButton, SIGNAL(clicked()), this, SLOT(makeNewLayer()));
    connect(ui->deleteLayerButton, SIGNAL(clicked()), this, SLOT(deleteLayer()));
    connect(ui->layers, SIGNAL(itemChanged(QTreeWidgetItem*,int)), this, SLOT(showLayer()));



}
MainWindow::~MainWindow()
{
//    delete editorSFML;
//    delete tileSFML;
    delete editorOpenGL;
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

void MainWindow::closeEvent(QCloseEvent *evt)
{

    QMainWindow::closeEvent(evt);
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
    newLayerWindow = new newLayer(this, &allLayers, mapWidth, mapHeight);
    newLayerWindow->show();

}

void MainWindow::deleteLayer()
{
    newDeleteLayerWindow = new deletelayer(this, &allLayers);
    newDeleteLayerWindow->show();

}

void MainWindow::showLayer()
{
    if (ui->layers->currentItem()->parent())
    {
        for (int i = 0; i < allLayers.size(); ++i)
        {

            if (allLayers.at(i).getId() == ui->layers->currentItem()->data(0, Qt::UserRole).toInt())
            {
                if (ui->layers->currentItem()->checkState(0) == Qt::Checked)
                {
                    allLayers.at(i).setVisible(true);
                } else {
                    allLayers.at(i).setVisible(false);
                }

            }
        }


    }


}
