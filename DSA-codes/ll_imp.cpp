#include<bits/stdc++.h>
#include<stack>
using namespace std;

struct lnode
{
    int data;
    int cnt;
    lnode *next[5];
};

typedef struct lnode* lptr;

void insert_at_end(lptr &l,int x,int count)
{
    lptr t;
    t= new (lnode);
    t->data=x;
    t->cnt=count;
    for(int i=0;i<5;i++)
        t->next[i]=NULL;
    if(l==NULL)
    {
        l=t;
    }
    else{
        lptr t1;
        t1=l;
        while(t1->next[0]!=NULL)
        {
            t1=t1->next[0];
        }
        t1->next[0]=t;
    }
}


void creat(lptr &l)
{
    cout<<"enter the data: ";
    int data;cin>>data;
    cout<<"enter the count: ";
    int count;cin>>count;
    if(count>0)
    {
        insert_at_end(l,data,count);
        for(int i=0;i<count;i++)
        {
            creat(l->next[i]);
        }
    }
}

void print(lptr &l,int t)
{
    lptr t1=l;
    while(t1->data!=t)
    {
        cout<<t1->data<<" ";
        t1=t1->next[0];
    }
    cout<<t1->data<<" ";
}

void display(lptr &l)
{
    static lptr t=l;
    static stack<int> s;
    if(l==NULL)
    {
        cout<<endl;
        if(!s.empty())
        {
            print(t,s.top());
            s.pop();
        }
        return;
    }
    else{
        if(l->cnt>1)
        {
            for(int i=0;i<l->cnt-1;i++)
            {
                s.push(l->data);
            }
        }
        cout<<l->data<<" ";
        for(int i=0;i<l->cnt;i++)
        {
            display(l->next[i]);
        }
    }
}


int main()
{
    lptr l=NULL;
    creat(l);
    display(l);
}