#include<iostream>
#include<queue>
using namespace std;

struct bstnode{
	char data;
	int pri;
	bstnode *lchild;
	bstnode *rchild;
};

typedef struct bstnode* bstptr;

bstptr creatnode(char data,int a)
{
	bstptr temp;
	temp=new bstnode;
	temp->data=data;
	temp->pri=a;
	temp->lchild=temp->rchild=NULL;
	return temp;
}

bstptr insert(bstptr &t,char data,int pri)
{
	if(t==NULL)
	{
		t=creatnode(data,pri);
	}
	else if(int(data)<int(t->data))
	{
		t->lchild=insert(t->lchild,data,pri);
	}
	else t->rchild=insert(t->rchild,data,pri);
	return t;
}

bstptr heapify(bstptr &t,char a)
{
	if(t->data<a)
	{
		heapify(t->rchild,a);
	}
	else if(t->data>a)
	{
		heapify(t->lchild,a);
	}
	if(t->lchild!=NULL&&t->lchild->pri>t->pri)
	{
		bstptr k1=t,k2=t->lchild;
		k1->lchild=k2->rchild;
		k2->rchild=k1;
		t=k2;
	}
	else if(t->rchild!=NULL&&t->rchild->pri>t->pri)
	{
		bstptr k1=t,k2=t->rchild;
		k1->rchild=k2->lchild;
		k2->lchild=k1;
		t=k2;
	}
}

void preorder(bstptr &t)
{
	if(t!=NULL)
	{
		cout<<t->data<<" ";
		preorder(t->lchild);
		preorder(t->rchild);
	}
}

int main()
{
	cout<<"enter the character and number($ to stop)\n";
	bstptr t=NULL;
	while(1)
	{
		char a;int n;
		cin>>a>>n;
		if(a=='$')break;
		t=insert(t,a,n);
		heapify(t,a);
	}
	preorder(t);
	cout<<endl;
}

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ul;

struct node{
    ll data;ul pri,size;
    node* lchild;
    node* rchild;
    node(int d){
        data=d;pri=rand()%LLONG_MAX;size=1;
        lchild=rchild=NULL;
    }
};

typedef node* btptr;

ul get_size(btptr &t){
    if(t==NULL)return 0;
    else return t->size;
}

void update_size(btptr &t){
    if(t==NULL)return;
    else t->size=1+get_size(t->lchild)+get_size(t->rchild);
}

btptr left_rotation(btptr &t){
    btptr right=t->rchild;
    btptr temp=right->lchild;
    right->lchild=t;
    t->rchild=temp;
    update_size(t);
    update_size(right);
    return right;
}

btptr right_rotation(btptr &t){
    btptr left=t->lchild;
    btptr temp=left->rchild;
    left->rchild=t;
    t->lchild=temp;
    update_size(t);
    update_size(left);
    return left;
}

btptr insert_node(btptr &t,ll data){
    if(t==NULL){
        return new node(data);
    }else if(data<t->data){
        t->lchild=insert_node(t->lchild,data);
        if(t->lchild->pri>t->pri){
            t=right_rotation(t);
        }
    }else if(data>t->data){
        t->rchild=insert_node(t->rchild,data);
        if(t->rchild->pri>t->pri){
            t=left_rotation(t);
        }
    }else{
        return t;
    }
    update_size(t);
    return t;
}

void level_order(btptr &t){
    if(t==NULL)return;
    queue<btptr> q;
    q.push(t);
    q.push(NULL);
    while(!q.empty()){
        if(q.front()==NULL){
            cout<<endl;
            q.pop();
            if(q.empty())break;
            q.push(NULL);
        }
        btptr temp=q.front();q.pop();
        cout<<temp->data<<" "<<temp->pri<<"\t";
        if(temp->lchild)q.push(temp->lchild);
        if(temp->rchild)q.push(temp->rchild);
    }
}

btptr search(btptr t,ll x){
    while(t!=NULL){
        if(x<t->data){
            t=t->lchild;
        }else if(x>t->data){
            t=t->rchild;
        }else{
            break;
        }
    }
    return t;
}

btptr deleteNode(btptr &t,ll x){
    if(t==NULL){
        return NULL;
    }else if(x<t->data){
        t->lchild=deleteNode(t->lchild,x);
    }else if(x>t->data){
        t->rchild=deleteNode(t->rchild,x);
    }else{
        if(t->lchild==NULL && t->rchild==NULL){
            delete t;
            return NULL;
        }else if(t->lchild==NULL){
            btptr temp=t->rchild;
            delete t;
            return temp;
        }else if(t->rchild==NULL){
            btptr temp=t->lchild;
            delete t;
            return temp;
        }else{
            if(t->lchild->pri>t->rchild->pri){
                t=right_rotation(t);
                t->rchild=deleteNode(t->rchild,x);
            }else{
                t=left_rotation(t);
                t->lchild=deleteNode(t->lchild,x);
            }
        }
    }
    update_size(t);
    return t;
}

//FUNTION TO COUNT NUMBER OF NODES WHICH ARE SMALL THAN THE GIVEN NODE

ll count_small(btptr &t,ll x){
    if(t==NULL)return 0;
    else if(t->data==x){
        return get_size(t->lchild);
    }else if(x<t->data){
        return count_small(t->lchild,x);
    }else{
        return 1+get_size(t->lchild)+count_small(t->rchild,x);
    }
}

//FUNTION TO GET THE KTH SMALLEST NODE IN LOG(N)

btptr kth_smallest(btptr &t,ll k){
    if(t==NULL)return NULL;
    else if((1+get_size(t->lchild))==k){
        return t;
    }else if(k<(1+get_size(t->lchild))){
        return kth_smallest(t->lchild,k);
    }else{
        return kth_smallest(t->rchild,k-1-get_size(t->lchild));
    }
}

int main()
{
    srand(time(0));
    btptr t=NULL;
    while(true){
        char x;ll data;
        cin>>x>>data;
        if(data==-1)break;
        if(x=='i'){
            t=insert_node(t,data);
        }else if(x=='d'){
            t=deleteNode(t,data);
        }else if(x=='s'){
            btptr temp=search(t,data);
            cout<<(temp!=NULL?"found":"not found")<<"\n";
            continue;
        }else if(x=='k'){
            btptr temp=kth_smallest(t,data);
            if(temp==NULL)cout<<"node not found\n";
            else cout<<"kth SMALLEST node is: "<<temp->data<<"\n";
            continue;
        }else if(x=='c'){
            cout<<count_small(t,data)<<"\n";
            continue;
        }
        level_order(t);
    }
}