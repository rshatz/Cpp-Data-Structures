#ifndef DEALER_H
#define DEALER_H


#include <list>
#include <string>

using std::list;
using std::string;

class Dealer
{
public:

    Dealer();

    void hit(const string card) { hand.push_back(card); }
    int getHandTotal() const { return handTotal; }

private:

    list<string> hand;

    int handTotal;
};

#endif // DEALER_H
