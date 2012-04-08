#ifndef TILESELECTION_H
#define TILESELECTION_H

#include "QSFMLCanvas.h"


class tileSelection : public QSFMLCanvas
{
public:
    tileSelection(QWidget* Parent, const QPoint& Position, const QSize& Size) :
        QSFMLCanvas(Parent, Position, Size)
    {

    }
};

#endif // TILESELECTION_H
