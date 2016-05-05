#include "Dealer.h"

#include <algorithm>
#include <iterator>
#include <iostream>
#include <ctime>
#include <random>

using std::vector;

Dealer::Dealer()
{
    shuffleCards();
}

void Dealer::shuffleCards()
{
    vector<string> vect;

    map<string, int>::const_iterator imap;
    for (imap = cards.begin(); imap != cards.end(); imap++) {
       vect.push_back(imap->first);
    }
    srand(std::time(0));
    random_shuffle(vect.begin(), vect.end());

    vector<string>::const_iterator ivect = vect.begin();
    while (ivect != vect.end()) {
        deck.push(*ivect);
        ivect++;
    }

    std::copy(vect.begin(), vect.end(), std::ostream_iterator<string>(std::cout, " "));
    std::cout << "\n";

    while (!deck.empty()) {

    }

}
