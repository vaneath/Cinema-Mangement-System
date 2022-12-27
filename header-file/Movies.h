#include"showtime.h"
using namespace std;
void NowShowing()
{
    int Set[]={12,15,15,15,15,15,15,6}; //15 default white color, last index use for movie's star color
    int counter=0;
    char key;
    bool running=true;

    while(running)
    {
        gotoxy(10,1);
        color(11);
        cout<<"*** ";
        color(3);
        cout<<"NOW SHOWING";
        color(11);
        cout<<" ***";

            gotoxy(8,0);           //box outside cadt cinema;       left upper corner
            cout<<char(201);
            gotoxy(8,1);
            cout<<char(186);
            gotoxy(8,2);                                //left lower corner
            cout<<char(200);

            for(int i=9; i<30; i++)                     //straight upper horizontal line
            {
                gotoxy(i,0);
                cout<<char(205);
            }

            for(int i=9; i<30; i++)                     //straight lower horizontal line
            {
                gotoxy(i,2);
                cout<<char(205);
            }

            gotoxy(30,0);                               //Right upper corner
            cout<<char(187);
            gotoxy(30,1);
            cout<<char(186);
            gotoxy(30,2);
            cout<<char(188);                             //Right lower corner

        gotoxy(9,4);
        color(Set[7]);
        cout<<"* ";
        color(Set[0]);
        cout<<"AVATAR 2";

        gotoxy(9,6);
        color(Set[7]);
        cout<<"* ";
        color(Set[1]);
        cout<<"BLACK PANTHER";

        gotoxy(9,8);
        color(Set[7]);
        cout<<"* ";
        color(Set[2]);
        cout<<"AVENGER: END-GAME";

        gotoxy(9,10);
        color(Set[7]);
        cout<<"* ";
        color(Set[3]);
        cout<<"BLACK ADAM";

        gotoxy(9,12);
        color(Set[7]);
        cout<<"* ";
        color(Set[4]);
        cout<<"MORBIUS";

        gotoxy(9,14);
        color(Set[7]);
        cout<<"* ";
        color(Set[5]);
        cout<<"GHOST WRITER 2";

        gotoxy(10,17);
        color(Set[6]);
        cout<<"Back";

        key = _getch();

        Set[0]=15; //reset color
        Set[1]=15;
        Set[2]=15;
        Set[3]=15;
        Set[4]=15;
        Set[5]=15;
        Set[6]=15;

        if(key == 72 && (counter >= 1 && counter <= 6)) //72 for up arrow
        {
            counter --;
            Set[counter]=12;
            //cout<<counter;
        }

        else if(key == 80 && (counter >= 0 && counter <= 5)) //80 for down arrow
        {
            counter ++;
            Set[counter]=12;
            //cout<<counter;
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
                showtimePrice();
            }
            if(counter==1)
            {
                system("cls");
                showtimePrice();
            }
            if(counter==2)
            {
                system("cls");
                showtimePrice();
            }
            if(counter==3)
            {
                system("cls");
                showtimePrice();
            }
            if(counter==4)
            {
                system("cls");
                showtimePrice();
            }
            if(counter==5)
            {
                system("cls");
                showtimePrice();
            }
            if(counter==6)
            {
                system("cls");
                break;
            }
        }
    }
}
