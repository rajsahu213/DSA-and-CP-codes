#include<bits/stdc++.h>
using namespace std;

struct mlnode
{
    int data;
    mlnode *next;
    mlnode *down;
};

struct mlnode *l;

typedef struct mlnode* lptr;

void add_down(lptr &h,int num)
{
    if(num==0)
    return;
    else
    {
        h=new struct mlnode;
        cout<<"enter a number(down): ";
        cin>>h->data;
        h->next=NULL;
        h->down=NULL;
        add_down(h->down,num-1);
    }
}

void add(lptr &l,int x)
{
    if(x==0)
        return;
    else
    {
        l=new struct mlnode;
        char ch;
        cout<<"enter the number(right): ";
        cin>>l->data;
        cout<<"do you want to insert a branch?(y/n): ";
        cin>>ch;
        if(ch=='n')
        {
            l->down=NULL;
            l->next=NULL;
            add(l->next,x-1);
        }
        else if(ch=='y')
        {
            int n;
            cout<<"enter the number of vertical nodes: ";
            cin>>n;
            l->next=NULL;
            l->down=NULL;
            add_down(l->down,n);
            add(l->next,x-1);
        }
    }
}

void display(lptr &l)
{
    if(l==NULL)
    {
        return;
    }
    cout<<l->data<<" ";
    if(l->down!=NULL)
    {
        display(l->down);
    }
    display(l->next);
}

void display(lptr &l){
    if(l!=NULL){
        cout<<l->data<<" ";
        display(l->down);
        display(l->next);
    }
}

int main()
{
    lptr l=NULL;
    cout<<"enter the number of horizontal nodes: ";
    int n;cin>>n;
    add(l,n);
    display(l);
}