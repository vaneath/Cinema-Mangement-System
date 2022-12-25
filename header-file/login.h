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
    system("cls");
    while(1)
    {
        gotoxy(X-10, Y);
        color(12);
        cout << "Esc";
    
        gotoxy(X+5, Y);
        color(6);
        cout << "*** Login for CADT Cinema ***" << endl;

        Username:
            gotoxy(X+5, Y+2);
            color(15);
            cout << LoginInfoDisplay[0];
            if(getch() == 27) return;
            color(10);
            getline(cin >> ws, loginVar.loginUsername);
        
            gotoxy(X+5, Y+4);
            color(15);
            cout << LoginInfoDisplay[1];
            if(getch() == 27) return;
            color(10);
            getline(cin >> ws, loginVar.loginPassword);
            gotoxy(X+16, Y+4);
            color(10);
            for(int i = 0; i < (loginVar.loginPassword).length(); i++) cout << "*";

        if(checkLoginInfo() == false)
        {
            gotoxy(X+16, Y+2);
            for(int i = 0; i < (loginVar.loginUsername).length(); i++) cout << " ";
            gotoxy(X+16, Y+4);
            for(int i = 0; i < (loginVar.loginPassword).length(); i++) cout << " ";
            gotoxy(X+35, Y+4);
            color(12);
            cout << "No data!";
        }
        else
        {
            gotoxy(X+35, Y+4);
            for(int i = 0; i < 8; i++) cout << " ";
            mainMenu();
            return;
        }

        if(checkLoginAdmin() == false)
        {
            gotoxy(X+16, Y+2);
            for(int i = 0; i < (loginVar.loginUsername).length(); i++) cout << " ";
            gotoxy(X+16, Y+4);
            for(int i = 0; i < (loginVar.loginPassword).length(); i++) cout << " ";
            gotoxy(X+35, Y+4);
            color(12);
            cout << "No data!";
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
