#include<bits/stdc++.h>
using namespace std;

struct btnode
{
	int data;
	btnode* lchild;
	btnode* rchild;
};

typedef struct btnode* btptr;

btptr creatnode(int a)
{
	if(a==-1)return NULL;
	btptr temp;
	temp=new btnode;
	temp->data=a;
	temp->lchild=temp->rchild=NULL;
	return temp;
}

btptr creat(btptr &t,int a[],int &i,int n)
{
	t=creatnode(a[i]);
	if(t==NULL||i>=n)return t;
	t->lchild=creat(t->lchild,a,++i,n);
	t->rchild=creat(t->rchild,a,++i,n);
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

int max_path(btptr &t,int &res)
{
	if(t==NULL)return 0;
	int l=max_path(t->lchild,res);
	int r=max_path(t->rchild,res);
	int max_single=max(max(l,r)+t->data,t->data);
	int max_top=max(l+r+t->data,max_single);
	res=max(res,max_top);
	return max_single;
}
int diameter(btptr &t,int &res)
{
	if(t==NULL)return 0;
	int l=diameter(t->lchild,res);
	int r=diameter(t->rchild,res);
	int max_single=max(max(l,r)+1,1);
	int max_top=max(l+r+1,max_single);
	res=max(max_top,res);
	return max_single;
}

int main()
{
	cout<<"enter n: ";
	int n;cin>>n;
	cout<<"enter the serialization: ";
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	shell_sort(a,n);
	for(int i=0;i<n;i++)cout<<a[i]<<" ";
	cout<<endl;
	// btptr t=NULL;
	// int i=0;
	// creat(t,a,i,n);
	// level_order(t);
	// int res=INT_MIN;
	// max_path(t,res);
	// cout<<res<<endl;res=0;
	// diameter(t,res);
	// cout<<res<<endl;	
}
