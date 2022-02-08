#include<bits/stdc++.h>
using namespace std;

struct bstnode
{
	int data;
	bstnode *lchild;
	bstnode* rchild;
};

typedef struct bstnode* bstptr;

bstptr creatnode(int data)
{
	bstptr temp;
	temp=new bstnode;
	temp->data=data;
	temp->lchild=temp->rchild=NULL;
	return temp;
}

bstptr creat_bst(bstptr &t,int data)
{
	if(t==NULL)t=creatnode(data);
	else if(data<t->data)t->lchild=creat_bst(t->lchild,data);
	else t->rchild=creat_bst(t->rchild,data);
	return t;
}

int min(bstptr &t)
{
	if(t->lchild==NULL)return t->data;
	else return min(t->lchild);
}

int max(bstptr &t)
{
	if(t->rchild==NULL)return t->data;
	else return max(t->rchild);
}

void range_leaf(bstptr &t,int k,int &min,int &max)
{
	if(t->lchild==NULL&&t->rchild==NULL)
	{
		cout<<"the range of "<<k<<" is ";
		if(min>INT_MIN&&max<INT_MAX)
		{
			for(int i=min+1;i<max;i++)
			{
				cout<<i<<" ";
			}
			cout<<endl;
		}
		else if(min==INT_MIN&&max<INT_MAX)
		{
			cout<<"-& to "<<max-1<<endl;
		}
		else cout<<min+1<<" to +&"<<endl;
	}
	else if(k<t->data)
	{
		range_leaf(t->lchild,k,min,t->data);
	}
	else range_leaf(t->rchild,k,t->data,max);
}

void range(bstptr &t,int k)
{
	static bstptr t1=t;
	if(t->data==k)
	{
		if(t->lchild==NULL&&t->rchild==NULL)
		{
			int n1=INT_MIN,n2=INT_MAX;
			range_leaf(t1,k,n1,n2);
		}
		else
		{
			int mi=max(t->lchild);
			int ma=min(t->rchild);
			cout<<"range of "<<k<<" is ";
			for(int i=mi+1;i<ma;i++)
			{
				cout<<i<<" ";
			}
			cout<<endl;
		}
	}
	else if(k<t->data)
	{
		range(t->lchild,k);
	}
	else range(t->rchild,k);
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

void level_order(bstptr &t)
{
	bstptr t1=t;
	queue<bstptr> q;
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
		t1=q.front();
		cout<<t1->data<<" ";
		q.pop();
		if(t1->lchild!=NULL)q.push(t1->lchild);
		if(t1->rchild!=NULL)q.push(t1->rchild);
	}
}

void snake_print1(bstptr &t)
{
	bstptr t1=t;
	queue<bstptr> q;
	stack<int> s;
	q.push(t);
	q.push(NULL);
	int flag=0;
	while(!q.empty())
	{
		if(q.front()==NULL)
		{
			flag++;
			if(flag%2==0)
			{
				while(!s.empty())
				{
					cout<<s.top()<<" ";
					s.pop();
				}
				cout<<endl;
			}
			else cout<<endl;
			q.pop();
			if(q.empty())break;
			q.push(NULL);
		}
		t1=q.front();
		if(flag%2==0)cout<<t1->data<<" ";
		else s.push(t1->data);
		q.pop();
		if(t1->lchild!=NULL)q.push(t1->lchild);
		if(t1->rchild!=NULL)q.push(t1->rchild);
	}
}
void convert(bstptr &t)
{
	static int sum=0,flag=0;
	if(t!=NULL)
	{
		convert(t->rchild);
		sum+=t->data;
		if(flag==0){t->data=0;flag=1;}
		else t->data=sum;
		convert(t->lchild);
	}
}

void dead_end(bstptr &t,int min,int max)
{
	if(t!=NULL)
	{
		if(min==max)
		{
			cout<<t->data<<" ";
		}
		dead_end(t->lchild,min,t->data-1);
		dead_end(t->rchild,t->data+1,max);
	}
}

void preorder_iter(bstptr &t)
{
	stack<bstptr> s;
	s.push(t);
	while(!s.empty())
	{
		bstptr t1=s.top();
		s.pop();
		while(t1!=NULL)
		{
			if(t1->rchild!=NULL)s.push(t1->rchild);
			cout<<t1->data<<" ";
			t1=t1->lchild;
		}

	}
}

void inorder_iter(bstptr &t)
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
		bstptr t2=s.top();
		s.pop();
		cout<<t2->data<<" ";
		if(t2->rchild!=NULL)
		{
			bstptr t3=t2->rchild;
			while(t3!=NULL)
			{
				s.push(t3);
				t3=t3->lchild;
			}
		}
	}
}

struct node{
    int data,min,max;
    node(int val,int mi,int ma){
        data=val;min=mi;max=ma;
    }
};

bool check_level(vector<int> &a){
    if(a.size()<=1)return true;
    queue<node> q;
    node temp(a[0],INT_MIN,INT_MAX);
    q.push(temp);int i=1;
    while(!q.empty() && i<a.size()){
        node temp=q.front();q.pop();
        if(a[i]>temp.min && a[i]<temp.data){
            node temp1(a[i],temp.min,temp.data);
            q.push(temp1);
            i++;
        }
        if(i==a.size())break;
        if(a[i]<temp.max && a[i]>temp.data){
            node temp1(a[i],temp.data,temp.max);
            q.push(temp1);
            i++;
        }
    }
    if(i==a.size())return true;
    else return false;
}

void swap_wrng(bstptr &t,int min,int max)
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
		swap_wrng(t->lchild,min,t->data-1);
		swap_wrng(t->rchild,t->data+1,max);
	}
}

int LCA(bstptr &t,int k1,int k2)
{
	if(k1>t->data&&k2<t->data||k1<t->data&&k2>t->data)return t->data;
	else if(k1<t->data&&k2<t->data)return LCA(t->lchild,k1,k2);
	else if(k1>t->data&&k2>t->data)return LCA(t->rchild,k1,k2);
}

bool is_bst(bstptr &t,int min,int max)
{
	if(t==NULL)return true;
	if(t->data<min||t->data>max)return false;
	return is_bst(t->lchild,min,t->data-1)&&is_bst(t->rchild,t->data+1,max);
}

int sum_leaf(bstptr &t)
{
	if(t==NULL)return 0;
	if(t->lchild==NULL&&t->rchild==NULL)return t->data;
	else return sum_leaf(t->lchild)+sum_leaf(t->rchild);
}

bool is_dead(bstptr &t,int min,int max)
{
	if(t==NULL)return false;
	if(min==max)return true;
	else return is_dead(t->lchild,min,t->data-1)||is_dead(t->rchild,t->data+1,max);
}

struct node
{
	bstptr nodeptr;
	int min;
	int max;
};

void creat_level(bstptr &t,int a[],int n)
{
	t=creatnode(a[0]);
	queue<node> q;
	struct node t3;
	t3.nodeptr=t;
	t3.min=INT_MIN;
	t3.max=INT_MAX;
	q.push(t3);
	int i=1;
	while(i<n)
	{
		struct node t1=q.front();
		q.pop();
		if(a[i]<t1.nodeptr->data&&a[i]>t1.min)
		{
			struct node t2;
			t2.nodeptr=creatnode(a[i]);
			t2.min=t1.min;
			t2.max=t1.nodeptr->data-1;
			t1.nodeptr->lchild=t2.nodeptr;
			q.push(t2);
			i++;
		}
		if(i==n)break;
		if(a[i]>t1.nodeptr->data&&a[i]<t1.max)
		{
			struct node t2;
			t2.nodeptr=creatnode(a[i]);
			t2.min=t1.nodeptr->data+1;
			t2.max=t1.max;
			t1.nodeptr->rchild=t2.nodeptr;
			q.push(t2);
			i++;
		}
	}
}

int index(int a[],int i,int n)
{
	for(int j=i+1;j<n;j++)
	{
		if(a[j]>a[i])return j;
	}
}

void creat_bst_preorder(bstptr &t,int a[],int i,int n)
{
	if(i>=n)return;
	else
	{
		t=creatnode(a[i]);
		creat_bst_preorder(t->lchild,a,i+1,index(a,i,n));
		creat_bst_preorder(t->rchild,a,index(a,i,n),n);
	}
}

int index2(int a[],int i,int n)
{
	for(int j=i+1;j<n;j++)
	{
		if(a[j]<a[i])return j;
	}
}

void creat_bst_postorder(bstptr &t,int a[],int i,int n)
{
	if(i>=n)return;
	else
	{
		t=creatnode(a[i]);
		creat_bst_postorder(t->rchild,a,i+1,index2(a,i,n));
		creat_bst_postorder(t->lchild,a,index2(a,i,n),n);
	}
}

void print(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

void print_path(bstptr &t,int a[],int i)
{
	if(t!=NULL)
	{
		if(t->lchild==NULL&&t->rchild==NULL)
		{
			a[i++]=t->data;
			print(a,i);
		}
		else a[i++]=t->data;
		print_path(t->lchild,a,i);
		print_path(t->rchild,a,i);
	}
}

int path_length(bstptr &t,int k,int &count)
{
	if(t->data==k)return count;
	else if(k<t->data)path_length(t->lchild,k,++count);
	else path_length(t->rchild,k,++count);
}

void creat_fib(bstptr &t,bstptr t1,bstptr t2,int n)
{
	if(t->data==n)return;
	else
	{
		t=creatnode(t1->data+t2->data);
		t->lchild=t1;
		t->rchild=t2;
		creat_fib(t,t,t1,n);
	}
}

int max(int a,int b,int c,int d)
{
	int max=a;
	if(b>max)max=b;
	if(c>max)max=c;
	if(d>max)max=d;
	return max;
}
int max1(int a,int b)
{
	if(a>b)return a;
	else return b;
}

int mid_lev(bstptr &t)
{
	if(t==NULL)
	{
		return -1;
	}
	else if(t->lchild==NULL&&t->rchild==NULL)
	{
		return 0;
	}
	else
	{
		if(t->lchild==NULL)
		{
			return max1(mid_lev(t->rchild->rchild),mid_lev(t->rchild->lchild))+1;
		}
		else if(t->rchild==NULL)
		{
			return max1(mid_lev(t->lchild->lchild),mid_lev(t->lchild->rchild))+1;
		}
		else return max(mid_lev(t->lchild->lchild),mid_lev(t->rchild->rchild),mid_lev(t->lchild->rchild),mid_lev(t->rchild->lchild))+1;
	}
}

void pri(int n,vector<bstptr> &p,vector<int> &a,int &count)
{
  if(a.size() == n){
    for(int i=0;i<n;i++) cout << a[i] << " ";
    cout << endl;
		count++;
    return;
  }
  for(int i=0;i<p.size();i++)
	{
    bstptr t = p[i];
    p.erase(p.begin()+i);
    if(t->lchild) p.push_back(t->lchild);
    if(t->rchild) p.push_back(t->rchild);
    a.push_back(t->data);
    pri(n,p,a,count);
    a.pop_back();
    if(t->lchild) p.pop_back();
    if(t->rchild) p.pop_back();
    p.insert(p.begin()+i,t);
  }
}

int main()
{
	// cout<<"enter n: ";
	// int n;cin>>n;
	// bstptr t=NULL;
	// for(int i=0;i<n;i++)
	// {
	// 	int data;cin>>data;
	// 	creat_bst(t,data);
	// }
	// level_order(t);
	// int a[20];
	// int i=0;
	// cout<<"the paths are\n";
	// print_path(t,a,i);
	// cout<<sum_leaf(t)<<endl;
	// cout<<is_dead(t,INT_MIN,INT_MAX)<<endl;
	// cout<<"enter k1 and k2: ";
	// int k1,k2;
	// cin>>k1>>k2;
	// int n1,n2,n3;
	// n1=path_length(t,k1,i);
	// i=0;
	// n2=path_length(t,k2,i);
	// i=0;
	// int lca=LCA(t,k1,k2);
	// n3=path_length(t,lca,i);
	// int result=n1+n2-2*n3;
	// cout<<result<<endl;
	// cout<<"LCA of "<<k1<<" and "<<k2<<" is "<<lca<<endl;
	//cout<<is_bst(t,INT_MIN,INT_MAX)<<endl;
	//snake_print1(t);
	//snake_print2(t);
	// t->lchild->lchild->data=35;
	// t->rchild->rchild->data=15;
	// preorder(t);
	// cout<<endl;
	// swap_wrng(t,INT_MIN,INT_MAX);
	// preorder(t);
	// cout<<endl;
	// inorder_iter(t);
	// cout<<endl;
	// cout<<"enter k: ";
	// int k;cin>>k;
	// range(t,k);
	// inorder(t);
	// cout<<endl;
	// postorder(t);
	// cout<<endl;
	// level_order(t);
	// // dead_end(t,INT_MIN,INT_MAX);
	// // cout<<endl;
	// preorder_iter(t);
	// cout<<endl;
	// // convert(t);
	// // level_order(t);
	// //check_level_order(n);
	// cout<<"enter the array\n";
	// int a[n];
	// for(int i=0;i<n;i++)cin>>a[i];
	// bstptr t=NULL;
	// int i=0;
	//creat_bst_preorder(t,a,i,n);
	//creat_level(t,a,n);
	// reverse(a,a+n);
	// creat_bst_postorder(t,a,i,n);
	// level_order(t);
	// cout<<"enter n: ";
	// int n;cin>>n;
	// bstptr t1=creatnode(1);
	// bstptr t2=creatnode(1);
	// bstptr t=creatnode(2);
	// creat_fib(t,t1,t2,n);
	// level_order(t);
	// inorder_iter(t);
	// cout<<"the middle level is: "<<mid_lev(t)<<endl;
	// vector<int> a;
	// vector<bstptr> p;
	// p.push_back(t);
	// int count=0;
	// pri(n,p,a,count);
	// cout<<count<<endl;
	// cin.get();
	// cin.get();
	return 0;
}
