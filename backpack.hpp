#ifndef BACKPACK_HPP
#define BACKPACK_HPP

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include "backpack_item.hpp"

class Backpack 
{
private:
    std::list<Item> items = { //capitalize first word only
        Item("Food (1 day)", 0, 2.0),
        Item("Makeshift tent", 0, 6.0),
        Item("First aid kit", 0, 0.5),
        Item("Change of clothes", 0, 2.0),
        Item("Blanket", 0, 3.0),
        Item("Healing potion", 0, 1.0),
        Item("Good luck rock", 0, 3.0),
        Item("Walking stick", 0, 3.0)
    };

public:
    int count_of_item(std::string item_name);
    void increase_item_count(std::string item_name, int quantity);
    void print_contents(std::map<std::string, int> items_to_numbers_map = {});
    void drop_items();
    double weight();
    void initial_load();
    void reset();
    int number_of_items();
    std::map<int, std::string> map_numbers_to_items();
    std::map<std::string, int> map_items_to_numbers();
    std::string weight_status();

};

#endif