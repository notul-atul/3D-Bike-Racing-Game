/**
 *@file selectprofile.h
 *@author Durgesh
 *@date 8 Sep 2013
 */
#include "selectprofile.h"
#include "ui_selectprofile.h"
#include"mainwindow.h"
#include<fstream>
#include<iostream>
#include<stdio.h>
#include"selecttrack.h"
#include<sstream>
using namespace std ;

/**
 * @brief SelectProfile::SelectProfile default constructor of the Qt ui
 * @param parent default parameter of the Qt
 */
SelectProfile::SelectProfile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectProfile)
{
    ui->setupUi(this);
    ui->delete_2->setEnabled(false);
    ui->load->setEnabled(false);
    this->mode = 1 ;
    loadProfiles();
}
/**
 * @brief SelectProfile::~SelectProfile default destructor of the Qt ui
 */
SelectProfile::~SelectProfile()
{
    delete ui;
}

/**
 * @brief SelectProfile::loadProfiles gives option to select profile of the user which was previously created
 */
void SelectProfile::loadProfiles(){
    ifstream in ;
    in.open("players", ios::in);
    if(!in) return ;
    Player player ;
    in.read((char *)&player, sizeof(Player)) ;
    while(!in.eof()){
        ui->profilesNames->addItem(player.getName());
        in.read((char *)&player, sizeof(Player)) ;
        if(in.eof()) break ;
    }
    in.close();
}
/**
 * @brief SelectProfile::on_back_clicked returns the contol to the MainMenu
 */
void SelectProfile::on_back_clicked()
{
    MainWindow *window = new MainWindow ;
    window->setAttribute(Qt::WA_QuitOnClose);
    window->show();
    this->close();
}
/**
 * @brief SelectProfile::on_load_clicked loads all the saved data for that user and returns control to the track select window. There user can select
 *all the unlocked tracks
 */
void SelectProfile::on_load_clicked()
{
    ifstream in ;
    in.open("players", ios::in);
    // go to selected profile in file and load entire information
    in.seekg((ui->profilesNames->currentIndex()-1)*sizeof(Player), ios::beg) ;
    Player player ;
    in.read((char *)&player, sizeof(Player)) ;
    in.close();

    SelectTrack *selecttrack = new SelectTrack(player, false, mode) ;
    selecttrack->setAttribute(Qt::WA_QuitOnClose);
    selecttrack->show();
    this->close();
}
/**
 * @brief SelectProfile::on_profilesNames_currentIndexChanged Enables the Select and delete button if some user profile is selected
 * @param index A parameter which determines whether some profile at that time is selected or not
 */
void SelectProfile::on_profilesNames_currentIndexChanged(int index)
{
    // enable load and delete button on profile selection
    if(index != 0){
        ui->delete_2->setEnabled(true);
        ui->load->setEnabled(true);
        ui->desc->setText("");
        stringstream ss ;
        Player player ;
        ifstream in ;
        in.open("players", ios::in);
        in.seekg((index-1)*sizeof(Player), ios::beg) ;
        in.read((char *)&player, sizeof(Player)) ;
        ss << "    Description\n  Points : " << player.gettotalScore() << "\n" << "  Tracks : " << player.getnoOfUnlockTracks();
        string str = ss.str() ;
        ui->desc->setText(QString(str.c_str()));
    }
    // disable load and delete button when no profile is selected
    else{
        ui->delete_2->setEnabled(false);
        ui->load->setEnabled(false);
        stringstream ss ;
        ss << "  No Profile\n   Selected" ;
        string str = ss.str() ;
        ui->desc->setText(QString(str.c_str()));
    }
}
/**
 * @brief SelectProfile::on_delete_2_clicked delets all the data associated with that user
 */
void SelectProfile::on_delete_2_clicked()
{
    // delete selected profile from file
    ifstream in ;
    ofstream out ;
    in.open("players");
    out.open("tmpplayers");
    Player player ;
    int i = 1 ;
    if(!in) return ;
    in.read((char *)&player, sizeof(Player)) ;
    while(!in.eof()){
        if(ui->profilesNames->currentIndex() != i){
            out.write((char *)&player, sizeof(Player)) ;
        }
        i++;
        in.read((char *)&player, sizeof(Player)) ;
        if(in.eof()) break ;
    }
    in.close();
    out.close();
    remove("players") ;
    rename("tmpplayers", "players");
    ui->profilesNames->removeItem(ui->profilesNames->currentIndex());
}
/**
 * @brief SelectProfile::on_easy_clicked sets easy mode flag to True
 */
void SelectProfile::on_easy_clicked()
{
    ui->easy->setChecked(true);
    ui->hard->setChecked(false);
    mode = 1 ;
}
/**
 * @brief SelectProfile::on_hard_clicked sets hard mode flag to True
 */
void SelectProfile::on_hard_clicked()
{
    ui->easy->setChecked(false);
    ui->hard->setChecked(true);
    mode = 2 ;
}
