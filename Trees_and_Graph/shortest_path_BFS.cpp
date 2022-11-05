//importent concept:
//if the edges in a graph are of equal weight the shortest path from one 
//vertex to another is when we run bfs on one of the vertex and the level
//of the node to which shortest path has to be determined is the shortest path

#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
vector<int> graph[N];
int vis[N];
int level[N];
int sp=-1;
int mp=INT_MAX;
int bfs(int node1,int node2){
	queue<int> q;
	q.push(node1);
	while(!q.empty()){
       int cur_v=q.front();
       // cout<<cur_v<<"\n";
       q.pop();
       vis[cur_v]=1;
       for(int child:graph[cur_v]){
       	if(vis[child]) continue;
       	vis[child]=1;
       	level[child]=level[cur_v]+1;
       	mp=min(mp,level[child]);
       	q.push(child);
       }
       if(level[node2]) return level[node2];
       
	}
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int n1,n2;
		cin>>n1>>n2;
		graph[n1].push_back(n2);
		graph[n2].push_back(n1);
	}
	int x,y;
	cin>>x>>y;
	cout<<bfs(x,y)<<"\n";
}