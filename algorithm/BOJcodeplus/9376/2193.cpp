#include<bits/stdc++.h>

using namespace std;

int n;
long dp[100][2];

int main(){
	cin>>n;
	dp[1][1]=1;
	dp[1][0]=0;
	for(int i=2;i<=n;i++){
		dp[i][0]=dp[i-1][0]+dp[i-1][1];
		dp[i][1]=dp[i-1][0];
	}
	cout<<dp[n][1]+dp[n][0]<<'\n';
}