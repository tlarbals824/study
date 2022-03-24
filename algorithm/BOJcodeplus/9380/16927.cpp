#include<bits/stdc++.h>

using namespace std;

int n,m,r;
int dp[400][400];
int diry[4]={1,0,-1,0};
int dirx[4]={0,1,0,-1};
void dfs(int cnt,int y,int x,int dir,int next){
	int cur=dp[y][x];
	dp[y][x]=next;
	int yy=y+diry[dir];
	int xx=x+dirx[dir];
	if(dir==3&&(yy==cnt&&xx==cnt)) return;
	if(xx>=cnt&&yy>=cnt&&xx<m-cnt&&yy<n-cnt&&!(xx==cnt&&yy==cnt)){
		dfs(cnt,yy,xx,dir,cur);
	}else{
		if(dir+1<4){
			yy=y+diry[dir+1];
			xx=x+dirx[dir+1];
			if(dir==3&&(xx==cnt&&yy==cnt)) return;
			dfs(cnt,yy,xx,dir+1,cur);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin>>n>>m>>r;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>dp[i][j];
		}
	}
	
	int minN=min(n,m)/2;
	int rec=(n+m-2)*2;
	for(int i=0;i<minN;i++){
		int m=rec-i*8;
		int c=r%m;
		while(c--){
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