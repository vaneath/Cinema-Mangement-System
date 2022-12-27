#include"headers.h"
using namespace std;

void CinemaMenu()
{
    int Set[]={12,15,15,15,15,6};      //15 default value, last index use for block color
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

            gotoXY(8,0);           //box outside cadt cinema;       left upper corner
            cout<<char(201);
            gotoXY(8,1);
            cout<<char(186);
            gotoXY(8,2);                                //left lower corner
            cout<<char(200);

            for(int i=9; i<30; i++)                     //straight upper horizontal line
            {
                gotoXY(i,0);
                cout<<char(205);
            }

            for(int i=9; i<30; i++)                     //straight lower horizontal line
            {
                gotoXY(i,2);
                cout<<char(205);
            }

            gotoXY(30,0);                               //Right upper corner
            cout<<char(187);
            gotoXY(30,1);
            cout<<char(186);
            gotoXY(30,2);
            cout<<char(188);                             //Right lower corner

        gotoXY(9,4);
        color(Set[5]) ;
        cout<<char(BlockSign);
        color(Set[0]);
        cout<<" View All Available Movie";

        gotoXY(9,6);
        color(Set[5]);
        cout<<char(BlockSign);
        color(Set[1]);
        cout<<" Coming soon";

        gotoXY(9,8);
        color(Set[5]);
        cout<<char(BlockSign);
        color(Set[2]);
        cout<<" Buy Food & Baverage";

        gotoXY(9,10);
        color(Set[5]);
        cout<<char(BlockSign);
        color(Set[3]);
        cout<<" Setting";

        gotoXY(9,13);
        color(Set[5]);
        cout<<char(BlockSign);
        color(Set[4]);
        cout<<" Back";

        key = _getch();

        Set[0]=15; //reset color
        Set[1]=15;
        Set[2]=15;
        Set[3]=15;
        Set[4]=15;

        if(key == 72 && (counter >= 1 && counter <= 4)) //72 for up arrow
        {
            counter --;
            Set[counter]=12;
            //cout<<counter;
        }
        else if(key == 80 && (counter >= 0 && counter <= 3)) //80 for down arrow
        {
            counter ++;
            Set[counter]=12;
            //<<counter;
        }
        else if(key == 27) //80 for down arrow
        {
            break;
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
            if(counter==4)
            {
                system("cls");
                break;
            }
        }
    }
}
