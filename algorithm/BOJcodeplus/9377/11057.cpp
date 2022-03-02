#include<bits/stdc++.h>

using namespace std;

int dp[1010][10];


int main(){
	int n;
	cin>>n;
	for(int i=0;i<10;i++){
		dp[1][i]=1;
	}
	for(int i=2;i<=n;i++){
		for(int j=0;j<10;j++){
			for(int k=0;k<=j;k++){
				dp[i][j]=(dp[i][j]+dp[i-1][k])%10007;
			}
		}
	}
	int res=0;
	for(int i=0;i<10;i++){
		res=(res+dp[n][i])%10007;
	}
	cout<<res<<'\n';
}