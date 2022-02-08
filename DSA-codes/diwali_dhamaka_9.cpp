#include<bits/stdc++.h>
using namespace std;
float oper(float a,char c,float b)
{
	switch(c)
	{
		case '+':return a+b;
		case '-':return a-b;
		case '*':return a*b;
		case '/':return a/b;
	}
}
float eval(int s,vector<int> adj[],char a[])
{
	if(adj[s].size()==0)return a[s]-'0';
	else return oper(eval(adj[s][0],adj,a),a[s],eval(adj[s][1],adj,a));
}
int main()
{
	vector<int> v[8];
	v[0].push_back(1);v[0].push_back(2);
	v[1].push_back(3);v[1].push_back(4);
	v[2].push_back(4);v[2].push_back(5);
	v[4].push_back(6);v[4].push_back(7);
	char vert[8]={'+','+','/','2','*','5','3','4'};
	cout<<eval(0,v,vert)<<endl;
}