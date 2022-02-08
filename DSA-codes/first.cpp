#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("output.txt", "w", stdout); 
  	int n;
    cin>>n;
    for(int i=0;i<n;i++){
    	cout<<"T"<<i+1<<" ";
    	int num_of_trans;cin>>num_of_trans;
    	for(int k=0;k<num_of_trans;k++){
    		string trans;cin>>trans;
    		cout<<trans<<" ";
		}
		cout<<"\n";
	}
    return 0;    
}