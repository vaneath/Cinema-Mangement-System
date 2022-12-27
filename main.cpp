#include <iostream>
#include<conio.h>
#include <cwchar>

#include "header-file/color.h"
#include "header-file/registration.h"
#include "header-file/login.h"
#include "header-file/menu.h"
#include "header-file/About_us.h"

using namespace std;

void mainDispaly()
{
    int Set[]={12,15,15,6};      //15 default value, last index use for block color
    int counter=0, BlockSign=254;
    char key;

    system("cls");
    while(1)
    {
        gotoXY(19, 1);
        color(11);
        cout<<"*** ";
        color(3);
        cout<<"CADT CINEMA";
        color(11);
        cout<<" ***";

            gotoXY(17,0);           //box outside cadt cinema;       left upper corner
            cout<<char(201);
            gotoXY(17,1);
            cout<<char(186);
            gotoXY(17,2);                                //left lower corner
            cout<<char(200);

            for(int i=18; i<39; i++)                     //straight upper horizontal line
            {
                gotoXY(i,0);
                cout<<char(205);
            }

            for(int i=18; i<39; i++)                     //straight lower horizontal line
            {
                gotoXY(i,2);
                cout<<char(205);
            }

            gotoXY(39,0);                               //Right upper corner
            cout<<char(187);
            gotoXY(39,1);
            cout<<char(186);
            gotoXY(39,2);
            cout<<char(188);                             //Right lower corner

        gotoXY(9, 4);
        color(Set[3]);
        cout<<char(BlockSign);
        color(Set[0]);
        cout << "\t\t  Login";
        gotoXY(47, 4);
        color(Set[3]);
        cout<<char(BlockSign);

        gotoXY(9, 6);
        color(Set[3]);
        cout<<char(BlockSign);
        color(Set[1]);
        cout << "\t\t Register";
        gotoXY(47, 6);
        color(Set[3]);
        cout<<char(BlockSign);

        gotoXY(9, 8);
        color(Set[3]);
        cout<<char(BlockSign);
        color(Set[2]);
        cout << "   About Cinema Management System";
        gotoXY(47, 8);
        color(Set[3]);
        cout<<char(BlockSign);

        key = _getch();

        Set[0]=15; //reset color
        Set[1]=15;
        Set[2]=15;

        if(key == 72 && (counter >= 1 && counter <= 2)) //72 for up arrow
        {
            counter --;
            Set[counter]=12;
            //cout<<counter;
        }

        else if(key == 80 && (counter >= 0 && counter <= 1)) //80 for down arrow
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
                mainDispaly();
                break;
            }
            if(counter==1)
            {
                system("cls");
                mainRegister();
                mainDispaly();
                break;
            }
            if(counter==2)
            {
                system("cls");
                AboutUs();
                mainDispaly();
                break;
            }
        }
    }
}

main()
{
    mainDispaly();
    return 0;
}
