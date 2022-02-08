#include<iostream>
#include<stack>
#include<queue>
#include<climits>
using namespace std;

struct bstnode{
	int data;
	bstnode *left;
	bstnode *right;
};

typedef struct bstnode* bstptr;

bstptr creatnode(int data)
{
	bstptr temp;
	temp=new(bstnode);
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

void creat_bst(bstptr &t,int a[],int n)
{
	stack<bstptr> s;
	bstptr temp,temp1;
	int i=0;
	t=creatnode(a[0]);
	s.push(t);
	bstptr t1=t;
	while(a[i+1]<a[i])
	{
		t1->left=creatnode(a[i+1]);
		t1=t1->left;
		s.push(t1);
		i++;
	}
	i++;	
	while(i<n)
	{
		if(s.top()->data<a[i])
		{
			while((!s.empty())&&(s.top()->data<a[i]))
			{
				temp=s.top();
				s.pop();
			}
			temp->right=creatnode(a[i]);
			s.push(temp->right);
			i++;
		}
		else
		{
			temp=s.top();
			temp->left=creatnode(a[i]);
			s.push(temp->left);
			i++;
		}
	}
}

bstptr creat_bst(bstptr &t,int a[],int n)
{
	stack<bstptr> s;
	t=creatnode(a[0]);
	s.push(t);
	bstptr t1=t;
	int i=1;
	while(i<n)
	{
		while(a[i-1]>a[i])
		{
			t->left=creatnode(a[i]);
			t=t->left;
			s.push(t);
			i++;
		}	
		while(!s.empty()&&s.top()->data<a[i])
		{
			t=s.top();
			s.pop();
		}
		if(i<n){
		t->right=creatnode(a[i]);
		t=t->right;
		s.push(t);
	}
		i++;
	}
	return t1;
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
		if(t1->left!=NULL){q.push(t1->left);}
		if(t1->right!=NULL){q.push(t1->right);}
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
			//if(flag%2==0)cout<<endl;
			if(flag%2!=0)
			{
				while(!s.empty()){cout<<s.top()->data<<" ";s.pop();}
				//cout<<endl;
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
		if(t1->left!=NULL){q.push(t1->left);}
		if(t1->right!=NULL){q.push(t1->right);}
	}
}

void preorder(bstptr &t)
{
	if(t!=NULL)
	{
		cout<<t->data<<" ";
		preorder(t->left);
		preorder(t->right);
	}
}

int main()
{
	bstptr t=NULL;
	cout<<"enter n: ";
	int n;cin>>n;
	int a[n];
	cout<<"enter the array\n";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	creat_bst(t,a,n);
	preorder(t);
	cout<<endl;
	level_order(t);
	cout<<endl;
	zig_zag1(t);
	cout<<endl;
}