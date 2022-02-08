#include<bits/stdc++.h>
using namespace std;
int a[1000000];int n;
void insert(int n,int p);
void replace(int n,int p);
void delet(int p);
int binary_search(int a[],int low,int high,int x);
void bubble_sort(int a[],int n);
int main()
{
	cout<<"enter the value of n\n";
	cin>>n;
	cout<<"enter the numbers\n";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int c;
	do{
	cout<<"enter the choice: \n";
	cout<<"1: sort the array\n";
	cout<<"2: insert a number\n";
	cout<<"3: delete a number\n";
	cout<<"4: replace a number\n";
	cout<<"5: search a number\n";
	cout<<"6: exit\n";
	cin>>c;
	switch(c)
	{
		case 1: cout<<"the sorted array is \n";
				bubble_sort(a,n);
				for(int i=0;i<n;i++)
					{
						cout<<a[i]<<endl;
					}
				break;

		case 2: cout<<"enter the number and the postion to be inserted\n";
   				int p,k;
				cin>>k>>p;
				insert(k,p);
				n=n+1;
				cout<<"the resulting array is\n";
				for(int i=0;i<n;i++)
				{
					cout<<a[i]<<endl;
				}	
				break;
		case 3:{cout<<"enter the number you want to delete\n";
				int g;
				cin>>g;
				int flag=binary_search(a,0,n-1,g);
				if(flag==-1){cout<<"number not found\n";}
				else{
					delet(flag+1);
					cout<<"the resulting array is\n";
					n=n-1;
					for(int i=0;i<n;i++)
					{
						cout<<a[i]<<endl;
					}	
					}
				break;}
		case 4: {int l,f;
				cout<<"enter the number you want to replace\n";
				cin>>l;
				cout<<"enter the new number\n";
				cin>>f;
				int flag2=binary_search(a,0,n-1,l);
				if(flag2==-1){cout<<"number not found\n";}
				else{
					replace(f,flag2);
					cout<<"the resulting array is\n";
					for(int i=0;i<n;i++)
					{
						cout<<a[i]<<endl;
					}	
				}
				break;}	
		case 5:{cout<<"enter the number you want to search\n";
			  int b;
			  cin>>b;
			  bubble_sort(a,n);	
			  int flag3=binary_search(a,0,n-1,b);
				if(flag3==-1){cout<<"number not found\n";}
				else{cout<<"the number is at a position of "<<flag3+1<<endl;}
				break;}	

		case 6:break;

		default:cout<<"wrong choice.try again\n";
				break;			
	}
}while(c!=6);
return 0;	
}
void insert(int n,int p)
{
    for(int i=n;i>=p;i--)
    {
       a[i]=a[i-1];
    }
    a[p-1]=n;
}
void replace(int n,int p)
{
	a[p]=n;
}
void delet(int p)
{
	for(int i=p-1;i<n-1;i++)
	{
		a[i]=a[i+1];
	}
}
void bubble_sort(int a[],int n)
{
	int last;
	for(int i=0;i<n;i++)
	{
		last=n-1-i;
		for(int j=0;j<last;j++)
		{
			if(a[j+1]<a[j]){int temp=a[j];a[j]=a[j+1];a[j+1]=temp;}
		}
	}
}
int binary_search(int a[],int low,int high,int x)
{
	if(high>=low)
	{
		int mid=low+(high-low)/2;
		if(a[mid]==x){return mid;}
		else if(a[mid]>x){return binary_search(a,low,mid-1,x);}
		else {return binary_search(a,mid+1,high,x);}
	}
	else return -1;
}