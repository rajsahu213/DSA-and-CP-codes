#include<iostream>
using namespace std;
void tower(int n,int i,int j)
{
if(n==0) return;
tower(n-1,i,6-i-j);
cout<<n<<":"<<i<<" to "<<j<<endl;
tower(n-1,6-i-j,j);
}
int main()
{
int n;
cin>>n;
tower(n,1,2);
return 0;
}
