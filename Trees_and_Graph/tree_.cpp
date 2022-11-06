//tree construction using structures and pointers
//tree traversals->DFS
//type-1 ->pre-order traversal data->left->right
//type-2 ->in-order traversal left->data->right
//type-3 ->pre-order traversal left->right->data
#include<bits/stdc++.h>
using namespace std;
//basic contents of a Node:
//data->data or content of a node
//Node* right->contains pointer to the right child of the node 
//Node* left->contains pointer to the left child of the node 
struct  Node{
	int data;
	Node* right;
	Node* left;
};
//function to create a node and return a pointer to the node:
Node* createNode(int data){
	Node* newNode=new Node();
	newNode->data=data;
	newNode->left=newNode->right=nullptr;
}
void preOrder(Node* node){
  if(node==nullptr) return;
  cout<<node->data<<" ";
  preOrder(node->left);
  preOrder(node->right);

}
void inOrder(Node* node){
  if(node==nullptr) return;
  inOrder(node->left);
  cout<<node->data<<" ";
  inOrder(node->right);
}
void postOrder(Node* node){
  if(node==nullptr) return;
  postOrder(node->left);
  postOrder(node->right);
  cout<<node->data<<" ";
}

int main(){
// construction of tree:
//  	       1
//           /   \
// 	   2       3
//        / \     / \
//       4   5   6   7
// 	  /	 /
// 	 9      15	 
		
  Node* root=createNode(1);
  root->left=createNode(2);
  root->right=createNode(3);
  root->left->left=createNode(4);
  root->left->right=createNode(5);
  root->left->right->left=createNode(9);
  root->right->left=createNode(6);
  root->right->right=createNode(7);
  root->right->right->left=createNode(15);
  preOrder(root);
  cout<<"\n";
  inOrder(root);
  cout<<"\n";
  postOrder(root);

}
