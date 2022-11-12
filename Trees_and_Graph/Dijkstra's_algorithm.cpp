#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
vector<pair<int,int>> graph[N];
const int INF=1e8+10;
vector<int> dis(N,INF);
vector<int> vis(N,0);
void dijkstras(int source_n){
   set<pair<int,int>> st;
   dis[source_n]=0;
   st.insert({0,source_n});
   while(st.size()){
   	 auto node=*st.begin();
   	 int node_v=node.second;
   	 int node_wt=node.first;
   	 st.erase(st.begin());
   	 if(vis[node_v]) continue;
   	 vis[node_v]=1;
   	 for(auto child:graph[node_v]){
          int child_n=child.first;
          int child_wt=child.second;
          if(dis[node_v]+child_wt<dis[child_n]){
                dis[child_n]=dis[node_v]+child_wt;
                st.insert({dis[child_n],child_n});
          }
   	 }
   }

}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int n1,n2,wt;
        cin>>n1>>n2>>wt;
		graph[n1].push_back({n2,wt});
		graph[n2].push_back({n1,wt});
	}
	dijkstras(1);
    for(int i=1;i<=n;i++){
        cout<<dis[i]<<" ";
    }
}
