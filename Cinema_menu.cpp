#include<iostream>
#include<conio.h>
#include"color.h"
#include"movies.h"
#include"ComingSoon.h"
#include"Food.h"
#include"Setting.h"
using namespace std;

void CinemaMenu()
{
    int Set[]={12,15,15,15,6};      //15 default value, last index use for block color
    int counter=0, BlockSign=254;
    char key;
    bool running=true;

    while(running)
    {
        gotoXY(10,1);
        color(11);
        cout<<"*** ";
        color(3);
        cout<<"CADT CINEMA";
        color(11);
        cout<<" ***";

        gotoXY(10,4);
        color(Set[4]);
        cout<<char(BlockSign);
        color(Set[0]);
        cout<<" View All Available Movie";

        gotoXY(10,6);
        color(Set[4]);
        cout<<char(BlockSign);
        color(Set[1]);
        cout<<" Coming soon";

        gotoXY(10,8);
        color(Set[4]);
        cout<<char(BlockSign);
        color(Set[2]);
        cout<<" Buy Food & Baverage";

        gotoXY(10,10);
        color(Set[4]);
        cout<<char(BlockSign);
        color(Set[3]);
        cout<<" Setting";

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

        else if(key == 80 && (counter >= 0 && counter <= 2)) //80 for down arrow
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
                NowShowing();
            }
            if(counter==1)
            {
                system("cls");
                ComingSoon();
            }
            if(counter==2)
            {
                system("cls");
                FoodMenu();
            }
            if(counter==3)
            {
                system("cls");
                ChangeSetting();
            }
        }
    }
}

main()
{
    CinemaMenu();
    return 0;
}
