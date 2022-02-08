#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("rand_input.txt", "r", stdin); 
    freopen("output3.txt", "w", stdout); 
  	int n;
    cin>>n;
    map<string,vector<int>> mp;
    for(int i=0;i<n;i++){
    	int num_of_trans;cin>>num_of_trans;
    	for(int k=0;k<num_of_trans;k++){
    		string trans;cin>>trans;
    		mp[trans].push_back(i);
		}
	}
    for(auto i:mp){
        cout<<i.first<<" ";
        for(int x:i.second){
            cout<<"T"<<x+1<<" ";
        }
        cout<<endl;
    }
    return 0;    
}