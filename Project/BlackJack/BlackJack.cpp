#include "BlackJack.h"

#include <iostream>

using std::cout;
using std::cin;

BlackJack::BlackJack()
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

void BlackJack::menu()
{
    cout << "\nEnter h to hit s to stay: ";

    char choice;
    cin >> choice;

    switch (tolower(choice)) {
    case 'h':
        playerHit();
        showCards();
        break;
    case 's':
        dealerHit();
        showCards();
        break;
    default:
        cout << "\nEnter a valid option.";
        menu();
        break;
    }
}

void BlackJack::playerHit()
{
    player.pushCard(deck.popCard());

    if(player.getHandTotal() > 21) {
        player.showHand(false);
        cout << " Bust!\n";
    }
}

void BlackJack::dealerHit()
{
    while(dealer.getHandTotal() < 17) {
        dealer.pushCard(deck.popCard());
    }
    if(dealer.getHandTotal() > 21) {
        cout << "Bust!\n";
    }
}

void BlackJack::showCards()
{
    cout << "\nPlayer's Hand: ";
    player.showHand(false);

    cout << "\nDealer's Hand: ";
    dealer.showHand(false);

    // Show menu after initial deal
    menu();
}









