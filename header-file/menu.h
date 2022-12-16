#include <iostream>

#define X 50
#define Y 5

using namespace std;

void mainMenu()
{
    system("cls");
    gotoxy(X, Y-2);
    cout << "Hello this is our menu list" << getch() << endl;
}

void mainAdmin()
{
    system("cls");
    gotoxy(X, Y-2);
    cout << "This is admin" << getch() << endl;
}