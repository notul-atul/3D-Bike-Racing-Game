#include"Vector.h"
#include"texture.h"
#include<stdlib.h>
#include"objectRender.h"
#ifndef TERRAIN_H_
#define TERRAIN_H_
// class for terrain rendring and texture mapping on terrain
class Terrain{
private:
    int length, width, displayListID ;
    float **height ;
    bool isHeightMapCalculated ; // weather height array calculated from .bmp image file
    bool isNormalsCalculated ; // weather normals are calculated or not
    bool isDisplayListCreated;
    Vector **normals ;
    // testure ides of skyBox and terrain
    unsigned int texID, frontskytexID, sideskytexID ;
    void calculateNormals() ;
    // to initilize this->height and this->normals
    void init() ;
public:
    Terrain() ;
    ~Terrain(){
        {for(int i = 0 ; i < this->length ; i++){
            free(height[i]) ;
            free(normals[i]) ;
        }
        free(height) ;
        free(normals) ;
        }
    }
    // read bitmap image and store heights in this->height if file is not valid than return false
    bool readBMP(const char *filename, int heightOffset) ;
    // generate texture from given image file and store in this->texID
    bool genTexture(const char *filename) ;
    // generate terrain using this->height array created by readBMP
    void renderTerrain() ;
    // create display list of terrain when renderTerrain first time called
    void createDisplayList() ;
    // return height of terrain at point x,z
    float getHeight(int x, int z) {
        return this->height[z][x] ;
    }
    Vector getNormal(int x, int z){
        return this->normals[z][x] ;
    }
    int getWidth(){
        return this->width ;
    }
    int getLength(){
        return this->length ;
    }
};
#endif
