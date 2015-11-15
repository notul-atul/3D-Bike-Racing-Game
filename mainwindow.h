#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_quit_clicked();

    void on_newGame_clicked();

    void on_freeRome_clicked();

    void on_load_clicked();

    void on_options_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
