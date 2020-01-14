#ifndef Pokemon_H_
#define Pokemon_H_
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Rival.h"
#include "BattleArena.h"


enum PokemonStates
{
	STOPPED = 0,
	MOVING = 1,
	EXHAUSTED = 2,
	IN_GYM = 3,
	IN_CENTER = 4,
	MOVING_TO_GYM = 5,
	MOVING_TO_CENTER = 6,
	TRAINING_IN_GYM = 7,
	RECOVERING_STAMINA = 8,
	IN_ARENA = 9,
	MOVING_TO_ARENA = 10,
	BATTLE = 11,
	FAINTED = 12
};

class Pokemon : public GameObject
{
	public:
		Pokemon(); //default constructor
		Pokemon(char in_code); //constructor
		Pokemon(string in_name, double speed, double hp, double phys_dmg, double magic_dmg, double def, int in_id, char in_code, Point2D in_loc); //constructor
		~Pokemon();
		void StartMoving(Point2D dest);
		void StartMovingToCenter(PokemonCenter* center);
		void StartMovingToGym(PokemonGym* gym);
		void StartTraining(unsigned int num_training_units);
		void StartRecoveringStamina(unsigned int num_stamina_points);
		void Stop();
		string GetName();
		char GetCode();
		bool IsExhausted();
		bool ShouldBeVisible();
		void ShowStatus();
		bool Update();
		bool isAlive();
		void TakeHit(double physical_damage, double magical_damage, double defense);
		void ReadyBattle(Rival* in_target);
		bool StartBattle();	
		void StartMovingToArena(BattleArena* arena);
	protected:
		bool UpdateLocation();
		void SetupDestination(Point2D dest);
		double health;
		double store_health;
		double physical_damage;
		double magical_damage;
		double defense;
		Rival* target;
		bool is_in_arena;
		BattleArena* current_arena;
	
	private:
		double speed; //speed obj travels per time unit
		bool is_in_gym = false; //set to true if pk is in gym, inital value should == false
		bool is_in_center = false; //set to true if pk is in center, initial value should == flase
		unsigned int stamina; //stamina of pk
		unsigned int experience_points; //experience points of pk
		double pokemon_dollars; // $$$ held by pk
		unsigned int training_units_to_buy;
		unsigned int stamina_points_to_buy;
		string name; //pk name
		PokemonCenter* current_center = NULL; //pointer to center
		PokemonGym* current_gym = NULL; //pointer to gym
		Point2D destination; //pk current destiantion coords
		Vector2D delta; //contains the x & y amts that object will move on each time unit
};

static double GetRandomAmountOfPokemonDollars(); //generates random num btwn 0.0 and 2.0



#endif