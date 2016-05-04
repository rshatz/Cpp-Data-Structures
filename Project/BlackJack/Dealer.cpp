#include "Dealer.h"
#include <iostream>

Dealer::Dealer()
{
    map<string, int>::iterator iter;
    for (iter = cards.begin(); iter != cards.end(); iter++) {
       deck.push(iter->first);
    }
}
