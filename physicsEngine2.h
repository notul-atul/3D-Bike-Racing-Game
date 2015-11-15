/*
 * physicsEngine2.h
 *
 *  Created on: 10-Aug-2013
 *      Author: DURGESH
 */
#include"terrain.h"

#define FRICTION_COEFICENT 0.8
#define GREAVITY 200.0
#define TIME 0.005

#ifndef PHYSICSENGINE2_H_
#define PHYSICSENGINE2_H_
class PhysicsEngine2{
private:
    Terrain *terrain ;
    Vector velocity ;
public:
    float fxco, fyco, fzco, bxco, byco, bzco ; //front and back x,y,z coordinates of body
    PhysicsEngine2() ;
    PhysicsEngine2(float fxco, float fyco, float fzco, float bxco, float byco, float bzco, Terrain *terrain) ;
    void Init(float fxco, float fyco, float fzco, float bxco, float byco, float bzco, Terrain *terrain) ; // initial the physics engine by giving initial coordinate and object of terrain on which we are working
    void keyForward() ; // increase magnitude of velocity if body is on the surface of terrain
    void keyBackword() ; // decrease magnitude of velocity if body is on the surface of terrain
    void keyLeft() ; // change direction of velocity by some angle to left remaining magnitude same
    void keyReight() ; // change direction of velocity by some angle to right remaining magnitude same
    void updatePhysics() ; // update velocity according to various forces and calculate next coordinate of object
    Vector getVelocity() ; // return current velocity for use in HUD and other purpose
    ~PhysicsEngine2() ;
};
#endif /* PHYSICSENGINE2_H_ */
