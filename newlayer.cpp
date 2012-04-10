#include "newlayer.h"
#include "ui_newlayer.h"

newLayer::newLayer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newLayer)
{
    ui->setupUi(this);

    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(addNewLayer()));

    layersTree = parent->findChild<QTreeWidget*>("layers");

}

newLayer::~newLayer()
{
    delete ui;
    delete newItem;
}

void newLayer::addNewLayer()
{
    newItem = new QTreeWidgetItem(layersTree->topLevelItem(ui->layerSelect->currentIndex()));
    newItem->setText(0, ui->layerName->text());
    newItem->setCheckState(0, Qt::Checked);
}

