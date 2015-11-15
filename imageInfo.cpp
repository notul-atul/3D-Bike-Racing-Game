/**
 * @file imageInfo.cpp
 *
 *  @date 09-Aug-2013
 *  @author DURGESH
 */

#include<stdio.h>
#include<fstream>
#include "imageInfo.h"
/**
 * @brief ImageInfo::ImageInfo constructor for the class ImageInfo which sets everything to Zero
 */
ImageInfo::ImageInfo(){
    this->data = NULL ;
    this->length = 0 ;
    this->width = 0 ;
}
/**
 * @brief ImageInfo::~ImageInfo destructor which deletes the char *data used by the class. This used to contains all the pixels information of the image
 */
ImageInfo::~ImageInfo(){
    free(data) ;
}
/**
 * @brief ImageInfo::getImageInfo reads the header of the BMP image to obtain width, Height and Offset of the pixel information.
 * @param filename name of the image file
 * @return the offset of the pixel data contained int the file
 */
int ImageInfo::getImageInfo(const char *filename){
    FILE *fp = fopen(filename, "rb") ;
    char *buffer ; // read width, height and other information of image
    buffer = (char*)malloc(2*sizeof(char)) ;
    fread(buffer, 2, 1, fp) ;
    if(!(buffer[0] == 'B' && buffer[1] == 'M')){ // is valid .bmp file
        return -1 ;
    }
    buffer = (char*)malloc(8*sizeof(char)) ;
    fread(buffer, 8, 1, fp) ;
    int offset ; // .bmp header offset
    fread(&offset, 4, 1, fp) ;
    buffer = (char*)malloc(2*sizeof(char)) ;
    fseek(fp, 18, SEEK_SET) ;
    fread(&this->width, 4, 1, fp) ;
    fseek(fp, 22, SEEK_SET) ;
    fread(&this->length, 4, 1, fp) ;
    fclose(fp) ;
    delete buffer ;
    return offset ;
}
/**
 * @brief ImageInfo::loadImage reads pixels data into the data pointer
 * @param filename filename of the BMP image file
 * @return true if it successfully reads the pixels data
 */
bool ImageInfo::loadImage(const char *filename){
    int offset = this->getImageInfo(filename);
    if(offset == -1){
        printf("Can't read Image File") ;
        return false ;
    }
    FILE *fp ;
    fp = fopen(filename, "rb") ;
    fseek(fp, offset, SEEK_SET) ; // skip header
    this->data = (char*)malloc(this->width*this->length*3*sizeof(unsigned char)) ;
    for(int i = 0 ; i < this->width*this->length*3 ; i+=3){
        fread(this->data+i, 3, 1, fp) ;
        unsigned char tmp = (this->data+i)[0] ;
        (this->data+i)[0] = (this->data+i)[2] ;
        (this->data+i)[2] = tmp ;
    }
    fclose(fp) ;
    return true ;
}
/**
 * @brief ImageInfo::getLength
 * @return returns the length of the image
 */
int ImageInfo::getLength(){
    return this->length ;
}
/**
 * @brief ImageInfo::getWidth
 * @return returns the height of the image
 */
int ImageInfo::getWidth(){
    return this->width ;
}
/**
 * @brief ImageInfo::getImageData
 * @return pointer to the pixels data saved in data
 */
char* ImageInfo::getImageData(){
    return this->data ;
}
/**
 * @brief ImageInfo::getImageDataAt
 * @param i value of the position at which image data is to obtain
 * @return return the image data at position i in char dataType format
 */
char ImageInfo::getImageDataAt(int i){
    return this->data[i] ;
}
