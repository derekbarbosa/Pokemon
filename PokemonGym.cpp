#include "PokemonGym.h"
using namespace std;

PokemonGym::PokemonGym()
{
	display_code = 'G';
	state = NOT_BEATEN;
	max_number_of_training_units = 10;
	num_training_units_remaining = max_number_of_training_units;
	stamina_cost_per_training_unit = 1;
	dollar_cost_per_training_unit = 1.0;
	experience_points_per_training_unit = 2;
	cout << "PokemonGym default constructed." << endl;
}

PokemonGym::PokemonGym(unsigned int max_training_units, unsigned int stamina_cost, double dollar_cost, unsigned int exp_points_per_unit, int in_id, Point2D in_loc)
{
	display_code = 'G';
	state = NOT_BEATEN;
	id_num = in_id;
	max_number_of_training_units = max_training_units;
	num_training_units_remaining = max_number_of_training_units;
	stamina_cost_per_training_unit = stamina_cost;
	experience_points_per_training_unit = exp_points_per_unit;
	dollar_cost_per_training_unit = dollar_cost;
	location = in_loc;
	cout << "PokemonGym Constructed" << endl;
}

PokemonGym::~PokemonGym()
{
	cout << "PokemonGym Destructed." << endl;
}

double PokemonGym::GetDollarCost(unsigned int unit_qty)
{
	return (dollar_cost_per_training_unit * unit_qty);
}

unsigned int PokemonGym::GetStaminaCost(unsigned int unit_qty)
{
	return (stamina_cost_per_training_unit * unit_qty);
}

unsigned int PokemonGym::GetNumTrainingUnitsRemaining()
{
	return (num_training_units_remaining);
}

bool PokemonGym::IsAbleToTrain(unsigned int unit_qty, double budget, unsigned int stamina)
{
	if ( (budget - (unit_qty * dollar_cost_per_training_unit) >= 0) && (stamina - (unit_qty *stamina_cost_per_training_unit) >= 0) )
		return true;
	else
		return false;
}

unsigned int PokemonGym::TrainPokemon(unsigned int training_units)
{
	if(num_training_units_remaining >= training_units)
	{
		num_training_units_remaining -= training_units;
		unsigned int experience_points = num_training_units_remaining * experience_points_per_training_unit;
		return (experience_points);
	}
	else if (num_training_units_remaining < training_units)
	{
		unsigned int experience_points = num_training_units_remaining * experience_points;
		return experience_points;
	}
	
}

bool PokemonGym::Update()
{
	if(num_training_units_remaining == 0)
	{
		state = BEATEN;
		display_code = 'g';
		cout << display_code << " " << id_num << "has been beaten." << endl;
		return true;
	}
	else if (num_training_units_remaining > 0)
	{
		return false;
	}
}

bool PokemonGym::IsBeaten()
{
	if(num_training_units_remaining == 0)
		return true;
}

void PokemonGym::ShowStatus()
{
	cout << " " << endl;
	cout << "PokemonGym Status: ";
	Building::ShowStatus();
	cout << "\t Max Number of Training Units: " << max_number_of_training_units << endl;
	cout << "\t Stamina Cost per Training Unit: " << stamina_cost_per_training_unit << endl;
	cout << "\t Pokemon Dollar Cost per Training Unit: " << dollar_cost_per_training_unit << endl;
	cout << "\t Experience points per Training Unit: " << experience_points_per_training_unit << endl;
	cout << "\t " << num_training_units_remaining << " training unit(s) are remaining for this gym." << endl;
}