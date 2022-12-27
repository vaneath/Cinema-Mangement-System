#include <iostream>
#include<conio.h>
#include <cwchar>

#include "header-file/registration.h"
#include "header-file/Admin.h"
#include "header-file/login.h"
#include "header-file/menu.h"
#include "header-file/snack.h"
#include "header-file/ticket.h"

using namespace std;

void mainDisplay()
{
    int Set[]={12,15,15,15,6};      //15 default value, last index use for block color
    int counter=0, BlockSign=254;
    char key;

    system("cls");
    
    while(1)
    {

        gotoxy(X+10, Y);
        color(11);
        cout<<"*** ";
        color(3);
        cout<<"CADT CINEMA";
        color(11);
        cout<<" ***";

        gotoxy(X, Y+2);
        color(Set[4]);
        cout<<char(BlockSign);
        color(Set[0]);
        cout << "\t\t  Login";
        gotoxy(X+38, Y+2);
        color(Set[4]);
        cout<<char(BlockSign);

        gotoxy(X, Y+4);
        color(Set[4]);
        cout<<char(BlockSign);
        color(Set[1]);
        cout << "\t\t Register";
        gotoxy(X+38, Y+4);
        color(Set[4]);
        cout<<char(BlockSign);

        gotoxy(X, Y+6);
        color(Set[4]);
        cout<<char(BlockSign);
        color(Set[2]);
        cout << "   About Cinema Management System";
        gotoxy(X+38, Y+6);
        color(Set[4]);
        cout<<char(BlockSign);

        key = _getch();

        Set[0]=15; //reset color
        Set[1]=15;
        Set[2]=15;
        Set[3]=15;

        if(key == 72 && (counter >= 1 && counter <= 3)) //72 for up arrow
        {
            counter --;
            Set[counter]=12;
            //cout<<counter;
        }

        else if(key == 80 && (counter >= 0 && counter < 2)) //80 for down arrow
        {
            counter ++;
            Set[counter]=12;
            //<<counter;
        }

        else
        {
            Set[counter]=12;
            //cout<<counter;
        }

        if(key == '\r') //carriage return for "Enter" key
        {
            if(counter==0)
            {
                system("cls");
                mainLogin();
                mainDisplay();
                break;
            }
            if(counter==1)
            {
                system("cls");
                mainRegister();
                mainDisplay();
                break;
            }
            if(counter==2)
            {
                system("cls");
                cout << "About us";
                break;
            }
        }
    }
}

main()
{ 
    mainDisplay();
    return 0;
}