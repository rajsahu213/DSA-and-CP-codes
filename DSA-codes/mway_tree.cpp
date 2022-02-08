#include<bits/stdc++.h>
using namespace std;

struct mstnode
{
	int cnt;
	int key[100];
	mstnode* cptr[100];
};

typedef struct mstnode* mstptr;

void sort(mstptr &t,int m)
{
	int last,flag;
	for(int i=0;i<m;i++)
	{
		last=m-i-1;
		flag=0;
		for(int j=0;j<last;j++)
		{
			if(t->key[j+1]<t->key[j])
			{int temp=t->key[j];t->key[j]=t->key[j+1];t->key[j+1]=temp;flag=1;}
		}
		if(flag==0)break;
	}
}

mstptr creatnode(int data,int m)
{
	mstptr temp;
	temp=new mstnode;
	temp->cnt=1;
	temp->key[0]=data;
	for(int i=1;i<m-1;i++)
	{
		temp->key[i]=-1;
		temp->cptr[i]=NULL;
	}
	temp->cptr[0]=temp->cptr[m]=NULL;
	return temp;
}

void creat(mstptr &t,int m,int data,int &flag)
{
	if(t==NULL)
	{
		t=creatnode(data,m);
		return;
	}
	else if(t->cnt<m-1)
	{
		t->key[t->cnt]=data;
		t->cnt++;
		sort(t,t->cnt);
		return;
	}
	else
	{
		for(int i=0;i<m-1;i++)
		{
			if(data<t->key[i])
			{
				flag=1;
				creat(t->cptr[i],m,data,flag);
				break;
			}
		}
		if(flag==0)creat(t->cptr[t->cnt],m,data,flag);
	}
}

void inorder(mstptr &t,int m)
{
	if(t!=NULL)
	{
		for(int i=0;i<t->cnt;i++)
		{
			inorder(t->cptr[i],m);
			cout<<t->key[i]<<" ";
		}
		inorder(t->cptr[t->cnt],m);
	}
}

void search(mstptr &t,int x,int &flag)
{
	if(t!=NULL)
	{
		for(int i=0;i<t->cnt;i++)
		{
			search(t->cptr[i],x,flag);
			if(t->key[i]==x)flag=1;
		}
		search(t->cptr[t->cnt],x,flag);
	}
}

void level_order(mstptr &t,int m)
{
    queue<mstptr> q;
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
        mstptr t1=q.front();
        for(int i=0;i<t1->cnt;i++)
        {
        	if(i==0)cout<<"< ";
        	cout<<t1->key[i]<<" ";
        	if(i==t1->cnt-1)cout<<"> ";
        }
        q.pop();
        for(int i=0;i<m;i++)
        {
        	if(t1->cptr[i]!=NULL)
        	{
        		q.push(t1->cptr[i]);
        	}
        }
    }
}

int main()
{
	cout<<"enter m: ";
	int m;cin>>m;
	cout<<"enter n: ";
	int n;cin>>n;
	cout<<"enter the numbers\n";
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	mstptr t=NULL;
	for(int i=0;i<n;i++)
	{
		int flag=0;
		creat(t,m,a[i],flag);
	}
	inorder(t,m);
	cout<<endl;
	cout<<"enter a number: ";
	int x;cin>>x;
	int flag=0;
	search(t,x,flag);
	cout<<flag<<endl;
	level_order(t,m);
}