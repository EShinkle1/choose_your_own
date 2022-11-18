#ifndef BACKPACK_HPP
#define BACKPACK_HPP

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <unordered_map>
#include "backpack_item.hpp"

class Stats;
class Backpack 
{
private:
    std::map<std::string, Item> items =
        {
        {"Food (1 day)", Item("Food (1 day)", 0, 2.0, &eat_half_can_food, true)},
        {"Makeshift tent", Item("Makeshift tent", 0, 6.0, &null_function, false)},
        {"First aid kit", Item("First aid kit", 0, 0.5, &first_aid_kit, true)},
        {"Change of clothes", Item("Change of clothes", 1, 2.0, &null_function, false)},
        {"Blanket", Item("Blanket", 1, 3.0, &null_function, false)},
        {"Questionable healing potion", Item("Questionable healing potion", 1, 1.0, &healing_potion, true)},
        {"Good luck rock", Item("Good luck rock", 0, 3.0, &null_function, false)},
        {"Walking stick", Item("Walking stick", 0, 3.0, &null_function, false)},
        {"Skeleton's sword", Item("Skeleton's sword", 0, 5.0, &null_function, false)},
        {"Strange gold trinket", Item("Strange gold trinket", 0, 0.5, &null_function, false)},
        {"Cave creature's skull", Item("Cave creature's skull", 0, 2.0, &null_function, false)}
        };

    std::map<int, std::string> map_numbers_to_items(bool actionable_only = false);
    std::map<std::string, int> map_items_to_numbers(bool actionable_only = false);



public:
    bool item_exists(std::string item_name);
    bool item_present(std::string item_name);
    double item_quantity(std::string item_name);
    void increase_item_quantity(std::string item_name, double amount);
    void set_item_quantity(std::string item_name, double amount);
    void print_contents(std::map<std::string, int> items_to_numbers_map = {}, bool actionable_only = false);
    double weight();
    void drop_items();
    int number_of_items();
    int number_of_actionable_items();
    void reset();
    std::string weight_status();
    void initial_load();
    void item_action(std::string item_name, Stats &stats, Backpack &backpack);
    void select_item_for_action(Stats &stats, Backpack &backpack);

};

#endif