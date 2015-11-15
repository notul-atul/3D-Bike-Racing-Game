// header to display pause menu
#ifndef PAUSEDMENU_H
#define PAUSEDMENU_H

#include <QDialog>
#include<QKeyEvent>

namespace Ui {
class PausedMenu;
}

class PausedMenu : public QDialog
{
    Q_OBJECT
    
public:
    explicit PausedMenu(QWidget *parent = 0);
    ~PausedMenu();
    bool quit ; // true if Yes button is clicked, false otherwise
signals:
    /*
     * connected to a getPausedMenuResponce() slot of HUD
     * class to get responce(weather player wants to quit or not) of pause menu
     */
    void actionPerformed() ;
private slots:
    void on_yes_clicked(); // "Yes" button's slot
    void on_no_clicked(); // "No" button's slot
    /* get current status of game (how much time left and how many bonus points collected)
     * from giveInfo(char *) SIGNAL of GameWindow class in string form and display it
     */
    void getInfo(char *) ;

private:
    Ui::PausedMenu *ui;
};

#endif // PAUSEDMENU_H
