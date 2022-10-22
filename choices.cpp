#include <iostream>
#include "helpers.hpp"
#include "text_blocks.hpp"
#include "stats.hpp"
#include "backpack.hpp"

int choose_route(Stats &stats) {
    std::cout << "\nChoose whether to take a northern route or a southern route. The voyager who returned unsuccessfully reported that the northern route had difficult terrain but that he encountered few creatures.\n\n";
    std::cout << "  A. Northern route\n";
    std::cout << "  B. Southern route\n";

    return letter_to_int(input_checker_char(2)); //0 = northern, 1 = southern
}

void check_in(Stats &stats, Backpack &backpack) {
    std::cout << "Check in option.\n\n";
    //list backpack contents
    //drop items
    //use items
    //view stats
    //continue your journey
    pause();
}

void lunch(Stats &stats, Backpack &backpack) {
    stats.increaseFullness(-25);

    std::cout << "It is midday.\n\n";

    stats.print_health_status();
    std::cout << "Your backpack is " << backpack.weight_status() << ".\n";
    stats.print_fullness_status();

    pause();

    check_in(stats, backpack);

}

void dinner(Stats &stats, Backpack &backpack) {
    std::cout << "Dinnertime.\n\n";
    pause();
}

void bedtime(Stats &stats, Backpack &backpack) {
    std::cout << "Bedtime.\n\n";
    pause(false);
}


