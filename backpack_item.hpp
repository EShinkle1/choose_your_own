#ifndef BACKPACK_ITEM_HPP
#define BACKPACK_ITEM_HPP

#include <iostream>
#include <string>

class Item {
private:
    std::string name;
    int quantity;
    double weight;

    // bool actionable = false;
public:
    Item(std::string new_name, int new_quantity, double new_weight);
    std::string getName();
    int getQuantity();
    double getWeight();
    
    void increaseQuantity(int amount);

    // bool is_actionable();
    // void setActionable(bool value);

    // void (*dotakeAction)(Item*);
    // void takeAction() { if (dotakeAction) dotakeAction(this); };
    
};

#endif