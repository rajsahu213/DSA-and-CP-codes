#include<bits/stdc++.h>
using namespace std;

void insert_heap(int h[],int data,int &n)
{
	h[n++]=data;
	int i=n-1;
	while(((i-1)/2)>=0)
	{
		if(h[(i-1)/2]>h[i]){swap(h[(i-1)/2],h[i]);i=(i-1)/2;}
		else break;
	}
}

int index(int h[],int n,int x)
{
	for(int i=0;i<n;i++)
	{
		if(h[i]==x)return i;
	}
	return -1;
}

void delete_from_heap(int h[],int &n,int x)
{
	int k=index(h,n,x);n--;
	h[k]=h[n];
	while((2*k+1)<=n)
	{
		if((2*k+1)==n)
		{
			if(h[(2*k+1)]<h[k]){swap(h[k],h[2*k+1]);k=2*k+1;}
			else break;
		}
		else if(h[2*k+1]<h[k]&&h[2*k+2]>h[k])
		{
			swap(h[k],h[2*k+1]);k=2*k+1;		
		}
		else if(h[2*k+1]>h[k]&&h[2*k+2]<h[k])
		{
			swap(h[k],h[2*k+2]);k=2*k+2;		
		}
		else if(h[2*k+1]<h[k]&&h[2*k+2]<h[k])
		{
			if(h[2*k+1]<h[2*k+2]){swap(h[k],h[2*k+1]);k=2*k+1;}		
			else{swap(h[k],h[2*k+2]);k=2*k+2;}
		}		
		else break;
	}
}

void heap_sort(int h[],int s)
{
	int j=s;
	for(int i=0;i<j;i++)
	{
		cout<<h[0]<<" ";
		delete_from_heap(h,s,h[0]);
	}
	cout<<endl;
}

int main()
{
	vector<int> v;
	while(1)
	{
		int data;cin>>data;
		if(data==-1)break;
		v.push_back(data);
	}
	cout<<"the entered array is\n";
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
	int h[v.size()],s=0;
	for(int i=0;i<v.size();i++)
	{
		insert_heap(h,v[i],s);
	}
	// cout<<"the heap of those numbers is: \n";
	// int k=1;
	// for(int i=0;i<s;i++)
	// {
	// 	if(i==(pow(2,k)-1)){cout<<endl;k++;}
	// 	cout<<h[i]<<" ";
	// }
	// cout<<endl;
	// while(1)
	// {
	// 	int x;cin>>x;
	// 	if(x==-1)break;
	// 	delete_from_heap(h,s,x);
	// 	int j=1;
	// 	for(int i=0;i<s;i++)
	// 	{
	// 		if(i==(pow(2,j)-1)){cout<<endl;j++;}
	// 		cout<<h[i]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	cout<<"the sorted array is\n";
	heap_sort(h,s);
}