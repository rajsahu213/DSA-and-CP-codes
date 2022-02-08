#include<bits/stdc++.h>
using namespace std;

void push(priority_queue<int> pq1,priority_queue<int> pq2,int data,int &temp)
{
	temp=data;
	pq1.push(data);
}

int pop(priority_queue<int> &pq1,priority_queue<int> &pq2,int &temp)
{
	// while(!pq1.empty())
	// {
	// 	if(pq1.top()!=temp)
	// 	{
	// 		pq2.push(pq1.top());
	// 		pq1.pop();
	// 	}
	// 	else
	// 	{
	// 		temp=pq1.top();
	// 		pq1.pop();
	// 	}
	// }
	// while(!pq2.empty())
	// {
	// 	pq1.push(pq2.top());
	// 	pq2.pop();
	// }
	// int ans=temp;
	// temp=pq1.top();
	int ans=pq1.top();
	// pq1.pop();
	return ans;
}

int main()
{
	priority_queue<int> pq1,pq2;
	int temp;
	while(1)
	{
		int data;cin>>data;
		if(data==-1)break;
		push(pq1,pq2,data,temp);
	}
	for(int i=0;i<1;i++)
	{
		cout<<pop(pq1,pq2,temp)<<endl;
	}
}