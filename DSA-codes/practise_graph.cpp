#include<bits/stdc++.h>
using namespace std;
struct vertex;
struct edge
{
	struct vertex* vert;
	struct edge* next_edge;
};

struct vertex
{
	char data;
	struct vertex* down;
	struct edge* next;
};

typedef struct vertex* vptr;
typedef struct edge* eptr;

vptr creat_vertex(char a)
{
	vptr temp;
	temp=new vertex;
	temp->data=a;
	temp->down=NULL;
	temp->next=NULL;
	return temp;
}

eptr creat_edge()
{
	eptr temp;
	temp=new edge;
	temp->vert=NULL;
	temp->next_edge=NULL;
	return temp;
}

vptr insert_vertex(vptr &v,char data)
{
	if(v==NULL)
	{
		v=creat_vertex(data);
	}
	else 
	{
		v->down=insert_vertex(v->down,data);
	}
	return v;
}

eptr insert_edge(eptr &e)
{
	if(e==NULL)
	{
		e=creat_edge();
	}
	else 
	{
		e->next_edge=insert_edge(e->next_edge);
	}
	return e;
}

void creat_graph(vptr &v,int n)
{
	vptr t=v;
	char temp='a';
	for(int i=0;i<n;i++)
	{
		// cout<<"enter the adjacent vertex of "<<temp<<" (# to stop)\n";
		int k=0;
		while(1)
		{
			char a;cin>>a;
			if(a=='#')break;
			t->next=insert_edge(t->next);
			eptr l=t->next;
			for(int j=0;j<k;j++)
			{
				l=l->next_edge;
			}
			vptr t1=v;
			for(int j=0;j<a-'a';j++)
			{
				t1=t1->down;
			}
			l->vert=t1;
			k++;
		}
		temp++;
		t=t->down;
	}
}

// void dfs(char s,vptr &v,bool vis[])
// {
//     if(!vis[s-'a'])
//     {
//         cout<<s<<" ";
//         vis[s-'a']=true;
//         eptr t1=v->next;
//         while(t1!=NULL)
//         {
//             dfs(t1->vert->data,t1->vert,vis);
//             t1=t1->next_edge;
//         }
//     }
// }

void dfs(char s,vptr &v,bool vis[])
{
	if(!vis[s-'a'])
	{
		cout<<s<<" ";
		vis[s-'a']=true;
		eptr e=v->next;
		while(e!=NULL)
		{
			dfs(e->vert->data,e->vert,vis);
			e=e->next_edge;
		}
	}
}

int main()
{
	cout<<"enter v: ";
	int n;cin>>n;
	vptr v=NULL;char temp='a';
	for(int i=0;i<n;i++)
	{
		v=insert_vertex(v,temp);
		temp++;
	}
	creat_graph(v,n);
	bool vis[n]={false};
	dfs(v->data,v,vis);
	cout<<endl;
}