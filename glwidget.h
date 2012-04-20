#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QtOpenGL>
#include "renderthread.h"
#include "layer.h"
#include <QImage>
#include <QCursor>

class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);
    ~GLWidget();
    void init(std::vector<layer>* layers, int width, int height);
    std::vector<layer>* layers;
signals:

public slots:
private slots:
    void update();

protected:

    void paintEvent(QPaintEvent *event);

private:
    void loadTilesets();

    QTimer myTimer;
    GLuint texture;
    QImage spriteSheet, formattedSheet;
    QPainter painter;
    QBrush background;

    QPoint cursorPos;
    QRect cursorRect;

    int mapWidth, mapHeight;
};

#endif // GLWIDGET_H
