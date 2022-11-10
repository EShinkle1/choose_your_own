#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <backpack.hpp>
#include <stats.hpp>
#include <helpers.hpp>

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

            while (true) {
                std::cout << "Please enter Y or N: ";
                std::string response;
                std::cin >> response;
                std::cin.ignore(100,'\n');
                if (response == "Y"){
                    middle_dashes();
                    std::cout << "\nYou exit the caves.\n\n";
                    pause();
                    return false;
                } 
                if (response == "N"){
                    middle_dashes();
                    std::cout << "You turn back around.\n\n";
                    pause();
                    current_position[1] = 1;
                    current_position[2] = 0;
                    return true;
                }
                std::cout << "Invalid input.\n";
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
bool seen_cave_mushrooms = false;
bool seen_bugs = false;
bool seen_grassy_area = false;
bool seen_fishing_spot = false;
bool seen_shiny_rocks = false;
bool seen_growling_animal = false;

void position_happenings(std::vector<int> current_position) {
    //Interesting locations
    if ((current_position[0] == 2 && current_position[1] == 4 && current_position[2] == 3) ||
        (current_position[0] == 3 && current_position[1] == 4 && current_position[2] == 1)) {
        if (!seen_shiny_rocks) {
            std::cout << "You see the shiny rocks for the first time!\n\n";
            seen_shiny_rocks = true;
        }
        else {
            std::cout << "You see the shiny_rocks again.\n\n";
        }
    }
    else if (current_position[0] == 1 && current_position[1] == 3) {
        if (!seen_cave_mushrooms) {
            std::cout << "You see the cave mushrooms for the first time!\n\n";
            seen_cave_mushrooms = true;
        }
        else {
            std::cout << "You return to the cave with mushrooms.\n\n";
        }
    }
    else if (current_position[0] == 2 && current_position[1] == 7) {
        if (!seen_growling_animal) {
            std::cout << "You hear a growling animal ahead.\n\n";
            seen_growling_animal = true;
        }
        else {
            std::cout << "The growling animal is still there.\n\n";
        }
    }
    else if (current_position[0] == 6 && current_position[1] == 5) {
        if (!seen_fishing_spot) {
            std::cout << "You see the fishing spot for the first time!\n\n";
            seen_fishing_spot = true;
        }
        else {
            std::cout << "You return to the fishing spot.\n\n";
        }
    }
    else if (current_position[0] == 9 && current_position[1] == 4) {
        if (!seen_grassy_area) {
            std::cout << "You enter a grassy area!\n\n";
            seen_grassy_area = true;
        }
        else {
            std::cout << "You return to grassy area.\n\n";
        }
    }
    else if (current_position[0] == 7 && current_position[1] == 1) {
        if (!seen_bugs) {
            std::cout << "You see a swarm of bugs ahead!\n\n";
            seen_bugs = true;
        }
        else {
            std::cout << "The swarm of bugs is still there.\n\n";
        }
    }
    else if (current_position[0] == 4 && current_position[1] == 7) {
        if (!seen_skeleton) {
            std::cout << "You see skeleton with a backpack!\n\n";
            seen_skeleton = true;
        }
        else {
            std::cout << "The skeleton is still there.\n\n";
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
    pause();
}

void intro_text() {
    std::cout << "You set out again. The sun is very bright and the trees provide little protection.\n\n";
    pause();
    std::cout << "Ahead to the right, the tree cover appears to thicken, so you head in that direction, hoping for a bit of relief.\n\n";
    pause();
    std::cout << "Although still sparse, the shade feel nice. You wipe a bit of sweat from your forehead.\n\n";
    pause();
    std::cout << "Unfortunately, the shade is short lived, as bushier trees soon give way to nearly bare ones again.\n\n";
    pause();
    std::cout << "Up ahead, on the right, a steep cliff towers over you. You see an opening in the rocks and peer in. This seems to be a cave of sorts. Desperate for relief from the sun, you step in.\n\n";
    pause();
    std::cout << "You're surprised to discover, it is not merely a cave but a tunnel. You light a candle you brought with you and begin to explore.\n\n";
    pause();
    std::cout << "Before long, you reach a point where the tunnel splits into multiple paths.\n\n";
    pause();
}

void event7(Backpack &backpack, Stats &stats, std::string time_of_day) {

    //To-do:
    //* Expand mini-events
    //* Make a leaving mechanic -- are you sure you want to exit?
    //* Maybe add descriptions to some of the passageways? Perhaps hints to what is ahead?
    //* Event ending

    //0 = North, 1 = East, 2 = South, 3 = West
    // turn around = +2, right = +1, forward = 0, left = -1

    //position: (int x-coord, int y-coord, int orientation)

    intro_text();

    std::vector<int> current_position = {4, 1, 0};

    bool cont = true;

    for (int i = 0; i < 20; i++) {
        
        cont = get_new_position(current_position);
        if (!cont) { break; }
        position_happenings(current_position);

    }


}