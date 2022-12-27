using namespace std;
void FoodMenu()
{
    int Set[]={12,15,15,15,15,15,15,15,6}; //15 default white color, last index use for movie's star color
    int counter=0, box=207;
    char key;
    bool running=true;

    while(running)
    {
        gotoxy(10,1);
        color(11);
        cout<<"*** ";
        color(3);
        cout<<"Food";
        color(11);
        cout<<" ***";

                gotoxy(8,0);           //box outside cadt cinema;       left upper corner
                cout<<char(201);
                gotoxy(8,1);
                cout<<char(186);
                gotoxy(8,2);                                //left lower corner
                cout<<char(200);

                for(int i=9; i<23; i++)                     //straight upper horizontal line
                {
                    gotoxy(i,0);
                    cout<<char(205);
                }

                for(int i=9; i<23; i++)                     //straight lower horizontal line
                {
                    gotoxy(i,2);
                    cout<<char(205);
                }

                gotoxy(23,0);                               //Right upper corner
                cout<<char(187);
                gotoxy(23,1);
                cout<<char(186);
                gotoxy(23,2);
                cout<<char(188);                             //Right lower corner

            gotoxy(35,1);
            color(15);
            cout<<"Size";
            gotoxy(50,1);
            cout<<"Price";

        gotoxy(9,4);
        color(Set[8]);
        cout<<char(box);
        color(Set[0]);
        cout<<" Pop-Corn";

            gotoxy(35,4);
            cout<<"M/L";
            gotoxy(50,4);
            cout<<"5$/10$";

        gotoxy(9,6);
        color(Set[8]);
        cout<<char(box);
        color(Set[1]);
        cout<<" Sausage";

            gotoxy(35,6);
            cout<<"M/L";
            gotoxy(50,6);
            cout<<"2$/4$";

        gotoxy(9,8);
        color(Set[8]);
        cout<<char(box);
        color(Set[2]);
        cout<<" Dry-Beef";

            gotoxy(50,8);
            cout<<"3$";

        gotoxy(9,10);
        color(Set[8]);
        cout<<char(box);
        color(Set[3]);
        cout<<" Tao-kae-Noi";

            gotoxy(50,10);
            cout<<"2.5$";

        gotoxy(10,13);                       //**** DRINK ***
        color(11);
        cout<<"*** ";
        color(3);
        cout<<"Drink";
        color(11);
        cout<<" ***";

                gotoxy(8,12);           //box outside cadt cinema;       left upper corner
                cout<<char(201);
                gotoxy(8,13);
                cout<<char(186);
                gotoxy(8,14);                                //left lower corner
                cout<<char(200);

                for(int i=9; i<24; i++)                     //straight upper horizontal line
                {
                    gotoxy(i,12);
                    cout<<char(205);
                }

                for(int i=9; i<24; i++)                     //straight lower horizontal line
                {
                    gotoxy(i,14);
                    cout<<char(205);
                }

                gotoxy(24,12);                               //Right upper corner
                cout<<char(187);
                gotoxy(24,13);
                cout<<char(186);
                gotoxy(24,14);
                cout<<char(188);                             //Right lower corner

        gotoxy(9,16);
        color(Set[8]);
        cout<<char(box);
        color(Set[4]);
        cout<<" Coke";

            gotoxy(35,16);
            cout<<"M/L";
            gotoxy(50,16);
            cout<<"1.5$/2.5$";

        gotoxy(9,18);
        color(Set[8]);
        cout<<char(box);
        color(Set[5]);
        cout<<" Fanta";

            gotoxy(35,18);
            cout<<"M/L";
            gotoxy(50,18);
            cout<<"1.5$/2.5$";

        gotoxy(9,20);
        color(Set[8]);
        cout<<char(box);
        color(Set[6]);
        cout<<" Bottle-of-Water";

            gotoxy(50,20);
            cout<<"0.8$";

        gotoxy(10,23);
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
