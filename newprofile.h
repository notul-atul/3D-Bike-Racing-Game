#ifndef NEWPROFILE_H
#define NEWPROFILE_H

#include <QDialog>

namespace Ui {
class NewProfile;
}

class NewProfile : public QDialog
{
    Q_OBJECT
    
public:
    explicit NewProfile(QWidget *parent = 0);
    ~NewProfile();
    
private slots:
    void on_back_clicked();

    void enableStart(QString) ; // enable start button if valid profile name is entered
    void on_start_clicked();

    void on_easy_clicked();

    void on_hard_clicked();

private:
    Ui::NewProfile *ui;
    int mode ; // easy or hard
};

#endif // NEWPROFILE_H
