#include "Player.h"

#include <iostream>

using std::cout;

void Player::pushCard(const string card)
{
    hand.push_back(card);
    tallyHand(card);
}

void Player::tallyHand(const string card)
{
    map<string, int>::const_iterator imap;
    imap = cards.find(card);

    handTotal += imap->second;

    if(imap->second == 11) {
        aceCount++;
    }

    while(aceCount && handTotal > 21) {
        handTotal -= 10; // Ace now is equal to 1.
        aceCount--; // Ace value logically can only change once.
    }
}

void Player::hideCard() const
{
    cout << "|" << hand.front() << "| *";
}

void Player::showHand() const
{
    list<string>::const_iterator iter = hand.begin();

    while(iter != hand.end()) {
        cout << "|" << *iter << "|";
        iter++;
    }
}
