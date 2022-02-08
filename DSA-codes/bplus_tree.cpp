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
	return temp;
}
bool is_leaf(btptr t,int m)
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
int median(btptr t,int m,int data,int a[],int &i)
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
        for(int i=0;i<=t1->cnt;i++)
        {
        	if(is_leaf(t1,m)&&i==m)break;
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
		for(int i=0;i<t->cnt;i++)t->key[i]=-1;
		t->key[0]=a[0];t->key[1]=a[1];t->cnt=2;
		btptr t2=creatnode(med,m);
		t2->key[1]=a[3];t2->cnt++;
		t2->key[2]=a[4];t2->cnt++;
		t->pptr->ptr[0]=t;
		t->pptr->ptr[1]=t2;
		t2->ptr[m]=t->ptr[m];
		t->ptr[m]=t2;
		return t->pptr;
	}
	else 
	{
		int a[m+10],i=0;
		int med=median(t,m,data,a,i);		
		for(int i=0;i<t->cnt;i++)t->key[i]=-1;
		t->key[0]=a[0];t->key[1]=a[1];t->cnt=2;		
		btptr t2=creatnode(med,m);
		t2->key[1]=a[3];t2->cnt++;
		t2->key[2]=a[4];t2->cnt++;	
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
		t2->ptr[m]=t->ptr[m];
		t->ptr[m]=t2;	
		return t;
	}
}
btptr overflow1(btptr &t,int m,int data)
{
	int a[m+10],i=0;
	int med=median(t,m,t->key[4],a,i);
	btptr t2=creatnode(a[3],m);
	t2->key[1]=a[4];t2->cnt++;
	for(int i=0;i<3;i++)t2->ptr[i]=t->ptr[i+3];	
	t->key[2]=t->key[3]=t->key[4]=-1;t->cnt=2;
	t->ptr[3]=t->ptr[4]=t->ptr[5]=NULL;	
	t->pptr->key[t->pptr->cnt]=med;t->pptr->cnt++;	
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
	return t;			
}
btptr creat(btptr &t,btptr &pptr,btptr &root,int m,int data,int flag)
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
				t->pptr=pptr;
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
					t->ptr[i]=creat(t->ptr[i],t,root,m,data,0);
					break;
				}
			}
			if(flag==0){t->ptr[t->cnt]=creat(t->ptr[t->cnt],t,root,m,data,flag);}

			if(t->cnt>m-1)
			{
				if(t==root)
				{
					int a[m+10],i=0;
					int med=median(t,m,t->key[4],a,i);
					queue<btptr> q;
					for(int i=0;i<6;i++)q.push(t->ptr[i]);
					btptr t1=creatnode(a[0],m);
					t1->key[1]=a[1];t1->cnt++;
					for(int i=0;i<3;i++){t1->ptr[i]=q.front();q.pop();}
					btptr t2=creatnode(a[3],m);
					t2->key[1]=a[4];t2->cnt++;
					for(int i=0;i<3;i++){t2->ptr[i]=q.front();q.pop();}	
					btptr temp=NULL;	
					temp=creatnode(med,m);
					temp->ptr[0]=t1;
					temp->ptr[1]=t2;
					return temp;
				}		
				else{
					t->pptr=pptr;
					t=overflow1(t,m,data);
				}
			}
		}
	}
	return t;
}
void print(btptr &t)
{
	if(t->ptr[0]==NULL)
	{
		while(t!=NULL)
		{
			for(int i=0;i<t->cnt;i++)
			{
				cout<<t->key[i]<<" ";
			}
			t=t->ptr[5];
		}
		return;
	}
	else print(t->ptr[0]);
}
int main()
{
	int m=5;
	cout<<"enter n: ";
	int n;cin>>n;
	cout<<"enter the numbers\n";
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	btptr t=NULL;
	for(int i=0;i<n;i++)
	{
		btptr pptr=NULL;
		int flag=0;
		t=creat(t,pptr,t,m,a[i],flag);
	}
	inorder(t,m);
	cout<<endl;
	level_order(t,m);
	print(t);
	cout<<endl;
}
