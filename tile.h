#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>
#include <QtDebug>

class tile
{
public:
    tile();
    void setId(int id);
    void setTexture();
    void draw(int x, int y, sf::RenderWindow *rWindow);
    int getId();

private:
    int id;
    sf::Sprite tileSprite;
    sf::Texture spriteSheet2;
};

#endif // TILE_H
