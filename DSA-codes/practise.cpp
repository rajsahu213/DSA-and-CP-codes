#include<iostream>
#include<queue>
#include<stack>
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

// void inorder(bstptr &t)
// {
// 	if(t!=NULL)
// 	{
// 		inorder(t->lchild);
// 		cout<<t->data<<" ";
// 		inorder(t->rchild);
// 	}
// }

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

void range_leaf(bstptr &t,int k,int &greater,int &lesser)
{
	static int flag=0,temp=0;
	if(k<t->data)
	{
		range_leaf(t->lchild,k,greater,lesser);
	}
	else if(k>t->data)
	{
		range_leaf(t->rchild,k,greater,lesser);
	}
	if(temp==1&&flag==0)
	{
		if(t->rchild!=NULL)
		{
			greater=t->data;
			flag=1;
		}
		else
		{
			lesser=t->data;
			flag=1;
		}
	}
	temp++;
}

void range(bstptr &t,int k)
{
	static bstptr t1=t;
	if(t->data==k)
	{
		if(t->lchild==NULL||t->rchild==NULL)
		{
			int greater=t1->data,lesser=t1->data;
			range_leaf(t1,k,greater,lesser);
			cout<<"the range is: ";
			for(int i=greater+1;i<lesser;i++)
			{
				cout<<i<<" ";
			}
			cout<<endl;
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

void zig_zag1(bstptr &t)
{
	queue<bstptr> q;
	stack<bstptr> s;
	bstptr t1;
	q.push(t);
	q.push(NULL);
	int flag=0;
	while(!q.empty())
	{
		if(q.front()==NULL)
		{
			if(flag%2==0)cout<<endl;
			if(flag%2!=0)
			{
				while(!s.empty()){cout<<s.top()->data<<" ";s.pop();}
				cout<<endl;
			}
			q.pop();
			if(q.empty()){break;}
			q.push(NULL);
			flag++;
		}
		t1=q.front();
		if(flag%2==0)cout<<t1->data<<" ";
		else s.push(t1);
		q.pop();
		if(t1->lchild!=NULL){q.push(t1->lchild);}
		if(t1->rchild!=NULL){q.push(t1->rchild);}
	}
}

void zig_zag2(bstptr &t)
{
	queue<bstptr> q;
	stack<bstptr> s,s1;
	bstptr t1,t2;
	t2->data=-1;
	q.push(t);
	q.push(NULL);
	int flag=0;
	while(!q.empty())
	{
		if(q.front()==NULL)
		{
			if(flag%2==0)s1.push(NULL);
			else s.push(NULL);
			q.pop();
			if(q.empty()){break;}
			q.push(NULL);
			flag++;			
		}
		t1=q.front();
		if(flag%2==0)s1.push(t1);
		else s.push(t1);
		q.pop();
		if(t1->lchild!=NULL){q.push(t1->lchild);}
		if(t1->rchild!=NULL){q.push(t1->rchild);}
	}
	flag++;
	while(!s.empty()||!s1.empty())
	{
		if(flag%2==0)
		{
			if(s.top()==NULL){s.pop();}
			while(!s.empty()&&s.top()!=NULL)
			{
				cout<<s.top()->data<<" ";
				s.pop();
			}
			//cout<<endl;
		}
		else{
			if(s1.top()==NULL){s1.pop();}
			while(!s1.empty()&&s1.top()!=NULL)
			{
				s.push(s1.top());
				s1.pop();
			}
			while(!s.empty()&&s.top()!=NULL)
			{
				cout<<s.top()->data<<" ";
				s.pop();
			}			
			//cout<<endl;
		}
		flag++;
	}
}

void convert(bstptr &t)
{
	static int sum=0,flag=0;
	if(t!=NULL)
	{
		convert(t->rchild);
		int n=t->data;
		t->data=sum;
		sum+=n;
		// if(flag==0){t->data=0;flag=1;}
		// else t->data=sum;
		convert(t->lchild);
	}
}

void inorder(bstptr &t)
{
	stack<bstptr> s;
	bstptr t1=t;
	while(t1!=NULL)
	{
		s.push(t1);
		t1=t1->lchild;
	}
	while(!s.empty())
	{
		t1=s.top();
		s.pop();
		cout<<t1->data<<" ";
		if(t1->rchild!=NULL)
		{
			t1=t1->rchild;
			while(t1!=NULL)
			{
				s.push(t1);
				t1=t1->lchild;
			}
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
	// inorder(t);
	// cout<<endl;
	// preorder(t);
	// cout<<endl;
	// postorder(t);
	// cout<<endl;
	// convert(t);
	// level_order(t);
	// // cout<<"the min is: "<<min(t)<<endl;
	// // cout<<"the max is: "<<max(t)<<endl;
	// min_and_max(t);
	// cout<<"the the node: ";
	// int k;cin>>k;
	// range(t,k);
	level_order(t);
	cout<<endl;
	zig_zag2(t);
	cout<<endl;
	// inorder(t);
	// cout<<endl;
}
