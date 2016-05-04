#ifndef DEALER_H
#define DEALER_H

#include <map>
#include <list>
#include <queue>
#include <set>
#include <string>
#include <unistd.h>

using std::map;
using std::list;
using std::queue;
using std::set;
using std::string;

class Dealer
{
private:

    map<string, int> cards = {  // Hearts
                               {"1H", 1}, {"2H", 2}, {"3H", 3}, {"4H", 4}, {"5H", 5}
                              ,{"6H", 6}, {"7H", 7}, {"8H", 8}, {"9H", 9}, {"10H", 10}
                              ,{"JH", 10}, {"QH", 10}, {"KH", 10}, {"AH", 11}
                                // Diamonds
                              ,{"1D", 1}, {"2D", 2}, {"3D", 3}, {"4D", 4}, {"5D", 5}
                              ,{"6D", 6}, {"7D", 7}, {"8D", 8}, {"9D", 9}, {"10D", 10}
                              ,{"JD", 10}, {"QD", 10}, {"KD", 10}, {"AD", 11}
                               // Spades
                              ,{"1S", 1}, {"2S", 2}, {"3S", 3}, {"4S", 4}, {"5S", 5}
                              ,{"6S", 6}, {"7S", 7}, {"8S", 8}, {"9S", 9}, {"10S", 10}
                              ,{"JS", 10}, {"QS", 10}, {"KS", 10}, {"AS", 11}
                               // Clubs
                              ,{"1C", 1}, {"2C", 2}, {"3C", 3}, {"4C", 4}, {"5C", 5}
                              ,{"6C", 6}, {"7C", 7}, {"8C", 8}, {"9C", 9}, {"10C", 10}
                              ,{"JC", 10}, {"QC", 10}, {"KC", 10}, {"AC", 11}
                             };

    queue<string> deck;
    list<map<string, int>> hand;
    set<int> bet = {10, 20, 50, 100, 250, 500, 1000, 5000};

public:
    Dealer();
};

#endif // DEALER_H