/**
 * @file terrain.cpp
 *
 * @date 07-Aug-2013
 * @author DURGESH
 */

#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include"Vector.h"
#include"terrain.h"
#include"imageInfo.h"
void Terrain::init(){
    // initilize @height and @normals array
    this->height = (float**)calloc(this->length, sizeof(float*)) ;
    this->normals = (Vector**)calloc(this->length, sizeof(Vector*)) ;
    for(int i = 0 ; i < this->length ; i++){
        this->height[i] = (float*)calloc(this->width,sizeof(float)) ;
        this->normals[i] = (Vector*)calloc(this->width, sizeof(Vector)) ;
    }
}
/**
 * @brief Terrain::Terrain initialises everything to 0
 */
Terrain::Terrain(){
    this->length = 0 ;
    this->width = 0 ;
    height = NULL ;
    normals = NULL ;
    isHeightMapCalculated = false ;
    isNormalsCalculated = false ;
    isDisplayListCreated = false ;
}
/**
 * @brief Terrain::genTexture sets texture parameters to various texture images
 * @param filename name of the Texture file for the terrain
 * @return true if it successfully sets the parameters for texture images
 */
bool Terrain::genTexture(const char *filename){
    Texture obj ;
    obj.loadTexture(filename, this->texID) ; // load texture of terrain in texID
    // load texture for sky box
    obj.loadTexture("skySide.bmp", this->sideskytexID);
    obj.loadTexture("sun.bmp", this->frontskytexID);
}
/**
 * @brief Terrain::calculateNormals calculates the normal at point by averaging the four normals formed by its four nearest neighbours
 */
void Terrain::calculateNormals(){
    // return if hegiht array is not calculated or normals are allready calculated
    if(!this->isHeightMapCalculated || this->isNormalsCalculated) return ;
    for(int i = 0 ; i < this->length ; i++){
        for(int j = 0 ; j < this->width ; j++){
            Vector out(0,0,0) ;
            if(i > 0){
                out.setX(0) ;
                out.setY(this->height[i-1][j]- this->height[i][j]) ;
                out.setZ(-1) ;
            }
            Vector left(0,0,0) ;
            if(j > 0){
                left.setX(-1) ;
                left.setY(this->height[i][j-1]- this->height[i][j]) ;
                left.setZ(0) ;
            }
            Vector in(0,0,0) ;
            if(i < this->length-1){
                in.setX(0) ;
                in.setY(this->height[i+1][j]-this->height[i][j]) ;
                in.setZ(1) ;
            }
            Vector right(0,0,0) ;
            if(j < this->width-1){
                right.setX(1) ;
                right.setY(this->height[i][j+1]-this->height[i][j]) ;
                right.setZ(0) ;
            }
            Vector sum(0,0,0) ;
            sum = sum.addV(out.crossProductV(left)) ;
            sum = sum.addV(left.crossProductV(in)) ;
            sum = sum.addV(in.crossProductV(right)) ;
            sum = sum.addV(right.crossProductV(out)) ;
            sum.normalize() ;
            this->normals[i][j] = sum ;
        }
    }
    this->isNormalsCalculated = true ;
}
/**
 * @brief Terrain::readBMP reads the BMP image and sets the Height Vectors acoordingly
 * @param filename name of the BMP file
 * @param heightOffset value which is to be multiplied to the height obtained from pixels data
 * @return true if it successfullly sets the height data into array else false
 */
bool Terrain::readBMP(const char *filename, int heightOffset){
    ImageInfo obj ;
    obj.loadImage(filename) ;
    this->length = obj.getLength() ;
    this->width = obj.getWidth() ;
    init() ; // initilize this->height array
    for(int i = 0 ; i < this->length ; i++){
        for(int j = 0 ; j < this->width ; j++){
            unsigned char c = obj.getImageDataAt(i*this->width*3+3*j) ;
            float h = heightOffset*(c/255.0); // make height between -0.5*heightOffset to 0.5*heightOffset
            this->height[i][j] = h ;
        }
    }
    this->isHeightMapCalculated  = true ;
    if(!this->isNormalsCalculated) calculateNormals() ;
    return true ;
}
/**
 * @brief Terrain::createDisplayList stores the information needed to create the terrain right, left front and back  sky into the display list
 */
void Terrain::createDisplayList(){
    this->displayListID = glGenLists(1) ;
    glNewList(displayListID, GL_COMPILE);

    // terrain
    glBindTexture(GL_TEXTURE_2D, this->texID);
    if(!this->isHeightMapCalculated || !this->isNormalsCalculated) return ;
    for(int i = 0 ; i < this->length-1 ; i++){
        glBegin(GL_TRIANGLE_STRIP) ;
        for(int j = 0  ; j < this->width ; j++){
            glNormal3f(this->normals[i][j].getX(), this->normals[i][j].getY(), this->normals[i][j].getZ()) ;
            glTexCoord2f(((float)j)/this->width, ((float)i)/this->length) ;
            glVertex3f(j, this->height[i][j], i) ;
            glNormal3f(this->normals[i+1][j].getX(), this->normals[i+1][j].getY(), this->normals[i+1][j].getZ()) ;
            glTexCoord2f(((float)j)/this->width, ((float)i+1)/this->length) ;
            glVertex3f(j, this->height[i+1][j], i+1) ;
        }
        glEnd() ;
    }

    //skybox
    // front part of skybox
    glBindTexture(GL_TEXTURE_2D, this->frontskytexID);
    glBegin(GL_POLYGON);
    glNormal3f(0,0,-1) ;
    glTexCoord2f(1,1);
    glVertex3f(256+5, 150, 256+5);
    glNormal3f(0,0,-1) ;
    glTexCoord2f(0,1) ;
    glVertex3f(-5, 150, 256+5) ;
    glNormal3f(0,0,-1) ;
    glTexCoord2f(0,0) ;
    glVertex3f(-5, -70, 256+5) ;
    glNormal3f(0,0,-1) ;
    glTexCoord2f(1,0) ;
    glVertex3f(256+5, -70, 256+5) ;
    glEnd() ;

    glBindTexture(GL_TEXTURE_2D, this->sideskytexID);
    // left of skybox
    glBegin(GL_POLYGON);
    glNormal3f(-1,0,0) ;
    glTexCoord2f(1,1);
    glVertex3f(256+5, 150, -5);
    glNormal3f(-1,0,0) ;
    glTexCoord2f(0,1) ;
    glVertex3f(256+5, 150, 256+5) ;
    glNormal3f(-1,0,0) ;
    glTexCoord2f(0,0) ;
    glVertex3f(256+5, -70, 256+5) ;
    glNormal3f(-1,0,0) ;
    glTexCoord2f(1,0) ;
    glVertex3f(256+5, -70, -5) ;
    glEnd() ;

    //back of skybox
    glBegin(GL_POLYGON);
    glNormal3f(0,0,1) ;
    glTexCoord2f(1,1);
    glVertex3f(-5, 150, -5);
    glNormal3f(0,0,1) ;
    glTexCoord2f(0,1) ;
    glVertex3f(256+5, 150, -5) ;
    glNormal3f(0,0,1) ;
    glTexCoord2f(0,0) ;
    glVertex3f(256+5, -70, -5) ;
    glNormal3f(0,0,1) ;
    glTexCoord2f(1,0) ;
    glVertex3f(-5, -70, -5) ;
    glEnd() ;

    // right of skybox
    glBegin(GL_POLYGON);
    glNormal3f(1,0,0) ;
    glTexCoord2f(1,1);
    glVertex3f(-5, 150, 256+5);
    glNormal3f(-1,0,0) ;
    glTexCoord2f(0,1) ;
    glVertex3f(-5, 150, -5) ;
    glNormal3f(1,0,0) ;
    glTexCoord2f(0,0) ;
    glVertex3f(-5, -70, -5) ;
    glNormal3f(1,0,0) ;
    glTexCoord2f(1,0) ;
    glVertex3f(-5, -70, 256+5) ;
    glEnd() ;

    glEndList();
    this->isDisplayListCreated = true ;
}
/**
 * @brief Terrain::renderTerrain executes the dispaly list to render Terrain again and again
 */
void Terrain::renderTerrain(){
    if(!this->isDisplayListCreated) this->createDisplayList();
    glCallList(displayListID);
}
