/**
 * @author Durgesh
 * @date 5 Sep-2013
 * @file newprofile.cpp
 */
#include "newprofile.h"
#include "ui_newprofile.h"
#include"mainwindow.h"
#include"selecttrack.h"
#include"player.h"
#include<iostream>
#include<fstream>
#include<QErrorMessage>
#include<string.h>
using namespace std ;
/**
 * @brief NewProfile::NewProfile default constructor of the Qt
 * @param parent default QWidget parameter of the Qt
 */
NewProfile::NewProfile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewProfile)
{
    ui->setupUi(this);
    mode = 1 ;
    connect(ui->lineEdit, SIGNAL(textChanged(QString)), this, SLOT(enableStart(QString)));
}
/**
 * @brief NewProfile::~NewProfile destructor which deletes the ui of the NewProfile window
 */
NewProfile::~NewProfile()
{
    delete ui;
}
/**
 * @brief NewProfile::on_back_clicked closes current window and reopens MainWindow
 */
void NewProfile::on_back_clicked()
{
    MainWindow *mainWindow = new MainWindow();
    mainWindow->setAttribute(Qt::WA_QuitOnClose);
    mainWindow->show();
    this->close() ;
}

/**
 * @brief isValidName checks if the entered name alredy exits or not
 * @param name Name of the person Entered
 * @return ture if name doesnot exits else false
 */
bool isValidName(char *name){
    Player player ;
    ifstream in ;
    in.open("players", ios::in);
    if(!in) return true ;
    while(!in.eof()){
        in.read((char *)&player, sizeof(Player)) ;
        if(strcmp(player.getName(), name) == 0){
            in.close();
            return false ;
        }
    }
    in.close();
    return true ;
}
/**
 * @brief NewProfile::on_start_clicked at first checks if name alredy exists or not. If it exists the display error message else saves the entered
 *name into the fle and starts the Game
 */
void NewProfile::on_start_clicked()
{
    // display error message if profile is already exist
    if(!isValidName((char *)ui->lineEdit->text().toStdString().c_str())){
        ui->start->setEnabled(false);
        QErrorMessage error ;
        error.showMessage("Profile Already Exist");
        error.exec() ;
        return ;
    }

    ofstream out ;
    Player player((char *)ui->lineEdit->text().toStdString().c_str()) ;
    out.open("players", ios::app) ;
    out.write((char *)&player, sizeof(Player)) ;
    out.close();
    SelectTrack *selectTrack = new SelectTrack(player, false, mode) ;
    selectTrack->setAttribute(Qt::WA_QuitOnClose);
    selectTrack->show();
    this->close() ;
}

/**
 * @brief NewProfile::enableStart Enables the Disabled Start Button if a new Name is Entered
 * @param text value of the entered name
 */
void NewProfile::enableStart(QString text){
    if(text.length() != 0)
        ui->start->setEnabled(true);
    else
        ui->start->setEnabled(false);
}

/**
 * @brief NewProfile::on_easy_clicked Enters into the Easy Mode according to the option selected
 */
void NewProfile::on_easy_clicked()
{
    ui->easy->setChecked(true);
    ui->hard->setChecked(false);
    mode = 1 ;
}
/**
 * @brief NewProfile::on_hard_clicked Enters into the Easy Mode according to the option selected
 */
void NewProfile::on_hard_clicked()
{
    ui->easy->setChecked(false);
    ui->hard->setChecked(true);
    mode = 2 ;
}
