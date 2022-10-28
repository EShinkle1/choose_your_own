#include <iostream>
#include "backpack_item.hpp"
#include "stats.hpp"
#include "backpack.hpp"

Item::Item(std::string new_name, double new_quantity, double new_weight, double (*new_function)(Stats &stats, Backpack &backpack), bool if_actionable)
    : weight(new_weight), name(new_name) {
    quantity = new_quantity;
    function = new_function;
    actionable = if_actionable;
}

void Item::takeAction(Stats &stats, Backpack &backpack) {
    if (quantity == 0) {
        std::cout << "WARNING: None of the item " << name << " remains\n\n";
        return;
    }
    quantity += function(stats, backpack);
}

std::string Item::getName() {
    return name;
}

double Item::getQuantity() {
    return quantity;
}

double Item::getWeight() {
    return weight;
}


void Item::increaseQuantity(double amount) {
    quantity += amount;
    if (quantity < 0) {quantity = 0;}
}

void Item::setQuantity(double amount) {
    quantity = amount;
    if (quantity < 0) {quantity = 0;}
}


// bool Item::is_gone() {
//     return (quantity <= 0);
// }

bool Item::is_actionable() {
    return actionable;
}

