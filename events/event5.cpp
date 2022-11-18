#include <backpack.hpp>
#include <stats.hpp>
#include <helpers.hpp>

//Tier 4, find fruit in trees
void event5(Backpack &backpack, Stats &stats, std::string time_of_day) {
    std::cout << "You're back at it. You take a casual pace, letting your mind wander as you walk along.\n\n";
    pause0();
    if (stats.getMilesJourneyed() < 30) {
        std::cout << "You think about all the things you could encounter ahead. Your mind drifts back to your village. Hopefully you've made the right decision.\n\n";
    }
    else {
        std::cout << "You think about all the things you've already experienced. It's hard to guess how much longer you have to journey and what else you'll see along the way.\n\n";
    }
    pause0();
    std::cout << "You notice a strange fruit on a bushy tree up ahead. It looks a bit like an oblong orange apple.\n\n";
    pause0();
    std::cout << "You find one that is within your reach and pluck it from the branch. You examine its smooth, waxy exterior. Curious, you decide to try a bite.\n\n";
    pause0();
    std::cout << "It's quite tasty! It has a subtle sweetness to it, followed by a burst of tartness.\n\n";
    pause0();
    std::cout << "You look around and see that more trees bearing the fruit are scattered around the area. You may have to climb a bit to reach the most fruit, but the trees seem sturdy and have a lot of thick branches.\n\n";
    pause0();

    //A choice
    std::vector<std::string> choices = {"Spend the " + time_of_day + " collecting fruit from the nearby trees.", "Finish eating the fruit in your hand then continue moving."};

    std::cout << "You have a choice to make.\n\n";
    for (int i = 0; i < choices.size(); i++) {
        std::cout << "  " << int_to_letter(i) << ". " << choices[i] << "\n";
    }
    std::cout << "\n";

    int response = letter_to_int(input_checker_char(choices.size()));

    //Outcome 
    if (response == 0) {
        std::cout << "You examine the branches on the tree in front of you and contemplate the best way to reach a clump of fruit you spotted near the top.\n\n";
        pause0();
        std::cout << "You have little trouble making your way up. You pull four fruits from the tree and drop them to the ground, near your backpack.\n\n";
        pause0();
        std::cout << "For a few hours, you continue, climbing trees and retrieving the peculiar fruits.\n\n";
        pause0();
        std::cout << "Eventually, you stop for a rest. You worked up quite the appetite, but managed to collect a good amount of fruit.\n\n";
        pause0();

        stats.increaseFullness(-10);
        backpack.increase_item_quantity("Food (1 day)", 2);
    }
    else {
        std::cout << "You grab an extra fruit and stash it in your backpack for later. Then you continue on your way.\n\n";
        pause0();
        std::cout << "As you walk, you try to remember if you'd ever heard someone describe a similar fruit. It's astounding that items like this were so near to you all your life and yet you had no knowledge of their existence.\n\n";
        pause0();
        std::cout << "You make good progress over the " << time_of_day << ".\n\n";
        pause0();
        stats.increaseMilesJourneyed(13, backpack);
    }
}