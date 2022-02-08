#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("input_brute.txt", "w", stdout); 
    srand(time(0));
    int n=rand()%15+1;
    cout<<n<<endl;
    for(int i=0;i<n;i++){
        int temp=rand()%15+1;
        cout<<temp<<endl;
        set<int> s;
        while(s.size()!=temp){
            s.insert(rand()%temp+1);
        }
        for(auto x:s){
            cout<<"I"<<x<<" ";
        }
        cout<<endl;
	}
    vector<int> min_sup={2,3,4};
    cout<<min_sup[rand()%3]<<endl;
    return 0;    
}