#include "options.h"
#include "ui_options.h"
#include"mainwindow.h"

Options::Options(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Options)
{
    ui->setupUi(this);
}

Options::~Options()
{
    delete ui;
}

void Options::on_pushButton_clicked()
{
    MainWindow *window = new MainWindow ;
    window->setAttribute(Qt::WA_QuitOnClose);
    window->show();
    this->close();
}
