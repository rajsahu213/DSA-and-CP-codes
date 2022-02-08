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

lptr reverse(lptr prev,lptr curr,lptr next)
{
    if(curr==NULL)
    {
        return prev;
    }
    else{
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        reverse(prev,curr,next);
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
        while(t!=NULL)
        {
            cout<<t->data<<" ";
            t=t->next;
        }
        cout<<endl;
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
    cout<<"the reversed linked list is: ";
    l=reverse(NULL,l,l->next);
    display(l);
}