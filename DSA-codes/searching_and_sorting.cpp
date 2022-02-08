#include<bits/stdc++.h>
using namespace std;
int selection_sort(int a[],int n);
int bubble_sort(int a[],int n);
int insertion_sort(int a[],int n);
void merge(int a[],int low,int high);
int merge_sort(int a[],int low,int high);
int linear_search(int a[],int n,int x);
int binary_search(int a[],int n,int x);
int main()
{
	cout<<"enter n: ";
	int n;cin>>n;
	cout<<"enter numbers\n";
	int a[n];
	for(int i=0;i<n;i++){cin>>a[i];}
	cout<<"the sorted array is: "<<endl;
	merge_sort(a,0,n-1);
	for(int i=0;i<n;i++){cout<<a[i]<<endl;}
	cout<<"enter the number: ";
	int x;cin>>x;
	int flag=binary_search(a,n-1,x);
	if(flag==-1){cout<<"number not found\n";}
	else {cout<<"number is at "<<flag +1<<" position\n";}	
}

int selection_sort(int a[],int n)
{
	int temp,min;
	for(int i=0;i<n-1;i++)
	{
		min=i;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<a[min]){min=j;}
		}
		temp=a[i];a[i]=a[min];a[min]=temp;
	}
}

int bubble_sort(int a[],int n)
{
	int temp,flag,last;
	for(int i=0;i<n;i++)
	{
		last=n-1-i;flag=0;
		for(int j=0;j<last;j++)
		{
			if(a[j+1]<a[j]){temp=a[j];a[j]=a[j+1];a[j+1]=temp;flag=1;}
		}
		if(flag==0){break;}
	}
}

int insertion_sort(int a[],int n)
{
	int value,hole;
	for(int i=1;i<n;i++)
	{
		value=a[i];hole=i;
		while(hole>0&&a[hole-1]>value)
		{
			a[hole]=a[hole-1];
			hole--;
		}
		a[hole]=value;
	}
}

int merge_sort(int a[],int low,int high)
{
	if(high>low)
	{
		int mid=low+(high-low)/2;
		merge_sort(a,low,mid);
		merge_sort(a,mid+1,high);
		merge(a,low,high);
	}
	else return 0;
}

void merge(int a[],int low,int high)
{
	int mid=low+(high-low)/2;
	int i=low;
	int j=mid+1;
	int k=low;
	int temp[high+10];
	while(i<=mid&&j<=high)
	{
		if(a[i]<a[j]){temp[k++]=a[i++];}
		else {temp[k++]=a[j++];}
	}
	while(i<=mid){temp[k++]=a[i++];}
	while(j<=high){temp[k++]=a[j++];}
	for(int i=low;i<=high;i++)
	{
		a[i]=temp[i];
	}
}

int linear_search(int a[],int n,int x)
{
	for(int i=0;i<n;i++)
	{
		if(a[i]==x){return i;}
	}
	return -1;
}

int binary_search(int a[],int n,int x)
{
	int low=0;
	int high=n;
	while(low<=high)
	{
		int mid=low+(high-low)/2;
		if(a[mid]==x){return mid;}
		else if(a[mid]>x){high=mid-1;}
		else {low=mid+1;}
	}
	return -1;
}