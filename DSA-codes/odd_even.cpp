#include<bits/stdc++.h>
using namespace std;

struct lnode{
    int data;
    lnode *next;
};

struct lnode *l;

typedef struct lnode* lptr;

lptr creatnode(int x)
{
    lptr temp;
    temp=new(lnode);
    temp->data=x;
    temp->next=NULL;
    return temp;
}

lptr insert_at_end(lptr &l,int x)
{
    if(l==NULL)
    {
        l=creatnode(x);
    }
    else
    {
        l->next=insert_at_end(l->next,x);
    }
    return l;
}

void even_odd(lptr &l)
{
    int temp;
    if(l==NULL)
    {
        cout<<"the list is empty\n";
    }
    else{
        lptr t=l;
        while(t->next->next!=NULL)
        {
            if(t->data%2==0&&t->next->data%2!=0)
            {
                temp=t->data;
                t->data=t->next->data;
                t->next->data=temp;
            }
            else if(t->data%2==0&&t->next->data%2==0)
            {
                lptr t1=t;
                while(t1->data%2==0&&t1->next!=NULL)
                {
                    t1=t1->next;
                }
                temp=t->data;
                t->data=t1->data;
                t1->data=temp;
            }
            t=t->next;
        }
    }
}

void display(lptr l)
{
    if(l!=NULL)
    {
        cout<<l->data<<" ";
        display(l->next);
    }
}

int main()
{
    lptr l=NULL;
    cout<<"enter n: ";
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"enter a number: ";
        int data;cin>>data;
        l=insert_at_end(l,data);
    }
    even_odd(l);
    cout<<"the list is: ";
    display(l);
    cout<<endl;
}