#include "BlackJack.h"

BlackJack::BlackJack()
    : hideCard(true)
{
    newRound();
}

void BlackJack::newRound()
{
    deck.shuffle();
    //takeBet();
    dealCards();
    showCards();
}

void BlackJack::menu()
{
    char choice;
    // If player has 21, player automatically stays - 's'.
    if(player.getHandTotal() == 21) {
        choice = 's';
    }
    else {
        cout << "\nEnter h to hit s to stay: ";
        cin >> choice;
    }

    switch (tolower(choice)) {
    case 'h':
        playerHit();
        showCards();
        break;
    case 's':
        dealerHit();
        hideCard = false; // Player's turn is complete. Show dealer's hand.
        showCards();
        //checkWin();
        break;
    default:
        cout << "\nEnter a valid option.";
        menu();
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

    // Show menu for player's options.
    menu();
}

void BlackJack::playerHit()
{
    player.pushCard(deck.popCard());

    if(player.getHandTotal() > 21) {
        player.showHand();
        cout << "Player busts!\n";
        dealerWins();
    }
}

void BlackJack::dealerHit()
{
    while(dealer.getHandTotal() < 17) {
        dealer.pushCard(deck.popCard());
    }
    if(dealer.getHandTotal() > 21) {
        cout << "Dealer busts!\n";
        playerWins();
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
        cout << "PUSH!";
        newRound();
    }
}

void BlackJack::playerWins()
{
    cout << "Player wins!\n";
    player.win();
    newRound();
}

void BlackJack::dealerWins()
{
    cout << "Dealer wins.\n";
    player.lose();
    newRound();
}
