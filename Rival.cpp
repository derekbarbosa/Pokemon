#include "Rival.h"

Rival::Rival(string in_name, double speed, int id, Point2D in_loc):GameObject(in_loc, id, 'P')
{
	speed = 5;
	name = in_name;
	cout << "Rival constructed" << endl;
}

double Rival::get_phys_dmg()
{
	return physical_damage;
}

double Rival::get_magic_dmg()
{
	return magical_damage;
}

double Rival::get_defense()
{
	return defense;
}

bool Rival::isAlive()
{
	if(this -> state == FAINTED_RIVAL || this -> health <= 0) //checks is rival is fainted (or if health is <= 0)
	{	
		state = FAINTED_RIVAL; //sets state to fainted (defensive programming -> rival will stay fainted)
		return false; 
	}
	else
	{
		state = ALIVE_RIVAL;
		return true; //otherwise, return true
	}
}

void Rival::TakeHit(double physical_damage, double magical_damage, double defense) //call in startbattle() ensure health of rival or Pokemon first
{
	srand(time(NULL)); 
	double random_number = rand() % 1; //generates random number between 0 and 1
	double damage_type = 0;
	double damage = 0;

	if(random_number == 0) //as stated in manual, use random number to determine damage type
	{
		damage_type = magical_damage;
	}
	else if (random_number = 1)
	{
		damage_type = physical_damage;
	}

	damage = (100.0-defense)/100 * damage_type; //damage calculation

	this -> health = this -> health - damage; //subtracts damage from health
}

bool Rival::Update() //as stated in manual
{
	switch (this -> state)
	{
		case ALIVE_RIVAL:
			return false;
			break;
		case FAINTED_RIVAL:
			return true;
	}
}

bool Rival::ShouldBeVisible()
{
	if(state != FAINTED_RIVAL)
	{
		return true;
	}
}

string Rival::get_name()
{
	return this -> name;
}

double Rival::get_health()
{
	return health;
}

void Rival::ShowStatus()
{
	GameObject::ShowStatus();

	switch (state)
	{
		case ALIVE_RIVAL:
			cout << "\tRival" << " " << this -> GetId() << " " << "is alive." << endl;
			cout << " \thealth:" << " " << this->get_health() << endl;
			cout << "\t in arena:" << " " << this->current_arena->GetLocation() << endl;
		break;
	
		case FAINTED_RIVAL:
			cout << "Rival" << " " << this -> GetId() << " " << this -> get_name() << " " << "is fainted." << endl;
		break;
	}

}
