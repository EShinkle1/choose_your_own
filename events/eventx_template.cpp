#include <backpack.hpp>
#include <stats.hpp>
#include <helpers.hpp>

//Tier X, topic
void eventXXX(Backpack &backpack, Stats &stats, std::string time_of_day) {
                                                         // time_of_day = "morning" or "afternoon"
    //Intro text


    //A choice
    std::vector<std::string> choices = {"One choice", "Another choice"};

    std::cout << "You have a choice to make.\n\n";
    for (int i = 0; i < choices.size(); i++) {
        std::cout << "  " << int_to_letter(i) << ". " << choices[i] << "\n";
    }
    std::cout << "\n";

    int response = letter_to_int(input_checker_char(2));

    if (response == 0) {

    } else {

    }

    pause0();
}