//
//  vector.h
//  vector
//
//  Created by Hana Makhlouf on 11/9/18.
//  Copyright © 2018 Hana Makhlouf. All rights reserved.
//

#ifndef vector_h
#define vector_h


#include <iostream>
#include <math.h>
using namespace std;

class Vector{
public:

// Overload + and - operator to add two 2 vectors
	Vector operator+(Vector v);
	Vector operator-(Vector v);

	Vector();
	Vector( float x, float y, float z ); //initialise
    
	void SetVector(int iD, float x, float y, float z);
	void print();

	//add, subtract, scalar and vector product with no operator overloading
    void add( Vector v );
    void subtract( Vector v);
    float scalarproduct (Vector v);
    Vector vectorproduct (Vector v);

    float getx(); //{ return x; }
    float gety(); //{ return y; }
    float getz(); //{ return z; }


    //friend Vector vectorproduct( Vector v1, Vector v2 );

private:
    int ID;
    float x;
    float y;
    float z;

};


#endif /* vector_h */
