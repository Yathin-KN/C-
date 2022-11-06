//this problem asks us to find the sum of all the cousin nodes of a given node
// a cousin node is a node at the same level of the node but has deifferent parents
//My approach:
//maintain and populate two arrays lvl array which stores the level of each node and par array which stores par of each array
//then traverse through the nodes continue if the nodes have same parent or if the level of the key node != that of the node
//callculate the sum of all the remaining nodes

#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
vector<int> t[N];
int par[N];
int lvl[N];
int vis[N];
void bfs(int node){
  queue<int> q;
  vis[node]=1;
  q.push(node);
  while(!q.empty()){
    int cv=q.front();
    q.pop();
    for(int child:t[cv]){
       if(vis[child]) continue;
       vis[child]=1;
       par[child]=cv;
       lvl[child]=lvl[cv]+1;
       q.push(child);
}
  }
}
int main(){
  int n;
  cin>>n;
  int m=n-1;
  for(int j=0;j<m;j++){
    int n1, n2;
    cin>>n1>>n2;
    t[n1].push_back(n2);
    t[n2].push_back(n1);
  }
  bfs(1);
  int key;
  cin>>key;
  int flag=0,sum=0;
  
  
 for(int k=1;k<=n;k++){
   if(par[key]==par[k]) continue;
   if(lvl[key]!=lvl[k])continue;
   flag++;
   sum+=k;
 }
  if(flag){
    cout<<sum<<"\n";
  }else{
    cout<<-1<<"\n";
  }

  

}
