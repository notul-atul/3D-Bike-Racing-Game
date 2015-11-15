/**
 * @file selecttrack.h
 * @author Durgesh
 * @date 8 Sep 2013
 */
#include "selecttrack.h"
#include "ui_selecttrack.h"
#include"gamewindow.h"
#include"hud.h"
#include"QLabel"
#include"mainwindow.h"
#include<iostream>
using namespace  std;
/**
 * @brief SelectTrack::SelectTrack Displays track selection windoow according to the Name of the player or Practice mode
 * @param player Name of the user which will play game
 * @param isPracticeMode tells whether practice mode is on or off
 * @param mode mode of the game i.e Easy or Hard
 * @param parent default QWidget parameter of the Qt
 */
SelectTrack::SelectTrack(Player player, bool isPracticeMode, int mode, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectTrack)
{
    ui->setupUi(this);
    this->isPracticeMode = isPracticeMode ;
    this->mode = mode;
    this->player = player ;

    // display preview of unlocked track(all tracks in practice mode)
    if(player.getnoOfUnlockTracks() >= 1 || isPracticeMode){
        TrackPreview *track1 = new TrackPreview("track1.bmp", "track1tex.bmp", this) ;
        QHBoxLayout *layout1 = new QHBoxLayout(this) ;
        layout1->addWidget(track1);
        ui->Track_1->setLayout(layout1);
    }
    else{
        ui->Track_1->setStyleSheet("background-image:url(lock.jpg)");
    }

    if(player.getnoOfUnlockTracks() >= 2 || isPracticeMode){
        TrackPreview *track2 = new TrackPreview("track2.bmp", "track2tex.bmp", this) ;
        QHBoxLayout *layout2 = new QHBoxLayout(this) ;
        layout2->addWidget(track2);
        ui->Track_2->setLayout(layout2);
    }
    else{
        ui->Track_2->setStyleSheet("background-image:url(lock.jpg)");
    }

    if(player.getnoOfUnlockTracks() >= 3 || isPracticeMode){
        TrackPreview *track3 = new TrackPreview("track3.bmp", "track3tex.bmp", this) ;
        QHBoxLayout *layout3 = new QHBoxLayout(this) ;
        layout3->addWidget(track3);
        ui->Track_3->setLayout(layout3);
    }
    else{
        ui->Track_3->setStyleSheet("background-image:url(lock.jpg)");
    }

    if(player.getnoOfUnlockTracks() >= 4 || isPracticeMode){
        TrackPreview *track4 = new TrackPreview("track4.bmp", "track4tex.bmp", this) ;
        QHBoxLayout *layout4 = new QHBoxLayout(this) ;
        layout4->addWidget(track4);
        ui->Track_4->setLayout(layout4);
    }
    else{
        ui->Track_4->setStyleSheet("background-image:url(lock.jpg)");
    }

    if(player.getnoOfUnlockTracks() >= 5 || isPracticeMode){
        TrackPreview *track5 = new TrackPreview("track5.bmp", "track5tex.bmp", this) ;
        QHBoxLayout *layout5 = new QHBoxLayout(this) ;
        layout5->addWidget(track5);
        ui->Track_5->setLayout(layout5);
    }
    else{
        ui->Track_5->setStyleSheet("background-image:url(lock.jpg)");
    }
    if(player.getnoOfUnlockTracks() >= 6 || isPracticeMode){
        TrackPreview *track6 = new TrackPreview("track6.bmp", "track6tex.bmp", this) ;
        QHBoxLayout *layout6 = new QHBoxLayout(this) ;
        layout6->addWidget(track6);
        ui->Track_6->setLayout(layout6);
    }
    else{
        ui->Track_6->setStyleSheet("background-image:url(lock.jpg)");
    }
    if(player.getnoOfUnlockTracks() >= 7 || isPracticeMode){
        TrackPreview *track7 = new TrackPreview("track7.bmp", "track7tex.bmp", this) ;
        QHBoxLayout *layout7 = new QHBoxLayout(this) ;
        layout7->addWidget(track7);
        ui->Track_7->setLayout(layout7);
    }
    else{
        ui->Track_7->setStyleSheet("background-image:url(lock.jpg)");
    }
    if(player.getnoOfUnlockTracks() >= 8 || isPracticeMode){
        TrackPreview *track8 = new TrackPreview("track8.bmp", "track8tex.bmp", this) ;
        QHBoxLayout *layout8 = new QHBoxLayout(this) ;
        layout8->addWidget(track8);
        ui->Track_8->setLayout(layout8);
    }
    else{
        ui->Track_8->setStyleSheet("background-image:url(lock.jpg)");
    }
    if(player.getnoOfUnlockTracks() >= 9 || isPracticeMode){
        TrackPreview *track9 = new TrackPreview("track9.bmp", "track9tex.bmp", this) ;
        QHBoxLayout *layout9 = new QHBoxLayout(this) ;
        layout9->addWidget(track9);
        ui->Track_9->setLayout(layout9);
    }
    else{
        ui->Track_9->setStyleSheet("background-image:url(lock.jpg)");
    }
    if(player.getnoOfUnlockTracks() >= 10 || isPracticeMode){
        TrackPreview *track10 = new TrackPreview("track10.bmp", "track10tex.bmp", this) ;
        QHBoxLayout *layout10 = new QHBoxLayout(this) ;
        layout10->addWidget(track10);
        ui->Track_10->setLayout(layout10);
    }
    else{
        ui->Track_10->setStyleSheet("background-image:url(lock.jpg)");
    }
}
/**
 * @brief SelectTrack::~SelectTrack default destructor of the Qt ui
 */
SelectTrack::~SelectTrack()
{
    delete ui;
}
/**
 * @brief SelectTrack::on_pushButton_clicked loads texture and terrain file according to the track selected and "practice mode"
 */
void SelectTrack::on_pushButton_clicked()
{
    // don't start game if selected track is not unlocked
    if(ui->toolBox->currentIndex()+1 > player.getnoOfUnlockTracks() && !isPracticeMode) return ;
    gameWindow *window = new gameWindow(isPracticeMode, mode);
    window->setAttribute(Qt::WA_QuitOnClose);
    if(ui->toolBox->currentIndex() == 0)
        window->setTrack("track1.bmp", "track1tex.bmp");
    else if(ui->toolBox->currentIndex() == 1)
        window->setTrack("track2.bmp", "track2tex.bmp");
    else if(ui->toolBox->currentIndex() == 2)
        window->setTrack("track3.bmp", "track3tex.bmp");
    else if(ui->toolBox->currentIndex() == 3)
        window->setTrack("track4.bmp", "track4tex.bmp");
    else if(ui->toolBox->currentIndex() == 4)
        window->setTrack("track5.bmp", "track5tex.bmp");
    else if(ui->toolBox->currentIndex() == 5)
        window->setTrack("track6.bmp", "track6tex.bmp");
    else if(ui->toolBox->currentIndex() == 6)
        window->setTrack("track7.bmp", "track7tex.bmp");
    else if(ui->toolBox->currentIndex() == 7)
        window->setTrack("track8.bmp", "track8tex.bmp");
    else if(ui->toolBox->currentIndex() == 8)
        window->setTrack("track9.bmp", "track9tex.bmp");
    else
        window->setTrack("track10.bmp", "track10tex.bmp");
    HUD *hud = new HUD(window, player, isPracticeMode) ;
    hud->setAttribute(Qt::WA_QuitOnClose);
    hud->show();
    this->close();
}
/**
 * @brief SelectTrack::on_toolBox_currentChanged
 * @param index
 */
void SelectTrack::on_toolBox_currentChanged(int index)
{

}
/**
 * @brief SelectTrack::on_back_clicked returns the control to the MainMenu
 */
void SelectTrack::on_back_clicked()
{
    MainWindow *w = new MainWindow();
    w->setAttribute(Qt::WA_QuitOnClose);
    w->show();
    this->close();
}
