using namespace std;
void ChooseSeat()
{
    int BlockSign=254, hor=16, ver=7;
    char key;
    bool running=true;

    while(running)
    {
        system("cls");
        gotoxy(10,1);
        color(11);
        cout<<"*** ";
        color(3);
        cout<<"SELECT SEAT";
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

        int j=7;
        for(int i=65; i<73; i++)        //cout A to H row order
        {
            gotoxy(9,j);
            color(15);
            cout<<char(i)<<endl;
            j+=2;
        }


        j=16;
        for(int i=1; i<10; i++)        // cout 1 to 8 column order
        {
            gotoxy(j,4);
            color(15);
            cout<<i<<endl;
            j+=3;
        }


        for(int i=7; i<22; i+=2)                    //veritcal
        {
            for(int j=16; j<41; j+=3)                  //horizontal
            {
                if(j==hor && i==ver)
                {
                    gotoxy(j,i);
                    color(12);
                    cout<<char(BlockSign);
                }
                else
                {
                    gotoxy(j,i);
                    color(15);
                    cout<<char(BlockSign);
                }
            }
            cout<<endl;
        }

        if(ver==23)
        {
            gotoxy(26,24);
            color(12);
            cout<<"Back";
        }
        else
        {
            gotoxy(26,24);
            color(15);
            cout<<"Back";
        }

        key = _getch();

        if(key == 72 && (ver >= 9 && ver <= 23)) //72 for up arrow                     (hor >= 30 && hor <= 41)
        {
            ver-=2;
        }

        else if(key == 80 && (ver >= 7 && ver <= 21)) //80 for down arrow
        {
            ver+=2;
        }
        else if(key == 75 && (hor >= 19 && hor <= 40)) //80 for left arrow
        {
            hor-=3;
        }
        else if(key == 77 && (hor >= 16 && hor <= 37)) //80 for right arrow
        {
            hor+=3;
        }


        if(key == '\r')
        {
            if(ver==23)
            {
                system("cls");
                break;
            }

            if(hor<=40 && ver<= 23)
            {
                system("cls");
                confirm_movie();
            }
        }
    }
}
