/**
  * @author Durgesh
  * @date 4 Sep 2013
  * @file gameWindow.cpp
  */
#include "gamewindow.h"
#include "ui_gamewindow.h"
#include<math.h>
#include<iostream>
#include<QPainter>
#include<QPen>
#include<QBrush>
#include<string.h>
#include<fstream>
#include<stdio.h>
#include<sstream>
using namespace std ;

/**
 * @brief gameWindow::gameWindow
 * @param isPracticeMode true if Practice mode is Selected else false if New Game is selected or previously saved game is reloaded
 * @param mode value which determines whether to keep bonuses and obstacles on the Landscape or not
 * @param parent default parameter of the Qt apps
 */
gameWindow::gameWindow(bool isPracticeMode, int mode, QWidget *parent) :
    QGLWidget(parent),
    ui(new Ui::gameWindow)
{
    ui->setupUi(this);
    this->isPracticeMode = isPracticeMode ;
    this->mode = mode ;
    setFormat(QGLFormat(QGL::DoubleBuffer|QGL::DepthBuffer|QGL::Rgba));

    mainLoopTimer = new QTimer(this) ;
    connect(mainLoopTimer, SIGNAL(timeout()), this, SLOT(update1())) ;
    mainLoopTimer->start(1) ;// update after 1 milisecond

    clockTimer = new QTimer(this) ;
    connect(clockTimer, SIGNAL(timeout()), this, SLOT(emmitTimeLeft())) ;
    clockTimer->start(1000); // count number of second ellips to calculate how much time left(not in practice mode)

    for(int i = 0 ; i < 4 ; i++) keysPressed[i] = 0 ; // initialy no key is pressed
    paused = false ;
   // out.open("track10obst", ios::out);
    a = 0 ;
}
/**
 * @brief gameWindow::getTrack replies with the name of the track which is selected by the user
 * @return name of the selected track
 */
char* gameWindow::getTrack(){
    return track ;
}
/**
 * @brief gameWindow::getTexture replies with the name of the texture of the track which is selected by the user
 * @return name of the texture file of the selected track
 */
char* gameWindow::getTexture(){
    return tracktex ;
}
/**
 * @brief gameWindow::getPhysics
 * @return return the pointer of the physicsEngine object
 */
GameEngine gameWindow::getPhysics(){
    return  this->physics;
}
/**
 * @brief gameWindow::getNoOfPoints
 * @return latest number of points collected by the gamer
 */
int gameWindow::getNoOfPoints(){
    return doobs.numBonusCollect ;
}
/**
 * @brief gameWindow::setTrack sets the Landscape of the game accorf=ding to the track name and its corresponding texture file
 * @param track name of the terrain file
 * @param tracktex corresponding texture file name of the terrain
 */
void gameWindow::setTrack(char *track, char *tracktex){
    this->track = track ;
    this->tracktex = tracktex ;
    ifstream input ;// open file which storing starting position and other information of perticular track
    FILE *fileBonus, *fileObst;// open file which storing positions of bonus markers and obstacles
    if(strcmp(track, "track1.bmp") == 0){
        input.open("track1", ios::in);
        fileBonus= fopen("track1bonus", "rb");
        fileObst= fopen("track1obst", "rb");
        timeleft = 360 ;
    }
    else if(strcmp(track, "track2.bmp") == 0){
        input.open("track2", ios::in);
        fileBonus= fopen("track2bonus", "rb");
        fileObst= fopen("track2obst", "rb");
        timeleft = 435 ;
    }
    else if(strcmp(track, "track3.bmp") == 0){
        input.open("track3", ios::in);
        fileBonus= fopen("track3bonus", "rb");
        fileObst= fopen("track3obst", "rb");
        timeleft = 465 ;
    }
    else if(strcmp(track, "track4.bmp") == 0){
        input.open("track4", ios::in);
        fileBonus= fopen("track4bonus", "rb");
        fileObst= fopen("track4obst", "rb");
        timeleft = 300 ;
    }
    else if(strcmp(track, "track5.bmp") == 0){
        input.open("track5", ios::in);
        fileBonus= fopen("track5bonus", "rb");
        fileObst= fopen("track5obst", "rb");
        timeleft = 615 ;
    }
    else if(strcmp(track, "track6.bmp") == 0){
        input.open("track6", ios::in);
        fileBonus= fopen("track6bonus", "rb");
        fileObst= fopen("track6obst", "rb");
        timeleft = 450 ;
    }
    else if(strcmp(track, "track7.bmp") == 0){
        input.open("track7", ios::in);
        fileBonus= fopen("track7bonus", "rb");
        fileObst= fopen("track7obst", "rb");
        timeleft = 375 ;
    }
    else if(strcmp(track, "track8.bmp") == 0){
        input.open("track8", ios::in);
        fileBonus= fopen("track8bonus", "rb");
        fileObst= fopen("track8obst", "rb");
        timeleft = 390 ;
    }
    else if(strcmp(track, "track9.bmp") == 0){
        input.open("track9", ios::in);
        fileBonus= fopen("track9bonus", "rb");
        fileObst= fopen("track9obst", "rb");
        timeleft = 420 ;
    }
    else{
        input.open("track10", ios::in);
        fileBonus= fopen("track10bonus", "rb");
        fileObst= fopen("track10obst", "rb");
        timeleft = 375 ;
    }
    int n=0, j;

    // read all positions of bonus markers from @fileBonus
    fscanf(fileBonus, "%d", &n);
    int *markers ;
    markers = (int*)calloc(n*4, sizeof(int)) ;
    int i=0;
    fscanf(fileBonus, "%d", &j) ;
    while(!feof(fileBonus)){
        markers[i++] = j;
        fscanf(fileBonus, "%d", &j) ;
    }
    fclose(fileBonus);
    bonus.setMarkers(markers, n);
    free(markers) ;
    if(mode == 2){// read all positions of bonus obstracles from @fileObst if hard mode is selected

        fscanf(fileObst, "%d", &n);
        int *obst ;
        obst = (int*)calloc(n*4, sizeof(int)) ;
        fscanf(fileObst, "%d", &j) ;
        i = 0 ;
        while(!feof(fileObst)){
            obst[i++] = j;
            fscanf(fileObst, "%d", &j) ;
        }
        fclose(fileObst);
        bonus.setObstacles(obst, n);
        free(obst) ;
    }
    // get initial position of bike
    input >> this->inifx ;
    input >> this->inifz ;
    input >> this->inibx  ;
    input>> this->inibz ;
    input.close();
}
/**
 * @brief gameWindow::initialiseGL sets various modes of the openGL which is required for the terrain and Texture to be render correctly on the screen
 */
void gameWindow::initializeGL(){
    qglClearColor(Qt::blue);
    glEnable(GL_DEPTH_TEST);
    glClearDepth(1) ;
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_TEXTURE_2D);

    terrain.readBMP(track, 40) ;
    terrain.genTexture(tracktex) ;
    bike.readObj("Bike_Suzuki_Katana.obj");
    rider.readObj("rider.obj");
    // set initial position of bike
    physics.init(inifx, terrain.getHeight(inifx, inifz), inifz, inibx, terrain.getHeight(inibx, inibz), inibz, &terrain);

    bonus.Init(&terrain, "coin.obj", "hell_pig.obj", "hell_pig.obj", "cube.obj");
    doobs.Init(&terrain, &physics, bonus.markersList, bonus.noOfMarkers, bonus.obstaclePosition, bonus.numObstacles);
}

// used camera when game is paused
/**
 * @brief gameWindow::pausedCamera Sets the camera to different position and angle when the game is paused
 */
void gameWindow::pausedCamera(){
    gluLookAt(terrain.getWidth()/2.0, 600, terrain.getLength()/2.0, physics.xf, physics.yf, physics.zf, 1,0,0);
    glPushMatrix() ;
     Vector dir(physics.xf-physics.xb, physics.yf-physics.yb, physics.zf-physics.zb) ;
    glTranslatef(physics.zf, physics.yf+1, physics.zf) ;
    dir.normalize();
    float anglex = asin(dir.getX()/sqrt(dir.getX()*dir.getX()+dir.getZ()*dir.getZ()))*180/3.14 ;
    if(anglex >= 0){
        if(dir.getZ() < 0){
            anglex = 180-anglex ;
        }
    }
    else{
        if(dir.getZ() < 0){
            anglex = -(180+anglex) ;
        }
    }
    float angley = asin(dir.getY())*180/3.14 ;
    glRotatef(180,0,1,0) ;
    glRotatef(anglex, 0, 1, 0);
    glRotatef(angley, 1,0,0) ;
    bike.drawObj();
    glPopMatrix() ;
}
/**
 * @brief gameWindow::camera function which locates the camera and sets its view direction and up vector acoording to
 * data obtained from physicsEngine
 */
void gameWindow::camera(){

    Vector dir(physics.xf-physics.xb, physics.yf-physics.yb, physics.zf-physics.zb) ;
     dir.normalize() ;
     dir.scalarMul(20) ;
     int x = physics.xb-dir.getX() ;
     int z = physics.zb-dir.getZ() ;
     gluLookAt(physics.xb-dir.getX(), physics.yb+7, physics.zb-dir.getZ(), physics.xf, physics.yf+1, physics.zf, 0, 1, 0) ;
     // draw bike at physics.xf, physics.yf, physics.zf
     glPushMatrix() ;
     glTranslatef(physics.xf, physics.yf+1, physics.zf) ;
     dir.normalize();
     float anglex = asin(dir.getX()/sqrt(dir.getX()*dir.getX()+dir.getZ()*dir.getZ()))*180/3.14 ;
     if(anglex >= 0){
         if(dir.getZ() < 0){
             anglex = 180-anglex ;
         }
     }
     else{
         if(dir.getZ() < 0){
             anglex = -(180+anglex) ;
         }
     }
     float angley = asin(dir.getY())*180/3.14 ;
     glRotatef(180,0,1,0) ;
     glRotatef(anglex, 0, 1, 0);
     glRotatef(angley, 1,0,0) ;
     glPushMatrix();
     glRotatef(90, 0, 1,0);
     glScalef(1.5,1.5,1.5);
     //rider.drawObj();
     glPopMatrix();
     glScalef(1/100.0,1/100.0,1/100.0);
     bike.drawObj();
     glPopMatrix() ;
}
/**
 * @brief gameWindow::paintGL draws everything whichthe Game demands such as Texture Terrain Obstacles Object Bonuses etc
 */
void gameWindow::paintGL(){
    emit giveCoordinates(physics.xf, physics.yf, physics.zf);
    makeCurrent();

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT) ;
    glMatrixMode(GL_MODELVIEW) ;
    glLoadIdentity();

    float light_position[] = {-0.5f, 0.8f, 0.1f, 0.0f} ;
    float mat_shininess[] = {128} ;
    float light_ambient[] = {1,1,1,1} ;
     GLfloat cyan[] = {0.f, .8f, .8f, 1.f};
     float light_diffuse[] = {1,0,0,1} ;

     glLightfv(GL_LIGHT0, GL_POSITION, light_position) ;
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient) ;
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, cyan);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
   // if(!paused)
        camera() ;
    //else
      //  pausedCamera();

    terrain.renderTerrain(); // draw terrain

    bonus.drawAllMarkers(); // display all bonus points on terrain
    bonus.drawAllObstacles();

    swapBuffers();
}
/**
 * @brief gameWindow::getkeyPressEvent sets flags corresponding to the keyboard buttons=1 when it is pressed
 * @param evt Key event parameter of the Qt
 */
void gameWindow::getkeyPressEvent(QKeyEvent *evt){
    if(evt->key() == Qt::Key_Escape && timeleft > 0){
        paused = !paused ;
    }
    if(paused) return ; // don't update if game is paused

    // change state(to 1) of @keysPressed corresponding to pressed key
    switch(evt->key()){
    case Qt::Key_W:
        keysPressed[0] = 1 ;
        break;
    case Qt::Key_S:
        keysPressed[1] = 1 ;
        break;
    case Qt::Key_A:
        keysPressed[2] = 1 ;
        break;
    case Qt::Key_D:
        keysPressed[3] = 1 ;
        break;
    case Qt::Key_F:
        cout << "front" << (physics.xf) << " " << (physics.yf) << " " << physics.zf << "\n" ;
        cout << "back" << (physics.xb) << " " << (physics.yb) << " " << physics.zb << "\n" ;
        break ;
    }

    update1() ; // update every time key is pressed
}
/**
 * @brief gameWindow::getkeyReleaseEvent sets flags corresponding to the keyboard buttons=0 when it is released
 * @param evt Key event parameter of the Qt
 */
void gameWindow::getkeyReleaseEvent(QKeyEvent *evt){
    if(paused) return ;// don't update if game is paused

    // change state(to 0) of @keysPressed corresponding to pressed key
    switch(evt->key()){
    case Qt::Key_W:
        keysPressed[0] = 0 ;
        break;
    case Qt::Key_S:
        keysPressed[1] = 0 ;
        break;
    case Qt::Key_A:
        keysPressed[2] = 0 ;
        break;
    case Qt::Key_D:
        keysPressed[3] = 0 ;
        break;
    }

    update1() ; // update every time key is released
}
/**
 * @brief gameWindow::update1 calls Keyboard functions of the Physics Engine According to the flags set by the pressed and released functions
 *                              and also bonus collection, collision and updates points
 */
void gameWindow::update1(){
    if(paused){
        stringstream ss ;
        ss << "Bonus Points Left:- " << (bonus.noOfMarkers-doobs.numBonusCollect) << "\nTime Left:- " << this->timeleft ;
        // give information to paused menu to display(number of bonus and time left)
        emit giveInfo((char *)ss.str().c_str());
        return ; // don't update if game is paused
    }


    if(keysPressed[0]){
        physics.doPhysics(Qt::Key_W);
    }
    if(keysPressed[1]){
        physics.doPhysics(Qt::Key_S);
    }
    if(keysPressed[2]){
        physics.doPhysics(Qt::Key_A);
        updateGL() ;
        physics.doPhysics(Qt::Key_A);
    }
    if(keysPressed[3]){
        physics.doPhysics(Qt::Key_D);
        updateGL() ;
        physics.doPhysics(Qt::Key_D);
    }

    physics.doPhysics(122221);

    emit speedChanged(physics.velocity.magnitude());

    doobs.doBonusCollect() ; // check collision with bonus markers
    if(mode == 2||isPracticeMode)
        doobs.collisionIfCollides();

    emit givePoints(doobs.numBonusCollect);
    updateGL() ;
}
/**
 * @brief gameWindow::emmitTimeLeft Emits the time left in the Game to the Time left widget
 */
void gameWindow::emmitTimeLeft(){
    if(paused) return ;// don't update if game is paused

    if(timeleft > 0 && !isPracticeMode) //no decreament in time when game is paused
        timeleft-- ;

    emit giveTimeLeft(timeleft);

    if(timeleft <= 0){ // pause if time is over
        emit timeOver(true);
        paused = true ;
    }
}
/**
 * @brief gameWindow::resizeGL resizes the window
 * @param w width of the screen recieved when screen resize or moves
 * @param h height of the screen recieved when the screen resize or moves
 */
void gameWindow::resizeGL(int w, int h){
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, w/h, 0.1, 500);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

/**
 * @brief gameWindow::~gameWindow destructs all the data and pointers used, while the game was on, after quitting
 */
gameWindow::~gameWindow()
{
    delete ui;
    delete mainLoopTimer ;
    delete clockTimer ;
    delete track;
    delete tracktex ;
}
