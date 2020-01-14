#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_
#include "Point2D.h"

class GameObject
{
   protected:
        Point2D location;
        int id_num;
        char display_code;
        char state;
    public:
        GameObject();
        GameObject(char in_code);
        GameObject(Point2D in_loc, int in_id, char in_code);
        virtual bool Update() = 0;
        virtual bool ShouldBeVisible() = 0; //forgot to include in PA3
        void DrawSelf(char* ptr);
        Point2D GetLocation();
        int GetId();
        char GetState();
        virtual void ShowStatus();
    
    
};

#endif