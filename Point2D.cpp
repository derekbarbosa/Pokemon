#include "Point2D.h"
#include <math.h> 
using namespace std;

Point2D::Point2D()
{   
    x = 0;
    y = 0;
}
    
Point2D::Point2D(double in_x, double in_y)
{
    x = in_x;
    y = in_y;
}

double GetDistanceBetween(Point2D p1, Point2D p2)
{
    double distance = 0;
    double A = p1.x - p2.x; //sets A = to the delta of the x-coords of p1 and p2
    double B = p1.y - p2.y; //sets B = to the delta of the y-coords of p1 and p2

    A = pow(A,2); // A = a^2
    B = pow(B,2); // B = b^2

    distance = A+B; //sets distance to A^2 + B^2
    distance = sqrt(distance); // sets distance = sqrt of sum of both terms squared

    return distance; //returns the cartesian distance
}

ostream& operator<<(ostream& out, Point2D p1)
{
    
    out << "(" << p1.x << "," << p1.y << " )";
    
    return out;
}


Point2D operator+(Point2D p1, Vector2D v1) 
{
    Point2D newP = Point2D();
    newP.x = p1.x + v1.x;
    newP.y = p1.y + v1.y;

    return newP;
}

Vector2D operator-(Point2D p1, Point2D p2) 
{
    Vector2D newV = Vector2D();
    newV.x = p1.x - p2.x;
    newV.y = p1.y - p2.y;

    return newV;
}