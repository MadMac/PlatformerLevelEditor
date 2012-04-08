
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    editorSFML = new mapEditor(this, QPoint(0, 0), QSize(800, 550));
    editorSFML->setMinimumSize(1024,768);
    ui->mapEditor->setWidget(editorSFML);

    tileSFML = new tileSelection(this, QPoint(0,0), QSize(800,550));
    tileSFML->setMinimumSize(1024,768);
    ui->tileScrollArea->setWidget(tileSFML);


    connect(ui->actionNew, SIGNAL(triggered()), this, SLOT(openNewMap()));
    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(saveLevel()));
    connect(ui->actionLoad, SIGNAL(triggered()), this, SLOT(loadLevel()));
}
MainWindow::~MainWindow()
{
    delete editorSFML;
    delete tileSFML;
    delete ui;
    delete newMapWindow;
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
