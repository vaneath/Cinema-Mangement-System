using namespace std;

void AboutUs()
{

    gotoxy(34, 5);
    cout<<"Team B3"<<endl;
    gotoxy(34,6);
    cout<<"CADT Cinema";

    gotoxy(17,0);           //box outside cadt cinema;       left upper corner
    cout<<char(201);

    for(int i=1; i<11; i++)                 //side straight
    {
        gotoxy(17,i);
        cout<<char(186);
    }

    gotoxy(17,11);                                //left lower corner
    cout<<char(200);

    for(int i=18; i<61; i++)                     //straight upper horizontal line
    {
    gotoxy(i,0);
    cout<<char(205);
    }

    for(int i=18; i<61; i++)                     //straight lower horizontal line
    {
    gotoxy(i,11);
    cout<<char(205);
    }

    gotoxy(61,0);                               //Right upper corner
    cout<<char(187);

    for(int i=1; i<11; i++)                 //side straight
    {
        gotoxy(61,i);
        cout<<char(186);
    }

    gotoxy(61,11);
    cout<<char(188);                             //Right lower corner

    getch();
}
