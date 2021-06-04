#include "BattleArena.h"

BattleArena::BattleArena()
{
	display_code = 'A';
	pokemon_count = 0;
	max_num_rivals = 3;
	num_rivals_remaining = max_num_rivals;
	dollar_cost_per_fight = 4;
	stamina_cost_per_fight = 3;
	state = RIVALS_AVAILABLE;
	
	cout << "BattleArena default constructed" << endl;
}

BattleArena::BattleArena(unsigned int max_rivals, unsigned int stamina_cost, double dollar_cost, int in_id, Point2D in_loc):Building('A', in_id, in_loc)
{
	id_num = in_id;
	stamina_cost_per_fight = stamina_cost;
	dollar_cost_per_fight = dollar_cost;
	max_num_rivals = max_rivals;
	location = in_loc;
	state = RIVALS_AVAILABLE;

	cout << "BattleArena constructed" << endl;
}

unsigned int BattleArena::GetNumRivalsRemaining()
{
	return num_rivals_remaining;
}

bool BattleArena::HasEnoughRivals()
{
	if(num_rivals_remaining > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

double BattleArena::GetDollarCost()
{
	return dollar_cost_per_fight;
}

unsigned int BattleArena::GetStaminaCost()
{
	return stamina_cost_per_fight;
}

bool BattleArena::IsAbleToFight(double budget, unsigned int stamina)
{
	if(budget - this->dollar_cost_per_fight >=0 && stamina - this->stamina_cost_per_fight >=0)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

bool BattleArena::Update()
{
	if(num_rivals_remaining < 0)
	{
		return false;
	}
	else if (num_rivals_remaining == 0)
	{
		state = NO_RIVALS_AVAILABLE;
		return true;
	}
	
	return false;
}

bool BattleArena::IsBeaten()
{
	if(num_rivals_remaining==0)
	{
		state = NO_RIVALS_AVAILABLE;
		return true;
	}
	else
	{
		return false;
	}
	
}

void BattleArena::ShowStatus()
{
	GameObject::ShowStatus();
	cout << "\t Max Number of Rivals: " << " " << "<" << max_num_rivals << " >" << endl;
	cout << "\t Stamina Cost Per Fight:" << " " << "<" << stamina_cost_per_fight << ">" << endl;
	cout << "\t Pokemon Dollar Cost Per Fight" << " " << "<" << dollar_cost_per_fight << ">" << endl;
	cout << "\t" << num_rivals_remaining << " " << "rival(s) are remaining for this arena" << endl;
}
