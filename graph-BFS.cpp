#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
//an adjacency matrix representation of graph
vector<int> graph[N];
//visited array
int vis[N];
//cstores level of each node:
int level[N];
void bfs(int source){
   //initializing a queue
   queue<int> q;
   //pushing the source node into queue
   q.push(source);
   //marking the node pushed as 1 in visited array
   vis[source]++;
   //running a while loop till q is empty
   while(!q.empty()){
      //initialize the the front element in queue as the current vertex
       int cur_v=q.front();
       cout<<cur_v<<" ";
       //removes the front element from the queue
       q.pop();
       //traverse through all the children of the the current vertex
       for(int child:graph[cur_v]){
         // if the child node is already visited ignore it.
         if(vis[child]) continue;
         //else push the child node into the queue and mark it as visited.
         vis[child]=1;
         q.push(child);
         //stores the level of each node.
         level[child]=level[cur_v]+1;
       }

   }

}
int main(){
   int n,m;
   //n->no of nodes m->no. of edges
   cin>>n>>m;
   //taking the m edge nodes in the graph
   for(int i=0;i<m;i++){
      int n1,n2;
      cin>>n1>>n2;
      //n1--n2 connected biderectionally
      graph[n2].push_back(n1);
      graph[n1].push_back(n2);
   }
   //considering 1 as root node and calling BFS function
   bfs(1);
   cout<<"\n";
   //printing the level of each node:
   for(int i=1;i<=n;i++){
      cout<<i<<":"<<level[i]<<"\n";
   }
}