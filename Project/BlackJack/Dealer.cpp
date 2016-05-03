#include "Dealer.h"

#include <iostream>

Dealer::Dealer()
{
    //map<string, int>::iterator i;
//    for (i = cards.begin(); i != cards.end(); i++) {
//        std::cout << cards << "\n";
//    }
    for (auto elem : cards) {
        std::cout << elem.first << "\n";
    }


}
