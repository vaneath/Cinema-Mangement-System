#include <iostream>
#include<conio.h>
#include <cwchar>

#include "header-file/registration.h"
#include "header-file/Admin.h"
#include "header-file/login.h"
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

            gotoxy(17,0);           //box outside cadt cinema;       left upper corner
            cout<<char(201);
            gotoxy(17,1);
            cout<<char(186);
            gotoxy(17,2);                                //left lower corner
            cout<<char(200);

            for(int i=18; i<39; i++)                     //straight upper horizontal line
            {
                gotoxy(i,0);
                cout<<char(205);
            }

            for(int i=18; i<39; i++)                     //straight lower horizontal line
            {
                gotoxy(i,2);
                cout<<char(205);
            }

            gotoxy(39,0);                               //Right upper corner
            cout<<char(187);
            gotoxy(39,1);
            cout<<char(186);
            gotoxy(39,2);
            cout<<char(188);                             //Right lower corner

        gotoxy(9, 4);
        color(Set[3]);
        cout<<char(BlockSign);
        color(Set[0]);
        cout << "\t\t  Login";
        gotoxy(47, 4);
        color(Set[3]);
        cout<<char(BlockSign);

        gotoxy(9, 6);
        color(Set[3]);
        cout<<char(BlockSign);
        color(Set[1]);
        cout << "\t\t Register";
        gotoxy(47, 6);
        color(Set[3]);
        cout<<char(BlockSign);

        gotoxy(9, 8);
        color(Set[3]);
        cout<<char(BlockSign);
        color(Set[2]);
        cout << "   About Cinema Management System";
        gotoxy(47, 8);
        color(Set[3]);
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
