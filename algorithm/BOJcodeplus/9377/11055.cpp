#include<bits/stdc++.h>

using namespace std;

int n;
int num[1010];
int dp[1010];
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>num[i];
	
	int res=-1;
	
	for(int i=0;i<n;i++){
		int Max=0;
		for(int j=0;j<i;j++){
			if(num[i]>num[j]){
				Max=max(Max,dp[j]);
			}
		}
		dp[i]=Max+num[i];
		if(res<dp[i]) res=dp[i];
	}
	cout<<res<<'\n';
}