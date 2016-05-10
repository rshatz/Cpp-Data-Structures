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
    newDeal();
}

void BlackJack::newDeal()
{
    cout << " *********************************\n"
         << " *  d key = deal | q key = quit  *\n"
         << " *********************************\n"
         << " Enter: ";

    char input;
    cin >> input;

    while(tolower(input) != 'd' && tolower(input) != 'q') {
        cout << "Enter a valid option: \n"
             << "Enter: ";
        cin >> input;
    }
    if(tolower(input) == 'd') {
        ClearScreen();
        newRound();
    }
    else {
        exitGame();
    }
    cin.ignore();
}

void BlackJack::menu()
{
    cout << " ********************************\n"
         << " *  h key = hit | s key = stay  *\n"
         << " ********************************\n"
         << " Enter: ";

    char choice;
    cin >> choice;

    switch (tolower(choice)) {
    case 'h':

        playerHit();
        control = true; // Run menu() again.
        break;

    case 's':

        dealerHit();
        hideCard = false; // Player's turn is complete. Show dealer's hand.
        control = false; // menu() terminates.
        break;

    default:

        cout << "\n  Enter a valid option.";
        control = true; // Run menu() again.
        break;
    }

    cout << "\n";
}

void BlackJack::takeBet()
{
    cout << "=======================================================\n"
         << "  Chip values: ";
    set<int>::const_iterator iter;
    for (iter = chips.begin(); iter != chips.end(); iter++) {
        cout << " $" << *iter << " ";
    }

    cout << "\n\n  Place your bet: ";

    int bet;
    cin >> bet;
    cout << "\n";

    auto check = chips.find(bet);
    // Loop if invalid bet is made
    while(check == chips.end()) {
        cout << "  Enter a valid chip value: ";
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
    cout << "  Player's Hand: "
         << "-" << setw(2) << player.getHandTotal() << "- ";
    player.showHand();

    cout << "\n  Dealer's Hand: ";
    if(hideCard) {
        cout << "-??- ";
        dealer.hideCard();   
    }
    else {
        cout << "-" << setw(2) << dealer.getHandTotal() << "- ";
        dealer.showHand();
    }
    cout << "\n\n";
}

void BlackJack::playerHit()
{
    player.pushCard(deck.popCard());

    if(player.getHandTotal() > 21) {
        cout << "\n  Player bust! ";
        hideCard = false;
        dealerWins();
    }
}

void BlackJack::dealerHit()
{
    while(dealer.getHandTotal() < 17) {
        dealer.pushCard(deck.popCard());
    }
    if(dealer.getHandTotal() > 21) {
        cout << "\n  Dealer bust! ";
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
        cout << "  PUSH!\n\n";
        //newRound();
    }
}

void BlackJack::playerWins()
{
    cout << "  Player wins!\n";
    player.win();
    //newRound();
}

void BlackJack::dealerWins()
{
    cout << "  Dealer wins.\n";
    player.lose();
    //newRound();
}
