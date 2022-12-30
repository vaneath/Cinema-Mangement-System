#include <sstream>
using namespace std;

void CinemaMenu();

void confirm_movie(int h, char v)
{
    int Set[]={12,15};
    int counter=0;
    char key;
    bool running=true;

    stringstream ss;
    ss << v << h;
    string Seat = ss.str();

    while(running)
    {
        gotoxy(10,1);
        color(11);
        cout<<"*** ";
        color(3);
        cout<<"CONFIRM PURCHASE";
        color(11);
        cout<<" ***";

                gotoxy(8,0);           //box outside cadt cinema;       left upper corner
                cout<<char(201);
                gotoxy(8,1);
                cout<<char(186);
                gotoxy(8,2);                                //left lower corner
                cout<<char(200);

                for(int i=9; i<36; i++)                     //straight upper horizontal line
                {
                    gotoxy(i,0);
                    cout<<char(205);
                }

                for(int i=9; i<36; i++)                     //straight lower horizontal line
                {
                    gotoxy(i,2);
                    cout<<char(205);
                }

                gotoxy(35,0);                               //Right upper corner
                cout<<char(187);
                gotoxy(35,1);
                cout<<char(186);
                gotoxy(35,2);
                cout<<char(188);                             //Right lower corner

        gotoxy(9,4);
        color(15);
        cout<<"Name: ";

        gotoxy(9,5);
        cout<<"Seat: "<<Seat;

        gotoxy(9,6);
        cout<<"Total Price: 3$";

        gotoxy(10,8);
        color(Set[0]);
        cout<<"Confirm";

        gotoxy(22,8);
        color(Set[1]);
        cout<<"Back";

        key=_getch();

        Set[0]=15;
        Set[1]=15;

        if(key == 75 && (counter == 1)) //75 for left arrow
        {
            counter --;
            Set[counter]=12;
            //cout<<counter;
        }
        else if(key == 77 && (counter == 0)) //75 for left arrow
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
            if(counter==1)
            {
                system("cls");
                break;
            }
            if(counter==0)
            {
                system("cls");
                gotoxy(50,5);
                color(12);
                cout<<"Purchase Success!";
                getch();
                CinemaMenu();
            }
        }
    }
}
