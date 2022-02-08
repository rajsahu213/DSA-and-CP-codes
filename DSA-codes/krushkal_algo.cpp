#include<bits/stdc++.h>
using namespace std;

struct weight
{
    int data;
    int wei;
};

struct edge
{
    int x;
    int y;
    int w;
};

typedef vector<weight> graph;
typedef map<pair<int,int>,bool> maping;

void adjlist_undir_weight(int v,vector<weight> adj_list[],vector<edge> &e)
{
    for(int i=0;i<v;i++)
    {
        // cout<<"enter the adjacent vertex of "<<i<<" and its weight( -1 to stop )\n";
        while(1)
        {
            struct weight a;
            cin>>a.data>>a.wei;
            if(a.data==-1)break;
            struct edge temp;
            temp.x=i;temp.y=a.data;temp.w=a.wei;
            e.push_back(temp);
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
int find(int a[],int n)
{
    if(a[n]==-1)return n;
    else return find(a,a[n]);
}

void krushkal_algo(graph adj[],int v,vector<edge> &e)
{
    int edge_count=0,temp1,temp2;
    int set[v];for(int i=0;i<v;i++)set[i]=-1;
    int i=0,sum=0;
    while(edge_count<(v-1))
    {
        temp1=find(set,e[i].x);
        temp2=find(set,e[i].y);
        if(temp1!=temp2)
        {
            cout<<"v"<<e[i].x<<" -- v"<<e[i].y<<"  :  "<<e[i].w<<endl;
            set[e[i].y]=e[i].x;
            sum+=e[i].w;
            edge_count++;
        }
        i++;
    }
    cout<<sum<<endl;
}


bool operator1(edge lhs,edge rhs)
{
    return lhs.w>rhs.w;
}


int main()
{
    cout<<"enter v: ";
    int v;cin>>v;
    vector<weight> adj_list[v];
    vector<edge> e;
    adjlist_undir_weight(v,adj_list,e);
    print_adjlist_wei(adj_list,v);
    sort(e.begin(),e.end(),operator1);
    krushkal_algo(adj_list,v,e); 
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