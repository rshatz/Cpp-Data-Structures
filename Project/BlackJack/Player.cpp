#include "Player.h"

#include <iostream>

using std::cout;

void Player::pushCard(const std::string card)
{
    hand.push_back(card);
    //hand.sort();
    tallyHand(card);
}

void Player::tallyHand(const std::string card)
{
    map<string, int>::const_iterator imap;

    imap = cards.find(card);
    handTotal += imap->second;
}

void Player::showHand(bool hideCard) const
{
    list<string>::const_iterator iter = hand.begin();

    if(hideCard) {
        cout << *iter << " *";
    }
    else {
        while(iter != hand.end()) {
            cout << *iter << " ";
            iter++;
        }
    }
}
