#ifndef STATS_HPP
#define STATS_HPP

class Stats
{
private:
    int health = 100; //max 100, dead at 0
    int fullness = 100; //max 100
    int luck = 0; //0 is neutral 
    int day_number = 0;
    int miles_journied = 0;
public:
    int getHealth();
    int getFullness();
    int getLuck();
    int getDayNumber();
    int getMilesJournied();
    
    void increaseHealth(int amount);
    void increaseFullness(int amount);
    void increaseLuck(int amount);
    void increaseDayNumber(int amount);
    void increaseMilesJournied(int amount);

    void print_health_status();
    void print_fullness_status();
    void print_status();
};

#endif