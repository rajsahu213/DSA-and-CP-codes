#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<string>
using namespace std;

typedef long long int ll;

string removedupli(string s) 
{  
    int count=0,x,size,length=0,i=0; 
    size = s.size(); 
    while (i < size)
    { 
        x = s[i] - 97; 
        if ((count&(1<<x))==0)
        { 
            s[length] = 'a' + x; 
            count= count|(1 << x); 
            length++; 
        } 
        i++; 
    } 
  
    return s.substr(0, length); 
} 

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		cout <<removedupli(s)<<endl;
	}
}