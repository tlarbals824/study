#include<bits/stdc++.h>

using namespace std;

int dp[400][400];
int n,m,r;
int dirx[4]={0,1,0,-1};
int diry[4]={1,0,-1,0};
void dfs(int cnt,int x,int y,int dir,int next){
	int cur=dp[y][x];
	dp[y][x]=next;
	int xx=x+dirx[dir];
	int yy=y+diry[dir];
	if(dir==3&&(xx==cnt&&yy==cnt)) return;
	if(xx<m-cnt&&xx>=cnt&&yy<n-cnt&&yy>=cnt&&!(xx==cnt&&yy==cnt)){
		dfs(cnt,xx,yy,dir,cur);
	}else{
		if(dir+1<4){
			xx=x+dirx[dir+1];
			yy=y+diry[dir+1];
			if(dir==3&&(xx==cnt&&yy==cnt)) return;
			dfs(cnt,xx,yy,dir+1,cur);
		}
	}
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>r;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>dp[i][j];
		}
	}
	int minN=min(n,m);
	while(r--){
		for(int i=0;i<minN/2;i++){
			dfs(i,i,i,0,dp[i][i+1]);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<dp[i][j]<<' ';
		}
		cout<<'\n';
	}
}