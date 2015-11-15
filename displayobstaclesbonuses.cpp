/**
  * @author Atul Shree & Durgesh
  * @date 4-Sep-2013
  * @mainpage It controls the display and position of the Bonuses and Obstacles
  * @file DisplayObstaclesBonuses
  */


#include "displayobstaclesbonuses.h"
#include<stdlib.h>
#include<stdio.h>
using namespace std ;

DisplayObstaclesBonuses::DisplayObstaclesBonuses(){
    angle = 0 ;
    this->noOfMarkers = 0 ;
    this->numObstacles = 0 ;
}

DisplayObstaclesBonuses::~DisplayObstaclesBonuses(){
    delete[] markersList ;
}

void DisplayObstaclesBonuses::Init(Terrain *terr, char *bronzefile, char *silverfile, char *goldfile,char *cubefile)
{
    bronze.readObj(bronzefile);
    silver.readObj(silverfile);
    gold.readObj(goldfile);
    cube.readObj(cubefile);
    this->terr = terr ;
}

void DisplayObstaclesBonuses::setnoOfMarkers(int noOfMarkers){
    this->noOfMarkers = noOfMarkers ;
}

void DisplayObstaclesBonuses::setMarkers(int *array, int size){
    this->noOfMarkers = size ;
    this->markersList = (int*)calloc(size, 4*sizeof(int));

    for(int i = 0 ; i < size ; i++){
        this->markersList[i*4] = array[i*4] ;
        this->markersList[i*4+1] = array[i*4+1] ;
        this->markersList[i*4+2] = array[i*4+2] ;
        this->markersList[i*4+3] = array[i*4+3] ;
    }
}

void DisplayObstaclesBonuses::setObstacles(int *array, int size){
    this->numObstacles=size;
    this->obstaclePosition= (int *) calloc(size, 4*sizeof(int));

    for(int i=0; i<numObstacles*4; i+=4){
        this->obstaclePosition[i]=array[i];
        this->obstaclePosition[i+1]=array[i+1];
        this->obstaclePosition[i+2]=array[i+2];
        this->obstaclePosition[i+3]=array[i+3];
    }
}

void DisplayObstaclesBonuses::drawAllObstacles(){
    for(int i=0; i< numObstacles*4; i+=4){
        glPushMatrix();
        glTranslatef(obstaclePosition[i]-2, terr->getHeight(obstaclePosition[i]-2, obstaclePosition[i+1]-2),
                     obstaclePosition[i+1]-2);
        glScalef(4, 4, 4);
        cube.drawObj();
        glPopMatrix();
    }
}

void DisplayObstaclesBonuses::drawAllMarkers(){
    for(int i = 0 ; i < noOfMarkers ; i++){
        glPushMatrix();
        glTranslatef(markersList[i*4+1],markersList[i*4+2],markersList[i*4+3]);
        glRotatef(angle, 0,1,0);
        glRotatef(90, 0,0,1) ;
        glScalef(1/2.0, 1/2.0, 1/2.0) ;
        if(markersList[i*4] == 1)
            bronze.drawObj();
        else if(markersList[i*4] == 2)
            silver.drawObj();
        else if (markersList[i*4] ==3)
            gold.drawObj();
        glPopMatrix();
        angle++ ;
        if(angle > 360) angle -= 360 ;
    }
}


