#include<bits/stdc++.h>
using namespace std;

struct node
{
	int value,list,index;
};

struct comp
{
	bool operator()(node lhs,node rhs)
	{
		return lhs.value>rhs.value;
	}
};

pair<int,int> range(vector<int> list[],int m)
{
	pair<int,int> p={0,INT_MAX};
	priority_queue<node,vector<node>,comp> pq;
	int high=INT_MIN;
	for(int i=0;i<m;i++)
	{
		pq.push({list[i][0],i,0});
		high=max(high,list[i][0]);
	}
	while(1)
	{
		int low=pq.top().value;
		int list_no=pq.top().list;
		int index_no=pq.top().index;
		pq.pop();
		if((high-low)<(p.second-p.first))
		{
			p={low,high};
		}
		if(index_no==list[list_no].size()-1)
		{
			return p;
		}
		pq.push({list[list_no][index_no+1],list_no,index_no+1});
		high=max(list[list_no][index_no+1],high);
	}
}

int main()
{
	cout<<"enter m: ";
	int m;cin>>m;
	vector<int> list[m];
	for(int i=0;i<m;i++)
	{
		cout<<"enter the "<<i+1<<" list\n";
		while(1)
		{
			int data;cin>>data;
			if(data==-1)break;
			list[i].push_back(data);
		}
	}
	cout<<"the entered list are\n";
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<list[i].size();j++)
		{
			cout<<list[i][j]<<" ";
		}
		cout<<endl;
	}
	pair<int,int> p=range(list,m);
	cout<<"the minimum range is "<<p.first<<" - "<<p.second<<endl;
}