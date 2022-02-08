#include<iostream>
#include<stack>
#include<climits>
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

void preorder(bstptr &t)
{
	stack<bstptr> s;
	s.push(t);
	while(!s.empty())
	{
		bstptr temp=s.top();
		s.pop();
		while(temp!=NULL)
		{
			if(temp->rchild!=NULL)
			{
				s.push(temp->rchild);
			}
			cout<<temp->data<<" ";
			temp=temp->lchild;
		}
	}
}

void find_de(bstptr &t,int min,int max)
{

	if(t!=NULL)
	{
		if(min==max){cout<<t->data<<" ";}	
		find_de(t->lchild,min,t->data-1);
		find_de(t->rchild,t->data+1,max);
	}
}

void swap_2_wrong(bstptr &t,int min,int max)
{
	static int flag=0;
	static bstptr t1;
	if(t!=NULL)
	{
		if(t->data<min||t->data>max)
		{
			if(flag==0){t1=t;flag=1;}
			else{int temp=t1->data;t1->data=t->data;t->data=temp;}
		}	
		swap_2_wrong(t->lchild,min,t->data-1);
		swap_2_wrong(t->rchild,t->data+1,max);
	}
}

bool check_bst(bstptr &t,int min,int max)
{
	if(t==NULL)
	{
		return true;
	}
	if(t->data>min&&t->data<max)
	{
		if(check_bst(t->lchild,min,t->data)&&check_bst(t->rchild,t->data,max))
		{
			return true;
		}
	}
	else{
		return false;
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
	cout<<"the preorder traversal of the tree is \n";
	preorder(t);
	cout<<endl;
	// inorder(t);
	// cout<<endl;
	// find_de(t,INT_MIN,INT_MAX);
	// cout<<endl;
	// t->lchild->rchild->data=28;
	// t->rchild->lchild->data=23;
	// preorder(t);
	// cout<<endl;
	// if(check_bst(t,INT_MIN,INT_MAX)){cout<<"the entered tree is a binary search tree\n";}
	// else{cout<<"the entered tree is not a binary search tree\n";}	
	// swap_2_wrong(t,INT_MIN,INT_MAX);
	// preorder(t);
	// cout<<endl;
	// if(check_bst(t,INT_MIN,INT_MAX)){cout<<"the entered tree is a binary search tree\n";}
	// else{cout<<"the entered tree is not a binary search tree\n";}	

}