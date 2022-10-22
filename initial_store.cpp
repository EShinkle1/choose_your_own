#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "initial_store.hpp"
#include "helpers.hpp"

void InitialStore::print_inventory_options() {
        std::cout << "\nChoose equipment for your journey.\n\n";
        std::cout << "   Item                             Weight       Quantity Available\n";
        std::cout << "   ----------------------------------------------------------------\n";
        std::cout << "A. Food (1 day)                     2 lbs        unlimited\n";
        std::cout << "B. Makeshift tent                   6 lbs        " << counts[0] << "\n";
        std::cout << "C. First aid kit                    0.5 lbs      " << counts[1] << "\n";
        std::cout << "D. Change of clothes                2 lbs        " << counts[2] << "\n";
        std::cout << "E. Blanket                          3 lbs        " << counts[3] << "\n";
        std::cout << "F. Questionable healing potion      1 lbs        " << counts[4] << "\n";
        std::cout << "G. Good luck rock                   3 lbs        " << counts[5] << "\n";
        std::cout << "H. Walking stick                    3 lbs        " << counts[6] << "\n\n";
        std::cout << "I. Finished packing\n";
        std::cout << "J. Restart\n";
}

bool InitialStore::take_item(char choice) {
    bool success = false;
    int i = letter_to_int(choice);
    if (i == 0) {
        success = true;
    } else {
        if (counts[i-1] < 1) {
            std::cout << "No more available.\n";
        } else {
            counts[i-1] -= 1;
            success = true;
        }
    }
    
    return success;
}

std::string InitialStore::item_name(char choice) {
    return names[letter_to_int(choice)];
}

double InitialStore::item_weight(char choice) {
    return weights[letter_to_int(choice)];
}

void InitialStore::reset() {
    int counts[8] = {2, 4, 2, 2, 1, 1, 1, 1};
}
