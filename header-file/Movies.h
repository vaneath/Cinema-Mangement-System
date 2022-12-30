using namespace std;
void NowShowing()
{
    int ver=6, n=0;
    char key;
    bool running=true;

    while(running)
    {
        system("cls");
        gotoxy(10,1);
        color(11);
        cout<<"*** ";
        color(3);
        cout<<"NOW SHOWING";
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

            gotoxy(8,4);
            cout<<"Press Esc to go back!"<<endl;

        MovieFile.open("Movie.txt", ios::in);

        if(!MovieFile.is_open())
            {
            cout<<"Unable to open the file."<<endl;
            return;
            }

        if (MovieFile.is_open()){   //checking whether the file is open
            string tp;
            int counter=6;
            
            while(getline(MovieFile, tp)){ //read data from file object and put it into string.
            gotoxy(9,counter);
            color(6);
            cout<<"* ";

            if(counter==ver)
                {
                    color(12);
                    cout << tp << endl; //print the data of the string
                }

            else
                {
                    color(15);
                    cout << tp << endl; //print the data of the string
                }
            counter=counter+2;
            }
            n=counter;
        }
        MovieFile.close();

        key = _getch();

        if(key == 72 && (ver >= 8 && ver <= (n-2))) //72 for up arrow
        {
            ver=ver-2;
            color(12);
        }

        else if(key == 80 && (ver >= 6 && ver <= (n-4))) //80 for down arrow
        {
            ver=ver+2;
            color(12);
        }

        else if(key == 27) return;


        if(key == '\r') //carriage return for "Enter" key
        {
            system("cls");
            ChooseSeat();
        }
    }
}
