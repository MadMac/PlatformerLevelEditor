#ifndef LAYER_H
#define LAYER_H

#include "tile.h"
#include <string>
#include <vector>
#include <QtDebug>
#include <QImage>
class layer
{
public:
    layer(std::string layerName, int width, int height, int id, int category);
    void setVisible(bool visibility);
    bool isVisible();
    int getId();
    int getCategory();
    std::vector<tile> tiles;

    std::string layerName;
    void addObject();
    int getObjects();
    void moveObject(int oldId, int newId);
private:

    bool visible;

    int width, height;
    int id;
    int category;
    int objects;

};

#endif // LAYER_H
