using namespace std;
void ChangeSetting()
{
    int Set[]={12,15,15,15,15,6}; //15 default white color
    int counter=0, box=207;
    char key;
    bool running=true;

    while(running)
    {
        gotoxy(10,1);
        color(11);
        cout<<"*** ";
        color(3);
        cout<<"Setting";
        color(11);
        cout<<" ***";

            gotoxy(8,0);           //box outside cadt cinema;       left upper corner
            cout<<char(201);
            gotoxy(8,1);
            cout<<char(186);
            gotoxy(8,2);                                //left lower corner
            cout<<char(200);

            for(int i=9; i<26; i++)                     //straight upper horizontal line
            {
                gotoxy(i,0);
                cout<<char(205);
            }

            for(int i=9; i<26; i++)                     //straight lower horizontal line
            {
                gotoxy(i,2);
                cout<<char(205);
            }

            gotoxy(26,0);                               //Right upper corner
            cout<<char(187);
            gotoxy(26,1);
            cout<<char(186);
            gotoxy(26,2);
            cout<<char(188);                             //Right lower corner

        gotoxy(9,4);
        color(Set[5]);
        cout<<char(box);
        color(Set[0]);
        cout<<" Change Name";

        gotoxy(9,6);
        color(Set[5]);
        cout<<char(box);
        color(Set[1]);
        cout<<" Change Password";

        gotoxy(9,8);
        color(Set[5]);
        cout<<char(box);
        color(Set[2]);
        cout<<" Change Phone-Number";

        gotoxy(9,10);
        color(Set[5]);
        cout<<char(box);
        color(Set[3]);
        cout<<" Change Email";

        gotoxy(10,13);
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
