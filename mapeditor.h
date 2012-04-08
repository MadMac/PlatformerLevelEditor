#ifndef MAPEDITOR_H
#define MAPEDITOR_H

#include "QSFMLCanvas.h"


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

    sf::Sprite sprite;
    sf::Texture texture;
    sf::CircleShape circle;

};

#endif // MAPEDITOR_H
