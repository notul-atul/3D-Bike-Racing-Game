/*
 * objectRender.h
 *
 *  Created on: 11-Aug-2013
 *      Author: DURGESH
 */
// header for object rendring
#ifndef OBJECTRENDER_H_
#define OBJECTRENDER_H_
#include"glm.h"
class Object{
private:
    GLMmodel *model ;
    unsigned int textureID ; // object texture
    bool isDisplayListCreated ;
    int displayListID ;
public:
    Object() ;
    void readObj(char *filename) ;
    void drawObj() ;
    ~Object() ;
};
#endif /* OBJECTRENDER_H_ */
