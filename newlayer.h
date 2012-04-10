#ifndef NEWLAYER_H
#define NEWLAYER_H

#include <QDialog>
#include <QTreeWidget>
#include <QtDebug>

namespace Ui {
class newLayer;
}

class newLayer : public QDialog
{
    Q_OBJECT
    
public:
    explicit newLayer(QWidget *parent = 0);
    ~newLayer();
private slots:
    void addNewLayer();
private:
    Ui::newLayer *ui;

    QTreeWidget* layersTree;
    QTreeWidgetItem* newItem;
    QTreeWidgetItem* layer;

};

#endif // NEWLAYER_H
