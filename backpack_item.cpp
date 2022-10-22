#include <iostream>
#include "backpack_item.hpp"

Item::Item(std::string new_name, int new_quantity, double new_weight) {
    name = new_name;
    quantity = new_quantity;
    weight = new_weight;
}

std::string Item::getName() {
    return name;
}

int Item::getQuantity() {
    return quantity;
}

double Item::getWeight() {
    return weight;
}


void Item::increaseQuantity(int amount) {
    quantity += amount;
}


// bool Item::is_gone() {
//     return (quantity <= 0);
// }

// bool Item::is_actionable() {
//     return actionable;
// }



// void Item::setActionable(bool value) {
//     actionable = value;
// }
