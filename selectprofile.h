// header to create new profile(when new game is started)
#ifndef SELECTPROFILE_H
#define SELECTPROFILE_H

#include <QDialog>
#include"player.h"

namespace Ui {
class SelectProfile;
}

class SelectProfile : public QDialog
{
    Q_OBJECT
    
public:
    explicit SelectProfile(QWidget *parent = 0);
    ~SelectProfile();
    
private slots:

    void on_back_clicked();

    void on_load_clicked();

    void on_profilesNames_currentIndexChanged(int index);

    void on_delete_2_clicked();

    void on_easy_clicked();

    void on_hard_clicked();

private:
    Ui::SelectProfile *ui;
    void loadProfiles() ;
    int mode ; // easy or hard
};

#endif // SELECTPROFILE_H
