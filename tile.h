#ifndef TILE_H
#define TILE_H

#include <QtDebug>
#include <vector>

#include "attribute.h"

class tile
{
public:
    tile();
    void setId(int id);
    void setTexture();
    void draw(int x, int y);
    int getId();
    std::vector<attribute> attributes;

private:
    int id;

};

#endif // TILE_H
