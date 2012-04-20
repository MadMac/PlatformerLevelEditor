#include "deletelayer.h"
#include "ui_deletelayer.h"

deletelayer::deletelayer(QWidget *parent, std::vector<layer>* layers) :
    QDialog(parent),
    ui(new Ui::deletelayer)
{
    ui->setupUi(this);
    this->layers = layers;
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
        for (int i = 0; i < layers->size(); ++i)
        {

            if (layers->at(i).getId() == layersTree->currentItem()->data(0, Qt::UserRole).toInt())
            {
                qDebug() << "Layer deleted";

                layers->erase(layers->begin()+i);
                qDebug() << layers->size();

            }
        }
        delete layersTree->currentItem()->parent()->takeChild(layersTree->currentItem()->parent()->indexOfChild(layersTree->currentItem()));

    } else {
        qDebug() << "No layer selected!";
    }
}
