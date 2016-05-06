#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "Dealer.h"
#include "Player.h"
#include "Deck.h"

class BlackJack
{
public:

    BlackJack();
    void takeBets(); // Take bets at beging of each round.
    void dealCards(Dealer& dealer); // Deals two cards for each player at begining of round.

private:

    set<int> chips = { 10, 20, 50, 100, 250, 500, 1000 };
    Player player;
    Dealer dealer;
    Deck deck;
};

#endif // BLACKJACK_H
