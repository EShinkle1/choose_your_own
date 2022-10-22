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

    // //print_intro();

    Stats stats;
    Backpack backpack;
    Events events;

    // // int route = choose_route(stats);

    //backpack.initial_load();

    stats.increaseFullness(-1 * (rand() % 100));
    stats.increaseHealth(-1 * (rand() % 100));

    lunch(stats, backpack);

    // //YOU'RE READY TO BEGIN YOUR JOURNEY...
    // //write this text later
    // //Have the journey into the woods scripted, perhaps based on which route was chosen. 
    // //Have the player take a pause to consider the journey ahead of them. This way, when they 
    // //begin their first event, if it starts with something like "You continue hiking...", it is
    // //still coherent.

    // int i = 0;

    // while (i < 1) {
    //     backpack.print_contents();
    //     new_day(stats, backpack, events);
    //     backpack.print_contents();
    //     i++;
    // }

    return 0;
}