#include<bits/stdc++.h>
using namespace std;

struct btnode
{
	int data;
	btnode* lchild;
	btnode* rchild;
};

typedef struct btnode* btptr;

btptr creatnode(int data)
{
	btptr temp;
	temp=new(btnode);
	temp->data=data;
	temp->lchild=temp->rchild=NULL;
	return temp;
}

void creat_bt_from_lo(btptr &t,int a[],int i,int n)
{
	if(i<n)
	{
		t=creatnode(a[i]);
		creat_bt_from_lo(t->lchild,a,2*i+1,n);
		creat_bt_from_lo(t->rchild,a,2*i+2,n);
	}
}

void insert_heap(int h[],int &n,int x)
{
	int i=n;
	h[n]=x;
	while((i-1)/2>=0)
	{
		if(h[(i-1)/2]>h[i]){int temp=h[i];h[i]=h[(i-1)/2];h[(i-1)/2]=temp;i=(i-1)/2;}
		else break;
	}
	n++;
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


void convert_into_min_heap(int h[],int n)
{
	for(int i=0;i<n;i++)
	{
		insert_heap(h,i,h[i]);
	}
}


void convert_into_max_heap(int h[],int n)
{
	for(int k=n-1;k>=0;k--)
	{
		int i=k;
		while(2*i+1<n)
		{
			int l=2*i+1,r=2*i+2;
			if(h[l]>h[i]&&h[r]>h[i])
			{
				if(h[l]>h[r]){int temp=h[l];h[l]=h[i];h[i]=temp;i=l;}
				else{int temp=h[r];h[r]=h[i];h[i]=temp;i=r;}
			}
			else if(h[r]>h[i]||h[l]>h[i])
			{
				if(h[l]>h[i]){int temp=h[l];h[l]=h[i];h[i]=temp;i=l;}
				else{int temp=h[r];h[r]=h[i];h[i]=temp;i=r;}
			}
			else break;
		}
	}
}


int main()
{
	cout<<"enter n: ";
	int n;cin>>n;
	cout<<"enter the array\n";
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	btptr t=NULL;
	int i=0;
	creat_bt_from_lo(t,a,i,n);
	cout<<"the entered tree is\n";
	level_order(t);
	int h[n+10];
	for(int i=0;i<n;i++)h[i]=a[i];
	convert_into_min_heap(h,n);
	//convert_into_max_heap(h,n);
	btptr t1=NULL;
	i=0;
	creat_bt_from_lo(t1,h,i,n);
	cout<<"the converted heap is\n";
	level_order(t1);
	// cout<<"enter the running array\n";
	// int a[n],min_heap[n],max_heap[n];
	// for(int i=0;i<n;i++)
	// {
	// 	cin>>a[i];
	// 	min_heap[i]=a[i];
	// 	max_heap[i]=a[i];
	// 	if(i==0)cout<<a[i]<<endl;
	// 	else
	// 	{
	// 		convert_into_min_heap(min_heap,i+1);
	// 		convert_into_max_heap(max_heap,i+1);
	// 		cout<<(min_heap[0]+max_heap[0])/2<<endl;
	// 	}
	// }
	// cout<<"enter the array(for rank)\n";
	// int h[n];
	// for(int i=0;i<n;i++)cin>>h[i];
	// convert_into_min_heap_for_rank(h,n);
	// for(int i=0;i<n;i++)
	// {
	// 	cout<<"the rank of "<<h[i]<<" is "<<i+1<<endl;
	// }
}