#include<bits/stdc++.h>
#define d 2
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
	btptr temp=new btnode;
	for(int i=0;i<=2*d;i++)
	{
		temp->key[i]=-1;
	}
	for(int i=0;i<=2*d+1;i++)
	{
		temp->ptr[i]=NULL;
	}
	temp->key[0]=data;
	temp->count=1;
	return temp;
}

void level_order(btptr &t)
{
	queue<btptr> q;
	btptr t1=creatnode(INT_MIN);
	btptr t2=creatnode(INT_MAX);
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
		if(t3==t1)
		{
			cout<<"< ";
			q.pop();
		}
		else if(t3==t2)
		{
			cout<<">  ";
			q.pop();
		}
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
	for(int i=0;i<=2*d+1;i++)
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
	for(int i=0;i<t->count;i++)
	{
		a[i]=t->key[i];
	}
	a[t->count]=data;
	sort(a,a+t->count+1);
}

btptr split1(btptr &t,btptr &prev,int data)
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
	prev->key[prev->count]=a[d];
	prev->count++;
	sorting(prev);
	int i;
	for(i=2*d+1;i>=0;i--)
	{
		if(prev->key[i-1]==a[d])break;
		prev->ptr[i]=prev->ptr[i-1];
	}				
	prev->ptr[i]=temp1;
	return t;	
}

btptr split2(btptr &t,btptr &prev)
{
	btptr temp1=creatnode(t->key[d+1]);
	for(int i=d+2;i<2*d+1;i++)
	{
		temp1->key[i-d-1]=t->key[i];
		t->key[i]=-1;
	}
	temp1->count=d;	
	for(int i=d+1;i<2*d+2;i++)
	{
		temp1->ptr[i-d-1]=t->ptr[i];
		t->ptr[i]=NULL;
	}	
	prev->key[prev->count]=t->key[d];
	prev->count++;
	sorting(prev);	
	int i;
	for(i=2*d+1;i>=0;i--)
	{
		if(prev->key[i-1]==t->key[d])break;
		prev->ptr[i]=prev->ptr[i-1];
	}				
	prev->ptr[i]=temp1;	
	t->key[d]=-1;t->count=d;
	return t;	
}

int index(btptr &prev,btptr &t)
{
	for(int i=0;i<2*d+2;i++)
	{
		if(prev->ptr[i]==t)return i;
	}
	return -1;
}

bool isempty(btptr &t)
{
	for(int i=0;i<2*d;i++)
	{
		if(t->key[i]==-1)return true;
	}
	return false;
}

btptr leaf_split(btptr &t,btptr &prev,int data)
{
	if(prev==NULL)
	{
		int a[2*d+1];
		mid(t,a,data);
		btptr temp=creatnode(a[d]);
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
		temp->ptr[0]=t;
		temp->ptr[1]=temp1;
		return temp;
	}
	else 
	{
		int k=index(prev,t);
		if(k==0)
		{
			if(prev->ptr[k+1]!=NULL&&isempty(prev->ptr[k+1]))
			{
				int temp=prev->key[k];
				prev->ptr[k+1]->key[prev->ptr[k+1]->count]=temp;
				prev->ptr[k+1]->count++;
				sorting(prev->ptr[k+1]);
				int a[2*d+1];
				mid(t,a,data);		
				prev->key[k]=a[2*d];
				for(int i=0;i<2*d;i++)t->key[i]=a[i];
				return t;	
			}
			else
			{
				return split1(t,prev,data);
			}
		}
		else
		{
			if(isempty(prev->ptr[k-1]))
			{
				int temp=prev->key[k-1];
				prev->ptr[k-1]->key[prev->ptr[k-1]->count]=temp;
				prev->ptr[k-1]->count++;
				sorting(prev->ptr[k-1]);	
				int a[2*d+1];
				mid(t,a,data);
				prev->key[k-1]=a[0];
				for(int i=1;i<=2*d;i++)t->key[i-1]=a[i];
				return t;																
			}
			else if(prev->ptr[k+1]!=NULL&&isempty(prev->ptr[k+1]))
			{
				int temp=prev->key[k];
				prev->ptr[k+1]->key[prev->ptr[k+1]->count]=temp;
				prev->ptr[k+1]->count++;
				sorting(prev->ptr[k+1]);
				int a[2*d+1];
				mid(t,a,data);		
				prev->key[k]=a[2*d];
				for(int i=0;i<2*d;i++)t->key[i]=a[i];
				return t;
			}
			else
			{
				return split1(t,prev,data);
			}
		}
	}
}

btptr node_split(btptr &t,btptr &prev)
{
	if(prev==NULL)
	{
		btptr temp1=creatnode(t->key[d+1]);
		for(int i=d+2;i<2*d+1;i++)
		{
			temp1->key[i-d-1]=t->key[i];
			t->key[i]=-1;
		}
		temp1->count=d;	
		for(int i=d+1;i<2*d+2;i++)
		{
			temp1->ptr[i-d-1]=t->ptr[i];
			t->ptr[i]=NULL;
		}	
		btptr temp=creatnode(t->key[d]);
		t->key[d]=-1;t->count=d;
		temp->ptr[0]=t;
		temp->ptr[1]=temp1;
		return temp;		
	}
	else
	{
		int k=index(prev,t);
		if(k==0)
		{
			if(prev->ptr[k+1]!=NULL&&isempty(prev->ptr[k+1]))
			{
				for(int i=2*d+1;i>=1;i--)
				{
					prev->ptr[k+1]->ptr[i]=prev->ptr[k+1]->ptr[i-1];
				}
				int temp=prev->key[k];
				prev->ptr[k+1]->key[prev->ptr[k+1]->count]=temp;
				prev->ptr[k+1]->count++;
				sorting(prev->ptr[k+1]);
				prev->key[k]=t->key[2*d];
				t->key[2*d]=-1;t->count=2*d;
				prev->ptr[k+1]->ptr[0]=t->ptr[2*d+1];
				t->ptr[2*d+1]=NULL;
				return t;
			}
			else
			{
				return split2(t,prev);
			}
		}
		else
		{
			if(isempty(prev->ptr[k-1]))
			{
				prev->ptr[k-1]->key[prev->ptr[k-1]->count]=prev->key[k-1];
				prev->ptr[k-1]->count++;
				prev->ptr[k-1]->ptr[prev->ptr[k-1]->count]=t->ptr[0];
				prev->key[k-1]=t->key[0];
				for(int i=0;i<2*d+1;i++)
				{
					t->ptr[i]=t->ptr[i+1];
				}
				t->ptr[2*d+1]=NULL;
				for(int i=0;i<2*d;i++)
				{
					t->key[i]=t->key[i+1];
				}
				t->key[2*d]=-1;t->count=2*d;
				return t;
			}
			else if(prev->ptr[k+1]!=NULL&&isempty(prev->ptr[k+1]))
			{
				for(int i=2*d+1;i>=1;i--)
				{
					prev->ptr[k+1]->ptr[i]=prev->ptr[k+1]->ptr[i-1];
				}
				int temp=prev->key[k];
				prev->ptr[k+1]->key[prev->ptr[k+1]->count]=temp;
				prev->ptr[k+1]->count++;
				sorting(prev->ptr[k+1]);
				prev->key[k]=t->key[2*d];
				t->key[2*d]=-1;t->count=2*d;
				prev->ptr[k+1]->ptr[0]=t->ptr[2*d+1];
				t->ptr[2*d+1]=NULL;
				return t;
			}
			else
			{
				return split2(t,prev);
			}
		}		
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
		// level_order(t);
	}
	level_order(t);
}