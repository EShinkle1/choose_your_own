#include "stats.hpp"
#include "text_blocks.hpp"
#include <iostream>

int Stats::getHealth() {
    return health;
    }
int Stats::getFullness() {
    return fullness;
    }
int Stats::getLuck() {
    return luck;
    }
int Stats::getDayNumber() {
    return day_number;
    }
int Stats::getMilesJournied() {
    return miles_journied;
    }

void Stats::increaseHealth(int amount) {
    health += amount;
    if (health > 100) {health = 100;}
    if (health <= 0) {out_of_health();}
    }
void Stats::increaseFullness(int amount) {
    fullness += amount;
    if (fullness > 100) {
        fullness = 100;
        std::cout << "You are full. You cannot eat any more. ";
    }
    }
void Stats::increaseLuck(int amount) {
    luck += amount;
    }
void Stats::increaseDayNumber(int amount) {
    day_number += amount;
    }
void Stats::increaseMilesJournied(int amount) {
    miles_journied += amount;
    }

void Stats::print_health_status() {
    std::string health_status;
    if (health < 10) {health_status = "extremely poor";} 
    else if (health < 25) {health_status = "very poor";}
    else if (health < 50) {health_status = "diminished";}
    else if (health < 75) {health_status = "fair";}
    else {health_status = "good";}

    std::cout << "Your health is " << health_status << ".\n";
}

void Stats::print_fullness_status() {
    std::string fullness_status;
    if (fullness < 10) {fullness_status = "Your hunger is excruciating. You feel light-headed and weak. It is hard to see straight.";} 
    else if (fullness < 25) {fullness_status = "Your stomach aches. You don't know how much longer you can handle this.";}
    else if (fullness < 50) {fullness_status = "You hear your stomach rumble. You should probably eat something soon.";}
    else if (fullness < 75) {fullness_status = "Your stomach growls a bit. You put it out of your mind.";}
    else {fullness_status = "Your stomach feels content.";}

    // std::cout << "It is day " << day_number + 1 << " of your journey.\n";
    
    std::cout << fullness_status << "\n\n";
}
void Stats::print_status() {
    print_health_status();
    print_fullness_status();
}
