#include<bits/stdc++.h>
using namespace std;

struct trienode;

union u{
	char array[30];
	struct trienode* ptr[27];
};

struct trienode
{
	bool is_leaf;
	union u ka;
};

typedef struct trienode* tptr;

tptr creat_nonleaf()
{
	tptr t=new trienode;
	t->is_leaf=false;
	for(int i=0;i<27;i++)
	{
		t->ka.ptr[i]=NULL;
	}
	return t;
}


tptr creat_leaf(string s)
{
	tptr t=new trienode;
	t->is_leaf=true;
	for(int i=0;i<s.length();i++)
	{
		t->ka.array[i]=s[i];
	}
	return t;
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
			t=creat_nonleaf();
			if(strlen(temp->ka.array)==i)t->ka.ptr[26]=temp;
			else t->ka.ptr[temp->ka.array[i]-'a']=temp;
		}
		if(i==s.length())t->ka.ptr[26]=creat_leaf(s);
		for(int j=i;j<s.length();j++)
		{
			t->ka.ptr[s[j]-'a']=creat_trie(t->ka.ptr[s[j]-'a'],++i,s);
			break;
		}
	}
	return t;
}

void display(tptr &t)
{
	if(t!=NULL)
	{
		if(t->is_leaf)
		{
			int i=0;
			while(t->ka.array[i]!='\0')
			{
				cout<<t->ka.array[i++];
			}
			cout<<" ";
		}
		else{
			display(t->ka.ptr[26]);
			for(int i=0;i<26;i++)
			{
				display(t->ka.ptr[i]);
			}
		}
	}
}

int count(tptr &t)
{
	int cnt =0;
	for(int i=0;i<27;i++)
	{
		if(t->ka.ptr[i]!=NULL)cnt++;
	}
	return cnt;
}

tptr index(tptr &t)
{
	for(int i=0;i<27;i++)
	{
		if(t->ka.ptr[i]!=NULL)return t->ka.ptr[i];
	}
}

tptr delete_trie(tptr &t,tptr &root,int i,string s)
{
	if(t==NULL)return NULL;
	else if(t->is_leaf)
	{
		if(t->ka.array==s)return NULL;
		else return t;
	}
	else
	{
		if(i==s.length())t->ka.ptr[26]=delete_trie(t->ka.ptr[26],t,i,s);
		else t->ka.ptr[s[i]-'a']=delete_trie(t->ka.ptr[s[i]-'a'],t,i+1,s);
	}
	if(t!=root && count(t)==1)
	{
		if(index(t)->is_leaf)return index(t);
	}
	return t;
}

int main()
{
	int n;cin>>n;
	tptr t=creat_nonleaf();
	for(int i=0;i<n;i++)
	{
		string data;cin>>data;int j=0;
		t=creat_trie(t,j,data);
	}
	display(t);
	cout<<endl;
}