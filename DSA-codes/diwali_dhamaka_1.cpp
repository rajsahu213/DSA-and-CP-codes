#include<bits/stdc++.h>
using namespace std;
struct edge;
struct vertex
{
	char data;
	struct vertex* down;
	struct edge* next;
};

struct edge
{
	struct edge* next_edge;
	struct vertex* vert;
};

typedef struct vertex* vptr;
typedef struct edge* eptr;

vptr creat_vertex(char data)
{
	vptr temp;
	temp=new vertex;
	temp->data=data;
	temp->down=NULL;
	temp->next=NULL;
	return temp;
}

eptr creat_edge()
{
	eptr temp;
	temp=new edge;
	temp->next_edge=NULL;
	temp->vert=NULL;
	return temp;
}

vptr insert_vertex(vptr &v,char data)
{
	if(v==NULL)v=creat_vertex(data);
	else v->down=insert_vertex(v->down,data);
	return v;
}

eptr insert_edge(eptr &e)
{
	if(e==NULL)e=creat_edge();
	else e->next_edge=insert_edge(e->next_edge);
	return e;
}

void creat_adj_list(vptr &v,int n)
{
	vptr t=v;
	while(t!=NULL)
	{
		// cout<<"enter the number of adj vertex of "<<t->data<<" : ";
		int m;cin>>m;
		// cout<<"enter the vertexes\n";
		if(m>0)
		{
			t->next=insert_edge(t->next);
			vptr g1=v;
			char ch1;cin>>ch1;
			for(int i=0;i<ch1-'a';i++)
			{
				g1=g1->down;
			}
			t->next->vert=g1;
		}
		eptr h=t->next;
		for(int j=1;j<m;j++)
		{
			vptr g=v;
			h->next_edge=insert_edge(h->next_edge);
			char ch;cin>>ch;
			for(int c=0;c<ch-'a';c++)
			{
				g=g->down;
			}
			h->next_edge->vert=g;
			h=h->next_edge;
		}
		t=t->down;
	}
}

void dfs(char s,vptr &v,bool vis[])
{
    if(!vis[s-'a'])
    {
        cout<<s<<" ";
        vis[s-'a']=true;
        eptr t1=v->next;
        while(t1!=NULL)
        {
            dfs(t1->vert->data,t1->vert,vis);
            t1=t1->next_edge;
        }
    }
}

int main()
{
	cout<<"entre n: ";
	int n;cin>>n;
	vptr v=NULL;char ch='a';
	for(int i=0;i<n;i++)
	{
		v=insert_vertex(v,ch);
		ch++;
	}
	creat_adj_list(v,n);
	bool vis[n]={false};
	dfs(v->data,v,vis);
	cout<<endl;
}

// 3
// b c d 
// 1
// c
// 1
// e
// 2
// c e 
// 0