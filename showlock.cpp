#include "showlock.h"
#include "ui_showlock.h"

showLock::showLock(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::showLock)
{
    ui->setupUi(this);
}

showLock::~showLock()
{
    delete ui;
}
