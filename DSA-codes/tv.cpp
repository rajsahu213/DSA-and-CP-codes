#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
};

typedef struct node* btptr;

btptr creatnode(int data)
{
	btptr temp=new node;
	temp->data=data;
	temp->left=temp->right=NULL;
	return temp;
}

btptr insert(btptr &t,int data)
{
	if(t==NULL)
	{
		t=creatnode(data);
	}
	else if(t->data>=data)
	{
		t->left=insert(t->left,data);
	}
	else t->right=insert(t->right,data);
	return t;
}

void display(btptr &t,int &n)
{
	if(t!=NULL)
	{
		n++;
		display(t->left,n);
		display(t->right,n);
	}
}

void set_hd(btptr &t,int dis,int hd[],int &i,int data[])
{
	if(t!=NULL)
	{
		set_hd(t->left,dis-1,hd,i,data);		
		hd[i]=dis;
		data[i]=t->data;
		i++;
		set_hd(t->right,dis+1,hd,i,data);
	}
}

void set_vd(btptr &t,int dis,int vd[],int &i)
{
	if(t!=NULL)
	{
		set_vd(t->left,dis+1,vd,i);
		vd[i++]=dis;
		set_vd(t->right,dis+1,vd,i);
	}
}

int main()
{
	btptr t=NULL;
	while(1)
	{
		int data;
		cin>>data;
		if(data==-1)break;
		t=insert(t,data);
	}
	int n=0;
	display(t,n);
	int dis=500;
	int hd[n],vd[n],i=0,data[n];
	set_hd(t,dis,hd,i,data);
	dis=0;i=0;
	set_vd(t,dis,vd,i);
	bool vis[1000]={false};
	int arr[1000];
	memset(arr,-1,sizeof(arr));
	for(int i=0;i<n;i++)
	{
		if(!vis[hd[i]])
		{
			int v=vd[i],x=hd[i],ans=data[i];
			vis[hd[i]]=true;
			for(int j=i+1;j<n;j++)
			{
				if(hd[j]==x&&vd[j]<v){ans=data[j];v=vd[j];}
			}
			arr[hd[i]]=ans;
		}
	}
	for(int i=0;i<1000;i++)
	{
		if(arr[i]!=-1)
		{
			cout<<arr[i]<<" ";
		}
	}
	cout<<endl;
}