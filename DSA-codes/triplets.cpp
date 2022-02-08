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

void sum(lptr &l1,lptr &l2,lptr &l3,int k)
{
    if(l1==NULL||l2==NULL||l3==NULL||l1->data>k||l2->data>k||l3->data>k||
    (l1->data+l2->data)>k||(l2->data+l3->data)>k||(l1->data+l3->data)>k||
    (l1->data+l2->data+l3->data)>k)
    {
        return;
    }
    if((l1->data+l2->data+l3->data)==k&&(l3->data>l2->data)&&(l2->data>l1->data))
    {
        cout<<l1->data<<" "<<l2->data<<" "<<l3->data<<endl;
    }
    sum(l1,l2,l3->next,k);
    if(l3==l2->next)
    {
        sum(l1,l2->next,l3,k);
        if(l2==l1->next)
        {
            sum(l1->next,l2,l3,k);
        }
    }
}

void sum(lptr &l1,lptr &l2,lptr &l3,int k)
{
    lptr t1=l1,t2=l2,t3=l3;
    while(t1!=NULL)
    {
        t2=l1->next;
        while(t2!=NULL)
        {
            t3=l2->next;
            while(t3!=NULL)
            {
                if(t1->data+t2->data+t3->data==k&&t2->data>t1->data&&t3->data>t2->data)
                {
                    cout<<t1->data<<" "<<t2->data<<" "<<t3->data<<endl;
                }
                t3=t3->next;
            }
            t2=t2->next;
        }
        t1=t1->next;
    }
}

int main()
{
    cout<<"enter the data ( or -1 to stop )\n";
    lptr l=NULL;
    while(1)
    {
        cout<<"enter the number: ";
        int data;cin>>data;
        if(data==-1)break;
        insert_at_end(l,data);
    }
    cout<<"enter k: ";
    int k;cin>>k;
    sum(l,l,l,k);
}