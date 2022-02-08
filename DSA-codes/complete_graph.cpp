#include<bits/stdc++.h>
using namespace std;
// #define v 5

struct weight
{
	int wei;
	int data;
};

typedef vector<int> graph_int;
typedef vector<weight> graph_wei;
typedef map<pair<int,int>,bool> maping;

// void adj_mtx_undir(int g[][v])
// {
// 	cout<<"enter the edge pair( -1 to stop )\n";
// 	while(1)
// 	{
// 		int m,n;
// 		cin>>m>>n;
// 		if(m==-1)break;
// 		g[m][n]=1;
// 		g[n][m]=1;
// 	}
// }

// void adj_mtx_dir(int g[][v])
// {
// 	cout<<"enter the edge pair( -1 to stop )\n";
// 	while(1)
// 	{
// 		int m,n;
// 		cin>>m>>n;
// 		if(m==-1)break;
// 		g[m][n]=1;
// 	}
// }

// void adj_mtx_undir_wei(int g[][v])
// {
// 	cout<<"enter the edge pair and the weight of that edge( -1 to stop )\n";
// 	while(1)
// 	{
// 		int m,n,w;
// 		cin>>m>>n>>w;
// 		if(m==-1)break;
// 		g[m][n]=w;
// 		g[n][m]=w;
// 	}
// }

// void adj_mtx_dir_wei(int g[][v])
// {
// 	cout<<"enter the edge pair and the weight of that edge( -1 to stop )\n";
// 	while(1)
// 	{
// 		int m,n,w;
// 		cin>>m>>n>>w;
// 		if(m==-1)break;
// 		g[m][n]=w;
// 	}
// }

// int main() matrix main
// {
// 	int g[v][v];
// 	for(int i=0;i<v;i++)
// 		for(int j=0;j<v;j++)
// 			g[i][j]=0;
// 	adj_mtx_dir_wei(g);
// 	cout<<"the entered graph is\n";
// 	for(int i=0;i<v;i++)
// 	{	
// 		for(int j=0;j<v;j++)
// 		{
// 			cout<<g[i][j]<<" ";
// 		}
// 		cout<<endl;
// 	}			
// }

void adj_list_undir(graph_int adj[],int v)
{
	for(int i=0;i<v;i++)
	{
		// cout<<"enter the adj vert of "<<i<<" (-1 to stop )\n";
		while(1)
		{
			int n;cin>>n;
			if(n==-1)break;
			adj[i].push_back(n);
			adj[n].push_back(i);
		}
	}
}

void adj_list_dir(graph_int adj[],int v)
{
	for(int i=0;i<v;i++)
	{
		// cout<<"enter the adj vert of "<<i<<" (-1 to stop )\n";
		while(1)
		{
			int n;cin>>n;
			if(n==-1)break;
			adj[i].push_back(n);
		}
	}
}

void adj_list_undir_wei(graph_wei adj[],int v)
{
	for(int i=0;i<v;i++)
	{
		// cout<<"enter the adj vert of "<<i<<" and its weight (-1 to stop )\n";
		while(1)
		{
			struct weight a;
			cin>>a.data>>a.wei;
			if(a.data==-1)break;
			adj[i].push_back(a);
			struct weight b;
			b.data=i;b.wei=a.wei;
			adj[a.data].push_back(b);
		}
	}
}

void adj_list_dir_wei(graph_int adj[],int v,int wei[])
{
	for(int i=0;i<v;i++)
	{
		// cout<<"enter the adj vert of "<<i<<" and its weight (-1 to stop )\n";
		while(1)
		{
			int a;cin>>a;
			if(a==-1)break;
			adj[i].push_back(a);
		}
		// cout<<"enter the weight of vertex "<<i<<" : ";
		cin>>wei[i];
	}
}

void print_adj_list_unwei(graph_int adj[],int v)
{
	cout<<"the adjacency list is\n";
	for(int i=0;i<v;i++)
	{
		cout<<i<<" : ";
		for(int j=0;j<adj[i].size();j++)
		{
			cout<<"-> "<<adj[i][j];
		}
		cout<<endl;
	}
}

void print_adj_list_wei(graph_wei adj[],int v)
{
	cout<<"the adjacency list is\n";
	for(int i=0;i<v;i++)
	{
		cout<<i<<" ";
		for(int j=0;j<adj[i].size();j++)
		{
			cout<<"-> "<<adj[i][j].data<<" "<<adj[i][j].wei;
		}
		cout<<endl;
	}
}

bool check(graph_int &v,int x)
{
	for(int i=0;i<v.size();i++)
	{
		if(v[i]==x)return true;
	}
	return false;
}

void topo_sort(graph_int adj[],graph_int &v,int ind[],int n,int &count)
{
	if(v.size()==n)
	{
		for(int i=0;i<v.size();i++)
		{
			cout<<v[i]<<" ";
		}
		cout<<endl;count++;
		return;
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			if(!check(v,i))
			{
				if(ind[i]==0)
				{
					v.push_back(i);
					for(int j=0;j<adj[i].size();j++)
					{
						ind[adj[i][j]]--;
					}
					topo_sort(adj,v,ind,n,count);
					v.pop_back();
					for(int j=0;j<adj[i].size();j++)
					{
						ind[adj[i][j]]++;
					}
				}
			}
		}
	}
}

void dfs(int s,graph_wei adj[],bool vis[])
{
	if(!vis[s])
	{
		cout<<s<<" ";
		vis[s]=true;
		for(int i=0;i<adj[s].size();i++)
		{
			dfs(adj[s][i].data,adj,vis);
		}
	}
}

void bfs(graph_wei adj[],int s,bool vis[])
{
	queue<int> q;
	q.push(s);
	while(!q.empty())
	{
		int t1=q.front();
		q.pop();
		if(!vis[t1])cout<<t1<<" ";
		vis[t1]=true;
		for(int i=0;i<adj[t1].size();i++)
		{
			if(!vis[adj[t1][i].data])q.push(adj[t1][i].data);
		}
	}
}

void dijju(graph_wei adj[],int v,int s,int d)
{
	int dis[v];bool vis[v]={false};
	for(int i=0;i<v;i++)dis[i]=INT_MAX;
	int prev[v];dis[s]=0;
	queue<int> q;
	q.push(s);
	while(!q.empty())
	{
		int t1=q.front();
		q.pop();
		for(int i=0;i<adj[t1].size();i++)
		{
			if(dis[t1]+adj[t1][i].wei<dis[adj[t1][i].data])
			{
				dis[adj[t1][i].data]=dis[t1]+adj[t1][i].wei;
				prev[adj[t1][i].data]=t1;
			}
		}
		vis[t1]=true;
		for(int i=0;i<adj[t1].size();i++)
		{
			if(!vis[adj[t1][i].data])q.push(adj[t1][i].data);
		}
	}
	while(1)
	{
		cout<<d<<" ";
		d=prev[d];
		if(d==s)break;
	}
	cout<<s<<endl;
}

void dijju_vertex(graph_int adj[],int v,int s,int d,int wei[])
{
	int dis[v];bool vis[v]={false};
	for(int i=0;i<v;i++)dis[i]=INT_MAX;
	int prev[v];dis[s]=0;
	queue<int> q;
	q.push(s);
	while(!q.empty())
	{
		int t1=q.front();
		q.pop();
		for(int i=0;i<adj[t1].size();i++)
		{
			if(dis[t1]+wei[t1]<dis[adj[t1][i]])
			{
				dis[adj[t1][i]]=dis[t1]+wei[t1];
				prev[adj[t1][i]]=t1;
			}
		}
		vis[t1]=true;
		for(int i=0;i<adj[t1].size();i++)
		{
			if(!vis[adj[t1][i]])q.push(adj[t1][i]);
		}
	}
	while(1)
	{
		cout<<d<<" ";
		d=prev[d];
		if(d==s)break;
	}
	cout<<s<<endl;
}

void no_of_triangles(int s,int prev,int st,graph_int adj[],int flag,int &sum)
{
	if(flag==2)
	{
		for(int i=0;i<adj[s].size();i++)
		{
			if(adj[s][i]==st)
			{
				sum+=1;
				break;
			}
		}
		return;
	}
	else
	{
		for(int i=0;i<adj[s].size();i++)	
		{
			if(adj[s][i]!=prev)no_of_triangles(adj[s][i],s,st,adj,flag+1,sum);
		}
	}
}

void dfs_arr(int s,graph_int adj[],bool vis[],int arr[],int dep[],int &m)
{
	if(!vis[s])
	{
		// cout<<s<<" ";
		arr[s]=m++;
		vis[s]=true;
		for(int i=0;i<adj[s].size();i++)
		{
			dfs_arr(adj[s][i],adj,vis,arr,dep,m);
		}
		dep[s]=m++;
	}
}

int index(graph_int g[],int s,int x)
{
	for(int i=0;i<g[s].size();i++)
	{
		if(g[s][i]==x)return i;
	}
}

void euler_path(int s,graph_int adj[],int v,int st)
{
	cout<<s<<" ";
	for(int i=0;i<adj[s].size();i++)
	{
		int temp=adj[s][i];
		int m1=index(adj,temp,s);
		adj[temp].erase(adj[temp].begin()+m1);
		adj[s].erase(adj[s].begin()+i);
		for(int j=0;j<adj[s].size();j++)
		{
			int m=index(adj,adj[s][j],s);
			adj[adj[s][j]].erase(adj[adj[s][j]].begin()+m);
			adj[adj[s][j]].push_back(s);
		}
		for(int j=0;j<adj[st].size();j++)
		{
			int m=index(adj,adj[st][j],st);
			adj[adj[st][j]].erase(adj[adj[st][j]].begin()+m);
			adj[adj[st][j]].push_back(st);
		}	
		euler_path(temp,adj,v,st);	
	}
}

// bool check(graph_int &v,int x)
// {
// 	for(int i=0;i<v.size();i++)
// 	{
// 		if(v[i]==x)return true;
// 	}
// 	return false;
// }

bool is_edge(graph_int g[],int s,int x)
{
	for(int i=0;i<g[s].size();i++)
	{
		if(g[s][i]==x)return true;
	}
	return false;
}

void all_hamil(graph_int adj[],int n,graph_int &v)
{
	if(v.size()==n)
	{
		for(int i=0;i<n;i++)
		{
			cout<<v[i]<<" ";
		}
		cout<<endl;
		return;
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			if(!check(v,i))
			{
				if(is_edge(adj,v[v.size()-1],i))
				{
					v.push_back(i);
					all_hamil(adj,n,v);
					v.pop_back();
				}
			}
		}
	}
}

int min(int a[],int n)
{
	int mi=0;
	for(int i=1;i<n;i++)
	{
		if(a[i]<a[mi])mi=i;
	}
	return mi;
}

void prims_algo(graph_wei adj[],int v,graph_int &mst)
{
	int s=0;
	int dis[v]={0};
	for(int i=1;i<v;i++)dis[i]=INT_MAX;
	bool vis[v]={false};
	while(mst.size()<v)
	{
		int min_vert=min(dis,v);
		if(!vis[min_vert])
		{
			mst.push_back(min_vert);
			vis[min_vert]=true;
			for(int i=0;i<adj[min_vert].size();i++)
			{
				if(adj[min_vert][i].wei<dis[adj[min_vert][i].data])
				{
					dis[adj[min_vert][i].data]=adj[min_vert][i].wei;
				}
			}
		}
		else
		{
			dis[min_vert]=INT_MAX-1;
		}
	}
}

int main()
{
	cout<<"enter v: ";
	int v;cin>>v;
	graph_wei adj_list[v];
	// int ind[v]={0};
	// int wei[v];
	adj_list_undir_wei(adj_list,v);
	print_adj_list_wei(adj_list,v);
	// vector<int> ve;int i=0;
	// topo_sort(adj_list,ve,ind,v,i);
 //    cout<<i<<endl;
	// cout<<"enter the starting index of dfs: ";
	// int s;cin>>s;
	// bool vis[v]={false};
	// dfs(s,adj_list,vis);
	// for(int i=0;i<v;i++)
	// {
	// 	if(!vis[i])dfs(i,adj_list,vis);
	// }
	// bfs(adj_list,s,vis);
	// for(int i=0;i<v;i++)
	// {
	// 	if(!vis[i])bfs(adj_list,i,vis);
	// }	
	// cout<<endl;
	// cout<<"enter the starting index: ";
	// int s;cin>>s;
	// cout<<"enter the destination index: ";
	// int d;cin>>d;
	// dijju_vertex(adj_list,v,s,d,wei);
	// int sum=0;
	// for(int i=0;i<v;i++)
	// {
	// 	no_of_triangles(i,-1,i,adj_list,0,sum);
	// }
	// cout<<sum/6<<endl;
	// int arr[v],dep[v];bool vis[v]={false};int l=0;
	// dfs_arr(0,adj_list,vis,arr,dep,l);
	// for(int i=0;i<v;i++)
	// {
	// 	if(!vis[i])dfs_arr(i,adj_list,vis,arr,dep,l);
	// }
	// cout<<"the arrival time and departure time is given by\n";
	// for(int i=0;i<v;i++)
	// {
	// 	cout<<arr[i]<<"  "<<dep[i]<<endl;
	// }
	map<int,int> mp;
	for(int i=0;i<v;i++)
	{
		mp[dep[i]]=i;
	}	
	for(auto i=mp.rbegin();i!=mp.rend();++i)
	{
		cout<<i->second<<" ";
	}
	// cout<<endl;
	// cout<<"enter the starting index of euler path: ";
	// int s;cin>>s;bool vis[v];
	// euler_path(s,adj_list,v,s);
	// cout<<endl;
	// for(int i=0;i<v;i++)
	// {
	// 	graph_int vect;
	// 	vect.push_back(i);
	// 	all_hamil(adj_list,v,vect);
	// }
	graph_int mst;
	prims_algo(adj_list,v,mst);
	for(int i=0;i<v;i++)
	{
		cout<<mst[i]<<" ";
	}
	cout<<endl;
}

// 1 2 3 -1 
// 0 3 4 -1 
// 0 3 5 -1 
// 0 1 2 4 5 6 -1 
// 1 3 6 -1 
// 2 3 6 -1  
// 3 4 5 -1 

