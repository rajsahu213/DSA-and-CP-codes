#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("rand_input.txt", "r", stdin); 
    freopen("output2.txt", "w", stdout); 
  	int n;
    cin>>n;
    map<string,int> count;
    for(int i=0;i<n;i++){
    	int num_of_trans;cin>>num_of_trans;
    	for(int k=0;k<num_of_trans;k++){
    		string trans;cin>>trans;
    		count[trans]++;
		}
	}
    for(auto i:count){
        cout<<i.first<<" "<<i.second<<endl;
    }
    return 0;    
}