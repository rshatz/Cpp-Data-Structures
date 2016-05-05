#include "Dealer.h"

#include <algorithm>
#include <iterator>
#include <iostream>
#include <random>

using std::vector;

Dealer::Dealer()
{
    shuffleDeck();
}

void Dealer::shuffleDeck()
{
    vector<string> vect;

    map<string, int>::const_iterator imap;
    for (imap = cards.begin(); imap != cards.end(); imap++) {
       vect.push_back(imap->first);
    }

    random_shuffle(vect.begin(), vect.end());

    vector<string>::const_iterator ivect = vect.begin();
    while (ivect != vect.end()) {
        deck.push(*ivect);
        ivect++;
    }
}

const string& Dealer::dealCard()
{
    string& temp = deck.front();
    deck.pop();
    return temp;
}
