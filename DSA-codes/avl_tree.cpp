#include<iostream>
#include<queue>
using namespace std;

struct bstnode{
	int data;
	bstnode *lchild;
	bstnode *rchild;
};

typedef struct bstnode* bstptr;

int max(int a,int b)
{
	if(a>b)return a;
	else return b;
}

int find_h(bstptr &t)
{
	if(t==NULL)return -1;
	else return 1+max(find_h(t->lchild),find_h(t->rchild));
}

void insert(bstptr &t,int x)
{
	if(t==NULL)
	{
		bstptr temp;
		temp=new(bstnode);
		temp->data=x;
		temp->lchild=temp->rchild=NULL;
		t=temp;
		return;
	}
	else
	{
		if(x<t->data)
		{
			insert(t->lchild,x);
		}
		else 
		{
			insert(t->rchild,x);
		}
	}
	int lh=find_h(t->lchild);
	int rh=find_h(t->rchild);
	if(lh-rh>1||lh-rh<-1)
	{
		if(lh>rh)
		{
			bstptr t1=t->lchild;
			if(find_h(t1->lchild)>find_h(t1->rchild))
			{
				int temp=t->data;t->data=t1->data;t1->data=temp;
				t->lchild=t1->lchild;
				t1->lchild=t1->rchild;
				t1->rchild=t->rchild;
				t->rchild=t1;
			}
			else
			{
				bstptr t2=t1->rchild;
				int temp=t->data;t->data=t2->data;t2->data=temp;
				t1->rchild=t2->lchild;
				t2->lchild=t2->rchild;
				t2->rchild=t->rchild;
				t->rchild=t2;
			}
		}
		else
		{
			bstptr t1=t->rchild;
			if(find_h(t1->rchild)>find_h(t1->lchild))
			{
				int temp=t->data;t->data=t1->data;t1->data=temp;
				t->rchild=t1->rchild;
				t1->rchild=t1->lchild;
				t1->lchild=t->lchild;
				t->lchild=t1;
			}
			else
			{
				bstptr t2=t1->lchild;
				int temp=t->data;t->data=t2->data;t2->data=temp;
				t1->lchild=t2->rchild;
				t2->rchild=t2->lchild;
				t2->lchild=t->lchild;
				t->lchild=t2;				
			}			
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

int main()
{
	cout<<"enter n: ";
	int n;cin>>n;
	cout<<"enter the array\n";
	int a[n];
	bstptr t=NULL;
	for(int i=0;i<n;i++)
	{
		cout<<endl;
		a[i]=i+1;
		insert(t,a[i]);
		level_order(t);
	}
}