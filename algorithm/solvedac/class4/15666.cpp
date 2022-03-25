#include<bits/stdc++.h>

using namespace std;

vector<int> dp;
int n,m;
int res[10];
void dfs(int cnt,int l){
	if(cnt==m){
		for(int i=0;i<m;i++){
			cout<<res[i]<<' ';
		}
		cout<<'\n';
	}else{
		int last=0;
		for(int i=l;i<n;i++){
			if(last==dp[i]) continue;
			last=dp[i];
			res[cnt]=dp[i];
			dfs(cnt+1,i);
		}
	}
}

int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		dp.push_back(a);
	}
	sort(dp.begin(),dp.end());
	dfs(0,0);
	
}