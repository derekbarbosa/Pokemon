#ifndef Model_H_
#define Model_H_

#include "Pokemon.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Rival.h"
#include "BattleArena.h"
#include "View.h"
#include "Input_Handling.h"
#include <list>


class Model
{
	private:
		int time;
		Model(const Model&);

		list <GameObject*> object_ptrss;
		list <Pokemon*> pokemon_ptrss;
		list <PokemonGym*> gym_ptrss;
		list <PokemonCenter*> center_ptrss;
		list <Rival*> rival_ptrss;
		list <BattleArena*> arena_ptrss;
		list <GameObject*> active_ptrs;
	public:
		Model();
		~Model();
		Pokemon* GetPokemonPtr(int id);
		PokemonCenter* GetPokemonCenterPtr(int id);
		PokemonGym* GetPokemonGymPtr(int id);
		Rival* GetRivalPtr(int id);
		BattleArena* GetArenaPtr(int id);
		bool Update();
		void Display(View &view);
		void ShowStatus();
		void NewCommand(char type, int id, int x, int y);



	
};

#endif