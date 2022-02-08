#include<bits/stdc++.h>
using namespace std;
struct seg1
{
	int avg;
	int max;
	int min;
	int sum;
};

int min(int a,int b)
{
	if(b==0)return a;
	else if(a<b)return a;
	else return b;
}

int max(int a,int b)
{
	if(a>b)return a;
	else return b;
}

int range(int a[],int i,int n,int min,int max,int u,int v,int m,int flag)
{
	if(i>=n)return 0; 
	if(min>=u&&max<=v)return a[i];
	else 
	{
		if(flag==3)return range(a,2*i+1,n,min,max-m/2,u,v,m/2,flag)+range(a,2*i+2,n,min+m/2,max,u,v,m/2,flag);
		else if(flag==1)return max(range(a,2*i+1,n,min,max-m/2,u,v,m/2,flag),range(a,2*i+2,n,min+m/2,max,u,v,m/2,flag));
		else return min(range(a,2*i+1,n,min,max-m/2,u,v,m/2,flag),range(a,2*i+2,n,min+m/2,max,u,v,m/2,flag));
	}
}

void creat(int seg[],int a[],int &p,int &n,int flag)
{
	int j,l=0,temp;
	for(int i=0;i<n;i++)
	{
		if(pow(2,i)>=n)
		{
			temp=pow(2,i);
			break;
		}
	}
	for(int i=n;i<temp;i++)
	{
		a[i]=0;
	}
	n=temp;j=2*n-2;
	for(int i=n-1;i>=0;i--)
	{
		seg[j--]=a[i];
	}
	p=2*n-1;l=0;
	if(flag==1)
	{
		for(int i=n-2;i>=0;i--)
		{
			seg[i]->max=max(seg[2*i+1],seg[2*i+2]);
		}
	}
	if(flag==2)
	{
		for(int i=n-2;i>=0;i--)
		{
			seg[i]->min=min(seg[2*i+1],seg[2*i+2]);
		}
	}
	if(flag==3)
	{
		for(int i=n-2;i>=0;i--)
		{
			seg[i]->sum=seg[2*i+1]+seg[2*i+2];
		}
	}
	int k=1;
	for(int i=0;i<p;i++)
	{
		if(i==(pow(2,k)-1)){cout<<endl;k++;}
		cout<<seg[i]<<" ";		
	}
	cout<<endl;		
}

int main()
{
	int n,temp,p,j,l=0;
	cout<<"enter n: ";
	cin>>n;int a[n];
	cout<<" enter the array\n";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int ch,flag1=0,flag2=0,flag3=0;
	struct segi seg[100];
	do
	{
		cout<<"####SEGMENT TREE####\n";
		cout<<"1: MAXIMUM ELEMENT IN A GIVEN RANGE\n";
		cout<<"2: MINIMUM ELEMENT IN A GIVEN RANGE\n";
		cout<<"3: SUM OF ELEMENTS IN A GIVEN RANGE\n";
		cout<<"4: average of ELEMENTs in a given array\n";
		cout<<"5: to exit\n";
		cout<<"enter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1: {if(true)creat(seg,a,p,n,1);
					cout<<"enter the range: ";
					int u,v;cin>>u>>v;flag1=1;
					cout<<"the MAXIMUM ELEMENT in that range is: "<<range(seg,0,p,0,n-1,u,v,n,1)<<endl;
					break;}
			case 2: {if(true)creat(seg,a,p,n,2);
					cout<<"enter the range: ";
					int u,v;cin>>u>>v;flag2=1;
					cout<<"the MINIMUM ELEMENT in that range is: "<<range(seg,0,p,0,n-1,u,v,n,2)<<endl;
					break;}
			case 3: {if(true)creat(seg,a,p,n,3);
					cout<<"enter the range: ";
					int u,v;cin>>u>>v;flag3=1;
					cout<<"the SUM OF ELEMENTS in that range is: "<<range(seg,0,p,0,n-1,u,v,n,3)<<endl;
					break;}	
			case 4: {if(true)creat(seg,a,p,n,3);
					cout<<"enter the range: ";
					int u,v;cin>>u>>v;flag3=1;
					cout<<"the average OF ELEMENTS in that range is: "<<range(seg,0,p,0,n-1,u,v,n,4)/(v-u+1)<<endl;
					break;}															
		}
	}while(ch!=5);	

}