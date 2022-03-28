#include<bits/stdc++.h>
using namespace std;

int diry[4]={1,0,-1,0};
int dirx[4]={0,1,0,-1};
int Map[1100][1100];
int dp[1100][1100][20];

int main(){

	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%1d",&Map[i][j]);
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int x=0;x<=k;x++){
				dp[i][j][x]=10e6;
			}
		}
	}
	dp[1][1][k]=1;
	queue<pair<int,pair<int,int>>> q;
	q.push({k,{1,1}});
	while(!q.empty()){
		int y=q.front().second.first;
		int x=q.front().second.second;
		int t=q.front().first;
		q.pop();
		for(int i=0;i<4;i++){
			int yy=y+diry[i];
			int xx=x+dirx[i];
			if(yy<1||yy>n||xx<1||xx>m) continue;
			if(Map[yy][xx]==1){
				if(t>0){
					if(dp[yy][xx][t-1]>dp[y][x][t]+1){
						dp[yy][xx][t-1]=dp[y][x][t]+1;
						q.push({t-1,{yy,xx}});
					}
				}
			}else{
				if(dp[yy][xx][t]>dp[y][x][t]+1){
					dp[yy][xx][t]=dp[y][x][t]+1;
					q.push({t,{yy,xx}});
				}
			}
		}
	}
	int res=10e6;
	for(int i=0;i<=k;i++){
		res=min(res,dp[n][m][i]);
	}
	if(res==10e6) cout<<-1<<'\n';
	else cout<<res<<'\n';
}