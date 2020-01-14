#ifndef Building_H_
#define Building_H_

#include "GameObject.h"


class Building: public GameObject
{
    private:
        unsigned int pokemon_count = 0; //# of PK in building
    public:
        void AddOnePokemon(); 
        void RemoveOnePokemon();
        void ShowStatus();
        bool ShouldBeVisible();
        Building(); //default constructor
        Building(char in_code, int in_id, Point2D in_loc); //constructor
   

};

#endif