#include <ctime>
#include"seat.h"
using namespace std;

/*int getTimeAndModify() {
    // current date/time based on current system
    time_t now = time(NULL);
    tm *ltm = localtime(&now);

    //print various components of tm structure.
    //cout << "Year:" << 1900 + ltm->tm_year<<endl;
    //cout << "Month: "<< 1 + ltm->tm_mon<< endl;
    //cout << "Day: "<< ltm->tm_mday << endl;
    //cout << "Time: "<< ltm->tm_hour;
    //cout << 30+ltm->tm_min << ":";
    //cout << ltm->tm_sec << endl;
}*/


void showtimePrice()
{
    int Set[]={12,15,15,15,15,6}; //15 default white color, last index use for movie's star color
    int counter=0, box=207;
    char key;
    bool running=true;

    time_t now = time(NULL);
    tm *ltm = localtime(&now);      //pointer ltm point to localtime aka now time

    while(running)
    {
        gotoxy(10,1);
        color(11);
        cout<<"*** ";
        color(3);
        cout<<"SHOWTIME";
        color(11);
        cout<<" ***";

                gotoxy(8,0);           //box outside cadt cinema;       left upper corner
                cout<<char(201);
                gotoxy(8,1);
                cout<<char(186);
                gotoxy(8,2);                                //left lower corner
                cout<<char(200);

                for(int i=9; i<27; i++)                     //straight upper horizontal line
                {
                    gotoxy(i,0);
                    cout<<char(205);
                }

                for(int i=9; i<27; i++)                     //straight lower horizontal line
                {
                    gotoxy(i,2);
                    cout<<char(205);
                }

                gotoxy(27,0);                               //Right upper corner
                cout<<char(187);
                gotoxy(27,1);
                cout<<char(186);
                gotoxy(27,2);
                cout<<char(188);                             //Right lower corner

            gotoxy(40,1);
            color(15);
            cout<<"Price";
            gotoxy(55,1);
            cout<<"Type";

        gotoxy(9,4);
        color(11);
        cout<<"*** ";
        color(3);
        cout<<"THEATRE 4";                                          //Hall 4
        color(11);
        cout<<" ***";

        gotoxy(9,6);
        color(Set[5]);
        cout<<char(box);
        color(Set[0]);
        cout<<" "<< (1+ltm->tm_hour)%24 << ":20-" << (3+ltm->tm_hour)%24 << ":10";             // struct tm is in ctime header file, containing a calendar date and time broken down into its components
                                                                                                            // lt->tm_hour only call struct hour, we can modify the hour we call like shown (1 + ltm->tm_hour)
            gotoxy(40,6);                                                                                   // all of those % 24 so the time cannot pass 24h
            cout<<"3.5$";
            gotoxy(55,6);
            cout<<"3D";

        gotoxy(9,8);
        color(Set[5]);
        cout<<char(box);
        color(Set[1]);
        cout<<" "<< (4+ltm->tm_hour)%24 << ":15-" << (6+ltm->tm_hour)%24 << ":15";

            gotoxy(40,8);
            cout<<"3$";
            gotoxy(55,8);
            cout<<"2D";

        gotoxy(9,10);
        color(11);
        cout<<"*** ";
        color(3);
        cout<<"THEATRE 2";                                  //Hall 2
        color(11);
        cout<<" ***";

        gotoxy(9,12);
        color(Set[5]);
        cout<<char(box);
        color(Set[2]);
        cout<<" "<< (2+ltm->tm_hour)%24 << ":45-" << (4+ltm->tm_hour)%24 << ":15";

            gotoxy(40,12);
            cout<<"3$";
            gotoxy(55,12);
            cout<<"2D";

        gotoxy(9,14);
        color(Set[5]);
        cout<<char(box);
        color(Set[3]);
        cout<<" "<< (3+ltm->tm_hour)%24 << ":10-" << (5+ltm->tm_hour)%24 << ":20";

            gotoxy(40,14);
            cout<<"3.5$";
            gotoxy(55,14);
            cout<<"3D";

        gotoxy(10,17);
        color(Set[4]);
        cout<<"Back";

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
                ChooseSeat();
            }
            if(counter==1)
            {
                system("cls");
                ChooseSeat();
            }
            if(counter==2)
            {
                system("cls");
                ChooseSeat();
            }
            if(counter==3)
            {
                system("cls");
                ChooseSeat();
            }
            if(counter==4)
            {
                system("cls");
                break;
            }
        }
    }
}
