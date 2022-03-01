#include<bits/stdc++.h>

using namespace std;
int n,k;
int res=0;
long dp[210][210]={0};
int dfs(int num,int cnt){
	if(cnt==1){
		if(num>=0) return 1;
	}else{
		if(dp[num][cnt]) return dp[num][cnt];
		for(int i=0;i<=num;i++){
			dp[num][cnt]=(dp[num][cnt]+dfs(num-i,cnt-1))%1000000000;
		}
	}
	return dp[num][cnt];
}


int main(){
	cin>>n>>k;
	
	cout<<dfs(n,k)<<'\n';
}