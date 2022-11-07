// *** warning **** -> this is not the correct approach to solve the problem <- *** warning ****
// The solution i tried here is purely experimental:
//The question states that there are N tiles and a frog which is in the 0th tile has to reach the Nth tile in minimum number of jumps with a restriction that 
//if suppose the frog is on ith tile it can jump to either i+1th tile or i+2 th tile

//well since i had learned BFS recently and which is an algo to find minimum path at many problems eventhough the approach isn't needed here i tried to implement it
//so the code here assumes the frog is already at tile 6 (Nth tile here) thus the frog can havee arrived here from either N-1th or N-2th tile
//so using the same concept for both N-1th as well as N-2 th tile I imagined a probability tree ( as i like to call ) which sorta look like this:
//                    6            
//              /          \
//             5            4
//          /    \        /   \
//         4      3      3     2
//        / \    / \    / \     \
//       3   2  1   2  2   1     1
//      / \   \      \ \
//     2   1   1      1 1
//    /
//   1
// if we apply a bfs traversal the level at which the tile 1 is apprached one becomes the shortest path as shown by the arrows the path
// to be followed by the from in ordered to reach thr 6th tile is either:
// 1->3->5->6   1->2->4->6  1->3->4->6 i.e minimum of three jumps is required :) yeah preeeety confusing sol but yeah makes your hold on BFS preety strong:
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
