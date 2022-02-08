#include<bits/stdc++.h>
using namespace std;

struct dlnode{
    int data;
    dlnode *left;
    dlnode *right;
};

typedef struct dlnode* dptr;

void enqueue_front(dptr &f,dptr &r,int n)
{
    dptr t;
    t= new(dlnode);
    t->data=n;
    t->right=NULL;
    t->left=NULL;
    if(f==NULL&&r==NULL)
    {
        f=t;
        r=t;
    }
    else{
        f->left=t;
        t->right=f;
        f=t;
    }
}       

void enqueue_rear(dptr &f,dptr &r,int n)
{
    dptr t;
    t= new(dlnode);
    t->data=n;
    t->right=NULL;
    t->left=NULL;
    if(f==NULL&&r==NULL)
    {
        f=t;
        r=t;
    }
    else{
        t->left=r;
        r->right=t;
        r=t;
    }
}

int dequeue_front(dptr &f,dptr &r)
{

    if(f==NULL)
    {
        cout<<"the queue is empty\n";
    }
    else{
        int n=f->data;
        dptr t;
        t=f;
        f=f->right;
        free(t);
        return n;
    }
}

int dequeue_rear(dptr &f,dptr &r)
{

    if(f==NULL)
    {
        cout<<"the queue is empty\n";
    }
    else{
        int n=r->data;
        dptr t;
        t=r;
        r=r->left;
        free(t);
        return n;
    }
}

void display_queue(dptr &f,dptr &r)
{
    cout<<"the queue is: ";
    dptr t=f;
    while(t!=r)
    {
        cout<<t->data<<" ";
        t=t->right;
    }
    cout<<r->data<<endl;
}

int main()
{
    dptr f=NULL;
    dptr r=NULL;
    int c;
    do{
    cout<<"1: ENQUEUE\n";
    cout<<"2: DEQUEUE\n";
    cout<<"3: display_queue\n";
    cout<<"4: EXIT\n";
    cout<<"enter the choice: ";
    cin>>c;
    switch(c)
    {
        case 1: cout<<"do you want to enter from front or rear?(f/r): ";
                char a;cin>>a;
                cout<<"enter a number: ";
                int n;cin>>n;
                if(a=='f')
                {
                    enqueue_front(f,r,n);
                }
                else{
                    enqueue_rear(f,r,n);
                }
                break;
        case 2: cout<<"do you want to dequeue from front or rear?(f/r): ";
                char a1;cin>>a1;
                if(a1=='f')
                {
                    cout<<"the dequeued element is: "<<dequeue_front(f,r)<<endl;
                }
                else{
                    cout<<"the dequeued element is: "<<dequeue_rear(f,r)<<endl;
                }
                break;
        case 3: display_queue(f,r);
                break;             
        case 4: break;                     
    }

    }while(c!=4);
    return 0;
}