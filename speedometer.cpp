/**
  *@file speedometer.cpp
  *@author Durgesh
  *@date 5 Sep 2013
  */

#include "speedometer.h"
#include<math.h>

/**
 * @brief SpeedoMeter::SpeedoMeter default constructor of the Qt ui
 * @param parent default parameter of the Qt ui
 */
SpeedoMeter::SpeedoMeter(QWidget *parent) :
    QWidget(parent)
{
}

/**
 * @brief SpeedoMeter::paintEvent Draws the Speedometer on the Bottom Left of the Screen according to the Velocity Magnitude
 * It displays Speed as needle pointing to the Value of the speed on a calibrated semi-circle arc
 * @param evt default QPaintEvent pointer
 */
void SpeedoMeter::paintEvent(QPaintEvent *evt){
    // draw spedometer
    if(velocity > 180) velocity = 180 ;
    QPainter painter(this) ;
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(QPen(Qt::blue, 2, Qt::SolidLine, Qt::RoundCap));
    painter.setBrush(QBrush(Qt::blue, Qt::Dense7Pattern));
    painter.drawPie(10, 10, 160, 160, 0 * 16, 180 * 16);
    painter.setPen(QPen(Qt::red, 1, Qt::SolidLine, Qt::RoundCap));
    painter.drawLine(84, 90, 88-60*cos(velocity*3.14/180), 90-60*sin(velocity*3.14/180));
    painter.drawLine(92, 90, 88-65*cos(velocity*3.14/180), 90-65*sin(velocity*3.14/180));
}
/**
 * @brief SpeedoMeter::getVelocity sets the value of the speeed to which needle will points to
 * @param vel Tells the Speed of the bike
 */
void SpeedoMeter::getVelocity(double vel){
    this->velocity = vel ;
    repaint();
}
