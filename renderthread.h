#ifndef RENDERTHREAD_H
#define RENDERTHREAD_H

#include <QThread>
#include <QtOpenGL>

class QSize;
class GLWidget;

class RenderThread : public QThread
{
    Q_OBJECT
public:
    explicit RenderThread(GLWidget *parent = 0);
    void resizeViewport(const QSize &size);
    void run(void);
    void stop(void);


protected:
    void GLInit(void);
    void GLResize(int w, int h);
    void paintGL(void);

private:
    bool doRendering, doResize;
    int w, h;
    int frameCounter;

    GLWidget *cGLWidget;
signals:

public slots:
};

#endif // RENDERTHREAD_H
