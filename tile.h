#ifndef TILE_H
#define TILE_H

#include <QtDebug>

class tile
{
public:
    tile();
    void setId(int id);
    void setTexture();
    void draw(int x, int y);
    int getId();

private:
    int id;

};

#endif // TILE_H
