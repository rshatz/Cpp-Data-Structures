#include "MainMenu.h"

#include <string>
#include <iostream>

MainMenu::MainMenu()
{
    display();
}

void MainMenu::display()
{
    string temp = dealer.dealCard();
    std::cout << temp;
}
