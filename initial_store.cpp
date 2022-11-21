#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "initial_store.hpp"
#include "helpers.hpp"

void InitialStore::print_inventory_options() {
        print_nice("Choose equipment for your journey.\n\n");
        print_nice("   Item                             Weight       Quantity Available\n");
        print_nice("-------------------------------------------------------------------\n");
        print_nice("A. Food (1 day)                     2 lbs        unlimited\n");
        print_nice("B. Makeshift tent                   6 lbs        " + double_to_nice_string(counts[0]) + "\n");
        print_nice("C. First aid kit                    0.5 lbs      " + double_to_nice_string(counts[1]) + "\n");
        print_nice("D. Change of clothes                2 lbs        " + double_to_nice_string(counts[2]) + "\n");
        print_nice("E. Blanket                          3 lbs        " + double_to_nice_string(counts[3]) + "\n");
        print_nice("F. Questionable healing potion      1 lbs        " + double_to_nice_string(counts[4]) + "\n");
        print_nice("G. Good luck rock                   3 lbs        " + double_to_nice_string(counts[5]) + "\n");
        print_nice("H. Walking stick                    3 lbs        " + double_to_nice_string(counts[6]) + "\n");
        print_nice("I. Spear                            4 lbs        " + double_to_nice_string(counts[7]) + "\n\n");
        print_nice("J. Finished packing\n");
        print_nice("K. Restart\n\n");
}

bool InitialStore::take_item(char choice, double quantity) {
    bool success = false;
    int i = letter_to_int(choice);
    if (i == 0) {
        success = true;
    } else {
        if (counts[i-1] < 1) {
            print_nice("No more available.\n");
        } 
        else if (counts[i-1] < quantity) {
            print_nice("Only " + double_to_nice_string(counts[i-1]) + " available. No items added.\n\n");
            pause0();
        }
        else {
            counts[i-1] -= quantity;
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
    int new_counts[8] = {2, 4, 2, 2, 1, 1, 1, 1};
    for (int i = 0; i < 8; i++) {
        counts[i] = new_counts[i];
    }
}


