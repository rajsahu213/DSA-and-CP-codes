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

void sorting(graph adj_list[],int v)//sort according to the weight
{
    for(int i=0;i<v;i++)
    {
        int last; 
        for(int j=0;j<adj_list[i].size()-1;j++)
        {
            last=adj_list[i].size()-j-1;
            for(int k=0;k<last;k++)
            {
                if(adj_list[i][k+1].wei<adj_list[i][k].wei)
                {
                    swap(adj_list[i][k+1].wei,adj_list[i][k].wei);
                    swap(adj_list[i][k+1].data,adj_list[i][k].data);
                }
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
    adjlist_dir_weight(e,v,adj_list);
    print_adjlist_wei(adj_list,v);
    sorting(adj_list,v);
    
}

// 1 2 2 4 3 1 -1 -1
// 0 2 3 3 4 10 -1 -1
// 0 4 3 2 5 5 -1 -1
// 0 1 1 3 2 2 4 6 5 8 6 4 -1 -1
// 1 10 3 6 6 6 -1 -1
// 2 5 3 8 6 1 -1 -1
// 3 4 4 6 5 1 -1 -1