
class disjointSet{
	private:
		ll n;
		vector<ll> parent,size;
	public:
		disjointSet(ll nn){
			n=nn;
			parent.resize(n);size.resize(n);
		}
		void make_set(ll a){
			parent[a]=a;
			size[a]=1;
		}
		ll find_set(ll a){
			if(parent[a]==a)
				return a;
			return parent[a]=find_set(parent[a]);
		}
		void union_set(ll a,ll b){
			a=find_set(a);
			b=find_set(b);
			if(a!=b){
				if(size[a]<size[b])
					swap(a,b);
				parent[b]=a;
				size[a]+=size[b];
			}
		}
};
