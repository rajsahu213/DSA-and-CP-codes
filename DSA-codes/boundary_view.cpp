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
    bool is_leaf;
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

void set_view(btptr &t,view arr[],int &i)
{
    if(t!=NULL)
    {
        if(t->rchild==NULL&&t->lchild==NULL)
        {
            arr[i].is_leaf=true;
        }
        else arr[i].is_leaf=false;
        arr[i].hd=t->hd;
        arr[i].vd=t->vd;
        arr[i].data=t->data;
        i++;
        set_view(t->lchild,arr,i);
        set_view(t->rchild,arr,i);
    }
}

int min_vd(view a[],int i,int n)
{
    int min=i;
    for(int j=i+1;j<n;j++)
    {
        if(a[j].hd==a[i].hd)
        {
            if(a[j].vd<a[min].vd)min=j;
        }
    }
    return min;
}

bool check_hd_bottom(view a[],int i,int n)
{
    bool flag=false;
    int k=i;
    for(int j=i+1;j<n;j++)
    {
        if(a[j].hd==a[i].hd)
        {
            flag=true;
            if(a[k].vd>a[j].vd){a[k].hd=100;k=j;}
            else a[j].hd=100;
        }
    }
    return flag;
}

void bottom_view(view a[],int n,char a2[],int &l)
{
    for(int i=0;i<n;i++)
    {
        if(check_hd_bottom(a,i,n)&&a[i].hd!=100&&a[i].is_leaf)
        {
            int k=min_vd(a,i,n);
            a2[l++]=a[k].data;
            i=k;
        }
        else if(a[i].hd!=100&&a[i].is_leaf)
        {
            a2[l++]=a[i].data;
        }
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

bool check_hd_top(view a[],int i,int n)
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

void top_view(view a[],int n,char a1[],int &l)
{
    for(int i=0;i<n;i++)
    {
        if(check_hd_top(a,i,n)&&a[i].hd!=100)
        {
            int k=max_vd(a,i,n);
            a1[l++]=a[k].data;
            i=k;
        }
        else if(a[i].hd!=100)
        {
            a1[l++]=a[i].data;
        }
    }
}

void union_top_bottom(char a1[],char a2[],int l1,int l2)
{
    for(int i=0;i<l1;i++)
    {
        cout<<a1[i]<<" ";
    }
    for(int i=0;i<l2;i++)
    {
        int flag=0;
        for(int j=0;j<l1;j++)
        {
            if(a1[j]==a2[i])flag=1;
        }
        if(flag==0)cout<<a2[i]<<" ";
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
    char a1[100],a2[100];
    int l1=0,l2=0;
    top_view(arr,len,a1,l1);
    len=0;
    set_view(t,arr,len);
    bottom_view(arr,len,a2,l2);
    union_top_bottom(a1,a2,l1,l2);
    cout<<endl;
}