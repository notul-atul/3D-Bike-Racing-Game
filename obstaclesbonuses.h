#ifndef OBSTACLESBONUSES_H
#define OBSTACLESBONUSES_H
#include "terrain.h"
#include "GameEngine.h"
#include <list>

#define CR 0.8

#define PI 3.14159265358979323846
using namespace std;

class ObstaclesBonuses
{
private:
    Vector **obstacleData;

    float bonusCollectLength;
    float bonusCollectHeight;
    float bonusSidelength;

    GameEngine *physics;
    Terrain *terr;

    float directionAngle(float xc, float zc, float xp, float zp);
    int isPointInCube(float xc, float zc, float xp, float zp, float sideLength);

    int isBikeInCubePlane(float xcube, float zcube, float cubeSideLength, bool id);

public:
    int width, length;

    int *obstaclePosition;
    int *bonusData;

    int numObstacles;
    int numBonus;

    int numCollison, numBonusCollect;

    ObstaclesBonuses();
    ~ObstaclesBonuses();
    void Init(Terrain *terr, GameEngine *physics, int *bonusData,
              int numBonus, int *obstaclePosition, int numObstacles) ;
    void rotateThroughTheta(float xc, float zc, float &xp, float &zp, float dtheta);
    void loadCubeObstacle(float xc, float zc, float sideLength, float xcap);
    Vector isObstacleAt(float x, float z);

    bool collisionIfCollides();
    bool doBonusCollect();

};

#endif // OBSTACLESBONUSES_H
