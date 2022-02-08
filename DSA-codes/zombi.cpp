#include <bits/stdc++.h>
using namespace std;

int compare(const void * a, const void * b) 
{ 
    return ( *(int*)a - *(int*)b ); 
} 

int check(int a[],int c[],int h[],int n)
{
    for(int i=1;i<=n;i++)
    {
        int s1=i-c[i],s2=i+c[i];
        if(s1<0){s1=0;}
        if(s2>n){s2=n;}
        for(int k=s1;k<=s2;k++)
        {
            a[k]+=1;
        }
    }
    int flag=1;
    qsort(a, n+1, sizeof(int), compare);
    for(int i=1;i<=n;i++)
    {
    	cout<<a[i]<<endl;
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=h[i])
        {
            flag=0;
            break;
        }
    }
    return flag;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n+1],h[n+1],c[n+1];
	    for(int i=1;i<=n;i++)
	    {
	        cin>>c[i];
	        a[i]=0;
	    }
	    for(int i=1;i<=n;i++)
	    {
	        cin>>h[i];
	    }
	    qsort(h+1, n+1, sizeof(int), compare);
	    for(int i=1;i<=n;i++)
	    {
	    	cout<<h[i]<<endl;
	    }
	    int flag=check(a,c,h,n);
	    if(flag==1)cout<<"YES"<<endl;
	    else cout<<"NO"<<endl;
	}
	return 0;
}
