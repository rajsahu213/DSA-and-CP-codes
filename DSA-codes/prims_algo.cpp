#include<bits/stdc++.h>
using namespace std;

struct weight
{
    int data;
    int wei;
};

typedef vector<weight> graph;
typedef map<pair<int,int>,bool> maping;

void adjlist_undir_weight(int v,vector<weight> adj_list[])
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
            struct weight b;
            b.data=i;b.wei=a.wei;
            adj_list[a.data].push_back(b);
        }
    }
}


void print_adjlist_wei(graph adj_list[],int v)
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

int min(int dis[],int v)
{
    int mi=0;
    for(int i=1;i<v;i++)
    {
        if(dis[i]<dis[mi])
        {
            mi=i;
        }
    }
    return mi;
}

void prims_algo(graph adj[],int v,vector<int> &mst)
{
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
    vector<weight> adj_list[v];
    adjlist_undir_weight(v,adj_list);
    print_adjlist_wei(adj_list,v);
    vector<int> mst;
    prims_algo(adj_list,v,mst);
    cout<<"the spanning tree is given by\n";
    for(int i=0;i<mst.size();i++)
    {
        cout<<mst[i]<<" ";
    }
    cout<<endl;
}

// 1 4 7 8 -1 -1
// 2 9 7 11 -1 -1
// 3 7 5 4 8 2 -1 -1
// 4 9 5 14 -1 -1
// 5 10 -1 -1
// 6 2 -1 -1
// 7 1 8 6 -1 -1
// 8 7 -1 -1 
// -1 -1