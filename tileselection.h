#ifndef TILESELECTION_H
#define TILESELECTION_H


#include <QGLWidget>
#include <QtOpenGL>
#include <QtDebug>
#include <QKeyEvent>

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
    void keyPressEvent(QKeyEvent *e);
    void keyReleaseEvent(QKeyEvent *e);

private:
    QPainter painter;
    QTimer upTimer;
    QBrush background;

    QPoint cursorPos;
    QRect cursorRect;

    QRect selectedRect;

    QImage tilesetImage;
    std::vector<int> *currentTile;

    bool ctrlDown;
};

#endif // TILESELECTION_H
