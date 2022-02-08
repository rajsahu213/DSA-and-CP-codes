//EXPRESSION TREE
#include<bits/stdc++.h>
using namespace std;

union u 
{
    int num;
    char ch;
};

struct btnode
{
    btnode *lchild;
    btnode *rchild;
    int flag;
    union u data;
};

typedef struct btnode* btptr;

btptr creatnode1(string data)
{
    btptr temp;
    temp=new (btnode);
    temp->data.ch=data[0];
    temp->flag=0;
    temp->lchild=temp->rchild=NULL;
    return temp;
}

btptr creatnode2(int data)
{
    btptr temp;
    temp=new (btnode);
    temp->data.num=data;
    temp->flag=1;
    temp->lchild=temp->rchild=NULL;
    return temp;
}

btptr creat(btptr &t,string s[],int &i,int n)
{
    if(s[i]=="+"||s[i]=="-"||s[i]=="*"||s[i]=="/")
    {
        t=creatnode1(s[i++]);
    }
    else
    {
        t=creatnode2(stoi(s[i++]));
    }
    if(t->flag==1||i==n-1)return t;
    t->lchild=creat(t->lchild,s,i,n);
    t->rchild=creat(t->rchild,s,i,n);
    return t;
}

int eval(btptr &t)
{
    if(t->lchild==NULL&&t->rchild==NULL)
    {
        return t->data.num;
    }
    else
    {
        switch(t->data.ch)
        {
            case '+':return eval(t->lchild)+eval(t->rchild);
            case '-':return eval(t->lchild)-eval(t->rchild);
            case '*':return eval(t->lchild)*eval(t->rchild);
            case '/':return eval(t->lchild)/eval(t->rchild);
        }
    }
}

void preorder(btptr &t)
{
    if(t!=NULL)
    {
        if(t->lchild==NULL&&t->rchild==NULL)
            cout<<t->data.num<<" ";
        else cout<<t->data.ch<<" ";
        preorder(t->lchild);
        preorder(t->rchild);
    }
}

int main()
{
    cout<<"enter the EXPRESSION( type break to stop ): "; 
    string s[40];
    int i=0;
    while(1)
    {
        cin>>s[i];
        if(s[i]=="$")break;
        i++;
    }
    int j=0;
    btptr t=NULL;
    creat(t,s,j,i);
    preorder(t);
    cout<<endl;
    cout<<"the ans is : "<<eval(t)<<endl;
}