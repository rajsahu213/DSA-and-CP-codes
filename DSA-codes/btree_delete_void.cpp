//FOR B2 ONLY
#include<bits/stdc++.h>
using namespace std;
struct btnode
{
	int cnt;
	int key[100];
	btnode* pptr;
	btnode* ptr[100];
};
typedef struct btnode* btptr;
void sorting(btptr &t,int m)
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
btptr creatnode(int data,int m)
{
	btptr temp;
	temp=new btnode;
	temp->cnt=1;
	temp->key[0]=data;
	for(int i=1;i<m-1;i++)
	{
		temp->key[i]=-1;
		temp->ptr[i]=NULL;
	}
	temp->ptr[0]=temp->ptr[m]=NULL;
	temp->pptr=NULL;
	return temp;
}
bool is_leaf(btptr &t,int m)
{
	for(int i=0;i<m;i++)
	{
		if(t->ptr[i]!=NULL)
		{
			return false;
		}
	}
	return true;
}
int median(btptr &t,int m,int data,int a[],int &i)
{
	for(i=0;i<m-1;i++)
	{
		a[i]=t->key[i];
	}
	a[i]=data;
	i++;
	sort(a,a+i);
	int med=a[i/2];
	return med;
}
void inorder(btptr &t,int m)
{
	if(t!=NULL)
	{
		for(int i=0;i<t->cnt;i++)
		{
			inorder(t->ptr[i],m);
			cout<<t->key[i]<<" ";
		}
		inorder(t->ptr[t->cnt],m);
	}
}
void level_order(btptr &t,int m)
{
	btptr t2=creatnode(INT_MIN,m);
	btptr t3=creatnode(INT_MAX,m);
    queue<btptr> q;
    q.push(t2);
    q.push(t);
    q.push(t3);
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
        if(t1==t2){cout<<"< ";q.pop();}
        else if(t1==t3){cout<<"> ";q.pop();}
        else{
        for(int i=0;i<t1->cnt;i++)
        {
        	cout<<t1->key[i]<<" ";
        }
        q.pop();
        for(int i=0;i<=m+3;i++)
        {
        	if(t1->ptr[i]!=NULL)
        	{
        		q.push(t2);
        		q.push(t1->ptr[i]);
        		q.push(t3);
        	}
        }
    	}
    }
}

btptr overflow(btptr &t,int m,int data)
{
	if(t->pptr==NULL)
	{
		int a[m+10],i=0;
		int med=median(t,m,data,a,i);
		t->pptr=creatnode(med,m);
		btptr t1=creatnode(a[0],m);
		t1->key[1]=a[1];t1->cnt++;
		btptr t2=creatnode(a[3],m);
		t2->key[1]=a[4];t2->cnt++;
		t->pptr->ptr[0]=t1;
		t1->pptr=t->pptr;
		t->pptr->ptr[1]=t2;
		t2->pptr=t->pptr;
		return t->pptr;
	}
	else 
	{
		int a[m+10],i=0;
		int med=median(t,m,data,a,i);		
		btptr t1=creatnode(a[0],m);
		t1->key[1]=a[1];t1->cnt++;
		btptr t2=creatnode(a[3],m);
		t2->key[1]=a[4];t2->cnt++;
		t1->pptr=t->pptr;
		t2->pptr=t->pptr;		
		t->pptr->key[t->pptr->cnt]=med;
		t->pptr->cnt++;	
		sorting(t->pptr,t->pptr->cnt);
		for(int i=0;i<t->pptr->cnt;i++)
		{
			if(med==t->pptr->key[i])
			{
				for(int k=t->pptr->cnt;k>i;k--)
				{
					t->pptr->ptr[k]=t->pptr->ptr[k-1];
				}
				t->pptr->ptr[i+1]=t2;
				break;
			}
		}
		t->pptr=t1;
		return t->pptr;
	}
}

btptr overflow1(btptr &t,int m,int data)
{
	if(t->pptr==NULL)
	{
		int a[m+10],i=0;
		int med=median(t,m,t->key[4],a,i);
		t->pptr=creatnode(med,m);
		btptr t1=creatnode(a[0],m);
		t1->key[1]=a[1];t1->cnt++;
		btptr t2=creatnode(a[3],m);
		t2->key[1]=a[4];t2->cnt++;
		t->pptr->ptr[0]=t1;
		t1->pptr=t->pptr;
		t->pptr->ptr[1]=t2;
		t2->pptr=t->pptr;
		return t->pptr;
	}
	else 
	{
		int a[m+10],i=0;
		int med=median(t,m,t->key[4],a,i);		
		btptr t1=creatnode(a[0],m);
		t1->key[1]=a[1];
		t1->cnt++;
		for(int i=0;i<3;i++)t1->ptr[i]=t->ptr[i];
		btptr t2=creatnode(a[3],m);
		t2->key[1]=a[4];
		t2->cnt++;
		for(int i=0;i<3;i++)t2->ptr[i]=t->ptr[i+3];		
		t->pptr->key[t->pptr->cnt]=med;
		t->pptr->cnt++;	
		sorting(t->pptr,t->pptr->cnt);	
		for(int i=0;i<t->pptr->cnt;i++)
		{
			if(med==t->pptr->key[i])
			{
				for(int k=t->pptr->cnt;k>i;k--)
				{
					t->pptr->ptr[k]=t->pptr->ptr[k-1];
				}
				t->pptr->ptr[i+1]=t2;
				break;
			}
		}
		t->pptr=t1;		
		return t->pptr;			
	}
}
btptr creat(btptr t,btptr &tpr,btptr &tn,int m,int data,int flag)
{
	if(t==NULL)
	{
		t=creatnode(data,m);
	}
	else
	{
		if(is_leaf(t,m))
		{
			if(t->cnt==m-1)
			{
				t->pptr=tpr;
				t=overflow(t,m,data);
			}
			else
			{
				t->key[t->cnt]=data;
				t->cnt++;
				sorting(t,t->cnt);
				return t;
			}
		}
		else
		{
			for(int i=0;i<m;i++)
			{
				if(data<t->key[i])
				{
					flag=1;
					t->ptr[i]=creat(t->ptr[i],t,tn,m,data,0);
					t->ptr[i]->pptr=t;
					break;
				}
			}
			if(flag==0)
			{
				t->ptr[t->cnt]=creat(t->ptr[t->cnt],t,tn,m,data,flag);
				t->ptr[t->cnt]->pptr=t;
			}
			if(t->cnt>m-1)
			{
				if(t==tn){
				int a[m+10],i=0;
				int med=median(t,m,t->key[4],a,i);
				btptr t1=creatnode(a[0],m);
				t1->key[1]=a[1];
				t1->cnt++;
				for(int i=0;i<3;i++)t1->ptr[i]=t->ptr[i];
				btptr t2=creatnode(a[3],m);
				t2->key[1]=a[4];
				t2->cnt++;
				for(int i=0;i<3;i++)t2->ptr[i]=t->ptr[i+3];				
				t=creatnode(med,m);
				t->ptr[0]=t1;
				t->ptr[1]=t2;}		
				else{
					t->pptr=tpr;
					t=overflow1(t,m,data);
				}
			}
		}
	}
	return t;
}

int index(btptr &p,btptr &x)
{
	for(int i=0;i<=p->cnt;i++)
	{
		if(p->ptr[i]==x)return i;
	}
	return -1;
}

bool compare(btptr t,int x)
{
	for(int i=0;i<t->cnt;i++)
	{
		if(t->key[i]==x)
		{
			return true;
		}
	}
	return false;
}
int index1(btptr t,int x)
{
	for(int i=0;i<t->cnt;i++)
	{
		if(t->key[i]==x)
		{
			return i;
		}
	}
	return -1;
}

int max(btptr &t)
{
	if(t->ptr[t->cnt]==NULL)
	{
		return t->key[t->cnt-1];
	}
	else return max(t->ptr[t->cnt]);
}

int min(btptr &t)
{
	if(t->ptr[0]==NULL)
	{
		return t->key[0];
	}
	else return min(t->ptr[0]);
}
void underflow(btptr &t,int m,int x);

void nodecomb(btptr &t,int k,int x,int flag)
{
	if(flag==0)
	{
		int in=index1(t,x);
		t->ptr[in]=NULL;
		btptr a[6];
		a[0]=t->ptr[0];a[1]=t->ptr[1];a[2]=t->ptr[2];
		a[3]=t->pptr->ptr[k+1]->ptr[0];
		a[4]=t->pptr->ptr[k+1]->ptr[1];
		a[5]=t->pptr->ptr[k+1]->ptr[2];
		t->key[in]=t->pptr->key[k];
		t->key[t->cnt]=t->pptr->ptr[k+1]->key[0];
		t->cnt++;
		t->key[t->cnt]=t->pptr->ptr[k+1]->key[1];
		t->cnt++;
		sorting(t,t->cnt);
		int c=0;
		for(int i=0;i<6;i++)
		{
			if(a[i]!=NULL)
			{
				t->ptr[c]=a[i];
				c=c+1;
			}
		}
		if(t->pptr->cnt==2)
		{
			underflow(t->pptr,5,t->pptr->key[k]);
		}
		else if(t->pptr->cnt==1)
		{
			t->pptr->ptr[1]=NULL;
			t->pptr->cnt--;
		}
		else 
		{
		t->pptr->key[k]=INT_MAX;
		for(int i=k+1;i<=t->cnt;i++)
		{
			t->pptr->ptr[i]=t->pptr->ptr[i+1];
		}
		sorting(t->pptr,t->pptr->cnt);
		t->pptr->cnt--;}
		return ;
	}
	else
	{
		int in=index1(t,x);
		t->key[in]=INT_MAX;
		sorting(t,t->cnt);
		t->pptr->ptr[k-1]->key[t->pptr->ptr[k-1]->cnt]=t->key[0];
		t->pptr->ptr[k-1]->cnt++;
		t->pptr->ptr[k-1]->key[t->pptr->ptr[k-1]->cnt]=t->pptr->key[k-1];
		t->pptr->ptr[k-1]->cnt++;
		sorting(t->pptr->ptr[k-1],t->pptr->ptr[k-1]->cnt);
		if(t->pptr->cnt==2)
		{
			underflow(t->pptr,5,t->pptr->key[k-1]);
		}
		else
		{
		t->pptr->key[k-1]=-1;
		t->pptr->cnt--;}
		t=NULL;
	}
}

void underflow(btptr &t,int m,int x)
{
	if(t->pptr==NULL)
	{

	}
	else
	{
	int k=index(t->pptr,t);
	if(k!=0)
	{
		if(t->pptr->ptr[k-1]!=NULL&&t->pptr->ptr[k-1]->cnt>2)
		{
			int in=index1(t,x);
			t->key[in]=t->pptr->key[k-1];
			sorting(t,t->cnt);
			t->pptr->key[k-1]=t->pptr->ptr[k-1]->key[t->pptr->ptr[k-1]->cnt-1];
			t->pptr->ptr[k-1]->cnt--;
			return;
		}
		else
		{
			if(t->pptr->ptr[k+1]!=NULL&&t->pptr->ptr[k+1]->cnt>2)
			{
				if(t->pptr->ptr[k+1]->cnt>2)
				{
					int in=index1(t,x);
					t->key[in]=t->pptr->key[k];
					sorting(t,t->cnt);
					t->pptr->key[k]=t->pptr->ptr[k+1]->key[0];
					t->pptr->ptr[k+1]->key[0]=INT_MAX;
					sorting(t->pptr->ptr[k+1],t->pptr->ptr[k+1]->cnt);
					t->pptr->ptr[k+1]->cnt--;
					return;
				}
			}
			else
			{
				int flag=0;
				if(t->pptr->ptr[k+1]==NULL)flag=1;
				nodecomb(t,k,x,flag);
				return;
			}
		}
	}
	else if(k==0)
	{
		if(t->pptr->ptr[1]!=NULL&&t->pptr->ptr[1]->cnt>2)
		{
			int in=index1(t,x);
			t->key[in]=t->pptr->key[0];
			sorting(t,t->cnt);
			t->pptr->key[0]=t->pptr->ptr[1]->key[0];
			t->pptr->ptr[1]->key[0]=INT_MAX;
			sorting(t->pptr->ptr[1],t->pptr->ptr[1]->cnt);
			t->pptr->ptr[1]->cnt--;
			return;
		}
		else
		{
			if(t->pptr->ptr[1]!=NULL)
			{
				int flag=0;
				nodecomb(t,0,x,flag);
				return;
			}
		}
	}
	}
}

void delete_btree(btptr &t,btptr &root,btptr &pptr,int m,int x,int flag)
{
	t->pptr=pptr;
	if(compare(t,x))
	{
		if(is_leaf(t,m))
		{
			if(t->cnt==2&&pptr!=NULL)
			{
				t->pptr=pptr;
				underflow(t,m,x);
			}
			else
			{
				int in=index1(t,x);
				t->key[in]=INT_MAX;
				sorting(t,t->cnt);
				t->cnt--;
				return ;
			}
		}
		else
		{
			int in=index1(t,x);
			if(1)
			{
				t->key[in]=max(t->ptr[in]);
				delete_btree(t->ptr[in],root,t,m,t->key[in],0);
				return ;
			}
		}
	}
	else
	{
		for(int i=0;i<t->cnt;i++)
		{
			if(x<t->key[i])
			{
				flag=1;
				delete_btree(t->ptr[i],root,t,m,x,0);
				break;
			}
		}
		if(flag==0)
		{
			delete_btree(t->ptr[t->cnt],root,t,m,x,flag);
		}
	}
}

int main()
{
	int d=2;
	int m=2*d+1;
	cout<<"enter n: ";
	int n;cin>>n;
	cout<<"enter the numbers\n";
	int a[n];
	int k=65;
	for(int i=0;i<n;i++)cin>>a[i];
	btptr t=NULL;
	for(int i=0;i<n;i++)
	{
		btptr t1=NULL;
		int flag=0;
		t=creat(t,t1,t,m,a[i],flag);
	}
	level_order(t,m);
	cout<<"enter z: ";int z;cin>>z;
	while(z--){
	cout<<"enter the number to delete: ";
	int x,flag1=0;cin>>x;
	btptr t2=NULL;
	delete_btree(t,t,t2,m,x,flag1);
	level_order(t,m);
	inorder(t,m);
	cout<<endl;
}
}
