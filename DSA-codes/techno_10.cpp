#include<bits/stdc++.h>
using namespace std;

struct btnode{
    char data;
    btnode* lchild;
    btnode* rchild;
    btnode* next;
};

typedef struct btnode* btptr;

btptr creatnode(char a)
{
    if(a=='.')return NULL;
    btptr temp;
    temp=new(btnode);
    temp->data=a;
    temp->lchild=temp->rchild=temp->next=NULL;
    return temp;
}

btptr creat(btptr &t,string s,int n,int &i)
{
    t=creatnode(s[i]);
    if(t==NULL||i==n)return t;
    t->lchild=creat(t->lchild,s,n,++i);
    t->rchild=creat(t->rchild,s,n,++i);
    return t;
}

void level_order(btptr &t)
{
    queue<btptr> q;
    q.push(t);
    q.push(NULL);
    while(!q.empty())
    {
        if(q.front()==NULL)
        {
            cout<<endl;
            q.pop();
            if(q.empty())break;
            q.push(NULL);
        }
        btptr t1=q.front();
        cout<<t1->data<<" ";
        q.pop();
        if(t1->lchild!=NULL)q.push(t1->lchild);
        if(t1->rchild!=NULL)q.push(t1->rchild);
    }
}

int max(int a,int b)
{
    if(a>b)return a;
    else return b;
}
int height(btptr &t)
{
    if(t==NULL)return -1;
    else return max(height(t->lchild),height(t->rchild))+1;
}

void modify(btptr &t,btptr &l,int k,int &flag)
{
    if(t!=NULL)
    {
        if(k==0)
        {
           if(flag==0)
           {
                l=t;
                flag=1;
           } 
           else
           {
                l->next=t;
                l=l->next;
           }
        }
        modify(t->lchild,l,k-1,flag);
        modify(t->rchild,l,k-1,flag);
    }
} 

int main()
{
    btptr t=NULL;
    cout<<" >> ";
    string a;
    cin>>a;
    int i=0,n=a.length();
    t=creat(t,a,n,i); 
    level_order(t);
    int h=height(t);
    for(int i=1;i<=h;i++)
    {
        btptr l;int flag=0;
        modify(t,l,i,flag);
    }

}