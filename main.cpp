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

    backpack.print_contents();

    // // int route = choose_route(stats); //not implemented

    //backpack.initial_load();

    // stats.increaseFullness(-1 * (rand() % 100));
    // stats.increaseHealth(-1 * (rand() % 100));


    //first_day(stats, backpack, events);

    int i = 1;

    while (i < 2) {
        new_day(stats, backpack, events);
        i++;
    }

    return 0;
}