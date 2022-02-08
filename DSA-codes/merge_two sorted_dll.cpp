#include<bits/stdc++.h>
using namespace std;

struct dlnode{
    int data;
    dlnode *left;
    dlnode *right;
};

typedef struct dlnode* dptr;

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

void insert_before(dptr &d,int x,int data)
{
    dptr t;
    t= new(dlnode );
    t->data=data;
    t->left=NULL;
    t->right=NULL;
    if(d->data==x)
    {
        d->left=t;
        t->right=d;
        d=t;
    }
    else{
        dptr t1=d;
        while(t1->right!=NULL)
        {
            if(t1->right->data==x)
            {
                t->left=t1;
                t->right=t1->right;
                t1->right->left=t;
                t1->right=t;
                break;
            }
            else{
                t1=t1->right;
            }
        }
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
        cout<<"the list is : ";
        while(t!=NULL)
        {
            cout<<t->data<<" ";
            t=t->right;
        }
        cout<<endl;
    }
}

void merge(dptr &d1,dptr &d2)
{
    dptr t1=d1,t2=d2;
    while(t1!=NULL&&t2!=NULL)
    {
        if(t1->data<t2->data)
        {
            t1=t1->right;
        }
        else if(t1->data>=t2->data)
        {
            insert_before(d1,t1->data,t2->data);
            t2=t2->right;
        }
    }
    while(t2!=NULL)
    {
        insert_at_end(d1,t2->data);
        t2=t2->right;
    }
}

int main()
{
    dptr d1=NULL;
    dptr d2=NULL;
    cout<<"enter the number of elements in first linked list\n";
    int n;cin>>n;
    while(n--)
    {
        cout<<"enter the number: ";
        int n;cin>>n;
        insert_at_end(d1,n);
    }
    cout<<"enter the number of elements in second linked list\n";
    int n1;cin>>n1;
    while(n1--)
    {
        cout<<"enter the number: ";
        int n;cin>>n;
        insert_at_end(d2,n);
    }
    merge(d1,d2);
    display(d1);
}