#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define ul unsigned long long int

struct node{
    ll data;
    ul pri,size;
    node* lchild;
    node* rchild;
    node(ll d){
        data=d;pri=rand()%LLONG_MAX;size=1;
        lchild=rchild=NULL;
    }
};

typedef node* btptr;

ll get_size(btptr &t){
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
    q.push(t);q.push(NULL);
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
        if(x>t->data){
            t=t->rchild;
        }else if(x<t->data){
            t=t->lchild;
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
            if(t->rchild->pri>t->lchild->pri){
                t=left_rotation(t);
                t->lchild=deleteNode(t->lchild,x);
            }else{
                t=right_rotation(t);
                t->rchild=deleteNode(t->rchild,x);
            }
        }
    }
    update_size(t);
    return t;
}

ll count_small(btptr &t,ll x){
    if(t==NULL)return 0;
    else if(x<t->data){
        return count_small(t->lchild,x);
    }else if(x>t->data){
        return 1+get_size(t->lchild)+count_small(t->rchild,x);
    }else{
        return get_size(t->lchild);
    }
}

btptr kth_smallest(btptr &t,ll k){
    if(t==NULL)return NULL;
    else if((get_size(t->lchild)+1)==k){
        return t;
    }else if(k<=get_size(t->lchild)){
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