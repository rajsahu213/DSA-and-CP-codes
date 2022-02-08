#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Node
{
  ll value, list_num, index;
};


struct comp
{
    bool operator()(Node lhs,Node rhs) 
    {
       return lhs.value > rhs.value;
    }
};


pair<ll,ll> range(vector<ll> list[],ll M)
{
  ll high = LLONG_MIN;
  pair<ll,ll> p = { 0, LLONG_MAX };
  priority_queue<Node, vector<Node>,comp> pq;
  for (ll i = 0; i < M; i++)
  {
    pq.push({list[i][0], i, 0});
    high = max(high, list[i][0]);
  }
  for (;;)
  {
    ll low = pq.top().value;
    ll i = pq.top().list_num;
    ll j = pq.top().index;
    pq.pop();
    if (high - low < p.second - p.first) 
    {
      p = {low, high};
    }
    if (j == list[i].size() - 1) 
    {
      return p;
    }
    pq.push({list[i][j + 1], i, j + 1});
    high = max(high, list[i][j + 1]);
  }
}

int main() 
{
  ll t;cin>>t;
  while(t--)
  {
      ll n,m;
      cin>>n>>m;
      vector<ll> list[m];
      for(ll i=0;i<n;i++)
      {
          ll data;cin>>data;
          list[i%m].push_back(data);
      }
      for(ll i=0;i<m;i++)
      {
          sort(list[i].begin(),list[i].end());
          for(int j=0;j<list[i].size();j++)
          {
            cout<<list[i][j]<<" ";
          }
          cout<<endl;
      }
      pair<ll,ll> p =range(list,m);
      cout<<"the minimum range is "<<p.first<<" - "<<p.second<<endl;
  }
  return 0;
}


