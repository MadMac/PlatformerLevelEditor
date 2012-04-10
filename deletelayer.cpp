#include "deletelayer.h"
#include "ui_deletelayer.h"

deletelayer::deletelayer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deletelayer)
{
    ui->setupUi(this);

    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(deleteLayer()));


    layersTree = parent->findChild<QTreeWidget*>("layers");


}

deletelayer::~deletelayer()
{
    delete ui;

}

void deletelayer::deleteLayer()
{
    if (layersTree->currentItem()->parent())
    {
        delete layersTree->currentItem()->parent()->takeChild(layersTree->currentItem()->parent()->indexOfChild(layersTree->currentItem()));
    } else {
        qDebug() << "No layer selected!";
    }
}
