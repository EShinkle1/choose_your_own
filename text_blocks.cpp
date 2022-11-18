#include <iostream>
#include "helpers.hpp"

void print_intro() {
    std::cout << "\nTHE DARK, LONELY FOREST\n";
    std::cout << "A journey of choice and chance\n";
    std::cout << "Written by: Emily Shinkle\n\n";

    std::cout << "\nYou live in a village bordered by a dense forest to the west. Legend says that in the time before your grandparents were born, a brave young woman journeyed all the way to the other side of the forest. There, she found a bustling city full of brightly colored clothing, trinkets to purchase on every street corner, and curious smells of foods foreign to her palette. However, when she returned, she reported that the travel had been difficult. She had encountered frightening creatures in the forest, difficult terrain, and unsettlingly dark nights. By the time she reached the city, she had little food left and she had brought no goods to exchange. She managed to barter for a thin silver necklace which boasted a delicate ruby-colored gem. It was the only evidence she was able to bring back to support her grand claims.\n\n";
    pause0();
    std::cout << "Some doubt that the legend is true. A few over the years have tried to see for themselves. One returned saying that he walked for five days and no end to the forest was in sight. Others never returned. The length of the original journey is unknown. Some say the woman was gone for merely a week, others say it was much longer.\n\n";
    pause0();
    std::cout << "You will attempt to recreate the fabled journey. You will chose supplies and a route to take. You must monitor your health and hunger levels. You may encounter perils along the way. Chance may or may not be in your favor.\n\n";
    pause0();

}

void death() {
    std::cout << "Oh no, you died!\n";
    exit(0);
}

void first_day_journey() {
    std::cout << "You look around momentarily, taking in the familiar sights of your village as if for the first time. This could be the last time you see them.\n\n";
    pause0();
    std::cout << "No, no. That attitude won't help! You try to picture how the grand city will look, as you have done many times since first hearing the tale as a young child.\n\n";
    std::cout << "The city has never felt so close, nor so far away, as it does now.\n\n";
    pause0();
    std::cout << "You enter the forest, taking note of the sights and smells. You played in these woods many times when you were younger, but you were never permitted to venture very far in.\n\n";
    pause0();
    std::cout << "The trees become more dense as you enter the unfamiliar part of the forest. You can tell the ground here has not touched by human feet very recently.\n\n";
    pause0();
    std::cout << "You walk for a while, observing birds, squirrels, insects, and some unfamiliar foliage. You hope that the days ahead will be similarly fair, but something tells you that's unlikely to be the case.\n\n";
    pause0();
    std::cout << "You sight a small, flat patch of grass and decide to stop for a quick rest.\n\n";
    pause0();
}
