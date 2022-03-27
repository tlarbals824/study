#include<bits/stdc++.h>

using namespace std;
vector<pair<int,int>> m;
int n,k;
int dp[110][100100];
int dfs(int idx,int weight){
	if(dp[idx][weight]) return dp[idx][weight];
	
	if(idx==n) return 0;
	
	int cur1=0;
	if(weight+m[idx].first<=k){
		cur1=dfs(idx+1,weight+m[idx].first)+m[idx].second;
	}
	
	int cur2=dfs(idx+1,weight);
	
	return dp[idx][weight]=max(cur1,cur2);
}


int main(){
	ios_base::sync_with_stdio(false);
	
	cin>>n>>k;
	for(int i=0;i<n;i++){
		int w,v;
		cin>>w>>v;
		m.push_back({w,v});
	}
	
	cout<<dfs(0,0)<<'\n';
}