#include<bits/stdc++.h>
#define d 2
using namespace std;
struct btnode
{
	int count;
	int key[2*d+1];
	btnode* ptr[2*d+2]={NULL};
};
typedef struct btnode* btptr;
btptr creatnode(int data)
{
	btptr temp=new btnode;
	memset(temp->key, -1 , sizeof(temp->key));
	temp->key[0]=data;
	temp->count=1;
	return temp;
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
		btptr t3=q.front();
		for(int i=0;i<t3->count;i++)
		{
			if(i==0)cout<<"< ";
			cout<<t3->key[i]<<" ";
			if(i==t3->count-1)cout<<">";
			if(t3->ptr[i]!=NULL)q.push(t3->ptr[i]);
		}
		if(t3->ptr[t3->count]!=NULL)q.push(t3->ptr[t3->count]);
		q.pop();
	}
}
btptr split(btptr &t,btptr &prev,int data)
{
	int a[2*d+1];
	for(int i=0;i<t->count;i++)a[i]=t->key[i];
	if(t->count==2*d)a[t->count]=data;
	sort(a,a+2*d+1);
	btptr temp1=creatnode(a[d+1]);
	for(int i=d+2;i<2*d+1;i++)temp1->key[i-d-1]=a[i];
	for(int i=d+1;i<2*d+2;i++)
	{
		temp1->ptr[i-d-1]=t->ptr[i];
		t->ptr[i]=NULL;
	}
	memset(t->key,-1,sizeof(t->key));
	for(int i=0;i<d;i++)t->key[i]=a[i];	
	t->count=temp1->count=d;
	if(prev==NULL)
	{
		btptr temp=creatnode(a[d]);
		temp->ptr[0]=t;temp->ptr[1]=temp1;
		return temp;
	}
	else
	{
		prev->key[prev->count++]=a[d];
		sort(prev->key,prev->key+prev->count);int i;
		for(i=2*d+1;i>=1;i--)
		{
			if(prev->key[i-1]==a[d])break;
			prev->ptr[i]=prev->ptr[i-1];
		}
		prev->ptr[i]=temp1;
		return t;
	}
}
int index(btptr &t,btptr &prev)
{
	for(int i=0;i<=prev->count;i++)
	{
		if(prev->ptr[i]==t)return i;
	}
	return -1;
}
btptr check_red(btptr &t,btptr &prev,int data)
{
	if(prev==NULL)return split(t,prev,data);
	else
	{
		int k=index(t,prev);
		int a[2*d+1];
		for(int i=0;i<2*d;i++)a[i]=t->key[i];
		if(t->count==2*d)a[2*d]=data;
		else a[2*d]=t->key[2*d];
		sort(a,a+2*d+1);
		if(prev->ptr[k+1]!=NULL&&prev->ptr[k+1]->count<2*d)
		{
			for(int i=2*d+1;i>=1;i--)
			{
				prev->ptr[k+1]->ptr[i]=prev->ptr[k+1]->ptr[i-1];
			}
			prev->ptr[k+1]->ptr[0]=t->ptr[t->count];
			prev->ptr[k+1]->key[prev->ptr[k+1]->count++]=prev->key[k];
			sort(prev->ptr[k+1]->key,prev->ptr[k+1]->key+prev->ptr[k+1]->count);
			prev->key[k]=a[2*d];
			for(int i=0;i<2*d;i++)t->key[i]=a[i];
			t->count=2*d;
			return t;
		}
		else if(k!=0&&(prev->ptr[k-1]!=NULL)&&(prev->ptr[k-1]->count<2*d))
		{
			prev->ptr[k-1]->key[prev->ptr[k-1]->count++]=prev->key[k-1];
			prev->ptr[k-1]->ptr[prev->ptr[k-1]->count]=t->ptr[0];
			prev->key[k-1]=a[0];
			for(int i=1;i<=2*d;i++)t->key[i-1]=a[i];
			for(int i=0;i<=t->count;i++)t->ptr[i]=t->ptr[i+1];
			t->key[2*d]=-1;t->ptr[2*d+1]=NULL;
			t->count=2*d;
			return t;
		}
		else return split(t,prev,data);
	}
}
btptr creat(btptr &t,btptr &prev,int data)
{
	if(t==NULL)t=creatnode(data);
	else
	{
		if(t->ptr[0]==NULL)
		{
			if(t->count<2*d)
			{
				t->key[t->count++]=data;
				sort(t->key,t->key+t->count);
			}
			else
			{
				t=check_red(t,prev,data);
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
			if(t->count>2*d)t=check_red(t,prev,t->key[t->count]);
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