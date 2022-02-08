#include<iostream>
using namespace std;

struct node{
	int vertex;
	node *next;
};

node *g[20];
//heads  of linked list

int visited[20];
int n;

void read_graph();
//creat adjacency list

void insert(int ,int);
//insert an edge(vi,vj) in adjancency list

void dfs(int);

int main()
{
	int i;
	read_graph();
	//initialised visited to zero
	for(i=0;i<n;i++)
	{
		visited[i]=0;
	}
		dfs(0);
} 

void dfs(int i)
{
	node *p;
	cout<<i<<endl;
	p=g[i];
	visited[i]=1;
	while(p!=NULL)
	{
		i=p->vertex;
		if(!visited[i])
			dfs(i);
		p=p->next;
	}
}

void read_graph()
{
	int i,vi,vj,no_of_edges;
	cout<<"no of vertices: ";
	cin>>n;
	//initialise g[] with a null
	for(int i=0;i<n;i++)
	{
		g[i]=NULL;
	}
		//read edges and insert them in g[]
		cout<<"enter no of edges: ";
		cin>>no_of_edges;
		for(int i=0;i<no_of_edges;i++)
		{
			cout<<"enter an edge(u,v): ";
			cin>>vi>>vj;
			insert(vi,vj);
		}
	
}

void insert(int vi,int vj)
{
	node *p,*q;
	//acquire memory for the new node
	q=(node*)new(node);
	q->vertex=vj;
	q->next=NULL;
	//insert node in the linked list no vi
	if(g[vi]==NULL)
	{
		g[vi]=q;
	}
	else{
		//go to end of the linked list
		p=g[vi];
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=q;
	}
}