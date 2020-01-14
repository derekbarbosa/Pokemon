#include "Vector2D.h"


Vector2D::Vector2D()
{
    x = 0;
    y = 0;
}

Vector2D::Vector2D(double in_x, double in_y)
{
    x = in_x;
    y = in_y;
}

Vector2D operator*(Vector2D v1, double d)
{
    Vector2D newV;

    newV.x = v1.x * d;
    newV.y = v1.y * d;
    
    return newV;
}

Vector2D operator/(Vector2D v1, double d)
{
   if(d==0)
   {
       v1.x = v1.x;
       v1.y = v1.y;
       
       return v1;
   }
    else
    {
        Vector2D newV;
        newV.x = v1.x / d;
        newV.y = v1.y / d;

        return newV;
    }
    
}

ostream& operator<<(ostream& out, Vector2D v1)
{
    out <<  "<" << v1.x << ", " << v1.y << ">";
    return out;
}


