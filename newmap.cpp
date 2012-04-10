#include "newmap.h"
#include "ui_newmap.h"

newMap::newMap(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newMap)
{
    ui->setupUi(this);
    this->setFixedSize(425, 305);

    connect(ui->loadTileset, SIGNAL(clicked()), this, SLOT(changeTilesetPath()));
    connect(ui->loadObjects, SIGNAL(clicked()), this, SLOT(changeObjectsPath()));
}

newMap::~newMap()
{
    delete ui;
}

void newMap::updateUi()
{
    ui->tilesetPathText->setText(tilesetPath.absolutePath());
    ui->objectsPathText->setText(objectsPath.absolutePath());
}



void newMap::changeTilesetPath()
{
    QString ntilesetPath = QFileDialog::getOpenFileName (this, tr("Tileset file"), tilesetPath.path());
    if ( ntilesetPath.isNull() == false )
    {
        tilesetPath.setPath(ntilesetPath);
    }

    updateUi();

    qDebug() << tilesetPath;
}


void newMap::changeObjectsPath()
{
    QString nObjectsPath = QFileDialog::getOpenFileName (this, tr("Objects file"), objectsPath.path());
    if ( nObjectsPath.isNull() == false )
    {
        objectsPath.setPath(nObjectsPath);
    }

    updateUi();

    qDebug() << objectsPath;
}


