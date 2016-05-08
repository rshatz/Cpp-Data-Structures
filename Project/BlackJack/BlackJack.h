#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "Player.h"
#include "Deck.h"

#include <set>
#include <list>

using std::list;
using std::set;

class BlackJack
{
public:

    BlackJack();

private:

    void takeBet(); // Take bets at beging of each round.
    void dealCards(); // Deals two cards for each player at begining of round.
    void showCards(); // Display cards
    int cardValue(const string card); // Add value of card to total hand value

    set<int> chips = { 10, 20, 50, 100, 250, 500, 1000 };

    Player player;
    Player dealer;

    Deck deck;

    bool playerStays;
};

#endif // BLACKJACK_H
