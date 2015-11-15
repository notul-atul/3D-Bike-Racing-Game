//
#ifndef SPEEDOMETER_H
#define SPEEDOMETER_H

#include <QWidget>
#include<QPainter>
#include<QPaintEvent>

class SpeedoMeter : public QWidget
{
    Q_OBJECT
public:
    explicit SpeedoMeter(QWidget *parent = 0);
    
protected:
    void paintEvent(QPaintEvent *) ;
signals:
    
public slots:
    /*
     * get velocity from GameWindow and display speedo meter
     */
    void getVelocity(double vel) ;

private:
    float velocity ;
};

#endif // SPEEDOMETER_H
