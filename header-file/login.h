#include <iostream>
#include <unordered_set>
#include <sstream>

#define X 50
#define Y 5

using namespace std;

void mainDisplay();
void mainMenu();
void AdminMenu();
void mainRegister();

string LoginInfoDisplay[2] = {
    "Username : ",
    "Password : "
};

struct LoginInfoVariableList
{
    string loginUsername,
           loginPassword;
} loginVar;

bool checkLoginInfo()
{
    bool result = false;
    string line = " ";
    string fileUserName;
    string filePassword;

    fstream loginFile;
    loginFile.open("Registration.txt", ios::in);

    while (getline(loginFile, line)) {
        stringstream iss(line);
        iss >> fileUserName >> filePassword;

        if (loginVar.loginUsername == fileUserName && loginVar.loginPassword == filePassword) {
            result = true;
            break;
        }
    }
    return result;
}

bool checkLoginAdmin()
{
    bool result = false;
    string line = " ";
    string fileUserName;
    string filePassword;

    fstream loginFile;
    loginFile.open("Admin.txt", ios::in);

    while (getline(loginFile, line)) {
        stringstream iss(line);
        iss >> fileUserName >> filePassword;

        if (loginVar.loginUsername == fileUserName && loginVar.loginPassword == filePassword) {
            result = true;
            break;
        }
    }
    return result;
}

void mainLogin()
{
    int i;
    char c, password[30];

    system("cls");
    while(1)
    {
        Username:
            system("cls");
            gotoxy(9, 1);
            color(12);
            cout << "Esc";

            gotoxy(24, 1);
            color(11);
            cout<<"*** ";
            color(3);
            cout<<"LOGIN TO CADT CINEMA";
            color(11);
            cout<<" ***";

            color(11);
            gotoxy(22,0);           //box outside cadt cinema;       left upper corner
            cout<<char(201);
            gotoxy(22,1);
            cout<<char(186);
            gotoxy(22,2);                                //left lower corner
            cout<<char(200);

            for(int i=23; i<54; i++)                     //straight upper horizontal line
            {
                gotoxy(i,0);
                cout<<char(205);
            }

            for(int i=23; i<54; i++)                     //straight lower horizontal line
            {
                gotoxy(i,2);
                cout<<char(205);
            }

            gotoxy(54,0);                               //Right upper corner
            cout<<char(187);
            gotoxy(54,1);
            cout<<char(186);
            gotoxy(54,2);
            cout<<char(188);                             //Right lower corner

            gotoxy(22, 4);
            color(6);
            cout<<"Press ";
            color(12);
            cout << "Enter ";
            color(6);
            cout << "to start input or ";
            color(12);
            cout << "Esc ";
            color(6);
            cout << "to go back" << endl;

            gotoxy(22, 6);
            color(15);
            cout << LoginInfoDisplay[0];

            if(getch() == 27) return;

            gotoxy(9, 1);
            color(15);
            cout << "Esc";
            gotoxy(22, 6);
            color(12);
            cout << LoginInfoDisplay[0];
            color(10);
            getline(cin >> ws, loginVar.loginUsername);

        Password:
            gotoxy(9, 1);
            color(12);
            cout << "Esc";

            gotoxy(22, 8);
            color(15);
            cout << LoginInfoDisplay[1];

            if(getch() == 27) return;

            gotoxy(9, 1);
            color(15);
            cout << "Esc";
            gotoxy(22, 8);
            color(12);
            cout << LoginInfoDisplay[1];
            color(10);

            for(i=0;(c=getch())!='\r';)
            {
                //checking wheter the entered character is backspace  NOTE: ASCII value for '\b' is 8
                if(c!=8)
                {
                    password[i]=c;
                    putch('*');
                    i++;
                }
                else
                {
                    i--;
                    if(i<0)
                        i++;
                    else
                        printf("\b \b"); //implementing the effect of backspace
                }
            }
            password[i]='\0'; //terminating the password string 
            loginVar.loginPassword = password;

        if(checkLoginInfo() == true)
        {
            gotoxy(55, 4);
            for(int i = 0; i < 8; i++) cout << " ";
            CinemaMenu();
            return;
        }

        else if(checkLoginAdmin() == false)
        {
            gotoxy(X+16, Y+2);
            for(int i = 0; i < (loginVar.loginUsername).length(); i++) cout << " ";
            gotoxy(X+16, Y+4);
            for(int i = 0; i < (loginVar.loginPassword).length(); i++) cout << " ";
            gotoxy(55, 8);
            color(12);
            cout << "No data!" << getch();
            memset(password,0,30);
            goto Username;
        }

        else
        {
            gotoxy(X+35, Y+4);
            for(int i = 0; i < 8; i++) cout << " ";
            AdminMenu();
            return;
        }
    }
    return;
}
