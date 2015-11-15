/*
 * vector.h
 *
 *  Created on: 07-Aug-2013
 *      Author: atul
 */

#ifndef VECTOR_H_
#define VECTOR_H_
class Vector{
private :
    float i;
    float j;
    float k;

public:
    Vector();
    Vector(float x, float y, float z) ;

    float getX();
    float getY();
    float getZ();

    void setX(float x);
    void setY(float y);
    void setZ(float z);

    void setV(Vector v) ;
    void scalarMul(float k) ;
    float magnitude() ;
    Vector  addV(Vector vector);
    Vector  substractV(Vector vector);
    float dotProductV(Vector vector);
    Vector crossProductV(Vector vector);

    void normalize();
};
#endif /* VECTOR_H_ */
