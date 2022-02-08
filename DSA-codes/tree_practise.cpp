#include<iostream>
#include<queue>
#include<climits>
using namespace std;

 struct bstnode
 {
 	int data;
 	bstnode *left;
 	bstnode *right;
 };

 bstnode *creatnode(int data)
 {
 	bstnode *temp;
 	temp=(bstnode*)new(bstnode);
 	temp->data=data;
 	temp->left=temp->right=NULL;
 	return temp;
 }

 bstnode *insert(bstnode *root,int data)
 {
 	if(root==NULL)
 	{
 		root=creatnode(data);
 	}
 	else if(data<=root->data)
 	{
 		root->left=insert(root->left,data);
 	}
 	else {
 		root->right=insert(root->right,data);
 	}
 	return root;
 }

 void preorder_traversal(bstnode *root)
 {
 	if(root!=NULL)
 	{
 		cout<<root->data<<" ";
 		preorder_traversal(root->left);
 		preorder_traversal(root->right);
 	}
 }

  void inorder_traversal(bstnode *root)
 {
 	if(root!=NULL)
 	{
 		inorder_traversal(root->left);
 		cout<<root->data<<" ";
 		inorder_traversal(root->right);
 	}
 }

  void postorder_traversal(bstnode *root)
 {
 	if(root!=NULL)
 	{
 		postorder_traversal(root->left);
 		postorder_traversal(root->right);
  		cout<<root->data<<" ";		
 	}
 }

void levelorder_traversal(bstnode *root)
{
	queue<bstnode*> q;
	bstnode *curr;
	q.push(root);
	while(!q.empty())
	{
		curr=q.front();
		cout<<curr->data<<" ";
		if(curr->left!=NULL)q.push(curr->left);
		if(curr->right!=NULL)q.push(curr->right);
		q.pop();
	}
}

int search(bstnode *root,int x)
{
	if(root==NULL)return 0;
	else if(root->data==x)return 1;
	else if(x<root->data)return search(root->left,x);
	else return search(root->right,x);
}

bstnode *findmin(bstnode *root)
{
	if(root->left==NULL)return root;
	else return findmin(root->left);
}

int findmax(bstnode *root)
{
	if(root->right==NULL)return root->data;
	else return findmax(root->right);
}

int max(int a,int b)
{
	if(a>b)return a;
	else return b;
}

int findh(bstnode *root)
{
	static int lh,rh;
	if(root==NULL)return -1;
	else{
		lh=findh(root->left);
		rh=findh(root->right);
	}
	return max(lh,rh)+1;
}

bool checkbst(bstnode *root,int low,int high)
{
	if(root==NULL)return true;
	if(root->data>low&&root->data<high)
	{
		if(checkbst(root->left,low,root->data)&&checkbst(root->right,root->data,high))
		{
			return true;
		}
	}
	else return false;
}

bstnode *delet(bstnode *root,int data)
{
	if(root==NULL)return root;
	else if(data<root->data){root->left=delet(root->left,data);}
	else if(data>root->data){root->right=delet(root->right,data);}
	else{
		if(root->left==NULL)
		{
			bstnode *temp=root->right;
			free(root);
			return temp;
		}
		else if(root->right== NULL)
		{
			bstnode *temp=root->left;
			free(root);
			return temp;
		}	
		else{
			bstnode *temp=findmin(root->right);
			root->data=temp->data;
			root->right=delet(root->right,temp->data);
		}
	}
	return root;
}

int main()
{
	bstnode *root=NULL;
	int choice;
	do{
		cout<<"                   THE BINARY SEARCH TREE..!!!"<<endl;
		cout<<"1:  Insert nodes in the tree\n";
		cout<<"2:  pre-order traversal of the tree\n";
		cout<<"3:  in-order traversal of the tree\n";
		cout<<"4:  post-order traversal of the tree\n";
		cout<<"5:  level-order traversal of the tree\n";
		cout<<"6:  search a data in the tree\n";
		cout<<"7:  minimum value of the tree\n";
		cout<<"8:  maximum value of the tree\n";
		cout<<"9:  height of the tree\n";
		cout<<"10: given binary tree is BST or not?\n";
		cout<<"11: to delete a node in the binary tree\n";
		cout<<"12: EXIT\n";
		cout<<"ENTER YOUR choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1: cout<<"how many number you want to insert?\n";
					int n;cin>>n;
					for(int i=0;i<n;i++)
					{
						cout<<"enter a number: ";
						int data;cin>>data;
						root=insert(root,data);
					}
					break;
			case 2: cout<<"the required traversal of the tree is "<<endl;
					preorder_traversal(root);
					cout<<endl;
					break;	
			case 3: cout<<"the required traversal of the tree is "<<endl;
					inorder_traversal(root);
					cout<<endl;
					break;
			case 4: cout<<"the required traversal of the tree is "<<endl;
					postorder_traversal(root);
					cout<<endl;
					break;
			case 5: cout<<"the required traversal of the tree is "<<endl;
					levelorder_traversal(root);
					cout<<endl;
					break;	
			case 6: {cout<<"enter the number you want to search: ";
					int x;cin>>x;
					int flag=search(root,x);
					if(flag==0)cout<<"number not found\n";
					else cout<<"number found\n";
					break;}

			case 7: bstnode *min;
					min=findmin(root);
					cout<<"the minimum number in the tree is: "<<min->data<<endl;
					break;

			case 8: cout<<"the maximun number in the tree is: "<<findmax(root)<<endl;
					break;
			case 9: cout<<"the height of the tree is: "<<findh(root)<<endl;
					break;
			case 10:{bool flag1=checkbst(root,INT_MIN,INT_MAX);
					if(flag1)cout<<"entered tree is a binary search tree\n";
					else cout<<"entered tree is not a binary search tree\n";
					break;}
			case 11:cout<<"enter the number you want to delete: ";
					int num;cin>>num;
					delet(root,num);
					break;
			case 12: break;
			default:cout<<"wrong choice! try again\n";
					break;																				
		}
	}while(choice!=12);
	cout<<"\n\n\n\n"<<"THANK YOU"<<endl;
}