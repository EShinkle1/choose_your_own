#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <backpack.hpp>
#include <stats.hpp>
#include <helpers.hpp>
#include <algorithm>

//Tier 3, explore cave

void make_turn(std::vector<int> &current_position, int turn) {
    current_position[2] += turn;
    current_position[2] %= 4; 
    return;
}

int get_turn(std::string input) {
    if (input == "F") {
        return 0;
    }
    if (input == "R") {
        return 1;
    }
    if (input == "B") {
        return 2;
    }
    if (input == "L") {
        return 3;
    }
    return -1;
}

std::vector<std::string> options_text = {"  F. Continue forward\n", "  R. Turn right\n", "  B. Turn around\n", "  L. Turn left\n"};

void print_options(std::vector<int> current_position, std::set<int> possible_directions) {
    std::cout << "You have the following options:\n\n";
    std::set<int> relative_options = {};
    for (int i: possible_directions) {
        relative_options.insert((i - current_position[2] + 4) % 4);
    }
    for (int i: relative_options) {
        std::cout << options_text[i];
    }
    std::cout << "\n";
}

int get_step_direction(std::vector<int> current_position) {
    //0 = North, 1 = East, 2 = South, 3 = West
    std::set<int> possible_directions;

    if (current_position[0] == 1 && current_position[1] == 3) {
        possible_directions = {1};
    }
    else if (current_position[0] == 1 && current_position[1] == 4) {
        possible_directions = {1};
    }
    else if (current_position[0] == 2 && current_position[1] == 3) {
        possible_directions = {0, 1, 3};
    }
    else if (current_position[0] == 2 && current_position[1] == 4) {
        possible_directions = {1, 2, 3};
    }
    else if (current_position[0] == 2 && current_position[1] == 6) {
        possible_directions = {0, 1};
    }
    else if (current_position[0] == 2 && current_position[1] == 7) {
        possible_directions = {2};
    }
    else if (current_position[0] == 3 && current_position[1] == 1) {
        possible_directions = {0, 1};
    }
    else if (current_position[0] == 3 && current_position[1] == 2) {
        possible_directions = {0, 2};
    }
    else if (current_position[0] == 3 && current_position[1] == 3) {
        possible_directions = {2, 3};
    }
    else if (current_position[0] == 3 && current_position[1] == 4) {
        possible_directions = {0, 1, 3};
    }
    else if (current_position[0] == 3 && current_position[1] == 5) {
        possible_directions = {0, 2};
    }
    else if (current_position[0] == 3 && current_position[1] == 6) {
        possible_directions = {1, 2, 3};
    }
    else if (current_position[0] == 4 && current_position[1] == 0) {
        possible_directions = {0, 2};
    }
    else if (current_position[0] == 4 && current_position[1] == 1) {
        possible_directions = {0, 1, 2, 3};
    }
    else if (current_position[0] == 4 && current_position[1] == 2) {
        possible_directions = {0, 2};
    }
    else if (current_position[0] == 4 && current_position[1] == 3) {
        possible_directions = {0, 1, 2};
    }
    else if (current_position[0] == 4 && current_position[1] == 4) {
        possible_directions = {0, 2, 3};
    }
    else if (current_position[0] == 4 && current_position[1] == 5) {
        possible_directions = {0, 1, 2};
    }
    else if (current_position[0] == 4 && current_position[1] == 6) {
        possible_directions = {0, 2, 3};
    } 
    else if (current_position[0] == 4 && current_position[1] == 7) {
        possible_directions = {2};
    } 
    else if (current_position[0] == 5 && current_position[1] == 1) {
        possible_directions = {0, 1, 3};
    }
    else if (current_position[0] == 5 && current_position[1] == 2) {
        possible_directions = {1, 2};
    }
    else if (current_position[0] == 5 && current_position[1] == 3) {
        possible_directions = {3};
    }
    else if (current_position[0] == 5 && current_position[1] == 5) {
        possible_directions = {1, 3};
    } 
    else if (current_position[0] == 6 && current_position[1] == 1) {
        possible_directions = {0, 1, 3};
    } 
    else if (current_position[0] == 6 && current_position[1] == 2) {
        possible_directions = {1, 2, 3};
    } 
    else if (current_position[0] == 6 && current_position[1] == 5) {
        possible_directions = {3};
    } 
    else if (current_position[0] == 7 && current_position[1] == 1) {
        possible_directions = {3};
    } 
    else if (current_position[0] == 7 && current_position[1] == 2) {
        possible_directions = {0, 1, 3};
    } 
    else if (current_position[0] == 7 && current_position[1] == 3) {
        possible_directions = {0, 2};
    } 
    else if (current_position[0] == 7 && current_position[1] == 4) {
        possible_directions = {1, 2};
    } 
    else if (current_position[0] == 8 && current_position[1] == 2) {
        possible_directions = {3};
    } 
    else if (current_position[0] == 8 && current_position[1] == 4) {
        possible_directions = {0, 1, 3};
    } 
    else if (current_position[0] == 8 && current_position[1] == 5) {
        possible_directions = {2};
    } 
    else if (current_position[0] == 9 && current_position[1] == 4) {
        possible_directions = {3};
    } 
    
    else {
        std::cout << "WARNING: Not a valid position.\n\n";
        std::cout << "Attempted position (" << current_position[0] << ", " << current_position[1] << ", " << current_position[2] << ")\n\n";
    }

    print_options(current_position, possible_directions);

    bool accepted = false;
    std::string input;
    int turn;

    while (!accepted) {
        std::cout << "Enter your choice: ";
        std::cin >> input;
        std::cin.ignore(100,'\n');
        int proposed_turn = get_turn(input);
        if (proposed_turn == -1) {
            std::cout << "Invalid input. Try again.\n";
            continue;
        }
        for (int j: possible_directions) {
            if (j == (proposed_turn + current_position[2]) % 4) {
                turn = proposed_turn;
                accepted = true;
            }
        }
        if (!accepted) {
            std::cout << "Invalid input. Try again.\n";
        }
    }
    std::cout << "\n";
    middle_dashes();
    // turn around = +2, right = +1, forward = 0, left = -1
    if (turn == 0) {std::cout << "You continue forward. ";}
    else if (turn == 1) {std::cout << "You turn to the right. ";}
    else if (turn == 2) {std::cout << "You turn around and head back. ";}
    else {std::cout << "You turn to the left. ";} 

    return turn;
}

bool get_new_position(std::vector<int> &current_position) {
    int turn = get_step_direction(current_position);

    make_turn(current_position, turn);

    if (current_position[2] == 0) {
        current_position[1] += 1;
    }
    else if (current_position[2] == 1) {
        current_position[0] += 1;
    }
    else if (current_position[2] == 2) {
        current_position[1] -= 1;
        
        if (current_position[1] == -1) {
            std::cout << "This is the exit of the tunnel system. Do you wish to exit?\n\n";

            std::string response = yes_or_no();
            if (response == "Y") {
                std::cout << "You exit the caves.\n\n";
                pause0();
                return false;
            } 
            else {
                std::cout << "You turn back around.\n\n";
                pause0();
                current_position[1] = 1;
                current_position[2] = 0;
                return true;
            }
        }
    }
    else if (current_position[2] == 3) {
        current_position[0] -= 1;
    }

    
    //std::cout << "Current position: (" << current_position[0] << ", " << current_position[1] << ")\n\n";
    return true;
}

bool seen_skeleton = false;
bool looked_at_skeletons_bag = false;
bool taken_skeletons_sword = false;
bool seen_cave_mushrooms = false;
bool taken_cave_mushrooms = false;
bool seen_bugs = false;
bool seen_gold_trinket = false;
bool taken_gold_trinket = false;
bool seen_fishing_spot = false;
int fishing_counter = 0;
bool seen_shiny_rocks = false;
bool seen_growling_animal = false;
bool fought_growling_animal = false;

void fight_animal(Stats &stats, Backpack &backpack, std::vector<int> &current_position) {
    int animal_health = 5;
    std::cout << "You rip the sword from you pack and lunge forward toward the animal!\n\n";
    pause0();
    std::cout << "It moves to the right and swipes your arm as you thrust it forward.\n\n";
    pause0();
    stats.increaseHealth(-10);
    stats.check_for_death();
    std::cout << "Would you like to (A) use the same approach again, (B) try to be sneakier, or (C) flee?\n\n";
    char response = input_checker_char(3);
    if (response == 'C') {
        std::cout << "You turn around and run as quickly as you can. After a bit you stop to catch your breath. The animal does not seem to have followed you.\n\n";
        make_turn(current_position, 2);
        pause0();
        std::cout << "You are now facing the opposite direction.\n\n";
    } else {
        if (response == 'A') {
            std::cout << "You jut your sword at the creature again.\n\n";
            pause0();
            std::cout << "This time you hit it in the stomach.\n\n";
            pause0();
            std::cout << "The creature is about the size of a small bear, though leathery like an armadillo.\n\n";
            pause0();
            std::cout << "It stumbles back and lets out a soft cry.\n\n";
            pause0();
            animal_health -= 2;
        } else {
            std::cout << "You step back softly and creep to the left.\n\n";
            pause0();
            std::cout << "You wait until the creature is looking away.\n\n";
            pause0();
            std::cout << "Unfortunately, the creature does not look away, but instead rushes toward you.\n\n";
            pause0();
            std::cout << "You hustle away but smash your foot into a protruding rock in the process.\n\n";
            pause0();
            stats.increaseHealth(-10);
            stats.check_for_death();
        }
        std::string damage[3] = {"no", "a bit of", "some"};
        while (true) {
            std::cout << "Would you like to (A) attack again or (B) flee?\n\n";
            char response = input_checker_char(2);
            if (response == 'B') {
                std::cout << "You turn around and run as quickly as you can. After a bit you stop to catch your breath. The animal does not seem to have followed you.\n\n";
                make_turn(current_position, 2);
                pause0();
                std::cout << "You are now facing the opposite direction.\n\n";
                break;
            }
            std::cout << "You swing at the creature again.\n\n";
            pause0();
            int idx = std::max(std::min(stats.getLuck(backpack) + (rand() % 200), 199) * 3 / 200.0, 0.0);
            std::cout << "You do " << damage[idx] << " damage.\n\n";
            animal_health -= idx;
            pause0();
            
            if (animal_health <= 0) {
                std::cout << "The strange animal stumbles back and falls to the ground.\n\n";
                pause0();
                std::cout << "You cautiously approach. It does not appear to be breathing.\n\n";
                pause0();
                std::cout << "Just to be safe, you stab it a few more times.\n\n";
                pause0();
                std::cout << "You skin the creature. You can use this as a blanket. You add it to your sack.\n\n";
                backpack.increase_item_quantity("Blanket", 1);
                pause0();
                std::cout << "There is meat you can eat. You wrap it and add it to your sack to cook once you exit the cave.\n\n";
                backpack.increase_item_quantity("Food (1 day)", 2);
                pause0();
                std::cout << "Finally, you gut the skull and add it to your sack. A trophy!\n\n";
                backpack.increase_item_quantity("Cave creature's skull", 1);
                pause0();
                std::cout << "Your backpack weight is " << backpack.weight_status() << ".\n\n";
                pause0();
                std::cout << "You feel invigorated. You are ready to continue exploring the tunnels.\n\n";
                stats.increaseHealth(10);
                pause0();
                std::cout << "There is nothing ahead except some bones, presumably of the creature's past prey, near the passage's end.\n\n";
                break;
            }

            std::cout << "The creature attacks back.\n\n";
            pause0();
            int idx2 = std::max(std::min((200 - stats.getLuck(backpack)) + (rand() % 200), 199) * 3 / 200.0, 0.0);
            std::cout << "It does " << damage[idx2] << " damage.\n\n";
            pause0();
            stats.increaseHealth(idx2 * -5);
            stats.check_for_death();
        }
    }
}


void position_happenings(std::vector<int> &current_position, Backpack &backpack, Stats &stats) {
    //Interesting locations
    if ((current_position[0] == 2 && current_position[1] == 4 && current_position[2] == 3) ||
        (current_position[0] == 3 && current_position[1] == 4 && current_position[2] == 1)) {
        if (!seen_shiny_rocks) {
            seen_shiny_rocks = true;
            std::cout << "Something ahead captures your gaze. The light reflected from it seems brighter than the light from your candle.\n\n";
            pause0();
            std::cout << "As you walk a bit closer, everything else seems to fall out of focus.\n\n";
            pause0();
            std::cout << "The object of your gaze is a shimmering silver rock, sharply contrasted to the dull brown slab of rock into which it is firmly embedded.\n\n";
            pause0();
            std::cout << "You gently touch the glittery rock. It feels almost soft, like how you imagine it would feel to touch a cloud.\n\n";
            pause0();
            std::cout << "A shiver runs through your body. Odd...\n\n";
            stats.increaseLuck(10);
            
        }
        else {
            std::cout << "You again pass by the sparkling metallic rock you discovered earlier.\n\n";
            pause0();
            std::cout << "It captures your focus for a few moments until you are able to shake yourself loose.\n\n";
            stats.increaseLuck(1);
        }
    }
    else if (current_position[0] == 1 && current_position[1] == 3) {
        if (!seen_cave_mushrooms) {
            seen_cave_mushrooms = true;
            std::cout << "The tunnel ends up ahead. It appears there is something on the ground.\n\n";
            pause0();
            std::cout << "You walk closer to take a look. You see a patch of large, brown mushrooms.\n\n";
            pause0();
            std::cout << "Would you gather some to add to your backpack as food?\n\n";
            std::string response = yes_or_no();
            if (response == "Y") {
                std::cout << "You collect the best looking mushrooms and add them to your backpack.\n\n";
                backpack.increase_item_quantity("Food (1 day)", 2);
                std::cout << "The weight of your backpack is " << backpack.weight_status() << "\n\n";
                taken_cave_mushrooms = true;
            } else {
                std::cout << "You leave the mushrooms as they are.\n\n";
            }
            
        }
        else {
            std::cout << "You return to the place you found mushrooms earlier.\n\n";
            if (!taken_cave_mushrooms) {
                std::cout << "Would you gather some to add to your backpack as food?\n\n";
                std::string response = yes_or_no();
                if (response == "Y") {
                    std::cout << "You collect the best looking mushrooms and add them to your backpack.\n\n";
                    backpack.increase_item_quantity("Food (1 day)", 2);
                    std::cout << "The weight of your backpack is " << backpack.weight_status() << ".\n\n";
                    taken_cave_mushrooms = true;
                }
                else {
                    std::cout << "You leave the mushrooms as they are.\n\n";
                }
            }
        }
    }
    else if (current_position[0] == 2 && current_position[1] == 7) {
        if (!seen_growling_animal) {
            seen_growling_animal = true;
            std::cout << "You freeze, thinking you saw something move up ahead. Surely it's just the exhaustion getting to you, right?.\n\n";
            pause0();
            std::cout << "An encounter in a dark cave is something you'd rather avoid. You move only your eyes, searching for another indication of movement.\n\n";
            pause0();
            std::cout << "You hear a low growl. You feel the muscles in your shoulders and chest tighten. It sounds to be coming from a creature of substantial size.\n\n";
            pause0();

            if (backpack.item_present("Skeleton's sword")) {
                std::cout << "You do have the sword you retrieved from the skeleton. Do you want to attempt to fight the creature?\n\n";
                std::string response = yes_or_no();
                if (response == "Y") {
                    fight_animal(stats, backpack, current_position);
                } else {
                    std::cout << "You back away as cautiously and quietly as you are able.\n\n";
                }
            } else {
                std::cout << "You back away as cautiously and quietly as you are able.\n\n";
            }
        }
        else {
            std::cout << "This is where you found the growling animal earlier.\n\n";
            if (backpack.item_present("Skeleton's sword") && !fought_growling_animal) {

            }
        }
    }
    else if (current_position[0] == 6 && current_position[1] == 5) {
        if (!seen_fishing_spot) {
            seen_fishing_spot = true;
            std::cout << "You hear something ahead. It sounds like water, perhaps?\n\n";
            pause0();
            std::cout << "As you walk closer, you see a robust stream of water bursting out from between rocks in the cave wall and descending into a deep pond. It is unclear to you where the water exits, but the water level does not seem to be increasing.\n\n";
            pause0();
            std::cout << "There are fish in the water. They are about the size of your palm and of a yellow-orange color. You also notice a spear laid carefully to the side. It seems perhaps someone uses this spear for fishing.\n\n";
            pause0();
            std::cout << "Would you like to fish?\n\n";
            std::string response = yes_or_no();
            if (response == "Y") {
                fishing_counter++;
                std::cout << "It takes you a bit to get the hang of fishing with the spear, but you're able to catch two fish. You make a small fire and prepare the fish. Mmm...\n\n";
                stats.increaseFullness(25);
            } else {
                std::cout << "You decide it's better to keep exploring.\n\n";
            }
        }
        else {
            std::cout << "You are back at the fishing spot. Would you like to fish?\n\n";
            std::string response = yes_or_no();
            if (response == "Y") {
                fishing_counter++;
                if (fishing_counter == 1) {
                    std::cout << "It takes you a bit to get the hang of fishing with the spear, but you're able to catch two fish. You make a small fire and prepare the fish. Mmm...\n\n";
                    stats.increaseFullness(20);
                } else if (fishing_counter == 2) {
                    std::cout << "There are more visible fish, so you decide to catch some more. After a bit of work, you've caught three fish! You pause0 to enjoy your catch.\n\n";
                    stats.increaseFullness(30);
                } else {
                    std::cout << "You try for a bit, but have no success. If there are fish further down in the pond, they are evading your spear. Perhaps it is best to move on.\n\n";
                }
            } else {
                std::cout << "You decide it's better to keep exploring.\n\n";
            }
        }
    }
    else if (current_position[0] == 9 && current_position[1] == 4) {
        if (!seen_gold_trinket) {
            seen_gold_trinket = true;
            std::cout << "This appears to be a dead-end.\n\n";
            pause0();
            std::cout << "Wait! Something shiny catches your eye.\n\n";
            pause0();
            std::cout << "You crouch down, and brush your hand across the dusty ground. You pull a small figure from the ground.\n\n";
            pause0();
            std::cout << "You cannot tell what it is supposed to be, if anything at all. You blow some dirt of the figure. It is a dull gold color.\n\n";
            pause0();
            std::cout << "Would you like to add the trinket to your backpack?\n\n";
            std::string response = yes_or_no();
            if (response == "Y") {
                backpack.increase_item_quantity("Strange gold trinket", 1); 
                std::cout << "You add the item to your sack.\n\n"; 
                taken_gold_trinket = true;          
            } else {
                std::cout << "You place the figure back where you found it.\n\n";
            }     
        }
        else {
            std::cout << "This appears to be a dead-end.\n\n";
            if (!taken_gold_trinket) {
                pause0();
                std::cout << "This is where you found the strange gold trinket before, but it is nowhere to be seen now.\n\n";
            }
        }
    }
    else if (current_position[0] == 7 && current_position[1] == 1) {
        if (!seen_bugs) {
            seen_bugs = true;
            std::cout << "As you continue forward, your ears begin to detect an unnerving buzzing sound. You don't have a good feeling about this.\n\n";
            pause0();
            std::cout << "You continue towards the noise, uneasy about what you might find ahead. The noise grows louder.\n\n";
            pause0();
            std::cout << "Up ahead, you see several pale pink masses, each about the size of your thumb, attached to the ceiling of the tunnel.\n\n";
            pause0();
            std::cout << "They seem to be larvae, you realize, just as your eyes widen as you spot hundreds more attached to the ceiling and walls of the cave up ahead. You freeze.\n\n";
            pause0();
            std::cout << "The buzzing sound seems to be coming from the other side. You'd rather not find out what these larvae look like in their mature form.\n\n";
        }
        else {
            std::cout << "You hear a familiar buzzing. You are no more eager to see the larvae and those that spawned them any more than you were earlier.\n\n";
        }
    }
    else if (current_position[0] == 4 && current_position[1] == 7) {
        if (!seen_skeleton) {
            seen_skeleton = true;
            std::cout << "The light from your candle illuminates a face in front of you!\n\n";
            pause0();
            std::cout << "It is a human skeleton, you believe. Its right leg appears to have been broken.\n\n";
            pause0();
            std::cout << "You notice a sack by its side. Is it disrespectful to the dead to take a look at the sack?\n\n";
            pause0();
            std::cout << "Would you like to inspect the bag?\n\n";
            std::string response = yes_or_no();
            if (response == "Y") {
                looked_at_skeletons_bag = true;
                stats.increaseLuck(-5);
                std::cout << "You walk closer. The sack is decaying and appears to have been snacked upon by some collection of bugs. There is nothing inside.\n\n";
                pause0();
                std::cout << "Behind the skeleton you notice a sword. It is dirtied and appears to be rusting a bit.\n\n";
                pause0();
                std::cout << "Would you like to take the sword?\n\n";
                std::string response = yes_or_no();
                if (response == "Y") {
                    backpack.increase_item_quantity("Skeleton's sword", 1);
                    taken_skeletons_sword = true;
                    std::cout << "You lift the sword. It feels study but manueverable. You use your shirt to try to brush off a bit of the dirt. Your success is limited.\n\n";
                } else {
                    std::cout << "You leave the sword where it is.\n\n";
                }
            } else {
                std::cout << "You'd rather let the skeleton lie in peace. You back away.\n\n";
            }
            pause0();
            std::cout << "This appears to be a dead-end.\n\n";
        }
        else {
            std::cout << "You see the skeleton again.";
            if (!looked_at_skeletons_bag) {
                std::cout << " The bag is still there.";
            }
            std::cout << "\n\n";
            pause0();
            if (!looked_at_skeletons_bag) {
                std::cout << "Would you like to inspect the bag?\n\n";
                std::string response = yes_or_no();
                if (response == "Y") {
                    looked_at_skeletons_bag = true;
                    stats.increaseLuck(-5);
                    std::cout << "You walk closer. The sack is decaying and appears to have been snacked upon by some collection of bugs. There is nothing inside.\n\n";
                    pause0();
                    std::cout << "Behind the skeleton you notice a sword. It is dirtied and appears to be rusting a bit.\n\n";
                    pause0();
                    std::cout << "Would you like to take the sword?\n\n";
                    std::string response = yes_or_no();
                    if (response == "Y") {
                        backpack.increase_item_quantity("Skeleton's sword", 1);
                        taken_skeletons_sword = true;
                        std::cout << "You lift the sword. It feels study but manueverable. You use your shirt to try to brush off a bit of the dirt. You success is limited.\n\n";
                    } else {
                        std::cout << "You leave the sword where it is.\n\n";
                    }
                } else {
                    std::cout << "Your mind has not changed.\n\n";
                }  
            } else if (!taken_skeletons_sword) {
                std::cout << "The sword still lays where you saw it. Would you like to take it now?\n\n";
                std::string response = yes_or_no();
                if (response == "Y") {
                    backpack.increase_item_quantity("Skeleton's sword", 1);
                    taken_skeletons_sword = true;
                    std::cout << "You lift the sword. It feels study but manueverable. You use your shirt to try to brush off a bit of the dirt. You success is limited.\n\n";
                } else {
                    std::cout << "You leave the sword where it is.\n\n";
                }
            } else {
                std::cout << "There is not much else to do here.\n\n";
            }
        }
    }

    //Extra long passages
    else if (current_position[0] == 3 && current_position[1] == 2) {
        std::cout << "This tunnels seems to never end!\n\n";
    }
    else if (current_position[0] == 4 && current_position[1] == 2) {
        std::cout << "The tunnel continues as far as you can see.\n\n";
    }
    else if (current_position[0] == 5 && current_position[1] == 5) {
        std::cout << "You have been walking for quite a while.\n\n";
    }
    else if (current_position[0] == 3 && current_position[1] == 5) {
        std::cout << "You have been walking for quite a while.\n\n";
    }

    //Dead-ends
    else if ((current_position[0] == 5 && current_position[1] == 3) ||
                (current_position[0] == 8 && current_position[1] == 5) ||
                (current_position[0] == 8 && current_position[1] == 2) ||
                (current_position[0] == 1 && current_position[1] == 4)) {
        std::cout << "This appears to be a dead-end.\n\n";
    }

    //If nothing else happens
    else {
        std::cout << "You walk until you reach a junction.\n\n";
    }
    pause0();
}

void intro_text() {
    std::cout << "You set out again. The sun is very bright and the trees provide little protection.\n\n";
    pause0();
    std::cout << "Ahead to the right, the tree cover appears to thicken, so you head in that direction, hoping for a bit of relief.\n\n";
    pause0();
    std::cout << "Although still sparse, the shade feel nice. You wipe a bit of sweat from your forehead.\n\n";
    pause0();
    std::cout << "Unfortunately, the shade is short lived, as bushier trees soon give way to nearly bare ones again.\n\n";
    pause0();
    std::cout << "Up ahead, on the right, a steep cliff towers over you. You see an opening in the rocks and peer in. This seems to be a cave of sorts. Desperate for relief from the sun, you step in.\n\n";
    pause0();
    std::cout << "You're surprised to discover it is not merely a cave but a tunnel. You light a candle you brought with you and begin to explore.\n\n";
    pause0();
    std::cout << "Before long, you reach a point where the tunnel splits into multiple paths.\n\n";
    pause0();
}

void out_of_moves() {
    std::cout << "You realize you've been in the cave for quite some time. It would be best to get moving again.\n\n";
    pause0();
    std::cout << "You make your way back to the entrance and step outside.\n\n";
    pause0();
}

void event7(Backpack &backpack, Stats &stats, std::string time_of_day) {

    //To-do:
    //* Maybe add descriptions to some of the passageways? Perhaps hints to what is ahead?

    //0 = North, 1 = East, 2 = South, 3 = West
    // turn around = +2, right = +1, forward = 0, left = -1

    //position: (int x-coord, int y-coord, int orientation)

    intro_text();

    std::vector<int> current_position = {4, 1, 0};

    bool cont = true;

    int i = 0;

    while (i < 20) {
        
        cont = get_new_position(current_position);
        if (!cont) { break; }
        position_happenings(current_position, backpack, stats);
        if (i == 19) {
            out_of_moves();
        }
        i++;
    }

    std::cout << "It's not quite as sunny as earlier. You set off, hoping to cover a bit of distance before ";
    if (time_of_day == "morning") {
        std::cout << "stopping for lunch.\n\n";
    } else {
        std::cout << "the sun sets.\n\n";
    }
    pause0();

    stats.increaseMilesJourneyed(5 + 0.5*(20 - i), backpack);

    return;

}