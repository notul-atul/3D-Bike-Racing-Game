// header to show preview of tracks
#ifndef TRACKPREVIEW_H
#define TRACKPREVIEW_H
#include<qt4/QtOpenGL/qgl.h>
#include<QWidget>
#include<GL/glu.h>
#include<QPainter>
#include<QPaintEvent>
#include"terrain.h"

class TrackPreview : public QGLWidget
{
    Q_OBJECT
public:
    TrackPreview(QWidget *parent = 0);
    TrackPreview(char *track, char *tracktex, QWidget *parent = 0) ;
    ~TrackPreview() ;
protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
private:
    Terrain terrain ;
    char *track, *tracktex ; // file name of terrain and texture
};

#endif // TRACKPREVIEW_H
