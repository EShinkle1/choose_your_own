#ifndef CHOICES_HPP
#define CHOICES_HPP

class Stats;
class Backpack;

int choose_route(Stats &stats);
void check_in(Stats &stats, Backpack &backpack);
void lunch(Stats &stats, Backpack &backpack);
void dinner(Stats &stats, Backpack &backpack);
void bedtime(Stats &stats, Backpack &backpack);

#endif