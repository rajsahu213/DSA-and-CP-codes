#include<bits/stdc++.h>
using namespace std;

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

int get_index(int a[],int n,int x)
{
	for(int i=0;i<n;i++)
	{
		if(a[i]==x)return i;
	}
	return -1;
}

void delete_num(int h[],int &n,int x)
{
	int i=get_index(h,n,x);
	h[i]=h[n-1];n=n-1;
	int temp;
	while(n>=(2*i+1))
	{
		if(n==(2*i+1))
		{
			if(h[2*i+1]<h[i]){temp=h[i];h[i]=h[2*i+1];h[2*i+1]=temp;break;}
			else break;
		}
		else if(h[2*i+1]<h[i]&&h[2*i+2]>h[i])
		{
			temp=h[i];h[i]=h[2*i+1];h[2*i+1]=temp;i=2*i+1;
		}
		else if(h[2*i+1]>h[i]&&h[2*i+2]<h[i])
		{
			temp=h[i];h[i]=h[2*i+2];h[2*i+2]=temp;i=2*i+2;
		}		
		else if(h[2*i+1]<h[i]&&h[2*i+2]<h[i])
		{
			if(h[2*i+1]<h[2*i+2]){temp=h[i];h[i]=h[2*i+1];h[2*i+1]=temp;i=2*i+1;}
			else {temp=h[i];h[i]=h[2*i+2];h[2*i+2]=temp;i=2*i+2;}
		}		
		else break;
	}
}

int index(int n,int a[n][100],int i[],int n[],int x)
{
	for(int j=0;j<n;j++)
	{
		if(i[j]<n[j])
		{
			if(a[i][i[i]]==x)return j;
		}
	}
}

void creat_heap(int a[],int h[],int n)
{
	int size=0;
	for(int i=0;i<n;i++)
	{
		insert_heap(h,size,a[i]);
	}
}

int main()
{
	cout<<"enter m: ";
	int m;cin>>m;
	int a[m][100];
	int n[m];
	for(int i=0;i<m;i++)
	{
		cout<<"enter n"<<i+1<<" : ";
		cin>>n[i];
		cout<<"enter the "<<i+1<<" list\n";
		for(int j=0;j<n[i];j++)
		{
			cin>>a[i][j];
		}
	}
	int i[m];
	for(int j=0;j<m;j++)i[j]=0;
	int h[30];
	int size;
	int temp[m+10];
	int k;
	while(1)
	{
		size=0;
		k=0;
		while(k<m)
		{
			if(i[k]<n[k])temp[k]=a[k][i[k]];
			else
			{
				size++;
			}
		}
		if(m-size==0)break;
		creat_heap(temp,h,m-size);
		cout<<h[0]<<" ";
		int x=index(m,a,i,n,h[0]);
		i[x]++;
	}
	cout<<endl;
}

