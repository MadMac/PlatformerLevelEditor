#ifndef QSFMLCANVAS_H
#define QSFMLCANVAS_H

#include <SFML/Graphics.hpp>
#include <qwidget.h>
#include <qtimer.h>


class QSFMLCanvas : public QWidget, public sf::RenderWindow
{
public :


    QSFMLCanvas(QWidget* Parent, const QPoint& Position, const QSize& Size, unsigned int FrameTime = 0);
    virtual ~QSFMLCanvas();

private :


    virtual void OnInit();

    virtual void OnUpdate();


    virtual QPaintEngine* paintEngine() const;

    virtual void showEvent(QShowEvent*);

    virtual void paintEvent(QPaintEvent*);

    bool SFMLRunning;

    QTimer myTimer;       ///< Timer used to update the view
    bool   myInitialized; ///< Tell whether the SFML window has been initialized or not
};


#endif // QSFMLCANVAS_HPP
