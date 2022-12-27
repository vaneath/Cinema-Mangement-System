using namespace std;

void AboutUs()
{

    gotoXY(36,5);
    cout<<"Team B3"<<endl;
    gotoXY(34,6);
    cout<<"CADT Cinema";

    gotoXY(17,0);           //box outside cadt cinema;       left upper corner
    cout<<char(201);

    for(int i=1; i<11; i++)                 //side straight
    {
        gotoXY(17,i);
        cout<<char(186);
    }

    gotoXY(17,11);                                //left lower corner
    cout<<char(200);

    for(int i=18; i<61; i++)                     //straight upper horizontal line
    {
    gotoXY(i,0);
    cout<<char(205);
    }

    for(int i=18; i<61; i++)                     //straight lower horizontal line
    {
    gotoXY(i,11);
    cout<<char(205);
    }

    gotoXY(61,0);                               //Right upper corner
    cout<<char(187);

    for(int i=1; i<11; i++)                 //side straight
    {
        gotoXY(61,i);
        cout<<char(186);
    }

    gotoXY(61,11);
    cout<<char(188);                             //Right lower corner

    getch();
}
