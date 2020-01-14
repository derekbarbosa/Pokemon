#ifndef PokemonCenter_H_
#define PokemonCenter_H_
#include "Building.h"


enum PokemonCenterStates
{
    STAMINA_POINTS_AVAIALBLE = 0,
    NO_STAMINA_POINTS_AVAIALBLE = 1
};

class PokemonCenter: public Building
{
    private:
        unsigned int stamina_capacity;
        unsigned int num_stamina_points_remaining;
        double dollar_cost_per_stamina_point;
    public:
        PokemonCenter();
        PokemonCenter(int in_id, double stamina_cost, unsigned int stamina_cap, Point2D in_loc);
        ~PokemonCenter();
        bool HasStaminaPoints();
        unsigned int GetNumStaminaPointsRemaining();
        bool CanAffordStaminaPoints(unsigned int stamina_points, double budget);
        double GetDollarCost(unsigned int stamina_points);
        unsigned int DistributeStamina(unsigned int points_needed);
        bool Update();
        void ShowStatus();
};

#endif