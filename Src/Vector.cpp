//
//  vector.cpp
//  vector
//
//  Created by Hana Makhlouf on 11/9/18.
//  Copyright © 2018 Hana Makhlouf. All rights reserved.
//

#include "vector.h"
//#include "cell.hpp"
//#include "material.hpp"
//#include "model.hpp"
#include <iostream>
using namespace std;

/*---------------------------------------------------------*/
Vector::Vector( float x, float y, float z ) { //constructor
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector::Vector() { //default constructor just in case no values are entered
    this->x = 0.;
    this->y = 0.;
    this->z = 0.;
}
/*---------------------------------------------------------*/

//add function
void Vector::add( Vector v ) {
    this->x += v.x;
    this->y += v.y;
    this->z += v.z;
}

//subtract function
void Vector::subtract( Vector v ){
    this->x -= v.x;
    this->y -= v.y;
    this->z -= v.z;
}

/*---------------------------------------------------------*/
//scalar product function
float Vector::scalarproduct( Vector v ){ //dot product
    float scalarresult = this->x*v.x + this->y*v.y + this->z*v.z;
    return scalarresult;
}

//vector product function - MUST BE A 3D VECTOR
Vector  Vector:: vectorproduct( Vector v){ //cross product
    float vectorresult1 = this->y*v.z - this->z*v.y;
    float vectorresult2 = this->z*v.x - this->x*v.z;
    float vectorresult3 = this->x*v.y - this->y*v.x;
    
    Vector final(vectorresult1,vectorresult2,vectorresult3);
    
    return final;
}
/*---------------------------------------------------------*/


/*Vector  vectorproduct( Vector v1, Vector v2 ){ //cross product
 float vectorresult1 = v1.y*v2.z - v1.z*v2.y;
 float vectorresult2 = v1.z*v2.x - v1.x*v2.z;
 float vectorresult3 = v1.x*v2.y - v1.y*v2.x;
 
 Vector final(vectorresult1,vectorresult2,vectorresult3);
 
 return final;
 }*/

float Vector::getx(){ return x; }
float Vector::gety(){ return y; }
float Vector::getz(){ return z; }

/*---------------------------------------------------------*/
