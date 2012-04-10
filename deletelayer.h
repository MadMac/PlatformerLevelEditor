#ifndef DELETELAYER_H
#define DELETELAYER_H

#include <QDialog>
#include <QTreeWidget>
#include <QtDebug>

namespace Ui {
class deletelayer;
}

class deletelayer : public QDialog
{
    Q_OBJECT
    
public:
    explicit deletelayer(QWidget *parent = 0);
    ~deletelayer();
private slots:
    void deleteLayer();
private:
    Ui::deletelayer *ui;
    QTreeWidget* layersTree;
};

#endif // DELETELAYER_H
