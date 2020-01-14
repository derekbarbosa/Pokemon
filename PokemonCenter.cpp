#include "PokemonCenter.h"


PokemonCenter::PokemonCenter() //default constructor --> fix to include inhertiance
{
    display_code = 'C';
    stamina_capacity = 100;
    num_stamina_points_remaining = stamina_capacity;
    dollar_cost_per_stamina_point = 5;
    state = STAMINA_POINTS_AVAIALBLE;
    cout << "PokemonCenter default constructed"<< endl;
}

PokemonCenter::PokemonCenter(int in_id, double stamina_cost, unsigned int stamina_cap, Point2D in_loc)
{
    display_code = 'C';
    id_num = in_id;
    location = in_loc;
    dollar_cost_per_stamina_point = stamina_cost;
    stamina_capacity = stamina_cap;
    num_stamina_points_remaining = stamina_capacity;
    state = STAMINA_POINTS_AVAIALBLE;
    cout << "PokemonCenter constructed"<< endl;
}

PokemonCenter::~PokemonCenter()
{
    cout << "PokemonCenter Destructed." << endl;
}


bool PokemonCenter::HasStaminaPoints()
{
    if(num_stamina_points_remaining >= 1 )
        return true;
    else 
        return false;
}

unsigned int PokemonCenter::GetNumStaminaPointsRemaining()
{
    return num_stamina_points_remaining;
}

bool PokemonCenter::CanAffordStaminaPoints(unsigned int stamina_points, double budget)
{
    if(budget - (stamina_points * dollar_cost_per_stamina_point) >= 0)
        return true;
    else 
        return false;
}

double PokemonCenter::GetDollarCost(unsigned int stamina_points)
{
    return (dollar_cost_per_stamina_point * stamina_points);
}

unsigned int PokemonCenter::DistributeStamina(unsigned int points_needed)
{
    if(num_stamina_points_remaining >= points_needed)
    {
        num_stamina_points_remaining -= points_needed;
    }
    else if(num_stamina_points_remaining < points_needed)
    {
        return num_stamina_points_remaining;
        num_stamina_points_remaining = 0;
    }
}

bool PokemonCenter::Update()
{
    if(num_stamina_points_remaining == 0)
    {
        state = NO_STAMINA_POINTS_AVAIALBLE;
        display_code = 'c';
        cout << "PokemonCenter" << id_num << " has ran out of stamina points." << endl;
        return true;
    }
    else if (num_stamina_points_remaining > 0)
        return false;
    
}

void PokemonCenter::ShowStatus()
{
    cout << "PokemonCenter Status: ";
    Building::ShowStatus();
    cout << "\t Pokemon dollars per stamina point: " << dollar_cost_per_stamina_point << endl;
    cout << "\t has " << num_stamina_points_remaining << " stamina points remaining." << endl;

}