using namespace std;

void confirm_movie()
{
    int Set[]={12,15};
    int counter=0;
    char key;
    bool running=true;

    while(running)
    {
        gotoXY(10,1);
        color(11);
        cout<<"*** ";
        color(3);
        cout<<"CONFIRM PURCHASE";
        color(11);
        cout<<" ***";

                gotoXY(8,0);           //box outside cadt cinema;       left upper corner
                cout<<char(201);
                gotoXY(8,1);
                cout<<char(186);
                gotoXY(8,2);                                //left lower corner
                cout<<char(200);

                for(int i=9; i<36; i++)                     //straight upper horizontal line
                {
                    gotoXY(i,0);
                    cout<<char(205);
                }

                for(int i=9; i<36; i++)                     //straight lower horizontal line
                {
                    gotoXY(i,2);
                    cout<<char(205);
                }

                gotoXY(35,0);                               //Right upper corner
                cout<<char(187);
                gotoXY(35,1);
                cout<<char(186);
                gotoXY(35,2);
                cout<<char(188);                             //Right lower corner

        gotoXY(9,4);
        color(15);
        cout<<"Movie: ";
        gotoXY(9,5);
        cout<<"Time: ";
        gotoXY(9,6);
        cout<<"Seat: ";
        gotoXY(9,7);
        cout<<"Total Price: "<<endl;

        gotoXY(10,10);
        color(Set[0]);
        cout<<"Confirm";

        gotoXY(22,10);
        color(Set[1]);
        cout<<"Back";

        key=_getch();

        Set[0]=15;
        Set[1]=15;

        if(key == 75 && (counter == 1)) //75 for left arrow
        {
            counter --;
            Set[counter]=12;
            //cout<<counter;
        }
        else if(key == 77 && (counter == 0)) //75 for left arrow
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
            if(counter==1)
            {
                system("cls");
                break;
            }
        }
    }
}
