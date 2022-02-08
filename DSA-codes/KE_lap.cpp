#include<iostream>
#include<fstream>
#include<map>
#include<vector>
#include <bits/stdc++.h>
using namespace std;
void sub(vector<string > &v,vector<string > &temp,int k,vector<vector<string >> &ans){
	if(k==v.size()){
		ans.push_back(temp);
		return;
	}
	sub(v,temp,k+1,ans);
	temp.push_back(v[k]);
	sub(v,temp,k+1,ans);
	temp.pop_back();
}
int check(vector<string> &z,vector<vector<string>> &v){
	int ans = 0;
	for(auto it : v){
		bool f=true;
		for(auto it2 : z){
			if(find(it.begin(),it.end(),it2) == it.end()) f=false;
			if(!f) break;
		}
		if(f) ans++;
	}
	return ans;
}
int main() {
	fstream fout("out",ios::out);
	fstream fin("in",ios::in);
	int n;fin >> n;
	int min_sup;fin >> min_sup;
	vector<vector<string>> v(n);
	map<string,int> m;
	vector<string> t;
	for(int i=0;i<n;i++){
		int k;fin >> k;
		for(int j=0;j<k;j++){
			string s;fin >> s;
			v[i].push_back(s);
			m[s]=1;
		}
	}
	for(auto it : m){
		t.push_back(it.first);
	}
	vector<vector<string>> ans;
	vector<string> temp;
	sub(t,temp,0,ans);
	for(auto it : v){
		sort(it.begin(),it.end());
	}
	for(auto it : ans){
		sort(ans.begin(),ans.end(),[&](vector<string> &p1,vector<string> &p2){
		return p1.size() < p2.size();
	});
	}
	map<int,int> freq;
	for(int i=0;i<ans.size();i++){
		freq[i] = check(ans[i],v);
	}
	for(auto it : freq){
		if(it.second >= min_sup){
		for(int i=0;i<ans[it.first].size();i++) fout << ans[it.first][i] << " ";
			fout << endl;
		}
	}
	return 0;
}