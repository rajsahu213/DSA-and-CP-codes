/*
BELLMAN & FORD ALGORITHM 
find the shortest path from a source vertex s
to all other vertex in an directed or undirected graph
with negative weights and no negative weight cycle
and to detect if there is a negative weight cycle recheable
from vertex s
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pll pair<ll,ll>
const ll inf=1e16;
struct edge{
	ll u,v,w;
	edge(ll u,ll v,ll w){
		this->u=u;this->v=v;this->w=w;
	}
};
ll n,m;
bool bellman(ll s,vector<edge> &a,vector<ll> &d,vector<ll> &p){
	d.assign(n,inf);
	p.assign(n,-1);
	d[s]=0;ll count=0;
	while(true){
		bool any=false;
		for(ll i=0;i<m;i++){
			if(d[a[i].u]<inf){
				if(d[a[i].v]>d[a[i].u]+a[i].w){
					d[a[i].v]=d[a[i].u]+a[i].w;
					p[a[i].v]=a[i].u;
					any=true;
				}
			}
		}
		if(!any)break;
		if(count==n){
			return true;
		}
		count++;
	}
	return false;
}
ll fun(ll n, ll k){
	if(n==1){
		ll sum=0;
		while(k>0){
			sum+=k%10;
			k=k/10;
		}
		return sum*sum;
	}else{
		return fun(1,fun(n-1,k));
	}
}

int main(){
	cout<<fun(1988,11)<<endl;
}