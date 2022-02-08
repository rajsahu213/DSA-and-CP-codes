#include<bits/stdc++.h>
using namespace std;

struct weight
{
    int data;
    int wei;
};

typedef vector<weight> graph;
typedef map<pair<int,int>,bool> maping;

void print_adjlist_wei(vector<weight> adj_list[],int v)
{
    cout<<"the adjacency list is\n";
    for(int i=0;i<v;i++)
    {
        cout<<i;
        for(int j=0;j<adj_list[i].size();j++)
        {
            cout<<"-> "<<adj_list[i][j].data<<" "<<adj_list[i][j].wei;
        }
        cout<<endl;
    }
}

void adjlist_dir_weight(int e,int v,vector<weight> adj_list[])
{
    for(int i=0;i<v;i++)
    {
        // cout<<"enter the adjacent vertex of "<<i<<" and its weight( -1 to stop )\n";
        while(1)
        {
            struct weight a;
            cin>>a.data>>a.wei;
            if(a.data==-1)break;
            adj_list[i].push_back(a);
        }
    }
}

void shortest_path(int s,int d,vector<weight> adj[], bool vis[],int dis[],int prev[],int N,map<pair<int,int>,bool> &mp)
{
    queue<int> q;
    q.push(s);
    for(int i=0;i<N;i++)vis[i]=false;
    for(int i=0;i<N;i++)dis[i]=INT_MAX;
    dis[s]=0;
    while(!q.empty())
    {
        int t1=q.front();
        q.pop();
        if(vis[t1]==false)
        {
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
    }
    while(1)
    {
         mp[{d,prev[d]}]=true;
         mp[{prev[d],d}]=true;
	     d=prev[d];
	     if(d==s)break;
    }
}


int main()
{
    cout<<"enter v: ";
    int v;cin>>v;
    graph adj_list[v];
    // cout<<"enter e: ";
    int e;
    adjlist_dir_weight(e,v,adj_list);
    print_adjlist_wei(adj_list,v);
    int dis[v],prev[v];
    map<pair<int,int>,bool> mp;
    for(int i=1;i<v;i++)
    { 
        bool vis[v]={false};
        shortest_path(0,i,adj_list,vis,dis,prev,v,mp);
    }
    int sum=0;
    cout<<0<<" ";
    bool vis[v]={false};
    vis[0]=true;
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<adj_list[i].size();j++)
        {
            if(mp[{i,adj_list[i][j].data}])
            {
                sum+=adj_list[i][j].wei;
                if(!vis[adj_list[i][j].data])cout<<adj_list[i][j].data<<" ";
                vis[adj_list[i][j].data]=true;
            }
        }
    }
    cout<<endl;
    cout<<"the sum of minimum spanning tree is: "<<sum/2<<endl;
}

// 1 13 4 7 5 28 -1 -1
// 0 13 2 39 5 27 -1 -1
// 1 39 3 36 5 34 -1 -1
// 2 36 4 7 5 14 -1 -1
// 0 7 3 7 5 2 -1 -1
// 0 28 1 27 2 34 3 14 4 2 -1 -1