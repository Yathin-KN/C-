#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	int vis=0;
	Node* right;
	Node* left;
};
Node* createNode(int data){
	if(data==-1) return nullptr;
	Node* newNode=new Node();
	newNode->data=data;
	newNode->right=newNode->left=nullptr;
}
Node* jump(Node* node,int start){
	if(start<=0) return nullptr;
	node->right=createNode(start-1);
	jump(node->right,node->right->data);
	node->left=createNode(start-2);
	jump(node->right,node->right->data);
}
void bfs(Node* node){
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
	Node* root=createNode(6);
   jump(root,6);
   bfs(root);
}
