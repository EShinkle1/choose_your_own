#include <iostream>
#include "helpers.hpp"
#include "text_blocks.hpp"
#include "stats.hpp"
#include "backpack.hpp"

int choose_route(Stats &stats) {
    print_nice("\nChoose whether to take a northern route or a southern route. The voyager who returned unsuccessfully reported that the northern route had difficult terrain but that he encountered few creatures.\n\n");
    print_nice("  A. Northern route\n");
    print_nice("  B. Southern route\n");

    return letter_to_int(input_checker_char(2)); //0 = northern, 1 = southern
}

void check_in(Stats &stats, Backpack &backpack, std::string time) {
    bool finished = false;

    while (!finished) {
        print_nice("What would you like to do?\n\n");
    
        std::vector<std::string> options = {"List backpack contents", "Drop backpack items", "Use backpack items", "View your status"};
        if (time == "night") {
            options.push_back("Get some rest");
        }
        else {
            options.push_back("Proceed with your journey");
        }

        for (int i = 0; i < options.size(); i++) {
            print_nice("  " + std::string(1, int_to_letter(i)) + ". " + options[i] + "\n");
        }
        print_nice("\n");

        int response = letter_to_int(input_checker_char(options.size()));

        if (response == 0) {
            backpack.print_contents();
            pause0();
        }
        else if (response == 1) {
            backpack.drop_items();
        }
        else if (response == 2) {
            backpack.select_item_for_action(stats, backpack);
        }
        else if (response == 3) {
            stats.print_health_status();
            print_nice("Your backpack is " + backpack.weight_status() + ".\n");
            stats.print_fullness_status();
            pause0();
        }
        else {
            finished = true;
        }
    }
}

void lunch(Stats &stats, Backpack &backpack) {
    stats.increaseFullness(-25);

    print_nice("It is midday.\n\n");

    stats.print_health_status();
    print_nice("Your backpack is " + backpack.weight_status() + ".\n");
    stats.print_fullness_status();

    pause0();

    check_in(stats, backpack, "day");

    print_nice("You are ready to continue!\n\n");

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

    pause0();
}

void dinner(Stats &stats, Backpack &backpack) {
    stats.increaseFullness(-25);

    print_nice("It is growing dark.\n\n");

    stats.print_health_status();
    print_nice("Your backpack is " + backpack.weight_status() + ".\n");
    stats.print_fullness_status();

    pause0();

    check_in(stats, backpack, "night");

    print_nice("It is time to try to sleep.\n\n");

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

    pause0();
}

void bedtime(Stats &stats, Backpack &backpack) {
    double sleep_quality = 0;
    if (backpack.item_quantity("Makeshift tent") > 0) {
        print_nice("You set up your tent on a dry patch of ground. ");
        sleep_quality += 0.5;
        if (backpack.item_quantity("Blanket") > 0) {
            print_nice("You curl up in your blanket and hope for a good night of rest.\n\n");
            sleep_quality += 0.2;
        }
    }
    else if (backpack.item_quantity("Blanket") * backpack.item_quantity("Walking stick") > 0) {
        print_nice("You make a small shelter from use your blanket and walking stick.\n\n");
        sleep_quality += 0.4;
    }
    else {
        print_nice("You sit with your back up against a tree and close your eyes.\n\n");
    }

    pause0();

    double night_conditions = (rand() % 200 + stats.getLuck(backpack)) / 100.0 - 1;
    stats.increaseHealth(10 * (sleep_quality + night_conditions));

    if (night_conditions < -0.6) {
        print_nice("The night is cold and rainy. The ground beneath you is hard, cold, and damp.\n\n");
    }
    else if (night_conditions < -0.2) {
        print_nice("Strange noises haunt you during the night. You hope it's nothing more than the trees snickering to each other about your misfortune.\n\n");
    }
    else if (night_conditions < 0.2) {
        print_nice("The night passes slowly. You drift in and out of sleep.\n\n");
    }
    else if (night_conditions < 0.6) {
        print_nice("You sleep well, only waking a few times to the sound of branches rustling in the wind.\n\n");
    }
    else {
        print_nice("You fall right asleep and sleep soundly through the night.\n\n");
    }

    stats.check_for_death();
    pause0(false);
}


