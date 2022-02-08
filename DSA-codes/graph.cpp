#include<iostream>
using namespace std;

struct node{
	int data;
	node *next;
};

void read_graph(node *ad[],int no_of_nodes)
{
	node *new_node;
	int i,j,k,val;
	for(int i=0;i<no_of_nodes;i++)
	{
		node *last=NULL;
		cout<<"enter the numbers of neighbour of "<<i+1<<endl;
		cin>>k;
		for(int j=0;j<k;j++)
		{
			cout<<"enter the value of "<<j+1<<" neighbour of "<<i+1<<endl;
			cin>>val;
			new_node=(node*)new(node);
			new_node->data=val;
			new_node->next=NULL;
			if(ad[i]==NULL)
			{
				ad[i]=new_node;
			}
			else{
				last->next=new_node;
			}
			last=new_node;
		}
	}
}

void print_graph(node *ad[],int no_of_nodes)
{
	node *ptr=NULL;
	int i,j;
	for(int i=0;i<no_of_nodes;i++)
	{
		ptr=ad[i];
		cout<<"the neighbours of "<<i+1<<" are: ";
		while(ptr!=NULL)
		{
			cout<<ptr->data<<"  ";
			ptr=ptr->next;
		}
		cout<<endl;
	}
}

int main()
{
	int i,j,k,nodes;
	cout<<"enter node: ";
	cin>>nodes;
	node *adj[nodes];
	for(int i=0;i<nodes;i++)
	{
		adj[i]=NULL;
	}
	read_graph(adj,nodes);
	print_graph(adj,nodes);
	return 0;
}

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