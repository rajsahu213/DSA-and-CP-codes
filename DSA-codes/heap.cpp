#include<bits/stdc++.h>
using namespace std;

struct btnode{
    int data;
    btnode* lchild;
    btnode* rchild;
};

typedef struct btnode* btptr;

btptr creatnode(int a)
{
    btptr temp;
    temp=new(btnode);
    temp->data=a;
    temp->lchild=temp->rchild=NULL;
    return temp;
}

void creat_bt_from_level_order(btptr &t,int a[],int i,int n)
{
    if(i<n)
    {
        t=creatnode(a[i]);
        creat_bt_from_level_order(t->lchild,a,2*i+1,n);
        creat_bt_from_level_order(t->rchild,a,2*i+2,n);
    }
}

void insert_heap(int h[],int &n,int x)
{
	int i=n;
	h[n]=x;
	while((i-1)/2>=0)
	{
		if(h[(i-1)/2]>h[i]){int temp=h[i];h[i]=h[(i-1)/2];h[(i-1)/2]=temp;i=(i-1)/2;}
		else break;
	}
	n++;
}

int get_index(int a[],int n,int x)
{
	for(int i=0;i<n;i++)
	{
		if(a[i]==x)return i;
	}
	return -1;
}

void delete_num(int h[],int &n,int x)
{
	int i=get_index(h,n,x);
	h[i]=h[n-1];n=n-1;
	int temp;
	while(n>=(2*i+1))
	{
		if(n==(2*i+1))
		{
			if(h[2*i+1]<h[i]){temp=h[i];h[i]=h[2*i+1];h[2*i+1]=temp;break;}
			else break;
		}
		else if(h[2*i+1]<h[i]&&h[2*i+2]>h[i])
		{
			temp=h[i];h[i]=h[2*i+1];h[2*i+1]=temp;i=2*i+1;
		}
		else if(h[2*i+1]>h[i]&&h[2*i+2]<h[i])
		{
			temp=h[i];h[i]=h[2*i+2];h[2*i+2]=temp;i=2*i+2;
		}		
		else if(h[2*i+1]<h[i]&&h[2*i+2]<h[i])
		{
			if(h[2*i+1]<h[2*i+2]){temp=h[i];h[i]=h[2*i+1];h[2*i+1]=temp;i=2*i+1;}
			else {temp=h[i];h[i]=h[2*i+2];h[2*i+2]=temp;i=2*i+2;}
		}		
		else break;
	}
}

void heap_sort(int h[],int a[],int n)
{
	int n1=n;
	for(int i=0;i<n;i++)
	{
		a[i]=h[0];
		delete_num(h,n1,h[0]);
	}
	int temp=a[n-2];a[n-2]=a[n-1];a[n-1]=temp;
}

int no_of_nodes1(btptr &t,int &count)
{
    if(t!=NULL)
    {
        count++;
        no_of_nodes1(t->lchild,count);
        no_of_nodes1(t->rchild,count);
    }
}

int no_of_nodes(btptr &t)
{
    int count=0;
    no_of_nodes1(t,count);
    return count;
}

int check_com_bt(btptr &t)
{
    if(t==NULL)return 1;
    if(no_of_nodes(t->lchild)<no_of_nodes(t->rchild))return 0;
    return check_com_bt(t->lchild);
}

int check(btptr &t)
{
	if(t->rchild==NULL&&t->lchild)return 1;
	if(t->lchild==NULL&&t->rchild!=NULL)return 0;
	else if(t->lchild!=NULL&&t->rchild==NULL)
	{
		if(t->lchild->data>t->data)return 1;
		else return 0;
	}
	else
	{
		if(t->rchild->data>t->data&&t->lchild->data>t->data)return 1;
		else return 0;
	}
	return check(t->lchild)*check(t->rchild);
}

int main()
{
	int size;
	cout<<"enter the size of the heap: ";
	cin>>size;
	int h[100];
	cout<<"enter the numbers\n";
	for(int i=0;i<size;i++)cin>>h[i];
	cout<<"the entered array is\n";
	int j=1;
	for(int i=0;i<size;i++)
	{
		if(i==(pow(2,j)-1)){cout<<endl;j++;}
		cout<<h[i]<<" ";		
	}
	cout<<endl;
	// int h[100];
	// int siz=0;
	// cout<<"the converted heap is\n";
	// for(int i=0;i<size;i++)
	// {
	// 	insert_heap(h,siz,a[i]);
	// }
	// j=1;
	// for(int i=0;i<size;i++)
	// {
	// 	if(i==(pow(2,j)-1)){cout<<endl;j++;}
	// 	cout<<h[i]<<" ";		
	// }
	// cout<<endl;
	// cout<<"enter the number you want to insert: ";
	// int num;cin>>num;
	// insert_heap(h,size,num);
	// cout<<"the resulting heap is\n";
	// j=1;
	// for(int i=0;i<size;i++)
	// {
	// 	if(i==(pow(2,j)-1)){cout<<endl;j++;}
	// 	cout<<h[i]<<" ";		
	// }
	// cout<<endl;	
	// cout<<"enter the number you want to delete: ";
	// int x;cin>>x;
	// delete_num(h,size,x);
	// cout<<"the resulting heap is\n";
	// j=1;
	// for(int i=0;i<size;i++)
	// {
	// 	if(i==(pow(2,j)-1)){cout<<endl;j++;}
	// 	cout<<h[i]<<" ";		
	// }
	// cout<<endl;		
	// cout<<"the sorted array is\n";
	// int a[size];
	// heap_sort(h,a,size);
	// for(int i=0;i<size;i++){cout<<a[i]<<" ";}
	// cout<<endl;
	// btptr t=NULL;
	// int l=0;
	// creat_bt_from_level_order(t,h,l,size);
	// if(check_com_bt(t)&&check(t))cout<<"the tree is heap\n";
	// else cout<<"not heap\n";
}


#include<bits/stdc++.h>
using namespace std;

struct node{
    int fre;
    char ch;
    node* lchild;
    node* rchild;
    node(int f,char c){
        fre=f;
        ch=c;
        lchild=rchild=NULL;
    }
};

typedef node* btptr;

class comp
{ 
public: 
    int operator() (const btptr& p1, const btptr& p2) 
    { 
        return p1->fre > p2->fre; 
    } 
}; 

void encoding(btptr &t,vector<int> code){
    if(t==NULL)return;
    if(t->lchild==NULL && t->rchild==NULL){
        for(int i=0;i<code.size();i++){
            cout<<code[i];
        }
        cout<<" ";
    }else{
        code.push_back(0);
        encoding(t->lchild,code);
        code.pop_back();
        code.push_back(1);
        encoding(t->rchild,code);
    }
}

int main(){
    int t;cin>>t;
    while(t--){
        string s;cin>>s;
        vector<int> f(s.length());
        for(int i=0;i<s.length();i++){
            cin>>f[i];
        }
        priority_queue<btptr,vector<btptr>,comp> q;
        for(int i=0;i<s.length();i++){
            btptr temp=new node(f[i],s[i]);
            q.push(temp);
        }
        while(q.size()>1){
            btptr temp1=q.top();q.pop();
            btptr temp2=q.top();q.pop();
            btptr temp=new node(temp1->fre+temp2->fre,'#');
            temp->lchild=temp1;
            temp->rchild=temp2;
            q.push(temp);
        }
        btptr root=q.top();
        vector<int> code;
        encoding(root,code);
        cout<<"\n";
    }
}