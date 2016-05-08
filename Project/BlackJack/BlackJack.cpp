#include "BlackJack.h"

#include <iostream>

using std::cout;
using std::cin;

BlackJack::BlackJack()
    : playerStays(false)
{
    deck.shuffle();
    //takeBet();
    dealCards();
    showCards();
}

void BlackJack::takeBet()
{
    cout << "Chip values: ";
    set<int>::const_iterator iter;
    for (iter = chips.begin(); iter != chips.end(); iter++) {
        cout << *iter << " ";
    }

    cout << "\nPlace your bet: ";
    int bet;
    cin >> bet;

    auto check = chips.find(bet);
    while(check == chips.end()) {
        cout << "Enter a valid chip value: ";
        cin >> bet;
        check = chips.find(bet);
    }
    player.placeBet(bet);
}

void BlackJack::dealCards()
{
    // deal two cards to each player
    for(int i = 0; i < 2; i++) {
        player.pushCard(deck.popCard());
        dealer.pushCard(deck.popCard());
    }
}

void BlackJack::showCards() const
{
    cout << "Player's Hand: ";
    player.showHand(false);
    cout << " " << player.getHandTotal();

    cout << "\nDealer's Hand: ";
    dealer.showHand(true);
    cout << " " << dealer.getHandTotal();
}









