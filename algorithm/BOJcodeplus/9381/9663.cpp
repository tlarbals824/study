#include<bits/stdc++.h>

using namespace std;

int dp[20]={0};
int n;
int cnt=0;
void dfs(int idx){
	if(idx==n+1){
		cnt++;
	}else{
		for(int i=1;i<=n;i++){
			bool flag=false;
			for(int j=1;j<idx;j++){
				if(dp[j]==i||dp[j]==idx+i-j||j-dp[j]==idx-i){
					flag=true;
					break;
				}
			}
			if(flag) continue;
			else{
				dp[idx]=i;
				dfs(idx+1);
				dp[idx]=0;
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	
	cin>>n;
	
	dfs(1);
	cout<<cnt<<'\n';
}