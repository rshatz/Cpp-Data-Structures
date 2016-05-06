#include "Deck.h"

#include <vector>
#include <algorithm>

using std::vector;

Deck::Deck()
{

}

void Deck::shuffle()
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

string& Deck::popDeck()
{
    string& temp = deck.front();
    deck.pop();
    return temp;
}





















