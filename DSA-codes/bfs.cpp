#include<iostream>
using namespace std;

int a[20][20],q[20],visited[20],n,i,j,f=0,r=-1;

void bfs(int v)
{
	for(i=1;i<=n;i++)
	{
		if(a[v][i]&&!visited[i])
		{
			q[++r]=i;
		}
		if(f<=r)
		{
			visited[q[f]]=1;
			bfs(q[f++]);
		}
	}
}

int main()
{
	int v;
	cout<<"enter number of vertices: ";
	cin>>n;
	for(i=1;i<=n;i++)
	{
		q[i]=0;
		visited[i]=0;
	}
	cout<<"enter graph data in matrix form: ";
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	cout<<"enter the starting vertex: ";
	cin>>v;
	bfs(v);
	cout<<"the node which are reachable are: ";
	for(int i=1;i<=n;i++)
	{
		if(visited[i])
		{
			cout<<i<<endl;
		}
		else{
			cout<<"\n"<<"bfs is not possible for "<<i<<"\n";
		}
	}
}