#ifndef DEALER_H
#define DEALER_H

#include <map>
#include <list>
#include <queue>
#include <string>
#include <unistd.h>

using std::map;
using std::list;
using std::queue;
using std::string;

class Dealer
{
public:

    Dealer();
    int getHandTotal() const {return handTotal;}

private:

    list<string> hand;

    int handTotal;
};

#endif // DEALER_H
