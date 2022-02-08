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

int length(dptr &d)
{
    static int l=0;
    if(d==NULL)
    {
        return l;
    }
    else{
        l++;
        length(d->right);
    }
}

void spiral(dptr &d)
{
    int len=length(d);
    int mid=len/2;
    if(len%2==0){mid=mid-1;}
    dptr t1=d,t2,t3=d;
    while(t3->right != NULL)
    {
        if(t3->right->right==NULL)
        {
            t2=t3;
        }
        t3=t3->right;
    }
    while(mid--)
    {
        t2->right=NULL;
        t3->left=t1;
        t3->right=t1->right;
        t1->right->left=t3;
        t1->right=t3;
        t3=t2;
        t2=t2->left;
        t1=t1->right->right;
    }
}

int main()
{
    dptr d=NULL;
    cout<<"enter the numbers (or -1 to stop): ";
    while(1)
    {
        int data;cin>>data;
        if(data==-1)break;
        insert_at_end(d,data);
    }
    spiral(d);
    display(d);
}