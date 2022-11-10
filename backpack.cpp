#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "backpack.hpp"
#include "helpers.hpp"
#include "initial_store.hpp"
#include "backpack_item.hpp"
#include "stats.hpp"

bool Backpack::item_present(std::string item_name) {
    if (!(items.count(item_name))) {return false;}
    if (items.find(item_name)->second.getQuantity() <= 0) {return false;} 
    return true;
}

int Backpack::number_of_items() {
    int count = 0;
    for (auto it: items) {
        if (it.second.getQuantity() > 0) {
            count += 1;
        }
    }
    return count;
}

int Backpack::number_of_actionable_items() {
    int count = 0;
    for (auto item: items) {
        if (item.second.getQuantity() > 0 && item.second.is_actionable()) {
            count += 1;
        }
    }
    return count;
}

double Backpack::item_quantity(std::string item_name) {
    if (!item_present(item_name)) {return 0;}
    else {return items.find(item_name)->second.getQuantity();}
    return 1;
}

void Backpack::increase_item_quantity(std::string item_name, double amount) {
    if (!item_present(item_name)) {
        std::cout << "WARNING: Item " << item_name << " not present.\n\n";
        return;
    }
    else {
        items.find(item_name)->second.increaseQuantity(amount);
        return;
    } 
}

void Backpack::set_item_quantity(std::string item_name, double amount) {
    if (!item_present(item_name)) {
        std::cout << "WARNING: Item " << item_name << " not present.\n\n";
        return;
    }
    else {
        items.find(item_name)->second.setQuantity(amount);
        return;
    } 
}

std::map<int, std::string> Backpack::map_numbers_to_items(bool actionable_only) {
    std::map<int, std::string> map;
    int i = 0;
    for (auto it: items) {
        if (it.second.getQuantity() > 0 && (!actionable_only || it.second.is_actionable())) {
            map.insert({i, it.second.getName()});
            i++;
        }
    }
    return map;
}

std::map<std::string, int> Backpack::map_items_to_numbers(bool actionable_only) {
    std::map<std::string, int> map;
    int i = 0;
    for (auto it: items) {
        if (it.second.getQuantity() > 0 && (!actionable_only || it.second.is_actionable())) {
            map.insert({it.second.getName(), i});
            i++;
        }
    }
    return map;
}

void Backpack::print_contents(std::map<std::string, int> items_to_numbers_map, bool actionable_only) {
    std::cout << "Backpack contents:\n";
    int i = 0;
    for (auto it: items) {
        if (it.second.getQuantity() > 0 && (!actionable_only || it.second.is_actionable())) {
            char letter;
            if (items_to_numbers_map.size() == 0) {letter = int_to_letter(i);}
            else {letter = int_to_letter(items_to_numbers_map[it.second.getName()]);}
            std::cout << letter << ". " << it.second.getName() << ", " << it.second.getQuantity() << ", " << it.second.getWeight() << " lbs/each\n";
            i++;
        }
    }
    std::cout << "\n";
    if (!actionable_only) {std::cout << "Total weight: " << weight() << " lbs\n\n";}
}

double Backpack::weight() {
    double amount = 0;
    for (auto it: items) {
        amount += it.second.getWeight() * it.second.getQuantity();
    }
    return amount;
}

void Backpack::drop_items() {
    std::map<int, std::string> numbers_to_items_map = map_numbers_to_items();
    std::map<std::string, int> items_to_numbers_map = map_items_to_numbers();
    int num_items = number_of_items();
    while (true) {
        std::cout << "What would you like to drop?\n";
        std::cout << "One unit of the item will be dropped.\n\n";
        print_contents(items_to_numbers_map);
        std::cout << int_to_letter(num_items) << ". Cancel\n\n";
        char choice = input_checker_char(num_items+1);
        if (letter_to_int(choice) == num_items) {
            return;
        }
        std::string item_name = numbers_to_items_map[letter_to_int(choice)];
        
        if (item_present(item_name)) {
            increase_item_quantity(item_name, -1);
            std::cout << "\nDropped 1 of item '" << item_name << "'\n";
        } 
        else {
            std::cout << "\nNone of item remaining.\n";
        }

        middle_dashes();
    }
    print_contents();
    pause();
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

void Backpack::reset() {
    for (auto item: items) {
        item.second.setQuantity(0);
    }
}

void Backpack::initial_load() {
    bool done = false;

    InitialStore initial_store;

    while (!done) {
        reset(); //resets backpack
        initial_store.reset();

        bool cont = true;

        while (cont) {
            initial_store.print_inventory_options();
            char choice = input_checker_char(10);
            if (choice == 'I') {
                cont = false;
                done = true;
            } else if (choice == 'J') {
                cont = false;
                done = false;
                std::cout << "Backpack reset.\n\n";
                pause();
            } else {
                // std::cout << "\n";
                // print_line("-", (getWindowColumns() - 6) / 2, false);
                // std::cout << "RESULT";
                //  print_line("-", (getWindowColumns() - 6) / 2, true);
                std::cout << "How many would you like to add?\n\n";
                double quantity = input_checker_positive_int();
                if (initial_store.take_item(choice, quantity)) {
                    increase_item_quantity(initial_store.item_name(choice), quantity);
                    std::cout << "Item";
                    if (quantity > 1) {std::cout << "s";}
                    std::cout << " added to backpack.\n\n";
                    pause();
                    print_contents();
                    pause();
                }
            }
        }
    }

    std::cout << "\nYou are ready to begin your journey! You lift your back pack. ";
    if (weight() > 45) {
        std::cout << "You pull your backpack over your shoulders and take a step forward. You immediately fall over. This backpack is too heavy to continue.\n";
        drop_items();
        bool heavy = (weight() > 45);
        while (heavy) {
            std::cout << "\nThe backpack is still too heavy. Try to get to 45 lbs or less.\n";
            drop_items();
            heavy = (weight() > 45);
        }
        std::cout << "\nThat's better! You lift your backpack again. ";
        if (weight() <=15) {
            std::cout << "It is now quite light. You can move quickly through the forest.\n";
        } else if (weight() > 30) {
            std::cout << "It is still quite heavy but at least you can carry it now.\n";
        } else {
            std::cout << "\n";
        }
    } else if (weight() <= 15) {
        std::cout << "It is light. You can move quickly through the forest.\n";
    } else if (weight() <= 30) {
        std::cout << "\n";
    } else {
        std::cout << "It is heavy. Your shoulders are already starting to feel sore.\n";
    }
    std::cout << "\n";
    pause(false);
}

void Backpack::item_action(std::string item_name, Stats &stats, Backpack &backpack) {
    if (!item_present(item_name)) {
        std::cout << "WARNING: There is no item by the name of " << item_name << ".\n\n";
        return;
    }
    items.find(item_name)->second.takeAction(stats, backpack);
}

void Backpack::select_item_for_action(Stats &stats, Backpack &backpack) {
    std::map<int, std::string> numbers_to_items_map = map_numbers_to_items(true);
    std::map<std::string, int> items_to_numbers_map = map_items_to_numbers(true);
    int num_items = number_of_actionable_items();
    while (true) {
        std::cout << "What would you like to use?\n\n";
        print_contents(items_to_numbers_map, true);
        std::cout << int_to_letter(num_items) << ". Cancel\n\n";
        char choice = input_checker_char(num_items+1);
        if (letter_to_int(choice) == num_items) {
            return;
        }
        std::string item_name = numbers_to_items_map.find(letter_to_int(choice))->second;
        item_action(item_name, stats, backpack);
    }
}
