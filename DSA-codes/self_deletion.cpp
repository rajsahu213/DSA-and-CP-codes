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

void deletion(lptr &l,int x)
{
    lptr t1,t2;
    t1=l;
    t2=l->next;
    if(l->data==x)
    {
        l=t2;
        free(t1);
    }
    else{
        while(t1->next!=NULL)
        {
            if(t2->data==x)
            {
                t1->next=t2->next;
                free(t2);
                break;
            }
            else{
                t1=t1->next;
                t2=t2->next;
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

void mark(lptr &l,int x)
{
    lptr t=l;
    for(int i=1;i<x;i++)
    {
        t=t->next;
    }
    t->data=-1;
}

void self_delete(lptr &l,int n)
{
    queue<int> q;
    lptr t=l;
    while(t!=NULL)
    {
        q.push(t->data);
        t=t->next;
    }
    while(1)
    {
        if(q.front()>n)
        {
            break;
        }
        else{
            mark(l,q.front());
            q.pop();
        }
    }
    lptr t1=l;
    for(int i=0;i<n;i++)
    {
        if(t1->data==-1)
        {
            deletion(l,-1);
        }
        t1=t1->next;
    }
}

int main()
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
    self_delete(l,n);
    display(l);
}