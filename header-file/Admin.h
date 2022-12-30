#include <iostream>
#include <windows.h>
#include <string>
#include <dos.h>
#include <conio.h>
#include <fstream>

using namespace std;

fstream MovieFile;

void snackDisplay();
void ticketDisplay();

int movieScreening;

void readMovie(List *ls)
{
    Node *movie;
    string nowShowing;
    MovieFile.open("Movie.txt", ios::in);
    if (MovieFile.is_open())
    {
        while (getline(MovieFile, nowShowing))
        {
            movie = new Node;
            movie->movie_name = nowShowing;
            if (ls->index == 0)
            {
                ls->head = movie;
                ls->tail = movie;
            }
            else
            {
                ls->tail->next = movie;
                movie->prev = ls->tail;
                ls->tail = movie;
            }
            ls->index = ls->index + 1;
        }
    }
    else
    {
        cout << "File not open\n";
        exit(1);
    }

    MovieFile.close();
}

void readUpcoming(List *ls)
{
    Node *movie;
    string up_coming;
    MovieFile.open("Upcoming.txt", ios::in);
    if (MovieFile.is_open())
    {
        while (getline(MovieFile, up_coming))
        {
            movie = new Node;
            movie->movie_name = up_coming;
            if (ls->index == 0)
            {
                ls->head = movie;
                ls->tail = movie;
            }
            else
            {
                ls->tail->next = movie;
                movie->prev = ls->tail;
                ls->tail = movie;
            }
            ls->index = ls->index + 1;
        }
    }
    else
    {
        cout << "File not open\n";
        exit(1);
    }

    MovieFile.close();
}

void StoreNowShowing(List *ls)
{
    Node *tmp = ls->head;

    MovieFile.open("Movie.txt", ios::out);
    while (tmp != NULL)
    {
        MovieFile << tmp->movie_name << "\t\t\t";
        for (int i = 0; i < tmp->size; i++)
        {
            MovieFile << tmp->timetable[i] << " | ";
        }
        MovieFile << endl;
        tmp = tmp->next;
    }
    MovieFile.close();
}

void Storeupcoming(List *ls)
{
    Node *tmp;
    tmp = ls->head;

    MovieFile.open("Upcoming.txt", ios::out);
    while (tmp != NULL)
    {
        MovieFile << tmp->movie_name << "\t\t\t\t " << tmp->day << "." << tmp->month << "." << tmp->year << endl;
        tmp = tmp->next;
    }
    MovieFile.close();
}

void insertMovie(List *ls, string nowShowing, string ctimetable[])
{
    Node *movie = new Node();

    movie->movie_name = nowShowing;
    movie->size = movieScreening;
    for (int i = 0; i < movieScreening; i++)
    {
        movie->timetable[i] = ctimetable[i];
    }
    // movie->price = Cprice;

    movie->next = NULL;
    movie->prev = NULL;

    if (ls->index == 0)
    {
        ls->head = movie;
    }
    else
    {
        movie->prev = ls->tail;
        ls->tail->next = movie;
    }
    ls->tail = movie;
    ls->index = ls->index + 1;

    StoreNowShowing(ls);
}

void insertUpcoming(List *ls, string Upcoming, int D, int M, int Year)
{
    Node *movie = new Node;
    movie->movie_name = Upcoming;
    movie->day = D;
    movie->month = M;
    movie->year = Year;
    movie->next = NULL;
    movie->prev = NULL;

    if (ls->index == 0)
    {
        ls->head = movie;
    }
    else
    {
        movie->prev = ls->tail;
        ls->tail->next = movie;
    }
    ls->tail = movie;
    ls->index = ls->index + 1;
    Storeupcoming(ls);
}

// void displayTimetable(List *ls)
// {
//     Node *tmp = ls -> head;
//     while (tmp != NULL)
//     {
//         for(int i = 0; i < tmp -> timetable->length(); i++)
//         {
//             cout << tmp->timetable << " | ";
//         }
//         tmp = tmp->next;
//     }
// }

void displayNowShowing(List *ls)
{
    Node *tmp = ls->head;
    cout << "\t\t\t\t\tMoive List:\t\t";
    cout << "Showtime:" << endl;
    MovieFile.open("Movie.txt", ios::in);

    if (!MovieFile.is_open())
    {
        cout << "Unable to open the file." << endl;
        return;
    }

    if (MovieFile.is_open())
    { // checking whether the file is open
        string tp;
        while (getline(MovieFile, tp))
        {                                       // read data from file object and put it into string.
            cout << "\t\t\t\t\t" << tp << "\n"; // print the data of the string
        }
    }
    MovieFile.close();
}

void displayUpcoming(List *ls)
{
    Node *tmp = ls->head;
    cout << "\t\t\t\t\tUpcoming List:\t\t";
    cout << "Release Date:" << endl;
    while (tmp != NULL)
    {

        cout << "\t\t\t\t\t" << tmp->movie_name << "\t\t\t\t " << tmp->day << "." << tmp->month << "." << tmp->year << endl;
        tmp = tmp->next;
    }
}

void deleteMovie(List *ls, string search_name)
{
    int found = 0;
    Node *tmp1, *tmp, *tmp2;
    tmp = ls->head;

    while (tmp != NULL)
    {
        if (tmp->movie_name == search_name)
        { // At the Start
            if (tmp->prev == NULL)
            {
                ls->head = tmp->next;
                delete tmp;
                ls->index = ls->index - 1;
                found = 1;
                break;
            }
            else if (tmp->next == NULL)
            { // At the Tail
                ls->tail = tmp->prev;
                ls->tail->next = NULL;
                delete tmp;
                ls->index = ls->index - 1;
                found = 1;
                break;
            }
            else
            { // In between
                tmp1 = tmp->prev;
                tmp2 = tmp->next;
                tmp1->next = tmp2;
                tmp2->prev = tmp1;
                delete tmp;
                ls->index = ls->index - 1;
                found = 1;
                break;
            }
        }
        tmp = tmp->next;
    }

    if (found == 1)
    {
        cout << "delete successful!" << endl;
        Sleep(1);
    }
    else
    {
        cout << "Information not correct." << endl;
        Sleep(1);
    }
    StoreNowShowing(ls);
}

void deleteUpcoming(List *ls, string search_name)
{
    int found = 0;
    Node *tmp1, *tmp, *tmp2;
    tmp = ls->head;

    while (tmp != NULL)
    {
        if (tmp->movie_name == search_name)
        { // At the Start
            if (tmp->prev == NULL)
            {
                ls->head = tmp->next;
                delete tmp;
                ls->index = ls->index - 1;
                found = 1;
                break;
            }
            else if (tmp->next == NULL)
            { // At the Tail
                ls->tail = tmp->prev;
                ls->tail->next = NULL;
                delete tmp;
                ls->index = ls->index - 1;
                found = 1;
                break;
            }
            else
            { // In between
                tmp1 = tmp->prev;
                tmp2 = tmp->next;
                tmp1->next = tmp2;
                tmp2->prev = tmp1;
                delete tmp;
                ls->index = ls->index - 1;
                found = 1;
                break;
            }
        }
        tmp = tmp->next;
    }

    if (found == 1)
    {
        cout << "delete successful!" << endl;
        Sleep(1);
    }
    else
    {
        cout << "Information not correct." << endl;
        Sleep(1);
    }
    Storeupcoming(ls);
}

void InputNowShowing(List *ls)
{
InputName:
    system("cls");
    string nameMovie;
    string timeAvailible[10];
    int n;
    int inPrice;
    cout << "\t\tPlease enter the movie (No more than 7 character): ";
    getline(cin >> ws, nameMovie);
    // if(nameMovie.length() > 7) goto InputName;
    cout << "\t\tPlease set the price for the of the ticket: ";
    cin >> inPrice;
    cout << "\t\tHow many time do you want the movie put on screening: ";
    cin >> movieScreening;

    for (int i = 0; i < movieScreening; i++)
    {
        cout << "Please enter the timetable for the movie screening : ";
        getline(cin >> ws, timeAvailible[i]);
    }

    insertMovie(ls, nameMovie, timeAvailible);
}

void InputUpcoming(List *ls)
{
    string upcoming_movie;
    string DOR;
    int DAY, MONTH, YEAR;
    cout << "\t\t\t\t\tPlease enter the name of upcoming movie : ";
    getline(cin >> ws, upcoming_movie);
    cout << endl;
    cout << "\t\t\t\t\tPlease enter release date for upcoming movie based on this format DD.MM.YYYY :";
    cin >> DAY >> MONTH >> YEAR;
    cout << endl;
    insertUpcoming(ls, upcoming_movie, DAY, MONTH, YEAR);
}

void MovieMenu()
{
    int Set[] = {12, 15, 15, 15, 15, 15, 15, 15, 6}; // 15 default value, last index use for block color
    int counter = 0, BlockSign = 254;
    char key;
    bool running = true;

    List *NowShowing = createEmptyList();
    List *Upcoming = createEmptyList();

    readMovie(NowShowing);
    readUpcoming(Upcoming);

MainMenu:

    system("cls");
    while (running)
    {
        gotoxy(X + 10, Y);
        color(11);
        cout << "------ ";
        color(3);
        cout << "Movie System ";
        color(11);
        cout << "------";

        gotoxy(X + 5, Y + 2);
        color(Set[8]);
        cout << char(BlockSign);
        color(Set[0]);
        cout << "\t   Add new movie\t  ";
        color(Set[8]);
        cout << char(BlockSign);

        gotoxy(X + 5, Y + 4);
        color(Set[8]);
        cout << char(BlockSign);
        color(Set[1]);
        cout << "\tAdd new upcoming movie\t  ";
        color(Set[8]);
        cout << char(BlockSign);

        gotoxy(X + 5, Y + 6);
        color(Set[8]);
        cout << char(BlockSign);
        color(Set[2]);
        cout << "\tView most popular movie\t  ";
        color(Set[8]);
        cout << char(BlockSign);

        gotoxy(X + 5, Y + 8);
        color(Set[8]);
        cout << char(BlockSign);
        color(Set[3]);
        cout << "\t  View movies list\t  ";
        color(Set[8]);
        cout << char(BlockSign);

        gotoxy(X + 5, Y + 10);
        color(Set[8]);
        cout << char(BlockSign);
        color(Set[4]);
        cout << "\t  View upcoming list\t  ";
        color(Set[8]);
        cout << char(BlockSign);

        gotoxy(X + 5, Y + 12);
        color(Set[8]);
        cout << char(BlockSign);
        color(Set[5]);
        cout << "\t Delete outdated movie\t  ";
        color(Set[8]);
        cout << char(BlockSign);

        gotoxy(X + 5, Y + 14);
        color(Set[8]);
        cout << char(BlockSign);
        color(Set[6]);
        cout << "\t Delete upcoming list\t  ";
        color(Set[8]);
        cout << char(BlockSign);

        gotoxy(X + 20, Y + 20);
        color(Set[7]);
        cout << "Back";

        key = getch();

        Set[0] = 15; // reset color
        Set[1] = 15;
        Set[2] = 15;
        Set[3] = 15;
        Set[4] = 15;
        Set[5] = 15;
        Set[6] = 15;
        Set[7] = 15;

        if (key == 72 && (counter >= 1 && counter <= 8)) // 72 for up arrow
        {
            counter--;
            Set[counter] = 12;
            // cout<<counter;
        }

        else if (key == 80 && (counter >= 0 && counter < 7)) // 80 for down arrow
        {
            counter++;
            Set[counter] = 12;
            //<<counter;
        }

        else
        {
            Set[counter] = 12;
            // cout<<counter;
        }

        if (key == '\r') // carriage return for "Enter" key
        {
            if (counter == 0)
            {
                system("cls");
                InputNowShowing(NowShowing);
                cout << endl;
                cout << "\t\t\t\t\t\tSuccessfully Added";
                cout << "\n\t\t\t\t\t>>>>>>>Pressed any key to go back to main menu<<<<<<<<<<<<<<";
                getch();
                system("cls");
                goto MainMenu;
            }
            if (counter == 1)
            {
                system("cls");
                InputUpcoming(Upcoming);
                cout << endl;
                cout << "\t\t\t\t\t\tSuccessfully Added";
                cout << "\n\t\t\t\t\t>>>>>>>Pressed any key to go back to main menu<<<<<<<<<<<<<<";
                getch();
                system("cls");
                goto MainMenu;
            }
            if (counter == 2)
            {
                system("cls");
                cout << "no data";
                getch();
                break;
            }
            if (counter == 3)
            {
                system("cls");
                cout << "\t\t\t\t\tTHIS IS THE LIST OF MOVIES YOU HAVE ADDED\n";
                displayNowShowing(NowShowing);
                cout << "\n\t\t\t\t\t>>>>>>>Pressed any key to go back to main menu<<<<<<<<<<<<<<" << getch();
                goto MainMenu;
            }
            if (counter == 4)
            {
                system("cls");
                cout << "\t\t\t\t\tTHIS IS THE LIST OF UPCOMING MOVIES YOU HAVE ADDED\n";
                displayUpcoming(Upcoming);
                cout << "\n\t\t\t\t\t>>>>>>>Pressed any key to go back to main menu<<<<<<<<<<<<<<" << getch();
                goto MainMenu;
            }
            if (counter == 5)
            {
                string search;
                char confirm;
            Del_Nowshowing:
                system("cls");
                cout << "this is remaining movie that have been added: \n";
                displayNowShowing(NowShowing);
                cout << "Please input the name of the movie that you want to delete : ";
                getline(cin >> ws, search);
                cout << endl;
                cout << "Do you want to delete this movie[Y|N] :";
                cin >> confirm;
                cout << endl;
                if (confirm == 'Y' || confirm == 'y')
                {
                    deleteMovie(NowShowing, search);
                    cout << "\t\t\t\t\t>>>>>>>Pressed any key to go back to main menu<<<<<<<<<<<<<<";
                    getch();
                    goto MainMenu;
                }
                if (confirm == 'N' || confirm == 'n')
                {
                    goto Del_Nowshowing;
                }
            }
            if (counter == 6)
            {

                string search;
                char confirm;
            Del_upcoming:
                system("cls");
                cout << "this is the remaining upcoming movie: \n";
                displayUpcoming(Upcoming);
                cout << "Please input the name of the upcoming movie to delete it from the list:  ";
                getline(cin >> ws, search);
                cout << endl;
                cout << "Do you want to delete this movie[Y|N] :";
                cin >> confirm;
                cout << endl;
                if (confirm == 'Y' || confirm == 'y')
                {
                    deleteUpcoming(Upcoming, search);
                    cout << "\t\t\t\t\t>>>>>>>Pressed any key to go back to main menu<<<<<<<<<<<<<<";
                    getch();
                    goto MainMenu;
                }
                if (confirm == 'N' || confirm == 'n')
                {
                    goto Del_upcoming;
                }
            }
            if (counter == 7)
            {
                system("cls");
                break;
            }
        }
    }
}

void AdminMenu()
{
    int Set[] = {12, 15, 15, 15, 15, 6}; // 15 default value, last index use for block color
    int counter = 0, BlockSign = 254;
    char key;

    while (1)
    {
    adminMenu:
        system("cls");
        gotoxy(X + 10, Y);
        color(11);
        cout << "------ ";
        color(3);
        cout << "WELCOME";
        color(11);
        cout << " ------";

        gotoxy(X + 5, Y + 2);
        color(Set[5]);
        cout << char(BlockSign);
        color(Set[0]);
        cout << "\t   Movies\t    ";
        color(Set[5]);
        cout << char(BlockSign);

        gotoxy(X + 5, Y + 4);
        color(Set[5]);
        cout << char(BlockSign);
        color(Set[1]);
        cout << "\tFood & Drink\t    ";
        color(Set[5]);
        cout << char(BlockSign);

        gotoxy(X + 5, Y + 6);
        color(Set[5]);
        cout << char(BlockSign);
        color(Set[2]);
        cout << "\t   Tickets\t    ";
        color(Set[5]);
        cout << char(BlockSign);

        gotoxy(X + 5, Y + 8);
        color(Set[5]);
        cout << char(BlockSign);
        color(Set[3]);
        cout << "      Purchase History\t    ";
        color(Set[5]);
        cout << char(BlockSign);

        gotoxy(X + 16, Y + 12);
        color(Set[4]);
        cout << " Log out";

        key = getch();

        Set[0] = 15; // reset color
        Set[1] = 15;
        Set[2] = 15;
        Set[3] = 15;
        Set[4] = 15;

        if (key == 72 && (counter >= 1 && counter <= 4)) // 72 for up arrow
        {
            counter--;
            Set[counter] = 12;
            // cout<<counter;
        }

        else if (key == 80 && (counter >= 0 && counter <= 3)) // 80 for down arrow
        {
            counter++;
            Set[counter] = 12;
            //<<counter;
        }

        else
        {
            Set[counter] = 12;
            // cout<<counter;
        }

        if (key == '\r') // carriage return for "Enter" key
        {
            if (counter == 0)
            {
                MovieMenu();
            }
            if (counter == 1)
            {
                snackDisplay();
            }
            if (counter == 2)
            {
                ticketDisplay();
            }
            if (counter == 3)
            {
                system("cls");
                cout << "No data yet" << getch();
            }
            if (counter == 4)
            {
                string confirm;
                system("cls");
                gotoxy(50, 5);
                cout << "Do you want to log out of admin mode[YES/NO]: ";
                getline(cin >> ws, confirm);

                if (confirm == "YES" || confirm == "yes")
                {
                    gotoxy(45, 8);
                    cout << "Pressed any key to continued" << getch();
                    return;
                }
                else if (confirm == "NO" || confirm == "no")
                {
                    goto adminMenu;
                    break;
                }
            }
        }
    }
}
