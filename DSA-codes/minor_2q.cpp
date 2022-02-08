#include<iostream>
#include<stack>
#include<queue>
#include<climits>
#include<cstring>
using namespace std;

struct bstnode
{
    int data;
    bstnode *lchild;
    bstnode *rchild;
};

typedef struct bstnode* bstptr;

void insert(bstptr &t,int data)
{
    if(t==NULL)
    {
        bstptr temp;
        temp=new(bstnode);
        temp->data=data;
        temp->lchild=temp->rchild=NULL;
        t=temp;
    }
    else
    {
        if(data<t->data)
        {
            insert(t->lchild,data);
        }
        else{
            insert(t->rchild,data);
        }
    }
}

void score(string a)
{
    stack<char> s;
    int l=a.length(),scr=0;
    int i=0;
    while(i<l)
    {
        if(a[i]=='('&&a[i+1]!=')')
        {
            s.push(a[i]);
            i++;
        }
        else if(a[i]=='('&&a[i+1]==')')
        {
            i=i+2;
            if(a[i]==')'){scr+=2;s.pop();}
            else scr+=1;
        }
        else if(a[i]==')'&&!s.empty())
        {
            scr=scr*2;
            i++;
            s.pop();
        }
        else i++;
    }
    cout<<scr<<endl;
}

int main()
{
    cout<<"enter a string: ";
    string s;cin>>s;
    score(s);
}