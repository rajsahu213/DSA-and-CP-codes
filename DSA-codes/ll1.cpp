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

void insert_at_big(lptr &l,int x)
{
    lptr t;
    t= new(lnode);
    t->data=x;
    t->next=l;
    l=t;
}

void insert_after(lptr &l,int x)
{
    cout<<"enter an element: ";
    int e;cin>>e;
    lptr t;
    t= new(lnode);
    t->data=x;
    if(l->data==e)
    {
        t->next=l->next;
        l->next=t;
    }
    else{
        lptr t1;
        t1=l;
        while(t1!=NULL)
        {
            if(t1->data==e)
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

void insert_before(lptr &l,int x)
{
    cout<<"enter an element: ";
    int e;cin>>e;
    lptr t;
    t= new(lnode);
    t->data=x;
    if(l->data==e)
    {
        t->next=l;
        l=t;
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

void deletion_before(lptr &l,int x)
{
    lptr t1,t2;
    t1=l;
    t2=l->next;
    if(l->next->data==x)
    {
        l=l->next;
        free(t1);
    }
    else{
        while(t2->next!=NULL)
        {
            if(t2->next->data==x)
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

void deletion_after(lptr &l,int x)
{
    lptr t1,t2;
    t1=l;
    t2=l->next;
    if(l->data==x)
    {
        t1->next=t2->next;
        free(t2);
    }
    else{
        while(t2!=NULL)
        {
            if(t1->data==x)
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

int main()
{
    lptr l=NULL;
    cout<<"enter n: ";
    int n;cin>>n;
    int data;
    for(int i=0;i<n;i++)
    {
        cin>>data;
        insert_at_big(l,data);
        display(l);
        // cin>>data;
        // insert_at_end(l,data);
        // display(l);
        // cin>>data;
        // insert_before(l,data);
        // display(l);
        // cin>>data;
        // insert_after(l,data);
        // display(l);
    }
    for(int i=0;i<4;i++)
    {
        int c;cin>>c;
        deletion_after(l,c);
        display(l);
    }
}