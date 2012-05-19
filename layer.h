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
    void draw();
    void loadTextures();
    std::string layerName;

private:

    bool visible;

    int width, height;
    int id;
    int category;


};

#endif // LAYER_H
