#include "Model.h"

Model::Model()
{
	//no longer needed --> only time 
	this -> time = 0;

	//create 5 point2D objects with addresses corresponding to where each obj is located (object parameters require points!)
	Point2D point1 = Point2D(5,1); //pk ptr1
	Point2D point2 = Point2D(10,1); //pk ptr2
	Point2D point3 = Point2D(1,20); //center ptr1
	Point2D point4 = Point2D(10,20); //center ptr2
	Point2D point5 = Point2D(0,0); //gym ptr 1
	Point2D point6 = Point2D(5,5); //gym ptr 2
	Point2D point7 = Point2D(15,12); //arena ptr1

	//create OBJ pointers for Pokemon
	Pokemon* P1 = new Pokemon("Pikachu", 5, 20, 5, 4, 15, 1, 'P', point1); //Done according to manual 
	Pokemon* P2 = new Pokemon("Bulbasaur",5, 20, 5 ,4 , 15,  2, 'P', point2);

	//PK Pointers Array Initialization
	this -> pokemon_ptrss.push_back(P1);
	this -> pokemon_ptrss.push_back(P2);

	//OBJ Pointers for Pokemon Center
	PokemonCenter* C1 = new PokemonCenter(1, 1, 100, point3);
	PokemonCenter* C2 = new PokemonCenter(2, 2, 200, point4);

	//Center Pointers Array Initialization
	this -> center_ptrss.push_back(C1);
	this -> center_ptrss.push_back(C2);

	//OBJ pointers for Pokemon Gym
	PokemonGym* G1 = new PokemonGym(10, 1, 2, 3, 1, point5);
	PokemonGym* G2 = new PokemonGym(20, 5, 7.5, 8, 2, point6);

	//Gym pointers array Initialization
	this -> gym_ptrss.push_back(G1);
	this -> gym_ptrss.push_back(G2);

	//OBJ pointers for Battle Arena
	BattleArena* B1 = new BattleArena(3, 3, 4, 1, point7);

	//Battle Arena Array Initialization
	this -> arena_ptrss.push_back(B1);

	//OBJ Pointers for Rivals
	Rival* R1 = new Rival("Rival Densmore", 5, 1, point7);
	Rival* R2 = new Rival("Rival Burak", 5, 2, point7);
	Rival* R3 = new Rival("Rival Miguel",5 , 3, point7);

	//Rival list initalization
	this -> rival_ptrss.push_back(R1);
	this -> rival_ptrss.push_back(R2);
	this -> rival_ptrss.push_back(R3);

	//obj ptrs in list format --> all contents push front to back
	this -> object_ptrss.push_back(P1);
	this -> object_ptrss.push_back(P2);
	this -> object_ptrss.push_back(C1);
	this -> object_ptrss.push_back(C2);
	this -> object_ptrss.push_back(G1);
	this -> object_ptrss.push_back(G2);
	this -> object_ptrss.push_back(B1);
	this -> object_ptrss.push_back(R1);
	this -> object_ptrss.push_back(R2);
	this -> object_ptrss.push_back(R3);

	this -> active_ptrs.push_back(P1);
	this -> active_ptrs.push_back(P2);
	this -> active_ptrs.push_back(C1);
	this -> active_ptrs.push_back(C2);
	this -> active_ptrs.push_back(G1);
	this -> active_ptrs.push_back(G2);
	this -> active_ptrs.push_back(B1);
	this -> active_ptrs.push_back(R1);
	this -> active_ptrs.push_back(R2);
	this -> active_ptrs.push_back(R3);

	cout << "Model default constructed" << endl;
}

//replaced to work with linked lists
Model::~Model()
{
	list <GameObject*>::iterator i;

	for (i = this -> object_ptrss.begin();i != this -> object_ptrss.end(); i++) //for loop iterates through array of objects[num_objects] and deletes each one
	{
		delete *i; //because the list is a pointer to objects, we must deref the value!
	}
	
	cout << "Model Destructed." << endl;
}

//replaced to work with linked lists
Pokemon* Model::GetPokemonPtr(int id)
{
	//search pokemonptrs & see if it matches input id

	//search --> means for loop, create for loop & search array

	//FOLLOW THIS FOR ALL GET 

	list <Pokemon*>::iterator i;

	for(i = this -> pokemon_ptrss.begin(); i != this -> pokemon_ptrss.end(); i++) //comparison operator '<' doesnt work.. so we have to use !=
	{
		if( (*i) -> GetId() == id) //DEREFERENCE TO OBTAIN VALUE!
		{
			return *i;
		}
	}

	return NULL;
}

PokemonCenter* Model::GetPokemonCenterPtr(int id)
{
	list <PokemonCenter*>::iterator i;

	for(i = this -> center_ptrss.begin(); i != this -> center_ptrss.end() ; i++)
	{
		if((*i) -> GetId() == id)
		{
			return (*i);
		}
	}
	return NULL;
}


PokemonGym* Model::GetPokemonGymPtr(int id)
{
	list <PokemonGym*>::iterator i;

	for(i = this -> gym_ptrss.begin() ; i != this -> gym_ptrss.end(); i++)
	{
		if((*i) -> GetId() == id)
		{
			return *i;
		}
	}
	return NULL;
	
}

Rival* Model::GetRivalPtr(int id)
{
	list <Rival*>::iterator i;

	for(i = this -> rival_ptrss.begin(); i != this -> rival_ptrss.end() ; i++)
	{
		if((*i) -> GetId() == id)
		{
			return (*i);
		}
	}
	
	return NULL;
}

BattleArena* Model::GetArenaPtr(int id)
{
	list <BattleArena*>::iterator i;

	for (i = this -> arena_ptrss.begin(); i != this -> arena_ptrss.end(); i++)
	{
		if((*i) -> GetId() == id)
		{
			return *i;
		}
	}

	return NULL;
}


bool Model::Update()
{
	time++; //time increments regardless

	//check if all gyms are beaten!

	for(list <PokemonGym*>::iterator i = this -> gym_ptrss.begin(); i != this -> gym_ptrss.end(); i++)
	{
		bool winGame = true; //boolean value that "flips" depending on whether or not all gyms have been beaten

		if((*i) -> IsBeaten() == true)
		{
			winGame = true;
		}
		else
		{
			winGame = false;
		}
		//if wingame is true, triggers win message & exits the game!
		if(winGame == true)
		{
			cout << "GAME OVER: You Win! All Pokemon Gyms beaten!" << endl;
			exit(0);
		}
		
	}

	//check if all pokemon are exhausted!
	for(list <Pokemon*>::iterator i = this -> pokemon_ptrss.begin(); i != this -> pokemon_ptrss.end(); i++)
	{

		bool loseGame = true; //boolean value that "flips" depending on whether or not all pk have been exhausted

		if((*i) -> IsExhausted())
		{
			loseGame = true;
		}
		else
		{
			loseGame = false;
		}

		//if loseGame is true, will trigger fail message
		if(loseGame == true)
		{
			cout << "GAME OVER: You lose! :( All of your Pokemon are tired !" << endl;
			exit(0);
		}
	}

	//check if objects are alive!

	for(list<GameObject*>::iterator i = this -> active_ptrs.begin(); i!= this -> active_ptrs.end(); i++)
	{
		if((*i) -> GetState() == FAINTED) //if state is fainted!
		{
			i = active_ptrs.erase(i); //pulled from StackOverflow, you need to set i = erase(i), so iterator location can be moved to the object after you erased
			cout << "\tDead Object Removed" << endl;
		}
	}

	bool retval;
	for(list <GameObject*>::iterator i = this -> active_ptrs.begin(); i != this -> active_ptrs.end(); i++) //for loop, iterates through array of object ptrs and updates them using gameobject update
	{
		(*i) -> Update(); //updates each gameobject first 

		if((*i) -> Update() == true) // then does a for loop to see if they return true or not --> StackOverflow
		{
			retval = true; //done according to manual
		}
		else
		{
			retval = false; //manual said  "generally, if same state, return false"
		}
	}

	return retval;
}

void Model::Display(View& view)
{
	cout << "time:" << this -> time << endl;

	view.Clear(); //prepare the grid

	for (list <GameObject*>::iterator i = this -> active_ptrs.begin(); i != this -> active_ptrs.end(); i++) //plot all objects for the display
	{
		view.Plot(*i);
	}

	view.Draw(); //draw all objects
}

void Model::ShowStatus()
{
	for(list <GameObject*>::iterator i = this -> object_ptrss.begin(); i != this -> object_ptrss.end(); i++) //for loop, iterates through array of object ptrs and calls their showstatus
	{
		(*i) -> ShowStatus(); //calls showstatus for each object
	}
}

void Model::NewCommand(char type, int id, int x, int y)
{
	Point2D nPoint(x,y);

	switch(type) //needed to add brackets to case statements, as I couldn't initalize my pointer variables
	{
		case 'g': //new gym! //iterate through the for loop and check if ID num already exists
		{
			for(list <PokemonGym*>::iterator i = this -> gym_ptrss.begin(); i != this -> gym_ptrss.end(); i++)
			{
				if((*i)->GetId() == id)
				{
					throw Invalid_Input("Please choose an ID number that doesnt already exist!");
				}
			}
			//if passes the conditions, new pointer on the heap using default constructor!
			PokemonGym* GymPtr = new PokemonGym(10, 1, 1, 2, id, nPoint);

			//done according to manual --> push back on heap
			this -> gym_ptrss.push_back(GymPtr);
			this ->	object_ptrss.push_back(GymPtr);
			this ->	active_ptrs.push_back(GymPtr);
			cout << "New Gym Created Successfully" << endl;

			break;
		}
		case 'c':
		{
			for(list <PokemonCenter*>::iterator i = this -> center_ptrss.begin(); i != this -> center_ptrss.end(); i++)
			{
				if((*i)->GetId() == id)
				{
					throw Invalid_Input("Please choose an ID number that doesnt already exist!");
				}
			}
			PokemonCenter* CenterPtr = new PokemonCenter(id, 5, 100, nPoint);
			this -> center_ptrss.push_back(CenterPtr);
			this -> object_ptrss.push_back(CenterPtr);
			this -> active_ptrs.push_back(CenterPtr);

			break;
		}
		case 'p':
		{
			for(list <Pokemon*>::iterator i = this -> pokemon_ptrss.begin(); i != this -> pokemon_ptrss.end(); i++)
			{
				if((*i)->GetId() == id)
				{
					throw Invalid_Input("Please choose an ID number that doesnt already exist!");
				}
			}
			Pokemon* PokePointer = new Pokemon("New Pokemon", 5, 20, 5, 4, 15, id, 'P', nPoint);
			this -> pokemon_ptrss.push_back(PokePointer);
			this -> object_ptrss.push_back(PokePointer);
			this -> active_ptrs.push_back(PokePointer);

			break;
		}
		case 'r':
		{
			for(list <Rival*>::iterator i = this -> rival_ptrss.begin(); i != this -> rival_ptrss.end(); i++)
			{
				if((*i)->GetId() == id)
				{
					throw Invalid_Input("Please choose an ID number that doesnt already exist!");
				}
			}
			Rival* RivalPtr = new Rival("New Rival", 5, id, nPoint);

			this -> rival_ptrss.push_back(RivalPtr);
			this -> object_ptrss.push_back(RivalPtr);
			this -> active_ptrs.push_back(RivalPtr);
			break;
		}
		case 'a':
		{
			BattleArena* ArenaPtr = new BattleArena(3,3,2.5, id, nPoint);
			this -> object_ptrss.push_back(ArenaPtr);
			this -> active_ptrs.push_back(ArenaPtr);
			this -> arena_ptrss.push_back(ArenaPtr);
		}
		default:
		{
			cout << "how'd you get here, bud?" << endl;
			throw Invalid_Input("INVALID TYPE");
			//nothing happens here
		}
	}
}
