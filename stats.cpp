#include "stats.hpp"
#include "text_blocks.hpp"
#include "backpack.hpp"
#include "helpers.hpp"
#include <iostream>

class Backpack;

int Stats::getHealth() {
    return health;
    }
int Stats::getFullness() {
    return fullness;
    }
int Stats::getLuck(Backpack backpack) {
    int backpack_luck = 0;
    if (backpack.item_quantity("Good luck rock")) {backpack_luck += 30;}
    return luck + backpack_luck;
    }
int Stats::getDayNumber() {
    return day_number;
    }
double Stats::getMilesJourneyed() {
    return miles_journeyed;
    }

void Stats::increaseHealth(int amount) {
    health += amount;
    if (health > 99) {health = 99;}
    if (health < 0) {health = 0;}
    }
void Stats::increaseFullness(int amount) {
    fullness += amount;
    if (fullness >= 99) {
        fullness = 99;
        print_nice("You are full. You cannot eat any more. ");
    }
    if (fullness < 0) {
        fullness = 0;
    }
    }
void Stats::increaseLuck(int amount) {
    luck += amount;
    }
void Stats::increaseDayNumber(int amount) {
    day_number += amount;
    }
void Stats::increaseMilesJourneyed(double amount, Backpack backpack) {
    double multiplier = 1;
    if (backpack.weight_status() == "light") {
        multiplier = 1.2;
    } 
    else if (backpack.weight_status() == "heavy") {
        multiplier = 0.8;
    }
    if (backpack.item_quantity("Walking stick") > 0) {
        multiplier *= 1.1;
    }
    miles_journeyed += multiplier * amount;
    }

void Stats::print_health_status() {
    std::string health_status;
    if (health < 10) {health_status = "extremely poor";} 
    else if (health < 25) {health_status = "very poor";}
    else if (health < 50) {health_status = "diminished";}
    else if (health < 75) {health_status = "fair";}
    else {health_status = "good";}

    print_nice("Your health is " + health_status + ".\n");
}

void Stats::print_fullness_status() {
    std::string fullness_status;
    if (fullness < 10) {fullness_status = "Your hunger is excruciating. You feel light-headed and weak.";} 
    else if (fullness < 25) {fullness_status = "Your stomach aches. You don't know how much longer you can handle this.";}
    else if (fullness < 50) {fullness_status = "Your stomach is grumbling. You should probably eat something soon.";}
    else if (fullness < 75) {fullness_status = "You are a bit hungry. Some food would be nice.";}
    else {fullness_status = "Your stomach feels content.";}
    
    print_nice(fullness_status + "\n\n");
}
void Stats::print_status() {
    print_health_status();
    print_fullness_status();
}

void Stats::check_for_death() {
    if (health == 0) {
        death();
    }
}
