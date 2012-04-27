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
    void init(std::vector<layer>* layers, int width, int height, int *currentTile);
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

    int *currentTile;

    QTimer myTimer;
    QImage spriteSheet;
    QPainter painter;
    QBrush background;

    QPoint cursorPos;
    QRect cursorRect;

    int mapWidth, mapHeight;
    int layerSelected;
    QTreeWidget* layersTree;

    bool leftButtonDown;
    bool rightButtonDown;
};

#endif // GLWIDGET_H
