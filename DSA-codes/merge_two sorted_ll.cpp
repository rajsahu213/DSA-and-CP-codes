#include<bits/stdc++.h>
using namespace std;

struct lnode{
    int data;
    lnode *next;
};

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

void insert_before(lptr &l,int e,int x)
{
    lptr t;
    t= new(lnode);
    t->data=x;
    if(l->data==e)
    {
        return;
    }
    else{
        lptr t1;
        t1=l;
        while(t1->next!=NULL)
        {
            if(t1->next->data==e)
            {
                t->next=t1->next;
                t1->next=t;
                break;
            }
            else{
                t1=t1->next;
            }
        }
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
        cout<<"the list is: ";
        while(t!=NULL)
        {
            cout<<t->data<<" ";
            t=t->next;
        }
        cout<<endl;
    }
}

void merge(lptr &l1,lptr &l2)
{
    lptr t1=l1,t2=l2;
    while(t1!=NULL&&t2!=NULL)
    {
        if(t1->data<t2->data)
        {
            t1=t1->next;
        }
        else if(t1->data>=t2->data)
        {
            insert_before(l1,t1->data,t2->data);
            t2=t2->next;
        }
    }
    while(t2!=NULL)
    {
        insert_at_end(l1,t2->data);
        t2=t2->next;
    }
}

int main()
{
    lptr l1=NULL;
    lptr l2=NULL;
    cout<<"enter the number of elements in first linked list\n";
    int n;cin>>n;
    while(n--)
    {
        cout<<"enter the number: ";
        int n;cin>>n;
        insert_at_end(l1,n);
    }
    cout<<"enter the number of elements in second linked list\n";
    int n1;cin>>n1;
    while(n1--)
    {
        cout<<"enter the number: ";
        int n;cin>>n;
        insert_at_end(l2,n);
    }
    merge(l1,l2);
    display(l1);
}