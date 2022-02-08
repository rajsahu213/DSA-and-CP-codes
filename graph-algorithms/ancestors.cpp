#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vl vector<ll>
#define vvl vector<vl>

vvl tree;
vl startTime,endTime,color;
ll n,m,TIME;

void DFS(ll root){
	startTime[root]=TIME++;
	color[root]=1;
	for(ll node:tree[root]){
		if(color[node]==0){
			DFS(node);
		}
	}
	endTime[root]=TIME++;
	color[root]=2;
}

void getAnc(ll &node,vl &a){
	for(ll i=0;i<n;i++){
		if(startTime[i]<=startTime[node] && endTime[i]>=endTime[node]){
			a.push_back(i+1);
		}
	}
}

ll LCA(vl &a,vl &b){
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	ll i=0,j=0,ans=LLONG_MIN,lc;
	while(i<a.size() && j<b.size()){
		if(a[i]==b[j]){
			if(startTime[a[i]-1]>ans){
				ans=startTime[a[i]-1];
				lc=a[i];
			}
			i++;j++;
		}else if(a[i]>b[j]){
			j++;
		}else{
			i++;
		}
	}
	return lc;
}

int main(){
	cin>>n;
	cin>>m;
	tree.resize(n);
	startTime.resize(n),endTime.resize(n);
	color.resize(n,0);TIME=0;
	for(ll i=0;i<m;i++){
		ll u,v;cin>>u>>v;
		u--;v--;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	cout<<"enter the root of the tree: ";
	ll root;cin>>root;root--;
	DFS(root);
	cout<<"enter the first node: ";
	ll node1;cin>>node1;node1--;
	cout<<"enter the second node: ";
	ll node2;cin>>node2;node2--;
	cout<<"the ancestor of the entered node are\n";
	vl anc1,anc2;
	getAnc(node1,anc1);
	getAnc(node2,anc2);
	cout<<LCA(anc1,anc2)<<endl;
}