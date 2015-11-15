/*
 * physicsEngine2.cpp
 *
 *  Created on: 10-Aug-2013
 *      Author: DURGESH
 */
#include"physicsEngine2.h"
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

PhysicsEngine2::PhysicsEngine2(){
    this->fxco = 0 ;
    this->fyco = 0 ;
    this->fzco = 0;
    this->bxco = 0 ;
    this->byco = 0 ;
    this->bzco = 0 ;
    this->terrain = NULL ;
}
PhysicsEngine2::PhysicsEngine2(float fxco, float fyco, float fzco, float bxco, float byco, float bzco, Terrain *terrain){
    this->terrain = terrain ;
    this->fxco = fxco ;
    this->fyco = fyco ;
    this->fzco = fzco ;
    this->bxco = bxco ;
    this->byco = byco ;
    this->bzco = bzco ;
}
void PhysicsEngine2::Init(float fxco, float fyco, float fzco, float bxco, float byco, float bzco, Terrain *terrain){
    this->terrain = terrain ;
    this->fxco = fxco ;
    this->fyco = fyco ;
    this->fzco = fzco ;
    this->bxco = bxco ;
    this->byco = byco ;
    this->bzco = bzco ;
    this->velocity.scalarMul(0) ;
}
Vector PhysicsEngine2::getVelocity(){
    return this->velocity ;
}
void PhysicsEngine2::keyForward(){
    if(this->velocity.magnitude()+5 > 180) return ;
    if(!(abs(this->fyco-terrain->getHeight(this->fxco, this->fzco)) <= 0.1)) return ; //if body is not in contact with surface than don't do anything
    float vel = 5 ; // increase component of velocity in direction of heading of bike on every forward key pressed
    Vector chvelocity(this->fxco-this->bxco, this->fyco-this->byco, this->fzco-this->bzco) ;
    chvelocity.normalize() ;
    chvelocity.scalarMul(vel) ;
    this->velocity = this->velocity.addV(chvelocity) ;
    this->updatePhysics() ;
}
void PhysicsEngine2::keyBackword(){
    if(!(abs(this->fyco-terrain->getHeight(this->fxco, this->fzco)) <= 0.1)) return ; //if body is not in contact with surface than don't do anything
    if(this->velocity.magnitude()-2 <= 0.05) return ; // if velocity is very low or zero than don't do anything
    float vel = -2 ; // decrease in component of velocity in direction opposite to heading of bike on every backward key pressed
    Vector chvelocity(this->fxco-this->bxco, this->fyco-this->byco, this->fzco-this->bzco) ;
    chvelocity.normalize() ;
    chvelocity.scalarMul(vel) ;
    this->velocity = this->velocity.addV(chvelocity) ;
    this->updatePhysics();
}
void PhysicsEngine2::keyLeft(){
    //if(!(abs(this->fyco-terrain->getHeight(this->fxco, this->fzco)) <= 1)) return ; //if body is not in contact with surface than don't do anything
    float vel = this->velocity.magnitude() ;
    this->velocity.normalize() ;
    Vector rotate(this->velocity.getZ(), 0, -this->velocity.getX()); // vector perpendicular to velocity vector to change it's direction
    rotate.normalize() ;
    rotate.scalarMul(0.03) ;
    this->velocity = this->velocity.addV(rotate) ;
    this->velocity.normalize() ;
    this->velocity.scalarMul(vel) ;
    Vector dir(this->fxco-this->bxco, this->fyco-this->byco, this->fzco-this->bzco) ; //vector direction of bike
    float len = dir.magnitude() ; // length of bike(should remain constant)
    dir.normalize() ;
    rotate.setX(dir.getZ());
    rotate.setY(0);
    rotate.setZ(-dir.getX()) ;
    /*
     * vector rotate is now perpendicular to direction of heading of bike
     * it is to change direction of heading of bike
    */
    rotate.normalize() ;
    rotate.scalarMul(0.03) ;
    dir = dir.addV(rotate) ;
    dir.scalarMul(len) ;
    this->fxco = this->bxco+dir.getX() ;
    this->fyco = this->byco+dir.getY() ;
    this->fzco = this->bzco+dir.getZ() ;
    this->updatePhysics() ;
}
void PhysicsEngine2::keyReight(){
    //if(!(abs(this->fyco-terrain->getHeight(this->fxco, this->fzco)) <= 1)) return ; //if body is not in contact with surface than don't do anything
    float vel = this->velocity.magnitude() ;
    this->velocity.normalize() ;
    Vector rotate(-this->velocity.getZ(), 0, this->velocity.getX()); // vector perpendicular to velocity vector to change it's direction
    rotate.normalize() ;
    rotate.scalarMul(0.03) ;
    this->velocity = this->velocity.addV(rotate) ;
    this->velocity.normalize() ;
    this->velocity.scalarMul(vel) ;
    Vector dir(this->fxco-this->bxco, this->fyco-this->byco, this->fzco-this->bzco) ; //vector direction of bike
    float len = dir.magnitude() ; //length of bike (should remain constant)
    dir.normalize() ;
    rotate.setX(-dir.getZ());
    rotate.setY(0);
    rotate.setZ(dir.getX()) ;
        /*
         * vector rotate is now perpendicular to direction of heading of bike
         * it is to change direction of heading of bike
        */
    rotate.normalize() ;
    rotate.scalarMul(0.03) ;
    dir = dir.addV(rotate) ;
    dir.scalarMul(len) ;
    this->fxco = this->bxco+dir.getX() ;
    this->fyco = this->byco+dir.getY() ;
    this->fzco = this->bzco+dir.getZ() ;
    this->updatePhysics() ;
}
void PhysicsEngine2::updatePhysics(){
    float fx = this->fxco+this->velocity.getX()*TIME ;
    float fz = this->fzco+this->velocity.getZ()*TIME ;
    if(fx < 0||fx > 256){
        velocity.setX(0);
        Vector dir = this->velocity ;
        dir.normalize();
        Vector dir1(this->fxco-this->bxco, this->fyco-this->byco, this->fzco-this->bzco) ;
        float len = dir1.magnitude();
        dir.scalarMul(len);
        this->fxco = dir.getX()+this->bxco ;
        this->fyco = dir.getY()+this->byco ;
        this->fzco = dir.getZ()+this->bzco ;
    }
    if(fz < 0 || fz > 256){
        velocity.setZ(0);
        Vector dir = this->velocity ;
        dir.normalize();
        Vector dir1(this->fxco-this->bxco, this->fyco-this->byco, this->fzco-this->bzco) ;
        float len = dir1.magnitude();
        dir.scalarMul(len);
        this->fxco = dir.getX()+this->bxco ;
        this->fyco = dir.getY()+this->byco ;
        this->fzco = dir.getZ()+this->bzco ;
    }
    this->fxco += this->velocity.getX()*TIME ;
    this->fzco += this->velocity.getZ()*TIME ;
    this->bxco += this->velocity.getX()*TIME ;
    this->bzco += this->velocity.getZ()*TIME ;
    this->fyco += this->velocity.getY()*TIME ;
    this->byco += this->velocity.getY()*TIME ;
    // if go below surface than make height equal to height of surface
    if(this->fyco < terrain->getHeight(this->fxco, this->fzco)){
            this->fyco = terrain->getHeight(this->fxco, this->fzco) ;
    }
    if(this->byco < terrain->getHeight(this->bxco, this->bzco)){
        this->byco = terrain->getHeight(this->bxco, this->bzco) ;
    }
    Vector gacc(0,-GREAVITY,0) ; // acceleration due to gravity
    if(abs(this->fyco-terrain->getHeight(this->fxco, this->fzco)) <= 0.1){ //if body is in contact with ground than apply normal force otherwise only gravitational force
        Vector normal = terrain->getNormal(this->fxco, this->fzco) ;
        normal.scalarMul(-1) ; // flip the normal
        float factor = gacc.dotProductV(normal) ; //factor by which gravitational acceleration decrease
        normal.scalarMul(-1) ; // get original normal back
        normal.scalarMul(factor) ;
        gacc = gacc.addV(normal) ;
    }
    gacc.scalarMul(TIME) ; // get change in velocity vector due to both surface normal and gravity
    this->velocity = this->velocity.addV(gacc) ;
    if((abs(this->fyco-terrain->getHeight(this->fxco, this->fzco)) <= 0.1)){ // if body is in contact with surface than apply friction
        float friction = 5*FRICTION_COEFICENT*50*TIME ; // decrease in velocity due to friction
        float vel = this->velocity.magnitude() ;
        vel -= friction ;
        if(vel <= 0.01) this->velocity.scalarMul(0) ;
        else{
            this->velocity.normalize() ;
            this->velocity.scalarMul(vel) ;
        }
    }
}
PhysicsEngine2::~PhysicsEngine2(){
    delete terrain ;
}
