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
        Item("Food (1 day)", 3.5, 2),
        Item ("Walking stick", 1, 4),
        Item("Change of clothes", 2, 2)
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