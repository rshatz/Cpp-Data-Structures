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
    }

    checkWin();
    newDeal();
}

void BlackJack::newDeal()
{
    player.clearHand();
    dealer.clearHand();
    hideCard = true;

    if(!player.getBalance()) {
        cout << "Sorry you are out of funds. Game Over.\n";
        exitGame();
    }

    cout << "           *********************************\n"
         << "           *  d key = deal | q key = quit  *\n"
         << "           *********************************\n"
         << "           Enter: ";

    char input;
    cin >> input;

    while(tolower(input) != 'd' && tolower(input) != 'q') {
        cout << "Enter a valid option: \n"
             << "Enter: ";
        cin >> input;
    }
    if(tolower(input) == 'd') {
        ClearScreen();
        control = true; // Run menu() again.
        newRound();
    }
    else {
        exitGame();
    }
}

void BlackJack::menu()
{
    cout << "           ********************************\n"
         << "           *  h key = hit | s key = stay  *\n"
         << "           ********************************\n"
         << "           Enter: ";

    char choice;
    cin >> choice;

    switch (tolower(choice)) {
    case 'h':

        playerHit();
        showCards();
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
    cout << "  -----------------------------------------------------\n"
         << "  |                 $$$ BLACKJACK $$$                 |\n"
         << "  -----------------------------------------------------\n\n"
         << "       Your Account:   $" << player.getBalance() << ".\n"
         << "       Place your bet: $";

    string bet;
    cin >> bet;

    while(!validateBet(bet)) {
        cin >> bet;
    }
    player.placeBet(stoi(bet));
}

bool BlackJack::validateBet(const string bet)
{
    bool is_digit = std::all_of(bet.begin(), bet.end(), ::isdigit);

    while(!is_digit || stoi(bet) > player.getBalance()) {
        if(!is_digit) {
            cout << "       Enter a numerical bet: $";
            return false;
        }
        else {
            cout << "       You do not have sufficient funds to cover that bet.\n"
                 << "       Enter a valid bet: $";
            return false;
        }
    }
    return true;
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
    cout << "\n  _____________________________________________________\n\n";
    cout << "           Player's Hand: "
         << "-" << setw(2) << player.getHandTotal() << "- ";
    player.showHand();

    cout << "\n           Dealer's Hand: ";
    if(hideCard) {
        cout << "-??- ";
        dealer.hideCard();
    }
    else {
        cout << "-" << setw(2) << dealer.getHandTotal() << "- ";
        dealer.showHand();
    }
    cout << "\n  _____________________________________________________\n\n";
}

void BlackJack::playerHit()
{
    player.pushCard(deck.popCard());

    if(player.getHandTotal() > 21) {
        cout << "\n     Player bust! ";
        dealerWins();
    }
}

void BlackJack::dealerHit()
{
    while(dealer.getHandTotal() < 17) {
        dealer.pushCard(deck.popCard());
    }
    if(dealer.getHandTotal() > 21) {
        cout << "\n     Dealer bust! ";
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
        cout << "       PUSH!\n\n";
        showCards();
        newDeal();
    }
}

void BlackJack::playerWins()
{
    cout << "       Player wins!\n";
    hideCard = false;
    showCards();
    player.win();
    newDeal();
}

void BlackJack::dealerWins()
{
    cout << "       Dealer wins.\n";
    hideCard = false;
    showCards();
    player.lose();
    newDeal();
}
