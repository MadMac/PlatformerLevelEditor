#include <QResizeEvent>
#include "tileselection.h"

tileSelection::tileSelection(QWidget *parent) :
    QGLWidget(parent)
{
    upTimer.setInterval(16);
}

tileSelection::~tileSelection()
{

}

void tileSelection::update()
{

}

void tileSelection::paintEvent(QPaintEvent *event)
{
    cursorPos = mapFromGlobal(QCursor::pos());
    cursorPos.setX(floor(cursorPos.x()/32)*32);
    cursorPos.setY(floor(cursorPos.y()/32)*32);
    cursorRect.setTopLeft(cursorPos);
    cursorRect.setWidth(31);
    cursorRect.setHeight(31);

    if (cursorPos.x() == 0)
    {
        cursorPos.setX(1);
    }

    if (cursorPos.y() == 0)
    {
        cursorPos.setY(1);
    }

    painter.begin(this);
    background = QBrush(QColor(64, 32, 64));
    painter.setBackground(background);

    painter.drawImage(0,0, tilesetImage);

    painter.fillRect(cursorRect, QColor(150, 185, 255, 50));
    painter.setPen(QPen(QColor(191, 215, 255), 1, Qt::SolidLine));
    painter.drawRect(cursorRect);


    painter.end();
}

void tileSelection::init()
{
    connect(&upTimer, SIGNAL(timeout()), this, SLOT(repaint()));
    connect(&upTimer, SIGNAL(timeout()), this, SLOT(update()));
    upTimer.start();
}

void tileSelection::loadTileset(std::string path)
{
    tilesetImage = QImage(QString::fromStdString(path));
}
