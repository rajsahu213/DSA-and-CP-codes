#include<bits/stdc++.h>
using namespace std;
int fun(vector<int> &a,vector<int> &b){
	set<int> temp;
	for(int x:a)temp.insert(x);
	int ans=0;
	for(int x:b){
		if(temp.find(x)!=temp.end()){
			ans++;
		}
	}
	return ans;
}

int main(){
	int num;cin>>num;//number of transactions
	vector<set<int>> a(num);
	for(int i=0;i<num;i++){
		int n;cin>>n;//number of items;
		for(int j=0;j<n;j++){
			int item;cin>>item;
			a[i].insert(item);
		}
	}
	int min_sup;cin>>min_sup;//minimum support count
	map<int,int> mp;
	for(int i=0;i<num;i++){
		for(int x:a[i]){
			mp[x]++;
		}
	}
	set<set<int>> l;
	cout<<"1th item set"<<endl;
	for(auto i:mp){
		set<int> t;
		if(i.second>=min_sup){
			cout<<i.first<<endl;
			t.insert(i.first);
			l.insert(t);
		}
	}
	int common=0;
	while(true){
		if(l.size()==0)break;
		cout<<common+2<<"th item set"<<endl;
		vector<vector<int>> temp;
		for(auto i:l){
			vector<int> c(i.begin(),i.end());
			temp.push_back(c);
		}
		l.clear();
		for(int i=0;i<temp.size();i++){
			for(int j=i+1;j<temp.size();j++){
				if(fun(temp[i],temp[j])==common){
					set<int> new_c;
					for(int k=0;k<temp[i].size();k++){
						new_c.insert(temp[i][k]);
					}
					for(int k=0;k<temp[j].size();k++){
						if(new_c.find(temp[j][k])==new_c.end()){
							new_c.insert(temp[j][k]);
						}
					}
					l.insert(new_c);
				}
			}
		}
		set<set<int>> new_l;
		for(auto i:l){
			int cnt=0;
			for(int j=0;j<a.size();j++){
				int count=0;
				for(int x:a[j]){
					if(i.find(x)!=i.end()){
						count++;
					}
				}
				if(count==(int)i.size()){
					cnt++;
				}
			}
			if(cnt>=min_sup){
				new_l.insert(i);
			}
		}
		l=new_l;
		for(auto i:l){
			cout<<"{ ";
			for(int x:i){
				cout<<x<<" ";
			}
			cout<<"}"<<endl;
		}
		common++;
	}
}