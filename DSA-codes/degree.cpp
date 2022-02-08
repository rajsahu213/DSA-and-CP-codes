#include<bits/stdc++.h>
using namespace std;

typedef vector<int> graph;

void adjlist_undir(int e,int v,vector<int> adj_list[])
{
    for(int i=0;i<v;i++)
    {
        cout<<"enter the adjacent vertex of "<<i<<" ( -1 to stop )\n";
        while(1)
        {
            int n;cin>>n;
            if(n==-1)break;
            adj_list[i].push_back(n);
            adj_list[n].push_back(i);
        }
    }
}

void adjlist_dir(int e,int v,vector<int> adj_list[])
{
    for(int i=0;i<v;i++)
    {
        cout<<"enter the adjacent vertex of "<<i<<" ( -1 to stop )\n";
        while(1)
        {
            int n;cin>>n;
            if(n==-1)break;
            adj_list[i].push_back(n);
        }
    }
}

int indegree(graph adj_list[],int v,int n)
{
    int count=0;
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<adj_list[i].size();j++)
        {
            if(adj_list[i][j]==n)count++;
        }
    }
    return count;
}

int no_of_edges_undir(graph adj_list[],int v)
{
    int sum=0;
    for(int i=0;i<v;i++)
    {
        sum+=adj_list[i].size();
    }
    return sum/2;
}

int no_of_edges_dir(graph adj_list[],int v)
{
    int sum=0;
    for(int i=0;i<v;i++)
    {
        sum+=adj_list[i].size();
    }
    return sum;
}

int main()
{
    cout<<"enter v: ";
    int v;cin>>v;
    vector<int> adj_list[v];
    cout<<"enter e: ";
    int e;cin>>e;
    adjlist_dir(e,v,adj_list);
    cout<<"the adjacency list is\n";
    for(int i=0;i<v;i++)
    {
        cout<<i;
        for(int j=0;j<adj_list[i].size();j++)
        {
            cout<<"-> "<<adj_list[i][j];
        }
        cout<<endl;
    }
    cout<<"enter the vertex to find its degree: ";
    int n;cin>>n;
    //for undirected
    // cout<<"the degree of "<<n<<" is : "<<adj_list[n].size()<<endl;
    // for directed
    cout<<"the out degree of "<<n<<" is : "<<adj_list[n].size()<<endl;
    cout<<"the in degree of "<<n<<" is : "<<indegree(adj_list,v,n)<<endl;
    //NO OF EDGES IN UNDIRECTED GRAPH
    // cout<<"no of edges in UNDIRECTED GRAPH is: "<<no_of_edges_undir(adj_list,v)<<endl;
    cout<<"no of edges in DIRECTED GRAPH is: "<<no_of_edges_dir(adj_list,v)<<endl;
}