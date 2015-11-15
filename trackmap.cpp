#include "trackmap.h"
#include "ui_trackmap.h"

TrackMap::TrackMap(char *track, char *texture, PhysicsEngine2 physics, QWidget *parent):
    QGLWidget(parent),
    ui(new Ui::TrackMap)
{
    ui->setupUi(this);
    this->track = track ;
    this->texture = texture ;
    this->physics = physics ;
    obj.readObj("hell_pig.obj");
    terrain.readBMP(this->track, 10) ;
    terrain.genTexture(this->texture) ;
}

TrackMap::~TrackMap()
{
    delete ui;
    delete track ;
    delete texture ;
}

void TrackMap::initializeGL(){
    qglClearColor(Qt::blue) ;
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_TEXTURE_2D);
}

void TrackMap::paintGL(){
    /*glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0,0,-2);
    glRotatef(30, 1, 0, 0);


    GLfloat lightColor[] = {0.6f, 0.6f, 0.6f, 1} ;
    GLfloat lightPos[] = {0.5f, 0.8f, 0.1f, 0} ;
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos) ;

    float scale = 5.0/terrain.getLength() ;
    glScalef(scale, scale, scale);
    glTranslatef(-terrain.getWeidth()/2.0, 0, -terrain.getLength()/2.0);

    terrain.renderTerrain();
    swapBuffers();
   /* glPushMatrix();
    glTranslatef(physics.fxco, physics.fyco, physics.fzco);
    glScalef(20, 20, 20);
    obj.drawObj();
    glPopMatrix();
    swapBuffers();*/
    /*glBegin(GL_POLYGON);
    glColor3f(0,1,0) ;
    glVertex3f(-0.5, 0.5, -1);
    glVertex3f(0.5, 0.5, -1);
    glVertex3f(0.5, -0.5, -1);
    glVertex3f(-0.5, -0.5, -1);
    glEnd();*/
}

void TrackMap::resizeGL(int w, int h){
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, w/h, 0.1, 5000);
}

void TrackMap::getCoordinates(int x, int y, int z){
    this->physics.fxco = x ;
    this->physics.fyco = y ;
    this->physics.fzco = z ;
    updateGL() ;
}
