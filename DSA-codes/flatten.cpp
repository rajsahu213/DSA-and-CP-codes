#include<bits/stdc++.h>
using namespace std;

struct mlnode
{
    int data;
    mlnode *next;
    mlnode *down;
};

struct mlnode *l;

typedef struct mlnode* lptr;

//SHREYA
// void add_down(lptr &h,int num)
// {
//     if(num==0)
//     return;
//     else
//     {
//         h=new struct mlnode;
//         cout<<"enter a number(down): ";
//         cin>>h->data;
//         h->next=NULL;
//         h->down=NULL;
//         add_down(h->down,num-1);
//     }
// }

// void add(lptr &l,int x)
// {
//     if(x==0)
//         return;
//     else
//     {
//         l=new struct mlnode;
//         char ch;
//         cout<<"enter the number(right): ";
//         cin>>l->data;
//         cout<<"do you want to insert a branch?(y/n): ";
//         cin>>ch;
//         if(ch=='n')
//         {
//             l->down=NULL;
//             l->next=NULL;
//             add(l->next,x-1);
//         }
//         else if(ch=='y')
//         {
//             int n;
//             cout<<"enter the number of vertical nodes: ";
//             cin>>n;
//             l->next=NULL;
//             l->down=NULL;
//             add_down(l->down,n);
//             add(l->next,x-1);
//         }
//     }
// }

lptr creatnode(lptr &l,int data)
{
    lptr temp;
    temp=new(mlnode);
    temp->next=NULL;
    temp->down=NULL;
    temp->data=data;
    l=temp;
    return temp;
}

lptr insert_next(lptr &l,int data)
{
    if(l==NULL)return creatnode(l,data);
    else insert_next(l->next,data);
}

lptr insert_down(lptr &l,int data)
{
    if(l==NULL)return creatnode(l,data);
    else insert_next(l->down,data);
}

void add(lptr &l,int n)
{
    lptr t=l,p;
    while(n--)
    {
        cout<<"enter the number(right): ";
        int data;cin>>data;
        t=insert_next(l,data);
        cout<<"do you want to insert branch(y/n) ?: ";
        char ch;cin>>ch;
        if(ch=='y')
        {
            cout<<"how many vertical nodes? ";
            int n1;cin>>n1;
            for(int i=0;i<n1;i++)
            {
                cout<<"enter the number(down): ";
                int data1;cin>>data1;
                p=insert_down(t->down,data1);
            }
        }
    }
}

void flatten(lptr &l)
{
    lptr t=l,p;    
    while(t!=NULL)
    {
        p=t->next;
        while(t->down!=NULL)
        {
            t->next=t->down;
            t->down=NULL;
            t=t->next;
        }  
        t->next=p;
        t=p;
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
    cout<<"enter the number of horizontal nodes: ";
    int n;cin>>n;
    add(l,n);
    flatten(l);
    display(l);
}