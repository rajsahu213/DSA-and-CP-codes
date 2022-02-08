#include<bits/stdc++.h>
using namespace std;

struct lnode{
    int data;
    lnode *next;
};

struct head{
    lnode *l;
    head *nextptr;
    int index;
};

typedef struct lnode* lptr;
typedef struct head* hptr;

void insert_ptr(hptr &h,int x)
{
    hptr t;
    t= new (head);
    t->index=x;
    t->nextptr=NULL;
    t->l=NULL;
    if(h==NULL)
    {
        h=t;
    }
    else{
        hptr t1;
        t1=h;
        while(t1->nextptr!=NULL)
        {
            t1=t1->nextptr;
        }
        t1->nextptr=t;
    }
}

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

int delete_big(lptr &l)
{
    lptr t=l;
    int n=t->data;
    l=l->next;
    free(t);
    return n;
}

void insert(hptr &h,int d,int n)
{
    hptr t;
    t=h;
    while(t!=NULL)
    {
        if(t->index==d)
        {
            insert_at_end(t->l,n);
            break;
        }
        t=t->nextptr;
    }
}

void radix_sort(hptr &h,int a[],int n)
{
    int b=10,fact=1,k=0,y;
    while(b--)
    {
        k++;
        for(int i=0;i<n;i++)
        {
            int d=a[i],x;
            for(int j=0;j<k;j++)
            {
                x=d%10;
                d=d/10;
            }
            insert(h,x,a[i]);
        }      
        y=0;
        hptr t=h;    
        while(t!=NULL)
        {
            while(t->l!=NULL)
            {
                a[y++]=delete_big(t->l);
            }
            t=t->nextptr;
        }
    }
}

int main()
{
    hptr h=NULL;
    for(int i=0;i<10;i++)
    {
        insert_ptr(h,i);
    }
    cout<<"enter the size of the array: ";
    int n;cin>>n;
    cout<<"enter the number\n";
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    radix_sort(h,a,n);
    cout<<"the sorted array is\n";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;
}