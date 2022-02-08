#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	int height;
	node* lchild;
	node* rchild;
	node(int key){
		data=key;
		height=1;
		lchild=rchild=NULL;
	}
};

typedef node* btptr;

int get_height(btptr &t){
	if(t==NULL)return 0;
	else return t->height;
}

int get_balance(btptr &t){
	if(t==NULL)return 0;
	else return get_height(t->lchild)-get_height(t->rchild);
}

btptr left_rotation(btptr &t){
	btptr right=t->rchild;
	btptr temp=right->lchild;
	right->lchild=t;
	t->rchild=temp;
	t->height=max(get_height(t->lchild),get_height(t->rchild))+1;
	right->height=max(get_height(right->lchild),get_height(right->rchild))+1;
	return right;
}

btptr right_rotation(btptr &t){
	btptr left=t->lchild;
	btptr temp=left->rchild;
	left->rchild=t;
	t->lchild=temp;
	t->height=max(get_height(t->lchild),get_height(t->rchild))+1;
	left->height=max(get_height(left->lchild),get_height(left->rchild))+1;
	return left;
}

btptr left_left_case(btptr &t){
	return right_rotation(t);
}

btptr right_right_case(btptr &t){
	return left_rotation(t);
}

btptr left_right_case(btptr &t){
	t->lchild=left_rotation(t->lchild);
	return right_rotation(t);
}

btptr right_left_case(btptr &t){
	t->rchild=right_rotation(t->rchild);
	return left_rotation(t);
}

btptr insert_node(btptr &t,int data){
	if(t==NULL){
		return new node(data);
	}else if(data<t->data){
		t->lchild=insert_node(t->lchild,data);
	}else if(data>t->data){
		t->rchild=insert_node(t->rchild,data);
	}else{
		return t;
	}
	t->height=max(get_height(t->lchild),get_height(t->rchild))+1;
	int balance=get_balance(t);
	if(balance>1 && data<t->lchild->data){
		return left_left_case(t);
	}else if(balance>1 && data>t->lchild->data){
		return left_right_case(t);
	}else if(balance<-1 && data>t->rchild->data){
		return right_right_case(t);
	}else if(balance<-1 && data<t->rchild->data){
		return right_left_case(t);
	}
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
		cout<<temp->data<<" ";
		if(temp->lchild)q.push(temp->lchild);
		if(temp->rchild)q.push(temp->rchild);
	}
}

int min_value(btptr &t){
	if(t->lchild==NULL)return t->data;
	else return min_value(t->lchild);
}

btptr deleteNode(btptr &t,int data){
	if(t==NULL)return NULL;
	else if(data<t->data){
		t->lchild=deleteNode(t->lchild,data);
	}else if(data>t->data){
		t->rchild=deleteNode(t->rchild,data);
	}else{
		if(t->lchild==NULL && t->rchild==NULL){
			return NULL;
		}else if(t->lchild==NULL){
			return t->rchild;
		}else if(t->rchild==NULL){
			return t->lchild;
		}else{
			t->data=min_value(t->rchild);
			t->rchild=deleteNode(t->rchild,t->data);
		}
	}
	if(t==NULL)return NULL;
	t->height=max(get_height(t->lchild),get_height(t->rchild))+1;
	int balance=get_balance(t);
	if(balance>1 && get_balance(t->lchild)>=0){
		return left_left_case(t);
	}else if(balance>1 && get_balance(t->lchild)<0){
		return left_right_case(t);
	}else if(balance<-1 && get_balance(t->rchild)<=0){
		return right_right_case(t);
	}else if(balance<-1 && get_balance(t->rchild)>0){
		return right_left_case(t);
	}
	return t;
}

btptr search(btptr t,int x){
	while(t!=NULL){
		if(x<t->data){
			t=t->lchild;
		}else if(x>t->data){
			t=t->rchild;
		}else break;
	}
	return t;
}

int main()
{
	btptr t=NULL;
	while(true){
		int data;cin>>data;
		if(data==-1)break;
		t=insert_node(t,data);
		level_order(t);
	}
	while(true){
		int data;cin>>data;
		if(data==-1)break;
		t=deleteNode(t,data);
		level_order(t);
	}
}