#include<iostream>
#include<queue>
using namespace std;

struct bstnode{
	int data;
	bstnode *lchild;
	bstnode *rchild;
};

typedef struct bstnode* bstptr;

void insert(bstptr &t,int x)
{
	if(t==NULL)
	{
		bstptr temp;
		temp=new(bstnode);
		temp->data=x;
		temp->lchild=temp->rchild=NULL;
		t=temp;
	}
	else{
		if(x<t->data)
		{
			insert(t->lchild,x);
		}
		else 
		{
			insert(t->rchild,x);
		}
	}
}

void level_order(bstptr &t)
{
	queue<bstptr> q;
	bstptr t1;
	q.push(t);
	q.push(NULL);
	while(!q.empty())
	{
		if(q.front()==NULL)
		{
			cout<<endl;
			q.pop();
			if(q.empty()){break;}
			q.push(NULL);
		}
		t1=q.front();
		cout<<t1->data<<" ";
		q.pop();
		if(t1->lchild!=NULL)
		{
			q.push(t1->lchild);
		}
		if(t1->rchild!=NULL)
		{
			q.push(t1->rchild);
		}
	}
}

void inorder(bstptr &t)
{
	cout<<"abcd\n";
	if(t!=NULL)
	{
		inorder(t->lchild);
		cout<<t->data<<" ";
		inorder(t->rchild);
	}
}

void preorder(bstptr &t)
{
	if(t!=NULL)
	{
		cout<<t->data<<" ";
		preorder(t->lchild);
		preorder(t->rchild);
	}
}

void postorder(bstptr &t)
{
	if(t!=NULL)
	{
		postorder(t->lchild);
		postorder(t->rchild);
		cout<<t->data<<" ";
	}
}

int min(bstptr &t)
{
	if(t->lchild==NULL)
	{
		return t->data;
	}
	else{
		min(t->lchild);
	}
}

int max(bstptr &t)
{
	if(t->rchild==NULL)
	{
		return t->data;
	}
	else{
		max(t->rchild);
	}
}

void min_and_max(bstptr &t)
{
	static int flag=0;
	static bstptr t1=t;
	if(flag==0)
	{
		if(t->lchild==NULL)
		{
			cout<<"the min of tree is : "<<t->data<<endl;
			return;
		}
		else min_and_max(t->lchild);
	}
	flag=1;
	if(t==t1)
	{
		if(t->rchild==NULL)
		{
			cout<<"the max of tree is : "<<t->data<<endl;
			return;
		}
		else
		{
			 t1=t1->rchild;
			 min_and_max(t->rchild);
		}
	}
}

void range_leaf(bstptr &t,int k)
{
	static int greater=-1,lesser=-1,flag=0;
	if(k<t->data)
	{
		lesser=t->data;
		range_leaf(t->lchild,k);
	}
	else if(k>t->data)
	{
		greater=t->data;
		range_leaf(t->rchild,k);
	}
	if(flag==0)
	{
		if(lesser==-1)
		{
			cout<<"value should be greater than "<<greater<<endl;
		}
		else if(greater==-1)
		{
			cout<<"the value should be lesser than "<<lesser<<endl;
		}
		else
		{
			cout<<"the range of the entered node is: ";
			for(int i=greater+1;i<lesser;i++)
			{
				cout<<i<<" ";
			}
			cout<<endl;
		}
	}
	flag=1;
}

void range(bstptr &t,int k)
{
	static bstptr t1=t;
	if(t->data==k)
	{
		if(t->lchild==NULL||t->rchild==NULL)
		{
			range_leaf(t1,k);
		}
		else{
		int mi=max(t->lchild);
		int mx=min(t->rchild);
		cout<<"the range of the entered node is: ";
		for(int i=mi+1;i<mx;i++)
		{
			cout<<i<<" ";
		}
		cout<<endl;}
		return;
	}
	else{
		if(k<t->data)
		{
			range(t->lchild,k);
		}
		else if(k>t->data)
		{
			range(t->rchild,k);
		}
	}
}

int main()
{
	bstptr t=NULL;
	cout<<"enter n: ";
	int n;cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"enter a number: ";
		int data;cin>>data;
		insert(t,data);
	}
	inorder(t);
	cout<<endl;
	preorder(t);
	cout<<endl;
	postorder(t);
	cout<<endl;
	level_order(t);
	// cout<<"the min is: "<<min(t)<<endl;
	// cout<<"the max is: "<<max(t)<<endl;
	min_and_max(t);
	cout<<"the the node: ";
	int k;cin>>k;
	range(t,k);
}