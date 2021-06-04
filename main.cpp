#include "GameCommand.h"
#include "Input_Handling.h"


using namespace std;

int main()
{
	Model M; //initializes model

	View V = View(); //initialize view

	Point2D p1; //initialies point

	char UI; //user input will be stored here --> only for commands!

	bool loop = true; //variable keeps loop looping until exit(0) is called on command 'q' --> used a variable instead of "true" to c

	//initialize all variables
	int ID1, ID2, X, Y;
	unsigned int stamina_amount, unit_amount;

	const string POKEMON_BANNER = "                                  ,'\\\n"
                              "    _.----.        ____         ,'  _\\   ___    ___     ____\n"
                              "_,-'       `.     |    |  /`.   \\,-'    |   \\  /   |   |    \\  |`.\n"
                              "\\      __    \\    '-.  | /   `.  ___    |    \\/    |   '-.   \\ |  |\n"
                              " \\.    \\ \\   |  __  |  |/    ,','_  `.  |          | __  |    \\|  |\n"
                              "   \\    \\/   /,' _`.|      ,' / / / /   |          ,' _`.|     |  |\n"
                              "    \\     ,-'/  /   \\    ,'   | \\/ / ,`.|         /  /   \\  |     |\n"
                              "     \\    \\ |   \\_/  |   `-.  \\    `'  /|  |    ||   \\_/  | |\\    |\n"
                              "      \\    \\ \\      /       `-.`.___,-' |  |\\  /| \\      /  | |   |\n"
                              "       \\    \\ `.__,'|  |`-._    `|      |__| \\/ |  `.__,'|  | |   |\n"
                              "        \\_.-'       |__|    `-._ |              '-.|     '-.| |   |\n"
                              "                                `'                            '-._|";
	cout << " " << endl;
	cout << " " << endl;
	cout << " --------------------------------------------------------------------------------- " << endl;
	cout << POKEMON_BANNER << endl;
	cout << " " << endl;
	cout << "EC327: Introduction to Software Engineering" << endl;
	cout << "Fall 2019" << endl;
	cout << "Programming Assignment 4" << endl;
	cout << "Derek Barbosa, U66315658" << endl;                    
	cout << " --------------------------------------------------------------------------------- " << endl;
	cout << " " << endl;

	//initialize the game!
	M.ShowStatus();
	M.Display(V); 

	///SEE README FOR CHANGES
	//CHANGED USER INPUT TO TAKE INPUT WITHIN THE FUNCTIONS --> DEFENSIVE PROGRAMMING

	while(loop) //exit(0) or exit(1) will break this loop --> yay, im learning from PA2!
	{	
		cout << " " << endl;
		cout << " " << endl;
		cout << "Gotta Catch Them all!" << endl;
		cout << "Valid Game Commands (please separate with spaces) " << endl;
		cout << "m ID1, X, Y \\\\ Move Pokemon ID1 to location X,Y " << endl;
		cout <<  "g ID1, ID2 \\\\ Move Pokemon ID1 to Pokemon Gym ID2 " << endl;
		cout << "c ID1, ID2 \\\\ Move Pokemon ID1 to Pokemon Center ID2" << endl;
		cout << "s ID1 \\\\ Stops Pokemon" << endl;
		cout << "r ID1, ID2, stamina_amount \\\\ Recover Pokemon ID1's stamina by ''stamina amount'' at Pokemon Center ID2" << endl;
		cout << "t ID1, ID2, unit_amount \\\\ Complete ''unit amount'' training units with Pokemon ID1 at Pokemon Gym ID2" << endl;
		cout << "a ID1, ID2 \\\\ Pokemon ID1 will move to Arena ID2" << endl;
		cout << "b ID1, ID2 \\\\ Pokemon ID1 will battle Rival ID2 (only works in the arena!)" << endl;
		cout << "v \\\\ ''Go'' advance time by one step --> updates each object ONCE." << endl;
		cout << "x \\\\ ''Run'' advance one time step and update e/a object,repeat until either the" << endl;
		cout << "...update function returns true once, or 5 time steps." << endl;
		cout << "n TYPE, ID, X, Y \\\\ creates NEW object of TYPE, with ID at location (X,Y)" << endl;
		cout << "TYPES: g- Gym; c- Center; r- Rival; p- Pokemon" << endl;
		cout << "q \\\\ quit --> terminates program" << endl;
		cout << " " << endl;

		try //TRY --> ERROR CHECKING USING EXCEPTION HANDLING
		{
			cin >> UI; // accept user input
			UI = tolower(UI);
			//assume user will do this as stated (please dont break my program)
			if(cin.fail())
			{
				throw Invalid_Input("Please only enter valid commands"); //user input primary check
			}

			switch(UI)
			{
				case 'a': //move to arena
					DoMoveToArenaCommand(M);
					
					cout << "moving Pokemon" << " " << ID1 << " " << "to " << "arena" << " " << ID2 << endl;

				case 'b': // command pokemon to battle rival in arena only
					DoBattleInArenaCommand(M);
					
					cout << "battling with Pokemon" << " " << ID1 << " " << "with Rival" << " " << ID2;
				case 'm':
					p1.x = X;
					p1.y = Y;

					DoMoveCommand(M);
					cout << "moving Pokemon" << " " << ID1 << "to" << p1;
				
					break;
				case 'g':

					DoMoveToGymCommand(M);
					cout << "moving Pokemon" << " " << ID1 << " " << "to gym" << " " << ID2;

					break;
				case 'c':

					DoMoveToCenterCommand(M);
					cout << "moving Pokemon" << " " << ID1 << " " << "to center" << " " << ID2;

					break;
				case 's':

					DoStopCommand(M);
					cout << "Stopping" << " " << ID1;

					break;

				case 'r':

					DoRecoverInCenterCommand(M);
					cout << "Recovering Pokemon" << " " << ID1 << " " << "'s stamina points by" << " " << stamina_amount << "at Center" << " " << ID2;

					break;

				case 't':
			

					DoTrainInGymCommand(M);
					cout << "Training " << " " << ID1 << " " <<  "with" << unit_amount << "training units" << "at Gym" << " " << ID2;

					break;
				case 'v':
					DoGoCommand(M, V);

					break;
				case 'x':
					DoRunCommand(M, V);

					break;
				case 'n':
					DoNewCommand(M);

					break;
				case 'q':
					cout << "Quitting Program, Goodbye!" << endl;
					loop = false;
					exit(0);
					break;
				default:
					cout << "INVALID COMMAND" << endl;
					throw("Invalid Input! please enter a legal command.");
					break;		
			}

		}
			catch (Invalid_Input& except)
			{
				cout << "Invalid Input" << except.msg_ptr << endl; //catch statement for all exceptions
			}

			M.Update();
			M.ShowStatus();
			
			if(UI != 'q')
			{
				M.Display(V);
			}

	}
	//IM FINALLY FREEEEEE IM DONE THANK GODDDDDD

}