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
void level_order(btptr &t)
{
    queue<btptr> q;
    q.push(t);
    q.push(NULL);
    while(!q.empty())
    {
        if(q.front()==NULL)
        {
            cout<<endl;
            q.pop();
            if(q.empty())break;
            q.push(NULL);
        }
        btptr t1=q.front();
        cout<<t1->data<<" ";
        q.pop();
        if(t1->lchild!=NULL)q.push(t1->lchild);
        if(t1->rchild!=NULL)q.push(t1->rchild);
    }
}

int height(btptr &t)
{
    if(t==NULL)return -1;
    else return max(height(t->lchild),height(t->rchild))+1;
}

btptr creat(btptr &t,btptr &prev,int data)
{
    if(t==NULL)t=creatnode(data);
    else if(data<t->data)t->lchild=creat(t->lchild,t,data);
    else if(data>t->data)t->rchild=creat(t->rchild,t,data);
    int l=height(t->lchild);
    int r=height(t->rchild);
    if((l-r)>1||(l-r)<-1)
    {
        if(r>l)
        {
            int rr=height(t->rchild->rchild);
            int rl=height(t->rchild->lchild);
            if(rr>rl)
            {
                swap(t->data,t->rchild->data);
                btptr t1=t->rchild;t->rchild=t->rchild->rchild;
                t1->rchild=t1->lchild;t1->lchild=t->lchild;
                t->lchild=t1;      
            }
            else
            {
                swap(t->data,t->rchild->lchild->data);
                btptr t1=t->rchild->lchild;t->rchild->lchild=t1->rchild;
                t1->rchild=t1->lchild;t1->lchild=t->lchild;
                t->lchild=t1;
            }
        }
        else
        {
            int lr=height(t->lchild->rchild);
            int ll=height(t->lchild->lchild);
            if(lr>ll)
            {
                swap(t->data,t->lchild->rchild->data);
                btptr t1=t->lchild->rchild;t->lchild->rchild=t1->lchild;
                t1->lchild=t1->rchild;t1->rchild=t->rchild;
                t->rchild=t1;
            }
            else
            {
                swap(t->data,t->lchild->data);
                btptr t1=t->lchild;t->lchild=t->lchild->lchild;
                t1->lchild=t1->rchild;t1->rchild=t->rchild;
                t->rchild=t1;
            }
        }
    }
    return t;
}

int main()
{
    btptr t=NULL;
    while(1)
    {
        int data;cin>>data;
        if(data==-1)break;
        btptr prev=NULL;
        t=creat(t,prev,data);
        level_order(t);
    }
}





struct node
{
    int key;
    int height;
    node *left;
    node *right;
};
 
node* create_node(int key_)
{
    node *child = new node;
 
    child->key = key_;
    child->height = 1;
    child->left = NULL;
    child->right = NULL;
 
    return child;
}
 
int get_height(node *current_node)
{
    if(current_node == NULL)
        return 0;
    return current_node->height;
}
 
int get_balance(node *current_node)
{
    if(current_node == NULL)
        return 0;
    return get_height(current_node->left) - get_height(current_node->right);
}
 
node* left_rotate(node *x)
{
    node *y = x->right;
    node *t2 = y->left;
 
    y->left = x;
    x->right = t2;
 
    x->height = max(get_height(x->left), get_height(x->right)) + 1;
    y->height = max(get_height(y->left), get_height(y->right)) + 1;
 
    return y;
}
 
node* right_rotate(node *x)
{
    node *y = x->left;
    node *t2 = y->right;
 
    y->right = x;
    x->left = t2;
 
    x->height = max(get_height(x->left), get_height(x->right)) + 1;
    y->height = max(get_height(y->left), get_height(y->right)) + 1;
 
    return y;
}
 
node* left_left_case(node *current_node)
{
    return right_rotate(current_node);
}
 
node* right_right_case(node *current_node)
{
    return left_rotate(current_node);
}
 
node* left_right_case(node *current_node)
{
    current_node->left = left_rotate(current_node->left);
    return right_rotate(current_node);
}
 
node* right_left_case(node *current_node)
{
    current_node->right = right_rotate(current_node->right);
    return left_rotate(current_node);
}
 
void preorder_traverse(node *current_node)
{
    if(current_node == NULL)
        return;
 
    printf("%d ",current_node->key);
    preorder_traverse(current_node->left);
    preorder_traverse(current_node->right);
    return;
}
 
node* find_min(node *current_node)
{
    while(current_node->left != NULL)
        current_node = current_node->left;
    return current_node;
}
 
node* insert_node(node *current_node, int key_)
{
    if(current_node == NULL)
        return create_node(key_);
 
    if(key_ < current_node->key)
        current_node->left = insert_node(current_node->left, key_);
    else if(key_ > current_node->key)
        current_node->right = insert_node(current_node->right, key_);
    else
        return current_node;
 
    current_node->height = max(get_height(current_node->left), get_height(current_node->right)) + 1;
 
    int balance = get_balance(current_node);
 
    if(balance > 1 && key_ < current_node->left->key)
        return left_left_case(current_node);
 
    if(balance < -1 && key_ > current_node->right->key)
        return right_right_case(current_node);
 
    if(balance > 1 && key_ > current_node->left->key)
        return left_right_case(current_node);
 
    if(balance < -1 && key_ < current_node->right->key)
        return right_left_case(current_node);
 
    return current_node;
}
 
node* search_node(node *current_node, int item)
{
    while(current_node != NULL)
    {
        if(item > current_node->key)
            current_node = current_node->right;
        else if(item < current_node->key)
            current_node = current_node->left;
        else
            break;
    }
    return current_node;
}
 
node* delete_node(node *current_node, int key_)
{
    if(current_node == NULL)
        return current_node;
 
    if(key_ < current_node->key)
        current_node->left = delete_node(current_node->left, key_);
    else if(key_ > current_node->key)
        current_node->right = delete_node(current_node->right, key_);
    else
    {
        if(current_node->left == NULL || current_node->right == NULL)
        {
            node *temp = NULL;
 
            if(current_node->left != NULL)
                temp = current_node->left;
            else
                temp = current_node->right;
 
            if(temp == NULL)
            {
                temp = current_node;
                current_node = NULL;
            }
            else
            {
                current_node->key = temp->key;
                current_node->left = temp->left;
                current_node->right = temp->right;
                current_node->height = temp->height;
            }
 
            delete temp;
        }
        else
        {
            node *temp = find_min(current_node->right);
 
            current_node->key = temp->key;
            current_node->right = delete_node(current_node->right, temp->key);
        }
    }
 
    if(current_node == NULL)
        return current_node;
 
    current_node->height = max(get_height(current_node->left), get_height(current_node->right)) + 1;
 
    int balance = get_balance(current_node);
 
    if(balance > 1 && get_balance(current_node->left) >= 0)
        return left_left_case(current_node);
 
    if(balance < -1 && get_balance(current_node->right) <= 0)
        return right_right_case(current_node);
 
    if(balance > 1 && get_balance(current_node->left) < 0)
        return left_right_case(current_node);
 
    if(balance < -1 && get_balance(current_node->right) > 0)
        return right_left_case(current_node);
 
    return current_node;
}

int main()
{
    node *root = NULL;
 
    root = insert_node(root, 9);
    root = insert_node(root, 5);
    root = insert_node(root, 10);
    root = insert_node(root, 0);
    root = insert_node(root, 6);
    root = insert_node(root, 11);
    root = insert_node(root, -1);
    root = insert_node(root, 1);
    root = insert_node(root, 2);
 
    printf("Pre-order traverse: ");
    preorder_traverse(root);
 
    root = delete_node(root, 10);
 
    printf("\nPre-order traverse: ");
    preorder_traverse(root);
    delete_tree(root);
    return 0;
}