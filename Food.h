#include<iostream>
#include<conio.h>
using namespace std;

void FoodMenu()
{
    int Set[]={12,15,15,15,15,15,15,15,6}; //15 default white color, last index use for movie's star color
    int counter=0, box=207;
    char key;
    bool running=true;

    while(running)
    {
        gotoXY(10,1);
        color(11);
        cout<<"*** ";
        color(3);
        cout<<"Food";
        color(11);
        cout<<" ***";
        color(15);
        cout<<"\t\tSize\t\tPrice";

        /*gotoXY(32,3);
        color(15);
        cout<<"Size\t\tPrice";*/

        gotoXY(10,3);
        color(Set[8]);
        cout<<char(box);
        color(Set[0]);
        cout<<" Pop-Corn\t\tM/L\t\t5$/10$";

        gotoXY(10,5);
        color(Set[8]);
        cout<<char(box);
        color(Set[1]);
        cout<<" Sausage\t\tM/L\t\t2$/4$";

        gotoXY(10,7);
        color(Set[8]);
        cout<<char(box);
        color(Set[2]);
        cout<<" Dry-Beef\t\t\t\t3$";

        gotoXY(10,9);
        color(Set[8]);
        cout<<char(box);
        color(Set[3]);
        cout<<" Tao-kae-Noi\t\t\t\t2.5$";

        gotoXY(10,12);                       //**** DRINK ***
        color(11);
        cout<<"*** ";
        color(3);
        cout<<"Drink";
        color(11);
        cout<<" ***";

        gotoXY(10,14);
        color(Set[8]);
        cout<<char(box);
        color(Set[4]);
        cout<<" Coke\t\tM/L\t\t1.5$/2.5$";

        gotoXY(10,16);
        color(Set[8]);
        cout<<char(box);
        color(Set[5]);
        cout<<" Fanta\t\tM/L\t\t1.5$/2.5$";

        gotoXY(10,18);
        color(Set[8]);
        cout<<char(box);
        color(Set[6]);
        cout<<" Bottle-of-Water\t\t\t0.8$";

        gotoXY(10,21);
        color(Set[7]);
        cout<<"Back";

        key = _getch();

        Set[0]=15; //reset color
        Set[1]=15;
        Set[2]=15;
        Set[3]=15;
        Set[4]=15;
        Set[5]=15;
        Set[6]=15;
        Set[7]=15;

        if(key == 72 && (counter >= 1 && counter <= 7)) //72 for up arrow
        {
            counter --;
            Set[counter]=12;
            //cout<<counter;
        }

        else if(key == 80 && (counter >= 0 && counter <= 6)) //80 for down arrow
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
            if(counter==7)
            {
                system("cls");
                break;
            }
        }
    }
}
