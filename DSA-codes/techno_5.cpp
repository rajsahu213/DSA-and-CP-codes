#include<bits/stdc++.h>
using namespace std;

struct weight
{
    int data;
    int wei;
};

typedef vector<weight> graph;

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

void adjlist_undir_weight(int e,int v,vector<weight> adj_list[])
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

void boruvkar_algo(graph adj[],int v,vector<vector<int>> &f)
{
    vector<int> chpst_edge;
    for(int i=0;i<v;i++)
    {
        vector<int> temp;
        temp.push_back(i);
        f.push_back(temp);
    }
    int compo[v];
    while(f.size()>1)
    {
        for(int i=0;i<f.size();i++)
        {
            for(int j=0;j<f[i].size();j++)
            {
                compo[f[i][j]]=i;
            }
            chpst_edge.push_back(INT_MAX);
        }
        for(int i=0;i<v;i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                if(compo[i]!=compo[adj[i][j].data])
                {
                    if(adj[i][j].wei<chpst_edge[compo[i]])
                    {
                        chpst_edge[compo[i]]=adj[i][j].wei;
                    }    
                    if(adj[i][j].wei<chpst_edge[compo[adj[i][j].data]])
                    {
                        chpst_edge[compo[adj[i][j].data]]=adj[i][j].wei;
                    }                     
                }
            }
        }
        for(int i=0;i<f.size();i++)
        {
            if(chpst_edge[i]!=INT_MAX)
            {
                
            }
        }
    }
}

int main()
{
    cout<<"enter v: ";
    int v;cin>>v;
    graph adj_list[v];
    // cout<<"enter e: ";
     int e;//cin>>e;
    adjlist_undir_weight(e,v,adj_list);
    print_adjlist_wei(adj_list,v);
    vector<vector<int>> vt;
    boruvkar_algo(adj_list,v,vt);
}