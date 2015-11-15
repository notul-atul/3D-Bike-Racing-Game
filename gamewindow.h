#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include<qt4/QtOpenGL/QGLWidget>
#include<qt4/QtOpenGL/qgl.h>
#include<GL/glu.h>
#include<QKeyEvent>
#include<QTimer>
#include"objectRender.h"
#include"GameEngine.h"
#include"displayobstaclesbonuses.h"
#include"obstaclesbonuses.h"
#include<fstream>

namespace Ui {
class gameWindow;
}

class gameWindow : public QGLWidget
{
    Q_OBJECT
    
public:
    explicit gameWindow(bool isPractiseMode, int mode, QWidget *parent = 0);
    ~gameWindow();
    void setTrack(char *track, char *tracktex) ; // set current track (selected by player before starting game)
    char* getTrack() ;
    char* getTexture() ;
    GameEngine getPhysics() ;// return instance of physics engine currently using
    int getNoOfPoints() ; // return no of bonus points collected

signals:
    // connected to HUD to display
    void speedChanged(double speed) ;
    void giveTimeLeft(int) ;

    /*
    * emit how many bonus points collected to hud for displaying on screen and
    * save in profile of current player if it is not practice mode
    */

    void givePoints(int) ;
    void giveCoordinates(int, int, int) ;
    // emit when time is over (not emit in practice mode)
    void timeOver(bool) ;
    /*
     * give information (how many points are remaning on track and time left in form of string)
     * to show in pause menu when game is paused
     */
    void giveInfo(char *info) ;

public slots:
    // get key event from key event of HUD
    void getkeyPressEvent(QKeyEvent *) ;
    void getkeyReleaseEvent(QKeyEvent *);
    
protected:
    void initializeGL();
    void resizeGL(int w, int h) ;
    void paintGL();

private:
    Ui::gameWindow *ui;
    Terrain terrain ;
    GameEngine physics ;
    Object bike, rider ;
    int timeleft ;
    /*
     * mainLoopTimer is used for updating game mainLoop after every 1 milisecond
     *
     * clockTimer is used as stop watch
     *
     */
    QTimer *mainLoopTimer, *clockTimer ;
    int keysPressed[4] ; //keep track of states of keys for mutiple input key hendling
    void camera() ; // camera function which draw bike and rider and keep camera behind bike
    void pausedCamera() ; // camera when game is paused
    char *track, *tracktex ; // Name of track and track texture file
    bool paused ;
    DisplayObstaclesBonuses bonus ; // for drawing bonus on terrain
    ObstaclesBonuses doobs ; // for collision heandling and bonus collection
    float inifx, inifz, inibx, inibz ; // initial bike position when game start it is different for every track
    int array[40][4], a ;
    ofstream out ;
    bool isPracticeMode ;
    int mode ;
private slots:
    void update1() ; // update physics engine and graphics reandring
    void emmitTimeLeft() ; // // emit signal @giveTimeLeft(int) hud will catch and display it
};

#endif // GAMEWINDOW_H
