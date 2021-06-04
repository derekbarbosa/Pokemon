#include "PokemonCenter.h"


PokemonCenter::PokemonCenter() //default constructor --> fix to include inhertiance
{
    this -> display_code = 'C';
    this -> stamina_capacity = 100;
    this -> num_stamina_points_remaining = stamina_capacity;
    this -> dollar_cost_per_stamina_point = 5;
    this -> state = STAMINA_POINTS_AVAIALBLE;
    cout << "PokemonCenter default constructed"<< endl;
}

PokemonCenter::PokemonCenter(int in_id, double stamina_cost, unsigned int stamina_cap, Point2D in_loc)
{
    this -> display_code = 'C';
    this -> id_num = in_id;
    this -> location = in_loc;
    this -> dollar_cost_per_stamina_point = stamina_cost;
    this -> stamina_capacity = stamina_cap;
    this -> num_stamina_points_remaining = stamina_capacity;
    this -> state = STAMINA_POINTS_AVAIALBLE;
    cout << "PokemonCenter constructed"<< endl;
}

PokemonCenter::~PokemonCenter()
{
    cout << "PokemonCenter Destructed." << endl;
}


bool PokemonCenter::HasStaminaPoints()
{
    if((this -> num_stamina_points_remaining >= 1 ))
        return true;
    else 
        return false;
}

unsigned int PokemonCenter::GetNumStaminaPointsRemaining()
{
    return this -> num_stamina_points_remaining;
}

bool PokemonCenter::CanAffordStaminaPoints(unsigned int stamina_points, double budget)
{
    if(budget - (stamina_points * (this -> dollar_cost_per_stamina_point)) >= 0)
        return true;
    else 
        return false;
}

double PokemonCenter::GetDollarCost(unsigned int stamina_points)
{
    return ((this -> dollar_cost_per_stamina_point) * stamina_points);
}

unsigned int PokemonCenter::DistributeStamina(unsigned int points_needed)
{
    unsigned int retval = 0;

    if((this -> num_stamina_points_remaining) >= points_needed)
    {
        (this -> num_stamina_points_remaining) -= points_needed;
	retval = points_needed;
    }
    else if(num_stamina_points_remaining < points_needed)
    {
        retval = (this -> num_stamina_points_remaining);
        num_stamina_points_remaining = 0;
    }
    
    return retval;
}

bool PokemonCenter::Update()
{
    bool retval;
    if(this -> num_stamina_points_remaining == 0)
    {
        this -> state = NO_STAMINA_POINTS_AVAIALBLE;
        this -> display_code = 'c';
        cout << "PokemonCenter" << this -> id_num << " has ran out of stamina points." << endl;
        retval = true;
    }
    else if (this -> num_stamina_points_remaining > 0){
        retval = false;
    }
    
    return retval;
}

void PokemonCenter::ShowStatus()
{
    cout << "PokemonCenter Status: ";
    Building::ShowStatus();
    cout << "\t Pokemon dollars per stamina point: " << this -> dollar_cost_per_stamina_point << endl;
    cout << "\t has " << this -> num_stamina_points_remaining << " stamina points remaining." << endl;

}
