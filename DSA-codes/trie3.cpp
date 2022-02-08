#include<bits/stdc++.h>
using namespace std;
struct trienode;
union u
{
	char str[30];
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
	for(int i=0;i<s.length();i++)temp->ptr.str[i]=s[i];
	return temp;
}

tptr creat_trie(tptr &t,int &i,string s)
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
			if(strlen(temp->ptr.str)==i)t->ptr.nolf[26]=temp;
			else t->ptr.nolf[temp->ptr.str[i]-'a']=temp;
		}
		if(s.length()==i)t->ptr.nolf[26]=creat_leaf(s);
		for(int j=i;j<s.length();j++)
		{
			t->ptr.nolf[s[j]-'a']=creat_trie(t->ptr.nolf[s[j]-'a'],++i,s);
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
			int i=0;
			while(t->ptr.str[i]!='\0')
			{
				cout<<t->ptr.str[i];
				i++;
			}
			cout<<" ";
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

bool search(tptr &t,int i,string s)
{
	if(t==NULL)return false;
	if(t->is_leaf){if(t->ptr.str==s)return true;else return false;}
	else return search(t->ptr.nolf[s[i]-'a'],i+1,s)||search(t->ptr.nolf[26],i,s);
}
int count(tptr &t)
{
	int cnt=0;
	for(int i=0;i<27;i++)
	{
		if(t->ptr.nolf[i]!=0)cnt++;
	}
	return cnt;
}
tptr index(tptr &t)
{
	int cnt=0;
	for(int i=0;i<27;i++)
	{
		if(t->ptr.nolf[i]!=0)return t->ptr.nolf[i];
	}
}

tptr delete_trie(tptr &t,tptr &root,int i,string s)
{
	if(t==NULL)return NULL;
	if(t->is_leaf){if(t->ptr.str==s)return NULL;else return t;}
	else{
		t->ptr.nolf[26]=delete_trie(t->ptr.nolf[26],root,i,s); 
		t->ptr.nolf[s[i]-'a']=delete_trie(t->ptr.nolf[s[i]-'a'],root,i+1,s);
	}
	if(t!=root&&count(t)==1){if(index(t)->is_leaf)return index(t);}
	return t;
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
		t=creat_trie(t,k,a[i]);
	}
	print(t);
	cout<<endl;
	cout<<"enter a string: ";
	string s;cin>>s;int ki=0;
	cout<<search(t,ki,s)<<endl;
	cout<<"enter a string to delete: ";
	string s1;cin>>s1;ki=0;
	t=delete_trie(t,t,ki,s1);
	print(t);cout<<endl;
}