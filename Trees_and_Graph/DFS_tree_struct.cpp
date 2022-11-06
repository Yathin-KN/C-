#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	int vis=0;
	int lvl=0;
	Node* right;
	Node* left;
};
void dfs(Node*node){
	cout<<node->data<<" "<<node->lvl<<"\n";
	node->vis=1;
	if(node->right){
		if(node->right->vis==0){
			(node->right)->lvl=node->lvl + 1;
			dfs(node->right);
		}
	}
	if(node->left){
		if(node->left->vis==0){
			(node->left)->lvl=node->lvl + 1;
			dfs(node->left);
		}
	}
}
Node* createNode(int data){
   Node* newNode=new Node();
   newNode->data=data;
   newNode->right=newNode->left=nullptr;
}
int main(){
   Node* root=createNode(1);
   root->right=createNode(3);
   root->left=createNode(2);
   root->left->left=createNode(4);
   dfs(root);
}