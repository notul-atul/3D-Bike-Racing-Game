#ifndef HUD_H
#define HUD_H

#include <QWidget>
#include<qt4/QtOpenGL/qgl.h>
#include<QKeyEvent>
#include"gamewindow.h"
#include"pausedmenu.h"
#include"trackmap.h"
#include"player.h"
#include<string.h>

namespace Ui {
class HUD;
}

class HUD : public QWidget
{
    Q_OBJECT
    
public:
    explicit HUD(gameWindow *display, Player player, bool isPracticeMode, QWidget *parent = 0);
    ~HUD();

signals:
    /*
     * emit KeyEvent whenever key is pressed
     * connected to GameWindow.getkeyPressEvent & GameWindow.getkeyReleaseEvent
     * to get key that player press and performe task accordingly
     */
    void givekeyPressEvent(QKeyEvent *) ;
    void givekeyReleaseEvent(QKeyEvent *) ;
public slots:
    /*
     *get player responce to pause menu(wants to quit or not) by signal PausedMenu.actionPerformed()
     */
    void getPausedMenuResponce();
    
protected:
    void keyPressEvent(QKeyEvent *) ;
    void keyReleaseEvent(QKeyEvent *);
    void closeEvent(QCloseEvent *) ;// save game on quit
private:
    Ui::HUD *ui;
    gameWindow *display ; // display game
    PausedMenu *pausedMenu ;
    bool paused ;
    Player player ; // information of player currently playing
    bool isPracticeMode ;
};

#endif // HUD_H
