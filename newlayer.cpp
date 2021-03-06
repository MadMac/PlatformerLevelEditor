#include "newlayer.h"
#include "ui_newlayer.h"

newLayer::newLayer(QWidget *parent, std::vector<layer>* layers, int width, int height, std::vector<int>* layerCount) :
    QDialog(parent),
    ui(new Ui::newLayer)
{
    ui->setupUi(this);
    this->layers = layers;
    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(addNewLayer()));

    layersTree = parent->findChild<QTreeWidget*>("layers");

    lWidth = width;
    lHeight = height;
    this->layerCount = layerCount;
    defaultName.append("Layer ");
    defaultName.append(QString::number(layerCount->size()+1));

    ui->layerName->setText(defaultName);

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
    newItem->setData(0, Qt::UserRole, layerCount->size());
    newItem->setData(1, Qt::UserRole, ui->layerSelect->currentIndex());

    layer tempLayer(newItem->text(0).toStdString(), lWidth, lHeight, newItem->data(0, Qt::UserRole).toInt(), ui->layerSelect->currentIndex());
    layers->push_back(tempLayer);
    layersTree->setCurrentItem(newItem);
    layerCount->push_back(layerCount->size());
    qDebug() << "Added layer: " << newItem->text(0) << " " << newItem->data(0, Qt::UserRole).toInt() << " " << ui->layerSelect->currentText();

}

