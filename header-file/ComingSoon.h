using namespace std;
void ComingSoon()
{
    char key;
    bool running=true;

    while(running)
    {
        system("cls");
        gotoxy(10,1);
        color(11);
        cout<<"*** ";
        color(3);
        cout<<"UPCOMING MOVIES";
        color(11);
        cout<<" ***";

            gotoxy(8,0);           //box outside cadt cinema;       left upper corner
            cout<<char(201);
            gotoxy(8,1);
            cout<<char(186);
            gotoxy(8,2);                                //left lower corner
            cout<<char(200);

            for(int i=9; i<34; i++)                     //straight upper horizontal line
            {
                gotoxy(i,0);
                cout<<char(205);
            }

            for(int i=9; i<34; i++)                     //straight lower horizontal line
            {
                gotoxy(i,2);
                cout<<char(205);
            }

            gotoxy(34,0);                               //Right upper corner
            cout<<char(187);
            gotoxy(34,1);
            cout<<char(186);
            gotoxy(34,2);
            cout<<char(188);                             //Right lower corner

            gotoxy(8,4);
            cout<<"Press Esc to go back!"<<endl;

        MovieFile.open("Upcoming.txt", ios::in);

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
            color(15);
            cout << tp << endl; //print the data of the string
                
            counter=counter+2;
            }
        }
        MovieFile.close();

        key = _getch();

        if(key == 27) return;
    }
}

