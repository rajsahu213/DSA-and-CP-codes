#include <iostream>
using namespace std;
struct mlnode{
int data;
struct mlnode *dlink;
struct mlnode *next; 
};
typedef struct mlnode *LPTR;
void add_down(LPTR &h,int num)
{
if(num==0)
return;
else
{
h=new struct mlnode;
cin>>h->data;
h->next=NULL;
h->dlink=NULL;
add_down(h->dlink,num-1);
}
}
void add(LPTR &l,int x)
{
if(x==0)
return;
else
{
l=new struct mlnode;
char ch;
cin>>l->data;
cout<<"y for want a downlink n for not:";
cin>>ch;
if(ch=='n')
{
l->dlink=NULL;
l->next=NULL;
add(l->next,x-1);
}
else if(ch=='y')
{
int n;
cout<<"no of elements in downlink:";
cin>>n;
l->next=NULL;
l->dlink=NULL;
add_down(l->dlink,n);
add(l->next,x-1);
}
}
}
void flatten_end(LPTR &h,LPTR temp)
{
if(h->dlink==NULL)
{
h->dlink=temp;
}
else
{
flatten_end(h->dlink,temp);
}
}
void final(LPTR &l)
{
if(l==NULL)
return;
else
{
if(l->dlink!=NULL)
{
LPTR tmp=l->next;
l->next=NULL;
flatten_end(l->dlink,tmp);
final(l->next);
}
else
{
cout<<l->data<<endl;
final(l->next);
}

}
}
void print(LPTR &l)
{
if(l==NULL)
return;
else
{
if(l->dlink!=NULL)
{
cout<<l->data<<" ";
print(l->dlink);}
else
{
cout<<l->data<<" ";
print(l->next);
}
}
}
int main()
{
int z;
cin>>z;
LPTR l=NULL;
add(l,z);
final(l);
//cout<<"done"<<endl;
print(l);
}