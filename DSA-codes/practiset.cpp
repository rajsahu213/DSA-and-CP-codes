#include<iostream>
#include<stack>
#include<queue>
#include<climits>
using namespace std;

struct bstnode
{
	int data;
	bstnode *lchild;
	bstnode *rchild;
};

typedef struct bstnode* bstptr;

void insert(bstptr &t,int data)
{
	if(t==NULL)
	{
		bstptr temp;
		temp=new(bstnode);
		temp->data=data;
		temp->lchild=temp->rchild=NULL;
		t=temp;
	}
	else
	{
		if(data<t->data)
		{
			insert(t->lchild,data);
		}
		else{
			insert(t->rchild,data);
		}
	}
}



// void print(bstptr &t)
// {
// 	static bstptr t1=t,t2;
// 	static int flag=0;
// 	if(t!=NULL)
// 	{
// 		if(t->lchild==NULL&&t->rchild==NULL){t2=t;flag=0;}
// 		print(t->lchild);
// 		print(t->rchild);
// 	}
// 	if(t==NULL&&flag==0){print1(t1,t2);cout<<t2->data<<endl;flag=1;}
// }

void inorder(bstptr &t)
{
	if(t!=NULL)
	{
		inorder(t->lchild);
		cout<<t->data<<" ";
		inorder(t->rchild);
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

void min_max(bstptr &t)
{
	static int flag=0;
	static bstptr t1=t;
	if(flag==0){
	if(t->lchild==NULL){cout<<"the min is: "<<t->data<<endl;}
	if(t->lchild!=NULL)
	{
		min_max(t->lchild);
	}
	}
	flag=1;
	if(t==t1)
	{
		if(t->rchild==NULL){cout<<"the max is: "<<t->data<<endl;}
		if(t->rchild!=NULL)
		{
			t1=t1->rchild;
			min_max(t->rchild);
		}
	}
}

int min(bstptr &t)
{
	if(t->lchild==NULL)return t->data;
	else min(t->lchild);
}

int max(bstptr &t)
{
	if(t->rchild==NULL)return t->data;
	else max(t->rchild);
}

void level_order(bstptr &t)
{
	queue<bstptr> q;
	q.push(t);
	q.push(NULL);
	bstptr t1=t,t2;
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
		if(t1->lchild!=NULL)q.push(t1->lchild);
		if(t1->rchild!=NULL)q.push(t1->rchild);
	}
}

void convert(bstptr &t)
{
	static int sum=0;
	if(t!=NULL)
	{
		convert(t->rchild);
		sum+=t->data;
		t->data=sum-t->data;
		convert(t->lchild);
	}
}

void range_leaf(bstptr &t,int k,int min,int max)
{
	if(t->data==k)
	{
		if(min==INT_MIN){cout<<"lesser than "<<max<<endl;}
		else if(max==INT_MAX){cout<<"greater than "<<min<<endl;}
		else {
			cout<<"the range is : ";
			for(int i=min;i<=max;i++){cout<<i<<" ";}
			cout<<endl;
		}	
	}
	else
	{
		if(k<t->data)range_leaf(t->lchild,k,min,t->data-1);
		else range_leaf(t->rchild,k,t->data+1,max);
	}
}

int max(int a,int b)
{
	if(a>b)return a;
	else return b;
}

int find_h(bstptr &t)
{
	static int lh,rh;
	if(t==NULL)return -1;
	else
	{
		lh=find_h(t->lchild);
		rh=find_h(t->rchild);
	}
	return max(lh,rh)+1;
}

bool check_bst(bstptr &t,int min,int max)
{
	if(t==NULL)return true;
	if(t->data<max&&t->data>min)
	{
		if(check_bst(t->lchild,min,t->data)&&check_bst(t->rchild,t->data,max))
		{
			return true;
		}
	}
	return false;
}

void range(bstptr &t,int k)
{
	static bstptr t1=t;
	if(t->data==k)
	{
		if(t->lchild==NULL||t->rchild==NULL)range_leaf(t1,k,INT_MIN,INT_MAX);
		else
		{
			int mi=max(t->lchild);
			int ma=min(t->rchild);
			cout<<"the range of "<<k<<" is\n";
			for(int i=mi+1;i<ma;i++)cout<<i<<" ";
			cout<<endl;
		}
	}
	else
	{
		if(k<t->data)range(t->lchild,k);
		else range(t->rchild,k);
	}
}

void preorder_iter(bstptr &t)
{
	stack<bstptr> s;
	s.push(t);
	bstptr t1=t,t2;
	while(!s.empty())
	{
		t1=s.top();
		s.pop();
		while(t1!=NULL)
		{
			cout<<t1->data<<" ";
			if(t1->rchild!=NULL)
			{
				s.push(t1->rchild);
			}
			t1=t1->lchild;
		}
	}
}

void inorder_iter(bstptr &t)
{
	stack<bstptr> s;
	bstptr t1=t,t2;
	while(t1!=NULL)
	{
		s.push(t1);
		t1=t1->lchild;
	}
	while(!s.empty())
	{
		t1=s.top();
		cout<<t1->data<<" ";
		s.pop();
		if(t1->rchild!=nullptr)
		{
			t2=t1->rchild;
			while(t2!=NULL)
			{
				s.push(t2);
				t2=t2->lchild;
			}
		}
	}
}

bstptr creatnode(int data)
{
	bstptr temp;
	temp=new(bstnode);
	temp->data=data;
	temp->lchild=temp->rchild=NULL;
	return temp;
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
		while((a[i-1]>a[i])&&i<n)
		{
			t->lchild=creatnode(a[i]);
			t=t->lchild;
			s.push(t);
			i++;
		}	
		while(!s.empty()&&s.top()->data<a[i])
		{
			t=s.top();
			s.pop();
		}
		if(i<n){
		t->rchild=creatnode(a[i]);
		t=t->rchild;
		s.push(t);
		}
		i++;
	}
	return t1;
}

int preorder(bstptr &t)
{
	static bstptr t1=t;
	static int sum=0;
	if(t!=NULL)
	{
		if(t->lchild==NULL&&t->rchild==NULL)
		{
			sum+=t->data;
		}
		if(t->data==max(t1))return sum;			
		preorder(t->lchild);
		preorder(t->rchild);	
	}
}



int main()
{
	int t;cin>>t;
	while(t--){
	bstptr t=NULL;
	cout<<"enter n: ";
	int n;cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"enter the number: ";
		int data;cin>>data;
		insert(t,data);
	}
	cout<<preorder(t)<<endl;
	cout<<endl;}
	// // print(t);
	// level_order(t);
	// // min_max(t);
	// // cout<<"enter k: ";
	// // int k;cin>>k;
	// // range(t,k);
	// //convert(t);
	// //level_order(t);
	// cout<<"the height of the tree is: "<<find_h(t)<<endl;
	// cout<<"enter n: ";
	// int n;cin>>n;
	// int a[n];
	// cout<<"enter the numbers\n";
	// for(int i=0;i<n;i++)
	// {
	// 	cin>>a[i];
	// }
	// bstptr t=NULL;
	// t=creat_bst(t,a,n);
	// //preorder(t);
	// level_order(t);
}