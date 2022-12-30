using namespace std;
void FoodMenu()
{
    int Set[]={12,15,6};
    int counter=0, box=207;
    char key;
    bool running=true;

    while(running)
    {
        system("cls");
        gotoxy(10,1);
        color(11);
        cout<<"*** ";
        color(3);
        cout<<"Food Menu";
        color(11);
        cout<<" ***";

                gotoxy(8,0);           //box outside cadt cinema;       left upper corner
                cout<<char(201);
                gotoxy(8,1);
                cout<<char(186);
                gotoxy(8,2);                                //left lower corner
                cout<<char(200);

                for(int i=9; i<28; i++)                     //straight upper horizontal line
                {
                    gotoxy(i,0);
                    cout<<char(205);
                }

                for(int i=9; i<28; i++)                     //straight lower horizontal line
                {
                    gotoxy(i,2);
                    cout<<char(205);
                }

                gotoxy(28,0);                               //Right upper corner
                cout<<char(187);
                gotoxy(28,1);
                cout<<char(186);
                gotoxy(28,2);
                cout<<char(188);                             //Right lower corner
        
        gotoxy(9,4);
        cout<<"Press Esc to go back!";

        gotoxy(9,6);
        color(Set[2]) ;
        cout<<char(box);
        color(Set[0]);
        cout<<" Buy Food";

        gotoxy(9,8);
        color(Set[2]);
        cout<<char(box);
        color(Set[1]);
        cout<<" Buy Drink";

        key = _getch();

        Set[0]=15; //reset color
        Set[1]=15;

        if(key == 72 && (counter == 1)) //72 for up arrow
        {
            counter--;
            Set[counter]=12;
        }

        else if(key == 80 && (counter == 0)) //80 for down arrow
        {
            counter++;
            Set[counter]=12;
        }

        else if(key == 27) return;

        else
        {
            Set[counter]=12;
        }

        if(key == '\r') //carriage return for "Enter" key
        {
            if(counter==0)
            {
                system("cls");
                BuyFood();
            }
            if(counter==1)
            {
                system("cls");
                BuyDrink();
            }
        }
            
    }
}
