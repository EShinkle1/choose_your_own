#include <backpack.hpp>
#include <stats.hpp>
#include <helpers.hpp>

//Tier X, topic
void eventXXX(Backpack &backpack, Stats &stats, std::string time_of_day) {
                                                         // time_of_day = "morning" or "afternoon"
    //Intro text


    //A choice
    std::vector<std::string> choices = {"One choice", "Another choice"};

    print_nice("You have a choice to make.\n\n");
    for (int i = 0; i < choices.size(); i++) {
        print_nice("  " + std::string(1, int_to_letter(i)) + ". " + choices[i] + "\n");
    }
    print_nice("\n");

    int response = letter_to_int(input_checker_char(2));

    if (response == 0) {

    } else {

    }

    pause0();
}