#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <list>
#include <map>

using std::string;
using std::list;
using std::map;

class Player
{
public:

    Player()
        : handTotal(0)
        , account(1000)
        , bet(0)
        , aceCount(0) {}

    void placeBet(const int placedBet) { bet = placedBet; }
    void pushCard(const string card);
    void showHand() const; // Show all cards in players hand.
    void hideCard() const; // Show first card with second card hidden.
    void win() { account += bet; }
    void lose() { account -= bet; }
    int getHandTotal() const { return handTotal; }


private:

    void tallyHand(const string card);

    const map<string, int> cards = { // Hearts
                                      {"AH", 11}, {"2H", 2}, {"3H", 3}, {"4H", 4}, {"5H", 5}
                                     ,{"6H", 6}, {"7H", 7}, {"8H", 8}, {"9H", 9}, {"10H", 10}
                                     ,{"JH", 10}, {"QH", 10}, {"KH", 10}
                                     // Diamonds
                                     ,{"AD", 11} ,{"2D", 2}, {"3D", 3}, {"4D", 4}, {"5D", 5}
                                     ,{"6D", 6}, {"7D", 7}, {"8D", 8}, {"9D", 9}, {"10D", 10}
                                     ,{"JD", 10}, {"QD", 10}, {"KD", 10}
                                     // Spades
                                     ,{"AS", 11} ,{"2S", 2}, {"3S", 3}, {"4S", 4}, {"5S", 5}
                                     ,{"6S", 6}, {"7S", 7}, {"8S", 8}, {"9S", 9}, {"10S", 10}
                                     ,{"JS", 10}, {"QS", 10}, {"KS", 10}
                                     // Clubs
                                     ,{"AC", 11}, {"2C", 2}, {"3C", 3}, {"4C", 4}, {"5C", 5}
                                     ,{"6C", 6}, {"7C", 7}, {"8C", 8}, {"9C", 9}, {"10C", 10}
                                     ,{"JC", 10}, {"QC", 10}, {"KC", 10}
                                   };

    list<string> hand;

    int handTotal;  // Numerical value of player's hand.
    int account;    // Players total chips.
    int bet;        // Hold the current bet.
    int aceCount;   // Keep count of number of Aces.
};

#endif // PLAYER_H
