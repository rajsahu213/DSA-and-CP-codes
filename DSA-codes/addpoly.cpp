#include<bits/stdc++.h>
using namespace std;

struct lnode{
    int data;
    int power;
    lnode *next;
};

typedef struct lnode* lptr;

void insert_at_end(lptr &l,int c,int p)
{
    lptr t;
    t= new (lnode);
    t->data=c;
    t->power=p;
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

void display(lptr &l)
{
    if(l==NULL)
    {
        cout<<"the list is empty\n";
    }
    else{
        lptr t;
        t=l;
        cout<<"the addition of those two polynomial is\n";
        while(t!=NULL)
        {
            cout<<t->data<<"x^"<<t->power<<" ";
            t=t->next;
        }
        cout<<endl;
    }
}

void addpoly(lptr &l1,lptr &l2)
{
    lptr t1=l1,t2=l2,l3=NULL;
    while(t1!=NULL&&t2!=NULL)
    {
        if(t1->power==t2->power)
        {
            insert_at_end(l3,t1->data+t2->data,t1->power);
            t1=t1->next;
            t2=t2->next;
        }
        else if(t1->power>t2->power)
        {
            insert_at_end(l3,t1->data,t1->power);
            t1=t1->next;
        }
        else{
            insert_at_end(l3,t2->data,t2->power);
            t2=t2->next;
        }
    }
    display(l3);
}

int main()
{
    lptr l1=NULL;
    lptr l2=NULL;
    cout<<"enter the number of terms in the first polynomial\n";
    int n;cin>>n;
    while(n--)
    {
        cout<<"coefficient: ";
        int c;cin>>c;
        cout<<"x^";
        int n;cin>>n;
        insert_at_end(l1,c,n);
    }
    cout<<"enter the number of terms in the second polynomial\n";
    int n1;cin>>n1;
    while(n1--)
    {
        cout<<"coefficient: ";
        int c;cin>>c;
        cout<<"x^";
        int n;cin>>n;
        insert_at_end(l2,c,n);
    }
    addpoly(l1,l2);
}