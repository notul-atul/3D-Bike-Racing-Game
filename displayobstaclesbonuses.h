/**
  * @date 4-Sep-2013
  * @author Atul Shree & Durgesh
  * @file DisplayObstaclesBonuses
  */


#ifndef DISPLAYBONUS_H
#define DISPLAYBONUS_H
#include "objectRender.h"
#include "terrain.h"

class DisplayObstaclesBonuses
{
private:
    int width, length, angle ;
    Object bronze, silver, gold , cube;
public:
    /* total number of Bonuses
     */
    int  noOfMarkers;
    /* total number of Obstacles
     */
    int numObstacles;
    /* contains position and height of all the bonuses
     */
    int *markersList;
    /* contains position orientation and size of all obstacles
     */
    int *obstaclePosition;
    /* pointer to the Object of the terrain class which determines the landscape of the Game
     */
    Terrain *terr;
    void Init(Terrain *terr, char *bronzefile, char *silverfile, char *goldfile,char *cubefile) ;
    void setnoOfMarkers(int noOfMarkers) ;
    void drawAllMarkers() ;
    void drawAllObstacles();
    void setMarkers(int *array, int size) ;
    void setObstacles(int *array, int size);
    DisplayObstaclesBonuses();
    ~DisplayObstaclesBonuses() ;
};

#endif // DISPLAYBONUS_H
