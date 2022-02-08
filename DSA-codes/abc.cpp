#include<bits/stdc++.h>
using namespace std;

struct gtnode
{
	char data;
	int cnt;
    int max;
	gtnode* cptr[50]; 
};

typedef struct gtnode* gtptr;

int main()
{
	gtptr t=NULL;
	cout<<"hi\n";
	cout<<t->data<<endl;
}