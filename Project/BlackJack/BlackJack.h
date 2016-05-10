#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "Player.h"
#include "Deck.h"

#include <stdlib.h>
#include <iostream>
#include <set>

using std::cout;
using std::cin;
using std::set;

class BlackJack
{
public:

    BlackJack();

private:

    void takeBet();   // Take bets at beging of each round.
    void dealCards(); // Deals two cards for each player at begining of each round.
    void playerHit(); // Add a card to a player's hand.
    void dealerHit(); // Add a card to the dealer's hand.
    void showCards(); // Display cards.
    void menu();      // Shows blackjack options menu.
    void newRound();  // Start new round.
    void playerWins();
    void dealerWins();
    void exitGame() { exit(0); }  // Game ends when player places a bet of 0.

    set<int> chips = { 10, 20, 50, 100, 250, 500, 1000 };

    Player player;
    Player dealer;

    Deck deck;

    bool hideCard; // Test to see if dealer's 2nd card should be hidden.
};

#endif // BLACKJACK_H
