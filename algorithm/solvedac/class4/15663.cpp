#include<bits/stdc++.h>

using namespace std;

vector<int> dp;
int n,m;
int ch[10]={0};
int res[10];
void dfs(int cnt){
	if(cnt==m){
		for(int i=0;i<m;i++){
			cout<<res[i]<<' ';
		}
		cout<<'\n';
	}else{
		int last=0;
		for(int i=0;i<n;i++){
			if(last==dp[i]) continue;
			if(ch[i]==0){
				last=dp[i];
				ch[i]=1;
				res[cnt]=dp[i];
				dfs(cnt+1);
				ch[i]=0;
			}
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
	dfs(0);
	
}