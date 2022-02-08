#include<iostream>
using namespace std;
int merge_sort(int a[],int low,int high);
void merge(int a[],int low,int high);
int main()
{
	cout<<"enter n: ";
	int n;cin>>n;
	int a[n];
	cout<<"enter numbers\n";
	for(int i=0;i<n;i++){cin>>a[i];}
	cout<<"the sorted array is: \n";
	merge_sort(a,0,n-1);
	for(int i=0;i<n;i++){cout<<a[i]<<endl;}
	return 0;	
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
	int temp[1000];
	while(i<=mid&&j<=high)
	{
		if(a[i]<a[j]){temp[k++]=a[i++];}
		else{temp[k++]=a[j++];}
	}
	while(i<=mid){temp[k++]=a[i++];}
	while(j<=high){temp[k++]=a[j++];}
	for(int i=low;i<=high;i++)
		{a[i]=temp[i];}
}