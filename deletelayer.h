#ifndef DELETELAYER_H
#define DELETELAYER_H

#include <QDialog>
#include <QTreeWidget>
#include <QtDebug>
#include "layer.h"

namespace Ui {
class deletelayer;
}

class deletelayer : public QDialog
{
    Q_OBJECT
    
public:
    explicit deletelayer(QWidget *parent = 0, std::vector<layer>* layers = NULL);
    ~deletelayer();
private slots:
    void deleteLayer();
private:
    Ui::deletelayer *ui;
    QTreeWidget* layersTree;

    std::vector<layer>* layers;
};

#endif // DELETELAYER_H
