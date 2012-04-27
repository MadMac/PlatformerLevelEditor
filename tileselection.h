#ifndef TILESELECTION_H
#define TILESELECTION_H


#include <QGLWidget>
#include <QtOpenGL>


class tileSelection : public QGLWidget
{
    Q_OBJECT
public:
    explicit tileSelection(QWidget *parent = 0);
    ~tileSelection();
    void init();
    void loadTileset(std::string path);
private slots:
    void update();
protected:

    void paintEvent(QPaintEvent *event);

private:
    QPainter painter;
    QTimer upTimer;
    QBrush background;

    QPoint cursorPos;
    QRect cursorRect;

    QImage tilesetImage;
};

#endif // TILESELECTION_H
