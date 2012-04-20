#include <QResizeEvent>
#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{
    myTimer.setInterval(16);

}

GLWidget::~GLWidget()
{

}


void GLWidget::update()
{
}

void GLWidget::paintEvent(QPaintEvent *event)
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
//    painter.drawImage(0,0, spriteSheet);





    for (int i = 0; i < layers->size(); ++i)
    {
        int x = 0;
        int y = 0;
        if (layers->at(i).isVisible())
        {
            for (int j = 0; j < layers->at(i).tiles.size(); ++j)
            {
                painter.drawImage(x*32,y*32, spriteSheet);

                x++;
                if (x*32 > mapWidth*32-32)
                {

                    y++;
                    x = 0;
                }
            }
        }


    }

    if (cursorPos.x() > 0 && cursorPos.x() < mapWidth*32 && cursorPos.y() > 0 && cursorPos.y() < mapHeight*32)
    {
        painter.fillRect(cursorRect, QColor(150, 185, 255, 50));
        painter.setPen(QPen(QColor(191, 215, 255), 1, Qt::SolidLine));
        painter.drawRect(cursorRect);

    }

    painter.end();
}

void GLWidget::init(std::vector<layer>* layers, int width, int height)
{
    this->layers = layers;
    mapWidth = width;
    mapHeight = height;
    spriteSheet = QImage("metallipala.png");


    connect(&myTimer, SIGNAL(timeout()), this, SLOT(repaint()));
    myTimer.start();
}




