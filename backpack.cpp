#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include "backpack.hpp"
#include "helpers.hpp"
#include "initial_store.hpp"
#include "backpack_item.hpp"

int Backpack::count_of_item(std::string item_name) {
    std::list<Item>::iterator it;
    for (it = items.begin(); it != items.end(); it++) {
        if (it->getName() == item_name) {
            return it->getQuantity();
        }
    }
    return 0;
}

int Backpack::number_of_items() {
    int count = 0;
    std::list<Item>::iterator it;
    for (it = items.begin(); it != items.end(); it++) {
        if (it->getQuantity() > 0) {
            count++;
        }
    }
    return count;
}

void Backpack::increase_item_count(std::string item_name, int quantity) {
    std::list<Item>::iterator it;
    for (it = items.begin(); it != items.end(); it++) {
        if (it->getName() == item_name) {
            it->increaseQuantity(quantity);
        }
    }
}

double Backpack::weight() {
    double weight = 0;
    std::list<Item>::iterator it;
    for (it = items.begin(); it != items.end(); it++) {
        weight += it->getQuantity() * it->getWeight();
    }
    return weight;
}

std::string Backpack::weight_status() {
    if (weight() < 15) {
        return "light";
    }
    else if (weight() < 30) {
        return "fine";
    }
    else {
        return "heavy";
    }
}

void Backpack::print_contents(std::map<std::string, int> items_to_numbers_map) {
    std::vector<char> letters = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P'};
    std::cout << "Backpack contents:\n";
    int i = 0;
    std::list<Item>::iterator it;
    for (it = items.begin(); it != items.end(); it++) {
        if (it->getQuantity() > 0) {
            char letter;
            if (items_to_numbers_map.size() == 0) {letter = letters[i];}
            else {letter = letters[items_to_numbers_map.find(it->getName())->second];}
            std::cout << letter << ". " << it->getName() << ", " << it->getQuantity() << ", " << it->getWeight() << " lbs/each\n";
            i++;
        }
    }
    std::cout << "\n";
    std::cout << "Total weight: " << weight() << " lbs\n\n";

}

std::map<int, std::string> Backpack::map_numbers_to_items() {
    std::map<int, std::string> map;
    int i = 0;
    std::list<Item>::iterator it;
    for (it = items.begin(); it != items.end(); it++) {
        if (it->getQuantity() > 0) {
            map.insert({i, it->getName()});
            i++;
        }
    }
    return map;
}

std::map<std::string, int> Backpack::map_items_to_numbers() {
    std::map<std::string, int> map;
    int i = 0;
    std::list<Item>::iterator it;
    for (it = items.begin(); it != items.end(); it++) {
        if (it->getQuantity() > 0) {
            map.insert({it->getName(), i});
            i++;
        }
    }
    return map;
}

void Backpack::drop_items() {
    std::map<int, std::string> numbers_to_items_map = map_numbers_to_items();
    std::map<std::string, int> items_to_numbers_map = map_items_to_numbers();
    int num_items = number_of_items();
    bool cont = true;
    while (cont) {
        print_contents(items_to_numbers_map);
        std::cout << "Select an item to drop. "; 
        char choice = input_checker_char(num_items);
        std::string item_name = numbers_to_items_map.find(letter_to_int(choice))->second;
        
        if (count_of_item(item_name) > 0) {
            increase_item_count(item_name, -1);
            std::cout << "\nDropped 1 of item '" << item_name << "'\n";
        } 
        else {
            std::cout << "\nNone of item remaining.\n";
        }

        std::cout << "\nWould you like to remove more items (Y or N)? ";
        char response[80];
        std::cin.getline(response, 80, '\n');
        if (!(response[0] == 'Y' || response[0] == 'y')) {
            cont = false;
        }

        middle_dashes();
    }
    print_contents();
    pause();
}

void Backpack::initial_load() {
    std::cout << "Not implemented\n";
}

void Backpack::reset() {
    std::list<Item>::iterator it;
    for (it = items.begin(); it != items.end(); it++) {
        it->increaseQuantity(-1*it->getQuantity());
    }
}

// void Backpack::drop_items() {
// //     bool cont = true;
// //     while (cont) {
// //         print_contents();
// //         std::cout << "\nSelect an item to drop. "; 
// //         char choice = input_checker_char(number_of_item_types());
// //         remove_item_by_number(letter_to_int(choice));
// //         std::cout << "\nWould you like to remove more items (Y or N)? ";
// //         char response;
// //         std::cin >> response;
// //         if (!(response == 'Y' || response == 'y')) {
// //             cont = false;
// //         }
// //     }
// };

// double Backpack::weight() {
//     return backpack_weight;
// }

// int Backpack::number_of_item_types() {
//     return item_counts.size();
// }

// void Backpack::reset() {
//     // item_counts = {};
//     // item_weights = {};
//     // backpack_weight = 0.0;
// }

// void Backpack::initial_load() {
//     // bool done = false;

//     // InitialStore initial_store;

//     // while (!done) {
//     //     reset(); //resets backpack
//     //     initial_store.reset();

//     //     bool cont = true;

//     //     while (cont) {
//     //         initial_store.print_inventory_options();
//     //         char choice = input_checker_char(10);
//     //         if (choice == 'I') {
//     //             cont = false;
//     //             done = true;
//     //         } else if (choice == 'J') {
//     //             cont = false;
//     //             done = false;
//     //         } else {
//     //             std::cout << "\n--------------------------RESULT--------------------------\n";
//     //             if (initial_store.take_item(choice)) {
//     //                 add_item(initial_store.item_name(choice), 1, initial_store.item_weight(choice));
//     //                 std::cout << "Item added to backpack. Current backpack weight is " << weight() << " lbs.\n";
//     //             }
//     //         }
//     //     }
//     // }

//     // std::cout << "\nYou are ready to begin your journey! You lift your back pack. ";
//     // if (weight() > 45) {
//     //     std::cout << "You pull your backpack over your shoulders and take a step forward. You immediately fall over. This backpack is too heavy to continue.\n";
//     //     drop_items();
//     //     bool heavy = (weight() > 45);
//     //     while (heavy) {
//     //         std::cout << "\nThe backpack is still too heavy. Try to get to 45 lbs or less.\n";
//     //         drop_items();
//     //         heavy = (weight() > 45);
//     //     }
//     //     std::cout << "\nThat's better! You lift your backpack again. ";
//     //     if (weight() <=15) {
//     //         std::cout << "It is now quite light. You can move quickly through the forest.\n";
//     //     } else if (weight() > 30) {
//     //         std::cout << "It is still quite heavy but at least you can carry it now.\n";
//     //     } else {
//     //         std::cout << "\n";
//     //     }
//     // } else if (weight() <= 15) {
//     //     std::cout << "It is light. You can move quickly through the forest.\n";
//     // } else if (weight() <= 30) {
//     //     std::cout << "\n";
//     // } else {
//     //     std::cout << "It is heavy. Your shoulders are already starting to feel sore.\n";
//     // }
// }