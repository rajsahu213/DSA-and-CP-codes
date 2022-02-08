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

int delete_big(lptr &l)
{
    lptr t=l;
    int n=t->data;
    l=l->next;
    free(t);
    return n;
}

void radix_sort(lptr l[],int a[],int n)
{
    int t=10,k=0,y;
    while(t--)
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
            insert_at_end(l[x],a[i]);
        }
        y=0;
        for(int i=0;i<10;i++)
        {
            while(l[i]!=NULL)
            {
                a[y++]=delete_big(l[i]);
            }
        }
    }
}

int main()
{
    lptr l[10];
    for(int i=0;i<10;i++)
    {
        l[i]=NULL;
    }
    cout<<"enter the size of the array: ";
    int n;cin>>n;
    cout<<"enter the number\n";
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    radix_sort(l,a,n);
    cout<<"the sorted array is\n";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;
}