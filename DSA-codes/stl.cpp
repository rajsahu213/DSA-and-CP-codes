#include<bits/stdc++.h>
using namespace std;
typedef vector<int> graph;

void adjlist_undir(graph adj[],int v)
{
    for(int i=0;i<v;i++)
    {
        // cout<<"enter the adjacent vertex of "<<i<<endl;
        while(1)
        {
            int data;cin>>data;
            if(data==-1)break;
            adj[i].push_back(data);
            adj[data].push_back(i);
        }
    }
}

void adjlist_dir(graph adj[],int v)
{
    for(int i=0;i<v;i++)
    {
        // cout<<"enter the adjacent vertex of "<<i<<endl;
        while(1)
        {
            int data;cin>>data;
            if(data==-1)break;
            adj[i].push_back(data);
        }
    }
}

void print_unwlist(graph adj[],int v)
{
    cout<<"the entered adjacency list is\n";
    for(int i=0;i<v;i++)
    {
        cout<<i<<"  ";
        for(int j=0;j<adj[i].size();j++)
        {
            cout<<" -> "<<adj[i][j];
        }
        cout<<endl;
    }
}

struct weight
{
    int data;
    int wei;
};

typedef vector<weight> graphw;

void adjlist_undir_w(graphw adj[],int v)
{
    for(int i=0;i<v;i++)
    {
        // cout<<"enter the adjacent vertex and their weight of "<<i<<endl;
        while(1)
        {
            weight t;
            cin>>t.data>>t.wei;
            if(t.data==-1)break;
            adj[i].push_back(t);
            int data=t.data;t.data=i;
            adj[data].push_back(t);
        }
    }
}

void adjlist_dir_w(graphw adj[],int v)
{
    for(int i=0;i<v;i++)
    {
        // cout<<"enter the adjacent vertex and their weight of "<<i<<endl;
        while(1)
        {
            weight t;
            cin>>t.data>>t.wei;
            if(t.data==-1)break;
            adj[i].push_back(t);
        }
    }
}

void print_wlist(graphw adj[],int v)
{
    cout<<"the entered adjacency list is\n";
    for(int i=0;i<v;i++)
    {
        cout<<i<<"  ";
        for(int j=0;j<adj[i].size();j++)
        {
            cout<<" -> "<<adj[i][j].data<<" "<<adj[i][j].wei;
        }
        cout<<endl;
    }
}

void calc_ind(graph adj[],int v,int ind[])
{
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            if(j!=i){
            for(int k=0;k<adj[j].size();k++)
            {
                if(adj[j][k]==i)ind[adj[j][k]]++;
            }}
        }
    }
}

bool check(graph v,int a)
{
    for(int i=0;i<v.size();i++)
    {
        if(v[i]==a)return true;
    }
    return false;
}

void topo_sort(graph adj[],graph ve,int ind[],int v,int &k)
{
    if(ve.size()==v)
    {
        for(int i=0;i<v;i++)
        {
            cout<<ve[i]<<" ";
        }
        cout<<endl;
        return;
    }
    else
    {
        for(int i=0;i<v;i++)
        {
            if(ind[i]==0)
            {
                if(!check(ve,i))
                {
                    ve.push_back(i);
                    for(int j=0;j<adj[i].size();j++)
                    {
                        ind[adj[i][j]]--;
                    }
                    topo_sort(adj,ve,ind,v,k);
                    ve.pop_back();
                    for(int j=0;j<adj[i].size();j++)
                    {
                        ind[adj[i][j]]++;
                    }
                }
            }
        }
    }
}

void dfs_unwei(int s,graph adj[],bool vis[])
{
    if(!vis[s])
    {
        cout<<s<<" ";
        vis[s]=true;
        for(int i=0;i<adj[s].size();i++)
        {
            if(!vis[adj[s][i]])dfs_unwei(adj[s][i],adj,vis);
        }
    }
}

void dfs_wei(int s,graphw adj[],bool vis[])
{
    if(!vis[s])
    {
        cout<<s<<" ";
        vis[s]=true;
        for(int i=0;i<adj[s].size();i++)
        {
            if(!vis[adj[s][i].data])dfs_wei(adj[s][i].data,adj,vis);
        }
    }
}

void bfs_wei(int s,graphw g[],int v,bool vis[])
{
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        if(!vis[t])cout<<t<<" ";
        vis[t]=true;
        for(int i=0;i<g[t].size();i++)
        {
            if(!vis[g[t][i].data])q.push(g[t][i].data);
        }
    }
}

void bfs_unwei(int s,graph g[],int v,bool vis[])
{
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        if(!vis[t])cout<<t<<" ";
        vis[t]=true;
        for(int i=0;i<g[t].size();i++)
        {
            if(!vis[g[t][i]])q.push(g[t][i]);
        }
    }
}

void diju(int s,int d,graphw g[],int v)
{
    bool vis[v]={false};
    int prev[v];
    int dis[v];for(int i=0;i<v;i++)dis[i]=INT_MAX;
    queue<int> q;q.push(s);
    dis[s]=0;
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        if(!vis[t])
        {
            for(int i=0;i<g[t].size();i++)
            {
                if(dis[t]+g[t][i].wei<dis[g[t][i].data])
                {
                    dis[g[t][i].data]=dis[t]+g[t][i].wei;
                    prev[g[t][i].data]=t;
                }
            }
            vis[t]=true;
            for(int i=0;i<g[t].size();i++)
            {
                if(!vis[g[t][i].data])q.push(g[t][i].data);
            }
        }
    }
    cout<<"the shortest path is\n";
    while(1)
    {
        cout<<d<<" ";
        d=prev[d];
        if(d==s)break;
    }
    cout<<s<<endl;
}

void arr_and_dep(int s,graph g[],bool vis[],int arr[],int dep[],int &k)
{
    if(!vis[s])
    {
        arr[s]=k++;
        vis[s]=true;
        for(int i=0;i<g[s].size();i++)
        {
            if(!vis[g[s][i]])arr_and_dep(g[s][i],g,vis,arr,dep,k);
        }
        dep[s]=k++;
    }
}

int index(graph g[],int s,int x)
{
    for(int i=0;i<g[s].size();i++)
    {
        if(g[s][i]==x)return i;
    }
}

void euler_path(int s,graph g[],int v,int st)
{
    cout<<s<<" ";
    for(int i=0;i<g[s].size();i++)
    {
        int temp=g[s][i];
        int m1=index(g,g[s][i],s);
        g[g[s][i]].erase(g[g[s][i]].begin()+m1);
        g[s].erase(g[s].begin()+i);
        for(int k=0;k<g[s].size();k++)
        {
            int m2=index(g,g[s][k],s);
            g[g[s][k]].erase(g[g[s][k]].begin()+m2);
            g[g[s][k]].push_back(s);
        }
        for(int k=0;k<g[st].size();k++)
        {
            int m2=index(g,g[st][k],st);
            g[g[st][k]].erase(g[g[st][k]].begin()+m2);
            g[g[st][k]].push_back(st);
        }
        euler_path(temp,g,v,st);        
    }
}

// void eulere_path(int s, vector<int> g[],bool vis[],int v,int st)
// {
//     cout<<s<<" ";
//     for(int i=0;i<g[s].size();i++)
//     {
//         int temp=g[s][i];
//         int m1=index(g,g[s][i],s); 
//         g[g[s][i]].erase(g[g[s][i]].begin()+m1);
//         g[s].erase(g[s].begin()+i);  
//         for(int k=0;k<g[s].size();k++)
//         {
//             int m=index(g,g[s][k],s); 
//             g[g[s][k]].erase(g[g[s][k]].begin()+m);
//             g[g[s][k]].push_back(s);
//         }  
//         for(int k=0;k<g[st].size();k++)
//         {
//             int m=index(g,g[st][k],st); 
//             g[g[st][k]].erase(g[g[st][k]].begin()+m);
//             g[g[st][k]].push_back(st);
//         }        
//         eulere_path(temp,g,vis,v,st);
//     }

// }

int main()
{
    cout<<"enter v: ";
    int v;cin>>v;
    vector<int> adj_list[v];
    // graphw adj_list[v];
    adjlist_undir(adj_list,v);
    print_unwlist(adj_list,v);
    // int ind[v]={0};
    // calc_ind(adj_list,v,ind);
    // vector<int> ve;int i=0;
    // topo_sort(adj_list,ve,ind,v,i);
    // cout<<"enter the starting index for bfs: ";
    // int s;cin>>s;
    // bool vis[v]={false};
    // dfs_unwei(s,adj_list,vis);
    // bfs_wei(s,adj_list,v,vis);cout<<endl;
    // cout<<"enter s and d ";
    // int s,d;cin>>s>>d;
    // diju(s,d,adj_list,v);
    // bool vis[v]={false};
    // cout<<"enter the starting vertex : ";
    // int s;cin>>s;
    // int arr[v],dep[v];int l=0;
    // arr_and_dep(s,adj_list,vis,arr,dep,l);
    // for(int i=0;i<v;i++)
    // {
    //     if(!vis[i])arr_and_dep(i,adj_list,vis,arr,dep,l);
    // }
    // cout<<"the arrival time and departure time is given by\n";
    // for(int i=0;i<v;i++)
    // {
    //  cout<<arr[i]<<"  "<<dep[i]<<endl;
    // }
    // map<int,int> mp;
    // for(int i=0;i<v;i++)
    // {
    //     mp[dep[i]]=i;
    // }
    // for(auto i=mp.rbegin();i!=mp.rend();i++)
    // {
    //     cout<<i->second<<" ";
    // }cout<<endl;
    cout<<"enter s: ";
    int s;cin>>s;
    euler_path(s,adj_list,v,s);cout<<endl;
}
// 1 2 3 1 -1 -1
// 3 3 4 10 -1 -1
// 0 4 5 5 -1 -1
// 2 2 4 2 5 8 6 4 -1 -1
// 6 6 -1 -1
// -1 -1
// 5 1 -1 -1
