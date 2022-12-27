#include"conf_food.h"
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

                gotoXY(8,0);           //box outside cadt cinema;       left upper corner
                cout<<char(201);
                gotoXY(8,1);
                cout<<char(186);
                gotoXY(8,2);                                //left lower corner
                cout<<char(200);

                for(int i=9; i<23; i++)                     //straight upper horizontal line
                {
                    gotoXY(i,0);
                    cout<<char(205);
                }

                for(int i=9; i<23; i++)                     //straight lower horizontal line
                {
                    gotoXY(i,2);
                    cout<<char(205);
                }

                gotoXY(23,0);                               //Right upper corner
                cout<<char(187);
                gotoXY(23,1);
                cout<<char(186);
                gotoXY(23,2);
                cout<<char(188);                             //Right lower corner

            gotoXY(35,1);
            color(15);
            cout<<"Size";
            gotoXY(50,1);
            cout<<"Price";

        gotoXY(9,4);
        color(Set[8]);
        cout<<char(box);
        color(Set[0]);
        cout<<" Pop-Corn";

            gotoXY(35,4);
            cout<<"M/L";
            gotoXY(50,4);
            cout<<"5$/10$";

        gotoXY(9,6);
        color(Set[8]);
        cout<<char(box);
        color(Set[1]);
        cout<<" Sausage";

            gotoXY(35,6);
            cout<<"M/L";
            gotoXY(50,6);
            cout<<"2$/4$";

        gotoXY(9,8);
        color(Set[8]);
        cout<<char(box);
        color(Set[2]);
        cout<<" Dry-Beef";

            gotoXY(50,8);
            cout<<"3$";

        gotoXY(9,10);
        color(Set[8]);
        cout<<char(box);
        color(Set[3]);
        cout<<" Tao-kae-Noi";

            gotoXY(50,10);
            cout<<"2.5$";

        gotoXY(10,13);                       //**** DRINK ***
        color(11);
        cout<<"*** ";
        color(3);
        cout<<"Drink";
        color(11);
        cout<<" ***";

                gotoXY(8,12);           //box outside cadt cinema;       left upper corner
                cout<<char(201);
                gotoXY(8,13);
                cout<<char(186);
                gotoXY(8,14);                                //left lower corner
                cout<<char(200);

                for(int i=9; i<24; i++)                     //straight upper horizontal line
                {
                    gotoXY(i,12);
                    cout<<char(205);
                }

                for(int i=9; i<24; i++)                     //straight lower horizontal line
                {
                    gotoXY(i,14);
                    cout<<char(205);
                }

                gotoXY(24,12);                               //Right upper corner
                cout<<char(187);
                gotoXY(24,13);
                cout<<char(186);
                gotoXY(24,14);
                cout<<char(188);                             //Right lower corner

        gotoXY(9,16);
        color(Set[8]);
        cout<<char(box);
        color(Set[4]);
        cout<<" Coke";

            gotoXY(35,16);
            cout<<"M/L";
            gotoXY(50,16);
            cout<<"1.5$/2.5$";

        gotoXY(9,18);
        color(Set[8]);
        cout<<char(box);
        color(Set[5]);
        cout<<" Fanta";

            gotoXY(35,18);
            cout<<"M/L";
            gotoXY(50,18);
            cout<<"1.5$/2.5$";

        gotoXY(9,20);
        color(Set[8]);
        cout<<char(box);
        color(Set[6]);
        cout<<" Bottle-of-Water";

            gotoXY(50,20);
            cout<<"0.8$";

        gotoXY(10,23);
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
                system("cls");
                confirm_food(counter);
            }
            if(counter==1)
            {
                system("cls");
                confirm_food(counter);
            }
            if(counter==2)
            {
                system("cls");
                confirm_food(counter);
            }
            if(counter==3)
            {
                system("cls");
                confirm_food(counter);
            }
            if(counter==4)
            {
                system("cls");
                confirm_food(counter);
            }
            if(counter==5)
            {
                system("cls");
                confirm_food(counter);
            }
            if(counter==6)
            {
                system("cls");
                confirm_food(counter);
            }
            if(counter==7)
            {
                system("cls");
                break;
            }
        }
    }
}
