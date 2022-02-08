#include<bits/stdc++.h>
using namespace std;
#define ll long 
int main(){
	cout<<5<<endl;
	for(ll t=0;t<5;t++){
		ll n=rand()%100;
		cout<<n<<endl;
		for(ll i=0;i<n-1;i++){
			cout<<rand()%n<<" "<<rand()%n<<endl;
		}
	}
}