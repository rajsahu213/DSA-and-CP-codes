#include<bits/stdc++.h>
using namespace std;

struct btnode{
    char data;
    int x;
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

void preorder(btptr &t)
{
    if(t!=NULL)
    {
        cout<<t->x<<" ";
        preorder(t->lchild);
        preorder(t->rchild);
    }
}


void setx(btptr &t,int &l)
{
    if(t!=NULL)
    {
        setx(t->lchild,l);
        t->x=l++;
        setx(t->rchild,l);
    }
}

void print_bt(btptr &t)
{
    queue<btptr> q;
    queue<int> q1;
    q1.push(t->x);
    q.push(t);
    q.push(NULL);
    int n,sum=0;
    while(!q.empty())
    {
        if(q.front()==NULL)
        {
            sum=0;
            cout<<endl;
            q.pop();
            if(q.empty())break;
            q.push(NULL);
        }
        btptr t1=q.front();
        n=q1.front()-sum;
        sum=q1.front()+1;
        for(int i=0;i<n;i++)cout<<" ";
        cout<<t1->data;
        q.pop();q1.pop();
        if(t1->lchild!=NULL){q.push(t1->lchild);q1.push(t1->lchild->x);}
        if(t1->rchild!=NULL){q.push(t1->rchild);q1.push(t1->rchild->x);}
    }
}

void print_bt2(btptr &t)
{
    queue<btptr> q;
    queue<int> q1;
    queue<char> q2;
    q2.push('*');
    q1.push(t->x);
    q.push(t);
    q.push(NULL);
    btptr t1;
    int n,sum=0,flag=0;
    while(!q.empty())
    {
        if(flag%2==0){
        if(q.front()==NULL)
        {
            sum=0;
            cout<<endl;            
            q.pop();
            if(q.empty())break;
            q.push(NULL);
        }
        t1=q.front();
        n=q1.front()-sum;
        sum=q1.front()+1;
        for(int i=0;i<n;i++)cout<<" ";
        cout<<t1->data;
        q.pop();q1.pop();}
        if(t1->lchild!=NULL){q.push(t1->lchild);q1.push(t1->lchild->x);q2.push('/');}
        if(t1->rchild!=NULL){q.push(t1->rchild);q1.push(t1->rchild->x);q2.push('\\');}
        flag++;
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
    int l=1;
    setx(t,l);
    print_bt(t);
    // preorder(t); 
    // cout<<endl;
    //print_bt2(t);
}

            // if(q2.front()=='*')
            // {
            //     cout<<endl;
            //     q2.pop();
            //     if(q2.empty())break;
            //     q2.push('*');
            // }
            // char ch=q2.front();
            // cout<<ch<<"  ";
            // q2.pop();