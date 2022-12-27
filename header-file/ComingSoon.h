using namespace std;
void ComingSoon()
{
    int Set[]={12,6}; //15 default white color, last index use for movie's star color
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

            gotoXY(8,0);           //box outside cadt cinema;       left upper corner
            cout<<char(201);
            gotoXY(8,1);
            cout<<char(186);
            gotoXY(8,2);                                //left lower corner
            cout<<char(200);

            for(int i=9; i<30; i++)                     //straight upper horizontal line
            {
                gotoXY(i,0);
                cout<<char(205);
            }

            for(int i=9; i<30; i++)                     //straight lower horizontal line
            {
                gotoXY(i,2);
                cout<<char(205);
            }

            gotoXY(30,0);                               //Right upper corner
            cout<<char(187);
            gotoXY(30,1);
            cout<<char(186);
            gotoXY(30,2);
            cout<<char(188);                             //Right lower corner

        gotoXY(9,4);
        color(Set[1]);
        cout<<"* ";
        color(15);
        cout<<"Shazam: Fury Of The Gods";

            gotoXY(60,4);
            cout<<"16 MAR 2023";

        gotoXY(9,6);
        color(Set[1]);
        cout<<"* ";
        color(15);
        cout<<"Ant-Man & The Wasp: Quantumania";

            gotoXY(60,6);
            cout<<"23 FEB 2023";

        gotoXY(9,8);
        color(Set[1]);
        cout<<"* ";
        color(15);
        cout<<"Spider-man: Across The Spider-Verse";

            gotoXY(60,8);
            cout<<"02 JUN 2023";

        gotoXY(9,10);
        color(Set[1]);
        cout<<"* ";
        color(15);
        cout<<"John Wick: Chapter 4";

            gotoXY(60,10);
            cout<<"23 MAR 2023";

        gotoXY(9,12);
        color(Set[1]);
        cout<<"* ";
        color(15);
        cout<<"Puss In Boots: The Last Wish";

            gotoXY(60,12);
            cout<<"29 DEC 2022";

        gotoXY(9,14);
        color(Set[1]);
        cout<<"* ";
        color(15);
        cout<<"Mummies";

            gotoXY(60,14);
            cout<<"19 JAN 2023";

        gotoXY(10,17);
        color(Set[0]);
        cout<<"Back";

        key = _getch();

        if(key == '\r') //carriage return for "Enter" key
        {
            if(counter==0)
            {
                system("cls");
                break;
            }
        }
    }
}

