#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	int num[1010];
	int dp[1010];
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	int res=-1;
	for(int i=n;i>0;i--){
		int Max=0;
		for(int j=n;j>i;j--){
			if(num[i]>num[j]){
				Max=max(Max,dp[j]);
			}
		}
		dp[i]=Max+1;
		if(res<dp[i]) res=dp[i];
	}
	cout<<res<<'\n';
}