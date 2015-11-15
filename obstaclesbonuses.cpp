/**
  * @file obstaclesbonuses.cpp
  * @author Atul Shree
  * @date 7 Sep 2013
  */
#include "obstaclesbonuses.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


float ABS(float x){
    if(x>0) return x;
    else if(x<0) return -x;
    else return 0;
}

float SIGN(float x){
    if(x>0) return 1;
    else if(x<0) return -1;
    else return 0;
}
/**
 * @brief ObstaclesBonuses::ObstaclesBonuses does nothing
 */
ObstaclesBonuses::ObstaclesBonuses(){}

/**
 * @brief ObstaclesBonuses::Init does the work of constructor
 * @param terr Pointer to the terrain object
 * @param physics Pointer to the physics Engine object
 * @param bonusData integer pointer which contains the X,Y,Z value of its position and an id which tells whether it is gold, silver of bronze
 * @param numBonus Number of bonuses on the track
 * @param obstaclePosition integer pointer which contains the X,Z value of its position and its edge length and its orientation wrt x-axis
 * @param numObstacles Number of obstacles on the track
 */
void ObstaclesBonuses::Init(Terrain *terr, GameEngine *physics, int *bonusData,
                                   int numBonus, int *obstaclePosition, int numObstacles)
{
    this->bonusCollectLength=physics->bikeLenght;
    this->bonusCollectHeight=4;
    this->bonusSidelength=2;

    this->width=terr->getWidth();
    this->length=terr->getLength();

    this->numObstacles=numObstacles;
    this->bonusData= bonusData;
    this->obstaclePosition=obstaclePosition;

    this->numBonus=numBonus;
    this->numBonusCollect=0;
    this->numCollison=0;

    this->physics= physics;
    this->terr=terr;

    this->obstacleData= (Vector**) malloc(this->length*sizeof(Vector*));

    for(int i=0; i< length; i++){
        this->obstacleData[i]= (Vector*)calloc(this->width,sizeof(Vector));
    }

    for(int i=0; i< numObstacles*4; i+=4){
        loadCubeObstacle(obstaclePosition[i], obstaclePosition[i+1], obstaclePosition[i+2], obstaclePosition[i+3]);
    }
}
/**
 * @brief ObstaclesBonuses::~ObstaclesBonuses delets obstacles and bonus data
 */
ObstaclesBonuses::~ObstaclesBonuses(){
    delete obstacleData;
}
/**
 * @brief ObstaclesBonuses::isPointInCube tells whether the asked point lies in the X-Z plane formed by projection of cube on the X-Z plane
 * @param xc X value of the centre of the cube
 * @param zc Z value of the centre of the cube
 * @param xp X value of the point
 * @param zp Z value of the point
 * @param sideLength sideLength of the cube
 * @return return 1 if point lies in it and closest to right face. Similarly 2 for up face, 3 for left and 4 for down
 */
int ObstaclesBonuses::isPointInCube(float xc, float zc, float xp, float zp, float sideLength){
    float distanceRight=  xc+sideLength/2-xp;
    float distanceLeft=   xp-(xc-sideLength/2);
    float distanceUp=     zp-(zc-sideLength/2);
    float distanceBottom= (zc+sideLength/2)-zp;

    if(distanceRight<0 || distanceLeft<0 || distanceUp <0 || distanceBottom<0) return 0;

    float minDistance=distanceRight;


    if(distanceLeft < minDistance ) minDistance=distanceLeft;
    if(distanceUp < minDistance) minDistance= distanceUp;
    if(distanceBottom < minDistance) minDistance= distanceBottom;

    if      (minDistance==distanceRight) return 1;
    else if (minDistance == distanceUp ) return 2;
    else if (minDistance == distanceLeft ) return 3;
    else if (minDistance == distanceBottom ) return 4;

    return 0;
}
/**
 * @brief ObstaclesBonuses::directionAngle
 * @param xc X value of point c
 * @param zc Z value of point c
 * @param xp X value of point p
 * @param zp Z value of point p
 * @return return the angle of the direction of vector formed by (xc,zc) and (xp,zp)
 */
float ObstaclesBonuses::directionAngle(float xc, float zc, float xp, float zp){
    float r= sqrt((xp-xc)*(xp-xc) + (zp-zc)*(zp-zc));
    float itheta;

    if(ABS(zp-zc) ==r ) itheta=-(SIGN(zp-zc))*(PI/2-.0000001);
    else itheta=asin (-(zp-zc)/ r);

    if(xp - xc <= 0 && zp - zc <=0) itheta = PI-itheta;
    if(xp -xc <0 && zp- zc >0 ) itheta = PI -itheta;

    return itheta;
}
/**
 * @brief ObstaclesBonuses::rotateThroughTheta rotates the vector formed by the points (xc,zc) and (xp,zp) through angle dtheta
 * @param xc X value of point c
 * @param zc Z value of point c
 * @param xp X value of point p
 * @param zp Z value of point p
 * @param dtheta angle by which it is to be rotated
 */
void ObstaclesBonuses::rotateThroughTheta(float xc, float zc, float &xp, float &zp, float dtheta){
    float r= sqrt((xp-xc)*(xp-xc) + (zp-zc)*(zp-zc));
    float itheta=directionAngle(xc, zc, xp, zp);

    itheta+=dtheta;

    xp= xc+r*cos(itheta);
    zp= zc-r*sin(itheta);
}
/**
 * @brief ObstaclesBonuses::loadCubeObstacle loads the cube model obstacle in obstacleData by
 * fillings the points inside it with the vector of its nearest face
 * @param xc X value of the centre of the cube
 * @param zc Z value of the centre of the cube
 * @param sideLength sideLength of the cube
 * @param xcap orientation of the cube in the plane wrt x-axis
 */
void ObstaclesBonuses::loadCubeObstacle(float xc, float zc, float sideLength, float xcap){
    float theta=acos(xcap/(float)10000);
    float coordinates[8];

    for(int i=0; i<8; i+=2){
        coordinates[i]  = xc+ ( sideLength/sqrt(2) )* cos( (i-1) * 45 * PI / 180 + theta);
        coordinates[i+1]= zc- (sideLength/sqrt(2))*sin((i-1)* 45* PI / 180 + theta);
    }

    float maxx=coordinates[0];
    float minx=coordinates[0];
    float maxz=coordinates[1];
    float minz=coordinates[1];

    for(int i=0; i<8; i+=2){
        if(coordinates[i] >maxx) maxx=coordinates[i];
        if(coordinates[i] <minx) minx=coordinates[i];

        if(coordinates[i+1] > maxz) maxz=coordinates[i+1];
        if(coordinates[i+1] < minz) minz=coordinates[i+1];
    }

    for(float i=minz; i <= maxz; i++){
        for(float j=minx; j<= maxx; j++){
            float xp=j, zp=i;

            //printf("%f %f %f %f\n",xc, zc, xp, zp);

            rotateThroughTheta(xc, zc, xp,zp, -theta);

            int isIn= isPointInCube(xc, zc, xp, zp, sideLength);

            float nx=0,nz=0;
            if(isIn==1) rotateThroughTheta(0,0,(nx=1), (nz=0), theta);
            if(isIn==2) rotateThroughTheta(0,0,(nx=0), (nz=-1), theta);
            if(isIn==3) rotateThroughTheta(0,0,(nx=-1), (nz=0), theta);
            if(isIn==4) rotateThroughTheta(0,0,(nx=0), (nz=1), theta);

            obstacleData[(int)(zp)][(int)(xp)].setX(nx);
            obstacleData[(int)(zp)][(int)(xp)].setY(0);
            obstacleData[(int)(zp)][(int)(xp)].setZ(nz);
        }
    }
}
/**
 * @brief ObstaclesBonuses::isObstacleAt informs abt the obstacle by sending the normal vectors contained there
 * @param x X value of the position at which information is to be asked
 * @param z Z value of the position at which infromation is to be asked
 * @return returns the Vector value contained at that point
 */
Vector ObstaclesBonuses::isObstacleAt(float x, float z){
    return obstacleData[(int)ceil(z)][(int)ceil(x)];
}
/**
 * @brief ObstaclesBonuses::isBikeInCubePlane determines whether the bike is in cube or not
 * @param xcube X value of the centre of the cube
 * @param zcube Z value of the centre of the cube
 * @param cubeSideLength sideLength of the cube
 * @param id tells wheteher the infromation is asked for obstacle cube or bonus cube
 * @return return integer which tells whichPart of the bike is in cube
 */
int ObstaclesBonuses::isBikeInCubePlane(float xcube, float zcube, float cubeSideLength, bool id){
    /* do some changes depending upon whether along BCL succeeds or not
     */
    Vector bodyCentreLine(physics->xf-physics->xb, physics->yf-physics->yb, physics->zf-physics->zb);
    bodyCentreLine.setY(0);
    bodyCentreLine.normalize();

    float xbike= (physics->xf + physics->xb)/2;
    float zbike= (physics->zf + physics->zb)/2;

    float itheta= directionAngle(0,0,bodyCentreLine.getX(), bodyCentreLine.getZ());

    float fx1=xbike-1 + bonusCollectLength/2, fz1=zbike, fx3=xbike-1-bonusCollectLength/2, fz3=zbike;
    float sx1=xbike+1 + bonusCollectLength/2, sz1=zbike, sx3=xbike+1-bonusCollectLength/2, sz3=zbike;

    rotateThroughTheta(xbike-1, zbike, fx1, fz1, itheta);
    rotateThroughTheta(xbike-1, zbike, fx3, fz3, itheta);
    rotateThroughTheta(xbike+1, zbike, sx1, sz1, itheta);
    rotateThroughTheta(xbike+1, zbike, sx3, sz3, itheta);

    if(id){
        Vector v=isObstacleAt(fx1, fz1);
        if(!(v.getX()==0 && v.getY()==0 && v.getZ()==0)) return 1;

        v=isObstacleAt(sx1,sz1);
        if(!(v.getX()==0 && v.getY()==0 && v.getZ()==0)) return 2;

        v=isObstacleAt(xbike-1, zbike);
        if(!(v.getX()==0 && v.getY()==0 && v.getZ()==0)) return 3;

        v=isObstacleAt(xbike+1,zbike);
        if(!(v.getX()==0 && v.getY()==0 && v.getZ()==0)) return 4;

        v=isObstacleAt(fx3,fz3);
        if(!(v.getX()==0 && v.getY()==0 && v.getZ()==0)) return 5;

        v=isObstacleAt(sx3,sz3);
        if(!(v.getX()==0 && v.getY()==0 && v.getZ()==0)) return 6;
    }
    else{
        if(isPointInCube(xcube, zcube, fx1, fz1, cubeSideLength)) return true;
        if(isPointInCube(xcube, zcube, xbike-1, zbike, cubeSideLength)) return true;
        if(isPointInCube(xcube, zcube, fx3, fz3, cubeSideLength)) return true;
        if(isPointInCube(xcube, zcube, sx1, sz1, cubeSideLength)) return true;
        if(isPointInCube(xcube, zcube, xbike+1, zbike, cubeSideLength)) return true;
        if(isPointInCube(xcube, zcube, sx3, sz3, cubeSideLength)) return true;
    }
    return 0;
}
/**
 * @brief ObstaclesBonuses::doBonusCollect collects bonus if the bike comes under the bonus cube
 * @return true if bonus is collected
 */
bool ObstaclesBonuses::doBonusCollect(){
    float yb=physics->yb;
    float yf=physics->yf;

    float minHeight= min(yb, yf);
    float maxHeight= max(yb, yf) + bonusCollectHeight;

    for(int i=0; i<numBonus*4; i+=4){
        if(bonusData[i]!=0 && isBikeInCubePlane(bonusData[i+1],bonusData[i+3], bonusSidelength, false)
                && (( minHeight<= bonusData[i+2] && maxHeight >= bonusData[i+2] )
                    || ( bonusData[i+2]-bonusSidelength/2 <= minHeight
                         && bonusData[i+2]+bonusSidelength/2 >= minHeight)
                    || ( bonusData[i+2]-bonusSidelength/2 <= maxHeight
                         && bonusData[i+2]+ bonusSidelength/2 >= maxHeight) )) {
            numBonusCollect++;
            bonusData[i]=bonusData[i+1]=bonusData[i+2]=bonusData[i+3]=0;
            return true;
        }
    }
    return false;
}
/**
 * @brief ObstaclesBonuses::collisionIfCollides does the process of the collision if the bike comes under the obstacle cube
 * @return true if collision occurs else false
 */
bool ObstaclesBonuses::collisionIfCollides(){
    Vector bodyCentreLine(physics->xf-physics->xb, physics->yf-physics->yb, physics->zf-physics->zb);
    bodyCentreLine.setY(0);
    bodyCentreLine.normalize();

    float xbike= (physics->xf + physics->xb)/2;
    float zbike= (physics->zf + physics->zb)/2;

    float itheta= directionAngle(0,0,bodyCentreLine.getX(), bodyCentreLine.getZ());

    float fx1=xbike-1 + bonusCollectLength/2, fz1=zbike, fx3=xbike-1-bonusCollectLength/2, fz3=zbike;
    float sx1=xbike+1 + bonusCollectLength/2, sz1=zbike, sx3=xbike+1-bonusCollectLength/2, sz3=zbike;

    rotateThroughTheta(xbike-1, zbike, fx1, fz1, itheta);
    rotateThroughTheta(xbike-1, zbike, fx3, fz3, itheta);
    rotateThroughTheta(xbike+1, zbike, sx1, sz1, itheta);
    rotateThroughTheta(xbike+1, zbike, sx3, sz3, itheta);

    float yb=physics->yb;
    float yf=physics->yf;

    float minHeight= min(yb, yf);

    for(int i=0; i<numObstacles*4; i+=4){
        float x=obstaclePosition[i];
        float z=obstaclePosition[i+1];
        float sideLength=obstaclePosition[i+2];

        int whichPart= isBikeInCubePlane(x, z, sideLength, true);
        //printf("%d\n", whichPart);
        if(whichPart){
            if(! (minHeight > terr->getHeight( xbike , zbike) + sideLength/2 ) ){
                Vector n(0,0,0);
                if(whichPart ==1)      n= isObstacleAt(fx1, fz1);
                else if(whichPart ==2) n= isObstacleAt(sx1, sz1);
                else if(whichPart ==3) n= isObstacleAt(xbike-1, zbike);
                else if(whichPart ==4) n= isObstacleAt(xbike+1, zbike);
                else if(whichPart ==5) n= isObstacleAt(fx3, fz3);
                else                   n= isObstacleAt(sx3, sz3);

                n.normalize();

                //printf("normal %f %f %f\n", n.getX(), n.getY(), n.getZ());

                physics->velocity.scalarMul(0.1);

                n.scalarMul(sideLength);
                {
                    physics->xf+=n.getX(); physics->xb+=n.getX();
                    physics->yf+=n.getY(); physics->yb+=n.getY();
                    physics->zf+=n.getZ(); physics->zb+=n.getZ();
                }
                numCollison++;
                return true;
            }
        }
    }
    return false;
}
