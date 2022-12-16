#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <windows.h>

#define X 50
#define Y 5
#define SIZE 10

using namespace std;

void addRegisterToFile();
void mainLogin();

void color(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoxy(short x, short y)
{
    COORD coord = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

struct Node
{
    string fullName;
    string userName;
    string dateOfBirth;
    string phone;
    string gmail;
    string password;

    Node *next;
};

struct List
{
    int index;
    Node *head;
    Node *tail;
};

List *createEmptyList()
{
    List *newList = new List();

    newList -> index = 0;
    newList -> head = NULL;
    newList -> tail = NULL;

    return newList;
}

string registerDisplay[7] = {
    "Fullname : ",
    "Username : ",
    "Date of birth (Day Month Year) : ",
    "Phone : ", // 8 char     
    "Email : ", // 8 char
    "Password : ", // 11 char
    "Confirm Password : " // 20 char
};
                
struct registerVariableList
{
    string registerFullname,
           registerUsername,
           registerDOB,
           registerPhone,
           registerGmail,
           registerPassword,
           registerConfirmPassword;
    List *RegisterList[SIZE];
} registerVar;

void enqueue(List *newList)
{
    Node *newNode = new Node();

    newNode -> fullName = registerVar.registerFullname;
    newNode -> userName = registerVar.registerUsername;
    newNode -> dateOfBirth = registerVar.registerDOB;
    newNode -> phone = registerVar.registerPhone;
    newNode -> gmail = registerVar.registerGmail;
    newNode -> password = registerVar.registerPassword;

    if(newList -> index == 0) newList -> head = newNode;
    else newList -> tail -> next = newNode;

    newList -> tail = newNode;
    newList -> index += 1;

    addRegisterToFile();
}

void initListOfArray()
{
    for(int i = 0; i < SIZE; i++)
    {
        registerVar.RegisterList[i] = createEmptyList();
    }
}

int hashFunction(string userName)
{
    char eachChar;
    int index = 0;

    for(int i = 0; i < userName.length(); i++)
    {
        eachChar = int(userName[i]);
        index += eachChar;
    }
    return index % 10;
}

void addDataToRegisterTable()
{
    int index = hashFunction(registerVar.registerUsername);

    enqueue(registerVar.RegisterList[index]);
}

bool checkPhone()
{
    bool result = true;
    for(int i = 0; i < (registerVar.registerPhone).length(); i++)
    {
        if(int(registerVar.registerPhone[i]) < 48 || int(registerVar.registerPhone[i]) > 57 || (registerVar.registerPhone).length() != 9)
        {
            result = false;
            break;
        }
    }
    return result;
}

bool checkGmail()
{
    bool result = true;
    int gmailLength = (registerVar.registerGmail).length();

    string standardGmail = "@gmail.com";

    if( gmailLength < 14) result = false;
    else
    {
        for(int i = 0; i < 10; i++)
        {
            if(registerVar.registerGmail[++gmailLength - 11] != standardGmail[i]) result = false;
        }
    }
    return result;
}

bool checkPassword()
{
    bool result = true;

    if((registerVar.registerPassword).length() < 5) result = false;

    return result;
}

bool confirmPassword()
{
    bool result = true;

    if(registerVar.registerConfirmPassword != registerVar.registerPassword) result = false;

    return result;
}

void mainRegister()
{
    initListOfArray();
    system("cls");

    gotoxy(X-10, Y);
    color(12);
    cout << "Esc";

    gotoxy(X+3, Y);
    color(6);
    cout << "*** Register for CADT Cinema ***" << endl;

    Fullname:
        gotoxy(X, Y+2);
        color(15);
        cout << registerDisplay[0];
        if(getch() == 27) return;
        color(10);
        getline(cin >> ws, registerVar.registerFullname);
    Username:
        gotoxy(X, Y+4);
        color(15);
        cout << registerDisplay[1];
        if(getch() == 27) return;
        color(10);
        getline(cin >> ws, registerVar.registerUsername);
    DOB:
        gotoxy(X, Y+6);
        color(15);
        cout << registerDisplay[2];
        if(getch() == 27) return;
        color(10);
        getline(cin >> ws, registerVar.registerDOB);
    Phone:
        gotoxy(X, Y+8);
        color(15);
        cout << registerDisplay[3];
        if(getch() == 27) return;
        color(10);
        getline(cin >> ws, registerVar.registerPhone);
        if(checkPhone() == false)
        {
            gotoxy(X+8, Y+8);
            for(int i = 0; i < (registerVar.registerPhone).length(); i++) cout << " ";
            gotoxy(X+30, Y+8);
            color(12);
            cout <<"Invalid!";
            goto Phone;
        }
        else
        {
            gotoxy(X+30, Y+8);
            for(int i = 0; i < 8; i++) cout << " ";
        }
    Gmail:
        gotoxy(X, Y+10);
        color(15);
        cout << registerDisplay[4];
        if(getch() == 27) return;
        color(10);
        getline(cin >> ws, registerVar.registerGmail);
        if(checkGmail() == false)
        {
            gotoxy(X+8, Y+10);
            for(int i = 0; i < (registerVar.registerGmail).length(); i++) cout << " ";
            gotoxy(X+35, Y+10);
            color(12);
            cout <<"Invalid!";
            goto Gmail;
        }
        else
        {
            gotoxy(X+35, Y+10);
            for(int i = 0; i < 8; i++) cout << " ";
        }
    Password:
        gotoxy(X, Y+12);
        color(15);
        cout << registerDisplay[5];
        if(getch() == 27) return;
        color(10);
        getline(cin >> ws, registerVar.registerPassword);
        if(checkPassword() == false)
        {
            gotoxy(X+11, Y+12);
            for(int i = 0; i < (registerVar.registerPassword).length(); i++) cout << " ";
            gotoxy(X+35, Y+12);
            color(12);
            cout <<"Too Short!";
            goto Password;
        }
        else
        {   gotoxy(X+11, Y+12);
            for(int i = 0; i < (registerVar.registerPassword).length(); i++) cout << "*";
            gotoxy(X+35, Y+12);
            for(int i = 0; i < 10; i++) cout << " ";
        }
    ConfirmPassword:
        gotoxy(X, Y+14);
        color(15);
        cout << registerDisplay[6];
        if(getch() == 27) return;
        color(10);
        getline(cin >> ws, registerVar.registerConfirmPassword);
        if(confirmPassword() == false)
        {
            gotoxy(X+19, Y+14);
            for(int i = 0; i < (registerVar.registerConfirmPassword).length(); i++) cout << " ";
            gotoxy(X+35, Y+14);
            color(12);
            cout <<"Incorrect!";
            goto ConfirmPassword;
        }
        else
        {   gotoxy(X+19, Y+14);
            for(int i = 0; i < (registerVar.registerPassword).length(); i++) cout << "*";
            gotoxy(X+35, Y+14);
            for(int i = 0; i < 10; i++) cout << " ";
        }
    Comfirmation:
        int Set[]={10,15};      //15 default value, last index use for block color
        int counter=0, BlockSign=254;
        char key;

        while(1)
        {
            gotoxy(X, Y+16);
            color(15);
            cout << "Register now?";

            gotoxy(X+25, Y+16);
            color(Set[0]);
            cout << "Yes";

            gotoxy(X+30, Y+16);
            color(Set[1]);
            cout << "No" << endl;

            key = _getch();

            Set[0]=15; //reset color
            Set[1]=15;

            if(key == 75 && (counter == 1)) //72 for up arrow
            {
                counter --;
                Set[counter]=10;
                //cout<<counter;
            }
            else if(key == 77 && (counter == 0)) //80 for down arrow
            {
                counter ++;
                Set[counter]=12;
                //<<counter;
            }
            else if(key == 75)
            {
                Set[counter]=10;
            }
            else if(key == 77)
            {
                Set[counter]=12;
            }

            if(key == '\r') //carriage return for "Enter" key
            {
                if(counter==0)
                {
                    system("cls");     
                    addDataToRegisterTable();
                    mainLogin();
                    break;
                }
                if(counter==1)
                {
                    mainRegister();
                    break;
                }
            }
        }
}

void addRegisterToFile()
{
    for(int i = 0; i < 10; i++)
    {
        Node *tempNode = registerVar.RegisterList[i] -> head;

        fstream registerFile;

        registerFile.open("Registration.txt", ios::app);

        while (tempNode != NULL)
        { 
            registerFile << tempNode -> userName << " ";
            registerFile << tempNode -> password << " ";
            registerFile << tempNode -> fullName << " ";
            registerFile << tempNode -> dateOfBirth << " ";
            registerFile << tempNode -> phone << " ";
            registerFile << tempNode -> gmail << " ";
            registerFile << endl;
            tempNode = tempNode -> next;
        }
        registerFile.close();
    }
}

