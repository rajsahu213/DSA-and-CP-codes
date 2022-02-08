#include<bits/stdc++.h>
#define d 1
using namespace std;
struct btnode
{
	int count;
	int key[2*d+1];
	btnode* ptr[2*d+2];
};
typedef struct btnode* btptr;
btptr creatnode(int data)
{
	btptr temp;
	temp=new btnode;
	for(int i=0;i<2*d+1;i++)
	{
		temp->key[i]=-1;
		temp->ptr[i]=NULL;
	}
	temp->ptr[2*d+1]=NULL;
	temp->key[0]=data;
	temp->count=1;
	return temp;
}
void level_order(btptr &t)
{
	btptr t1=creatnode(INT_MIN);
	btptr t2=creatnode(INT_MAX);
	queue<btptr> q;
	q.push(t1);q.push(t);q.push(t2);q.push(NULL);
	while(!q.empty())
	{
		if(q.front()==NULL)
		{
			cout<<endl;
			q.pop();
			if(q.empty())break;
			q.push(NULL);
		}
		btptr t3=q.front();
		if(t3==t1){cout<<"< ";q.pop();}
		else if(t3==t2){cout<<">";q.pop();}
		else
		{
			for(int i=0;i<t3->count;i++)
			{
				cout<<t3->key[i]<<" ";
			}
			q.pop();
			for(int i=0;i<=t3->count;i++)
			{
				if(t3->ptr[i]!=NULL){q.push(t1);q.push(t3->ptr[i]);q.push(t2);}
			}
		}
	}
}
bool is_leaf(btptr &t)
{
	for(int i=0;i<2*d+2;i++)
	{
		if(t->ptr[i]!=NULL)
		{
			return false;
		}
	}
	return true;
}
void sorting(btptr &t)
{
	int last;
	for(int i=0;i<t->count;i++)
	{
		last=t->count-i-1;
		for(int j=0;j<last;j++)
		{
			if(t->key[j+1]<t->key[j])swap(t->key[j+1],t->key[j]);
		}
	}
}
void mid(btptr &t,int a[],int data)
{
	for(int i=0;i<2*d;i++)
	{
		a[i]=t->key[i];
	}
	a[2*d]=data;
	sort(a,a+2*d+1);
}
btptr prev_not_null(btptr &prev,btptr &t,btptr &temp1,int data)
{
	prev->key[prev->count]=data;
	prev->count++;
	sorting(prev);int i;
	for(i=2*d+1;i>=1;i--)
	{
		if(prev->key[i-1]==data)break;
		prev->ptr[i]=prev->ptr[i-1];
	}		
	prev->ptr[i]=temp1;
	return t;	
}
btptr leaf_split(btptr &t,btptr &prev,int data)
{
	int a[2*d+1];
	mid(t,a,data);
	for(int i=0;i<t->count;i++)
	{
		t->key[i]=-1;
	}
	for(int i=0;i<d;i++)
	{
		t->key[i]=a[i];
	}
	t->count=d;
	btptr temp1=creatnode(a[d+1]);
	for(int i=d+2;i<2*d+1;i++)
	{
		temp1->key[i-d-1]=a[i];
	}
	temp1->count=d;
	if(prev==NULL)
	{
		btptr temp=creatnode(a[d]);		
		temp->ptr[0]=t;
		temp->ptr[1]=temp1;
		return temp;
	}
	else return prev_not_null(prev,t,temp1,a[d]);
}
btptr node_split(btptr &t,btptr &prev)
{
	btptr temp1=creatnode(t->key[d+1]);
	for(int i=d+2;i<2*d+1;i++)
	{
		temp1->key[i-d-1]=t->key[i];
		t->key[i]=-1;
	}
	temp1->count=d;		
	for(int i=d+1;i<=2*d+1;i++)
	{
		temp1->ptr[i-d-1]=t->ptr[i];
		t->ptr[i]=NULL;
	}
	t->count=d;
	if(prev==NULL)
	{
		btptr temp=creatnode(t->key[d]);t->key[d]=-1;
		temp->ptr[0]=t;
		temp->ptr[1]=temp1;
		return temp;
	}	
	else
	{
		int s=t->key[d];t->key[d]=-1;
		return prev_not_null(prev,t,temp1,s);
	}	
}
btptr creat(btptr &t,btptr &prev,int data)
{
	if(t==NULL)
	{
		t=creatnode(data);
	}
	else
	{
		if(is_leaf(t))
		{
			if(t->count<2*d)
			{
				t->key[t->count]=data;
				t->count++;
				sorting(t);
			}	
			else
			{
				t=leaf_split(t,prev,data);
			}
		}
		else
		{
			bool flag=false;
			for(int i=0;i<t->count;i++)
			{
				if(data<t->key[i])
				{
					flag=true;
					t->ptr[i]=creat(t->ptr[i],t,data);
					break;
				}
			}
			if(!flag)t->ptr[t->count]=creat(t->ptr[t->count],t,data);
			if(t->count>2*d)
			{
				t=node_split(t,prev);
			}
		}
	}
	return t;
}
int main()
{
	btptr t=NULL;
	while(1)
	{
		int data;cin>>data;
		if(data==-1)break;
		btptr t1=NULL;
		t=creat(t,t1,data);
		level_order(t);
	}
}