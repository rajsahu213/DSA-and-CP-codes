bool iscyclic_directed(int V, vector<int> adj[])
{
    bool vis[V]={false};
    for(int i=0;i<V;i++)
    {
        if(vis[i]==false)
        {
            queue<int> q;
            q.push(i);
            int flag=0;
            while(!q.empty())
            {
                int t1=q.front();
                q.pop();
                if(flag==1&&t1==i||flag==1&&vis[t1]==true)return true;
                vis[t1]=true;
                flag=1;
                for(int j=0;j<adj[t1].size();j++)
                {
                    q.push(adj[t1][j]);
                }
            }
        }
    }
    return false;
}