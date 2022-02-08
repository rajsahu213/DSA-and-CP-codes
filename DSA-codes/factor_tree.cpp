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
	btptr temp;
	temp=new btnode;
	temp->data=a;
	temp->lchild=temp->rchild=NULL;
	return temp;
}

int index(int n)
{
	for(int i=2;i<n;i++)
	{
		if(n%i==0)return i;
	}
	return -1;
}

void creat(btptr &t,int n)
{
	int i=index(n);
	if(i==-1)
	{
		t=creatnode(n);
		return;
	}
	else
	{
		t=creatnode(n);
		creat(t->lchild,i);
		creat(t->rchild,n/i);
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

int main()
{
	cout<<"enter a number: ";
	int n;cin>>n;
	btptr t=NULL;
	creat(t,n);
	level_order(t);
}
