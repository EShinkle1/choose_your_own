#ifndef EVENTS_HPP
#define EVENTS_HPP

#include <vector>
#include <string>

class Backpack;
class Stats;

class Events
{
private:
    std::vector<int> Tier1 = {3, 6, 8, 12}; //worst
    std::vector<int> Tier2 = {2, 4, 10};
    std::vector<int> Tier3 = {1, 7, 11};
    std::vector<int> Tier4 = {0, 5, 9}; //best
    std::vector<int>* choose_tier(Stats stats, Backpack backpack);
public:
    void get_event(Stats &stats, Backpack &backpack, std::string time_of_day);
};

#endif