#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n,s;
	cin>>n>>s;
	int dp[n];
	for(int i=0;i<n;i++){
		cin>>dp[i];
	}
	int res=INT_MAX;
	int a1=0;
	int a2=0;
	int sum=dp[0];
	
	if(res==INT_MAX) cout<<0<<'\n';
	else cout<<res<<'\n';
}