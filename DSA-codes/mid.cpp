#include<bits/stdc++.h>
using namespace std;

// struct btnode
// {
// 	int hd;
// 	int vd;
// 	char data;
// 	btnode* lchild;
// 	btnode* rchild;
// };

struct btnode
{
	int data;
	int hd;
	int vd;
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

btptr creat(btptr &t,char a[],int &i,int n)
{
	t=creatnode(a[i]);
	if(t==NULL||i>=n)return t;
	t->lchild=creat(t->lchild,a,++i,n);
	t->rchild=creat(t->rchild,a,++i,n);
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
        if(t1->lchild!=NULL)q.push(t1->lchild);
        if(t1->rchild!=NULL)q.push(t1->rchild);
    }
}

bool is_there(char a,char in[],int i,int n)
{
	for(int j=i;j<n;j++)
	{
		if(in[j]==a)return true;
	}
	return false;
}

int index(char ch,char a[],int n)
{
	for(int j=0;j<n;j++)
	{
		if(a[j]==ch)return j;
	}
	return -1;
}

btptr creat_pre(btptr &t,char pre[],int &p,char in[],int i,int n)
{
	int k=index(pre[p],in,n);
	if(is_there(pre[p],in,i,n))
	{
		t=creatnode(pre[p++]);
	}
	else t=NULL;
	if(t==NULL||i>=n)return t;
	t->lchild=creat_pre(t->lchild,pre,p,in,i,k);
	t->rchild=creat_pre(t->rchild,pre,p,in,k+1,n);
	return t;
}

btptr creat_post(btptr &t,char post[],int &p,char in[],int i,int n)
{
	int k=index(post[p],in,n);
	if(is_there(post[p],in,i,n))
	{
		t=creatnode(post[p++]);
	}
	else t=NULL;
	if(t==NULL||i>=n)return t;
	t->rchild=creat_post(t->rchild,post,p,in,k+1,n);
	t->lchild=creat_post(t->lchild,post,p,in,i,k);
	return t;
}

int count_leaf(btptr &t)
{
    if(t==NULL)return 0;
    if(t->lchild==NULL&&t->rchild==NULL)return 1;
    else return count_leaf(t->lchild)+count_leaf(t->rchild);
}

void left_view(btptr &t,int l,int &m)
{
    if(t!=NULL)
    {
        if(l>m)
        {
            cout<<t->data<<" ";
            m=l;
        }
        left_view(t->lchild,l+1,m);
        left_view(t->rchild,l+1,m);
    }
}

void right_view(btptr &t,int l,int &m)
{
    if(t!=NULL)
    {
        if(l>m)
        {
            cout<<t->data<<" ";
            m=l;
        }
        right_view(t->rchild,l+1,m);
        right_view(t->lchild,l+1,m);
    }
}

void serialization(btptr &t)
{
	if(t==NULL)
	{
		cout<<".";
		return;
	}
	else
	{
		cout<<t->data;
		serialization(t->lchild);
		serialization(t->rchild);
	}
}

void set_hd(btptr &t)
{
	static int i=1;
	if(t!=NULL)
	{
		set_hd(t->lchild);
		t->hd=i++;
		set_hd(t->rchild);
	}
}

void set_vd(btptr &t,int vd)
{
	if(t!=NULL)
	{
		t->vd=vd;
		set_vd(t->lchild,vd+1);
		set_vd(t->rchild,vd+1);
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


void print_bt(btptr &t)
{
    queue<btptr> q;
    q.push(t);
    q.push(NULL);
    int start=0;
    while(!q.empty())
    {
        if(q.front()==NULL)
        {
            cout<<endl;
            q.pop();
            if(q.empty())break;
            q.push(NULL);
            start=0;
        }
        btptr t1=q.front();
        for(int i=start;i<t1->hd;i++)cout<<" ";
        cout<<t1->data;
    	start=t1->hd+1;
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

int find_h(btptr &t)
{
	if(t==NULL)return -1;
	else return max(find_h(t->lchild),find_h(t->rchild))+1;
}

bool search(btptr &t,int x)
{
	if(t==NULL)return false;
	else if(t->data==x)return true;
	return search(t->lchild,x)+search(t->rchild,x);
}

void print(char a[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

void print_path(btptr &t,char a[],int i)
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

void creat_level(btptr &t,int a[],int i,int n)
{
	if(i>=n)return;
	else
	{
		t=creatnode(a[i]);
		creat_level(t->lchild,a,2*i+1,n);
		creat_level(t->rchild,a,2*i+2,n);
	}
}

int LCA(btptr &t,int k1,int k2)
{
	if(search(t->lchild,k1)&&search(t->rchild,k2)||search(t->lchild,k2)&&search(t->rchild,k1))return t->data;
	else if(search(t->lchild,k1)&&search(t->lchild,k2))return LCA(t->lchild,k1,k2);
	else if(search(t->rchild,k1)&&search(t->rchild,k2))return LCA(t->rchild,k1,k2);
}

int max_index(int a[],int j,int n)
{
	int max=j;
	for(int i=j+1;i<n;i++)
	{
		if(a[i]>a[max])max=i;
	}
	return max;
}

void creat_max(btptr &t,int a[],int i,int n)
{
	if(i>=n)return;
	else
	{
		int k=max_index(a,i,n);
		t=creatnode(a[k]);
		creat_max(t->lchild,a,i,k);
		creat_max(t->rchild,a,k+1,n);
	}
}

void inorder_bt(btptr &t,int a[],int &i)
{
	if(t!=NULL)
	{
		inorder_bt(t->lchild,a,i);
		a[i++]=t->data;
		inorder_bt(t->rchild,a,i);
	}
}

void bt_to_bst(btptr &t,int a[])
{
	static int i=0;
	if(t!=NULL)
	{
		bt_to_bst(t->lchild,a);
		t->data=a[i++];
		bt_to_bst(t->rchild,a);
	}
}

int no_of_nodes(btptr &t)
{
	if(t==NULL)return 0;
	else if(t->lchild==NULL&&t->rchild==NULL)return 1;
	else return no_of_nodes(t->lchild)+no_of_nodes(t->rchild)+1;
}

int main()
{
	cout<<"enter n: ";
	int n;cin>>n;
	//cout<<"enter the serialization: ";
	int a[n];
	// for(int i=0;i<n;i++)cin>>a[i];
	// btptr t=NULL;
	// int i=0;
	// creat(t,a,i,n);
	// level_order(t);
	// int max=INT_MIN;
	// int sum=0;
	// max_sum_path(t,max,sum);
	// cout<<max<<endl
	// cout<<"no of leaf nodes are: "<<count_leaf(t)<<endl;
	// int l=0,m=-1;
	// left_view(t,l,m);
	// cout<<endl;
	// right_view(t,l,m);
	// cout<<endl;
	// cout<<"the serialization of the entered tree is: ";
	// serialization(t);
	// cout<<endl;
	// int vd=0;
	// cout<<find_h(t)<<endl;
	// cout<<"enter a char: ";
	// char c;cin>>c;
	// cout<<search(t,c)<<endl;
	// char arr[n];;
	// print_path(t,arr,0);
	//set_vd(t,vd);
	// cout<<"enter the preorder array: ";
	// char pre[n];
	// for(int i=0;i<n;i++)cin>>pre[i];
	// cout<<"enter the postorder array: ";
	// char post[n];
	// for(int i=0;i<n;i++)cin>>post[i];
	// cout<<"enter the inorder array: ";
	// char in[n];
	// for(int i=0;i<n;i++)cin>>in[i];
	//creat_pre(t,pre,i,in,i,n);
	// reverse(post,post+n);
	// creat_post(t,post,i,in,i,n);
	//level_order(t);
	cout<<"enter the level order array( of complete binary tree)\n";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int i=0;
	btptr t=NULL;
	creat_level(t,a,i,n);
	//creat_max(t,a,i,n);
	int hd=0;
	set_hd(t);
	print_bt(t);
	// cout<<"enter k1 and k2: ";
	// int k1,k2;
	// cin>>k1>>k2;
	// cout<<"LCA of "<<k1<<" and "<<k2 <<" is "<<LCA(t,k1,k2)<<endl;
	// int in[100];
	// int k=0;
	// inorder_bt(t,in,k);
	// sort(in,in+k);
	// bt_to_bst(t,in);
	// print_bt(t);
	cout<<no_of_nodes(t)<<endl;
}