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
int index(btptr &p,btptr &x)
{
	for(int i=0;i<=p->cnt;i++)
	{
		if(p->ptr[i]==x)return i;
	}
	return -1;
}
void level_order(btptr &t,int m)
{
	btptr t2=creatnode(INT_MIN,m);
	btptr t3=creatnode(INT_MAX,m);
    queue<btptr> q;
    q.push(t2);q.push(t);q.push(t3);q.push(NULL);
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
        		if(t1->ptr[i]!=NULL){q.push(t2);q.push(t1->ptr[i]);q.push(t3);}
        	}
    	}
    }
}
btptr funtion1(btptr &t,int m,int data)
{
	int a[m+10],i=0;
	int med=median(t,m,data,a,i);		
	for(int i=0;i<t->cnt;i++)t->key[i]=-1;
	t->key[0]=a[0];t->key[1]=a[1];t->cnt=2;		
	btptr t2=creatnode(a[3],m);
	t2->key[1]=a[4];t2->cnt++;	
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
	return t;	
}
btptr funtion2(btptr &t,int m,int data)
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
btptr overflow(btptr &t,int m,int data)
{
	if(t->pptr==NULL)
	{
		int a[m+10],i=0;
		int med=median(t,m,data,a,i);
		t->pptr=creatnode(med,m);
		for(int i=0;i<t->cnt;i++)t->key[i]=-1;
		t->key[0]=a[0];t->key[1]=a[1];t->cnt=2;
		btptr t2=creatnode(a[3],m);
		t2->key[1]=a[4];t2->cnt++;
		t->pptr->ptr[0]=t;
		t->pptr->ptr[1]=t2;
		return t->pptr;
	}
	else 
	{
		int k=index(t->pptr,t);
		if(k!=0)
		{
			if(t->pptr->ptr[k-1]->cnt<4)
			{
				int temp3;
				if(data<t->key[0])temp3=data;
				else temp3=t->key[0];
				int temp2=t->pptr->key[k-1];
				t->pptr->key[k-1]=temp3;
				t->pptr->ptr[k-1]->key[t->pptr->ptr[k-1]->cnt]=temp2;
				t->pptr->ptr[k-1]->cnt++;
				if(t->key[0]==temp3){
				t->cnt--;	
				t->key[0]=data;
				t->cnt++;
				sorting(t,t->cnt);}	
				return t;
			}
			else
			{
				if(t->pptr->ptr[k+1]->cnt<4)
				{
					int temp1;
					if(t->key[3]>data)temp1=t->key[3];
					else temp1=data;		
					t->pptr->ptr[k+1]->key[t->pptr->ptr[k+1]->cnt]=t->pptr->key[k];
					t->pptr->ptr[k+1]->cnt++;
					sorting(t->pptr->ptr[k+1],t->pptr->ptr[k+1]->cnt);
					t->pptr->key[k]=temp1;
					if(t->key[3]==temp1){
					t->cnt--;	
					t->key[t->cnt]=data;
					t->cnt++;
					sorting(t,t->cnt);}	
					return t;
				}
				else return funtion1(t,m,data);
			}
		}
		else if(k==0)
		{
			if(t->pptr->ptr[1]->cnt<4)
			{
				int temp;
				if(t->key[3]>data)temp=t->key[3];
				else temp=data;
				t->pptr->ptr[1]->key[t->pptr->ptr[1]->cnt]=t->pptr->key[0];
				t->pptr->ptr[1]->cnt++;
				sorting(t->pptr->ptr[1],t->pptr->ptr[1]->cnt);
				t->pptr->key[0]=temp;
				if(t->key[3]==temp)
				{t->key[t->cnt-1]=data;
				sorting(t,t->cnt);}	
				return t;
			}
			else return funtion1(t,m,data);
		}
	}
}

btptr overflow1(btptr &t,int m,int data)
{
	int k=index(t->pptr,t);
	if(k!=0)
	{
		if(t->pptr->ptr[k-1]->cnt<4)
		{
			t->pptr->ptr[k-1]->key[t->pptr->ptr[k-1]->cnt]=t->pptr->key[k-1];
			t->pptr->ptr[k-1]->cnt++;
			t->pptr->key[k-1]=t->key[0];
			t->pptr->ptr[k-1]->ptr[t->pptr->ptr[k-1]->cnt]=t->ptr[0];
			for(int i=0;i<m;i++)
			{
				t->key[i]=t->key[i+1];
				t->ptr[i]=t->ptr[i+1];
			}
			t->ptr[t->cnt]=NULL;
			t->cnt--;
			return t;
		}
		else
		{
			if(t->pptr->ptr[k+1]->cnt<4)
			{
				int temp1;
				for(int i=0;i<m;i++)
				{
					t->pptr->ptr[k+1]->key[i]=t->pptr->ptr[k+1]->key[i+1];
					t->pptr->ptr[k+1]->ptr[i]=t->pptr->ptr[k+1]->ptr[i+1];			
				}
				t->pptr->ptr[k+1]->key[0]=t->pptr->key[k];
				t->pptr->key[k]=t->key[4];
				t->pptr->ptr[k+1]->ptr[0]=t->ptr[5];
				t->pptr->ptr[k+1]->cnt++;t->cnt--;
				t->key[4]=-1;t->ptr[5]=NULL;
				return t;
			}
			else
			{
				return funtion2(t,m,data);
			}
		}
	}
	else if(k==0)
	{
		if(t->pptr->ptr[1]->cnt<4)
		{
			for(int i=t->pptr->ptr[1]->cnt;i>=0;i--)
			{
				t->pptr->ptr[1]->key[i]=t->pptr->ptr[1]->key[i-1];
				t->pptr->ptr[1]->ptr[i+1]=t->pptr->ptr[1]->ptr[i];
			}
			t->pptr->ptr[1]->ptr[0]=t->ptr[5];
			t->pptr->ptr[1]->key[0]=t->pptr->key[0];
			t->pptr->key[0]=t->key[4];
			t->pptr->ptr[1]->cnt++;
			t->key[t->cnt-1]=-1;
			t->ptr[t->cnt]=NULL;
			t->cnt--;
			return t;
		}
		else return funtion2(t,m,data);	
	}
	
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
int main()
{
	int d=2;
	int m=2*d+1;
	cout<<"enter n: ";
	int n;cin>>n;
	cout<<"enter the numbers\n";
	int a[n];
	for(int i=0;i<n;i++)a[i]=n-i;
	btptr t=NULL;
	for(int i=0;i<n;i++)
	{
		btptr t1=NULL;
		int flag=0;
		t=creat(t,t1,t,m,a[i],flag);
	}
	inorder(t,m);
	cout<<endl;
	level_order(t,m);
}
