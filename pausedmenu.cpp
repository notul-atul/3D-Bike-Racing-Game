/**
 *@file pausedmenu.cpp
 *@author Durgesh
 *@date 6 Sep 2013
 */
#include "pausedmenu.h"
#include "ui_pausedmenu.h"

/**
 * @brief PausedMenu::PausedMenu default constructor of the Qt ui
 * @param parent default parameter of the Qt ui
 */
PausedMenu::PausedMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PausedMenu)
{
    ui->setupUi(this);
}
/**
 * @brief PausedMenu::~PausedMenu default destructor
 */
PausedMenu::~PausedMenu()
{
    delete ui;
    this->quit = true ;
}
/**
 * @brief PausedMenu::on_yes_clicked returns the control to the main menu
 */
void PausedMenu::on_yes_clicked()
{
    this->quit = true ;
    emit actionPerformed();
    this->hide();
}
/**
 * @brief PausedMenu::getInfo displays the curent status of the game
 * @param info information of the satus of the current game
 */
void PausedMenu::getInfo(char *info){
    // display information on pause menu
    ui->pauseinfo->setText(QString(info));
}
/**
 * @brief PausedMenu::on_no_clicked resume the game
 */
void PausedMenu::on_no_clicked()
{
    this->quit = false ;
    emit actionPerformed();
    this->hide();
}
