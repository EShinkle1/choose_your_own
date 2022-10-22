#include <iostream>
#include "helpers.hpp"

void print_intro() {
    std::cout << "\nTHE DARK, LONELY FOREST\n";
    std::cout << "A journey of choice and chance\n";
    std::cout << "Written by: Emily Shinkle\n\n";

    std::cout << "\nYou live in a village bordered by a dense forest to the west. Legend says that in the time before your grandparents were born, a brave young woman journeyed all the way to the other side of the forest. There, she found a bustling city full of brightly colored clothing, trinkets to purchase on every street corner, and curious smells of food foreign to her palette. However, when she returned, she reported that the travel had been difficult. She had encountered frightening creatures in the forest, difficult terrain, and unsettlingly dark nights. By the time she reached the city, she had little food left and she had brought no goods to exchange. She managed to barter for a thin silver necklace which boasted a delicate ruby-colored gem. It was the only evidence she was able to bring back to support her grand claims.\n";
    pause();
    std::cout << "Some doubt that the legend is true. A few over the years have tried to see for themselves. One returned saying that he walked for five days and no end to the forest was in sight. Others never returned. The length of the original journey is unknown. Some say the woman was gone for merely a week, others say it was much longer.\n";
    pause();
    std::cout << "You will attempt to recreate the fabled journey. You will chose supplies and a route to take. You must monitor your health and hunger levels. You may encounter perils along the way. Chance may or may not be in your favor.\n";
    pause();

}

void death() {
    std::cout << "Oh no, you died!\n";
    exit(0);
}
