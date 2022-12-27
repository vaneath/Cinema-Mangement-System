#include<iostream>
#include<stdlib.h>
<<<<<<< HEAD
#include<unistd.h>
=======
>>>>>>> admin
#include<fstream>
#include<sstream>
#include<conio.h>

using namespace std;

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

List* creatMovieList(){
	List *ls;
	ls = new List();

	ls->n = 0;
	ls->head = NULL;
	ls->tail = NULL;
	return ls;
}

void MovieList(List *ls){
    system("cls");
	cout<<"\n\t\t\t\t\tSet ticket price each movie\n\n";
	Element *tmp;
	tmp = ls->head;
	while(tmp!=NULL){
	cout << "\t\t\t\t" << tmp->data <<"\n";
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

void Ticket(){
    int i, j, k, l;
    string ticket1[9][13]={{"  ", "1 ", "2 ", "3 ", "4 ", "5 ", "6 ", "7 ", "8 ", "9 ", "10", "11", "12"},
                        {"I ", "x ", "x ", "x ", "x ", "x ", "x ", "x ", "x ", "x ", "x ", "x ", "x "},
                        {"H ", "x ", "x ", "x ", "x ", "x ", "x ", "x ", "x ", "x ", "x ", "x ", "x "},
                        {"G ", "x ", "x ", "x ", "x ", "x ", "x ", "x ", "x ", "x ", "x ", "x ", "x "},
                        {"F ", "x ", "x ", "x ", "x ", "x ", "x ", "x ", "x ", "x ", "x ", "x ", "x "},
                        {"E ", "x ", "x ", "x ", "x ", "x ", "x ", "x ", "x ", "x ", "x ", "x ", "x "},
                        {"D ", "x ", "x ", "x ", "x ", "x ", "x ", "x ", "x ", "x ", "x ", "x ", "x "},
                        {"C ", "x ", "x ", "x ", "x ", "x ", "x ", "x ", "x ", "x ", "x ", "x ", "x "},
                        {"B ", "x ", "x ", "x ", "x ", "x ", "x ", "x ", "x ", "x ", "x ", "x ", "x "}};
    for(i=0; i<9; i++){
        cout<<"\n\t\t\t\t\t";
        for(j=0; j<13; j++){
            cout<<ticket1[i][j]<<" ";
        }
        }
    cout<<"\n";
    string ticket2[1][13]={"A", " xx ", "    ", " xxx ", " xx ", " xxx ", "    ", " xx "};
    for(k=0; k<1; k++){
        cout<<"\n\t\t\t\t\t";
        for(l=0; l<13; l++){
            cout<<ticket2[k][l]<<" ";
        }
        }
    cout<<"\n";
    }

void mainDisplay(){
    system("cls");
    cout<<"\n\t\t\t\t\t\tTicket System:\n\n";
    char TicketSystem[2][100] =
    {
    "1. Set ticket price each movie",
    "2. Available ticket"
    };
    for(int k=0; k<2; k++){
        cout<<"\t\t\t\t\t"<<TicketSystem[k]<<"\n";
    }
    cout<<"\n";
}

void Movie1(){
    system("cls");
    cout<<"\n\t\t\t\t\t\t* movie1 *\n\n";
    cout<<"\t\t\t\t\tThis movie show in Hall 4.\n";
    cout<<"\t\t\t\t\tSeat available:\n";
    Ticket();
}

void Movie2(){
    system("cls");
    cout<<"\n\t\t\t\t\t\t* movie2 *\n\n";
    cout<<"\t\t\t\t\tThis movie show in Hall 5.\n";
    cout<<"\t\t\t\t\tSeat available:\n";
    Ticket();
}

void Movie3(){
    system("cls");
    cout<<"\n\t\t\t\t\t\t* movie3 *\n\n";
    cout<<"\t\t\t\t\tThis movie show in Hall 6.\n";
    cout<<"\t\t\t\t\tSeat available:\n";
    Ticket();
}

main(){
    List *TAP = creatMovieList();
    AddToEnd(TAP, "1. Movie1");
    AddToEnd(TAP, "2. Movie2");
    AddToEnd(TAP, "3. Movie3");

    movieMainScreen:
    mainDisplay();
    int OptMovie;
    cout<<"\t\t\t\t\tPlease select(1-2, 0 to exit program): ";
    cin>>OptMovie;

    float cost2DMovie1SingleSeat, cost2DMovie2SingleSeat, cost2DMovie3SingleSeat;
    float cost3DMovie1SingleSeat, cost3DMovie2SingleSeat, cost3DMovie3SingleSeat;

    float cost2DMovie1TwinSeat, cost2DMovie2TwinSeat, cost2DMovie3TwinSeat;
    float cost3DMovie1TwinSeat, cost3DMovie2TwinSeat, cost3DMovie3TwinSeat;

    float cost2DMovie1FamilySeat, cost2DMovie2FamilySeat, cost2DMovie3FamilySeat;
    float cost3DMovie1FamilySeat, cost3DMovie2FamilySeat, cost3DMovie3FamilySeat;

    float storeKindOfMovie1, storeKindOfMovie2, storeKindOfMovie3;

    if(OptMovie==1){
            SETTICKETPRICE:
            MovieList(TAP);
            int OptInSetTicketPrice;
            cout<<"\n\t\t\t\tPlease select number of movie in the list(9 to back): ";
            cin>>OptInSetTicketPrice;
            if(OptInSetTicketPrice==9){
                goto movieMainScreen;
            }
            if(OptInSetTicketPrice==1){
                system("cls");
                cout<<"\n\t\t\t\t\t\t* movie 'ABC' *\n\n";
                //Ticket();
                int OptInMovie1;
                cout<<"\n\t\t\t\t\tPlease select 1 to continue, 9 to go back: ";
                cin>>OptInMovie1;
                if(OptInMovie1==1){
                    system("cls");
                    cout<<"\n\t\t\t\t\t\tSet Ticket Price:";
                    int kindOfMovie1;
                    cout<<"\n\n\t\t\t\t\tWhat kind of this movie?";
                    cout<<"\n\t\t\t\t\t\t1. 2D";
                    cout<<"\n\t\t\t\t\t\t2. 3D";
                    cout<<"\n\t\t\t\t\t\t3. 2D & 3D";
                    cout<<"\n\t\t\t\t\tChose one option: ";
                    cin>>kindOfMovie1;
                    if(kindOfMovie1==1){
                        storeKindOfMovie1=2;
                        cout<<"\n\t\t\t\tPrice of This movie 2D ticket(Single Seat)\t: $";
                        cin>>cost2DMovie1SingleSeat;
                        cout<<"\n\t\t\t\tPrice of This movie 2D ticket(Twin Seat)  \t: $";
                        cin>>cost2DMovie1TwinSeat;
                        cout<<"\n\t\t\t\tPrice of This movie 2D ticket(Family Seat)\t: $";
                        cin>>cost2DMovie1FamilySeat;

                        int done2DMovie1;
                        cout<<"\n\n\t\t\t\t\tSelect 9(Done): ";
                        cin>>done2DMovie1;
                        if(done2DMovie1==9){
                            goto SETTICKETPRICE;
                        }
                    }
                    if(kindOfMovie1==2){
                        storeKindOfMovie1=3;
                        cout<<"\n\t\t\t\tPrice of This movie 3D ticket(Single Seat)\t: $";
                        cin>>cost3DMovie1SingleSeat;
                        cout<<"\n\t\t\t\tPrice of This movie 3D ticket(Twin Seat)  \t: $";
                        cin>>cost3DMovie1TwinSeat;
                        cout<<"\n\t\t\t\tPrice of This movie 3D ticket(Family Seat)\t: $";
                        cin>>cost3DMovie1FamilySeat;

                        int done3DMovie1;
                        cout<<"\n\n\t\t\t\t\tSelect 9(Done): ";
                        cin>>done3DMovie1;
                        if(done3DMovie1==9){
                            goto SETTICKETPRICE;
                        }
                    }
                    if(kindOfMovie1==3){
                        storeKindOfMovie1=2.3;
                        cout<<"\n\t\t\t\tPrice of This movie 2D ticket(Single Seat)\t: $";
                        cin>>cost2DMovie1SingleSeat;
                        cout<<"\n\t\t\t\tPrice of This movie 2D ticket(Twin Seat)  \t: $";
                        cin>>cost2DMovie1TwinSeat;
                        cout<<"\n\t\t\t\tPrice of This movie 2D ticket(Family Seat)\t: $";
                        cin>>cost2DMovie1FamilySeat;

                        cout<<"\n\n\t\t\t\tPrice of This movie 3D ticket(Single Seat)\t: $";
                        cin>>cost3DMovie1SingleSeat;
                        cout<<"\n\t\t\t\tPrice of This movie 3D ticket(Twin Seat)  \t: $";
                        cin>>cost3DMovie1TwinSeat;
                        cout<<"\n\t\t\t\tPrice of This movie 3D ticket(Family Seat)\t: $";
                        cin>>cost3DMovie1FamilySeat;

                        int done2D3DMovie1;
                        cout<<"\n\n\t\t\t\t\tSelect 9(Done): ";
                        cin>>done2D3DMovie1;
                        if(done2D3DMovie1==9){
                            goto SETTICKETPRICE;
                        }
                    }
                }
                if(OptInMovie1==9){
                goto movieMainScreen;
                }
            }
            if(OptInSetTicketPrice==2){
                system("cls");
                cout<<"\n\t\t\t\t\t\t* movie 'Cambodia' *\n\n";
                //Ticket();
                int OptInMovie2;
                cout<<"\n\t\t\t\t\tPlease select 1 to continue, 9 to go back: ";
                cin>>OptInMovie2;
                if(OptInMovie2==1){
                    system("cls");
                    cout<<"\n\t\t\t\t\t\tSet Ticket Price:";
                    int kindOfMovie2;
                    cout<<"\n\n\t\t\t\t\tWhat kind of this movie?";
                    cout<<"\n\t\t\t\t\t\t1. 2D";
                    cout<<"\n\t\t\t\t\t\t2. 3D";
                    cout<<"\n\t\t\t\t\t\t3. 2D & 3D";
                    cout<<"\n\t\t\t\t\tChose one option: ";
                    cin>>kindOfMovie2;
                    if(kindOfMovie2==1){
                        storeKindOfMovie2=2;
                        cout<<"\n\t\t\t\tPrice of This movie 2D ticket(Single Seat)\t: $";
                        cin>>cost2DMovie2SingleSeat;
                        cout<<"\n\t\t\t\tPrice of This movie 2D ticket(Twin Seat)  \t: $";
                        cin>>cost2DMovie2TwinSeat;
                        cout<<"\n\t\t\t\tPrice of This movie 2D ticket(Family Seat)\t: $";
                        cin>>cost2DMovie2FamilySeat;

                        int done2DMovie2;
                        cout<<"\n\n\t\t\t\t\tSelect 9(Done): ";
                        cin>>done2DMovie2;
                        if(done2DMovie2==9){
                            goto SETTICKETPRICE;
                        }
                    }
                    if(kindOfMovie2==2){
                        storeKindOfMovie2=3;
                        cout<<"\n\t\t\t\tPrice of This movie 3D ticket(Single Seat)\t: $";
                        cin>>cost3DMovie2SingleSeat;
                        cout<<"\n\t\t\t\tPrice of This movie 3D ticket(Twin Seat)  \t: $";
                        cin>>cost3DMovie2TwinSeat;
                        cout<<"\n\t\t\t\tPrice of This movie 3D ticket(Family Seat)\t: $";
                        cin>>cost3DMovie2FamilySeat;

                        int done3DMovie2;
                        cout<<"\n\n\t\t\t\t\tSelect 9(Done): ";
                        cin>>done3DMovie2;
                        if(done3DMovie2==9){
                            goto SETTICKETPRICE;
                        }
                    }
                    if(kindOfMovie2==3){
                        storeKindOfMovie2=2.3;
                        cout<<"\n\t\t\t\tPrice of This movie 2D ticket(Single Seat)\t: $";
                        cin>>cost2DMovie2SingleSeat;
                        cout<<"\n\t\t\t\tPrice of This movie 2D ticket(Twin Seat)  \t: $";
                        cin>>cost2DMovie2TwinSeat;
                        cout<<"\n\t\t\t\tPrice of This movie 2D ticket(Family Seat)\t: $";
                        cin>>cost2DMovie2FamilySeat;

                        cout<<"\n\n\t\t\t\tPrice of This movie 3D ticket(Single Seat)\t: $";
                        cin>>cost3DMovie2SingleSeat;
                        cout<<"\n\t\t\t\tPrice of This movie 3D ticket(Twin Seat)  \t: $";
                        cin>>cost3DMovie2TwinSeat;
                        cout<<"\n\t\t\t\tPrice of This movie 3D ticket(Family Seat)\t: $";
                        cin>>cost3DMovie2FamilySeat;

                        int done2D3DMovie2;
                        cout<<"\n\n\t\t\t\t\tSelect 9(Done): ";
                        cin>>done2D3DMovie2;
                        if(done2D3DMovie2==9){
                            goto SETTICKETPRICE;
                        }

                    }
                }
                if(OptInMovie2==9){
                goto movieMainScreen;
            }
            }
            if(OptInSetTicketPrice==3){
                system("cls");
                cout<<"\n\t\t\t\t\t\t* movie 'Anchor' *\n\n";
                //Ticket();
                int OptInMovie3;
                cout<<"\n\t\t\t\t\tPlease select 1 to continue, 9 to go back: ";
                cin>>OptInMovie3;
                if(OptInMovie3==1){
                    system("cls");
                    cout<<"\n\t\t\t\t\t\tSet Ticket Price:";
                    int kindOfMovie3;
                    cout<<"\n\n\t\t\t\t\tWhat kind of this movie?";
                    cout<<"\n\t\t\t\t\t\t1. 2D";
                    cout<<"\n\t\t\t\t\t\t2. 3D";
                    cout<<"\n\t\t\t\t\t\t3. 2D & 3D";
                    cout<<"\n\t\t\t\t\tChose one option: ";
                    cin>>kindOfMovie3;
                    if(kindOfMovie3==1){
                        storeKindOfMovie3=2;
                        cout<<"\n\t\t\t\tPrice of This movie 2D ticket(Single Seat)\t: $";
                        cin>>cost2DMovie3SingleSeat;
                        cout<<"\n\t\t\t\tPrice of This movie 2D ticket(Twin Seat)  \t: $";
                        cin>>cost2DMovie3TwinSeat;
                        cout<<"\n\t\t\t\tPrice of This movie 2D ticket(Family Seat)\t: $";
                        cin>>cost2DMovie3FamilySeat;

                        int done2DMovie3;
                        cout<<"\n\n\t\t\t\t\tSelect 9(Done): ";
                        cin>>done2DMovie3;
                        if(done2DMovie3==9){
                            goto SETTICKETPRICE;
                        }
                    }
                    if(kindOfMovie3==2){
                        storeKindOfMovie3=3;
                        cout<<"\n\t\t\t\tPrice of This movie 3D ticket(Single Seat)\t: $";
                        cin>>cost3DMovie3SingleSeat;
                        cout<<"\n\t\t\t\tPrice of This movie 3D ticket(Twin Seat)  \t: $";
                        cin>>cost3DMovie3TwinSeat;
                        cout<<"\n\t\t\t\tPrice of This movie 3D ticket(Family Seat)\t: $";
                        cin>>cost3DMovie3FamilySeat;

                        int done3DMovie3;
                        cout<<"\n\n\t\t\t\t\tSelect 9(Done): ";
                        cin>>done3DMovie3;
                        if(done3DMovie3==9){
                            goto SETTICKETPRICE;
                        }
                    }
                    if(kindOfMovie3==3){
                        storeKindOfMovie3=2.3;
                        cout<<"\n\t\t\t\tPrice of This movie 2D ticket(Single Seat)\t: $";
                        cin>>cost2DMovie3SingleSeat;
                        cout<<"\n\t\t\t\tPrice of This movie 2D ticket(Twin Seat)  \t: $";
                        cin>>cost2DMovie3TwinSeat;
                        cout<<"\n\t\t\t\tPrice of This movie 2D ticket(Family Seat)\t: $";
                        cin>>cost2DMovie3FamilySeat;

                        cout<<"\n\n\t\t\t\tPrice of This movie 3D ticket(Single Seat)\t: $";
                        cin>>cost3DMovie3SingleSeat;
                        cout<<"\n\t\t\t\tPrice of This movie 3D ticket(Twin Seat)  \t: $";
                        cin>>cost3DMovie3TwinSeat;
                        cout<<"\n\t\t\t\tPrice of This movie 3D ticket(Family Seat)\t: $";
                        cin>>cost3DMovie3FamilySeat;

                        int done2D3DMovie3;
                        cout<<"\n\n\t\t\t\t\tSelect 9(Done): ";
                        cin>>done2D3DMovie3;
                        if(done2D3DMovie3==9){
                            goto SETTICKETPRICE;
                        }
                    }
                }
                if(OptInMovie3==9){
                goto movieMainScreen;
            }
            }
    }
    if(OptMovie==2){
        system("cls");
        MovieList(TAP);
        int selectMovie;
        cout<<"\t\t\t\t\tPlease select movie: ";
        cin>>selectMovie;
        if(selectMovie==1){
            Movie1();
            if(!storeKindOfMovie1){
                cout<<"\n\t\t\t\t\tThe cost of this movie ticket has not set.";
                int goSet1;
                cout<<"\n\t\t\t\t\tPlease enter 9 to go to set movie cost: ";
                cin>>goSet1;
                goto SETTICKETPRICE;
            }
            else{
                cout<<"\n\t\t\t\t\tThis movie show for "<<storeKindOfMovie1<<"D.";
                if(storeKindOfMovie1==2.3){
                    cout<<"\n\t\t\t\t\tCost of Single Seat: $"<<cost2DMovie1SingleSeat;
                    cout<<"\n\t\t\t\t\tCost of Twin Seat  : $"<<cost2DMovie1TwinSeat;
                    cout<<"\n\t\t\t\t\tCost of Family Seat: $"<<cost2DMovie1FamilySeat;
                    cout<<"\n\t\t\t\t\tCost of Single Seat: $"<<cost3DMovie1SingleSeat;
                    cout<<"\n\t\t\t\t\tCost of Twin Seat  : $"<<cost3DMovie1TwinSeat;
                    cout<<"\n\t\t\t\t\tCost of Family Seat: $"<<cost3DMovie1FamilySeat;
                }
                if(storeKindOfMovie1==2){
                    cout<<"\n\t\t\t\t\tCost of Single Seat: $"<<cost2DMovie1SingleSeat;
                    cout<<"\n\t\t\t\t\tCost of Twin Seat  : $"<<cost2DMovie1TwinSeat;
                    cout<<"\n\t\t\t\t\tCost of Family Seat: $"<<cost2DMovie1FamilySeat;
                }
                else{
                    cout<<"\n\t\t\t\t\tCost of Single Seat: $"<<cost3DMovie1SingleSeat;
                    cout<<"\n\t\t\t\t\tCost of Twin Seat  : $"<<cost3DMovie1TwinSeat;
                    cout<<"\n\t\t\t\t\tCost of Family Seat: $"<<cost3DMovie1FamilySeat;
                }
                int OptInSelectMovie1;
                cout<<"\n\n\t\t\t\t\tPlease select 9 to go back: ";
                cin>>OptInSelectMovie1;
                if(OptInSelectMovie1==9){
                    goto movieMainScreen;
                }
            }
        }
        if(selectMovie==2){
            Movie2();
            if(!storeKindOfMovie2){
                cout<<"\n\t\t\t\t\tThe cost of this movie ticket has not set.";
                int goSet2;
                cout<<"\n\t\t\t\t\tPlease enter 9 to go to set movie cost: ";
                cin>>goSet2;
                goto SETTICKETPRICE;
            }
            else{
                cout<<"\n\t\t\t\t\tThis movie show for "<<storeKindOfMovie2<<"D.";
                if(storeKindOfMovie2==2.3){
                    cout<<"\n\t\t\t\t\tCost of Single Seat: $"<<cost2DMovie2SingleSeat;
                    cout<<"\n\t\t\t\t\tCost of Twin Seat  : $"<<cost2DMovie2TwinSeat;
                    cout<<"\n\t\t\t\t\tCost of Family Seat: $"<<cost2DMovie2FamilySeat;
                    cout<<"\n\t\t\t\t\tCost of Single Seat: $"<<cost3DMovie2SingleSeat;
                    cout<<"\n\t\t\t\t\tCost of Twin Seat  : $"<<cost3DMovie2TwinSeat;
                    cout<<"\n\t\t\t\t\tCost of Family Seat: $"<<cost3DMovie2FamilySeat;
                }
                if(storeKindOfMovie2==2){
                    cout<<"\n\t\t\t\t\tCost of Single Seat: $"<<cost2DMovie2SingleSeat;
                    cout<<"\n\t\t\t\t\tCost of Twin Seat  : $"<<cost2DMovie2TwinSeat;
                    cout<<"\n\t\t\t\t\tCost of Family Seat: $"<<cost2DMovie2FamilySeat;
                }
                else{
                    cout<<"\n\t\t\t\t\tCost of Single Seat: $"<<cost3DMovie2SingleSeat;
                    cout<<"\n\t\t\t\t\tCost of Twin Seat  : $"<<cost3DMovie2TwinSeat;
                    cout<<"\n\t\t\t\t\tCost of Family Seat: $"<<cost3DMovie2FamilySeat;
                }
                int OptInSelectMovie2;
                cout<<"\n\n\t\t\t\t\tPlease select 9 to go back: ";
                cin>>OptInSelectMovie2;
                if(OptInSelectMovie2==9){
                    goto movieMainScreen;
                }
            }

        }
        if(selectMovie==3){
            Movie3();
            if(!storeKindOfMovie3){
                cout<<"\n\t\t\t\t\tThe cost of this movie ticket has not set.";
                int goSet3;
                cout<<"\n\t\t\t\t\tPlease enter 9 to go to set movie cost: ";
                cin>>goSet3;
                goto SETTICKETPRICE;
            }
            else{
                cout<<"\n\t\t\t\t\tThis movie show for "<<storeKindOfMovie1<<"D.";
                if(storeKindOfMovie3==2.3){
                    cout<<"\n\t\t\t\t\tCost of Single Seat: $"<<cost2DMovie3SingleSeat;
                    cout<<"\n\t\t\t\t\tCost of Twin Seat  : $"<<cost2DMovie3TwinSeat;
                    cout<<"\n\t\t\t\t\tCost of Family Seat: $"<<cost2DMovie3FamilySeat;
                    cout<<"\n\t\t\t\t\tCost of Single Seat: $"<<cost3DMovie3SingleSeat;
                    cout<<"\n\t\t\t\t\tCost of Twin Seat  : $"<<cost3DMovie3TwinSeat;
                    cout<<"\n\t\t\t\t\tCost of Family Seat: $"<<cost3DMovie3FamilySeat;
                }
                if(storeKindOfMovie3==2){
                    cout<<"\n\t\t\t\t\tCost of Single Seat: $"<<cost2DMovie3SingleSeat;
                    cout<<"\n\t\t\t\t\tCost of Twin Seat  : $"<<cost2DMovie3TwinSeat;
                    cout<<"\n\t\t\t\t\tCost of Family Seat: $"<<cost2DMovie3FamilySeat;
                }
                else{
                    cout<<"\n\t\t\t\t\tCost of Single Seat: $"<<cost3DMovie3SingleSeat;
                    cout<<"\n\t\t\t\t\tCost of Twin Seat  : $"<<cost3DMovie3TwinSeat;
                    cout<<"\n\t\t\t\t\tCost of Family Seat: $"<<cost3DMovie3FamilySeat;
                }
                int OptInSelectMovie3;
                cout<<"\n\n\t\t\t\t\tPlease select 9 to go back: ";
                cin>>OptInSelectMovie3;
                if(OptInSelectMovie3==9){
                    goto movieMainScreen;
                }
            }

        }
    }
}
