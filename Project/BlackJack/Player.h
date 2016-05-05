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
        : cardSum(0)
        , account(0) {}

    void placeBet();

private:

    list<string> hand;
    set<int> bet = { 10, 20, 50, 100, 250, 500, 1000 };

    int cardSum;
    int account;
};

#endif // PLAYER_H
