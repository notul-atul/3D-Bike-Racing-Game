// display preview of all tracks and start game with selected track
#ifndef SELECTTRACK_H
#define SELECTTRACK_H

#include <QDialog>
#include"player.h"
#include"showlock.h"
#include"trackpreview.h"
#include<QHBoxLayout>
namespace Ui {
class SelectTrack;
}

class SelectTrack : public QDialog
{
    Q_OBJECT
    
public:
    explicit SelectTrack(Player player, bool isPracticeMode, int mode, QWidget *parent = 0);
    ~SelectTrack();
    
private slots:

    void on_pushButton_clicked();

    void on_toolBox_currentChanged(int index);

    void on_back_clicked();

private:
    Ui::SelectTrack *ui;
    Player player ;
    bool isPracticeMode ;
    int mode ; // easy or hard
};

#endif // SELECTTRACK_H
