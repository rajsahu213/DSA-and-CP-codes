#include<bits/stdc++.h>
using namespace std;
struct trienode;
union u
{
	char* str;
	struct trienode* nolf[27];
};

struct trienode
{
	bool is_leaf;
	union u ptr;
};
typedef struct trienode* tptr;

tptr creat_noleaf()
{
	tptr temp;
	temp=new trienode;
	temp->is_leaf=false;
	for(char i=0;i<=26;i++)
	{
		temp->ptr.nolf[i]=NULL;
	}
	return temp;
}

tptr creat_leaf(string s)
{
	tptr temp;
	temp=new trienode;
	temp->is_leaf=true;
	char a[s.length()];
	for(int i=0;i<s.length();i++)a[i]=s[i];
	temp->ptr.str=a;
	return temp;
}

tptr creat_trie(tptr &t,tptr &pptr,int &i,string s,int in)
{
	if(t==NULL)
	{
		t=creat_leaf(s);
	}
	else
	{
		if(t->is_leaf)
		{
			tptr temp=t;
			t=creat_noleaf();
			pptr->ptr.nolf[in]=t;
			t->ptr.nolf[*(temp->ptr.str+i)-'a']=temp;
		}
		for(int j=i;j<s.length();j++)
		{
			t->ptr.nolf[s[j]-'a']=creat_trie(t->ptr.nolf[s[j]-'a'],t,++i,s,s[j]-'a');
			break;
		}
	}
	return t;
}
void print(tptr &t)
{
	if(t!=NULL)
	{
		if(t->is_leaf)
		{
			// while( *t->ptr.str != '\0')
  	// 		{
   //  			cout << *t->ptr.str;
   //  			t->ptr.str++;
			// }
			// cout<<" ";
			puts(t->ptr.str);
		}
		else
		{
			for(int i=0;i<27;i++)
			{
				print(t->ptr.nolf[i]);
			}
		}
	}
}


int main()
{
	tptr t=creat_noleaf();
	cout<<"enter n: ";
	int n;cin>>n;
	string a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		int k=0;
		tptr t1=NULL;
		t=creat_trie(t,t1,k,a[i],k-1);
	}
	print(t);
	cout<<endl;
}