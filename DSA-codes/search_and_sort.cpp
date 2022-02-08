#include<bits/stdc++.h>
using namespace std;

void selection_sort(int a[],int n)
{
	int min,flag;
	for(int i=0;i<n-1;i++)
	{
		min=i;flag=0;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<a[min]){min=j;flag=1;}
		}
		if(flag)swap(a[min],a[i]);
	}
}

int partition(int a[],int low,int high)
{
	int p=a[low];
	int l=low+1;
	int h=high;
	while(l<=h)
	{
		while(a[l]<p&&l<=high)
		{
			l++;
		}
		while(a[h]>p&&h>=0)
		{
			h--;
		}
		if(l<h)swap(a[l],a[h]);
	}
	swap(a[low],a[h]);
	return h;
}

void bubble_sort(int a[],int n)
{
	int flag,last;
	for(int i=0;i<n;i++)
	{
		last=n-i-1;flag=0;
		for(int j=0;j<last;j++)
		{
			if(a[j+1]<a[j]){swap(a[j+1],a[j]);flag=1;}
		}
		if(!flag)break;
	}
}

void insertion_sort(int a[],int n)
{
	int hole,value;
	for(int i=1;i<n;i++)
	{
		hole=i;
		value=a[i];
		while(hole>0&&value<a[hole-1])
		{
			a[hole]=a[hole-1];
			hole--;
		}
		a[hole]=value;
	}
}

void merge(int a[],int low,int high)
{
	int mid=low+(high-low)/2;
	int i=low;
	int j=mid+1;
	int k=low;
	int temp[high+1];
	while(i<=mid&&j<=high)
	{
		if(a[i]<a[j])temp[k++]=a[i++];
		else temp[k++]=a[j++];
	}
	while(i<=mid)temp[k++]=a[i++];
	while(j<=high)temp[k++]=a[j++];
	for(int i=low;i<=high;i++)
	{
		a[i]=temp[i];
	}
}

void merge_sort(int a[],int low,int high)
{
	if(low<high)
	{
		int mid=low+(high-low)/2;
		merge_sort(a,low,mid);
		merge_sort(a,mid+1,high);
		merge(a,low,high);
	}
}

// int partition(int a[],int low,int high)
// {
// 	int p=a[low];
// 	int l=low+1;
// 	int h=high;
// 	while(l<=h)
// 	{
// 		while(a[l]<p&&l<=high)
// 		{
// 			l++;
// 		}
// 		while(a[h]>p&&h>=0)
// 		{
// 			h--;
// 		}
// 		if(l<h)swap(a[l],a[h]);
// 	}
// 	swap(a[low],a[h]);
// 	return h;
// }

void quick_sort(int a[],int low,int high)
{
	if(low<high)
	{
		int t=partition(a,low,high);
		quick_sort(a,low,t-1);
		quick_sort(a,t+1,high);
	}
}

void bubble_sort_rec(int a[],int i,int j,int n)
{
	if(i==n)return;
	else if(j==(n-i-1))
	{
		j=0;
		i++;
	}	
	if(a[j+1]<a[j])swap(a[j+1],a[j]);
	bubble_sort_rec(a,i,j,n);
}

void shellSort(int a[],int n)
{
	int k=n/2,value,hole;
	while(k>0)
	{
		for(int i=k;i<n;i++)
		{
			value=a[i];
			hole=i;
			while(hole>=k&&value<a[hole-k])
			{
				a[hole]=a[hole-k];
				hole=hole-k;
			}
			a[hole]=value;
		}
		k=k/2;
	}
}

void radix_sort(int a[],int n)
{
	vector<int> v[10];
	int t=10,k=0;
	while(t--)
	{
		k++;int flag=0;
		for(int i=0;i<n;i++)
		{
			int d=a[i],x,p=k;
			while(p--)
			{
				x=d%10;
				d=d/10;
			}
			if(d!=0)flag=1;
			v[x].push_back(a[i]);
		}
		int y=0;
		for(int i=0;i<10;i++)
		{
			for(int j=0;j<v[i].size();j++)
			{
				a[y++]=v[i][j];
			}
			v[i].erase(v[i].begin(),v[i].end());
		}
		if(!flag)break;
	}
}

int main()
{
	// cout<<"enter n: ";
	// int n;cin>>n;int a[n];
	int n=10;
	int a[n]={23,90,34,27,19,1,9,77,62,99};
	// cout<<"enter the numbers\n";
	// for(int i=0;i<n;i++)cin>>a[i];
	cout<<"the sorted array is\n";
	// selection_sort(a,n);
	// bubble_sort(a,n);
	// insertion_sort(a,n);
	// merge_sort(a,0,n-1);
	quick_sort(a,0,n-1);
	// shellSort(a,n);
	// radix_sort(a,n);
	//heap
	//counting
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}