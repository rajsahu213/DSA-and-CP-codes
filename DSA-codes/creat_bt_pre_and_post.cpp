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
    btptr temp;
    temp=new(btnode);
    temp->data=a;
    temp->lchild=temp->rchild=NULL;
    return temp;
}

bool is_there(char x,string a,int i,int n)
{
    for(int j=i;j<n;j++)
    {
        if(a[j]==x)return true;
    }
    return false;
}

int index(char x,string a)
{
    for(int i=0;i<a.length();i++)
    {
        if(a[i]==x)return i;
    }
    return -1;
}

btptr creat(btptr &t,string pre,string in,int j,int n,int n1)
{
    static int i=0;
    int k=index(pre[i],in);    
    if(is_there(pre[i],in,j,n))
    {
        t=creatnode(pre[i++]);
    }
    else t=NULL;
    if(t==NULL||i==n1)return t;
    t->lchild=creat(t->lchild,pre,in,j,k,n1);
    t->rchild=creat(t->rchild,pre,in,k+1,n,n1);
    return t;
}

btptr creat2(btptr &t,string post,string in,int j,int n,int n1)
{
    static int i=n1-1;
    int k=index(post[i],in);    
    if(is_there(post[i],in,j,n))
    {
        t=creatnode(post[i--]);
    }
    else t=NULL;
    if(t==NULL||i<0)return t;
    t->rchild=creat2(t->rchild,post,in,k+1,n,n1);
    t->lchild=creat2(t->lchild,post,in,j,k,n1);
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

void preorder(btptr &t)
{
    if(t!=NULL)
    {
        cout<<t->data<<" ";
        preorder(t->lchild);
        preorder(t->rchild);
    }
}

int main()
{
    // cout<<"enter the preorder\n";
    // cout<<"> ";    
    cout<<"enter the postorder\n";
    cout<<"> ";
    //string pre;cin>>pre;    
    string post;cin>>post;
    cout<<"enter the inorder\n";
    cout<<"> ";
    string in;cin>>in;
    btptr t=NULL;
    //int i=0,j=0,n=pre.length();
    int i=0,j=0,n=post.length();
    int n1=n;
    //t=creat(t,pre,in,j,n,n1);
    t=creat2(t,post,in,j,n,n1);
    level_order(t);
}