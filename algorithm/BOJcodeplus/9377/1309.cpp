#include<bits/stdc++.h>

using namespace std;

int n;
int dp[200020][3];

int main(){
	cin>>n;
	dp[0][0]=1;
	dp[0][1]=dp[0][2]=0;

	for(int num=1;num<=n;num++){
		dp[num][0]=(dp[num-1][0]+dp[num-1][1]+dp[num-1][2])%9901;
		dp[num][1]=(dp[num-1][0]+dp[num-1][2])%9901;
		dp[num][2]=(dp[num-1][0]+dp[num-1][1])%9901;
	}
	cout<<(dp[n][0]+dp[n][1]+dp[n][2])%9901<<'\n';
}