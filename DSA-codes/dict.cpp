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

string to_string(char x)
{
	string s(1,x);
	return s;
}

void remove(tptr &t)
{
	if(t!=NULL)
	{	
		if(t->is_leaf)
		{
			delete t;
		}
		else
		{
			for(int i=0;i<27;i++)
			{
				if(t->ka.ptr[i]!=NULL)
				{
					remove(t->ka.ptr[i]);
				}
			}
		}
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        tptr root=NULL;
        root=creat_nonleaf();
        // vector<string> contacts(n);
        for(int i=0;i<n;i++)
        {
        	string contacts;
            cin>>contacts;
            int data=0;
            root=creat_trie(root,data,contacts);   
        }
        string qry;
        cin>>qry;
        string s1;
        tptr t1=NULL;
        int l=qry.length();
        int idx=1;
        t1=root->ka.ptr[qry[0]-'a'];
        display(t1);
        cout<<endl;
        while(idx<l)
        {
            if(!t1) cout<<"0"<<endl;
            else if(!t1->is_leaf) 
            {
            	t1=t1->ka.ptr[qry[idx]-'a'];
            	if(t1){display(t1);cout<<endl;}
            	else cout<<"0"<<endl;
            }
            else if(t1->is_leaf)
            {
            	string s1="";
            	int i=0;
				while(t1->ka.array[i]!='\0')
				{
					s1=s1.append(to_string(t1->ka.array[i++]));
				}
                if(s1.substr(0,idx+1)==qry.substr(0,idx+1)) cout<<s1<<endl;
                else
                {
                    t1=NULL;
                    cout<<"0"<<endl;
                }
            }
            idx++;
        }
        remove(root);
        delete root;
    }
    return 0;
}
