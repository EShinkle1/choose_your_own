#include <string>
#include <backpack.hpp>
#include <stats.hpp>
#include <helpers.hpp>

//Event 9: Tier 4, healing statue
//Event 10: Tier 3, good luck statue
//Event 11: Tier 2, sleep statue
void event9_10_11(Backpack &backpack, Stats &stats, std::string time_of_day, int event_number, int statue_encounters) {
                                                         // time_of_day = "morning" or "afternoon"
    std::string smell_of_air;
    std::string observe_on_ground;
    std::string what_it_is;

    if (event_number == 9) {
        smell_of_air = "warmth";
        observe_on_ground = "knobby roots of trees slithering in and out of the ground.";
        what_it_is = "It looks like an extra large walking stick, about the same height as you, with a granite-like rock twisting about it, as though it were fabric.";
    } else if (event_number == 10) {
        smell_of_air = "sweetness";
        observe_on_ground = "clovers scatter about the forest floor.";
        what_it_is = "It is a large, flat rock, perfectly rounded, with small stones pressed into it in the shape of a star. It about as wide as your arm span, but appears to be balancing upon a small rock about the size of your fist.";
    } else if (event_number == 11) {
        smell_of_air = "crispness";
        observe_on_ground = "soft, billowy clouds in the sky.";
        what_it_is = "It is a collection of sticks arranged in a circle and all leaning towards the center to resemble a small hut. There is a cool mist in the air that seems to be centralized to this area.";
    } else {
        print_nice("WARNING: Only event_numbers 9, 10, and 11 can be supplied to this function, but event_number " + std::to_string(event_number) + " was supplied.\n\n");
        return;
    }

    std::string directions[2] = {"left", "right"};
    
    //Intro text
    print_nice("You continue forward. There is a strange " + smell_of_air + " to the air.\n\n");
    pause0();
    print_nice("You walk for a while, observing the " + observe_on_ground + "\n\n");
    pause0();
    print_nice("You notice something to the " + directions[rand() % 2] + ". It looks like a statue or monument of sorts.\n\n");
    pause0();

    //A choice
    std::vector<std::string> choices = {"Continue forward", "Stop to check out the object"};

    print_nice("You have a choice to make.\n\n");
    for (int i = 0; i < choices.size(); i++) {
        print_nice("  " + std::string(1, int_to_letter(i)) + ". " + choices[i] + "\n");
    }
    print_nice("\n");

    int response = letter_to_int(input_checker_char(2));

    if (response == 1) {
        print_nice("You head over to see exactly what it is.\n\n");
        pause0();
        print_nice(what_it_is + " It is quite bizarre.\n\n");
        pause0();
        if (statue_encounters == 0) {
            print_nice("You reach out to touch it, but hesitate. There is a strange feeling about it.\n\n");
        } else if (statue_encounters == 1) {
            print_nice("You pause, not sure what to make of this.\n\n");
        } else {
            print_nice("How many weird statues does this forest have?\n\n");
        }
        pause0();

        //A choice
        std::vector<std::string> choices = {"Touch it", "Head back to the path"};

        print_nice("What would you like to do?\n\n");
        for (int i = 0; i < choices.size(); i++) {
            print_nice("  " + std::string(1, int_to_letter(i)) + ". " + choices[i] + "\n");
        }
        print_nice("\n");

        int response2 = letter_to_int(input_checker_char(2));

        if (response2 == 1) {
            print_nice("You back away, feeling uncomfortable. You head back to the path you were following, looking back over your shoulder a few times along the way.\n\n");
            pause0();
        } else {
            print_nice("You slowly reach out and touch the object with the tip of your finger.\n\n");
            pause0();
            
            if (event_number == 9) {
                if (stats.getHealth() >= 90) {
                    print_nice("You feel a tingle rush over your body. You feel a bit more alert.\n\n");
                    pause0();
                    stats.increaseHealth(10);
                } else if (stats.getHealth() >= 50) {
                    print_nice("You quiver a bit and take a quick step back. You feel invigorated and ready to continue ahead.\n\n");
                    pause0();
                    stats.increaseHealth(20);
                } else {
                    print_nice("You feel momentarily stunned. Once you recover yourself, you realize that you are feeling substantially better than before.\n\n");
                    pause0();
                    print_nice("You're not sure what to make of this, but it is nice feel less weary.\n\n");
                    pause0();
                    stats.increaseHealth(30);
                }
                print_nice("You head back to continue walking, pondering what you just experienced.\n\n");
                pause0();
                std::string stopping_spots[3] = {"narrow stream up ahead", "shaded grassy spot ahead and to the right", "large rock under some trees over to the left"};
                print_nice(std::string("Eventually, you see a ") + stopping_spots[rand() % 3] + " ahead. This seems like a good place to stop for a break.\n\n");
                stats.increaseMilesJourneyed(10, backpack);
                pause0();
            } else if (event_number == 10) {
                print_nice("You touch your finger to one of the stones that make up the star. Suddenly, you entire palm is pressed against the rock and you're not sure you'd be able to pull it away if you tried.\n\n");
                pause0();
                print_nice("The stone appears to glow just a bit. You feel as though you are floating in a sea of light.\n\n");
                pause0();
                print_nice("Then, in an instance, everything returns to normal and you return your hand to your side. You feel slightly flushed.\n\n");
                pause0();
                print_nice("Though it is daytime, you see a star shoot across the sky. You feel as if favor is upon you.\n\n");
                pause0();
                stats.increaseLuck(10);
                print_nice("You head back to continue walking, pondering what you just experienced.\n\n");
                pause0();
                std::string stopping_spots[3] = {"narrow stream up ahead", "shaded grassy spot ahead and to the right", "large rock under some trees over to the left"};
                print_nice(std::string("Eventually, you see a ") + stopping_spots[rand() % 3] + " ahead. This seems like a good place to stop for a break.\n\n");
                stats.increaseMilesJourneyed(10, backpack);
                pause0();
            } else if (event_number == 11) {
                print_nice("You touch the arrangement gingerly...\n\n");
                pause0();
                print_nice("...\n\n");
                pause0();
                print_nice("...\n\n");
                pause0();
                print_nice("You awake from a deep sleep. It seems you've been out most of the " + time_of_day + ".\n\n");
                pause0();
                print_nice("You can't recall anything that happened after touching the stone.\n\n");
                pause0();
                print_nice("Perhaps you needed the sleep anyways...\n\n");
                stats.increaseHealth(5);
                pause0();
                if (time_of_day == "morning") {
                    print_nice("You might as well have lunch here before setting off for some afternoon walking.\n\n");
                } else {
                    print_nice("You might as well find a good place here to camp out for the night.\n\n");
                }
                pause0();
            }
        }
    } else {
        print_nice("You can be curious once you reach your destination, you decide, and keep forging ahead.\n\n");
        pause0();
        std::string fruits[3] = {"peach", "apple", "pear"};
        print_nice("As you're walking, you notice some " + fruits[rand() % 3] + " trees. You grab the better looking fruits from the trees as you pass by.\n\n");
        pause0();
        print_nice("You eat a bit as you walk and save the rest for later.\n\n");
        backpack.increase_item_quantity("Food (1 day)", 1);
        stats.increaseFullness(10);
        stats.increaseMilesJourneyed(12, backpack);
        pause0();
    }
}