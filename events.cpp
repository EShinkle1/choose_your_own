#include "events.hpp"
#include "stats.hpp"
#include "helpers.hpp"
#include "backpack.hpp"
#include <iostream>
#include <algorithm>
#include <random>

std::vector<int> * Events::choose_tier(Stats stats) {
    int score = rand() % 200 + stats.getLuck();
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

void Events::get_event(Stats &stats, Backpack &backpack) {
    std::vector<int>& tier = *choose_tier(stats);

    int size = tier.size();

    if (size == 0) {
        std::cout << "You proceed with your journey. You walk forward, left foot, right foot, left foot, right foot. Your eyelids feel heavy. You press ahead.\n\n";
        pause();
        std::cout << "You eventually stop and realize you've been walking for quite some time. You remember little from the walk and have no idea how much progress you've made. Maybe it's time for a break.\n\n";
        stats.increaseMilesJournied(5 + (rand() % 10), backpack);
        pause();
        return;
    }

    int idx = rand() % size;
    int event = tier[idx];
    //int event = 4;

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
                stats.increaseMilesJournied(12, backpack);
            } else {
                std::cout << "There is no time to waste. You keep moving. The terrain ahead is very easy. You cover a good distance. Finally after many hours of walking, you decide it's time for a break. \n\n";
                stats.increaseMilesJournied(15, backpack);
            }

            pause();
            break;
        }
        /////////////////////////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////////////////////////
        case 1: //Tier 3, dried fruit and nuts available off-course for a price
        {
            //Intro
            std::cout << "You continue on your trek. The forest ahead is especially dense. Fortunately, you spot a narrow path. It looks as though it is treaded on frequently. You pause to look around, but don't see anything except tree after tree.\n\n";

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
                std::cout << "You continue forward. The woods start to thin, and you are able to move more quickly. You walk for several hours, enjoying the sounds of birds chirping and the beams of sunlight peaking through the forest canopy. As you stop to take a rest, you are reminded of the footpath you travelled along earlier. It's probably good that you didn't follow it any further -- who knows how long you could have been stuck following it.\n\n";
                stats.increaseHealth(10);
                stats.increaseMilesJournied(10, backpack);
            } else {
                std::cout << "You continue to follow the footpath, curious as to where it may lead. You follow it for some time before it veers to the right again.\n\n";
                pause();
                std::cout << "You continue to follow the path. It curves back to the left.\n\n";
                pause();
                std::cout << "You follow along for some time longer until a small structure comes into view. As you near the structure, the footpath ends. You approach the makeshift shelter cautiously. It appears to be constructed from three rotting logs and a large dirtied piece of cloth, draped to form a roof. Inside you see a worn leather bag. You open the bag to find a mixture of dried fruit and nuts.\n\n";

                //A subchoice
                std::vector<std::string> choices = {"Add the sack of food to your backpack.", "Leave the sack where it is."};

                std::cout << "You have a choice to make.\n\n";
                for (int i = 0; i < choices.size(); i++) {
                    std::cout << "  " << int_to_letter(i) << ". " << choices[i] << "\n";
                }
                std::cout << "\n";

                int response = letter_to_int(input_checker_char(2));

                if (response == 1) {
                    std::cout << "You set down the sack of food and look around. There is dense forest in every direction. You head west once again, brushing branches and foliage out of your way as you go along. Eventually, the trees start to thin. This seems like a good place to rest.\n\n";
                    stats.increaseMilesJournied(5, backpack);
                } else {
                    std::cout << "You grab the sack and step back from the structure. The forest is still. As you begin heading west again, a cold breeze whisks leaves off the trees around you. You shiver and clutch your pack a bit tighter as you continue through the woods. Eventually, the trees start to thin. This seems like a good place to rest.\n\n";
                    backpack.increase_item_count("Food (1 day)", 2);
                    stats.increaseMilesJournied(5, backpack);
                    stats.increaseLuck(-20);
                }
            }

            pause();
            break;
        }
        //////////////////////////////////////////////////////////////////////////////////////

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
                std::cout << "You walk a bit further, but your stomach continues to tighten. Eventually you give up and sit down. You place your head in your hands and sit for a while. Eventually, you feel well enough to continue, but your sense of balance has yet to be restored...\n\n";
                pause();
                std::cout << "After a while, you pause to take a break.\n\n";
                pause();
                stats.increaseHealth(-5);
                stats.increaseMilesJournied(5, backpack);
            } else {
                std::cout << "There is no time to waste. You keep moving. The terrain is very easy. You cover a good distance. Finally after many hours of walking, you decide it's time for a break. \n\n";
                stats.increaseMilesJournied(15, backpack);
                pause();
            }
            break;
        }
        /////////////////////////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////////////////////////
        case 3: //Tier 1, fall into muddy stream
        {
            std::cout << "The air is crisp. You walk along at a moderate pace, occasionally stopping to glance at the colorful bugs crawling in and out of the crevaces in the bark of the trees.\n\n";
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

            if (backpack.count_of_item("Change of clothes") > 0) {
                std::cout << "You remember that you have extra clothes in your backpack.\n\n";
                std::cout << "Use change of clothes?\n\n";
                std::cout << "  A. Yes\n";
                std::cout << "  B. No\n\n";
                int choice = letter_to_int(input_checker_char(2));

                if (choice == 0) {
                    backpack.increase_item_count("Change of clothes", -1);
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
            stats.increaseMilesJournied(8, backpack);
            break;
        }
        /////////////////////////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////////////////////////
        case 4: //Tier 2, steep climb or long journey around hill
        {
            std::cout << "As you walk along, you hear the characteristic croak of a frog. You pause for a moment and look around before returning on your way. In a forest like this, there are critters everywhere. You wonder what sorts of creatures you have passed unknowingly already during your journey.\n\n" ;
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
                int climbing_ability = stats.getLuck() + stats.getHealth();
                std::cout << "You decide to press forward. ";
                if (backpack.count_of_item("Walking Stick") > 0) {
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
                    stats.increaseMilesJournied(4, backpack);
                    stats.increaseHealth(-10);
                }
                else {
                    std::cout << "You reach the top and stop for a moment to look down. You are lucky that you made it to the top at all.\n\n";
                    pause();
                    std::cout << "Your eyes turn back forwards to a flat stretch ahead. You're able to get in a few more hours of walking before you stop for a break.\n\n";
                    pause();
                    stats.increaseMilesJournied(8, backpack);
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

                if (backpack.count_of_item("Change of clothes") > 0) {
                    std::cout << "You remember that you have extra clothes in your backpack.\n\n";
                    std::cout << "Use change of clothes?\n\n";
                    std::cout << "  A. Yes\n";
                    std::cout << "  B. No\n\n";
                    int choice = letter_to_int(input_checker_char(2));

                    if (choice == 0) {
                        backpack.increase_item_count("Change of clothes", -1);
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
                stats.increaseMilesJournied(4, backpack);
            }
            break;
        }


            
    }
}

