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
    if(a==-1)return NULL;
    btptr temp;
    temp=new(btnode);
    temp->data=a;
    temp->lchild=temp->rchild=NULL;
    return temp;
}

btptr creat(btptr &t,int s[],int n,int &i)
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

void print_level1(btptr &t)
{
  vector<int> a;
    queue<btptr> q;
    q.push(t);
    q.push(NULL);
    while(!q.empty())
    {
        if(q.front()==NULL)
        {
            int flag=0,i=0,j=a.size()-1;
            for(auto k=a.begin();k!=a.end();k++)
            {
              if(flag%2==0){cout<<a[i]<<" ";i++;}
              else{cout<<a[j]<<" ";j--;}
              flag++;
            }
            a.clear();q.pop();
            if(q.empty())break;
            q.push(NULL);
        }
        btptr t1=q.front();
        a.push_back(t1->data);q.pop();
        if(t1->lchild!=NULL)q.push(t1->lchild);
        if(t1->rchild!=NULL)q.push(t1->rchild);
    }
}

void print_level2(btptr &t)
{
    vector<vector<int>> a;
    vector<int> v,v1;
    queue<btptr> q;
    q.push(t);
    q.push(NULL);
    while(!q.empty())
    {
        if(q.front()==NULL)
        {
            int flag=0;
            int k=0,l=v.size()-1;
            for(auto i=v.begin();i!=v.end();i++)
            {
              if(flag%2==0){v1.push_back(v[k]);k++;}
              else{v1.push_back(v[l]);l--;}
              flag++;
            }
            a.push_back(v1);v.clear();
            v1.clear();q.pop();
            if(q.empty())break;
            q.push(NULL);
        }
        btptr t1=q.front();
        v.push_back(t1->data);q.pop();
        if(t1->lchild!=NULL)q.push(t1->lchild);
        if(t1->rchild!=NULL)q.push(t1->rchild);
    }
    for(int i=a.size()-1;i>=0;i--)
      for(int k=0;k<a[i].size();k++)
        cout<<a[i][k]<<" ";
}

int max(int a,int b,int c,int d)
{
    int max=a;
    if(b>max)max=b;
    if(c>max)max=c;
    if(d>max)max=d;
    return max;
}
int max1(int a,int b)
{
    if(a>b)return a;
    else return b;
}

int mid_lev(btptr &t)
{
    if(t==NULL)
    {
        return -1;
    }
    else if(t->lchild==NULL&&t->rchild==NULL)
    {
        return 0;
    }
    else
    {
        if(t->lchild==NULL)
        {
            return max1(mid_lev(t->rchild->rchild),mid_lev(t->rchild->lchild))+1;
        }
        else if(t->rchild==NULL)
        {
            return max1(mid_lev(t->lchild->lchild),mid_lev(t->lchild->rchild))+1;
        }
    else return max(mid_lev(t->lchild->lchild),mid_lev(t->rchild->rchild),mid_lev(t->lchild->rchild),mid_lev(t->rchild->lchild))+1;
    }
}

void print(btptr &t,int k)
{
    if(t!=NULL)
    {
        if(k==0)
        {
            cout<<t->data<<" ";
        }
        print(t->lchild,k-1);
        print(t->rchild,k-1);
    }
}

int main()
{
    btptr t=NULL;
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int i=0;
    t=creat(t,a,n,i);
    level_order(t);
    // cout<<"the middle level is: "<<mid_lev(t)<<endl;
    // int k=mid_lev(t);
    // print(t,k);
    // cout<<endl;
    cout<<"the required printing is: \n";
    print_level1(t);
    cout<<endl;
    cout<<"the second version is\n";
    print_level2(t);
    cout<<endl;
}
// 1 2 4 8 16 -1 -1 17 -1 -1 9 18 -1 -1 19 -1 -1 5 10 20 -1 -1 21 -1 -1
// 11 22 -1 -1 23 -1 -1 3 6 12 24 -1 -1 25 -1 -1 13 26 -1 -1 27 -1 -1 7 14 28 -1 -1 29 -1 -1 15 30 -1 -1 31 -1 -1
