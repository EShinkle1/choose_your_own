#ifndef EVENTS_HPP
#define EVENTS_HPP

#include <vector>

class Backpack;
class Stats;

class Events
{
private:
    std::vector<int> Tier1 = {3}; //worst
    std::vector<int> Tier2 = {2, 4};
    std::vector<int> Tier3 = {1};
    std::vector<int> Tier4 = {0}; //best
    std::vector<int>* choose_tier(Stats stats);
public:
    void get_event(Stats &stats, Backpack &backpack);
};

#endif