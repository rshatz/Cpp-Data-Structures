#ifndef MAINMENU_H
#define MAINMENU_H

#include "Player.h"
#include "Dealer.h"

class MainMenu
{
public:

    MainMenu();
    void display();

private:

    const set<int> chipValue = { 10, 20, 50, 100, 250, 500, 1000 };

    Player player;
    Dealer dealer;
};

#endif // MAINMENU_H
