#ifndef NEWMAP_H
#define NEWMAP_H

#include <QDialog>
#include <QDir>
#include <QFileDialog>
#include <QtDebug>

namespace Ui {
class newMap;
}

class newMap : public QDialog
{
    Q_OBJECT

public:
    explicit newMap(QWidget *parent = 0);
    ~newMap();

private slots:
    void changeTilesetPath();
    void changeObjectsPath();

private:
    Ui::newMap *ui;

    QDir tilesetPath;
    QDir objectsPath;

    void updateUi();

};

#endif // NEWMAP_H
