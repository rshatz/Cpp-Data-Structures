#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "Player.h"
#include "Deck.h"

#include <set>

using std::set;

class BlackJack
{
public:

    BlackJack();

private:

    void takeBet(); // Take bets at beging of each round.
    void dealCards(); // Deals two cards for each player at begining of each round.
    void hit(); // Add a card to a player's hand.
    void showCards(); // Display cards
    void menu(); // Shows blackjack options menu.

    set<int> chips = { 10, 20, 50, 100, 250, 500, 1000 };

    Player player;
    Player dealer;

    Deck deck;
};

#endif // BLACKJACK_H
