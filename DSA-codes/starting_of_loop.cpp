#include<bits/stdc++.h>
using namespace std;

struct lnode{
    int data;
    lnode *next;
};

struct lnode *l;

typedef struct lnode* lptr;

void insert_at_end(lptr &l,int x)
{
    lptr t;
    t= new (lnode);
    t->data=x;
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

void makeloop(lptr &l)
{
    cout<<"enter the index to make loop\n";
    int i;cin>>i;
    lptr t=l;
    for(int j=0;j<i;j++)
    {
        t=t->next;
    }
    lptr t1=l;
    while(t1->next!=NULL)
    {
        t1=t1->next;
    }
    t1->next=t;
}

int strloop(lptr &l)
{
    lptr sp=l,fp=l;
    while(sp!=NULL && fp!=NULL && fp->next!=NULL)
    {
        sp=sp->next;
        fp=fp->next->next;
        if(sp==fp)
        {break;}
    }
    if(sp==fp)
    {
        sp=l;
        while(sp!=fp)
        {
            sp=sp->next;
            fp=fp->next;
        }
    return sp->data;
    }
}

int main()
{
    lptr l=NULL;
    int data;
    cout<<"enter the data or( enter -1 to exit)\n";
    while(1)
    {
        cout<<"enter a number: ";
        cin>>data;
        if(data==-1){break;}
        insert_at_end(l,data);
    }
    makeloop(l);
    int result=strloop(l);
    cout<<"the loop starts at "<<result <<endl;
}