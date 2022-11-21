#include <backpack.hpp>
#include <stats.hpp>
#include <helpers.hpp>
 
//Tier 1, raccoons steal your food
void event6(Backpack &backpack, Stats &stats, std::string time_of_day) {
    print_nice("After walking for an hour or so, you spot a gentle stream. The water looks cool and clear.\n\n");
    pause0();
    print_nice("You stop for a moment to take a drink. You rinse your hands and face. How nice!\n\n");
    stats.increaseHealth(5);
    pause0();
    print_nice("You turn to continue and notice three raccoons pressing their tiny heads into the opening of your backpack, which you had placed on the ground before approaching the stream.\n\n");
    pause0();

    if (backpack.item_quantity("Food (1 day)") == 0) {
        print_nice("You watch them quietly for a few seconds, clenching your fists in frustration.\n\n");
        pause0();
        print_nice("They seem to decide that there is nothing of interest in your pack, and scurry off as quietly as they arrived.\n\n");
        pause0();
        print_nice("Feeling invigorated, you grab your sack and take off.\n\n");
        pause0();
        print_nice("You're able to cover a good distance before ");
        if (time_of_day == "morning") {print_nice("midday");}
        else {print_nice("evening");}
        print_nice(".\n\n");
        pause0();
        stats.increaseMilesJourneyed(12, backpack);
    }
    else {
        print_nice("\"Nahhhhhh!\" you shout, and they scurry away.\n\n");
        pause0();
        print_nice("Unfortunately, you realize, they took off with some of your food in hand. Indeed, you check your sack and confirm that the little rascals thieved you.\n\n");

        //A choice
        std::vector<std::string> choices = {"Chase after the raccoons", "Accept your loss and move on"};

        print_nice("You have a choice to make.\n\n");
        for (int i = 0; i < choices.size(); i++) {
            print_nice("  " + std::string(1, int_to_letter(i)) + ". " + choices[i] + "\n");
        }
        print_nice("\n");

        int response = letter_to_int(input_checker_char(choices.size()));

        if (response == 0) {
            double amount_food_lost;
            double amount_food_regained;
            if (backpack.item_quantity("Food (1 day)") >= 2) {
                amount_food_lost = 2;
            } else {
                amount_food_lost = backpack.item_quantity("Food (1 day)");
            }
            backpack.increase_item_quantity("Food (1 day)", -2);

            //Choice
            print_nice("Do you\n\n");
            std::vector<std::string> choices = {"Dash after them", "Follow them quietly"};

            for (int i = 0; i < choices.size(); i++) {
                print_nice("  " + std::string(1, int_to_letter(i)) + ". " + choices[i] + "\n");
            }
            print_nice("\n");

            int response = letter_to_int(input_checker_char(choices.size()));

            if (response == 0) {
                print_nice("You sprint towards them, and they speed away in fear.\n\n");
                pause0();
                print_nice("You notice one of the raccoons dropped a piece of your food along the way. You add it back to your pack.\n\n");
                pause0();
                amount_food_regained += 0.5;
            } 
            else {
                print_nice("The raccoons have stopped a several yards away and seem to be examining the heisted food.\n\n");
                pause0();
                print_nice("You creep slowly towards them, placing your feet gently on the ground at each step.\n\n");
                pause0();
                print_nice("Suddenly, one of the raccoons turns your way. You freeze.\n\n");
                pause0();
                print_nice("It is too late. The raccoons scurry off into the forest.\n\n");
                pause0();
            }

            print_nice("You attempt to follow them.\n\n");
            pause0();


            //Choice
            print_nice("Do you\n\n");
            std::vector<std::string> choices2 = {"Go straight after them", "Veer to the side and try to get ahead of them"};

            for (int i = 0; i < choices2.size(); i++) {
                print_nice("  " + std::string(1, int_to_letter(i)) + ". " + choices2[i] + "\n");
            }
            print_nice("\n");

            int response2 = letter_to_int(input_checker_char(choices2.size()));

            if (response2 == 0) {
                print_nice("You run after the raccoons into the brush. You can hear fallen leaves crinkle under their feet as they run.\n\n");
                pause0();
                print_nice("Unfortunately, they can hear you as well.\n\n");
                pause0();
                print_nice("After a bit, their sounds cease. You stop to listen.\n\n");
                pause0();
            }
            else {
                print_nice("You head towards the right, hoping you are fast enough to outrun them.\n\n");
                pause0();
                print_nice("They seem to hear you, as you can tell they begin taking a more leftward trajectory.\n\n");
                pause0(); 
                print_nice("You correct your path, still hoping to get out in front of them.\n\n");
                pause0();
                print_nice("Suddenly, you lose their track. You stop and look around.\n\n");
                pause0();
                print_nice("The raccoons are nowhere to be seen.\n\n");
                pause0();
                print_nice("Ah, but wait! Close to your foot, you spot a dropped piece of your food!\n\n");
                pause0();
                amount_food_regained += 0.5;
            }

            print_nice("You suspect the raccoons must have stopped somewhere.\n\n");

            //Choice
            print_nice("Do you\n\n");
            std::vector<std::string> choices3 = {"Look in hollowed out tree nearby", "Check out a hole in the ground up ahead"};

            for (int i = 0; i < choices3.size(); i++) {
                print_nice("  " + std::string(1, int_to_letter(i)) + ". " + choices3[i] + "\n");
            }
            print_nice("\n");

            int response3 = letter_to_int(input_checker_char(choices3.size()));

            if (response3 == 0) {
                print_nice("As you approach the tree, you hear some noise coming from inside.\n\n");
                pause0();
                print_nice("A woodpecker pops its head out the hole and you realize you likely heard the sounds of a nest full of baby birds inside the tree.\n\n");
                pause0();
                print_nice("You hear a sound coming from behind and turn quickly to see the raccoons dashing out of the hole in the ground into some brush nearby.\n\n");
                pause0();
                print_nice("You sneakily walk that way.\n\n");
                pause0();
            }
            else {
                print_nice("You approach the hole cautiously, debating whether it is safe to reach your hand inside.\n\n");
                pause0();
                print_nice("Before you can decide, the three little bandits dash from the hole into some brush nearby.\n\n");
                pause0();
                print_nice("You jump back in surprise!\n\n");
                pause0();
                print_nice("You step forward again and peer into the hole. Aha! You retrieve a piece of your food.\n\n");
                pause0();
                amount_food_regained += 0.5;
            }

            print_nice("The raccoons are still in the brush pile. You can hear them moving around inside. Is that the sound of chewing you hear?\n\n");
            pause0();
            print_nice("You see a stick nearby.\n\n");
            pause0();

            //Choice
            print_nice("Do you\n\n");
            std::vector<std::string> choices4 = {"Poke the brush pile with the stick, or", "Cut your loses and get back to traveling"};

            for (int i = 0; i < choices4.size(); i++) {
                print_nice("  " + std::string(1, int_to_letter(i)) + ". " + choices4[i] + "\n");
            }
            print_nice("\n");

            int response4 = letter_to_int(input_checker_char(choices.size()));

            if (response4 == 0) {
                print_nice("You can't let these furry rascals get away with this!\n\n");
                pause0();
                print_nice("You prod the pile of leaves and debris with the stick, carefully at first, then more rigorously.\n\n");
                pause0();
                print_nice("Attack!! One of the raccoons leaps at your face. Its sharp claws leave a set of lacerations across your left cheek.\n\n");
                pause0();
                print_nice("Before you can retaliate, all three raccoons scutter away. You hang your head in defeat.\n\n");
                pause0();
                stats.increaseHealth(-15);

                if (backpack.item_quantity("First aid kit") > 0) {
                    print_nice("Use first aid kit?\n\n");
                    std::vector<std::string> choices5 = {"Yes", "No"};

                    for (int i = 0; i < choices5.size(); i++) {
                        print_nice("  " + std::string(1, int_to_letter(i)) + ". " + choices5[i] + "\n");
                    }
                    print_nice("\n");

                    int response5 = letter_to_int(input_checker_char(choices5.size()));

                    if (response5 == 0) {backpack.item_action("First aid kit", stats, backpack);}
                }
                
            }
            else {
                print_nice("It's probably not a good idea to provoke the raccoons. You lean against a nearby tree to catch your breath.\n\n");
                pause0();
                print_nice("You can still hear the trio rustling around in the pile of leaves and debris.\n\n");
                pause0();
                print_nice("After a few minutes, they scutter away. You gingerly reach your hand into the brush and after a moment of searching, find a piece of your lost food.\n\n");
                pause0();
                amount_food_regained += 0.5;
            }

            print_nice("It is time get back to the expedition.\n\n");
            pause0();


            //Conclusion
            if (amount_food_regained >= amount_food_lost) {
                print_nice("You retrieved all of your food!\n\n");
            }
            else if (amount_food_regained >= amount_food_lost - 0.5 &&
                        amount_food_lost > 1) {
                print_nice("You got back most of your food!");
                backpack.increase_item_quantity("Food (1 day)", amount_food_regained - amount_food_lost);
            }
            else if (amount_food_regained == 0) {
                print_nice("What a wasted " + time_of_day + "!\n\n");
                backpack.increase_item_quantity("Food (1 day)", -2);
            } 
            else {
                print_nice("At least you got back some of your food...\n\n");
                backpack.increase_item_quantity("Food (1 day)", -2);
                backpack.increase_item_quantity("Food (1 day)", amount_food_regained);
            }
            pause0();
            print_nice("You return to the stream and rinse again. It's time for a break.\n\n");
            pause0();
        }
        else {
            backpack.increase_item_quantity("Food (1 day)", -2);
            print_nice("You look in your pack. You have " + double_to_nice_string(backpack.item_quantity("Food (1 day)")));
            if (backpack.item_quantity("Food (1 day)") == 1) {print_nice(" day ");}
            else {print_nice(" days ");}
            print_nice("worth of food remaining.\n\n");
            pause0();
            print_nice("You sigh and continue on your way, cursing the raccoons under your breath.\n\n");
            pause0();
            print_nice("Fortunately, the path ahead is easy, and your irritation speeds your pace.\n\n");
            pause0();
            print_nice("You're able to cover a good distance before stopping for a rest.\n\n");
            pause0();
            stats.increaseMilesJourneyed(12, backpack);
        }
    }
}