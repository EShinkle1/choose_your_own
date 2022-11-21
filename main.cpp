#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include "backpack.hpp"
#include "choices.hpp"
#include "events.hpp"
#include "helpers.hpp"
#include "initial_store.hpp"
#include "pieces.hpp"
#include "stats.hpp"
#include "text_blocks.hpp"
#include "backpack_item.hpp"

int main() {

    srand((unsigned) time(NULL));
    rand();

    declare_window_length();

    //print_intro();

    Stats stats;
    Backpack backpack;
    Events events;

    // // int route = choose_route(stats); //not implemented

    backpack.initial_load();

    backpack.drop_items();

    // stats.increaseFullness(-1 * (rand() % 100));
    // stats.increaseHealth(-1 * (rand() % 100));


    first_day(stats, backpack, events);

    int i = 1;

    while (i < 6) {
        new_day(stats, backpack, events);
        i++;
    }

    std::cout << "GAME OVER!!!\n\n";

    print_nice("Fullness: " + std::to_string(stats.getFullness()) + "\n");
    print_nice("Health: " + std::to_string(stats.getHealth()) + "\n");
    print_nice("Luck: " + std::to_string(stats.getLuck(backpack)) + "\n");
    print_nice("Miles Journeyed: " + std::to_string(stats.getMilesJourneyed()) + "\n");


    return 0;
}