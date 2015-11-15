/**
 * This id the Implementation of the the physics engine
 *  of the Game
 *  @author Atul Shree
 *  @date 21 Aug 2013
 *  @file GameEngine.cpp
 */

#include "GameEngine.h"
#include <stdio.h>
#include <QApplication>

#define Time  .005
#define Gravity  300
#define meu  0.8
#define PI  3.14159265358979323846
#define Front_Acceleration  1500
#define Max_Speed 200
float sign(float x){
    if(x > 0) return 1 ;
    if(x == 0) return 0 ;
    return -1;
}

float abs1(float x){
    if(x >=0) return x;
    else return -x;
}
/**
 * constructor of the class GameEngine
 * @brief GameEngine::GameEngine
 * @param <>
 *
 */
GameEngine::GameEngine(){
    this->velocity.setX(0); this->velocity.setY(0); this->velocity.setZ(0);
    this->bikeLenght=0;

    this->xf=0; this->yf=0; this->zf=0;
    this->xb=0; this->yb=0; this->zb=0;

    this->theta=0;
}
/**
 * @brief GameEngine::getVelocity
 * @return returns the magnitude of the velocity vector of the bike
 */
float GameEngine::getVelocity(){
    return this->velocity.magnitude() ;
}
/**
 * @brief GameEngine::init
 * @param xf X value of the Front Wheel co-ordinate
 * @param yf Y value of the Front Wheel co-ordinate
 * @param zf Z value of the Front Wheel co-ordinate
 * @param xb X value of the Rear Wheel co-ordinate
 * @param yb Y value of the Rear Wheel co-ordinate
 * @param zb Z value of the Rear Wheel co-ordinate
 * @param terrain Pointer to the terrain class of the Game which defines current Landscape
 */
void GameEngine::init(float xf, float yf, float zf, float xb, float yb, float zb, Terrain *terrain){
    this->xf=xf; this->yf=yf; this->zf=zf;
    this->xb=xb; this->yb=yb; this->zb=zb;

    this->bikeLenght=sqrt( (xf-xb)*(xf-xb) + (yf-yb)*(yf-yb) + (zf-zb)*(zf-zb) );

    {
        float r= sqrt((xf-xb)*(xf-xb) + (zf-zb)*(zf-zb));

        if(abs1(zf-zb) ==r ) this->theta=-(sign(zf-zb))*(PI/2-.0000001);
        else this->theta=asin (-(zf-zb)/ r);

        if(xf - xb <= 0) this->theta = PI-this->theta;
    }

    this->velocity.setX(0); this->velocity.setY(0); this->velocity.setZ(0);
    this->terrain = terrain ;
}
/**
 * @brief GameEngine::queryHeight
 * @param x X value of the Position at which Height is to be Queried
 * @param z Z value of the Position at which Height is to be Queried
 * @return Height of the Landscape at position X,Z
 */
float GameEngine::queryHeight(float x, float z){
    return terrain->getHeight(x,z) ;
}
/**
 * @brief GameEngine::queryNormal
 * @param x X value of the Position at which Normal is to be Queried
 * @param z Z value of the Position at which Normal is to be Queried
 * @return Normal Vector at position X,Z
 */
Vector GameEngine::queryNormal(float x, float z){
    return terrain->getNormal(x,z) ;
}

/**
 * @brief GameEngine::KFactorOfNormal
 * @param vector one of the vectors which determines the direction of the vector in asked plane
 * @param normal normal Vector of the Plane
 * @return A factor which when multiplied with normal and then added with vector gives one of the Vector in the Plane
 */
float GameEngine::KFactorOfNormal(Vector vector, Vector normal){
    float nx=normal.getX();
    float ny=normal.getY();
    float nz=normal.getZ();

    return -(vector.getX()*nx + vector.getY()*ny + vector.getZ()*nz)/(nx*nx + nz*nz + ny*ny );
}

/**
 * @brief GameEngine::vectorAlongPlane
 * @param x X value of the position at which Vector along plane is asked to compute
 * @param z Z value of the position at which Vector along plane is asked to compute
 * @param vector one of the vectors which determines the direction of the vector in asked plane
 * @return Vector in the plane of the landscape at position X, Height, Z which is projection of the vector on the plane
 */
Vector GameEngine::vectorAlongPlane(float x, float z, Vector vector){
    Vector normal = queryNormal(x, z);
    float K=KFactorOfNormal(vector, normal);

    normal.normalize();
    normal.scalarMul(K);
    Vector alongPlane= vector.addV(normal);

    return alongPlane;
}

/**
 * @brief GameEngine::rotateThroughTheta rotates Bike and its velocity Vector through angle dtheta in anticlockwise sense wrt X-axis
 * @param dtheta Angle through which bike and it's vector is to be rotated
 */
void GameEngine::rotateThroughTheta(float dtheta){
    this->theta+=dtheta;

    float r = sqrt( (zf-zb)*(zf-zb) + (xf-xb)*(xf-xb) );

    xf = xb + r*cos(theta * PI/180);
    zf = zb - r*sin(theta * PI/180);

    r=sqrt(velocity.getX()*velocity.getX() + velocity.getZ()*velocity.getZ());

    velocity.setX(r*cos(theta *PI/180));
    velocity.setZ(- r*sin(theta * PI/180));
}
/**
 * @brief GameEngine::rotateThroughPsi rotates Bike and its velocity Vector through angle dpsi in anticlockwise sense wrt X-Z plane
 * @param dpsi Angle through which bike and it's vector is to be rotated
 */
void GameEngine::rotateThroughPsi(float dpsi){
    float psi = (sign(yf-yb))*asin( abs1 (yf-yb) / bikeLenght);
    psi+=dpsi*PI/180;

    xf = xb + bikeLenght*cos(psi)*cos(theta * PI /180);
    yf = yb + bikeLenght*sin(psi);
    zf = zb - bikeLenght*cos(psi)*sin(theta * PI /180);

    psi = (sign(velocity.getY()))*asin( abs1 (velocity.getY()) / velocity.magnitude());
    psi+=dpsi*PI/180;
    velocity.setX(velocity.magnitude()*cos(psi)*cos(theta*PI/180));
    velocity.setY(velocity.magnitude()*sin(psi));
    velocity.setZ(-velocity.magnitude()*cos(psi)*sin(theta*PI/180));

}
/**
 * @brief GameEngine::rotateBikeOntoPlane If the Front Wheel goes inside the terrrain then it rotates the Front wheel on to the Ground
 */
void GameEngine::rotateBikeOntoPlane(){
    float planeHeight = queryHeight(xf, zf);

    while(yf < planeHeight){
        rotateThroughPsi(.05);
        planeHeight = queryHeight(xf, zf);
    }
}
/**
 * @brief GameEngine::keepBikeOnPlane if the back wheel goes inside the terrain then shifts the whole bike s.t. back wheel comes on to the ground
 */
void GameEngine::keepBikeOnPlane(){
    float planeHeight = queryHeight(xb, zb);

    if(yb<planeHeight){
        yf+=(planeHeight-yb);
        yb=planeHeight;
    }
}
/**
 * @brief GameEngine::doBoundCheck If the Bike goes outside the defined landscape the resets its position inside the Landscape
 */
void GameEngine::doBoundCheck(){
    bool outOfBound=false;
    if(zf <=0 || zb <=0){
        outOfBound=true;
        zf+=7;
        zb=zf;
        if(xf - bikeLenght >0) {
            xb= xf- bikeLenght;
            theta=0;
        }
        else {
            theta=180;
            xb= xf + bikeLenght;
        }
    }

    if (zf >= terrain->getLength()-1 || zb >= terrain->getLength()-1 ){
        outOfBound=true;
        zf-=7;
        zb=zf;
        if(zf - bikeLenght >0) {
            theta=0;
            xb= xf-bikeLenght;
        }
        else {
            theta=180;
            xb= xf + bikeLenght;
        }
    }

    if(xf <=0 || xb <= 0){
        xf+=7;
        outOfBound=true;
        xf=xb;
        if(zf - bikeLenght >0) {
            theta=270;
            zb= zf - bikeLenght;
        }
        else{
            theta=90;
            zb= zf+ bikeLenght;
        }
    }
    if(xf >= terrain->getWidth()-1 || xb >= terrain->getWidth()-1){
        xf-=7;
        outOfBound=true;
        xf=xb;
        if(zf -bikeLenght >0) {
            theta=270;
            zb= zf - bikeLenght;
        }
        else{
            theta=90;
            zb= zf +bikeLenght;
        }
    }

    if(outOfBound) velocity.scalarMul(0);
}

/**
 * @brief GameEngine::motionFunction The core function which computes where the bike would be after time dt with the aid of above defined functions
 * @param accelerationCoefficient Value is 1 when bike is accelerating, -0.9 when the brakes are applied else 0.
 */
void GameEngine::motionFunction(float accelerationCoefficient){
    doBoundCheck();
    keepBikeOnPlane();

    float height = queryHeight(xb, zb);
    /*
     * if the back wheel is on the plane
     */
    if(yb <= height){

        Vector normal = queryNormal(xb, zb);
        normal.normalize();
        Vector bodyCentreLine(xf -xb, yf-yb, zf-zb);
        bodyCentreLine.normalize();
        Vector alongPlane = vectorAlongPlane(xb, zb, bodyCentreLine);
        alongPlane.normalize();
        /**
         * mod of the gravity component along the plane
         * and also int the plane created by the normal vector and the BikeVector
         */
        float gravityComponentAlongPlane = Gravity*abs1( alongPlane.getY() );
        /**
         * mod of the gravity component along the normal vector
         */
        float gravityComponentAlongNormal = sqrt(Gravity*Gravity - gravityComponentAlongPlane*gravityComponentAlongPlane);

        int velocitySign = sign(velocity.dotProductV(alongPlane));
        /*
         * adds gravity effect to the velocity
         * if the bike vector has downward component then its adds to it
         * otherwise subtracts from it
         */

        Vector dv(0,0,0);

        if(velocity.getY()<0){
            alongPlane.scalarMul(gravityComponentAlongPlane*Time);
            dv=dv.addV(alongPlane);
        }
        else{
            alongPlane.scalarMul(-gravityComponentAlongPlane*Time);
            dv=dv.addV(alongPlane);
        }

        alongPlane=vectorAlongPlane(xb,zb,bodyCentreLine);
        alongPlane.normalize();

        /*
         *adds friction effect in the direction opposite to the velocity
         */
        float frictionalForce = (-velocitySign)*gravityComponentAlongNormal*meu;
        alongPlane.scalarMul(frictionalForce*Time);
        dv=dv.addV(alongPlane);

        alongPlane=vectorAlongPlane(xb,zb,bodyCentreLine);
        alongPlane.normalize();
        /*
         *adds motor accelration effect to the velocity
         */
        alongPlane.scalarMul(accelerationCoefficient*Front_Acceleration*Time);
        dv=dv.addV(alongPlane);


        /*
         * moves the bike according to the velocity along the plane
         */
        {
            velocity=velocity.addV(dv);
            alongPlane=vectorAlongPlane(xb,zb,velocity);
            alongPlane.normalize();
            alongPlane.scalarMul(velocity.magnitude());
            velocity=alongPlane;
            if(velocity.magnitude()> Max_Speed){
                velocity.normalize();
                velocity.scalarMul(Max_Speed);
            }

            if(velocity.magnitude() <=2.5 && accelerationCoefficient ==0){
                velocity.scalarMul(0);
                return;
            }

            xf+=velocity.getX()*Time;
            yf+=velocity.getY()*Time;
            zf+=velocity.getZ()*Time;

            xb+=velocity.getX()*Time;
            yb+=velocity.getY()*Time;
            zb+=velocity.getZ()*Time;
        }

        keepBikeOnPlane();
        /*
         *if the front is inside plane it rotaes it to the plane
         * if it is in the air it rotates it downward about the back wheel
         */
        if(queryHeight(xf, zf) > yf) rotateBikeOntoPlane();
        else if( queryHeight(xf, zf) < yf ) {
            rotateThroughPsi(-.75);
            rotateBikeOntoPlane();
        }
        else;		// do Nothing
    }
    /*
     * if the back wheel is in the air
     */
    else{
        Vector temp(0,-Gravity*Time,0);
        velocity=velocity.addV(temp);

        if(velocity.magnitude()> Max_Speed){
            velocity.normalize();
            velocity.scalarMul(Max_Speed);
        }

        /*
         * projectile motion in differential form
         */
        {

            xf+= velocity.getX()*Time;
            yf+= velocity.getY()*Time;
            zf+= velocity.getZ()*Time;

            xb+= velocity.getX()*Time;
            yb+= velocity.getY()*Time ;
            zb+= velocity.getZ()*Time;
        }
        keepBikeOnPlane();
        if(queryHeight(xf, zf) > yf) rotateBikeOntoPlane();
        else rotateThroughPsi(-.75);
    }
}
/**
 * @brief GameEngine::keyboardFuncUp sends acceleration co-efficient =1 which indicates that bike is accelerating
 */
void GameEngine::keyboardFuncUp(){
    motionFunction(1);
}
/**
 * @brief GameEngine::keyboardFuncDown sends acceleration co-efficient =-0.9 which indicates that brakes have been applied
 */

void GameEngine::keyboardFuncDown(){
    motionFunction(-0.9);
}
/**
 * @brief GameEngine::keyboardFuncLeft roates the bike through an agle of 2 degress in anticlockwise sense
 */
void GameEngine::keyboardFuncLeft(){
    rotateThroughTheta(2);
    motionFunction(0);
}
/**
 * @brief GameEngine::keyboardFuncRight roates the bike through an agle of 2 degress in clockwise sense
 */
void GameEngine::keyboardFuncRight(){
    rotateThroughTheta(-2);
    motionFunction(0);
}
/**
 * @brief GameEngine::keyboardFuncNullLinear sends acceleration co-efficient =0 which indicates
 * that no brakes and motor force is being exerted on the bike
 */
void GameEngine::keyboardFuncNullLinear(){
    motionFunction(0);
}

/**
 * @brief GameEngine::doPhysics Invokes one of the keyboard Functions according to the button pressed on the keyboard
 * @param key value which determines which keyboard button is pressed
 */
void GameEngine::doPhysics(int key){
    switch(key){
    case Qt::Key_W:
        keyboardFuncUp();
        break;

    case Qt::Key_S:
        keyboardFuncDown();
        break;

    case Qt::Key_A:
        keyboardFuncLeft();
        break;
    case Qt::Key_D:
        keyboardFuncRight();
        break;
    case Qt::Key_Escape:
        exit(0);
        break;
    default:
        keyboardFuncNullLinear();
        break;
    }
}
