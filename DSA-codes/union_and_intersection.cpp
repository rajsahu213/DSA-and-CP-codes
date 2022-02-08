#include<iostream>
using namespace std;
void union_and_intersection(int a1[],int a2[],int n1,int n2);

int main()
{
	cout<<"enter n1: ";
	int n1;cin>>n1;
	cout<<"enter n2: ";
	int n2;cin>>n2;
	int a1[n1],a2[n2];
	cout<<"enter the first array\n";
	for(int i=0;i<n1;i++)
	{
		cin>>a1[i];
	}
	cout<<"enter the second array\n";
	for(int i=0;i<n2;i++)
	{
		cin>>a2[i];
	}
	union_and_intersection(a1,a2,n1,n2);
}

void union_and_intersection(int a1[],int a2[],int n1,int n2)
{
	int a3[n1+n2],a4[n2];
	int i=0,j=0,k=0,x=0;
	while(i<n1&&j<n2)
	{
		if(a1[i]<a2[j]){a3[k++]=a1[i++];}
		else if(a1[i]>a2[j]){a3[k++]=a2[j++];}
		else{a3[k++]=a1[i++];a4[x++]=a2[j++];}
	}
	while(i<n1){a3[k++]=a1[i++];}
	while(j<n2){a3[k++]=a2[j++];}
	cout<<"the union of two array is: ";
	for(int h=0;h<k;h++)
	{
		cout<<a3[h]<<"   ";
	}
	cout<<endl;
	cout<<"the intersection of two array is: ";
	for(int m=0;m<x;m++)
	{
		cout<<a4[m]<<"   ";
	}
	cout<<endl;
}