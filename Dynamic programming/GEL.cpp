#include<bits/stdc++.h>
using namespace std;
map<string,string> per_gene;
unordered_map<string,pair<string,string>> child_par;
string c1="non-existent",c2="dominant",c3="recessive";
const int N=3200;
unordered_map<string,int> child_check;
void test(){
	string s1,s2;
	cin>>s1>>s2;
	if(s2==c1 || s2==c2 || s2==c3){
		per_gene[s1]=s2;
	}else{
		if((child_par[s2].first).length()==0){
             child_par[s2].first=s1;
		}else{
			child_par[s2].second=s1;
		}
	}
	
}
int main(){
	int t;
	cin>>t;
	while(t--) test();
	string child,par1,par2;
	int ct=0;
	do{
		
		for(auto itr=child_par.begin();itr!=child_par.end();itr++){
		child=itr->first;
		par1=(itr->second).first;
		par2=(itr->second).second;
		if(child_check[child]==1) continue;
        if(per_gene[par1].length() && per_gene[par2].length()){
            child_check[child]=1;
        	if((per_gene[par1]!=c1 && per_gene[par2]!=c1) ||((per_gene[par1]==c2 || per_gene[par2]==c2))){
                  if((per_gene[par1]==c2 && per_gene[par2]==c2) || (per_gene[par1]==c2 && per_gene[par2]==c3) || (per_gene[par1]==c3 && per_gene[par2]==c2)){
                  	per_gene[child]=c2;
                  }else{
                  	per_gene[child]=c3;
                  }
		}else{
			per_gene[child]=c1;
		}

		}else{
            ct++;
		}
        }

	}while(ct--);
	
	for(auto itr=per_gene.begin();itr!=per_gene.end();itr++){
		cout<<itr->first<<" "<<itr->second<<"\n";
	}
}