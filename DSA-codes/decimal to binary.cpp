#include<iostream>
using namespace std;
int main()
{
	cout<<"enter the decimal number\n";
	float n;
	cin>>n;
	int n1=n;
	float n2=n-n1;
	int a[1000],i=0;
	while(n1!=0)
	{
		a[i]=n1%2;
		n1=n1/2;
		i++;
	}
	int b[100],k=0;
	while(n2!=1)
	{
		n2=n2*2;
		if(n2>1){b[k]=1;n2=n2-1;}
		else if(n2==1){b[k]=1;}
		else{b[k]=0;}
		k++;
	}
	
     
	cout<<"the number in binary number system is: ";
	for(int j=i-1;j>=0;j--)
	{
		cout<<a[j];
	}
	cout<<".";
	for(int h=0;h<k;h++)
	{
		cout<<b[h];
	}
	cout<<endl;
	return 0;
}