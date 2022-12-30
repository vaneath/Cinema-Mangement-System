using namespace std;

void CinemaMenu()
{
    int Set[]={12,15,15,6};      //15 default value, last index use for block color
    int counter=0, BlockSign=254;
    char key;
    bool running=true;

    while(running)
    {
        system("cls");
        gotoxy(10,1);
        color(11);
        cout<<"*** ";
        color(3);
        cout<<"CADT CINEMA";
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
        cout<<"Press Esc to go back!";

        gotoxy(9,6);
        color(Set[3]) ;
        cout<<char(BlockSign);
        color(Set[0]);
        cout<<" View All Available Movie";

        gotoxy(9,8);
        color(Set[3]);
        cout<<char(BlockSign);
        color(Set[1]);
        cout<<" Coming soon";

        gotoxy(9,10);
        color(Set[3]);
        cout<<char(BlockSign);
        color(Set[2]);
        cout<<" Buy Food & Baverage";

        key = getch();

        Set[0]=15; //reset color
        Set[1]=15;
        Set[2]=15;

        if(key == 72 && (counter >= 1 && counter <= 2)) //72 for up arrow
        {
            counter --;
            Set[counter]=12;
            //cout<<counter;
        }
        else if(key == 80 && (counter >= 0 && counter <= 1)) //80 for down arrow
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
        }
    }
}
