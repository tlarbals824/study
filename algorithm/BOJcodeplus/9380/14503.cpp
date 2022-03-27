#include<bits/stdc++.h>

using namespace std;

int diry[4]={-1,0,1,0};
int dirx[4]={0,1,0,-1};
int dp[60][60];//빈칸 0,벽 1, 청소함 -1
int cnt=0;
int n,m,r,c,d;

void dfs(int x,int y,int dir){
	if(dp[y][x]==0){
		dp[y][x]=-1;
		cnt++;
	}
	int tmp=dir+4;
	for(int i=1;i<=4;i++){
		int yy=y+diry[(tmp-i)%4];
		int xx=x+dirx[(tmp-i)%4];
		if(xx<0||xx>=m||yy<0||yy>=n) continue;
		if(dp[yy][xx]==0){
			dfs(xx,yy,(tmp-i)%4);
			return;
		}
	}
	if(dp[y-diry[dir]][x-dirx[dir]]==1){
		cout<<cnt<<'\n';
		exit(0);
	}else{
		dfs(x-dirx[dir],y-diry[dir],dir);
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	
	cin>>n>>m;
	
	cin>>r>>c>>d;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>dp[i][j];
		}
	}
	dfs(c,r,d);
}
