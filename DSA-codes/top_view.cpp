#include<bits/stdc++.h>
using namespace std;

struct btnode{
    char data;
    int hd;
    int vd;
    btnode* lchild;
    btnode* rchild;
};

struct view
{
    int hd;
    int vd;
    char data;
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
        cout<<t->vd<<" ";
        preorder(t->lchild);
        preorder(t->rchild);
    }
}

void print_1d_left(btptr &t,int &max,int l)
{
    if(t!=NULL)
    {
        if(l>max)
        {
            cout<<t->data<<" ";
            max=l;
        }
        print_1d_left(t->lchild,max,l+1);
        print_1d_left(t->rchild,max,l+1);
    }
}

void print_1d_right(btptr &t,int &max,int l)
{
    if(t!=NULL)
    {
        if(l>max)
        {
            cout<<t->data<<" ";
            max=l;
        }
        print_1d_right(t->rchild,max,l+1);
        print_1d_right(t->lchild,max,l+1);
    }
}

void set_hd(btptr &t,int hd)
{
    if(t!=NULL)
    {
        t->hd=hd;
        set_hd(t->lchild,hd-1);
        set_hd(t->rchild,hd+1);
    }
}

void set_vd(btptr &t,int vd)
{
    if(t!=NULL)
    {
        t->vd=vd;
        set_vd(t->lchild,vd-1);
        set_vd(t->rchild,vd-1);
    }
}

int max_vd(view a[],int i,int n)
{
    int max=i;
    for(int j=i+1;j<n;j++)
    {
        if(a[j].hd==a[i].hd)
        {
            if(a[j].vd>a[max].vd)max=j;
        }
    }
    return max;
}

bool check_hd(view a[],int i,int n)
{
    bool flag=false;
    for(int j=i+1;j<n;j++)
    {
        if(a[j].hd==a[i].hd)
        {
            flag=true;
            if(a[i].vd>a[j].vd){a[j].hd=100;}
            else a[i].hd=100;
        }
    }
    return flag;
}

void set_view(btptr &t,view arr[],int &i)
{
    if(t!=NULL)
    {
        arr[i].hd=t->hd;
        arr[i].vd=t->vd;
        arr[i].data=t->data;
        i++;
        set_view(t->lchild,arr,i);
        set_view(t->rchild,arr,i);
    }
}

void top_view(view a[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(check_hd(a,i,n)&&a[i].hd!=100)
        {
            int k=max_vd(a,i,n);
            cout<<a[k].data<<" ";
            i=k;
        }
        else if(a[i].hd!=100)
        {
            cout<<a[i].data<<" ";
        }
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
    int hd=0;
    set_hd(t,hd);
    int vd=0;
    set_vd(t,vd);
    struct view arr[n+10];
    int len=0;
    set_view(t,arr,len);
    top_view(arr,len);
    cout<<endl;
}