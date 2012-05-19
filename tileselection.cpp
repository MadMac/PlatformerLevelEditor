#include <QResizeEvent>
#include "tileselection.h"

tileSelection::tileSelection(QWidget *parent) :
    QGLWidget(parent)
{
    upTimer.setInterval(16);
    setFocusPolicy(Qt::StrongFocus);
}

tileSelection::~tileSelection()
{

}

void tileSelection::update()
{

}

void tileSelection::keyPressEvent(QKeyEvent *e)
{

    if (e->key() == Qt::Key_Control)
    {
        qDebug() << "Control down";
        ctrlDown = true;

    }
}

void tileSelection::keyReleaseEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Control)
    {
        ctrlDown = false;
    }
}

void tileSelection::mousePressEvent(QMouseEvent *e)
{

    if (e->button() == Qt::LeftButton)
    {
        if (cursorPos.x() > 0 && cursorPos.x() < tilesetImage.width() && cursorPos.y() > 0 && cursorPos.y() < tilesetImage.height())
        {
            if (!ctrlDown)
            {
                currentTile->clear();
            }
            int currentId = 0;
            currentId = 1+(tilesetImage.width()/32)*floor(cursorPos.y()/32)+floor(cursorPos.x()/32);

            currentTile->push_back(currentId);
            qDebug() << currentTile->at(0);
        }
    }

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

    if (cursorPos.x() > 0 && cursorPos.x() < tilesetImage.width() && cursorPos.y() > 0 && cursorPos.y() < tilesetImage.height())
    {
        painter.fillRect(cursorRect, QColor(150, 185, 255, 50));
        painter.setPen(QPen(QColor(191, 215, 255), 1, Qt::SolidLine));
        painter.drawRect(cursorRect);
    }
    painter.setPen(QPen(QColor(255, 0, 0), 1, Qt::SolidLine));

    for (int i = 0; i < currentTile->size(); ++i)
    {
        painter.fillRect(selectedRect, QColor(255, 0, 0, 50));
        selectedRect.setX(32*fmod(currentTile->at(i)-1, tilesetImage.width()/32));
        selectedRect.setY(32*ceil(double(currentTile->at(i))/(tilesetImage.width()/32)) - 32);
        selectedRect.setWidth(31);
        selectedRect.setHeight(31);
        painter.drawRect(selectedRect);
    }

    painter.end();
}

void tileSelection::init(std::vector<int>* currentTile)
{

    this->currentTile = currentTile;
    connect(&upTimer, SIGNAL(timeout()), this, SLOT(repaint()));
    connect(&upTimer, SIGNAL(timeout()), this, SLOT(update()));
    upTimer.start();
}

void tileSelection::loadTileset(std::string path)
{
    tilesetImage = QImage(QString::fromStdString(path));
}
