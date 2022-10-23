#ifndef BACKPACK_HPP
#define BACKPACK_HPP

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include "backpack_item.hpp"
#include "item_actions.hpp"

class Stats;

class Backpack 
{
private:
    std::list<Item> items = { //capitalize first word only
        Item("Food (1 day)", 1.5, 2.0, &eat_half_can_food, true),
        Item("Makeshift tent", 0, 6.0, &null_function),
        Item("First aid kit", 1, 0.5, &first_aid_kit, true),
        Item("Change of clothes", 0, 2.0, &null_function),
        Item("Blanket", 0, 3.0, &null_function), 
        Item("Questionable healing potion", 1, 1.0, &healing_potion, true),
        Item("Good luck rock", 1, 3.0, &null_function),
        Item("Walking stick", 0, 3.0, &null_function)
    };

    std::map<int, std::string> map_numbers_to_items(bool actionable_only = false);
    std::map<std::string, int> map_items_to_numbers(bool actionable_only = false);


public:
    double count_of_item(std::string item_name);
    void increase_item_count(std::string item_name, double quantity);
    void set_item_count(std::string item_name, double quantity);
    void print_contents(std::map<std::string, int> items_to_numbers_map = {}, bool actionable_only = false);
    void drop_items();
    double weight();
    void initial_load();
    void reset();
    int number_of_items();
    int number_of_actionable_items();
    std::string weight_status();
    void item_action(std::string item_name, Stats &stats, Backpack &backpack);
    void select_item_for_action(Stats &stats, Backpack &backpack);

};

#endif