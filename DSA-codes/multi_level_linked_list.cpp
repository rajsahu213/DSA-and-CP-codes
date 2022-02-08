#include<bits/stdc++.h>
using namespace std;
struct lnode;

union u
{
    char ch;
    lnode* ptr;
};

struct lnode
{
    int flag;
    union u data;
    lnode *next;
};

typedef struct lnode* lptr;

void insert_char(lptr &l,char x)
{
    lptr t;
    t= new (lnode);
    t->data.ch=x;
    t->flag=0;
    t->next=NULL;
    if(l==NULL)
    {
        l=t;
    }
    else{
        lptr t1;
        t1=l;
        while(t1->next!=NULL)
        {
            t1=t1->next;
        }
        t1->next=t;
    }
}

lptr insert_ptr(lptr &l)
{
    lptr t;
    t= new (lnode);
    t->data.ptr=NULL;
    t->flag=1;
    t->next=NULL;
    if(l==NULL)
    {
        l=t;
    }
    else{
        lptr t1;
        t1=l;
        while(t1->next!=NULL)
        {
            t1=t1->next;
        }
        t1->next=t;
    }
    return t;
}

void display(lptr &l)
{
    lptr t=l;
    while(t!=NULL)
    {
        if(t->flag==0)
        {
            cout<<t->data.ch;
        }
        else{
            cout<<"{";
            display(t->data.ptr);
            cout<<"}";
        }
        t=t->next;
    }
}

void flaging(lptr &l,char a[])
{
    static int i=0;
    while(i<strlen(a))
    {
        if(a[i]=='{')
        {
            lptr p=insert_ptr(l);
            i++;
            flaging(p->data.ptr,a);
        }
        else if(a[i]=='}')
        {
            return;
        }
        else {
            insert_char(l,a[i]);
        }
        i++;.
    }
}

int main()
{
    lptr l=NULL;
    cout<<"enter a string: ";
    char a[100];
    cin.getline(a,100);
    flaging(l,a);
    display(l);
    cout<<endl;
}