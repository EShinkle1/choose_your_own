#ifndef INITIAL_STORE_HPP
#define INITIAL_STORE_HPP

#include <iostream>
#include <string>
#include <vector>
#include <map>

class InitialStore 
{
private:
    int counts[8] = {2, 4, 2, 2, 1, 1, 1, 1}; 
    const std::vector<std::string> names = {"Food (1 day)", "Makeshift tent", "First aid kit", "Change of clothes", "Blanket", "Questionable Healing Potion", "Good luck rock", "Walking stick"};
    const std::vector<double> weights = {2.0, 6.0, 0.5, 2.0, 3.0, 1.0, 3.0, 3.0};

public: 
    void print_inventory_options();
    bool take_item(char choice, double quantity);
    std::string item_name(char choice);
    double item_weight(char choice);
    void reset();

};

#endif