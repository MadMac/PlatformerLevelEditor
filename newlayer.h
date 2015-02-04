#ifndef NEWLAYER_H
#define NEWLAYER_H

#include <QDialog>
#include <QTreeWidgetItem>
#include <QtDebug>

#include "layer.h"
#include <vector>

namespace Ui {
class newLayer;
}

class newLayer : public QDialog
{
    Q_OBJECT
    
public:
    explicit newLayer(QWidget *parent = 0, std::vector<layer>* layers = NULL, int width = 0, int height = 0, std::vector<int>* layerCount = NULL);
    ~newLayer();
private slots:
    void addNewLayer();
private:
    Ui::newLayer *ui;

    QTreeWidget* layersTree;
    QTreeWidgetItem* newItem;

    std::vector<layer>* layers;
    QString defaultName;

    int lWidth, lHeight;
    std::vector<int>* layerCount;
};

#endif // NEWLAYER_H
