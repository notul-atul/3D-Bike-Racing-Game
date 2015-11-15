/**
 *@file mainwindow.cpp
 *@author Durgesh
 *@date 6 Sep 2013
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newprofile.h"
#include<iostream>
#include"selecttrack.h"
#include"player.h"
#include"selectprofile.h"
#include"options.h"
using namespace  std;
/**
 * @brief MainWindow::MainWindow default constructor of the Qt mainwindow
 * @param parent default parameter of the Qt MainWindow constructor
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
/**
 * @brief MainWindow::~MainWindow default destructor
 */
MainWindow::~MainWindow()
{
    delete ui;
}
/**
 * @brief MainWindow::on_newGame_clicked opens a window to create a new profile of the user
 */
void MainWindow::on_newGame_clicked()
{
    NewProfile *newProfile = new NewProfile() ;
    newProfile->setAttribute(Qt::WA_QuitOnClose);
    newProfile->show();
    this->close() ;
}
/**
 * @brief MainWindow::on_quit_clicked quits the entire game
 */
void MainWindow::on_quit_clicked(){
    this->destroy();
}
/**
 * @brief MainWindow::on_freeRome_clicked Enters into the practice mode of the Game
 */
void MainWindow::on_freeRome_clicked(){
    Player player ;
    SelectTrack *selecttrack = new SelectTrack(player, true, 2) ;
    selecttrack->setAttribute(Qt::WA_QuitOnClose);
    selecttrack->show();
    this->close() ;
}
/**
 * @brief MainWindow::on_load_clicked Opens the window to load the alredy created profile of user
 */
void MainWindow::on_load_clicked()
{
    SelectProfile *selectprofile = new SelectProfile() ;
    selectprofile->setAttribute(Qt::WA_QuitOnClose);
    selectprofile->show();
    this->close();
}
/**
 * @brief MainWindow::on_options_clicked Displays the Key controls functionality
 */
void MainWindow::on_options_clicked()
{
    Options *option = new Options ;
    option->setAttribute(Qt::WA_QuitOnClose);
    option->show();
    this->close();
}
