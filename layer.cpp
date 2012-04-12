#include "layer.h"

layer::layer(std::string layerName, int width, int height, int id)
{
    this->layerName = layerName;
    this->width = width;
    this->height = height;
    this->id = id;

    spriteSheet.LoadFromFile("metallipala.png");

    for (int i = 0; i < (width/32)*(height/32); ++i)
    {
        tile tempTile;
        tempTile.setId(1);
        tiles.push_back(tempTile);
    }



}

void layer::setVisible(bool visible)
{
    this->visible = visible;
}

bool layer::isVisible()
{
    return visible;
}

int layer::getId()
{
    return id;
}

void layer::loadTextures()
{
    for (int i = 0; i < tiles.size(); ++i)
    {
        tiles.at(i).setTexture();

    }
    qDebug() << "Textures: done";
}

void layer::draw(sf::RenderWindow* rWindow)
{
    int x = 0;
    int y = 0;


    for (int i = 0; i < tiles.size(); ++i)
    {


        if (tiles.at(i).getId() != 0)
        {
            tiles.at(i).draw(x*32, y*32, rWindow);
        }

        x++;
        if (x*32 > width-32)
        {
            y++;
            x = 0;
        }
    }
}
