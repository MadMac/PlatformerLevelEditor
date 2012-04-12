#include "renderthread.h"
#include "glwidget.h"

RenderThread::RenderThread(GLWidget *_cGLWidget) :
    QThread(),
    cGLWidget(_cGLWidget)
{
    doRendering = true;
    doResize = false;
    frameCounter = 0;
}

void RenderThread::resizeViewport(const QSize &size)
{
    w = size.width();
    h = size.height();
    doResize = true;
}

void RenderThread::stop()
{
    doRendering = false;
}

void RenderThread::run()
{
    cGLWidget->makeCurrent();
    GLInit();

    while (doRendering)
    {
        if (doResize)
        {
            GLResize(w,h);
            doResize = false;
        }

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();

        paintGL();

        frameCounter++;
        cGLWidget->swapBuffers();

        msleep(16);
    }
}

void RenderThread::GLInit(void)
{
    glClearColor(0.05f, 0.05f, 0.1f, 0.0f);
}

void RenderThread::GLResize(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();
    gluPerspective(45.,((GLfloat)w)/((GLfloat)h),0.1f,1000.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void RenderThread::paintGL(void)
{
    glTranslatef(0.0f, 0.0f, -5.0f);            // move 5 units into the screen
    glRotatef(frameCounter,0.0f,0.0f,1.0f);     // rotate z-axis
    glBegin(GL_QUADS);
        glColor3f(1.,1.,0.); glVertex3f(-1.0, -1.0,0.0);
        glColor3f(1.,1.,1.); glVertex3f(1.0, -1.0,0.0);
        glColor3f(1.,0.,1.); glVertex3f(1.0, 1.0,0.0);
        glColor3f(1.,0.,0.); glVertex3f(-1.0, 1.0,0.0);
    glEnd();
}

