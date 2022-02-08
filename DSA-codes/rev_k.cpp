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

void delete_at_big(lptr &l)
{
    lptr t=l;
    l=l->next;
    free(t);
}

int length(lptr &l)
{
    static int len=0;
    if(l==NULL)
    {
        return len;
    }
    else{
        len++;
        length(l->next);
    }
}

void rev_k(lptr &l,int k)
{
    int len=length(l);
    int temp=k;
    stack<int> s;
    lptr t=l;
    while(t!=NULL)
    {
        while((k--)&&len>=temp)
        {
            s.push(t->data);
            lptr t1=t->next;
            delete_at_big(l);
            t=t1;
        }   
        if(len<temp)
        {
            lptr t1=t->next;
            insert_at_end(l,t->data);
            delete_at_big(l);
            t=t1;
            len--;
        }
        else len=len-temp;
        if(len<=0)break;
        while(!s.empty())
        {
            insert_at_end(l,s.top());
            s.pop();
        }
        k=temp;        
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
    cout<<"enter the numbers (or -1 to stop): ";
    while(1)
    {
        int data;cin>>data;
        if(data==-1)break;
        insert_at_end(l,data);
    }
    cout<<"enter k: ";
    int k;cin>>k;
    rev_k(l,k);
    display(l);
}