#include<bits/stdc++.h>
using namespace std;

struct btnode{
    int data;
    btnode* lchild;
    btnode* rchild;
};

typedef struct btnode* btptr;

btptr creatnode(int a)
{
    btptr temp;
    temp=new(btnode);
    temp->data=a;
    temp->lchild=temp->rchild=NULL;
    return temp;
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

void creat_bt_from_level_order(btptr &t,int a[],int i,int n)
{
    if(i<n)
    {
        t=creatnode(a[i]);
        creat_bt_from_level_order(t->lchild,a,2*i+1,n);
        creat_bt_from_level_order(t->rchild,a,2*i+2,n);
    }
}

int max_index(int a[],int i,int n)
{
    int max=i;
    for(int j=i;j<n;j++)
    {
        if(a[j]>a[max])max=j;
    }
    return max;
}

void creat_bt_from_max(btptr &t,int a[],int i,int n)
{
    if(i<n)
    {
        int max=max_index(a,i,n);
        t=creatnode(a[max]);
        creat_bt_from_max(t->lchild,a,i,max);
        creat_bt_from_max(t->rchild,a,max+1,n);
    }
}

bool check_strict_bt(btptr &t)
{
    static bool flag=true;
    static btptr t1=t;
    if(t!=NULL)
    {
        if(t->lchild==NULL&&t->rchild!=NULL||t->lchild!=NULL&&t->rchild==NULL)
        {
            flag=false;
        }
        check_strict_bt(t->lchild);
        check_strict_bt(t->rchild);
    }
    if(t1==t)return flag;
}

bool search(btptr &t,char x)
{
    if(t==NULL)return false;
    if(t->data==x)return true;
    else return search(t->lchild,x)+search(t->rchild,x);
}

void LCA(btptr &t,int k1,int k2)
{
    if(t==NULL)return;
    if(t->data==k1||t->data==k2){cout<<t->data<<endl;return;}
    else if(search(t->lchild,k1)&&search(t->rchild,k2)){cout<<t->data<<endl;return;}
    else if(search(t->lchild,k1)&&search(t->lchild,k2))LCA(t->lchild,k1,k2);
    else if(search(t->rchild,k1)&&search(t->rchild,k2))LCA(t->rchild,k1,k2);
}

void print(btptr &t)
{
    if(t!=NULL)
    {
        if(t->data!=-1)cout<<t->data;
        if(t->rchild!=NULL)cout<<"(";
        print(t->lchild);
        if(t->rchild!=NULL)cout<<")";
        if(t->rchild!=NULL)cout<<"(";
        print(t->rchild);
        if(t->rchild!=NULL)cout<<")";
    }
}

int no_of_nodes1(btptr &t,int &count)
{
    if(t!=NULL)
    {
        count++;
        no_of_nodes1(t->lchild,count);
        no_of_nodes1(t->rchild,count);
    }
}

int no_of_nodes(btptr &t)
{
    int count=0;
    no_of_nodes1(t,count);
    return count;
}

int check_com_bt(btptr &t)
{
    if(t==NULL)return 1;
    if(no_of_nodes(t->lchild)<no_of_nodes(t->rchild))return 0;
    return check_com_bt(t->lchild);
}

int main()
{
    cout<<"enter n: ";
    int n;cin>>n;
    cout<<"enter the array(enter -1 for NULL)\n";
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    btptr t=NULL;
    int i=0;
    creat_bt_from_level_order(t,a,i,n);
    // creat_bt_from_max(t,a,i,n);
    level_order(t);
    // if(check_strict_bt(t))cout<<"the entered tree is a strict binary tree\n";
    // else cout<<"the entered tree is not a strict binary tree\n";
    // cout<<"enter k1 and k2 : ";
    // int k1,k2;
    // cin>>k1>>k2;
    // LCA(t,k1,k2);
    // print(t);
    // cout<<endl;
    cout<<check_com_bt(t)<<endl;
}