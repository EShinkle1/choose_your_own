#include <backpack.hpp>
#include <stats.hpp>
#include <helpers.hpp>

//Tier 1, rainstorm
void event8(Backpack &backpack, Stats &stats, std::string time_of_day) {
                                                       // time_of_day = "morning" or "afternoon"

    //Intro text
    print_nice("You begin walking, hoping to make good progress this " + time_of_day + ".\n\n");
    pause0();
    print_nice("The sky looks a bit grey and the air feels moist. You wonder if it is about to rain.\n\n");
    pause0();
    print_nice("As you continue, the sky begins to clear a bit, and you can see the sun peeking out from behind some clouds.\n\n");
    pause0();
    print_nice("Unfortunately, it is not long before the sun in nowhere in sight and thick, grey clouds roll across the sky. You feel a cool breeze rush by.\n\n");
    pause0();
    print_nice("Before long, it begins to pour. Large raindrops splash on the ground around you and one smacks you right on the end of your nose.\n\n");
    pause0();

    //A choice
    std::vector<std::string> choices = {"Continue walking", "Crouch under some nearby trees and wait out the storm"};
    if (backpack.item_present("Makeshift tent")) {choices.push_back("Set up your tent and rest inside");}
    if (backpack.item_present("Blanket")) {choices.push_back("Use your blanket as a poncho and continue walking");}


    print_nice("You have a choice to make.\n\n");
    for (int i = 0; i < choices.size(); i++) {
        print_nice("  " + std::string(1, int_to_letter(i)) + ". " + choices[i] + "\n");
    }
    print_nice("\n");

    int response = letter_to_int(input_checker_char(choices.size()));

    if (response == 0) {
        print_nice("You decide to tough it out and continue forward.\n\n");
        pause0();
        print_nice("As the ground absorbs water, it becomes muddy and slippery. You tread carefully, not wishing to fall and coat yourself with the slimy mud.\n\n");
        pause0();
        print_nice("The rain continues to pour, soaking your clothes and hair. Your clothes feel heavy and you wonder if they are helping you stay warm at all.\n\n");
        pause0();
        print_nice("After some time, ");
        if (time_of_day == "morning") {
            print_nice("the clouds begin to part and you see the sun is now high in the sky. The rain turns to a drizzle, and then ceases completely. You see a faint rainbow high in the sky.\n\n");
            pause0();
            print_nice("This seems like a good time to stop for lunch.\n\n");
        } 
        else {
            print_nice("the sun begins to set. The rain begins to lessen. It turns to a drizzle, and then ceases completely. The clouds part and you have a surprisingly good view of the night sky.\n\n");
            pause0();
            print_nice("This seems like a good time to stop for the night.\n\n");
        }
        pause0();
        print_nice("Your clothes are still very wet and you cannot stop yourself from shivering.\n\n");
        if (backpack.item_present("Change of clothes")) {
            pause0();
            print_nice("Would you like to use a change of clothes?\n\n");
            std::string response1 = yes_or_no();
            if (response1 == "Y") {
                print_nice("You put on a clean set of clothes, still mostly kept dry in your sealed backpack. You exhale and feel a bit of tension release from your shoulders.\n\n");
                backpack.increase_item_quantity("Change of clothes", -1);
                stats.increaseHealth(-8);
            }
            else {
                print_nice("Best to save them for another time. You'll dry out. Eventually...\n\n");
                stats.increaseHealth(-15);
            }
        } else {
            stats.increaseHealth(-15);
        }
        stats.increaseLuck(10);
        stats.increaseMilesJourneyed(7, backpack);
    } else if (response == 1) {
        //"Crouch under some nearby trees and wait out the storm"
        print_nice("You look around for a spot with good cover. Your clothes are quickly becoming soaked.\n\n");
        pause0();
        print_nice("You spot a good hideout under a large sloping rock with some dense trees surrounding it. The ground is even dry in some patches still.\n\n");
        pause0();
        if (backpack.item_present("Change of clothes")) {
            print_nice("Would you like to use a change of clothes?\n\n");
            std::string response1 = yes_or_no();
            if (response1 == "Y") {
                print_nice("The dry clothes stick to your moistened skin as you struggle to get them on. They are a welcome relief, though.\n\n");
                backpack.increase_item_quantity("Change of clothes", -1);
                pause0();
                print_nice("You wait, under the shelter of the rock and trees, as the rain continues to pound the ground around you.\n\n");
                pause0();
                print_nice("You even doze off for a bit. You might have needed this rest more than you realized.\n\n");
                stats.increaseHealth(5);
                pause0();
            }
            else {
                print_nice("Best to save them for another time. You'll dry out. Eventually...\n\n");
                pause0();   
                print_nice("You wait, under the shelter of the rock and trees, as the rain continues to pound the ground around you.\n\n");
                pause0();
                print_nice("Your wet clothes feel like an ice blanket and you find yourself shivering for quite some time.\n\n");
                stats.increaseHealth(-8);
                pause0();
            }
        } else {
            print_nice("You wait, under the shelter of the rock and trees, as the rain continues to pound the ground around you.\n\n");
            pause0();
            print_nice("Your wet clothes feel like an ice blanket and you find yourself shivering for quite some time.\n\n");
            stats.increaseHealth(-8);
            pause0();
        }
        print_nice("Eventually, the rain begins to clear. ");
        if (time_of_day == "morning") {
            print_nice("The sun is now high in the sky. You might as well have some lunch before setting off for some afternoon hiking.\n\n");
        } 
        else {
            print_nice("It is quickly growing dark. Perhaps it is best to stay here for the night.\n\n");
        }

    } else if (response == 2 && backpack.item_present("Makeshift tent")) {
        //"Set up your tent and rest inside"
        print_nice("You look for a place to pitch your tent.\n\n");
        pause0();
        print_nice("You spot a flat section, with enough tree cover that the ground is still mostly dry. You quickly set up your tent.\n\n");
        pause0();
        print_nice("You ring as much water out of your clothes as possible, and settle down to wait out the storm.\n\n");
        pause0();
        print_nice("You nod in and out of sleep. The break was probably good for you.\n\n");
        pause0();
        stats.increaseHealth(5);

        print_nice("Eventually, the rain begins to clear. ");
        if (time_of_day == "morning") {
            print_nice("The sun is now high in the sky. You might as well have some lunch before setting off for some afternoon hiking.\n\n");
        } 
        else {
            print_nice("It is quickly growing dark. Perhaps it is best to stay here for the night.\n\n");
        }

    } else if ((response == 2 && !backpack.item_present("Makeshift tent")) || response == 3) {
        if (
            !backpack.item_present("Blanket")) {print_nice("WARNING: Selected option to use blanket but no blanket is available.\n\n");
            pause0();
            return;
        }
        //"Use your blanket as a poncho and continue walking"
        print_nice("You wrap your blanket strategically around your head and torso, hoping to deflect as much rain from your clothes and body as possible. You set off.\n\n");
        pause0();
        print_nice("The ground is becoming very slippery as the water saturates the forest floor. You tread carefully, not wishing to fall and coat yourself with the slimy mud.\n\n");
        pause0();
        print_nice("You can feel dampness slowly reaching your clothes, but overall, your blanket-poncho seems to be working. Your feet are quite cold but the blanket is helping keep your upper body at a tolerable temperature.\n\n");
        pause0();
        print_nice("After some time, ");
        if (time_of_day == "morning") {
            print_nice("the clouds begin to part and you see the sun is now high in the sky. The rain turns to a drizzle, and then ceases completely. You see a faint rainbow high in the sky.\n\n");
            pause0();
            print_nice("This seems like a good time to stop for lunch.\n\n");
        } 
        else {
            print_nice("the sun begins to set. The rain begins to lessen. It turns to a drizzle, and then ceases completely. The clouds part and you have a surprisingly good view of the night sky.\n\n");
            pause0();
            print_nice("This seems like a good time to stop for the night.\n\n");
        }
        pause0();
        print_nice("Your clothes are damp but should dry quickly presuming the rain does not return. You wrap the blanket around your feet to help them warm up.\n\n");
        stats.increaseHealth(-5);
        stats.increaseLuck(10);
        stats.increaseMilesJourneyed(7, backpack);
    } else {
        print_nice("WARNING: Something went wrong with choice selection. The option selected was " + double_to_nice_string(response) + " but the list of choices has length " + double_to_nice_string(choices.size()) + "\n\n");
        pause0();
        return;
    }

    pause0();
}