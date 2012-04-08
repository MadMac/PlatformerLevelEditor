#include "newmap.h"
#include "ui_newmap.h"

newMap::newMap(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newMap)
{
    ui->setupUi(this);
    this->setFixedSize(425, 305);

    connect(ui->loadTileset, SIGNAL(clicked()), this, SLOT(changeTilesetPath()));
}

newMap::~newMap()
{
    delete ui;
}

void newMap::updateUi()
{
    ui->tilesetPathText->setText(tilesetPath.absolutePath());
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


