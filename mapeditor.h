#ifndef MAPEDITOR_H
#define MAPEDITOR_H

#include "QSFMLCanvas.h"
#include <QtDebug>
#include <QCursor>
#include <vector>
#include <cmath>
#include "tile.h"
#include "layer.h"

class mapEditor : public QSFMLCanvas
{
public :

    mapEditor(QWidget* Parent, const QPoint& Position, const QSize& Size) :
        QSFMLCanvas(Parent, Position, Size)
    {

    }

    void init(std::vector<layer>* layers);
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

    std::vector<layer>* layers;

};

#endif // MAPEDITOR_H
