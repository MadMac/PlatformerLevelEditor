#include "newlayer.h"
#include "ui_newlayer.h"

newLayer::newLayer(QWidget *parent, std::vector<layer>* layers, int width, int height) :
    QDialog(parent),
    ui(new Ui::newLayer)
{
    ui->setupUi(this);
    this->layers = layers;
    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(addNewLayer()));

    layersTree = parent->findChild<QTreeWidget*>("layers");

    lWidth = width;
    lHeight = height;

    defaultName.append("Layer ");
    defaultName.append(QString::number(layers->size()+1));

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
    newItem->setData(0, Qt::UserRole, layers->size());

    layer tempLayer(newItem->text(0).toStdString(), lWidth, lHeight, newItem->data(0, Qt::UserRole).toInt(), ui->layerSelect->currentIndex());
    layers->push_back(tempLayer);
    layers->at(layers->size()-1).loadTextures();
    layersTree->setCurrentItem(newItem);
    qDebug() << "Added layer: " << newItem->text(0) << " " << newItem->data(0, Qt::UserRole).toInt() << " " << ui->layerSelect->currentText();
}

