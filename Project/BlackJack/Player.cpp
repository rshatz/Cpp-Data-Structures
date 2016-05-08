#include "Player.h"

#include <iostream>

using std::cout;

void Player::pushCard(const std::string card)
{
    hand.push_back(card);
    hand.sort();
}

void Player::showHand()
{
        cout << "Player's Hand: ";
        list<string>::const_iterator iter = hand.begin();

        while(iter != hand.end()) {
            cout << *iter << " ";
            iter++;
        }
        cout << "\nDealer's Hand: ";

        // if player stands than loop through all of dealer's cards
        // else show one card from dealer's hand
//        iter = hand.begin();
//        if(playerStays) {
//            while(iter != hand.end()) {
//                cout << *iter << " ";
//                iter++;
//            }
//        }
//        else {
//            cout << *iter << " *\n";
//        }
}
