#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	
	int n;
	cin>>n;
	int num[100010];
	int dp[100010][2];
	for(int i=0;i<n;i++)
		cin>>num[i];
	dp[0][0]=num[0];
	dp[0][1]=num[0];
	
	for(int i=1;i<n;i++){
		dp[i][0]=max(dp[i-1][0]+num[i],max(dp[i-1][1],num[i]));
		dp[i][1]=max(dp[i-1][1]+num[i],num[i]);
	}
	int res=-INT_MAX;
	for(int i=0;i<n;i++){
		res=max(res,max(dp[i][1],dp[i][0]));
	}
	cout<<res<<'\n';
}