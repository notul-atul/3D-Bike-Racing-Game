/**
 * this is the asked physics engine for the game
 * GameEngine.h
 *
 *  	@date 21-Aug-2013
 *      @author  Atul Shree
 *      @file GameEngine.h
 */
#ifndef GAMEENGINE_H_
#define GAMEENGINE_H_



#include <math.h>
#include "Vector.h"
#include "terrain.h"
/**
 * this os the dt of the physics engine
 */

#define Time  .005
/**
 * this is the acceleration due to gravity
 */
#define Gravity  100
/**
 * this the friction coefficient for the game
 */
#define meu  0.8
/**
 * value of PI
 */
#define PI  3.14159265358979323846
/**
 * this is motor acceleration
 */
#define Front_Acceleration  750
/**
 * Maximum speed which motor can sustain
 */
#define Max_Speed  78888

class GameEngine{
private:
    float KFactorOfNormal(Vector vector, Vector normal);
    Vector vectorAlongPlane(float x, float z,  Vector vector);

    void rotateThroughTheta(float dtheta);
    void rotateThroughPsi(float dpsi);
    void rotateBikeOntoPlane();
    void keepBikeOnPlane();

    void doBoundCheck();

    void motionFunction(float accelerationCoefficient);

    void keyboardFuncUp();
    void keyboardFuncDown();
    void keyboardFuncLeft();
    void keyboardFuncRight();
    void keyboardFuncNullLinear();

public:
    float xf,yf,zf;
    float xb,yb,zb;
    Vector velocity;

    float bikeLenght;
    float theta;

    Terrain *terrain ;

    GameEngine();
    void init(float xf, float yf, float zf, float xb, float yb, float zb, Terrain *terrain) ;
    Vector queryNormal(float x, float z);
    float queryHeight(float x, float z);
    float getVelocity() ;
    void doPhysics(int key);
};

#endif /* GAMEENGINE_H_ */
