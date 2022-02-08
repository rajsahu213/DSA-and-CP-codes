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

void display(lptr &l)
{
    if(l==NULL)
    {
        cout<<"the list is empty\n";
    }
    else{
        lptr t;
        t=l;
        cout<<"the sorted list is: ";
        while(t!=NULL)
        {
            cout<<t->data<<" ";
            t=t->next;
        }
        cout<<endl;
    }
}

void insertionsort(lptr &l1,lptr &l2)
{
    if(l2==NULL)
    {
        return;
    }
    if(l1->next==l2)
    {
        l1->next=NULL;
    }
    lptr t1=l1;
    lptr t2=l2;
    l2=l2->next;
    if(t2->data<t1->data)
    {
        t2->next=t1;
        l1=t2;
    }
    else
    {
        while(t1->next->data<t2->data&&t1->next!=NULL)
        {
            t1=t1->next;
        }
        t2->next=t1->next;
        t1->next=t2;
    }
    insertionsort(l1,l2);
}

main()
{
    lptr l=NULL;
    cout<<"enter n: ";
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"enter a number: ";
        int data;cin>>data;
        insert_at_end(l,data);
    }
    lptr l2=l->next;
    insertionsort(l,l2);
    display(l);
}