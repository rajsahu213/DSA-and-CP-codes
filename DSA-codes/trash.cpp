for(ll i=0; i<q; i++){
    ll left = queries[i].first.first;
    ll right = queries[i].first.second;
    while(currLeft > left) {
        currLeft--;
        ll currentNode = MO[currLeft];
        if(visited[currentNode]){
            for(ll x: bigPrime[currentNode]){
                value=mul(value,modInverse[final[x]+1]);
                final[x]--;
                value=mul(value,add(final[x],1));
            }
            visited[currentNode] = false;
        }
        else {
            for(ll x: bigPrime[currentNode]){
                value=mul(value,modInverse[final[x]+1]);
                final[x]++;
                value=mul(value,add(final[x],1));
            }
            visited[currentNode] = true;
        }
    }
    while(currRight < right) {
        currRight++;
        ll currentNode = MO[currRight];
        if(visited[currentNode]){
            for(ll x: bigPrime[currentNode]){
                value=mul(value,modInverse[final[x]+1]);
                final[x]--;
                value=mul(value,add(final[x],1));
            }
            visited[currentNode] = false;
        }
        else {
            for(ll x: bigPrime[currentNode]){
                value=mul(value,modInverse[final[x]+1]);
                final[x]++;
                value=mul(value,add(final[x],1));
            }
            visited[currentNode] = true;
        }
    }
    while(currLeft < left) {
        ll currentNode = MO[currLeft];
        if(visited[currentNode]){
            for(ll x: bigPrime[currentNode]){
                value=mul(value,modInverse[final[x]+1]);
                final[x]--;
                value=mul(value,add(final[x],1));
            }
            visited[currentNode] = false;
        }
        else{
            for(ll x: bigPrime[currentNode]){
                value=mul(value,modInverse[final[x]+1]);
                final[x]++;
                value=mul(value,add(final[x],1));
            }
            visited[currentNode] = true;
        }
        currLeft++;
    }
    while(currRight > right) {
        ll currentNode = MO[currRight];
        if(visited[currentNode]){
            for(ll x: bigPrime[currentNode]){
                value=mul(value,modInverse[final[x]+1]);
                final[x]--;
                value=mul(value,add(final[x],1));
            }
            visited[currentNode] = false;
        }
        else{
            for(ll x: bigPrime[currentNode]){
                value=mul(value,modInverse[final[x]+1]);
                final[x]++;
                value=mul(value,add(final[x],1));
            }
            visited[currentNode] = true;
        }
        currRight--;
    }

    if(queries[i].second.first != 0){
        for(ll x: bigPrime[queries[i].second.first]){
            value=mul(value,modInverse[final[x]+1]);
            final[x]++;
            value=mul(value,add(final[x],1));
        }
        
    }
    ans[queries[i].second.second] = mul(ans[queries[i].second.second],value);
    if(queries[i].second.first != 0){
        for(ll x: bigPrime[queries[i].second.first]){
            value=mul(value,modInverse[final[x]+1]);
            final[x]--;
            value=mul(value,add(final[x],1));
        }
    }
}


vector<pair<ll,ll>> smallPrime[N];

void seperate(vl &a,ll n){
    for(ll i=1;i<=n;i++){
        for(ll j=0;j<factors[a[i]].size();j++){
            if(factors[a[i]][j].first<100){
                smallPrime[i].pb(factors[a[i]][j]);
            }else{
                bigPrime[i].pb(factors[a[i]][j].first);
            }
        }
    }
}

vector<pair<ll,ll>> updateChild(vector<pair<ll,ll>> &childs_data,vector<pair<ll,ll>> &parents_data)
{
    unordered_map<ll,ll> mp;
    for(ll i=0;i<childs_data.size();i++){
        mp[childs_data[i].first]=add(mp[childs_data[i].first],childs_data[i].second);
    }
    for(ll i=0;i<parents_data.size();i++){
        mp[parents_data[i].first]=add(mp[parents_data[i].first],parents_data[i].second);
    }
    vector<pair<ll,ll>> new_data;
    for(auto i=mp.begin();i!=mp.end();i++){
        new_data.push_back({i->first,i->second});
    }
    return new_data;
}

void BFS(ll root,vector<point> node_data[],ll n)
{
    queue<ll> q;
    vector<bool> vis(n+1);
    vector<ll> p(n+1);
    q.push(root);
    vis[root]=true;
    p[root]=-1;
    while(!q.empty())
    {
        ll temp=q.front();q.pop();
        ll child=temp;
        ll parent=p[temp];
        if(parent!=-1)
        {
            vector<pair<ll,ll>> new_data=
            updateChild(node_data[child],node_data[parent]);
            node_data[child]=new_data;
        }
        for(ll u:graph[child])
        {
            if(!vis[u]){
                vis[u]=true;
                q.push(u);
                p[u]=temp;
            }
        }
    }
}