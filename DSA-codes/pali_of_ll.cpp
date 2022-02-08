#include<bits/stdc++.h>
using namespace std;

struct lnode{
    int data;
    lnode *next;
};

struct lnode *l;

typedef struct lnode* lptr;

void insert_at_end(lptr &l,int x)
{
    lptr t;
    t= new (lnode);
    t->data=x;
    t->next=NULL;
    if(l==NULL)
    {
        l=t;
    }
    else{
        lptr t1;
        t1=l;
        while(t1->next!=NULL)
        {
            t1=t1->next;
        }
        t1->next=t;
    }
}

int is_pali(lptr &l)
{
    stack<int> s;
    lptr sp=l,fp=l;
    int count=0;
    while(fp!=NULL&&fp->next!=NULL)
    {
        s.push(sp->data);
        sp=sp->next;
        fp=fp->next->next;
        count++;
    }
    if(count%2!=0){sp=sp->next;}
    while(!s.empty()/*&&sp!=NULL*/)
    {
        if(s.top()!=sp->data)
        {
            return 1;
        }
        s.pop();
        sp=sp->next;
    }
}

int main()
{
    lptr l=NULL;
    cout<<"enter n: ";
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"enter a number: ";
        int data;cin>>data;
        insert_at_end(l,data);
    }
    int flag=is_pali(l);
    if(flag==1){cout<<"not a palindrome\n";}
    else cout<<"palindrome\n";
}