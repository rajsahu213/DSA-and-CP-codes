#include<bits/stdc++.h>
using namespace std;

struct btnode{
    char data;
    btnode* lchild;
    btnode* rchild;
};

typedef struct btnode* btptr;

btptr creatnode(char a)
{
    if(a=='.')return NULL;
    btptr temp;
    temp=new(btnode);
    temp->data=a;
    temp->lchild=temp->rchild=NULL;
    return temp;
}

btptr creat(btptr &t,string s,int n,int &i)
{
    t=creatnode(s[i]);
    if(t==NULL||i==n-1)return t;
    t->lchild=creat(t->lchild,s,n,++i);
    t->rchild=creat(t->rchild,s,n,++i);
    return t;
}

void inorder(btptr &t,int a[],int &l)
{
    if(t!=NULL)
    {
        inorder(t->lchild,a,l);
        a[l++]=t->data-'0';
        inorder(t->rchild,a,l);
    }
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

void bt_to_bst(btptr &t,int a[],int n)
{
    static int i=0;
    if(t!=NULL)
    {
        bt_to_bst(t->lchild,a,n);
        string s=to_string(a[i++]);
        t->data=s[0];
        bt_to_bst(t->rchild,a,n);
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
    int arr[n+1],l=0;
    inorder(t,arr,l);
    sort(arr,arr+l);   
    bt_to_bst(t,arr,l);
    level_order(t);  
}