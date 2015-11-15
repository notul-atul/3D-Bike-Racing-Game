/*
 * loadBMP.h
 *
 *  Created on: 09-Aug-2013
 *      Author: DURGESH
 */
#include<stdlib.h>
// header for loading data of bmp image into this->data
#ifndef LOADBMP_H_
#define LOADBMP_H_
class ImageInfo{
private:
    char *data ;
    int length, width ;
    /* to get Information about given Image file like weidth, length and data
     *offset etc  and return data offset if image is not valid bitmap than return -1
     */
    int getImageInfo(const char *filename) ;
public:
    explicit ImageInfo() ;
    ~ImageInfo();
    int getLength() ;
    int getWidth() ;
    char* getImageData() ; // return this->data
    char getImageDataAt(int i) ; // return this->data[i]
    bool loadImage(const char *filename) ; // load image from @Perm filename and save in @this->data
};
#endif /* LOADBMP_H_ */
