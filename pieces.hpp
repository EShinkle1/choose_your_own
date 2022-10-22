#ifndef PIECES_HPP
#define PIECES_HPP

class Stats;
class Backpack;
class Events;

void wake_up_text(Stats &stats);
void day_header(Stats stats);
void new_day(Stats &stats, Backpack &backpack, Events &events);

#endif