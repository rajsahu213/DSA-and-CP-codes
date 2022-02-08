
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

void shortest_path(int s,int d,vector<weight> adj[], bool vis[],float dis[],int prev[],int N,map<pair<int,int>,bool> &mp)
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
        		if(log(dis[t1]+1)+log(adj[t1][i].wei+1)<log(dis[adj[t1][i].data]+1))
        		{
        			dis[adj[t1][i].data]=log(dis[t1]+1)+log(adj[t1][i].wei+1);
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
    int prev[v];
    float dis[v];
    map<pair<int,int>,bool> mp;
    for(int i=1;i<v;i++)
    { 
        bool vis[v]={false};
        shortest_path(0,i,adj_list,vis,dis,prev,v,mp);
    }
    int sum=1;
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<adj_list[i].size();j++)
        {
            if(mp[{i,adj_list[i][j].data}])
            {
                sum*=adj_list[i][j].wei;
            }
        }
    }
    cout<<"the minimum product of the spanning tree is: "<<sqrt(sum)<<endl;
}

// 1 2 2 4 3 1 -1 -1
// 0 2 3 3 4 10 -1 -1
// 0 4 3 2 5 5 -1 -1
// 0 1 1 3 2 2 4 6 5 8 6 4 -1 -1
// 1 10 3 6 6 6 -1 -1
// 2 5 3 8 6 1 -1 -1
// 3 4 4 6 5 1 -1 -1