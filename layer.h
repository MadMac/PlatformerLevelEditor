#ifndef LAYER_H
#define LAYER_H

#include "tile.h"
#include <string>
#include <vector>
#include <QtDebug>
#include <SFML/Graphics.hpp>

class layer
{
public:
    layer(std::string layerName, int width, int height, int id);
    void setVisible(bool visible);
    bool isVisible();
    int getId();
    std::vector<tile> tiles;
    void draw(sf::RenderWindow* rWindow);
    void loadTextures();

private:

    bool visible;
    std::string layerName;
    int width, height;
    int id;

    sf::Texture spriteSheet;

};

#endif // LAYER_H
