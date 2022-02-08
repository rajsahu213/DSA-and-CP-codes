#include<iostream>
using namespace std;
int binary_search(int a[],int low,int high,int x,int flag)
{
	int result=-1;
	while(high>=low)
	{
		int mid=low+(high-low)/2;
		if(a[mid]==x){
			if(flag==0){result=mid;high=mid-1;}
			else if(flag==1){result=mid;low=mid+1;}
		}
		else if(a[mid]>x){high=mid-1;}
		else{low=mid+1;}
	}
	return result;
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
int main()
{
	int a[1000],b,n;
	cout<<"enter the value of n\n";
	cin>>n;
	cout<<"enter the numbers\n";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"the sorted array is\n";
	insertion_sort(a,n);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<endl;
	}
	cout<<"enter the number to be searched\n";
	cin>>b;
	int fiocc=binary_search(a,0,n-1,b,0);
	int lastocc=binary_search(a,0,n-1,b,1);
	int flag=lastocc-fiocc+1;
	if(fiocc==-1&&lastocc==-1){flag=0;}
	cout<<"the number of times that numbers occured is "<<flag<<endl;
	
	return 0;
}