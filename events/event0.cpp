#include <backpack.hpp>
#include <stats.hpp>
#include <helpers.hpp>

//Tier 4, find good berries
void event0(Backpack &backpack, Stats &stats, std::string time_of_day) {
    //Intro text
    std::vector<std::string> berry_color = {"dull blue", "dull red", "dull purple"};
    int idx = rand() % berry_color.size();
    std::cout << "You walk along for a while, before stumbling upon a bush of " << berry_color[idx] << " berries. ";
    std::cout << "There is a faint smell of sweetness to them.\n\n";

    //A choice
    std::vector<std::string> choices = {"Eat the berries.", "Move on."};

    std::cout << "You have a choice to make.\n\n";
    for (int i = 0; i < choices.size(); i++) {
        std::cout << "  " << int_to_letter(i) << ". " << choices[i] << "\n";
    }
    std::cout << "\n";

    int response = letter_to_int(input_checker_char(2));

    if (response == 0) {
        std::cout << "You eat several handfuls of the berries. They are quite good. You continue your hike. ";
        stats.increaseFullness(15);
        std::cout << "\n\n";
        pause0();
        std::cout << "The terrain ahead is very easy. You cover a good distance. Finally after many hours of walking, you decide it's time for a break. \n\n";
        stats.increaseMilesJourneyed(12, backpack);
    } else {
        std::cout << "There is no time to waste. You keep moving. \n\n";
        pause0();
        std::cout << "The terrain ahead is very easy. You cover a good distance. Finally after many hours of walking, you decide it's time for a break. \n\n";
        stats.increaseMilesJourneyed(15, backpack);
    }

    pause0();
}