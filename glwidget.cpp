#include <QResizeEvent>
#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent),
    cRenderThread(this)
{
    setAutoBufferSwap(false);
}

GLWidget::~GLWidget()
{

}

void GLWidget::initRenderThread(void)
{
    doneCurrent();
    cRenderThread.start();
}

void GLWidget::stopRenderThread(void)
{
    cRenderThread.stop();
    cRenderThread.wait();
}

void GLWidget::resizeEvent(QResizeEvent *e)
{
    cRenderThread.resizeViewport(e->size());
}

void GLWidget::paintEvent(QPaintEvent *)
{

}

void GLWidget::closeEvent(QCloseEvent *e)
{
    stopRenderThread();
    QGLWidget::closeEvent(e);
}
