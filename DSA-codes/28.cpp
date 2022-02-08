#include<iostream>
using namespace std;
int power(int a,int b)
{
int fact=1;
while(b!=0)
{
fact=fact*a;
b=b-1;
}
cout<<fact<<endl;
return 0;
}
int main()
{
int a,b;
cout<<"enter the value of a and b\n";
cin>>a>>b;
power(a,b);
return 0;
}
