#ifndef BACKPACK_ITEM_HPP
#define BACKPACK_ITEM_HPP

#include <iostream>
#include <string>
#include "item_actions.hpp"

class Stats;
class Backpack;

class Item {
private:
    const std::string name;
    double quantity;
    const double weight;
    double (*function)(Stats &stats, Backpack &backpack);
    bool actionable;
public:
    Item(std::string new_name, double new_quantity, double new_weight, double (*new_function)(Stats &stats, Backpack &backpack), bool if_actionable);
            
    std::string getName();
    double getQuantity();
    double getWeight();
    
    void increaseQuantity(double amount);
    void setQuantity(double amount);

    bool is_actionable();
    void takeAction(Stats &stats, Backpack &backpack);    
};

#endif