#include<bits/stdc++.h>
using namespace std;

struct lnode{
    int data;
    lnode *next;
};

struct lnode *l;

typedef struct lnode* lptr;

void creatnode(lptr &l,int x)
{
    lptr temp;
    temp=new(lnode);
    temp->data=x;
    temp->next=NULL;
    l=temp;
}

void insert_at_end(lptr &l,int x)
{
    if(l==NULL)creatnode(l,x);
    else insert_at_end(l->next,x);
}

void display(lptr l)
{
    if(l!=NULL)
    {
        cout<<l->data<<" ";
        display(l->next);
    }
}

int main()
{
    lptr l=NULL,new_head=nullptr;
    cout<<"enter n: ";
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        int a;cin>>a;
        insert_at_end(l,a);
    }
    cout<<"the list is: ";
    display(l);
    cout<<endl;
}