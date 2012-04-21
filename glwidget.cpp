#include <QResizeEvent>
#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{
    myTimer.setInterval(16);
    layersTree = parent->findChild<QTreeWidget*>("layers");

    layerSelected = -1;
    leftButtonDown = false;
}

GLWidget::~GLWidget()
{

}


void GLWidget::update()
{
    if (leftButtonDown)
    {
        if (cursorPos.x() > 0 && cursorPos.x() < mapWidth*32 && cursorPos.y() > 0 && cursorPos.y() < mapHeight*32)
        {
            int id = 0;
            id = cursorPos.y()/32*mapWidth+cursorPos.x()/32;

            if (layerSelected != -1)
            {
                for (int i = 0; i < layers->size(); ++i)
                {

                    if (layers->at(i).getId() == layerSelected)
                    {

                            layers->at(i).tiles.at(id).setId(1);
                            qDebug() << id << layers->at(i).tiles.at(id).getId();

                    }
                }
            }
        }

    }
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
                if (layers->at(i).tiles.at(j).getId() != 0)
                {
                    painter.drawImage(x*32,y*32, spriteSheet);
                }
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

void GLWidget::mousePressEvent(QMouseEvent *e)
{

    if (e->button() == Qt::LeftButton)
    {
        leftButtonDown = true;
    }
}

void GLWidget::mouseReleaseEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)
    {
        leftButtonDown = false;
    }
}

void GLWidget::init(std::vector<layer>* layers, int width, int height)
{
    this->layers = layers;
    mapWidth = width;
    mapHeight = height;
    spriteSheet = QImage("metallipala.png");




    connect(&myTimer, SIGNAL(timeout()), this, SLOT(repaint()));
    connect(&myTimer, SIGNAL(timeout()), this, SLOT(update()));
    myTimer.start();
}

void GLWidget::setSelectedLayer(int layer)
{
    layerSelected = layer;
}
