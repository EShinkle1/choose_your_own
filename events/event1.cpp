#include <backpack.hpp>
#include <stats.hpp>
#include <helpers.hpp>

//Tier 3, dried fruit and nuts available off-course for a price
void event1(Backpack &backpack, Stats &stats, std::string time_of_day) {
    //Intro
    print_nice("You continue on your trek. The forest ahead is especially dense. \n\n");
    pause0();
    print_nice("Fortunately, you spot a narrow path. It looks as though it is treaded on frequently. You pause to look around, but don't see anything except tree after tree.\n\n");
    pause0();
    print_nice("You follow along the foot path for some time. Eventually it turns sharply to the right. It looks as though it continues in that direction for some time.\n\n");

    //A choice
    std::vector<std::string> choices = {"Turn to the right and continue along the footpath.", "Keep moving forward. The forest seems to be thinning out ahead."};

    print_nice("You have a choice to make.\n\n");
    for (int i = 0; i < choices.size(); i++) {
        print_nice("  " + std::string(1, int_to_letter(i)) + ". " + choices[i] + "\n");
    }
    print_nice("\n");

    int response = letter_to_int(input_checker_char(2));

    //Outcome
    if (response == 1) {
        print_nice("You continue forward. The woods start to thin, and you are able to move more quickly.\n\n");
        pause0();
        print_nice("You walk for several hours, enjoying the sounds of birds chirping and the beams of sunlight peaking through the forest canopy. \n\n");
        pause0();
        print_nice("As you stop to take a rest, you are reminded of the footpath you traveled along earlier. It's probably good that you didn't follow it any further -- who knows how long it could have distracted you.\n\n");
        stats.increaseHealth(10);
        stats.increaseMilesJourneyed(10, backpack);
    } else {
        print_nice("You continue to follow the footpath, curious as to where it may lead. You follow it for some time before it veers to the right again.\n\n");
        pause0();
        print_nice("You continue to follow the path. It curves back to the left.\n\n");
        pause0();
        print_nice("You follow along for some time longer until a small structure comes into view. As you near the structure, the footpath ends.\n\n");
        pause0();
        print_nice("You approach the makeshift shelter cautiously. It appears to be constructed from three rotting logs and a large dirtied piece of cloth, draped to form a roof. \n\n");
        pause0();
        print_nice("Inside you see a worn leather bag. You open the bag to find a mixture of dried fruit and nuts.\n\n");

        //A sub-choice
        std::vector<std::string> choices = {"Add the sack of food to your backpack.", "Leave the sack where it is."};

        print_nice("You have a choice to make.\n\n");
        for (int i = 0; i < choices.size(); i++) {
            print_nice("  " + std::string(1, int_to_letter(i)) + ". " + choices[i] + "\n");
        }
        print_nice("\n");

        int response = letter_to_int(input_checker_char(2));

        if (response == 1) {
            print_nice("You set down the sack of food and look around. There is dense forest in every direction. You head west once again, brushing branches and foliage out of your way as you go along. \n");
            pause0();
            print_nice("Eventually, the trees start to thin. This seems like a good place to rest.\n\n");
            stats.increaseMilesJourneyed(5, backpack);
        } else {
            print_nice("You grab the sack and step back from the structure. \n\n");
            pause0();
            print_nice("The forest is still. As you begin heading west again, a cold breeze whisks leaves off the trees around you. You shiver and clutch your pack a bit tighter as you continue through the woods. \n\n");
            pause0();
            print_nice("Eventually, the trees start to thin. This seems like a good place to rest.\n\n");
            backpack.increase_item_quantity("Food (1 day)", 2);
            stats.increaseMilesJourneyed(5, backpack);
            stats.increaseLuck(-20);
        }
    }

    pause0();
}