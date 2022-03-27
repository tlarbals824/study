#include<bits/stdc++.h>

using namespace std;

int dp[110][110]={0};


int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>dp[i][j];
		}
	}
}