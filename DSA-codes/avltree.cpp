#include<bits/stdc++.h>
using namespace std;

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
 
void delete_tree(node *current_node)
{
    if(current_node == NULL)
    {
        delete current_node;
        return;
    }
    delete_tree(current_node->left);
    delete_tree(current_node->right);
    return;
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