#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
int n;
cout<<"enter the value of n\n";
cin>>n;
float flag=1;float pi=0;
for(float i=0;i<n;i++)
{
pi+=(flag)*(1.0/(2*(i)+1.0));
flag=flag*-1;
}
pi*=4;
cout<<setprecision(4)<<pi<<endl;
return 0;
}
