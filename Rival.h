#include "BattleArena.h"
#ifndef Rival_H_
#define Rival_H_

enum RivalStates 
{
	ALIVE_RIVAL = 1,
	FAINTED_RIVAL = 2
};

class Rival: public GameObject
{
	protected:
		double health = 20;
		double physical_damage = 5;
		double magical_damage = 4;
		double defense = 15;
		double stamina_cost_per_fight;
		bool is_in_arena;
		string name;
		BattleArena* current_arena;
	public:
		Rival(string in_name, double speed, int id, Point2D in_loc);
		void TakeHit(double physical_damage, double magical_damage, double defense); //same as PK
		double get_phys_dmg();
		double get_magic_dmg();
		double get_defense();
		double get_health();
		string get_name();
		bool Update();
		void ShowStatus();
		bool isAlive();
		bool ShouldBeVisible();


};


#endif