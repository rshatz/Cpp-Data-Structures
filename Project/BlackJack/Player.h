#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player
{
public:

    Player()
        : handTotal(0)
        , account(1000) {}

    void placeBet(const int bet) { currentBet = bet; }
    int getHandTotal() const { return handTotal; }

private:

    int handTotal;
    int account;
    int currentBet;
};

#endif // PLAYER_H
