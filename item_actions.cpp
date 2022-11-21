#include <iostream>
#include "stats.hpp"
#include "helpers.hpp"
#include "backpack.hpp"

//return the amount that has been consumed as a negative double

double eat_half_can_food(Stats &stats, Backpack &backpack) {
    print_nice("You eat a half day's portion of food. ");
    stats.increaseFullness(25);
    stats.print_fullness_status();
    print_nice("\n\n");
    pause0();
    return -0.5;
}

double null_function(Stats &stats, Backpack &backpack) {
    print_nice("This item does not have an associated action.\n\n");
    pause0();
    return 0;
}

double healing_potion(Stats &stats, Backpack &backpack) {
    print_nice("You uncork the bottle containing the healing potion. You can't seem to remember how you originally obtained this item.\n\n");
    pause0();
    print_nice("You take a drink.\n\n");
    pause0();

    int result = rand() % 200 + stats.getLuck(backpack);

    if (result < 50) {
        print_nice("You start to feel nauseous. Everything is very bright. There is a shrill noise piercing your ears.\n\n");
        pause0();
        print_nice("Everything goes black.\n\n");
        pause0();
        print_nice("You awake a bit later. You don't feel so good.\n\n");
        stats.increaseHealth(-1);
        pause0();
    } 
    else if (result < 100) {
        print_nice("You take another drink.\n\n");
        pause0();
        print_nice("Nothing seems to be happening.\n\n");
        pause0();
    }
    else {
        print_nice("It's oddly sweet.\n\n");
        pause0();
        print_nice("You take a deep breath in and release it slowly. You feel stronger. And taller? You suddenly have the urge to sprint.\n\n");
        pause0();
        print_nice("You're not sure what you just drank, but it made you feel great!\n\n");
        stats.increaseHealth(100);
        pause0();
    }
    return -1;
}

double first_aid_kit(Stats &stats, Backpack &backpack) {
    print_nice("TEXT NEEDED HERE.\n\n");
    stats.increaseHealth(10);
    return -1;
}