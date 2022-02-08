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

void creatmll(lptr &l)
{
    int data;
    lptr t=l;
    cout<<"enter the data or( enter -1 to exit)\n";
    while(1)
    {
        cout<<"enter a number: ";
        cin>>data;
        if(data==-1){break;}
        t=insert_next(l,data);
        cout<<"do you want to add a branch?(y/n): ";
        char a;cin>>a;
        if(a=='y'){creatmll(t->down);}
    }
}

void display(lptr &l)
{
    queue<mlnode*> q;
    lptr t=l;
    q.push(NULL);
    do
    {      
        while(t!=NULL)
        {
            cout<<t->data<<" ";
            if(t->down!=NULL)
            {
                q.push(t->down);
            }
            t=t->next;  
        }
        if(q.front()==NULL)
        {
            cout<<endl;
            q.pop();
            q.push(NULL);
        }
        t=q.front();
        q.pop();
    }while(!q.empty());
}

int main()
{
    lptr l=NULL;
    creatmll(l);
    display(l);
}