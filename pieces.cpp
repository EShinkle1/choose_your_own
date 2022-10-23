#include "stats.hpp"
#include "backpack.hpp"
#include "choices.hpp"
#include "events.hpp"
#include "helpers.hpp"
#include "text_blocks.hpp"
#include <iostream>

void day_header(Stats stats) {
    int length = (getWindowColumns() - 5)/ 2;
    std::cout << "\n";
    print_line("=");
    print_line(" ", length, false);
    std::cout << "DAY " << stats.getDayNumber() << "\n";
    print_line("=");
    std::cout << "\n";    
}

void wake_up_text(Stats &stats) {

    std::cout << "You awake from your sleep. ";

    //determine sleep quality
    int sleep_qual = rand() % 3; //0 worst, 2 best
    if (sleep_qual == 0) {
        std::cout << "You slept poorly.\n\n";
        if (stats.getHealth() > 10) {
            stats.increaseHealth(-10);
        }
    } else if (sleep_qual == 1) {
        std::cout << "Your sleep was adequate.\n\n";
    } else {
        std::cout << "You slept well last night.\n\n";
        stats.increaseHealth(10);
    }
}

void first_day(Stats &stats, Backpack &backpack, Events &events) {
    stats.increaseDayNumber(1);

    day_header(stats);

    first_day_journey();
    stats.increaseMilesJourneyed(10, backpack);

    lunch(stats, backpack);

    events.get_event(stats, backpack, "morning");

    dinner(stats, backpack);

    bedtime(stats, backpack);

}

void new_day(Stats &stats, Backpack &backpack, Events &events) {
    stats.increaseDayNumber(1);

    day_header(stats);

    std::cout << "The sun is rising. You pack up your things and set off.\n\n";
    stats.print_status();
    pause();

    events.get_event(stats, backpack, "morning");

    lunch(stats, backpack);

    events.get_event(stats, backpack, "afternoon");

    dinner(stats, backpack);

    bedtime(stats, backpack);

}