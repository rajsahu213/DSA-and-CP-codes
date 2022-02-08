#include<bits/stdc++.h>
using namespace std;
int fun(vector<string> &temp,vector<vector<string>> &a){
	int ans=0;
	for(int i=0;i<a.size();i++){
		bool ok=true;
		for(int j=0;j<temp.size();j++){
			bool found=false;
			for(int k=0;k<a[i].size();k++){
				if(temp[j]==a[i][k]){
					found=true;
					break;
				}
			}
			if(!found){
				ok=false;
				break;
			}
		}
		if(ok){
			ans++;
		}
	}
	return ans;
}

int main(){
	freopen("input_brute.txt","r",stdin);
	freopen("output_brute.txt","w",stdout);
	int n;cin>>n;
	vector<vector<string>> a(n);
	set<string> items;
	for(int i=0;i<n;i++){
		int num_item;cin>>num_item;
		a[i].resize(num_item);
		for(int j=0;j<num_item;j++){
			string item;cin>>item;
			a[i][j]=item;
			items.insert(item);
		}
	}
	int min_sup;cin>>min_sup;
	for(int i=0;i<n;i++){
		sort(a[i].begin(),a[i].end());
	}
	vector<string> temp(items.begin(),items.end());
	int num=items.size();
	vector<vector<string>> sub;
	for(int bit=1;bit<(1<<num);bit++){
		vector<string> curr;
		for(int i=0;i<num;i++){
			if((1<<i) & bit){
				curr.push_back(temp[i]);
			}
		}
		sub.push_back(curr);
	}
	vector<vector<string>> ans;
	for(int i=0;i<sub.size();i++){
		if(fun(sub[i],a)>=min_sup){
			ans.push_back(sub[i]);
		}
	}
	sort(ans.begin(),ans.end());
	sort(ans.begin(),ans.end(),[&](const vector<string> &p1,const vector<string> &p2){
		if(p1.size()!=p2.size())return p1.size()<p2.size();
		else return p1<p2;
	});
	for(auto i:ans){
		for(string x:i){
			cout<<x<<" ";
		}
		cout<<"\n";
	}
}