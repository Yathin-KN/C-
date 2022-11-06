#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	int vis=0;
	Node* left;
	Node* right;
};
Node* createNode(int data){
	Node* newNode=new Node();
	newNode->data=data;
	newNode->right=newNode->left=nullptr;
	return newNode;
};
void bfs(Node* node){
	cout<<"inside"<<"\n";
	queue<Node*> q;
	q.push(node);
	node->vis=1;
	while(!q.empty()){
	// cout<<"inside"<<"\n";
		
		Node* curr_node=q.front();
		q.pop();
		cout<<curr_node->data<<"\n";
		curr_node->vis=1;
		if(curr_node->right){
			if(curr_node->right->vis==0){
				curr_node->right->vis=1;
				q.push(curr_node->right);
			}
		}
		if(curr_node->left){
			if(curr_node->left->vis==0){
				curr_node->left->vis=1;
				q.push(curr_node->left);
			}
		}
	}
}
int main(){
  Node* root=createNode(1);
  root->right=createNode(3);
  root->left=createNode(2);
  root->left->left=createNode(4);
  root->left->right=createNode(5);
  root->right->left=createNode(6);
  root->right->right=createNode(7);
  bfs(root);

}