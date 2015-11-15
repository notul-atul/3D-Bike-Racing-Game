/**
  * @file trackpreview.cpp
  * @author Durgesh
  * @date 4 Sep 2013
  */

#include "trackpreview.h"
#include<QTimer>

/**
 * @brief TrackPreview::TrackPreview constructor which sets various openGL parameters which necessary to render the secne correctly on the screen
 * @param parent default parameter of the Qt ui
 */
TrackPreview::TrackPreview(QWidget *parent):QGLWidget(parent)
{
    setFormat(QGLFormat(QGL::DoubleBuffer | QGL::DepthBuffer | QGL::Rgba));
}
/**
 * @brief TrackPreview::TrackPreview constructor which sets various openGL parameters which necessary to render the secne correctly on the screen
 * and also intialises track and track texture fileName
 * @param track name of the terrain fileName
 * @param tracktex name of the Texture file name
 * @param parent default parameter of the Qt ui
 */
TrackPreview::TrackPreview(char *track, char *tracktex, QWidget *parent):QGLWidget(parent){
    setFormat(QGLFormat(QGL::DoubleBuffer | QGL::DepthBuffer | QGL::Rgba));
    this->track = track ;
    this->tracktex = tracktex ;
}
/**
 * @brief TrackPreview::initializeGL sets various modes of the openGL which is required for the terrain and Texture to be render correctly on the screen
 */
void TrackPreview::initializeGL(){
    qglClearColor(Qt::blue);
    glEnable(GL_DEPTH_TEST);
    glClearDepth(1);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0) ;
    glEnable(GL_NORMALIZE) ;
    terrain.readBMP(track, 20) ;
    terrain.genTexture(tracktex);
}
/**
 * @brief TrackPreview::resizeGL resizes the Window
 * @param w width of the screen recieved when screen resize or moves
 * @param h height of the screen recieved when screen resize or moves
 */
void TrackPreview::resizeGL(int w, int h){
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, w/h, 0.1, 1000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

/**
 * @brief TrackPreview::paintGL draws everything which the Track Preview demands such as Texture Terrain Obstacles Object Bonuses etc
 */
void TrackPreview::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0,0,-6);
    glRotatef(60, 1, 0, 0);
    glRotatef(180, 0, 1, 0);

    GLfloat lightColor[] = {1, 1, 1, 1} ;
    GLfloat lightPos[] = {0, 0, 0, 0} ;
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos) ;

    float scale = 5.0/terrain.getLength() ;
    glScalef(scale, scale, scale);
    glTranslatef(-terrain.getWidth()/2.0, 0, -terrain.getLength()/2.0);

    terrain.renderTerrain();
    swapBuffers();
}
/**
 * @brief TrackPreview::~TrackPreview deletes the pointers to the track and track texture name
 */
TrackPreview::~TrackPreview(){
    delete track ;
    delete tracktex ;
}
