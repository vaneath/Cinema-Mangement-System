#include <iostream>
#include "Cinema_menu.h"

using namespace std;

void mainMenu()
{
    system("cls");
    CinemaMenu();
}

void mainAdmin()
{
    system("cls");
    gotoXY(X, Y-2);
    cout << "This is admin" << getch() << endl;
}
