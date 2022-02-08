#include<bits/stdc++.h>
using namespace std;

struct lnode{
    int data;
    lnode *next;
};

struct lnode *l1;
struct lnode *l2;

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


void merge(lptr &l1,lptr &l2)
{
    lptr t1=l1,t2=l2;
    cout<<"enter n: ";
    int n;cin>>n;
    while(n--)
    {
        t1=t1->next;
    }
    while(t2->next!=NULL)
    {
        t2=t2->next;
    }
    t2->next=t1;
}

int merge_point(lptr &l1,lptr &l2)
{
    lptr t1=l1,t2=l2;
    int count1=0,count2=0;
    while(t1->next!=NULL)
    {count1++;t1=t1->next;}
    while(t2->next!=NULL)
    {count2++;t2=t2->next;} 
    lptr sp,fp,p;
    if(count1>count2)
    {
        t1->next=l1;
        sp=l2;
        fp=l2;
        p=l2;
    }
    else{
        t2->next=l2;
        sp=l1;
        fp=l1;
        p=l1;
    }
    do{
        sp=sp->next;
        fp=fp->next->next;
    }while(sp!=fp);   
    while(p!=sp)
    {
        p=p->next;
        sp=sp->next;
    } 
    return p->data;
}

int main()
{
    lptr l1=NULL,l2=NULL;
    cout<<"enter the first list(press -1 to stop)\n";
    while(1)
    {
        cout<<"enter a number: ";
        int data;cin>>data;
        if(data==-1)break;
        insert_at_end(l1,data);
    } 
    cout<<"enter the second list(press -1 to stop)\n";
    while(1)
    {
        cout<<"enter a number: ";
        int data;cin>>data;
        if(data==-1)break;
        insert_at_end(l2,data);
    }   
    merge(l1,l2); 
    display(l1);
    display(l2); 
    int result=merge_point(l1,l2);
    cout<<"the two list merges at node : "<<result<<endl; 
}