#include<bits/stdc++.h>

using namespace std;

int n;
int dp[130];

int main(){
	cin>>n;
	
	dp[0]=0;
	dp[2]=3;
	for(int i=4;i<=n;i+=2){
		dp[i]=2;
		for(int j=i-4;j>0;j-=2){
			dp[i]+=dp[j]*2;
		}
		dp[i]+=dp[i-2]*3;
	}	
	cout<<dp[n]<<'\n';
}