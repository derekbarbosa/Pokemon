#include "GameObject.h"


GameObject::GameObject()
{
    display_code = ' ';
}

GameObject::GameObject(char in_code)
{
    state = 0;
    display_code = in_code;
    id_num = 1;
    cout << "GameObject Constructed" << endl;
}

GameObject::GameObject(Point2D in_loc, int in_id, char in_code)
{
    state = 0;

    display_code = in_code;
    
    id_num = in_id;

    location = in_loc;
    
    cout << "GameObject Constructed" << endl;

}


int GameObject::GetId()
{
    return id_num;
}

char GameObject::GetState()
{
    return state;
}

void GameObject::ShowStatus()
{
    cout << this -> display_code << " " << this -> id_num << " at" << this -> location << endl;
}

Point2D GameObject::GetLocation()
{
    return location;
}

bool GameObject::Update()
{
    return false; //should never be used, as each object has its own "update" from hereon out (manual)
}

void GameObject::DrawSelf(char* pointer)
{
    *pointer = display_code; //put display code at the character that the pointer is pointing to (so derefrence, and store display code)
    *(pointer+1) = ('0' + id_num); //put ASCII character from id_num in the NEXT character (ptr+1) --> PULLED FROM STACKOVERFLOW!!
    //id_num becomes converted to char AND converted to ASCII, and can therefore be stored in pointer
}