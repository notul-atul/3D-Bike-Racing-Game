#ifndef TRACKMAP_H
#define TRACKMAP_H

#include <QWidget>
#include<qt4/QtOpenGL/QGLWidget>
#include<qt4/QtOpenGL/qgl.h>
#include"physicsEngine2.h"
#include"terrain.h"
#include"objectRender.h"

namespace Ui {
class TrackMap;
}

class TrackMap : public QGLWidget
{
    Q_OBJECT
    
public:
    explicit TrackMap(char *track, char *texture, PhysicsEngine2 physics, QWidget *parent = 0);
    ~TrackMap();
protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
public slots:
    void getCoordinates(int, int, int) ;
private:
    Ui::TrackMap *ui;
    char *track, *texture ;
    Object obj ;
    Terrain terrain ;
    PhysicsEngine2 physics ;
};

#endif // TRACKMAP_H
