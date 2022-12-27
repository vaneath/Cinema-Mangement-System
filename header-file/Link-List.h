struct Element
{
    Element *next,*prev;
    string movie, time, date, food, Name, Gmail, password;
};

struct List
{
    Element *head, *tail;
    int n;
};

List *createList()
{
    List *ls;
    ls=new List;
    ls->head=NULL;
    ls->tail=NULL;
    ls->n=0;

    return ls;
}

void addMovie(List *ls, int newNum)
{
    Element *e;
    e=new Element;
    e->ranNumber=newNum;

    e->prev=ls->tail;
    e->next=NULL;

    if(ls->n==0)
    {
        ls->head=e;
    }
    if(ls->n!=0)
    {
        ls->tail->next=e;
    }
    ls->tail=e;
    ls->n=ls->n+1;
}
