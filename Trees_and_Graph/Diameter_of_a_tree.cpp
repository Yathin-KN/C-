#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
vector<int> graph[N];
int depth[N];
int maxlen=0;
int mxnode=0;
void dfs(int node,int par=0){
	for(int child:graph[node]){
		if(child==par) continue;
		depth[child]=depth[node]+1;
		if(depth[child]>maxlen){
			maxlen=depth[child];
			mxnode=child;
		}

		dfs(child,node);
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
	int maxnum=0;
	for(int i=1;i<=n;i++){

       dfs(i);
       for(int i=1;i<=n;i++){
       	depth[i]=0;
       }
       maxnum=max(maxnum,maxlen);
       maxlen=0;
	}
	cout<<maxnum<<"\n";
	cout<<mxnode<<"\n";

}