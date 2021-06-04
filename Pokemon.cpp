#include "Pokemon.h"

Pokemon::Pokemon():GameObject('P') 
{
	this -> stamina_points_to_buy = 0;
	this -> training_units_to_buy = 0;
	this -> pokemon_dollars = 0;
	this -> experience_points = 0;
	this -> speed = 5;
	this -> stamina = 20;
	cout << "Pokemon default constructed." << endl;
}

Pokemon::Pokemon(char in_code):GameObject('P')
{
	this -> stamina_points_to_buy = 0;
	this -> training_units_to_buy = 0;
	this -> pokemon_dollars = 0;
	this -> experience_points = 0;
	this -> speed = 5;
	this -> stamina = 20;
	this -> state = STOPPED;
	this -> display_code = in_code;
	cout << "Pokemon Constructed." << endl;
	this -> health = 20;
	this -> store_health = 20;
	this -> physical_damage = 5;
	this -> magical_damage = 4;
	this -> defense = 15;
	this -> stamina = 20;
}

Pokemon::Pokemon(string in_name, double in_speed, double hp, double phys_dmg, double magic_dmg, double def, int in_id, char in_code, Point2D in_loc):GameObject(in_loc, in_id, 'P')
{
	this -> stamina_points_to_buy = 0;
	this -> training_units_to_buy = 0;
	this -> pokemon_dollars = 0;
	this -> experience_points = 0;
	this -> stamina = 20;
	this -> name = in_name;
	this -> display_code = in_code;
	this -> state = STOPPED;
	cout << "Pokemon Constructed." << endl;
	this -> health = hp;
	this -> store_health = hp;
	this -> physical_damage = phys_dmg;
	this -> magical_damage = magic_dmg;
	this -> defense = def;
	this -> speed = in_speed;
}

Pokemon::~Pokemon()
{
	cout << "Pokemon Destructed." << endl;
}
 
void Pokemon::StartMoving(Point2D dest)
{
	if( this -> location.x == dest.x && this -> location.y == dest.y){
		cout << this -> display_code << " " << this -> id_num  << ": I'm already there. See?" << endl;
		state = STOPPED; 
	}
	else if (this -> IsExhausted()){
		cout << this -> display_code << " " << this -> id_num << ": I am exhausted. I may move but you cannot see me." << endl;
		state = EXHAUSTED;	
	}
	else
	{
		Pokemon::SetupDestination(dest);
		state = MOVING; 
		cout << this -> display_code << " " << this -> id_num << ": On my way." << endl;
	}
}

void Pokemon::StartMovingToCenter(PokemonCenter* center)
{     
	if (this -> IsExhausted())
	{
		cout << this -> display_code << " " << this -> id_num << ": I am exhausted, so I can't move to recover stamina." << endl;
		state = EXHAUSTED;	

	}
	else if( this -> location.x == center->GetLocation().x && this -> location.y == center->GetLocation().y )
	{
		cout << display_code << " " << id_num << ": I'm already at the Pokemon Center!" << endl;
		state = STOPPED; 
	}
	else
	{
		this -> current_center = center;
		state = MOVING_TO_CENTER;
		Pokemon::SetupDestination(center -> GetLocation());
		cout << this -> display_code << " " << this -> id_num << ": On my way to center " << center -> GetId() << endl;
	}


}

void Pokemon::StartMovingToGym(PokemonGym* gym) // double check if statmenets --> make sure they're ok FIX COUT STATEMENTS
{

	if (IsExhausted())
	{
		cout << this -> display_code << " " << this -> id_num << ": I am exhausted. So I shouldn't be going to the gym" << endl;
		this -> state = EXHAUSTED;	

	}
	else if( this -> location.x == gym -> GetLocation().x && this -> location.y == gym -> GetLocation().y)
	{
		cout << this -> display_code << " " << this -> id_num << ": I'm already at the Pokemon Gym!" << endl;
		this -> state = STOPPED; 

	}
	else
	{	
		this -> current_gym = gym;
		Pokemon::SetupDestination(gym -> GetLocation());
		this -> state = MOVING_TO_GYM;
		cout << this -> display_code << " " << this -> id_num << ": On my way to gym" << gym -> GetId() << endl;
	}
}

void Pokemon::StartTraining(unsigned int num_training_units) // double check if statmenets --> make sure they're ok FIX COUT STATEMENTS
{
	if(!is_in_gym)
	{
		cout << this -> display_code << " " << this -> id_num << "I can only train in a Pokemon Gym!" << endl;
	}
	else
	{
		if(IsExhausted())
		{
			cout << this -> display_code << " " << this -> id_num << "I am so exhausted, so no more training for me." << endl;\
			this -> state = EXHAUSTED;	

		}
		else if (!current_gym -> IsAbleToTrain(num_training_units, pokemon_dollars, stamina)) //if not enough stamina or dollars
		{
			cout << this -> display_code << " " << this -> id_num << "not enough stamina and/or money for training!" << endl;
		}
		else if (current_gym -> GetState() == BEATEN || current_gym -> IsBeaten())
		{
			cout << this -> display_code << " " << this -> id_num << "Cannot train! This gym is already beaten!" << endl;
		}
		else
		{	
			this -> state = TRAINING_IN_GYM;

			cout << this -> display_code << ": " << "Started to train at Pokemon Gym " << current_gym -> GetId() 
			<< "with " << current_gym -> GetNumTrainingUnitsRemaining() << "training units." << endl;

			training_units_to_buy = min(num_training_units, current_gym -> GetNumTrainingUnitsRemaining());
		}
	}
	
	

}

void Pokemon::StartRecoveringStamina(unsigned int num_stamina_points) // double check if statements --> make sure they're ok FIX COUT STATMENTS
{
	
	if (!is_in_center)
	{
		cout << this -> display_code << " " << this -> id_num << "I can only recover stamina at a pokemon center!" << endl;
	}
	else
	{
		if(!current_center -> CanAffordStaminaPoints(num_stamina_points, this-> pokemon_dollars))
		{
			cout << this -> display_code << " " << this -> id_num << "Not enough money to recover stamina." << endl;
		}
		else if(current_center -> GetNumStaminaPointsRemaining() <= 0)
		{
			cout << this -> display_code << " " << this -> id_num << "Cannot recover! No stamina points remaining in this Pokemon Center." << endl;
		}
		else
		{
			this -> state = RECOVERING_STAMINA;
			cout << this -> display_code << " " << this -> id_num << ":" << "Started recovering" << num_stamina_points << "stamina points at Pokemon Center" << current_center -> GetId();
			stamina_points_to_buy = min(num_stamina_points, current_center -> GetNumStaminaPointsRemaining());
		}
	}
	
}

void Pokemon::Stop()
{
	this -> state = STOPPED;
	cout << display_code << " " << id_num << " : Stopping..." << endl;
}

bool Pokemon::IsExhausted()
{
	bool retval;

	if(this -> stamina == 0)
	{
		this -> state = EXHAUSTED;
		retval = true;
	}
	
	return retval;
}

bool Pokemon::ShouldBeVisible()
{
	bool retval;

	if(state != EXHAUSTED)
	{
		retval = true;
	}

	return retval;
}

void Pokemon::ShowStatus()
{
	cout << name << " status:" << endl;

	GameObject::ShowStatus();

	switch (state)
	{
		case STOPPED: //pokemon does nothing --> showstatus print stopped
			cout << "\tstopped" << endl;
			cout << " \t Stamina: " << this -> stamina << endl;
			cout << " \t Pokemon Dollars:" << this -> pokemon_dollars << endl;
			cout << " \t Experience Points: " << this -> experience_points << endl;
			break;

		case MOVING: //showstatus prints --> "moving at a speed of [speed] to destination <x,y> at each step of (delta)"
			cout << "moving at a speed of" << " " << speed << "to destination <" << destination.x << ", " << destination.y << ">"
			<< " at each step of " << delta << endl;

			cout << " \t Stamina: " << this -> stamina << endl;
			cout << " \t Pokemon Dollars:" << this -> pokemon_dollars << endl;
			cout << " \t Experience Points: " << this -> experience_points << endl;
			break;

		case MOVING_TO_CENTER: //showstatus prints --> "heading to pokemon center (current_center id) at a speed of [speed] at each step of (delta)"
			cout << "heading to Pokemon Center" << current_center -> GetId() << "at a speed of " << " " << speed
			<< "at each step of " << delta;

			cout << " \t Stamina: " << this -> stamina << endl;
			cout << " \t Pokemon Dollars:" << this -> pokemon_dollars << endl;
			cout << " \t Experience Points: " << this -> experience_points << endl;
			break;
		case MOVING_TO_GYM: //showstatus prints --> "heading to pokemon gym (current_gym id) at speed of speed and step of delta"
			cout << "heading to Pokemon Gym" << current_gym -> GetId() << "at a speed of " << " " << speed 
			<< "at each step of " << delta;

			cout << " \t Stamina: " << this -> stamina << endl;
			cout << " \t Pokemon Dollars:" << this -> pokemon_dollars << endl;
			cout << " \t Experience Points: " << this -> experience_points << endl;
			break;

		case IN_CENTER: //showstatus prints inside pokemon center 
			cout <<  "inside Pokemon Center" << current_center -> GetId() << endl;

			cout << " \t Stamina: " << this -> stamina << endl;
			cout << " \t Pokemon Dollars:" << this -> pokemon_dollars << endl;
			cout << " \t Experience Points: " << this -> experience_points << endl;
			break;
		
		case IN_GYM: //show status prints inside pokemon gym 
			cout << "inside Pokemon Gym" << current_gym -> GetId() << endl;

			cout << " \t Stamina: " << this -> stamina << endl;
			cout << " \t Pokemon Dollars:" << this -> pokemon_dollars << endl;
			cout << " \t Experience Points: " << this -> experience_points << endl;
			break;
 		
		case TRAINING_IN_GYM: //showstatus prints training in pokemongym (Current gym id)
			cout << "training in Pokemon Gym" << current_gym -> GetId() << endl;

			cout << " \t Stamina: " << this -> stamina << endl;
			cout << " \t Pokemon Dollars:" << this -> pokemon_dollars << endl;
			cout << " \t Experience Points: " << this -> experience_points << endl;
			break;
		
		case RECOVERING_STAMINA: //showstatus prints recovering stamina in PK center
			cout << "recovering stamina in Pokemon Center" << current_center -> GetId() << endl;

			cout << " \t Stamina: " << this -> stamina << endl;
			cout << " \t Pokemon Dollars:" << this -> pokemon_dollars << endl;
			cout << " \t Experience Points: " << this -> experience_points << endl;
			break;
		default:
			break;
	}

}  

bool Pokemon::Update() //function
{
	bool retval; 
	switch (state)
	{
		case STOPPED: //pokemon does nothing --> showstatus print stopped //fix pokemon::showstatus to this -> showstatus
			Pokemon::ShowStatus();
			retval = false;
			break;

		case MOVING: //showstatus prints --> "moving at a speed of [speed] to destination <x,y> at each step of (delta)"
			Pokemon::ShowStatus();
			Pokemon::UpdateLocation();
			if( this -> location.x == destination.x && this -> location.y == destination.y)
			{	
				state = STOPPED;
				retval = true;
			}
			else
			{
				this -> stamina = stamina - 1;
				this -> pokemon_dollars = pokemon_dollars + GetRandomAmountOfPokemonDollars();
				state = MOVING;
			}

			if( this -> is_in_center)
			{
				current_center -> RemoveOnePokemon();
			}
			else if( this -> is_in_gym )
			{
				current_gym -> RemoveOnePokemon();
			}

			
			break;

		case MOVING_TO_CENTER: //showstatus prints --> "heading to pokemon center (current_center id) at a speed of [speed] at each step of (delta)"
			Pokemon::ShowStatus();
			Pokemon::UpdateLocation();

			if( this -> is_in_gym)
			{
				current_gym -> RemoveOnePokemon();
			}

			if(this -> is_in_arena)
			{
				current_arena -> RemoveOnePokemon();
			}

			if( this -> location.x == destination.x && this -> location.y == destination.y)
			{
				state = IN_CENTER;
				current_center -> AddOnePokemon();
				retval = true;
			}
			else
			{
				this -> stamina = stamina - 1;
				this -> pokemon_dollars = pokemon_dollars + GetRandomAmountOfPokemonDollars();
				state = MOVING;
			}
			break;

		case MOVING_TO_GYM: //showstatus prints --> "heading to pokemon gym (current_gym id) at speed of speed and step of delta"
			Pokemon::ShowStatus();
			Pokemon::UpdateLocation();

			if(this -> is_in_center)
			{
				current_center -> RemoveOnePokemon();
			}

			if(this -> is_in_arena)
			{
				current_arena -> RemoveOnePokemon();
			}

			if( this -> location.x == destination.x && this -> location.y == destination.y)
			{
				this -> state = IN_GYM;
				this -> current_gym -> AddOnePokemon();
				retval = true;
			}
			else
			{
				this -> stamina = stamina - 1;
				this -> pokemon_dollars = pokemon_dollars + GetRandomAmountOfPokemonDollars();
				state = MOVING_TO_GYM;
			}
			break;

		case IN_CENTER: //showstatus prints inside pokemon center (current center id)
			Pokemon::ShowStatus();
			this -> is_in_center = true;
			retval = false;
			break;
		
		case IN_GYM: //show status prints inside pokemon gym (current gym id)
			Pokemon::ShowStatus();
			this -> is_in_gym = false;
			retval = false;
			break;
		
		case TRAINING_IN_GYM: //showstatus prints training in pokemongym (Current gym id)
			Pokemon::ShowStatus();

			this -> stamina -= current_gym -> GetStaminaCost( stamina_points_to_buy ) ; 
			this -> pokemon_dollars -= current_gym -> GetDollarCost( training_units_to_buy ); 
			this -> experience_points += current_gym -> TrainPokemon( training_units_to_buy );
			cout << "** " << this -> name << "completed " << this -> training_units_to_buy << "training unit(s)!**" << endl;
			cout << "** " << this -> name << "gained " <<  current_gym -> TrainPokemon( training_units_to_buy ) << "experience point(s)!" << endl;

			state = IN_GYM; 
			retval = true;
			break;
		
		case RECOVERING_STAMINA: //showstatus prints recovering stamina in PK center //follow manual 
			Pokemon::ShowStatus();
			this -> stamina += current_center -> DistributeStamina( this-> stamina_points_to_buy);
			this -> pokemon_dollars -= current_center -> GetDollarCost( this -> stamina_points_to_buy);
			

			cout << "** " << this -> name << "recovered" << current_center -> DistributeStamina( this-> stamina_points_to_buy)
			<< " stamina point(s)!" << endl;
			state = IN_CENTER;

			retval = true;

			break;
		case FAINTED:
			this -> state = FAINTED;

			retval = false;

			break;
		case MOVING_TO_ARENA:
			Pokemon::ShowStatus();
			Pokemon::UpdateLocation();

			if(this -> is_in_center)
			{
				this-> current_center -> RemoveOnePokemon();
			}

			if(this -> is_in_gym)
			{
				this -> current_gym -> RemoveOnePokemon();
			}

			if( this -> location.x == destination.x && this -> location.y == destination.y)
			{
				this -> state = IN_ARENA;
				this -> current_arena-> AddOnePokemon();
				retval = true;
			}
			else
			{
				this -> stamina = stamina - 1;
				this -> pokemon_dollars = pokemon_dollars + GetRandomAmountOfPokemonDollars();
				this -> state = MOVING_TO_ARENA;
			}
			break;
		case BATTLE:
			Pokemon::StartBattle();
			if(StartBattle())
			{
				this -> health = this -> health + store_health;
				this -> state = IN_ARENA;
				target -> isAlive();
			}
			else
			{
				this -> state = FAINTED;
				target -> isAlive();
			}
			break;
		default:
			retval = false;
			break;
	}

	return retval;
}

bool Pokemon::UpdateLocation() 
{
	if(fabs(this -> destination.x - this->location.x) <= fabs(delta.x) && fabs(this -> destination.y - this->location.y) <= fabs(delta.y))
	{
		this -> location = destination;
		cout << "arrived." << endl;
		return true;
	}
	else
	{
		this -> location.x += delta.x;
		this -> location.y += delta.y;
		cout << "moved. " << endl;
		return false;
	}
	if( this -> location.x == destination.x && this -> location.y == destination.y)
	{
		cout << this -> display_code << " " << this -> id_num << ": " << "I'm there!" << endl;
	}
	else
	{
		cout << this -> display_code << " " << this -> id_num << ": " << "step..." << endl;
	}
}

void Pokemon::SetupDestination(Point2D dest) //finish function
{
	destination = dest;

	delta = (dest - location) * (speed / GetDistanceBetween(dest, location));
	state = MOVING;
}

string Pokemon::GetName()
{
	return name;
}

char Pokemon::GetCode()
{
	return display_code;
}

static double GetRandomAmountOfPokemonDollars()
{
	srand(time(NULL));
	return ( (2.0) * ((double)rand() / (double)RAND_MAX ) ); //StackOverflow solution --> used to generate random doubles btwn 0.0 & 2.0
}

bool Pokemon::isAlive()
{
	if(this -> state == FAINTED || this -> health <= 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Pokemon::TakeHit(double physical_damage, double magical_damage, double defense) //call in startbattle() ensure health of rival or Pokemon first
{
	srand(time(NULL)); 
	double random_number = rand() % 1;
	double damage_type = 0;
	double damage = 0;

	if(random_number == 0)
	{
		damage_type = magical_damage;
	}
	else
	{
		damage_type = physical_damage;
	}

	damage = (100.0-defense)/100 * damage_type;

	this -> health = this -> health - damage;
}
 
void Pokemon::ReadyBattle(Rival* in_target)
{
	if(
	this->state == IN_ARENA &&
	current_arena->IsAbleToFight(this -> pokemon_dollars, this -> stamina) == true &&
	current_arena->IsBeaten() == false &&
	in_target->isAlive() == true)
	{
		this -> state = BATTLE;
		target = in_target;
	}
	else
	{
		this -> state = IN_ARENA;
	}
}

bool Pokemon::StartBattle() //battle program described in manual RETURN TRUE IF PK WINS
{	
	do
	{
		this -> TakeHit(target -> get_phys_dmg(), target -> get_magic_dmg(), this -> defense); //rival hits first
		if(!(this -> isAlive())) //checks if PK is alive --> break out of loop if not
		{
			return false;
		}

		target -> TakeHit(this -> physical_damage, this -> magical_damage, target -> get_defense()); //PK hits

	}
	while(target-> get_health() > 0); //while target is still alive, continue to execute loop

	return true; //PK WINS, RETURN TRUE
}

void Pokemon::StartMovingToArena(BattleArena* arena)
{
	if (this ->IsExhausted())
	{
		cout << this -> display_code << " " << this -> id_num << ": I am exhausted. So I shouldn't be going to the Arena" << endl;
	}
	else if( this -> location.x == arena -> GetLocation().x && this -> location.y == arena -> GetLocation().y)
	{
		cout << this -> display_code << " " << this -> id_num << ": I'm already at the BattleArena" << endl;
	}
	else
	{	
		this -> current_arena = arena;
		Pokemon::SetupDestination(arena-> GetLocation());
		state = MOVING_TO_ARENA;
		cout << this -> display_code << " " << this -> id_num << ": On my way to arena" << arena-> GetId() << endl;
	}
}
