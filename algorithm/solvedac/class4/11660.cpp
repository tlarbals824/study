#include<bits/stdc++.h>

using namespace std;

int n,m;
int x1,a1,x2,a2;
int dp[2000][2000];
int ch[2000][2000];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>ch[i][j];
			
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+ch[i][j];
		}
	}
	for(int i=0;i<m;i++){
		cin>>x1>>a1>>x2>>a2;
		int sum=dp[x2][a2]-dp[x1-1][a2]-dp[x2][a1-1]+dp[x1-1][a1-1];
		cout<<sum<<'\n';
	}
}