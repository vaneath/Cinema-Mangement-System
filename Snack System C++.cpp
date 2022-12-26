#include<iostream>
#include<stdlib.h>
#include<unistd.h>
#include<fstream>
#include<sstream>
#include<conio.h>
#include<string>

using namespace std;
fstream fl;

struct Element{
	string data;
	Element *next;
	Element *previous;
};
typedef struct Element Element;

struct List{
	int n;
	Element *head;
	Element *tail;
};
typedef struct List List;

List* createList(){
	List *ls;
	ls = new List();

	ls->n = 0;
	ls->head = NULL;
	ls->tail = NULL;
	return ls;
}

void Food(List *ls){
    system("cls");
	cout<<"\n\t\t\t\t\t\tMenu\n\n";
	Element *tmp;
	tmp = ls->head;
	while(tmp!=NULL){
	cout << "\t\t\t\t\t" << tmp->data <<"\n";
	tmp = tmp->next;
	}
	cout<<"\n";
}

void Drink(List *ls){
    system("cls");
	cout<<"\n\t\t\t\t\t\tMenu\n\n";
	Element *tmp;
	tmp = ls->head;
	while(tmp!=NULL) {
	cout << "\t\t\t\t\t" << tmp->data <<"\n";
	tmp = tmp->next;
	}
	cout<<"\n";
}

void AddToEnd(List * ls, string newData){
	Element *e;
	e = new Element();
	e->data = newData;
	e->next = NULL;
	e->previous = ls->tail;
	if(ls->n == 0){
	ls->head = e;
	}
	if(ls->n!= 0){
	ls->tail->next = e;
	}
	ls->tail = e;
	ls->n = ls->n + 1;
}

void deleteEnd(List *newList)
{
    Element *tempNode = newList -> tail;
    newList -> tail = newList -> tail -> previous;
    if(newList -> n >= 2) newList -> tail -> next = NULL;
    delete tempNode;
    if(newList -> n == 1) newList -> head = NULL;
    newList -> n -= 1;
}

void mainDisplay(){
    system("cls");
    cout<<"\n\t\t\t\t\t\tSnack System:\n\n";
    char snack[3][100] =
    {
    "1. Food Menu",
    "2. Drink Menu",
    "3. Print Receipt"
    };
    for(int i=0; i<3; i++){
        cout<<"\t\t\t\t\t"<<snack[i]<<"\n";
    }
    cout<<"\n";
}

void  mTicket(){
    int hall;
    string seat;

    cout<<"\t\t\t\t\tCustomer movie tickets information:\n\n";
    fl<<"\n\t\t\t\t\tCustomer movie tickets information:\n\n";
    cout<<"\t\t\t\t\tHall: "; cin>>hall;
    fl<<"\t\t\t\t\t\tHall: "<<hall;
    cout<<"\t\t\t\t\tSeat: "; cin>>seat;
    fl<<"\n\t\t\t\t\t\tSeat: "<<seat;
}

void PrintReceipt(string filename){

    system("cls");
    fl.open("Snack-List.txt",ios::in);
    if(!fl){
        cout<<"Can not open file!!!";
    }
    string line, word;
    istringstream iss;
    while(!fl.eof()){
        getline(fl, line);
        cout<<line<<endl;
    }
    cout<<"\n\t\t\t\t\t===================================\n";
    fl.close();
}

main()
{
    fl.open("Snack-List.txt",ios::out);

    List *L1 = createList();
    AddToEnd(L1, "1. Cheesy Corn    \t$2   /Can");
    AddToEnd(L1, "2. Fried Chicken  \t$1,5 /Piece");
    AddToEnd(L1, "3. Chocolate Bread\t$1   /Piece");

    List *L2 = createList();
    AddToEnd(L2, "1. Coca Cola  \t$0,75 /Can");
    AddToEnd(L2, "2. Green Tea  \t$1,5  /Can");
    AddToEnd(L2, "3. Coffee Milk\t$1,75 /Can");
    mainScreen:
    mainDisplay();
    int selectedOpt;
    cout<<"\t\t\t\t\tPlease select(1-3, 0 to exit program):";
    cin>>selectedOpt;


    switch(selectedOpt){
        int cc, fc, cb; //How many each food that we buy for customer
        float ccCost, fcCost, cbCost;
        int coca, gt, cm; ////How many each drink that we buy for customer
        float cocaCost, gtCost, cmCost;
        case 1:
                food:
                Food(L1);

                int fOpt, fOpt1;
                cout<<"\n\t\t\tPlease input(Remove last food(0), Buy for Customer(1), Add foot(2), Back(9): ";
                cin>>fOpt;
                if(fOpt==9) goto mainScreen;
                if(fOpt==2){
                        system("cls");
                        Food(L1);
                        string aF;
                        cout<<"\n\t\t\t\t\tInput numbering, food and price:\n\t"; cin.ignore(); getline(cin, aF);
                        AddToEnd(L1, aF);
                        Food(L1);
                        int removeFood;
                        cout<<"\n\t\t\t\t\tInput(Remove food that u add(0), Continue(1): ";
                        cin>>removeFood;
                        if(removeFood==0){
                        system("cls");
                        deleteEnd(L1);
                        goto food;
                        }
                        if(removeFood==1){
                        system("cls");
                        goto food;
                        }
                }
                if(fOpt==0){
                    system("cls");
                    deleteEnd(L1);
                    goto food;
                }
                if(fOpt==1){

                        int cc1, fc1, cb1;
                        system("cls");
                        Food(L1);
                        mTicket();
                        BuyFood:
                        fl<<mTicket;
                        cout<<"\t\t\t\t\tSelect food(1, 2, 3 or ...): ";
                        cin>>fOpt1;
                        if(fOpt1==1){
                            CC:
                            //float ccCost;
                            cout<<"\t\t\t\t\t1. Cheesy Corn    \t: "; cin>>cc;
                            ccCost= cc*2;
                            fl<<"\n\t\t\t\t\tCheesy Corn    \t: "<<cc<<"\t\t$"<<ccCost;
                            cout<<"\n\t\t\t\t(Select 2 or 3 to buy another food, 8 go to by drink, 0 if it is already): ";
                            cin>>cc1;
                            if(cc1==0){
                                goto mainScreen;
                            }
                            if(cc1==2){
                                cout<<"\n";
                                goto FC;
                            }
                            if(cc1==3){
                                cout<<"\n";
                                goto CB;
                            }
                            if(cc1==8){
                                system("cls");
                                Drink(L2);
                                goto BuyDrink;
                            }
                        }
                        if(fOpt1==2){
                            FC:
                            //float fcCost;
                            cout<<"\t\t\t\t\t2. Fried Chicken  \t: "; cin>>fc;
                            fcCost= fc*1.5;
                            fl<<"\n\t\t\t\t\tFried Chicken  \t: "<<fc<<"\t\t$"<<fcCost;
                            cout<<"\n\t\t\t\t(Select 1 or 3 to buy another food, 8 go to by drink, 0 if it is already): ";
                            cin>>fc1;
                            if(fc1==0){
                                goto mainScreen;
                            }
                            if(fc1==1){
                                cout<<"\n";
                                goto CC;
                            }
                            if(fc1==3){
                                cout<<"\n";
                                goto CB;
                            }
                            if(fc1==8){
                                system("cls");
                                Drink(L2);
                                goto BuyDrink;
                            }
                        }
                        if(fOpt1==3){
                            CB:
                            //float cbCost;
                            cout<<"\t\t\t\t\t3. Chocolate Bread\t: "; cin>>cb;
                            cbCost= cb*1;
                            fl<<"\n\t\t\t\t\tChocolate Bread\t: "<<cb<<"\t\t$"<<cbCost;
                            cout<<"\n\t\t\t\t(Select 1 or 2 to buy another food, 8 go to by drink, 0 if it is already): ";
                            cin>>cb1;
                            if(cb1==0){
                                goto mainScreen;
                            }
                            if(cb1==1){
                                cout<<"\n";
                                goto CC;
                            }
                            if(cb1==2){
                                cout<<"\n";
                                goto FC;
                            }
                            if(cb1==8){
                                system("cls");
                                Drink(L2);
                                goto BuyDrink;
                            }
                        }
                }
                break;
        case 2:
                DRINK:
                Drink(L2);

                int dOpt, dOpt1;
                cout<<"\n\t\t\tPlease input(Remove last drink(0), Buy for Customer(1), Add drink(2), Back(9): ";
                cin>>dOpt;
                if(dOpt==9) goto mainScreen;
                if(dOpt==2){
                        string aD;
                        cout<<"\t\t\t\t\tInput numbering and drink:\n\t\t\t\t\t"; getline(cin, aD);
                        AddToEnd(L2, aD);
                        Drink(L2);
                        int removeDrink;
                        cout<<"\t\t\t\t\tInput(Remove drink that u add(0), Continue(1): ";
                        cin>>removeDrink;
                        if(removeDrink==0){
                        system("cls");
                        deleteEnd(L2);
                        goto DRINK;
                        }
                        if(removeDrink==1){
                        system("cls");
                        goto DRINK;
                        }
                }
                if(dOpt==1){
                        //int coca, gt, cm; (already write it)
                        int coca1, gt1, cm1;
                        system("cls");
                        Drink(L2);
                        mTicket();
                        fl<<mTicket;
                        BuyDrink:
                        cout<<"\t\t\t\t\tSelect food(1, 2, 3 or ...): ";
                        cin>>dOpt1;
                        if(dOpt1==1){
                            COCA:
                            //float cocaCost;
                            cout<<"\t\t\t\t\t1. Coca Cola  \t: "; cin>>coca;
                            cocaCost= coca*0.75;
                            fl<<"\n\t\t\t\t\tCoca Cola    \t: "<<coca<<"\t\t$"<<cocaCost;
                            cout<<"\n\t\t\t(Select 2 or 3 to buy another drink, 8 go to by food, 0 if it is already): ";
                            cin>>coca1;
                            if(coca1==0){
                                goto mainScreen;
                            }
                            if(coca1==2){
                                cout<<"\n";
                                goto GT;
                            }
                            if(coca1==3){
                                cout<<"\n";
                                goto CM;
                            }
                            if(coca1==8){
                                system("cls");
                                Food(L1);
                                goto BuyFood;
                            }
                        }
                        if(dOpt1==2){
                            GT:
                            //float gtCost;
                            cout<<"\t\t\t\t\t2. Green Tea  \t: "; cin>>gt;
                            gtCost= gt*1.5;
                            fl<<"\n\t\t\t\t\tGreen Tea    \t: "<<gt<<"\t\t$"<<gtCost;
                            cout<<"\n\t\t\t\t(Select 1 or 3 to buy another drink, 8 go to by food, 0 if it is already): ";
                            cin>>gt1;
                            if(gt1==0){
                                goto mainScreen;
                            }
                            if(gt1==1){
                                cout<<"\n";
                                goto COCA;
                            }
                            if(gt1==3){
                                cout<<"\n";
                                goto CM;
                            }
                            if(gt1==8){
                                system("cls");
                                Food(L1);
                                goto BuyFood;
                            }
                        }
                        if(dOpt1==3){
                            CM:
                            //float cmCost;
                            cout<<"\t\t\t\t\t3. Coffee Milk\t: "; cin>>cm;
                            cmCost= cm*1.75;
                            fl<<"\n\t\t\t\t\tCoffee Milk  \t: "<<cm<<"\t\t$"<<cmCost;
                            cout<<"\n\t\t\t\t(Select 1 or 2 to buy another drink, 8 go to by food, 0 if it is already): ";
                            cin>>cm1;
                            if(cm1==0){
                                goto mainScreen;
                            }
                            if(cm1==1){
                                cout<<"\n";
                                goto COCA;
                            }
                            if(cm1==2){
                                cout<<"\n";
                                goto GT;
                            }
                            if(cm1==8){
                                system("cls");
                                Food(L1);
                                goto BuyFood;
                            }
                        }
                }
                break;
                fl.close();

        case 3:

                fl.open("Snack-List.txt",ios::in);
                fl.close();
                PrintReceipt("Snack-List.txt");
                float totalCost;
                totalCost = ccCost + fcCost + cbCost + cocaCost + gtCost + cmCost;
                cout<<"\n\t\t\t\t\tTotal Cost\t:\t$"<<totalCost;

                int ol;
                cout<<"\n\n\t\t\t\t\t(Input 9 to go back):";
                cin>>ol;
                if(ol==9) goto mainScreen;
                break;
    }
    cout<<"\n\n";
}
