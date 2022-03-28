#include<bits/stdc++.h>

using namespace std;
int dp[1100][1100];
int ch[1100][1100]={0};
int diry[4]={-1,0,1,0};
int dirx[4]={0,-1,0,1};
int main(){
	int n,m;
	cin>>n>>m;
	queue<pair<int,int>> s;
	int cnt=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%1d",&dp[i][j]);
			if(dp[i][j]==1){ 
				s.push({i,j});
			}
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<dp[i][j];
		}
		cout<<'\n';
	}
}