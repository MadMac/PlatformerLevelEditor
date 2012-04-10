#ifndef MAPEDITOR_H
#define MAPEDITOR_H

#include "QSFMLCanvas.h"
#include <QtDebug>
#include <QCursor>
#include <vector>
#include <cmath>
#include "tile.h"

class mapEditor : public QSFMLCanvas
{
public :

    mapEditor(QWidget* Parent, const QPoint& Position, const QSize& Size) :
        QSFMLCanvas(Parent, Position, Size)
    {

    }
private:
    void OnInit();
    void OnUpdate();

    int margin;

    sf::Sprite sprite;
    sf::Texture texture;
    sf::RectangleShape border;
    sf::RectangleShape currentTile;

    QPoint cursorPos;

    sf::View mainCamera;

    std::vector<tile> backgroundTiles;
};

#endif // MAPEDITOR_H
