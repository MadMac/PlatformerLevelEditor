#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include "renderthread.h"

class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);
    ~GLWidget();
    void initRenderThread(void);
    void stopRenderThread(void);
signals:
    
public slots:

protected:
    void closeEvent(QCloseEvent *e);
    void resizeEvent(QResizeEvent *e);
    void paintEvent(QPaintEvent *);

    RenderThread cRenderThread;
    
};

#endif // GLWIDGET_H
