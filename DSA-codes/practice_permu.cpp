#include<bits/stdc++.h>
using namespace std;

bool check(vector<int> &v,int a)
{
	for(int i=0;i<v.size();i++)
	{
		if(v[i]==a)return true;
	}
	return false;
}

void permu(int s[],vector<int> &v,int n)
{
	if(n==v.size())
	{
		for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
		cout<<endl;
		return;
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			if(!check(v,s[i]))
			{
				v.push_back(s[i]);
				permu(s,v,n);
				v.pop_back();
			}
		}
	}
}

void pri(int n,vector<bstptr> &p,vector<int> &a,int &count)
{
  if(a.size() == n){
    for(int i=0;i<n;i++) cout << a[i] << " ";
    cout << endl;
		count++;
    return;
  }
  for(int i=0;i<p.size();i++)
	{
    bstptr t = p[i];
    p.erase(p.begin()+i);
    if(t->lchild) p.push_back(t->lchild);
    if(t->rchild) p.push_back(t->rchild);
    a.push_back(t->data);
    pri(n,p,a,count);
    a.pop_back();
    if(t->lchild) p.pop_back();
    if(t->rchild) p.pop_back();
    p.insert(p.begin()+i,t);
  }
}

int main()
{
	cout<<"enter n: ";
	int n;cin>>n;
	cout<<"enter the elements of the array\n";
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	vector<int> v;
	permu(a,v,n);
}