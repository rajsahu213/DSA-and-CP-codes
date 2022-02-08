#include<iostream>
#include<stack>
#include<queue>
#include<climits>
using namespace std;

struct bstnode
{
    int data;
    bstnode *lchild;
    bstnode *rchild;
};

typedef struct bstnode* bstptr;

void insert(bstptr &t,int data)
{
    if(t==NULL)
    {
        bstptr temp;
        temp=new(bstnode);
        temp->data=data;
        temp->lchild=temp->rchild=NULL;
        t=temp;
    }
    else
    {
        if(data<t->data)
        {
            insert(t->lchild,data);
        }
        else{
            insert(t->rchild,data);
        }
    }
}

void sum_pair(bstptr &t1,bstptr &t2,int k)
{
    static int d=-100;
    if(t1!=NULL&&t2!=NULL)
    {
        sum_pair(t1->lchild,t2,k);
        sum_pair(t1,t2->rchild,k);
        if(t1->data+t2->data==k&&(t1->data-t2->data)!=d)
        {
            d=t1->data-t2->data;
            cout<<t1->data<<" "<<t2->data<<endl;
        }
        else if(t1->data+t2->data<k)
        {
            sum_pair(t1->rchild,t2,k);
        }
        else{
            sum_pair(t1,t2->lchild,k);
        }
    }
}

void common_nodes(bstptr &t1,bstptr &t2)
{
    static int d=-100;
    if(t1!=NULL&&t2!=NULL)
    {
        common_nodes(t1->lchild,t2);
        common_nodes(t1,t2->rchild);
        if(t1->data==t2->data&&t1->data!=d)
        {
            d=t1->data;
            cout<<t1->data<<endl;
        }
        else if(t1->data<t2->data)
        {
            common_nodes(t1->rchild,t2);
        }
        else{
            common_nodes(t1,t2->lchild);
        }
    }
}

int main()
{
    bstptr t1=NULL;
    cout<<"enter n: ";
    int n1;cin>>n1;
    for(int i=0;i<n1;i++)
    {
        cout<<"enter the number: ";
        int data;cin>>data;
        insert(t1,data);
    }
    bstptr t2=NULL;
    cout<<"enter n: ";
    int n2;cin>>n2;
    for(int i=0;i<n2;i++)
    {
        cout<<"enter the number: ";
        int data;cin>>data;
        insert(t2,data);
    }   
    cout<<"enter k: ";
    int k;cin>>k;
    sum_pair(t1,t2,k);
    common_nodes(t1,t2);
}