/**
 * @file texture.cpp
 *
 *  @date 09-Aug-2013
 *  @author DURGESH
 */

#include"texture.h"
#include"imageInfo.h"
#include<stdio.h>
#include<GL/gl.h>
/**
 * @brief Texture::loadTexture reads the BMP file and sets the texture mapping parameters by calling loadTexture (char *, int, int, unsigned int)
 * @param filename name of the image File to be used as texture
 * @param ID id of the Texture mapping
 */
void Texture::loadTexture(const char *filename, unsigned int &ID){
    ImageInfo obj ;
    obj.loadImage(filename) ;
    this->loadTexture(obj.getImageData(), obj.getWidth(), obj.getLength(), ID) ;
}
/**
 * @brief Texture::loadTexture generates the Texture id sets various parameters for the texture mapping
 * @param data image pixel data
 * @param width width of the image
 * @param height height of the image
 * @param ID id of the texture mapping
 */
void Texture::loadTexture(char *data, int width, int height, unsigned int &ID){
    glGenTextures(1, &ID) ;
    glBindTexture(GL_TEXTURE_2D, ID) ;
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, weidth, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data) ;
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT) ;
}
