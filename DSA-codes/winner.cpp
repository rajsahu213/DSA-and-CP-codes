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

void creat1(btptr &t,int a1[],int i,int n)
{
	if(i<n)
	{
		t=creatnode(0);
		creat1(t->lchild,a1,2*i+1,n);
		creat1(t->rchild,a1,2*i+2,n);
	}
}

void creat(btptr &t,int a[],int n)
{
	static int i=0;
	if(t!=NULL)
	{
		if(t->lchild==NULL&&t->rchild==NULL)
		{
			t->lchild=creatnode(a[i++]);
			t->rchild=creatnode(a[i++]);
			return;
		}
		creat(t->lchild,a,n);
		creat(t->rchild,a,n);
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

int max(int a,int b)
{
	if(a>b)return a;
	else return b;
}

int win(btptr &t)
{
	if(t->lchild==NULL&&t->rchild==NULL)
	{
		return t->data;
	}
	else return max(win(t->lchild),win(t->rchild));
}

void assign(btptr &t,int x)
{
	if(t!=NULL)
	{
		if(t->data==x)
		{
			t->data=INT_MIN;
		}
		assign(t->lchild,x);
		assign(t->rchild,x);
	}
}

int main()
{
	cout<<"enter n: ";
	int n;cin>>n;
	cout<<"enter the array\n";
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	btptr t=NULL;
	int a1[n-1];
	int i=0;
	for(int i=0;i<n-1;i++)a1[i]=0;
	creat1(t,a1,i,n-1);
	creat(t,a,n);
	level_order(t);
	int x=win(t);
	assign(t,x);
	x=win(t);
	assign(t,x);
	cout<<"the 3rd winner is: "<<win(t)<<endl;
}