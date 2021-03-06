#include "Deck.h"

void Deck::shuffle()
{
    emptyDeck(); // Empty the deck so new cards can be added.
    vector<string> vect;

    set<string>::const_iterator iset;
    for(iset = cards.begin(); iset != cards.end(); iset++) {
        vect.push_back(*iset);
    }

    random_shuffle(vect.begin(), vect.end());

    vector<string>::const_iterator ivect = vect.begin();
    while(ivect != vect.end()) {
        deck.push(*ivect);
        ivect++;
    }
}

string& Deck::popCard()
{
    if(deck.empty()) {
        shuffle();
    }
    string& temp = deck.front();
    deck.pop();
    return temp;
}

void Deck::emptyDeck() {

    while(!(deck.empty())) {
        deck.pop();
    }
}
