#ifndef TILESELECTION_H
#define TILESELECTION_H


#include <QGLWidget>
#include <QtOpenGL>
#include <QtDebug>

class tileSelection : public QGLWidget
{
    Q_OBJECT
public:
    explicit tileSelection(QWidget *parent = 0);
    ~tileSelection();
    void init(std::vector<int>* currentTile);
    void loadTileset(std::string path);
private slots:
    void update();
protected:

    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *e);

private:
    QPainter painter;
    QTimer upTimer;
    QBrush background;

    QPoint cursorPos;
    QRect cursorRect;

    QRect selectedRect;

    QImage tilesetImage;
    std::vector<int> *currentTile;
};

#endif // TILESELECTION_H
