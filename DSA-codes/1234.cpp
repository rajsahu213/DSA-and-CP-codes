#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *next;
};

struct node *l;

typedef struct node * lptr;

void insert_at_end(lptr &l,int x)
{
    lptr t;
    t= new (node);
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

lptr push(lptr l,int data)
{
    lptr temp;
    temp=(lptr)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=l;
    return temp;
}

int pop(lptr l)
{
    int n=l->data;
    lptr t=l;
    l=l->next;
    free(t);
    return n;
}

lptr creatnode(lptr l,int data)
{
    lptr temp;
    temp=(lptr)malloc(sizeof(struct node)) ;
    temp->data=data;
    temp->next=NULL;
    return temp;    
}

lptr insert11(lptr l,int data)
{
    if(l==NULL)l=creatnode(l,data);
    else insert11(l->next,data);
    return l;
}

lptr reverse (lptr l, int k)
{ 
    lptr s=NULL;
    lptr t=l;
    int count=0;
    while(t!=NULL){count++;t=t->next;}
    int j=0;
    while(j<count)
    {
        for(int i=0;i<k;i++)
        {
            if(j==count-1)break;
            s=(lptr)push(s,pop(l));
            j++;
        }
        for(int i=0;i<k;i++)
        {
            l=(lptr)insert11(l,pop(s));
        }
    }
    return l;
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
    l=reverse(l,k);
    display(l);
}