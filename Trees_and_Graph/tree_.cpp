#include<bits/stdc++.h>
using namespace std;
struct  Node{
	int data;
	Node* right;
	Node* left;
};
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