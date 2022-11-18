#include <backpack.hpp>
#include <stats.hpp>
#include <helpers.hpp>

//Tier 1, fall into muddy stream
void event3(Backpack &backpack, Stats &stats, std::string time_of_day) {
    print_nice("The air is crisp. You walk along at a moderate pace, occasionally stopping to glance at the colorful bugs crawling in and out of the crevices in the bark of the trees.\n\n");
    pause0();
    print_nice("If you got desperate enough, you think to yourself, ...\n\n");
    print_nice("You shake your head to toss the thought from your mind.\n\n");
    pause0();
    print_nice("Suddenly your feel your foot sinking, as cold mud begins to envelop your lower leg. A thin stream of water splits as it hits your leg and passes across the front and back sides of your thigh.\n\n");
    pause0();
    print_nice("Unfortunately, you had already lifted your other leg before recognizing your misfortune, and in your attempt to rebalance find your chest and face pressed into the mud as well.\n\n");
    pause0();
    print_nice("Luckily, the mud is less than a foot deep and you are able to pull yourself up. You wipe off as much as you can and shiver as a breeze ruffles the leaves on the nearby trees.\n\n");
    pause0();

    if (backpack.item_quantity("Change of clothes") > 0) {
        print_nice("You remember that you have extra clothes in your backpack.\n\n");
        print_nice("Use change of clothes?\n\n");
        print_nice("  A. Yes\n");
        print_nice("  B. No\n\n");
        int choice = letter_to_int(input_checker_char(2));

        if (choice == 0) {
            backpack.increase_item_quantity("Change of clothes", -1);
            print_nice("You feel much better!\n\n");
            pause0();
        } else {
            print_nice("You continue walking, shivering as you go along. ");
            stats.increaseHealth(-10);
            print_nice("Hopefully you'll be able to warm up soon.\n\n");
            pause0();
        }
    } else {
        print_nice("You continue walking, shivering as you go along. You imagine how soothing a clean pair of clothes would feel. ");
        stats.increaseHealth(-10);
        print_nice("Hopefully you'll be able to warm up soon.\n\n");
        pause0();
    }
    print_nice("You see a patch of grass ahead. It looks like a good place to take a break.\n\n");
    pause0();
    stats.increaseMilesJourneyed(8, backpack);
}