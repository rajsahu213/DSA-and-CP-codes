#include<bits/stdc++.h>
using namespace std;

struct lnode{
    int data;
    lnode *next;
};

struct lnode *l1;
struct lnode *l2;

typedef struct lnode* lptr;

void insert_at_big(lptr &l,int x)
{
    lptr t;
    t= new(lnode);
    t->data=x;
    t->next=l;
    l=t;
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
        while(t!=NULL)
        {
            cout<<t->data<<" ";
            t=t->next;
        }
        cout<<endl;
    }
}

void insertionsort(lptr &l,lptr &l2)
{
    if(l!=NULL)
    {
    if(l2==NULL)
    {
        return;
    }
    if(l->next==l2)
    {
        l->next=NULL;
    }
    lptr t=l2;
    l2=l2->next;
    lptr t2=l;
    if(t2->data>t->data)
    {
        t->next=l;
        l=t;
    }
    else{
        while(t2->next!=NULL&&t2->next->data<t->data)
        {
            t2=t2->next;
        }
        t->next=t2->next;
        t2->next=t;
    }
    insertionsort(l,l2);
}
}


void insertionsort1(lptr &l1,lptr &l2)
{
    lptr t1=l1,t2=l2;
    l1->next=NULL;
    while(l2!=NULL)
    {
        t1=l1;
        t2=l2;
        l2=l2->next;
        if(t1->data>t2->data)
        {
            t2->next=t1;
            l1=t2;
        }
        else
        {
            while(t1->next!=NULL&&t1->next->data<t2->data)
            {
                t1=t1->next;
            }
            t2->next=t1->next;
            t1->next=t2;
        }
    }
}

void unio(lptr &l1,lptr &l2)
{
    lptr t1=l1,t2=l2;
    lptr l3=NULL;
    while(t1!=NULL)
    {
        insert_at_big(l3,t1->data);
        t1=t1->next;
    }
    int flag;
    lptr t3=l3;
    while(t2!=NULL)
    {
        flag=0;
        t3=l3;
        while(t3!=NULL)
        {
            if(t2->data==t3->data)
            {
                flag=1;
                break;
            }
            t3=t3->next;
        }
        if(flag==0){insert_at_big(l3,t2->data);}
        t2=t2->next;
    }
    lptr l4=l3->next;
    insertionsort1(l3,l4);
    display(l3);
}

void inter(lptr &l1,lptr &l2)
{
    lptr l3=NULL;
    lptr t1=l1,t2=l2;
    while(t1!=NULL)
    {
        t2=l2;
        while(t2!=NULL)
        {
            if(t1->data==t2->data)
            {
                insert_at_big(l3,t1->data);
                break;
            }
            t2=t2->next;
        }
        t1=t1->next;
    }
    lptr l4=l3->next;
    insertionsort1(l3,l4);    
    display(l3);
}

int main()
{
    lptr l1=NULL,l2=NULL;
    cout<<"enter the first list(press -1 to stop)\n";
    while(1)
    {
        cout<<"enter a number: ";
        int data;cin>>data;
        if(data==-1)break;
        insert_at_big(l1,data);
    } 
    cout<<"enter the second list(press -1 to stop)\n";
    while(1)
    {
        cout<<"enter a number: ";
        int data;cin>>data;
        if(data==-1)break;
        insert_at_big(l2,data);
    }   
    cout<<"the union of those two list is\n";
    unio(l1,l2);
    cout<<"the intersection of those two list is\n";
    inter(l1,l2);     
}