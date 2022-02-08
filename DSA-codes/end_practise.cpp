#include<bits/stdc++.h>
using namespace std;

struct btnode
{
	int hd;
	char data;
	struct btnode* lchild;
	struct btnode* rchild;
};

typedef struct btnode* btptr;

btptr creatnode(char a)
{
	if(a=='.')return NULL;
	btptr temp=new btnode;
	temp->hd=-1;
	temp->data=a;
	temp->lchild=temp->rchild=NULL;
	return temp;
}

btptr creat(btptr &t,string s,int &i)
{
	t=creatnode(s[i]);
	if(t==NULL||i==s.length())return t;
	t->lchild=creat(t->lchild,s,++i);
	t->rchild=creat(t->rchild,s,++i);
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
		if(t1->lchild)q.push(t1->lchild);
		if(t1->rchild)q.push(t1->rchild);
	}
}

void preorder(btptr &t)
{
	if(t!=NULL)
	{
		cout<<t->hd<<" ";
		preorder(t->lchild);
		preorder(t->rchild);
	}
}

void serialization(btptr &t)
{
	if(t==NULL)cout<<".";
	if(t!=NULL)
	{
		cout<<t->data;
		serialization(t->lchild);
		serialization(t->rchild);
	}
}

void inorder(btptr &t)
{
	if(t!=NULL)
	{
		inorder(t->lchild);
		cout<<t->data<<" ";
		inorder(t->rchild);
	}
}

void postorder(btptr &t)
{
	if(t!=NULL)
	{
		postorder(t->lchild);
		postorder(t->rchild);
		cout<<t->data<<" ";
	}
}

int no_of_leaf(btptr &t)
{
	if(t==NULL)return 0;
	if(t->lchild==NULL&&t->rchild==NULL)return 1;
	else return no_of_leaf(t->lchild)+no_of_leaf(t->rchild);
}

void no_of_nonleaf(btptr &t,int &count)
{
	if(t==NULL)return;
	if(t->lchild!=NULL||t->rchild!=NULL)count++;;
	no_of_nonleaf(t->lchild,count);
	no_of_nonleaf(t->rchild,count);
}

int index(string in,int i,int n,char a)
{
	for(int j=i;j<n;j++)
	{
		if(in[j]==a)return j;
	}
	return -1;	
}

btptr creat(btptr &t,string pre,int &p,string in,int i,int n)
{
	int k=index(in,i,n,pre[p]);
	if(k!=-1)
	{
		t=creatnode(pre[p++]);
	}
	else t=NULL;
	if(t==NULL||p==pre.length())return t;
	t->lchild=creat(t->lchild,pre,p,in,i,k);
	t->rchild=creat(t->rchild,pre,p,in,k+1,n);
	return t;
}

void left_view(btptr &t,int l,int &max)
{
	if(t!=NULL)
	{
		if(l<max)
		{
			cout<<t->data<<" ";
			max=l;
		}
		left_view(t->lchild,l-1,max);
		left_view(t->rchild,l-1,max);
	}
}

void set_hd(btptr &t,int &i)
{
	if(t!=NULL)
	{
		set_hd(t->lchild,i);
		t->hd=i++;
		set_hd(t->rchild,i);
	}
}

void print(btptr &t)
{
	queue<btptr> q;
	q.push(t);
	q.push(NULL);
	int k=0;
	while(!q.empty())
	{
		if(q.front()==NULL)
		{
			cout<<endl;
			k=0;
			q.pop();
			if(q.empty())break;
			q.push(NULL);
		}
		btptr t1=q.front();
		for(int i=0;i<t1->hd-k;i++)cout<<" ";
		cout<<t1->data;
		k=t1->hd+1;
		q.pop();
		if(t1->lchild)q.push(t1->lchild);
		if(t1->rchild)q.push(t1->rchild);
	}
}

int main()
{
	cout<<"> ";
	string s;cin>>s;
	btptr t=NULL;
	int h=0;
	t=creat(t,s,h);
	level_order(t);h=0;
	set_hd(t,h);
	// preorder(t);cout<<endl;
	print(t);
	// left_view(t,-1,h);cout<<endl;
	// serialization(t);cout<<endl;
	// cout<<"the no of leaf nodes is: "<<no_of_leaf(t)<<endl;
	// int count=0;
	// no_of_nonleaf(t,count);
	// cout<<"the no of non leaf nodes is: "<<count<<endl;
	// cout<<"enter the preorder string: ";
	// string pre;cin>>pre;
	// cout<<"enter the inorder string: ";
	// string in;cin>>in;
	// int i=0,j=0,n=in.length();
	// t=creat(t,pre,i,in,i,n);
	// level_order(t);
}