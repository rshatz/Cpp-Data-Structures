#ifndef PLAYER_H
#define PLAYER_H

#include <list>
#include <set>
#include <string>

using std::list;
using std::string;
using std::set;

class Player
{
public:

    Player()
        : handTotal(0)
        , account(1000) {}

    void placeBet(const int bet) {currentBet = bet;}
    const int& getHandTotal() const {return handTotal;}

private:

    list<string> hand;

    int handTotal;
    int account;
    int currentBet;
};

#endif // PLAYER_H
