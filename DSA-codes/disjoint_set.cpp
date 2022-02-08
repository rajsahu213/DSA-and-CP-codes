#include<bits/stdc++.h>
using namespace std;

oint find(int a[],int n)
{
	if(a[n]<=0)return n;
	else return find(a,a[n]);
}

void unio(int a[],int i,int j)
{
	if(find(a,i)==find(a,j))return;
	if(a[j]==0&&a[i]>=0){a[j]=i;a[find(a,a[j])]--;}
	else if(a[j]==0&&a[i]<0)a[j]=i;
	else if(a[i]<0||a[j]<0)
	{
		if(a[j]<0&&a[i]==0){a[i]=a[j]-1;a[j]=i;}
		else
		{
			int x1=find(a,a[i]);
			if(a[j]==a[x1]){a[x1]=a[x1]-1;a[j]=i;}
			else if(a[j]>a[x1])a[j]=x1;
			else a[x1]=j;
		}
	}
	else
	{
		int x=find(a,a[j]);
		unio(a,i,x);
	}
}

int main()
{
	int a[100]={0};
	while(1)
	{
		int i,j;
		cout<<"enter the ordered pairs: ";cin>>i>>j;
		if(i==-1||j==-1)break;
		unio(a,i,j);
	}
	while(1)
	{
		cout<<"enter the number to find its root: ";
		int k;cin>>k;
		if(k==-1)break;
		cout<<find(a,k)<<endl;
	}
}