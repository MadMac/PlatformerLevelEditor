#include "layer.h"

layer::layer(std::string layerName, int width, int height, int id, int category)
{
    this->layerName = layerName;
    this->width = width;
    this->height = height;
    this->id = id;
    this->category = category;
    objects = 0;

    visible = true;

    qDebug() << category;
    for (int i = 0; i < (width/32)*(height/32); ++i)
    {
        tile tempTile;
        tempTile.setId(0);
        tiles.push_back(tempTile);
    }
    qDebug() << tiles.size();



}

void layer::setVisible(bool visibility)
{
    visible = visibility;
    qDebug() << visible;
}

void layer::addObject()
{
    objects++;
}

void layer::moveObject(int oldId, int newId)
{
    tiles.at(newId).setId(tiles.at(oldId).getId());
    tiles.at(oldId).setId(0);

    tiles.at(newId).attributes.clear();
    tiles.at(newId).attributes = tiles.at(oldId).attributes;
    tiles.at(oldId).attributes.clear();
}

int layer::getObjects()
{
    return objects;
}

bool layer::isVisible()
{
    return visible;
}

int layer::getId()
{
    return id;
}

int layer::getCategory()
{
    return category;
}


