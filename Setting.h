#include<iostream>
#include<conio.h>
using namespace std;

void ChangeSetting()
{
    int Set[]={12,15,15,15,15,6}; //15 default white color
    int counter=0, box=207;
    char key;
    bool running=true;

    while(running)
    {
        gotoXY(10,1);
        color(11);
        cout<<"*** ";
        color(3);
        cout<<"Setting";
        color(11);
        cout<<" ***";

        gotoXY(10,4);
        color(Set[5]);
        cout<<char(box);
        color(Set[0]);
        cout<<" Change Name";

        gotoXY(10,6);
        color(Set[5]);
        cout<<char(box);
        color(Set[1]);
        cout<<" Change Password";

        gotoXY(10,8);
        color(Set[5]);
        cout<<char(box);
        color(Set[2]);
        cout<<" Change Phone-Number";

        gotoXY(10,10);
        color(Set[5]);
        cout<<char(box);
        color(Set[3]);
        cout<<" Change Email";

        gotoXY(10,13);
        color(Set[4]);
        cout<<"Back";

        key = _getch();

        Set[0]=15; //reset color
        Set[1]=15; //reset color
        Set[2]=15; //reset color
        Set[3]=15; //reset color
        Set[4]=15; //reset color

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
                system("cls");
                break;
            }
        }
    }
}
