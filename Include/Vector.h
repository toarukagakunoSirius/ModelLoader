//
//  vector.h
//  vector
//
//  Created by Hana Makhlouf on 11/9/18.
//  Copyright © 2018 Hana Makhlouf. All rights reserved.
//

#ifndef vector_h
#define vector_h

#include <stdio.h>
using namespace std;

class Vector{
public:
    Vector( float x, float y, float z );
    Vector();

    void add( Vector v );
    void subtract( Vector v);
    float scalarproduct (Vector v);
    Vector vectorproduct (Vector v);

    float getx(); //{ return x; }
    float gety(); //{ return y; }
    float getz(); //{ return z; }

	//Still working on this part
// Overload + operator to add two 2 vectors
	Vector operator+(const Vector& v) {
		Vector vector1;
		vector1.add = this->add + v.add;
		return vector1;

    //friend Vector vectorproduct( Vector v1, Vector v2 );

private:
    int ID;
    float x;
    float y;
    float z;

};


#endif /* vector_h */
