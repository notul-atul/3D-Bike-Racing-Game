#include<QHBoxLayout>
#include "hud.h"
#include "ui_hud.h"
#include"mainwindow.h"
#include<fstream>
#include<stdio.h>
#include<QMessageBox>
#include<string.h>
using namespace std ;

HUD::HUD(gameWindow *display, Player player, bool isPracticeMode, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HUD)
{
    ui->setupUi(this);
    this->display = display ;
    this->player = player ;
    this->isPracticeMode = isPracticeMode ;

    ui->Player_Name->setText(QString((player.getName()))); // display player name on hud

    // set display window
    QHBoxLayout *layout = new QHBoxLayout(this) ;
    layout->addWidget(display);
    ui->displayWindow->setLayout(layout);

    connect(this, SIGNAL(givekeyPressEvent(QKeyEvent*)), display, SLOT(getkeyPressEvent(QKeyEvent*)));
    // show speed on hud (on LCD Display on hud window)
    connect(display, SIGNAL(speedChanged(double)), ui->speed, SLOT(display(double))) ;
    // display bonus collected (on LCD Display on hud window)
    connect(display, SIGNAL(givePoints(int)), ui->points, SLOT(display(int))) ;
    // display time left(if not in practise mode)
    connect(display, SIGNAL(giveTimeLeft(int)), ui->timeellipsis, SLOT(display(int))) ;
    // give speed to @ui->speedoMeter to display speedo meter
    connect(display, SIGNAL(speedChanged(double)), ui->speedoMeter, SLOT(getVelocity(double))) ;
    connect(this, SIGNAL(givekeyReleaseEvent(QKeyEvent*)), display, SLOT(getkeyReleaseEvent(QKeyEvent*))) ;

    paused = false ;
    pausedMenu = new PausedMenu(this) ;

    connect(pausedMenu, SIGNAL(actionPerformed()), this, SLOT(getPausedMenuResponce())) ;
    connect(pausedMenu, SIGNAL(rejected()), this, SLOT(getPausedMenuResponce())) ;
    connect(display, SIGNAL(giveInfo(char*)), pausedMenu, SLOT(getInfo(char*)));
}

HUD::~HUD()
{
    delete ui;
    delete display ;
    delete pausedMenu ;
}
void HUD::getPausedMenuResponce(){
    if((!pausedMenu->quit)&&pausedMenu->Accepted){
       QKeyEvent *evt = new QKeyEvent(QEvent::KeyPress, Qt::Key_Escape, Qt::NoModifier) ;
       keyPressEvent(evt);
    }
    else if(pausedMenu->quit){
        MainWindow *window = new MainWindow ;
        window->setAttribute(Qt::WA_QuitOnClose);
        window->show(); // show main menu on quit
        this->close() ;
    }
}

void HUD::closeEvent(QCloseEvent *evt){
    if(this->isPracticeMode) evt->accept(); // do nothing if it is practice

    // otherwise save game and quit
        ifstream in ;
        ofstream out ;

        // unlock new track if all bonus points of current track is collected
        if(strcmp(display->getTrack(), "track1.bmp") == 0){
            if(display->getNoOfPoints() == 24 && player.getnoOfUnlockTracks() == 1){
                player.setnoOfUnlockTracks(player.getnoOfUnlockTracks()+1);
            }
        }
        else if(strcmp(display->getTrack(), "track2.bmp") == 0){
            if(display->getNoOfPoints() == 29 && player.getnoOfUnlockTracks() == 2){
                player.setnoOfUnlockTracks(player.getnoOfUnlockTracks()+1);
            }
        }
        else if(strcmp(display->getTrack(), "track3.bmp") == 0){
            if(display->getNoOfPoints() == 31 && player.getnoOfUnlockTracks() == 3){
                player.setnoOfUnlockTracks(player.getnoOfUnlockTracks()+1);
            }
        }
        else if(strcmp(display->getTrack(), "track4.bmp") == 0){
            if(display->getNoOfPoints() == 19 && player.getnoOfUnlockTracks() == 4){
                player.setnoOfUnlockTracks(player.getnoOfUnlockTracks()+1);
            }
        }
        else if(strcmp(display->getTrack(), "track5.bmp") == 0){
            if(display->getNoOfPoints() == 41 && player.getnoOfUnlockTracks() == 5){
                player.setnoOfUnlockTracks(player.getnoOfUnlockTracks()+1);
            }
        }
        else if(strcmp(display->getTrack(), "track6.bmp") == 0){
            if(display->getNoOfPoints() == 30 && player.getnoOfUnlockTracks() == 6){
                player.setnoOfUnlockTracks(player.getnoOfUnlockTracks()+1);
            }
        }
        else if(strcmp(display->getTrack(), "track7.bmp") == 0){
            if(display->getNoOfPoints() == 25 && player.getnoOfUnlockTracks() == 7){
                player.setnoOfUnlockTracks(player.getnoOfUnlockTracks()+1);
            }
        }
        else if(strcmp(display->getTrack(), "track8.bmp") == 0){
            if(display->getNoOfPoints() == 26 && player.getnoOfUnlockTracks() == 8){
                player.setnoOfUnlockTracks(player.getnoOfUnlockTracks()+1);
            }
        }
        else if(strcmp(display->getTrack(), "track9.bmp") == 0){
            if(display->getNoOfPoints() == 28 && player.getnoOfUnlockTracks() == 9){
                player.setnoOfUnlockTracks(player.getnoOfUnlockTracks()+1);
            }
        }

        // update player data in file ("players")
        Player pl ;
        out.open("tmpplayers", ios::out);
        in.open("players",ios::in);
        in.read((char *)&pl, sizeof(Player)) ;
        while(!in.eof()){
            if(strcmp(pl.getName(), player.getName()) == 0){
                player.settotalScore(player.gettotalScore()+display->getNoOfPoints());
                out.write((char *)&player, sizeof(Player)) ;
            }
            else{
                out.write((char *)&pl, sizeof(Player)) ;
            }
            in.read((char *)&pl, sizeof(Player)) ;
            if(in.eof()) break ;
        }
        in.close();
        out.close();
        remove("players") ;
        rename("tmpplayers", "players") ;

    evt->accept(); // quit
}

void HUD::keyPressEvent(QKeyEvent *evt){
    // give key event to GameWindow(this->display) to link with keyboard
    emit givekeyPressEvent(evt);
    // show(or hide) pause menu on [esc] key press
    if(evt->key() == Qt::Key_Escape){
        if(!paused){
            paused = true ;
            pausedMenu->show();
        }
        else{
            paused = false ;
        }
    }
}

void HUD::keyReleaseEvent(QKeyEvent *evt){
    emit givekeyReleaseEvent(evt);
}
