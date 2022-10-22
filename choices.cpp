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

void check_in(Stats &stats, Backpack &backpack, std::string time) {
    bool finished = false;

    while (!finished) {
        std::cout << "What would you like to do?\n\n";
    
        std::vector<std::string> options = {"List backpack contents", "Drop backpack items", "Use backpack items", "View your status"};
        if (time == "night") {
            options.push_back("Get some rest");
        }
        else {
            options.push_back("Proceed with your journey");
        }

        for (int i = 0; i < options.size(); i++) {
            std::cout << "  " << int_to_letter(i) << ". " << options[i] << "\n";
        }
        std::cout << "\n";

        int response = letter_to_int(input_checker_char(options.size()));

        if (response == 0) {
            backpack.print_contents();
            pause();
        }
        else if (response == 1) {
            backpack.drop_items();
        }
        else if (response == 2) {
            std::cout << "Not yet implemented.\n\n";
            pause();
        }
        else if (response == 3) {
            stats.print_health_status();
            std::cout << "Your backpack is " << backpack.weight_status() << ".\n";
            stats.print_fullness_status();
            pause();
        }
        else {
            finished = true;
        }
    }
}

void lunch(Stats &stats, Backpack &backpack) {
    stats.increaseFullness(-25);

    std::cout << "It is midday.\n\n";

    stats.print_health_status();
    std::cout << "Your backpack is " << backpack.weight_status() << ".\n";
    stats.print_fullness_status();

    pause();

    check_in(stats, backpack, "day");

    std::cout << "You are ready to continue!\n\n";

    stats.print_fullness_status();
    int fullness = stats.getFullness();
    if (fullness == 0) {
        stats.increaseHealth(-25);
    }
    else if (fullness < 25) {
        stats.increaseHealth(-15);
    }
    else if (fullness < 50) {
        stats.increaseHealth(-10);
    }

    stats.check_for_death();

    pause();
}

void dinner(Stats &stats, Backpack &backpack) {
    stats.increaseFullness(-25);

    std::cout << "It is growing dark.\n\n";

    stats.print_health_status();
    std::cout << "Your backpack is " << backpack.weight_status() << ".\n";
    stats.print_fullness_status();

    pause();

    check_in(stats, backpack, "night");

    std::cout << "It is time to try to get some sleep.\n\n";

    //stats.print_fullness_status();
    int fullness = stats.getFullness();
    if (fullness == 0) {
        stats.increaseHealth(-25);
    }
    else if (fullness < 25) {
        stats.increaseHealth(-15);
    }
    else if (fullness < 50) {
        stats.increaseHealth(-10);
    }

    stats.check_for_death();

    pause();
}

void bedtime(Stats &stats, Backpack &backpack) {
    std::cout << "Bedtime.\n\n";
    std::cout << "Further implementation needed.\n\n";

    //See if player has tent in backpack
    //Roll dice for nighttime conditions 
    //Determine sleep quality
    //Update health

    stats.check_for_death();
    pause(false);
}


