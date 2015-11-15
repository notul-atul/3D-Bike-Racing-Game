/**
 * @file Vector.cpp
 *
 * @date 07-Aug-2013
 * @author atul
 */

# include "Vector.h"
# include <math.h>

/**
 * @brief Vector::Vector sets x, y , z to 0
 */
Vector::Vector(){
    this->i=0;
    this->j=0;
    this->k=0;
}
/**
 * @brief Vector::Vector sets the X,Y and Z component of the vector to corresponding x,y and z
 */
Vector::Vector(float x,  float y,  float z){
    this->i=x;
    this->j=y;
    this->k=z;
}
/**
 * @brief Vector::getX return the X component of the Vector
 * @return x component
 */
float Vector::getX(){
    return this->i;
}
/**
 * @brief Vector::getY return the Y component of the Vector
 * @return y component
 */
float Vector::getY(){
    return this->j;
}
/**
 * @brief Vector::getZ return the Z component of the vector
 * @return z component
 */
float Vector::getZ(){
    return this->k;
}
/**
 * @brief Vector::setX sets the X component of the vector
 * @param x x component
 */
void Vector::setX(float x){
    this->i=x;
}
/**
 * @brief Vector::setY sets the Y component of the vector
 * @param y y component
 */
void Vector::setY(float y){
    this->j=y;
}
/**
 * @brief Vector::setZ sets the Z component of the vector
 * @param z z component
 */
void Vector::setZ(float z){
    this->k=z;
}
/**
 * @brief Vector::scalarMul mutiplies the vector with the given scalar k
 * @param k A scalar
 */
void Vector::scalarMul(float k){
    this->i = k*this->i ;
    this->j = k*this->j ;
    this->k = k*this->k ;
}
/**
 * @brief Vector::magnitude
 * @return the magnitude
 */
float Vector::magnitude(){
    return sqrt(this->i*this->i + this->j*this->j + this->k*this->k) ;
}
/**
 * @brief Vector::setV sets the x, y, z component of the vector with the x,y,z component of the Vector v
 * @param v A Vector
 */
void Vector::setV(Vector v){
    this->i = v.getX() ;
    this->j = v.getY() ;
    this->k = v.getZ() ;
}
/**
 * @brief Vector::addV adds current Vector with the Vector vector
 * @param vector A Vector
 * @return return the net Vector obtained after addition
 */
Vector Vector::addV(Vector vector){
    Vector temp(0,0,0);

    temp.setX( (this->i + vector.getX()) );
    temp.setY((this->j + vector.getY()));
    temp.setZ((this->k +vector.getZ()));

    return temp;
}
/**
 * @brief Vector::substractV subtracts current Vector with the Vector vector
 * @param vector A vector
 * @return returns the vector obtained after subtraction
 */
Vector Vector::substractV(Vector vector){
    Vector temp(0,0,0);

        temp.setX( (this->i - vector.getX()) );
        temp.setY((this->j - vector.getY()));
        temp.setZ((this->k -vector.getZ()));

        return temp;
}
/**
 * @brief Vector::dotProductV performs dot multiplication of the current vector with the Vector vector
 * @param vector A vector
 * @return the result of the dot product
 */
float Vector::dotProductV(Vector vector){
    return ((this->i * vector.getX() ) + (this->j * vector.getY() ) + (this->k * vector.getZ() ));
}
/**
 * @brief Vector::crossProductV performs cross multiplication of the current vector with the Vector vector
 * @param vector A Vector
 * @return the result of the cross product
 */
Vector Vector::crossProductV(Vector vector){
    Vector temp(0,0,0);

    temp.setX( ((this->j * vector.getZ() ) - this->k*vector.getY()) );
    temp.setY( ((this->k * vector.getX() ) - this->i*vector.getZ()) );
    temp.setZ( ((this->i * vector.getY() ) - this->j*vector.getX()) );

    return temp;
}
/**
 * @brief Vector::normalize normalize the vector
 */
void Vector::normalize(){
    float magnitude= this->magnitude() ;
    if(magnitude == 0) return ;
    this->i=this->i/magnitude;
    this->j=this->j/magnitude;
    this->k=this->k/magnitude;
}
