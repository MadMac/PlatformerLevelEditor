#include <QResizeEvent>
#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{
    myTimer.setInterval(16);
    layersTree = parent->findChild<QTreeWidget*>("layers");

    layerSelected = -1;
    leftButtonDown = false;
    rightButtonDown = false;

    setMouseTracking(true);

    moveObjectId = 0;
}

GLWidget::~GLWidget()
{

}


void GLWidget::update()
{
    int id = 0;
    //Normal drawing while left button is down.
    if (leftButtonDown)
    {


            id = cursorPos.y()/32*mapWidth+cursorPos.x()/32;

            if (layerSelected != -1)
            {
                for (int i = 0; i < int(layers->size()); ++i)
                {

                    if (layers->at(i).getId() == layerSelected )
                    {
                        if (layers->at(i).getCategory() != 3 && *currentTool == 1)
                        {
                            layers->at(i).tiles.at(id).setId(currentTile->at(0));
                            qDebug() << id << layers->at(i).tiles.at(id).getId();
                        } else if (layers->at(i).getCategory() == 3 && *currentTool == 2 && layers->at(i).tiles.at(id).getId() == 0)
                        {
                            layers->at(i).addObject();
                            layers->at(i).tiles.at(id).setId(layers->at(i).getObjects());
                            qDebug() << "Object added!" << layers->at(i).tiles.at(id).getId();
                        }

                    }
                }
            }
        }


    //When right button is down
    //it removes tiles/objects.
    if (rightButtonDown)
    {
            id = cursorPos.y()/32*mapWidth+cursorPos.x()/32;

            if (layerSelected != -1)
            {
                for (int i = 0; i < int(layers->size()); ++i)
                {

                    if (layers->at(i).getId() == layerSelected && layers->at(i).getCategory() != 3 && *currentTool == 1)
                    {

                        layers->at(i).tiles.at(id).setId(0);
                        qDebug() << id << layers->at(i).tiles.at(id).getId();

                    } else if (layers->at(i).getCategory() == 3 && *currentTool == 2 && layers->at(i).tiles.at(id).getId() != 0)
                    {
                        layers->at(i).tiles.at(id).setId(0);
                        qDebug() << "Object deleted!" << layers->at(i).tiles.at(id).getId();
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
    painter.setBackground(background);


    double startx, starty;


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
                    startx = 32*fmod(layers->at(i).tiles.at(j).getId()-1, spriteSheet.width()/32);
                    starty = 32*ceil(double(layers->at(i).tiles.at(j).getId())/(spriteSheet.width()/32)) - 32;
                    if (layers->at(i).getCategory() == 0)
                    {
                        painter.drawImage(x*32,y*32, spriteSheet, startx, starty, 32, 32);
                    }
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
                    startx = 32*fmod(layers->at(i).tiles.at(j).getId()-1, spriteSheet.width()/32);
                    starty = 32*ceil(double(layers->at(i).tiles.at(j).getId())/(spriteSheet.width()/32)) - 32;
                    if (layers->at(i).getCategory() == 1)
                    {
                        painter.drawImage(x*32,y*32, spriteSheet, startx, starty, 32, 32);
                    }
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
                    startx = 32*fmod(layers->at(i).tiles.at(j).getId()-1, spriteSheet.width()/32);
                    starty = 32*ceil(double(layers->at(i).tiles.at(j).getId())/(spriteSheet.width()/32)) - 32;
                    if (layers->at(i).getCategory() == 2) {

                        collisionRect.setTopLeft(QPoint(x*32, y*32));
                        collisionRect.setWidth(31);
                        collisionRect.setHeight(31);
                        painter.fillRect(collisionRect, QColor(223, 255, 178, 50));
                        if (layers->at(i).getId() == layerSelected)
                        {
                            painter.setPen(QPen(QColor(187, 255, 91, 95), 2, Qt::SolidLine));
                        } else {
                            painter.setPen(QPen(QColor(106, 142, 51, 95), 1, Qt::SolidLine));
                        }
                        painter.drawRect(collisionRect);

                    }
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
                    startx = 32*fmod(layers->at(i).tiles.at(j).getId()-1, spriteSheet.width()/32);
                    starty = 32*ceil(double(layers->at(i).tiles.at(j).getId())/(spriteSheet.width()/32)) - 32;
                    if (layers->at(i).getCategory() == 3) {
                        objectRect.setTopLeft(QPoint(x*32, y*32));
                        objectRect.setWidth(31);
                        objectRect.setHeight(31);
                        painter.fillRect(objectRect, QColor(145, 145, 145, 50));
                        if (moveObjectId == j)
                        {
                            painter.setPen(QPen(QColor(211, 169, 0, 95), 2, Qt::DashDotLine));
                        } else if (layers->at(i).getId() == layerSelected) {
                            painter.setPen(QPen(QColor(211, 169, 130, 95), 2, Qt::DashDotLine));
                        } else {
                            painter.setPen(QPen(QColor(50, 50, 50, 95), 2, Qt::DashDotLine));
                        }
                        painter.drawRect(objectRect);

                    }
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
        if (*currentTool == 1)
        {
            painter.fillRect(cursorRect, QColor(150, 185, 255, 50));
            painter.setPen(QPen(QColor(191, 215, 255), 1, Qt::SolidLine));
            painter.drawRect(cursorRect);
        } else if (*currentTool == 2)
        {
            painter.fillRect(cursorRect, QColor(198, 0, 0, 50));
            painter.setPen(QPen(QColor(147, 0, 0), 1, Qt::SolidLine));
            painter.drawRect(cursorRect);
        } else if (*currentTool == 3)
        {
            painter.fillRect(cursorRect, QColor(255, 204, 0, 50));
            painter.setPen(QPen(QColor(211, 169, 0), 1, Qt::SolidLine));
            painter.drawRect(cursorRect);
        }

    }

    painter.end();
}

void GLWidget::mousePressEvent(QMouseEvent *e)
{
    if (cursorPos.x() > 0 && cursorPos.x() < mapWidth*32 && cursorPos.y() > 0 && cursorPos.y() < mapHeight*32)
    {
        if (e->button() == Qt::LeftButton)
        {
            if (*currentTool != 3)
            {
                leftButtonDown = true;
            } else {
                // Object Moving
                int id = 0;
                id = cursorPos.y()/32*mapWidth+cursorPos.x()/32;

                if (layerSelected != -1)
                {
                    for (int i = 0; i < int(layers->size()); ++i)
                    {
                        if (layers->at(i).getId() == layerSelected )
                        {
                            if (layers->at(i).getCategory() == 3)
                            {
                                if (moveObjectId == 0 && layers->at(i).tiles.at(id).getId() != 0)
                                {
                                    moveObjectId = id;
                                    qDebug() << "Object saved!" << moveObjectId << id;
                                } else if (moveObjectId != id && moveObjectId != 0 && layers->at(i).tiles.at(id).getId() == 0) {
                                    layers->at(i).moveObject(moveObjectId, id);
                                    qDebug() << "Object moved from " << moveObjectId << " to " << id;
                                    moveObjectId = 0;
                                }
                            }
                        }
                    }
                }
            }
        }
        else if (e->button() == Qt::RightButton)
        {
            rightButtonDown = true;
        }
    }
}
void GLWidget::mouseReleaseEvent(QMouseEvent *e)
{

        if (e->button() == Qt::LeftButton)
        {
            leftButtonDown = false;



        }
        else if (e->button() == Qt::RightButton)
        {
            rightButtonDown = false;
        }

}

void GLWidget::init(std::vector<layer>* layers, int width, int height, std::vector<int>* currentTile, int *currentTool)
{
    this->layers = layers;
    this->currentTile = currentTile;
    mapWidth = width;
    mapHeight = height;
    spriteSheet = QImage("tileset1.png");

    this->currentTool = currentTool;


    connect(&myTimer, SIGNAL(timeout()), this, SLOT(repaint()));
    connect(&myTimer, SIGNAL(timeout()), this, SLOT(update()));
    myTimer.start();
}

void GLWidget::setSelectedLayer(int layer)
{
    layerSelected = layer;
}
