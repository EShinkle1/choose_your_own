#include "stats.hpp"
#include "backpack.hpp"
#include "choices.hpp"
#include "events.hpp"
#include "helpers.hpp"
#include "text_blocks.hpp"
#include <iostream>

void day_header(Stats stats) {
    int length = (getWindowColumns() - 5)/ 2;
    print_nice("\n");
    print_line("=");
    print_line(" ", length, false);
    print_nice("DAY " + double_to_nice_string(stats.getDayNumber()) + "\n");
    print_line("=");
    print_nice("\n");    
}

void wake_up_text(Stats &stats) {

    print_nice("You awake from your sleep. ");

    //determine sleep quality
    int sleep_qual = rand() % 3; //0 worst, 2 best
    if (sleep_qual == 0) {
        print_nice("You slept poorly.\n\n");
        if (stats.getHealth() > 10) {
            stats.increaseHealth(-10);
        }
    } else if (sleep_qual == 1) {
        print_nice("Your sleep was adequate.\n\n");
    } else {
        print_nice("You slept well last night.\n\n");
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

    print_nice("The sun is rising. You pack up your things and set off.\n\n");
    stats.print_status();
    pause0();

    events.get_event(stats, backpack, "morning");

    lunch(stats, backpack);

    events.get_event(stats, backpack, "afternoon");

    dinner(stats, backpack);

    bedtime(stats, backpack);

}