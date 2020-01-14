#include "GameCommand.h"

//CHANGED USER INPUT TO TAKE INPUT WITHIN THE FUNCTIONS

void DoMoveCommand(Model& model)
{
	int pokemon_id, x, y;

	cin >> pokemon_id >> x >> y;
	if(cin.fail()|| pokemon_id == 0)
	{
		throw Invalid_Input("Please enter a valid Pokemon ID, and valid co-ordinates!");
	}

	Point2D p1(x,y);

	Pokemon* P = model.GetPokemonPtr(pokemon_id);

	P -> StartMoving(p1);

	cout << "Moving" << " " << P -> GetName() << "to" << " " << p1;
}


void DoMoveToCenterCommand(Model& model)
{
	int pokemon_id, center_id;

	cin >> pokemon_id >> center_id;

	if(cin.fail() || pokemon_id == 0 || center_id == 0)
	{
		throw Invalid_Input("Please enter valid Pokemon & Center ID's!");
	}

	Pokemon* P = model.GetPokemonPtr(pokemon_id);

	PokemonCenter* C = model.GetPokemonCenterPtr(center_id);

	P -> StartMovingToCenter(C);

	cout << "Moving" << " " << P->GetName() << "to center" << " " << C->GetId() << endl;
}

void DoMoveToGymCommand(Model& model)
{
	int pokemon_id, gym_id;
	cin >> pokemon_id >> gym_id;

	if(cin.fail() || pokemon_id ==0 || gym_id == 0)
	{
		throw Invalid_Input("Please enter a valid pokemon ID and Gym ID!");
	}

	Pokemon* P = model.GetPokemonPtr(pokemon_id);

	PokemonGym* G = model.GetPokemonGymPtr(gym_id);

	P -> StartMovingToGym(G);

	cout << "Moving" << " " << P->GetName() << "to gym" << " " << G->GetId() << endl;
}

void DoStopCommand(Model& model)
{
	int pokemon_id;
	cin >> pokemon_id;
	if(cin.fail() || pokemon_id == 0)
	{
		throw Invalid_Input("Please enter a valid Pokemon ID!");
	}
	Pokemon* P = model.GetPokemonPtr(pokemon_id);

	P -> Stop();

	cout << "Stopping" << P->GetName() << " " << P->GetCode() << " " << P->GetId() << endl;
}

void DoTrainInGymCommand(Model& model)
{
	int pokemon_id;
	unsigned int training_units;
	if(cin.fail() || pokemon_id == 0 || training_units <= 0)
	{
		throw Invalid_Input("Please enter a valid Pokemon ID and valid training units!");
	}
	Pokemon* P = model.GetPokemonPtr(pokemon_id);

	P -> StartTraining(training_units);

	cout << "Training" << " " << P->GetName() << endl;
}

void DoRecoverInCenterCommand(Model& model)
{
	int pokemon_id;
	unsigned int stamina_points;
	if(cin.fail() || pokemon_id == 0 || stamina_points <= 0)
	{
		throw Invalid_Input("Please enter a valid Pokemon ID and valid stamina units!");
	}
	Pokemon* P = model.GetPokemonPtr(pokemon_id);

	P->StartRecoveringStamina(stamina_points);

	cout << "Recovering" << " " << P->GetName() << "'s Stamina." << endl;
}

void DoGoCommand(Model& model, View& view)
{
	model.Update(); //UPDATE ONCE
	model.ShowStatus();
	cout << "Advancing One Tick..." << endl;
}

void DoRunCommand(Model& model, View& view)
{
	int i = 0; //counter
	cout << "Advancing One Tick.." << endl; 

	while (model.Update() != true && i < 5) //while loop will run update regardless -> either it will return true or reach 5 counters
	{
		i++; //increment counter
	}
		
}

void DoMoveToArenaCommand(Model& model)
{
	int pokemon_id, arena_id;
	cin >> pokemon_id >> arena_id;

	if(cin.fail() || pokemon_id == 0 || arena_id == 0)
	{
		throw Invalid_Input("Please enter a valid Pokemon ID and Arena ID!");
	}

	Pokemon* P = model.GetPokemonPtr(pokemon_id);

	BattleArena* B = model.GetArenaPtr(arena_id);

	P->StartMovingToArena(B);
}

void DoBattleInArenaCommand(Model& model)
{
	int pokemon_id, rival_id;
	cin >> pokemon_id >> rival_id;

	if(cin.fail() || pokemon_id == 0 || rival_id == 0)
	{
		throw Invalid_Input("Please enter a valid Pokemon ID and Rival ID!");
	}

	Pokemon* P = model.GetPokemonPtr(pokemon_id);

	Rival* R = model.GetRivalPtr(rival_id);

	P->ReadyBattle(R);
}

void DoNewCommand(Model& model) 
{
	char TYPE;
	int id_num, x, y;

	cin >> TYPE >> id_num >> x >> y;

	if(cin.fail() || id_num == 0  || id_num > 9|| x < 0 || y < 0)
	{
		throw Invalid_Input("Please enter a valid Type, ID number, and co-ordinates! (ID NUM MUST BE <9)");
	}

	model.NewCommand(TYPE, id_num, x, y);
}