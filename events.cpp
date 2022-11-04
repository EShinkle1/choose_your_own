#include "events.hpp"
#include "stats.hpp"
#include "helpers.hpp"
#include "backpack.hpp"
#include <iostream>
#include <algorithm>
#include <random>
#include <event0.hpp>
#include <event1.hpp>
#include <event2.hpp>
#include <event3.hpp>
#include <event4.hpp>
#include <event5.hpp>
#include <event6.hpp>
#include <event7.hpp>

std::vector<int> * Events::choose_tier(Stats stats, Backpack backpack) {
    int score = rand() % 200 + stats.getLuck(backpack);
    if (score < 50) {
        return &Tier1;
    } else if (score < 100) {
        return &Tier2;
    } else if (score < 150) {
        return &Tier3;
    } else {
        return &Tier4;
    }
}

void Events::get_event(Stats &stats, Backpack &backpack, std::string time_of_day) {
    std::vector<int>& tier = *choose_tier(stats, backpack);

    int size = tier.size();

    if (size == 0) {
        std::cout << "You proceed with your journey. You walk forward, left foot, right foot, left foot, right foot.\n\n";
        pause();
        std::cout << "Your eyelids feel heavy. You press ahead.\n\n";
        pause();
        std::cout << "You eventually stop and realize you've been walking for quite some time. You remember little from the walk and have no idea how much progress you've made.\n\n";
        pause();
        std::cout << "Maybe it's time for a break.\n\n";
        stats.increaseMilesJourneyed(5 + (rand() % 10), backpack);
        pause();
        return;
    }

    int idx = rand() % size;
    int event = tier[idx];
    //int event = 1;

    tier.erase(tier.begin()+idx);
    
    switch (event) {
        //Notes:
        //Tier 1 worst, Tier 4 best.
        //Journey is 100 miles long, average length covered during an event should be 10 miles.
        //Northern route has difficult terrain but fewer creatures.
        //Each event should end with finding a place to take a break. 
        //Each outcome should end with two line breaks, followed by a pause().

        case 0: 
            event0(backpack, stats, time_of_day);
            break;
        case 1: 
            event1(backpack, stats, time_of_day);
            break;
        case 2: 
            event2(backpack, stats, time_of_day);
            break;
        case 3: 
            event3(backpack, stats, time_of_day);
            break;
        case 4: 
            event4(backpack, stats, time_of_day);
            break;
        case 5: 
            event5(backpack, stats, time_of_day);  
            break;
        case 6: 
            event6(backpack, stats, time_of_day);  
            break;   
        case 7: 
            event7(backpack, stats, time_of_day);
            break;
    }
}

