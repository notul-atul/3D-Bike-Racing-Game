/*
 * texture.h
 *
 *  Created on: 09-Aug-2013
 *      Author: DURGESH
 */
//header to load texture from file or array of(unsigned char) and bind to given ID
#ifndef TEXTURE_H_
#define TEXTURE_H_
class Texture{
public:
    void loadTexture(const char *filename, unsigned int &ID) ; // read .bmp image
    // bind texture from @data calculated by loadTexture function
    void loadTexture(char *data, int weidth, int height, unsigned int &ID) ;
};
#endif /* TEXTURE_H_ */
