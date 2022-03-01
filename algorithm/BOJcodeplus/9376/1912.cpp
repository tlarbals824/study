#include<bits/stdc++.h>

using namespace std;

int n;
int num[100010];
int dp[100010];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;
	int maxidx=0;
	for(int i=0;i<n;i++){
		cin>>num[i];
	}
	for(int i=0;i<n;i++){
		if(i==0)
			dp[i]=num[i];
		else{
			dp[i]=max(dp[i-1]+num[i],num[i]);
		}
	}
	int maxsum=-INT_MAX;
	for(int i=0;i<n;i++){
		maxsum=max(maxsum,dp[i]);
	}
	cout<<maxsum<<'\n';
}