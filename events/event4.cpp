#include <backpack.hpp>
#include <stats.hpp>
#include <helpers.hpp>

//Tier 2, steep climb or long journey around hill
void event4(Backpack &backpack, Stats &stats, std::string time_of_day) {
    print_nice("As you walk along, you hear the characteristic croak of a frog. You pause for a moment and look around before returning on your way. \n\n");
    pause0();
    print_nice("In a forest like this, there are critters everywhere. You wonder what sorts of creatures you have passed unknowingly already during your journey.\n\n") ;
    pause0();
    print_nice("Up ahead the ground slopes up steeply, with only a few trees along the rocky soil. You walk closer, observing the soil. The ball of your foot sinks a bit as you take another step forwards. The rocky, muddy hill seems to extend to your left and right.\n\n");
    pause0();

    //A choice
    std::vector<std::string> choices = {"Continue forward.", "Head to the right.", "Head to the left."};

    print_nice("You have a choice to make.\n\n");
    for (int i = 0; i < choices.size(); i++) {
        print_nice("  " + std::string(1, int_to_letter(i)) + ". " + choices[i] + "\n");
    }
    print_nice("\n");

    int direction_response = letter_to_int(input_checker_char(3));

    if (direction_response == 0) {
        int climbing_ability = stats.getLuck(backpack) + stats.getHealth();
        print_nice("You decide to press forward. ");
        if (backpack.item_quantity("Walking Stick") > 0) {
            print_nice("Fortunately, you have a walking stick to aid your ascent. ");
            climbing_ability += 50;
        }
        if (stats.getHealth() < 50) { 
            print_nice("You are already feeling weak and hope you have the strength to make it. ");
        }
        print_nice("You begin the climb. It is strenuous, but you are making progress.\n\n");
        pause0();
        print_nice("Suddenly, your foot slips out from under you and you start to tumble backwards.\n\n");
        pause0();
        if ((rand() % 200 > climbing_ability)) {
            print_nice("A sharp pain bursts from your toes up to your kneecap. Your foot hit a large stone which protruded from the ground at an odd angle. It stopped your fall but you can already feel your foot beginning to swell.\n\n");
            pause0();
            stats.increaseHealth(-6);
        } 
        else {
            print_nice("You slide for a moment, but your hand grasps a large stone with protrudes from the ground at an odd angle. Relieved but shaken, you stand up and continue your climb.\n\n");
            pause0();
        }
        print_nice("A dozen meters up, it looks as though the ground begins to level out. You are tiring, but press forward. You can tell the dirt is drier ahead.\n\n");
        pause0();
        if (rand() % 200 > climbing_ability + 50) {
            print_nice("You quicken your pace. Unfortunately, as you do so, the seam of your pant leg catches on a fallen branch. You find yourself tumbling downward, collecting bruises and scratches along the way.\n\n");
            pause0();
            print_nice("You fall about halfway back before colliding with a tree trunk and coming to a stop. You pound the tree with your fist in frustration.\n\n");
            pause0();
            print_nice("After taking some time to collect yourself, you cautiously start again. You fight the urge to blink, as though even a moment of distraction could leave you falling to your death.\n\n");
            pause0();
            print_nice("This time you succeed! Upon reaching the flat ground spotted earlier, you collapse onto the dirt. You will need a break to recover.\n\n");
            pause0();
            stats.increaseMilesJourneyed(4, backpack);
            stats.increaseHealth(-10);
        }
        else {
            print_nice("You reach the top and stop for a moment to look down. You are lucky that you made it to the top at all.\n\n");
            pause0();
            print_nice("Your eyes turn back forwards to a flat stretch ahead. You're able to get in a few more hours of walking before you stop for a break.\n\n");
            pause0();
            stats.increaseMilesJourneyed(8, backpack);
        }
    } 
    else {
        std::vector<std::string> direction = {"NA", "right", "left"};
        print_nice("You head to the " + direction[direction_response] + ". You walk for some time, but the terrain remains the same. You can tell the sun has moved in the sky from when you first began. \n\n");
        pause0();

        //A choice
        std::vector<std::string> choices = {"Continue forward.", "Turn back."};

        print_nice("You have a choice to make.\n\n");
        for (int i = 0; i < choices.size(); i++) {
            print_nice("  " + std::string(1, int_to_letter(i)) + ". " + choices[i] + "\n");
        }
        print_nice("\n");

        int response = letter_to_int(input_checker_char(2));

        if (response == 0) {
            print_nice("Surely there is a way around this obstacle, you think to yourself. Right?\n\n");
            pause0();
        } 
        else {
            print_nice("Best to cut your losses, you decide. You pause for a moment and suddenly notice the sound of flowing water ahead. You decide to continue a bit further to check it out.\n\n");
            pause0();
        } 
        print_nice("Indeed! After walking a bit further, you discover a stream of water, which has carved out a narrow passage through the hill.\n\n");
        print_nice("Your clothes will surely get soaked, but it looks as though you can follow the stream for some time.\n\n");
        pause0();
        print_nice("After wading along the stream for what certainly must have been at least a few hours, the passage begins to widen and you see trees and flat land ahead. The stream veers off to the " + direction[direction_response] + " and you find your cold feet on dry ground again.\n\n");

        pause0();

        if (backpack.item_quantity("Change of clothes") > 0) {
            print_nice("You remember that you have extra clothes in your backpack.\n\n");
            print_nice("Use change of clothes?\n\n");
            print_nice("  A. Yes\n");
            print_nice("  B. No\n\n");
            int choice = letter_to_int(input_checker_char(2));

            if (choice == 0) {
                backpack.increase_item_quantity("Change of clothes", -1);
                print_nice("How nice it is to be dry again! You have earned yourself a rest.\n\n");
                pause0();
            } else {
                print_nice("You do your best to ring the water out of your clothes and sit down to rest for a bit. Hopefully your clothes will dry out quickly.\n\n");
                stats.increaseHealth(-6);
                pause0();
            }
        } else {
            print_nice("You do your best to ring the water out of your clothes and sit down to rest for a bit. Hopefully your clothes will dry out quickly.\n\n");
            stats.increaseHealth(-6);
            pause0();
        }
        stats.increaseMilesJourneyed(4, backpack);
    }
}