#include "Building.h"

Building::Building() //default constructor --> fix to include inheritance
{
    display_code = 'B';
    cout << "Building Default Constructed." << endl;
}

Building::Building(char in_code, int in_id, Point2D in_loc)
{
    display_code = in_code;
    id_num = in_id;
    location = in_loc;
    cout << "Building Constructed." << endl;
}

void Building::AddOnePokemon()
{
    pokemon_count = pokemon_count++;
}

void Building::RemoveOnePokemon()
{
    pokemon_count = pokemon_count--;
}

void Building::ShowStatus()
{
    if(pokemon_count == 1)
        cout << "\t" << this -> pokemon_count << "pokemon is in this building." << endl;
    else if (pokemon_count > 1)
        cout << "\t" << this -> pokemon_count << "pokemon are in this building." << endl;
}

bool Building::ShouldBeVisible()
{
    return true;
}