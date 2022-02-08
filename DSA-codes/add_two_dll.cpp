#include<bits/stdc++.h>
using namespace std;

struct dlnode{
    int data;
    dlnode *left;
    dlnode *right;
};

typedef struct dlnode* dptr;

void insert_at_big(dptr &d,int data)
{
    dptr t;
    t= new(dlnode);
    t->data=data;
    t->left=NULL;
    if(d==NULL)
    {
        t->left=d;
        d=t;
    }
    else{
        d->left=t;
        t->right=d;
        d=t;
    }
}

void insert_at_end(dptr &d,int data)
{
    dptr t;
    t= new(dlnode);
    t->data=data;
    t->right=NULL;
    t->left=NULL;
    if(d==NULL)
    {
        t->left=d;
        d=t;
    }
    else{
        dptr t1=d;
        while(t1->right!=NULL)
        {
            t1=t1->right;
        }
        t->left=t1;
        t1->right=t;
    }
}

void display(dptr &d)
{
    if(d==NULL)
    {
        cout<<"the list is empty\n";
    }
    else{
        dptr t=d;
        while(t!=NULL)
        {
            cout<<t->data<<" ";
            t=t->right;
        }
        cout<<endl;
    }
}

void add(dptr &d1,dptr &d2,dptr &d3,int n)
{
    if(d1->right!=NULL)
    {
        add(d1->right,d2->right,d3,n-1);
    }
    static int carry=0,sum;
    sum=d1->data+d2->data+carry;
    if(sum>=10){sum=sum-10;carry=1;}
    else {carry=0;}
    insert_at_big(d3,sum);
    if(n==-1&&carry==1){insert_at_big(d3,1);}
}

int main()
{
    dptr d1=NULL;
    dptr d2=NULL;
    dptr d3=NULL;
    cout<<"enter the number of elements\n";
    int n,n1;cin>>n;n1=n;
    cout<<"enter first number: ";
    while(n--)
    {
        int n;cin>>n;
        insert_at_end(d1,n);
    }
    cout<<"enter second number: ";
    while(n1--)
    {
        int n;cin>>n;
        insert_at_end(d2,n);
    }
    add(d1,d2,d3,n);
    cout<<"addition of those numbers is: ";
    display(d3);
}