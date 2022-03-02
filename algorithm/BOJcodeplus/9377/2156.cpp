#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	int dp[10010][3];
	int num[10010];
	for(int i=0;i<n;i++)
		cin>>num[i];
	
	dp[0][0]=dp[0][2]=0;
	dp[0][1]=num[0];
	for(int i=1;i<n;i++){
		dp[i][0]=max(dp[i-1][2],max(dp[i-1][1],dp[i-1][0]));
		dp[i][1]=dp[i-1][0]+num[i];
		dp[i][2]=dp[i-1][1]+num[i];
	}
	int res=max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
	cout<<res<<'\n';
}