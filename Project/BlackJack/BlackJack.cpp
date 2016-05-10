#include "BlackJack.h"

BlackJack::BlackJack()
    : hideCard(true)
    , control(true)
{
    newRound();
}

void BlackJack::newRound()
{
    deck.shuffle();
    takeBet();
    dealCards();
    showCards();

    while(control) {
        menu();
        showCards();
    }
    checkWin();
}

void BlackJack::menu()
{
    cout << "\n\nEnter h to hit, or s to stay: ";

    char choice;
    cin >> choice;

    switch (tolower(choice)) {
    case 'h':

        playerHit();
        control = true; // Run menu() again.
        break;

    case 's':

        hideCard = false; // Player's turn is complete. Show dealer's hand.
        dealerHit();
        control = false; // menu() terminates.
        break;

    default:

        cout << "\nEnter a valid option.";
        control = true; // Run menu() again.
        break;
    }
}

void BlackJack::takeBet()
{
    cout << "Chip values: ";
    set<int>::const_iterator iter;
    for (iter = chips.begin(); iter != chips.end(); iter++) {
        cout << *iter << " ";
    }

    cout << "\nEnter a 0 bet to end the game.\nPlace your bet: ";
    int bet;
    cin >> bet;
    if(!bet) {
        exitGame();
    }

    auto check = chips.find(bet);
    // Loop if invalid bet is made
    while(check == chips.end()) {
        cout << "Enter a valid chip value: ";
        cin >> bet;
        check = chips.find(bet);
    }
    player.placeBet(bet);
}

void BlackJack::dealCards()
{
    // deal two cards to each player
    for(int i = 0; i < 2; i++) {
        player.pushCard(deck.popCard());
        dealer.pushCard(deck.popCard());
    }
}

void BlackJack::showCards()
{
    cout << "\nPlayer's Hand: ";
    player.showHand();
    cout << player.getHandTotal();

    cout << "\nDealer's Hand: ";
    if(hideCard) {
        dealer.hideCard();
    }
    else {
        dealer.showHand();
    }
}

void BlackJack::playerHit()
{
    player.pushCard(deck.popCard());

    if(player.getHandTotal() > 21) {
        cout << "\nPlayer busts!\n";
        //dealerWins();
    }
}

void BlackJack::dealerHit()
{
    while(dealer.getHandTotal() < 17) {
        dealer.pushCard(deck.popCard());
    }
    if(dealer.getHandTotal() > 21) {
        cout << "\nDealer busts!\n";
        //playerWins();
    }
}

void BlackJack::checkWin()
{
    if(player.getHandTotal() > dealer.getHandTotal()) {
        playerWins();
    }
    else if(dealer.getHandTotal() > player.getHandTotal()) {
        dealerWins();
    }
    else {
        cout << "\nPUSH!\n";
        //newRound();
    }
}

void BlackJack::playerWins()
{
    cout << "\nPlayer wins!\n";
    player.win();
    //newRound();
}

void BlackJack::dealerWins()
{
    cout << "\nDealer wins.\n";
    player.lose();
    //newRound();
}
