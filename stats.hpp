#ifndef STATS_HPP
#define STATS_HPP

class Backpack;

class Stats
{
private:
    int health = 99; //max 99, dead at 0
    int fullness = 99; //max 99
    int luck = 0; //0 is neutral 
    int day_number = 0;
    double miles_journeyed = 0;
public:
    int getHealth();
    int getFullness();
    int getLuck(Backpack backpack);
    int getDayNumber();
    double getMilesJourneyed();
    
    void increaseHealth(int amount);
    void increaseFullness(int amount);
    void increaseLuck(int amount);
    void increaseDayNumber(int amount);
    void increaseMilesJourneyed(double amount, Backpack backpack);

    void print_health_status();
    void print_fullness_status();
    void print_status();

    void check_for_death();
};

#endif