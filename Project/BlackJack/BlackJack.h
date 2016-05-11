#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "Player.h"
#include "Deck.h"
#include "ClearScreen.h"

#include <iostream>
#include <iomanip>
#include <set>

using std::cout;
using std::cin;
using std::set;
using std::setw;

class BlackJack
{
public:

    BlackJack();

private:

    void takeBet();     // Take bets at beging of each round.
    void dealCards();   // Deals two cards for each player at begining of each round.
    void playerHit();   // Add a card to a player's hand.
    void dealerHit();   // Add a card to the dealer's hand.
    void showCards();   // Display cards.
    void menu();        // Shows blackjack options menu.
    void newRound();    // Current round terminates. Start new round.
    void checkWin();    // Check to see which player has higher value hand
    void newDeal();     // Ask player if quit or continue game.
    void playerWins();  // Declares player as winner.
    void dealerWins();  // Declares dealer as winner.
    void exitGame() { exit(0); }  // Game ends when player places a bet of 0.
    bool validateBet(const string bet); // Validates user input for bet value.

    Player player;
    Player dealer;

    Deck deck;

    bool hideCard; // Test to see if dealer's 2nd card should be hidden.
    bool control;  // Control if menu() function is called again.
};

#endif // BLACKJACK_H
