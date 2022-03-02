#include<bits/stdc++.h>

using namespace std;

int n;
long long dp[10000000]={0};
long dfs(int num){
	if(dp[num]!=0) return dp[num];
	if(num==1) return 1;
	if(num==2) return 2;
	if(num==3) return 4;
	
	dp[num]=(dfs(num-1)+dfs(num-2)+dfs(num-3))%1000000009;
	return dp[num];
}


int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		cout<<dfs(n)<<endl;
	}
}