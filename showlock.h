#ifndef SHOWLOCK_H
#define SHOWLOCK_H

#include <QWidget>

namespace Ui {
class showLock;
}

class showLock : public QWidget
{
    Q_OBJECT
    
public:
    explicit showLock(QWidget *parent = 0);
    ~showLock();
    
private:
    Ui::showLock *ui;
};

#endif // SHOWLOCK_H
