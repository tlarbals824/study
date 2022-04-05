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
	while(a2<n&&a1<=a2){
		if(sum>=s){
			res=min(res,a2-a1+1);
			if(sum==s){
				sum+=dp[++a2];
			}else{
				if(a1==a2){
					sum=sum-dp[a1++]+dp[++a2];
				}else{
					sum=sum-dp[a1++];
				}
			}
		}else{
			sum+=dp[++a2];
		}
	}
	if(res==INT_MAX) cout<<0<<'\n';
	else cout<<res<<'\n';
}