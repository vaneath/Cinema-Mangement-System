#include <iostream>
#include <unordered_set>
#include <sstream>

#define X 50
#define Y 5

using namespace std;

void mainDisplay();
void mainMenu();
void mainAdmin();
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
    char p, password[30];
    int s=0;

    system("cls");
    while(1)
    {
        Username:
            system("cls");
            gotoXY(9, 1);
            color(12);
            cout << "Esc";

            gotoXY(24, 1);
            color(11);
            cout<<"*** ";
            color(3);
            cout<<"LOGIN TO CADT CINEMA";
            color(11);
            cout<<" ***";

                color(11);
                gotoXY(22,0);           //box outside cadt cinema;       left upper corner
                cout<<char(201);
                gotoXY(22,1);
                cout<<char(186);
                gotoXY(22,2);                                //left lower corner
                cout<<char(200);

                for(int i=23; i<54; i++)                     //straight upper horizontal line
                {
                    gotoXY(i,0);
                    cout<<char(205);
                }

                for(int i=23; i<54; i++)                     //straight lower horizontal line
                {
                    gotoXY(i,2);
                    cout<<char(205);
                }

                gotoXY(54,0);                               //Right upper corner
                cout<<char(187);
                gotoXY(54,1);
                cout<<char(186);
                gotoXY(54,2);
                cout<<char(188);                             //Right lower corner

            gotoXY(22, 4);
            color(6);
            cout<<"Press Enter to start input"<<endl;

            gotoXY(22, 6);
            color(15);
            cout << LoginInfoDisplay[0];

            if(getch() == 27) return;

                gotoXY(9, 1);
                color(15);
                cout << "Esc";
                gotoXY(22, 6);
                color(12);
                cout << LoginInfoDisplay[0];
                color(10);
                getline(cin >> ws, loginVar.loginUsername);

            Password:
                gotoXY(22, 6);
                color(15);
                cout << LoginInfoDisplay[0];
                gotoXY(22, 8);
                color(12);
                cout << LoginInfoDisplay[1];
//                if(getch() == 27) return;
                color(10);

                while (p != 13)
                {
                    p = _getch();
                    if (p != 13)
                    {
                    putch('*');
                    password[s]=p;
                    s++;
                    }
                }
            loginVar.loginPassword=password;

        if(checkLoginInfo() == false)
        {
            gotoXY(55, 8);
            color(12);
            cout << "No data!";
            memset(password,0,30);
            s=0;
            p=0;
        }
        else
        {
            gotoXY(55, 4);
            for(int i = 0; i < 8; i++) cout << " ";
            mainMenu();
            return;
        }

        if(checkLoginAdmin() == false)
        {
            color(12);
            cout << "No data!"<<endl;
            memset(password,0,30);
            s=0;
            p=0;
            getch();
            goto Username;
        }
        else
        {
            gotoXY(55, 4);
            for(int i = 0; i < 8; i++) cout << " ";
            mainAdmin();
            return;
        }
    }
    return;
}
