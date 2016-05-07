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
        pHand.push_back(deck.popDeck());
        dHand.push_back(deck.popDeck());
    }
    pHand.sort();
    dHand.sort();
}

void BlackJack::showCards() const
{
    cout << "Player's Hand: ";
    list<string>::const_iterator iter = pHand.begin();

    while(iter != pHand.end()) {
        cout << *iter << " ";
        iter++;
    }
    cout << "\nDealer's Hand: ";

    // if player stands than loop through all of dealer's cards
    // else show one card from dealer's hand
    iter = dHand.begin();
    if(playerStays) {
        while(iter != pHand.end()) {
            cout << *iter << " ";
            iter++;
        }
    }
    else {
        cout << *iter << " *\n";
    }
}









