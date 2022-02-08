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
	memset(temp->key,-1,sizeof(temp->key));
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
		btptr t1=q.front();
		for(int i=0;i<t1->count;i++)
		{
			if(i==0)cout<<" < ";
			cout<<t1->key[i]<<" ";
			if(i==(t1->count-1))cout<<"> ";
		}
		q.pop();
		for(int i=0;i<=t1->count;i++)
		{
			if(t1->ptr[i]!=NULL)
			{
				q.push(t1->ptr[i]);
			}
		}
	}
}

btptr split(btptr &t,btptr &prev,int data)
{
	int a[2*d+1];
	for(int i=0;i<2*d;i++)a[i]=t->key[i];
	if(t->count==2*d)a[2*d]=data;
	else a[2*d]=t->key[t->count-1];
	sort(a,a+2*d+1);
	btptr temp1=creatnode(a[d+1]);
	for(int i=d+2;i<2*d+1;i++)
	{
		temp1->key[i-d-1]=a[i];
	}
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
		temp->ptr[0]=t;
		temp->ptr[1]=temp1;
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
}

btptr check_red(btptr &t,btptr &prev,int data)
{
	if(prev==NULL)return split(t,prev,data);
	else
	{
		int k=index(t,prev);		
		for(int i=0;i<=prev->count;i++)
		{
			if(prev->ptr[i]!=NULL&&prev->ptr[i]->count<2*d)
			{

				if(i<k)
				{
					for(int j=i;j<k;j++)
					{
						int a[2*d+1];
						if(j==k-1)
						{
							for(int m=0;m<2*d;m++)a[m]=t->key[m];
							a[2*d]=data;
							sort(a,a+2*d+1);
						}
						else
						{
							for(int m=0;m<prev->ptr[j+1]->count;m++)a[m]=prev->ptr[j+1]->key[m];
						}
						prev->ptr[j]->key[prev->ptr[j]->count++]=prev->key[j];
						prev->ptr[j]->ptr[prev->ptr[j]->count]=prev->ptr[j+1]->ptr[0];
						prev->key[j]=a[0];
						for(int m=1;m<=prev->ptr[j+1]->count;m++)prev->ptr[j+1]->key[m-1]=a[m];
						for(int m=0;m<=prev->ptr[j+1]->count;m++)prev->ptr[j+1]->ptr[m]=t->ptr[m+1];
						if((j+1)!=k)prev->ptr[j+1]->count--;
						else t->count=2*d;	
					}
					return t;
				}
				else 
				{
					int a[2*d+1];
					for(int j=i;j>k;j--)
					{
						int n=0;
						if(j==(k+1))
						{
							for(int m=0;m<2*d;m++){a[m]=t->key[m];n++;}
							if(t->count==2*d)a[2*d]=data;
							else a[2*d]=t->key[2*d];
							sort(a,a+2*d+1);
						}
						else
						{
							for(int m=0;m<prev->ptr[j-1]->count;m++)
							{
								a[m]=prev->ptr[j-1]->key[m];
								n++;
							}
						}
						for(int m=2*d+1;m>=1;m--)
						{
							prev->ptr[j]->ptr[m]=prev->ptr[j]->ptr[m-1];
						}
						prev->ptr[j]->ptr[0]=prev->ptr[j-1]->ptr[prev->ptr[j-1]->count];
						prev->ptr[j]->key[prev->ptr[j]->count++]=prev->key[j-1];
						sort(prev->ptr[j]->key,prev->ptr[j]->key+prev->ptr[j]->count);
						if(j==(k+1))
						{
							prev->key[j-1]=a[2*d];
							for(int m=0;m<2*d;m++)t->key[m]=a[m];
							t->count=2*d;
						}
						else
						{
							prev->key[j-1]=a[n-1];
							for(int i=0;i<n-1;i++)prev->ptr[j-1]->key[i]=a[i];
							prev->ptr[j-1]->count=n-1;
						}
					}
					return t;
				}
			}
		}
		return split(t,prev,data);
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
			if(t->count>2*d)
			{
				t=check_red(t,prev,t->key[t->count]);
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