#include "layer.h"

layer::layer(std::string layerName, int width, int height, int id, int category)
{
    this->layerName = layerName;
    this->width = width;
    this->height = height;
    this->id = id;
    this->category = category;


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

void layer::loadTextures()
{

}


void layer::draw()
{


}
