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
    layer(std::string layerName, int width, int height, int id);
    void setVisible(bool visibility);
    bool isVisible();
    int getId();
    std::vector<tile> tiles;
    void draw();
    void loadTextures();

private:

    bool visible;
    std::string layerName;
    int width, height;
    int id;


};

#endif // LAYER_H
