#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	
	int n;
	cin>>n;
	int num[510][510];
	int dp[510][510];
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			cin>>num[i][j];
		}
	}
	dp[0][0]=num[0][0];
	for(int i=1;i<n;i++){
		dp[i][0]=dp[i-1][0]+num[i][0];
		dp[i][i]=dp[i-1][i-1]+num[i][i];
	}
	for(int i=2;i<n;i++){
		for(int j=1;j<i;j++){
			dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+num[i][j];
		}
	}
	int res=-1;
	for(int i=0;i<n;i++){
		res=max(res,dp[n-1][i]);
	}
	cout<<res<<'\n';
}