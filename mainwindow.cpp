
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    currentTile.push_back(1);
    //Temp sizes
    mapWidth = 32*15;
    mapHeight = 32*15;
    layerSelected = 0;
    currentTool = 1;

    editorOpenGL = new GLWidget();
    editorOpenGL->setMinimumSize(mapWidth, mapHeight);
    editorOpenGL->setMaximumSize(mapWidth, mapHeight);
    ui->mapEditor->setWidget(editorOpenGL);
    editorOpenGL->init(&allLayers, mapWidth/32, mapHeight/32, &currentTile, &currentTool);
    editorOpenGL->show();

    tileGL = new tileSelection();
    tileGL->setMinimumSize(100,100);
    ui->tileScrollArea->setWidget(tileGL);
    tileGL->init(&currentTile);
    tileGL->loadTileset("tileset1.png");
    tileGL->show();

    objectGL = new tileSelection();
    objectGL->setMinimumSize(100,100);
    ui->objectScrollArea->setWidget(objectGL);
    objectGL->init(&currentTile);
    objectGL->show();


    ui->tilesetTab->setTabText(0, "Tiles");
    ui->tilesetTab->setTabText(1, "Objects");

    connect(ui->actionNew, SIGNAL(triggered()), this, SLOT(openNewMap()));
    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(saveLevel()));
    connect(ui->actionLoad, SIGNAL(triggered()), this, SLOT(loadLevel()));
    connect(ui->actionAddObject, SIGNAL(triggered()), this, SLOT(changeToolAddObject()));
    connect(ui->actionMoveObject, SIGNAL(triggered()), this, SLOT(changeToolMoveObject()));
    connect(ui->actionPen, SIGNAL(triggered()), this, SLOT(changeToolPen()));

    //Layers
    connect(ui->addLayerButton, SIGNAL(clicked()), this, SLOT(makeNewLayer()));
    connect(ui->deleteLayerButton, SIGNAL(clicked()), this, SLOT(deleteLayer()));
    connect(ui->addAttributeButton, SIGNAL(clicked()), this, SLOT(addAttributeWindow()));
    connect(ui->layers, SIGNAL(itemChanged(QTreeWidgetItem*,int)), this, SLOT(showLayer()));
    connect(ui->layers, SIGNAL(itemClicked(QTreeWidgetItem*,int)), this, SLOT(selectLayer()));


    connect(ui->tilesetTab, SIGNAL(currentChanged(int)), this, SLOT(changeTab()));



}
MainWindow::~MainWindow()
{

    delete editorOpenGL;
    delete ui;
    delete newMapWindow;
    delete newLayerWindow;
    delete newDeleteLayerWindow;
    delete newAttributeWindow;
    delete tileGL;

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

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Escape)
    {

    }
}


void MainWindow::saveLevel()
{
    QString nSaveFilePath = QFileDialog::getSaveFileName (this, tr("Save level"), currentFilePath.path(), ".level");
    if ( nSaveFilePath.isNull() == false )
    {
        currentFilePath.setPath(nSaveFilePath);
        file.open(currentFilePath.absolutePath().toLatin1(), std::ios::in | std::ios::trunc);
        if (file.is_open())
        {
            file << mapWidth;
            file << "\n";
            file << mapHeight;
            file << "\nBackground\n";
            for (int i = 0; i < allLayers.size(); ++i)
            {
                if (allLayers[i].getCategory() == 0)
                {
                    file << "\n" << allLayers[i].layerName;
                    file << "\n";
                    for (int j = 0; j < allLayers[i].tiles.size(); ++j)
                    {
                        file << allLayers[i].tiles.at(j).getId();
                    }
                }
            }
            file << "\nForeground\n";
            for (int i = 0; i < allLayers.size(); ++i)
            {
                if (allLayers[i].getCategory() == 1)
                {
                    file <<"\n" << allLayers[i].layerName;
                    file << "\n";
                    for (int j = 0; j < allLayers[i].tiles.size(); ++j)
                    {
                        file << allLayers[i].tiles.at(j).getId();
                    }
                }
            }
            file << "\nCollision\n";
            for (int i = 0; i < allLayers.size(); ++i)
            {
                if (allLayers[i].getCategory() == 2)
                {
                    file << "\n" << allLayers[i].layerName;
                    file << "\n";
                    for (int j = 0; j < allLayers[i].tiles.size(); ++j)
                    {
                        if (allLayers[i].tiles.at(j).getId() != 0)
                        {
                            file << "1";
                        } else {
                            file << "0";
                        }
                    }
                }
            }
            file << "\nObjects\n";
            for (int i = 0; i < allLayers.size(); ++i)
            {
                if (allLayers[i].getCategory() == 3)
                {
                    file << "\n" << allLayers[i].layerName;
                    file << "\n";
                    for (int j = 0; j < allLayers[i].tiles.size(); ++j)
                    {
                        file << allLayers[i].tiles.at(j).getId();
                    }
                }
            }
        }
        file.close();
    }


    qDebug() << currentFilePath.absolutePath();
}

void MainWindow::loadLevel()
{
    QString nLoadFilePath = QFileDialog::getOpenFileName (this, tr("Load level"), currentFilePath.path(), ".level");
    if ( nLoadFilePath.isNull() == false )
    {
        currentFilePath.setPath(nLoadFilePath);
    }

    qDebug() << currentFilePath;
}

void MainWindow::makeNewLayer()
{
    newLayerWindow = new newLayer(this, &allLayers, mapWidth, mapHeight, &layerCount);
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
                    ui->layers->currentItem()->setTextColor(0, Qt::black);
                } else {
                    allLayers.at(i).setVisible(false);
                    ui->layers->currentItem()->setTextColor(0, Qt::gray);
                }

            }
        }


    }



}

void MainWindow::selectLayer()
{
    if (ui->layers->currentItem()->parent())
    {
        layerSelected = ui->layers->currentItem()->data(0, Qt::UserRole).toInt();

        qDebug() << "Layer selected: " <<  layerSelected;
        editorOpenGL->setSelectedLayer(layerSelected);

        if (ui->layers->currentItem()->data(1, Qt::UserRole).toInt() == 3)
        {
            ui->actionMoveObject->setDisabled(false);
            ui->actionPen->setDisabled(true);
            ui->actionAddObject->setDisabled(false);
            changeToolMoveObject();
        } else {
            ui->actionMoveObject->setDisabled(true);
            ui->actionPen->setDisabled(false);
            ui->actionAddObject->setDisabled(true);
            changeToolPen();
        }
    } else {
        qWarning("No layer found.");
    }


}

void MainWindow::addAttributeWindow()
{
    newAttributeWindow = new addAttribute(this);
    newAttributeWindow->show();
}

void MainWindow::changeTab()
{
//    switch(ui->tilesetTab->currentIndex())
//    {
//    case 0:
//        ui->objectScrollArea->takeWidget();
//        ui->tileScrollArea->setWidget(tileGL);
//        break;
//    case 1:
//        ui->tileScrollArea->takeWidget();
//        ui->objectScrollArea->setWidget(tileGL);
//        break;
//    default:
//        qWarning("Error: no tab found.");
//    }
    qDebug() << "Tab changed" << ui->tilesetTab->currentIndex();
}
void MainWindow::changeToolPen()
{
    currentTool = 1;

    qDebug() << "changed tool to: " << currentTool;

}
void MainWindow::changeToolAddObject()
{
    currentTool = 2;
    qDebug() << "changed tool to: " << currentTool;

}
void MainWindow::changeToolMoveObject()
{
    currentTool = 3;
    qDebug() << "changed tool to: " << currentTool;
}

