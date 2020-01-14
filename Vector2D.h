#ifndef Vector2D_H_
#define Vector2D_H_

#include <math.h>
#include <string>
#include <time.h>
#include <iostream>
#include <stdlib.h>


using namespace std;

class Point2D;

class Vector2D
{
    public:
        double x;
        double y;
        Vector2D();
        Vector2D(double, double);
    
};

Vector2D operator*(Vector2D v1, double d);

Vector2D operator/(Vector2D v1, double d);

ostream& operator<<(ostream& out, Vector2D v1);

#endif
