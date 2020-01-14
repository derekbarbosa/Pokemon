#ifndef PokemonGym_H_
#define PokemonGym_H_
#include "Building.h"
using namespace std;

enum PokemonGymStates
{
    NOT_BEATEN = 0,
    BEATEN = 1,
};

class PokemonGym: public Building
{
    private:
        unsigned int num_training_units_remaining;
        unsigned int max_number_of_training_units;
        unsigned int stamina_cost_per_training_unit;
        unsigned int dollar_cost_per_training_unit;
        unsigned int experience_points_per_training_unit;
    public:
        PokemonGym();
        PokemonGym(unsigned int max_training_units, unsigned int stamina_cost, double dollar_cost, unsigned int exp_points_per_unit, int in_id, Point2D in_loc);
        ~PokemonGym();
        double GetDollarCost(unsigned int);
        unsigned int GetStaminaCost(unsigned int);
        unsigned int GetNumTrainingUnitsRemaining();
        bool IsAbleToTrain(unsigned int, double, unsigned int);
        unsigned int TrainPokemon(unsigned int);
        bool Update();
        bool IsBeaten();
        void ShowStatus();
};

#endif