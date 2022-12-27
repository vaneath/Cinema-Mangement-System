
#include<iostream>
#include<conio.h>
using namespace std;

void ShowTIme()
{
    int Set[]={12,15,15,15,15,15,15,6}; //15 default white color, last index use for movie's star color
    int counter=0;
    char key;
    bool running=true;

    while(running)
    {
        gotoXY(10,1);
        color(11);
        cout<<"*** ";
        color(3);
        cout<<"COMING SOON";
        color(11);
        cout<<" ***";

        gotoXY(10,4);
        color(Set[7]);
        cout<<"* ";
        color(Set[0]);
        cout<<"FACES OF ANNE";

        gotoXY(10,6);
        color(Set[7]);
        cout<<"* ";
        color(Set[1]);
        cout<<"ANT-MAN AND THE WASP: QUANTUMANIA";

        gotoXY(10,8);
        color(Set[7]);
        cout<<"* ";
        color(Set[2]);
        cout<<"SPIDER-MAN: ACROSS THE SPIDER-VERSE";

        gotoXY(10,10);
        color(Set[7]);
        cout<<"* ";
        color(Set[3]);
        cout<<"JOHN WICK: CHAPTER 4";

        gotoXY(10,12);
        color(Set[7]);
        cout<<"* ";
        color(Set[4]);
        cout<<"SHAZAM: FURY OF THE GODS";

        gotoXY(10,14);
        color(Set[7]);
        cout<<"* ";
        color(Set[5]);
        cout<<"MUMMIES";

        gotoXY(10,18);
        color(Set[6]);
        cout<<"Back";

        key = _getch();

        Set[0]=15; //reset color;
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

            }
            if(counter==1)
            {

            }
            if(counter==2)
            {

            }
            if(counter==3)
            {

            }
            if(counter==4)
            {

            }
            if(counter==5)
            {

            }
            if(counter==6)
            {
                system("cls");
                break;
            }
        }
    }
}

