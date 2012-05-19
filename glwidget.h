#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QtOpenGL>
#include "layer.h"
#include <QImage>
#include <QCursor>
#include <cmath>

class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);
    ~GLWidget();
    void init(std::vector<layer>* layers, int width, int height, std::vector<int>* currentTile, int* currentTool);
    std::vector<layer>* layers;

    void setSelectedLayer(int layer);

signals:

public slots:
private slots:
    void update();

protected:

    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent * e);
    void mouseReleaseEvent(QMouseEvent *e);

private:
    void loadTilesets();

    std::vector<int> *currentTile;

    QTimer myTimer;
    QImage spriteSheet;
    QPainter painter;
    QBrush background;

    QPoint cursorPos;
    QRect cursorRect;
    QRect collisionRect;

    int mapWidth, mapHeight;
    int layerSelected;
    QTreeWidget* layersTree;

    bool leftButtonDown;
    bool rightButtonDown;

    int *currentTool;
};

#endif // GLWIDGET_H
