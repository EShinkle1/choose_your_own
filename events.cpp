#include "events.hpp"
#include "stats.hpp"
#include "helpers.hpp"
#include "backpack.hpp"
#include <iostream>
#include <algorithm>
#include <random>

std::vector<int> * Events::choose_tier(Stats stats, Backpack backpack) {
    int score = rand() % 200 + stats.getLuck(backpack);
    if (score < 50) {
        return &Tier1;
    } else if (score < 100) {
        return &Tier2;
    } else if (score < 150) {
        return &Tier3;
    } else {
        return &Tier4;
    }
}

void Events::get_event(Stats &stats, Backpack &backpack, std::string time_of_day) {
    std::vector<int>& tier = *choose_tier(stats, backpack);

    int size = tier.size();

    if (size == 0) {
        std::cout << "You proceed with your journey. You walk forward, left foot, right foot, left foot, right foot.\n\n";
        pause();
        std::cout << "Your eyelids feel heavy. You press ahead.\n\n";
        pause();
        std::cout << "You eventually stop and realize you've been walking for quite some time. You remember little from the walk and have no idea how much progress you've made.\n\n";
        pause();
        std::cout << "Maybe it's time for a break.\n\n";
        stats.increaseMilesJourneyed(5 + (rand() % 10), backpack);
        pause();
        return;
    }

    int idx = rand() % size;
    //int event = tier[idx];
    int event = 5;

    tier.erase(tier.begin()+idx);
    
    switch (event) {
        //Notes:
        //Tier 1 worst, Tier 4 best.
        //Journey is 100 miles long, average length covered during an event should be 10 miles.
        //Northern route has difficult terrain but fewer creatures.
        //Each event should end with finding a place to take a break. 
        //Each outcome should end with two line breaks, followed by a pause().


        ////////////////////////////////////////////////////////////////////////////////////////////
        case 0: //Tier 4, find good berries
        {
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
                pause();
                std::cout << "The terrain ahead is very easy. You cover a good distance. Finally after many hours of walking, you decide it's time for a break. \n\n";
                stats.increaseMilesJourneyed(12, backpack);
            } else {
                std::cout << "There is no time to waste. You keep moving. \n\n";
                pause();
                std::cout << "The terrain ahead is very easy. You cover a good distance. Finally after many hours of walking, you decide it's time for a break. \n\n";
                stats.increaseMilesJourneyed(15, backpack);
            }

            pause();
            break;
        }
        ////////////////////////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////////////////////////
        case 1: //Tier 3, dried fruit and nuts available off-course for a price
        {
            //Intro
            std::cout << "You continue on your trek. The forest ahead is especially dense. \n\n";
            pause();
            std::cout << "Fortunately, you spot a narrow path. It looks as though it is treaded on frequently. You pause to look around, but don't see anything except tree after tree.\n\n";
            pause();
            std::cout << "You follow along the foot path for some time. Eventually it turns sharply to the right. It looks as though it continues in that direction for some time.\n\n";

            //A choice
            std::vector<std::string> choices = {"Turn to the right and continue along the footpath.", "Keep moving forward. The forest seems to be thinning out ahead."};

            std::cout << "You have a choice to make.\n\n";
            for (int i = 0; i < choices.size(); i++) {
                std::cout << "  " << int_to_letter(i) << ". " << choices[i] << "\n";
            }
            std::cout << "\n";

            int response = letter_to_int(input_checker_char(2));

            //Outcome
            if (response == 1) {
                std::cout << "You continue forward. The woods start to thin, and you are able to move more quickly.\n\n";
                pause();
                std::cout << "You walk for several hours, enjoying the sounds of birds chirping and the beams of sunlight peaking through the forest canopy. \n\n";
                pause();
                std::cout << "As you stop to take a rest, you are reminded of the footpath you traveled along earlier. It's probably good that you didn't follow it any further -- who knows how long you could have been stuck following it.\n\n";
                stats.increaseHealth(10);
                stats.increaseMilesJourneyed(10, backpack);
            } else {
                std::cout << "You continue to follow the footpath, curious as to where it may lead. You follow it for some time before it veers to the right again.\n\n";
                pause();
                std::cout << "You continue to follow the path. It curves back to the left.\n\n";
                pause();
                std::cout << "You follow along for some time longer until a small structure comes into view. As you near the structure, the footpath ends.\n\n";
                pause();
                std::cout << "You approach the makeshift shelter cautiously. It appears to be constructed from three rotting logs and a large dirtied piece of cloth, draped to form a roof. \n\n";
                pause();
                std::cout << "Inside you see a worn leather bag. You open the bag to find a mixture of dried fruit and nuts.\n\n";

                //A sub-choice
                std::vector<std::string> choices = {"Add the sack of food to your backpack.", "Leave the sack where it is."};

                std::cout << "You have a choice to make.\n\n";
                for (int i = 0; i < choices.size(); i++) {
                    std::cout << "  " << int_to_letter(i) << ". " << choices[i] << "\n";
                }
                std::cout << "\n";

                int response = letter_to_int(input_checker_char(2));

                if (response == 1) {
                    std::cout << "You set down the sack of food and look around. There is dense forest in every direction. You head west once again, brushing branches and foliage out of your way as you go along. \n\n";
                    pause();
                    std::cout << "Eventually, the trees start to thin. This seems like a good place to rest.\n\n";
                    stats.increaseMilesJourneyed(5, backpack);
                } else {
                    std::cout << "You grab the sack and step back from the structure. \n\n";
                    pause();
                    std::cout << "The forest is still. As you begin heading west again, a cold breeze whisks leaves off the trees around you. You shiver and clutch your pack a bit tighter as you continue through the woods. \n\n";
                    pause();
                    std::cout << "Eventually, the trees start to thin. This seems like a good place to rest.\n\n";
                    backpack.increase_item_quantity("Food (1 day)", 2);
                    stats.increaseMilesJourneyed(5, backpack);
                    stats.increaseLuck(-20);
                }
            }

            pause();
            break;
        }
        ////////////////////////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////////////////////////
        case 2: //Tier 2, find bad berries
        {
            //Intro text
            std::vector<std::string> berry_color = {"bright blue", "bright red", "bright purple"};
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
                std::cout << "You eat several handfuls of the berries. They are quite good. You continue your hike\n\n";
                pause();
                std::cout << "After walking for a bit, you begin to feel a bit dizzy and your stomach feels unsettled. Perhaps those berries weren't a good idea after all.\n\n";
                pause();
                std::cout << "You walk a bit further, but your stomach continues to tighten. Eventually you give up and sit down. \n\n";
                pause();
                std::cout << "You place your head in your hands and sit for a while. Eventually, you feel well enough to continue, but your sense of balance has yet to be restored...\n\n";
                pause();
                std::cout << "After a while, you pause to take a break.\n\n";
                pause();
                stats.increaseHealth(-5);
                stats.increaseMilesJourneyed(5, backpack);
            } else {
                std::cout << "There is no time to waste. You keep moving. \n\n";
                pause();
                std::cout << "The terrain is very easy. You cover a good distance. Finally after many hours of walking, you decide it's time for a break. \n\n";
                stats.increaseMilesJourneyed(15, backpack);
                pause();
            }
            break;
        }
        ////////////////////////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////////////////////////
        case 3: //Tier 1, fall into muddy stream
        {
            std::cout << "The air is crisp. You walk along at a moderate pace, occasionally stopping to glance at the colorful bugs crawling in and out of the crevices in the bark of the trees.\n\n";
            pause();
            std::cout << "If you got desperate enough, you think to yourself, ...\n\n";
            std::cout << "You shake your head to toss the thought from your mind.\n\n";
            pause();
            std::cout << "Suddenly your feel your foot sinking, as cold mud begins to envelop your lower leg. A thin stream of water splits as it hits your leg and passes across the front and back sides of your thigh.\n\n";
            pause();
            std::cout << "Unfortunately, you had already lifted your other leg before recognizing your misfortune, and in your attempt to rebalance find your chest and face pressed into the mud as well.\n\n";
            pause();
            std::cout << "Luckily, the mud is less than a foot deep and you are able to pull yourself up. You wipe off as much as you can and shiver as a breeze ruffles the leaves on the nearby trees.\n\n";
            pause();

            if (backpack.item_quantity("Change of clothes") > 0) {
                std::cout << "You remember that you have extra clothes in your backpack.\n\n";
                std::cout << "Use change of clothes?\n\n";
                std::cout << "  A. Yes\n";
                std::cout << "  B. No\n\n";
                int choice = letter_to_int(input_checker_char(2));

                if (choice == 0) {
                    backpack.increase_item_quantity("Change of clothes", -1);
                    std::cout << "You feel much better!\n\n";
                    pause();
                } else {
                    std::cout << "You continue walking, shivering as you go along. ";
                    stats.increaseHealth(-10);
                    std::cout << "Hopefully you'll be able to warm up soon.\n\n";
                    pause();
                }
            } else {
                std::cout << "You continue walking, shivering as you go along. You imagine how soothing a clean pair of clothes would feel. ";
                stats.increaseHealth(-10);
                std::cout << "Hopefully you'll be able to warm up soon.\n\n";
                pause();
            }
            std::cout << "You see a patch of grass ahead. It looks like a good place to take a break.\n\n";
            pause();
            stats.increaseMilesJourneyed(8, backpack);
            break;
        }
        /////////////////////////////////////////////////////////////////////////////////////////////

        /////////////////////////////////////////////////////////////////////////////////////////////
        case 4: //Tier 2, steep climb or long journey around hill
        {
            std::cout << "As you walk along, you hear the characteristic croak of a frog. You pause for a moment and look around before returning on your way. \n\n";
            pause();
            std::cout << "In a forest like this, there are critters everywhere. You wonder what sorts of creatures you have passed unknowingly already during your journey.\n\n" ;
            pause();
            std::cout << "Up ahead the ground slopes up steeply, with only a few trees along the rocky soil. You walk closer, observing the soil. The ball of your foot sinks a bit as you take another step forwards. The rocky, muddy hill seems to extend to your left and right.\n\n";
            pause();

            //A choice
            std::vector<std::string> choices = {"Continue forward.", "Head to the right.", "Head to the left."};

            std::cout << "You have a choice to make.\n\n";
            for (int i = 0; i < choices.size(); i++) {
                std::cout << "  " << int_to_letter(i) << ". " << choices[i] << "\n";
            }
            std::cout << "\n";

            int direction_response = letter_to_int(input_checker_char(3));

            if (direction_response == 0) {
                int climbing_ability = stats.getLuck(backpack) + stats.getHealth();
                std::cout << "You decide to press forward. ";
                if (backpack.item_quantity("Walking Stick") > 0) {
                    std::cout << "Fortunately, you have a walking stick to aid your ascent. ";
                    climbing_ability += 50;
                }
                if (stats.getHealth() < 50) { 
                    std::cout << "You are already feeling weak and hope you have the strength to make it. ";
                }
                std::cout << "You begin the climb. It is strenuous, but you are making progress.\n\n";
                pause();
                std::cout << "Suddenly, your foot slips out from under you and you start to tumble backwards.\n\n";
                pause();
                if ((rand() % 200 > climbing_ability)) {
                    std::cout << "A sharp pain bursts from your toes up to your kneecap. Your foot hit a large stone which protruded from the ground at an odd angle. It stopped your fall but you can already feel your foot beginning to swell.\n\n";
                    pause();
                    stats.increaseHealth(-6);
                } 
                else {
                    std::cout << "You slide for a moment, but your hand grasps a large stone with protrudes from the ground at an odd angle. Relieved but shaken, you stand up and continue your climb.\n\n";
                    pause();
                }
                std::cout << "A dozen meters up, it looks as though the ground begins to level out. You are tiring, but press forward. You can tell the dirt is drier ahead.\n\n";
                pause();
                if (rand() % 200 > climbing_ability + 50) {
                    std::cout << "You quicken your pace. Unfortunately, as you do so, the seam of your pant leg catches on a fallen branch. You find yourself tumbling downward, collecting bruises and scratches along the way.\n\n";
                    pause();
                    std::cout << "You fall about halfway back before colliding with a tree trunk and coming to a stop. You pound the tree with your fist in frustration.\n\n";
                    pause();
                    std::cout << "After taking some time to collect yourself, you cautiously start again. You fight the urge to blink, as though even a moment of distraction could leave you falling to your death.\n\n";
                    pause();
                    std::cout << "This time you succeed! Upon reaching the flat ground spotted earlier, you collapse onto the dirt. You will need a break to recover.\n\n";
                    pause();
                    stats.increaseMilesJourneyed(4, backpack);
                    stats.increaseHealth(-10);
                }
                else {
                    std::cout << "You reach the top and stop for a moment to look down. You are lucky that you made it to the top at all.\n\n";
                    pause();
                    std::cout << "Your eyes turn back forwards to a flat stretch ahead. You're able to get in a few more hours of walking before you stop for a break.\n\n";
                    pause();
                    stats.increaseMilesJourneyed(8, backpack);
                }
            } 
            else {
                std::vector<std::string> direction = {"NA", "right", "left"};
                std::cout << "You head to the " << direction[direction_response] << ". You walk for some time, but the terrain remains the same. You can tell the sun has moved in the sky from when you first began. \n\n";
                pause();

                //A choice
                std::vector<std::string> choices = {"Continue forward.", "Turn back."};

                std::cout << "You have a choice to make.\n\n";
                for (int i = 0; i < choices.size(); i++) {
                    std::cout << "  " << int_to_letter(i) << ". " << choices[i] << "\n";
                }
                std::cout << "\n";

                int response = letter_to_int(input_checker_char(2));

                if (response == 0) {
                    std::cout << "Surely there is a way around this obstacle, you think to yourself. Right?\n\n";
                    pause();
                } 
                else {
                    std::cout << "Best to cut your losses, you decide. You pause for a moment and suddenly notice the sound of flowing water ahead. You decide to continue a bit further to check it out.\n\n";
                    pause();
                } 
                std::cout << "Indeed! After walking a bit further, you discover a stream of water, which has carved out a narrow passage through the hill.\n\n";
                std::cout << "Your clothes will surely get soaked, but it looks as though you can follow the stream for some time.\n\n";
                pause();
                std::cout << "After wading along the stream for what certainly must have been at least a few hours, the passage begins to widen and you see trees and flat land ahead. The stream veers off to the " << direction[direction_response] << " and you find your cold feet on dry ground again.\n\n";

                pause();

                if (backpack.item_quantity("Change of clothes") > 0) {
                    std::cout << "You remember that you have extra clothes in your backpack.\n\n";
                    std::cout << "Use change of clothes?\n\n";
                    std::cout << "  A. Yes\n";
                    std::cout << "  B. No\n\n";
                    int choice = letter_to_int(input_checker_char(2));

                    if (choice == 0) {
                        backpack.increase_item_quantity("Change of clothes", -1);
                        std::cout << "How nice it is to be dry again! You have earned yourself a rest.\n\n";
                        pause();
                    } else {
                        std::cout << "You do your best to ring the water out of your clothes and sit down to rest for a bit. Hopefully your clothes will dry out quickly.\n\n";
                        stats.increaseHealth(-6);
                        pause();
                    }
                } else {
                    std::cout << "You do your best to ring the water out of your clothes and sit down to rest for a bit. Hopefully your clothes will dry out quickly.\n\n";
                    stats.increaseHealth(-6);
                    pause();
                }
                stats.increaseMilesJourneyed(4, backpack);
            }
            break;
        }
        /////////////////////////////////////////////////////////////////////////////////////////////

        /////////////////////////////////////////////////////////////////////////////////////////////
        case 5: //Tier 4, find fruit in trees
        {
            std::cout << "You're back at it. You take a casual pace, letting your mind wander as you walk along.\n\n";
            pause();
            if (stats.getMilesJourneyed() < 30) {
                std::cout << "You think about all the things you could encounter ahead. Your mind drifts back to your village. Hopefully you've made the right decision.\n\n";
            }
            else {
                std::cout << "You think about all the things you've already experienced. It's hard to guess how much longer you have to journey and what else you'll see along the way.\n\n";
            }
            pause();
            std::cout << "You notice a strange fruit on a bushy tree up ahead. It looks a bit like an oblong orange apple.\n\n";
            pause();
            std::cout << "You find one that is within your reach and pluck it from the branch. You examine its smooth, waxy exterior. Curious, you decide to try a bite.\n\n";
            pause();
            std::cout << "It's quite tasty! It has a subtle sweetness to it, followed by a burst of tartness.\n\n";
            pause();
            std::cout << "You look around and see that more trees bearing the fruit are scattered around the area. You may have to climb a bit to reach the most fruit, but the trees seem sturdy and have a lot of thick branches.\n\n";
            pause();

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
                pause();
                std::cout << "You have little trouble making your way up. You pull four fruits from the tree and drop them to the ground, near your backpack.\n\n";
                pause();
                std::cout << "For a few hours, you continue, climbing trees and retrieving the peculiar fruits.\n\n";
                pause();
                std::cout << "Eventually, you stop for a rest. You worked up quite the appetite, but managed to collect a good amount of fruit.\n\n";
                pause();

                stats.increaseFullness(-10);
                backpack.increase_item_quantity("Food (1 day)", 2);
            }
            else {
                std::cout << "You grab an extra fruit and stash it in your backpack for later. Then you continue on your way.\n\n";
                pause();
                std::cout << "As you walk, you try to remember if you'd ever heard someone describe a similar fruit. It's astounding that items like this were so near to you all your life and yet you had no knowledge of their existence.\n\n";
                pause();
                std::cout << "You make good progress over the " << time_of_day << ".\n\n";
                pause();
                stats.increaseMilesJourneyed(13, backpack);
            }
            break;
        }
        /////////////////////////////////////////////////////////////////////////////////////////////

        /////////////////////////////////////////////////////////////////////////////////////////////
        case 6: //Tier 1, raccoons steal your food
        {
            std::cout << "After walking for an hour or so, you spot a gentle stream. The water looks cool and clear.\n\n";
            pause();
            std::cout << "You stop for a moment to take a drink. You rinse your hands and face. How nice!\n\n";
            stats.increaseHealth(5);
            pause();
            std::cout << "You turn to continue and notice three raccoons pressing their tiny heads into the opening of your backpack, which you had placed on the ground before approaching the stream.\n\n";
            pause();

            if (backpack.item_quantity("Food (1 day)") == 0) {
                std::cout << "You watch them quietly for a few seconds, clenching your fists in frustration.\n\n";
                pause();
                std::cout << "They seem to decide that there is nothing of interest in your pack, and scurry off as quietly as they arrived.\n\n";
                pause();
                std::cout << "Feeling invigorated, you grab your sack and take off.\n\n";
                pause();
                std::cout << "You're able to cover a good distance before ";
                if (time_of_day == "morning") {std::cout << "midday";}
                else {std::cout << "evening";}
                std::cout << ".\n\n";
                pause();
                stats.increaseMilesJourneyed(12, backpack);
            }
            else {
               std::cout << "\"Nahhhhhh!\" you shout, and they scurry away.\n\n";
               pause();
               std::cout << "Unfortunately, you realize, they took off with some of your food in hand. Indeed, you check your sack and confirm that the little rascals thieved you.\n\n";

               //A choice
                std::vector<std::string> choices = {"Chase after the raccoons", "Accept your loss and move on"};

                std::cout << "You have a choice to make.\n\n";
                for (int i = 0; i < choices.size(); i++) {
                    std::cout << "  " << int_to_letter(i) << ". " << choices[i] << "\n";
                }
                std::cout << "\n";

                int response = letter_to_int(input_checker_char(choices.size()));

                if (response == 0) {
                    double initial_food_amount = backpack.item_quantity("Food (1 day)");
                    backpack.increase_item_quantity("Food (1 day)", -2);

                    //Choice
                    std::cout << "Do you\n\n";
                    std::vector<std::string> choices = {"dash after them, or", "follow them quietly?"};

                    for (int i = 0; i < choices.size(); i++) {
                        std::cout << "  " << int_to_letter(i) << ". " << choices[i] << "\n";
                    }
                    std::cout << "\n";

                    int response = letter_to_int(input_checker_char(choices.size()));

                    if (response == 0) {
                        std::cout << "You sprint towards them, and they speed away in fear.\n\n";
                        pause();
                        std::cout << "You notice one of the raccoons dropped a piece of your food along the way. You add it back to your pack.\n\n";
                        pause();
                        backpack.increase_item_quantity("Food (1 day)", 0.5);
                    } 
                    else {
                        std::cout << "The raccoons have stopped a several yards away and seem to be examining the heisted food.\n\n";
                        pause();
                        std::cout << "You creep slowly towards them, placing your feet gently on the ground at each step.\n\n";
                        pause();
                        std::cout << "Suddenly, one of the raccoons turns your way. You freeze.\n\n";
                        pause();
                        std::cout << "It is too late. The raccoons scurry off into the forest.\n\n";
                        pause();
                    }

                    std::cout << "You attempt to follow them.\n\n";
                    pause();


                    //Choice
                    std::cout << "Do you\n\n";
                    std::vector<std::string> choices2 = {"go straight after them, or", "veer to the side and try to get ahead of them?"};

                    for (int i = 0; i < choices2.size(); i++) {
                        std::cout << "  " << int_to_letter(i) << ". " << choices2[i] << "\n";
                    }
                    std::cout << "\n";

                    int response2 = letter_to_int(input_checker_char(choices2.size()));

                    if (response2 == 0) {
                        std::cout << "You run after the raccoons into the brush. You can fallen leaves crinkle under their feet as they run.\n\n";
                        pause();
                        std::cout << "Unfortunately, they can hear you as well.\n\n";
                        pause();
                        std::cout << "After a bit, their sounds cease. You stop to listen.\n\n";
                        pause();
                    }
                    else {
                        std::cout << "You head towards the right, hoping you are fast enough to outrun them.\n\n";
                        pause();
                        std::cout << "They seem to hear you, as you can tell they begin taking a more leftward trajectory.\n\n";
                        pause(); 
                        std::cout << "You correct your path, still hoping to get out in front of them.\n\n";
                        pause();
                        std::cout << "Suddenly, you lose their track. You stop and look around.\n\n";
                        pause();
                        std::cout << "The raccoons are nowhere to be seen.\n\n";
                        pause();
                        std::cout << "Ah, but wait! Close to your foot, you spot a dropped piece of your food!\n\n";
                        pause();
                        backpack.increase_item_quantity("Food (1 day)", 0.5);
                    }

                    std::cout << "You suspect the raccoons must have stopped somewhere.\n\n";

                    //Choice
                    std::cout << "Do you\n\n";
                    std::vector<std::string> choices3 = {"look in hollowed out tree nearby, or", "check out a hole in the ground up ahead?"};

                    for (int i = 0; i < choices3.size(); i++) {
                        std::cout << "  " << int_to_letter(i) << ". " << choices3[i] << "\n";
                    }
                    std::cout << "\n";

                    int response3 = letter_to_int(input_checker_char(choices3.size()));

                    if (response3 == 0) {
                        std::cout << "As you approach the tree, you hear some noise coming from inside.\n\n";
                        pause();
                        std::cout << "A woodpecker pops its head out the hole and you realize you likely heard the sounds of a nest full of baby birds inside the tree.\n\n";
                        pause();
                        std::cout << "You hear a sound coming from behind and turn quickly to see the raccoons dashing out of the hole in the ground into some brush nearby.\n\n";
                        pause();
                        std::cout << "You sneakily walk that way.\n\n";
                        pause();
                    }
                    else {
                        std::cout << "You approach the hole cautiously, debating whether it is safe to reach your hand inside.\n\n";
                        pause();
                        std::cout << "Before you can decide, the three little bandits dash from the hole into some brush nearby.\n\n";
                        pause();
                        std::cout << "You jump back in surprise!\n\n";
                        pause();
                        std::cout << "You step forward again and peer into the hole. Aha! You retrieve a piece of your food.\n\n";
                        pause();
                        backpack.increase_item_quantity("Food (1 day)", 0.5);
                    }

                    std::cout << "The raccoons are still in the brush pile. You can hear them moving around inside. Is that the sound of chewing you hear?\n\n";
                    pause();
                    std::cout << "You see a stick nearby.\n\n";
                    pause();

                    //Choice
                    std::cout << "Do you\n\n";
                    std::vector<std::string> choices4 = {"poke the brush pile with the stick, or", "cut your loses and get back to traveling?"};

                    for (int i = 0; i < choices4.size(); i++) {
                        std::cout << "  " << int_to_letter(i) << ". " << choices4[i] << "\n";
                    }
                    std::cout << "\n";

                    int response4 = letter_to_int(input_checker_char(choices.size()));

                    if (response4 == 0) {
                        std::cout << "You can't let these furry rascals get away with this!\n\n";
                        pause();
                        std::cout << "You prod the pile of leaves and debris with the stick, carefully at first, then more rigorously.\n\n";
                        pause();
                        std::cout << "Attack!! One of the raccoons leaps at your face. Its sharp claws leave a set of lacerations across your left cheek.\n\n";
                        pause();
                        std::cout << "Before you can retaliate, all three raccoons scutter away. You hang your head in defeat.\n\n";
                        pause();
                        stats.increaseHealth(-15);

                        if (backpack.item_quantity("First aid kit") > 0) {
                            std::cout << "Use first aid kit?\n\n";
                            std::vector<std::string> choices5 = {"Yes", "No"};

                            for (int i = 0; i < choices5.size(); i++) {
                                std::cout << "  " << int_to_letter(i) << ". " << choices5[i] << "\n";
                            }
                            std::cout << "\n";

                            int response5 = letter_to_int(input_checker_char(choices5.size()));

                            if (response5 == 0) {backpack.item_action("First aid kit", stats, backpack);}
                        }
                        
                    }
                    else {
                        std::cout << "It's probably not a good idea to provoke the raccoons. You lean against a nearby tree to catch your breath.\n\n";
                        pause();
                        std::cout << "You can still hear the trio rustling around in the pile of leaves and debris.\n\n";
                        pause();
                        std::cout << "After a few minutes, they scutter away. You gingerly reach your hand into the brush and after a moment of searching, find a piece of your lost food.\n\n";
                        pause();
                        backpack.increase_item_quantity("Food (1 day)", 0.5);
                    }

                    std::cout << "It is time get back to the expedition.\n\n";
                    pause();


                    //Conclusion
                    if (backpack.item_quantity("Food (1 day)") >= initial_food_amount) {
                        std::cout << "You retrieved all of your food!\n\n";
                        backpack.set_item_count("Food (1 day)", initial_food_amount);
                    }
                    else if (backpack.item_quantity("Food (1 day)") + 0.5 == initial_food_amount &&
                                initial_food_amount > 1) {
                        std::cout << "You got back most of your food!";
                    }
                    else if (backpack.item_quantity("Food (1 day)") == 0) {
                        std::cout << "What a wasted " << time_of_day << "!\n\n";
                    } 
                    else {
                        std::cout << "At least you got back some of your food...\n\n";
                    }
                    pause();
                    std::cout << "You return to the stream and rinse again. It's time for a break.\n\n";
                    pause();
                }
                else {
                    backpack.increase_item_quantity("Food (1 day)", -2);
                    std::cout << "You look in your pack. You have " << backpack.item_quantity("Food (1 day)");
                    if (backpack.item_quantity("Food (1 day)") == 1) {std::cout << " day ";}
                    else {std::cout << " days ";}
                    std::cout << "worth of food remaining.\n\n";
                    pause();
                    std::cout << "You sigh and continue on your way, cursing the raccoons under your breath.\n\n";
                    pause();
                    std::cout << "Fortunately, the path ahead is easy, and your irritation speeds your pace.\n\n";
                    pause();
                    std::cout << "You're able to cover a good distance before stopping for a rest.\n\n";
                    pause();
                    stats.increaseMilesJourneyed(12, backpack);
                }
            }
        break;   
        }
        /////////////////////////////////////////////////////////////////////////////////////////////

        /////////////////////////////////////////////////////////////////////////////////////////////
        case 7: //Tier 3, explore cave
        {
            
        }
            
    }
}

