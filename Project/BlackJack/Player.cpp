#include "Player.h"

#include <iostream>

using std::cout;

void Player::pushCard(const std::string card)
{
    hand.push_back(card);
    hand.sort();
    tallyHand();
}

void Player::tallyHand()
{

}

void Player::showHand(bool hideCard) const
{
    list<string>::const_iterator iter = hand.begin();

    if(hideCard) {
        cout << *iter << " *\n";
    }
    else {
        while(iter != hand.end()) {
            cout << *iter << " ";
            iter++;
        }
    }
}
